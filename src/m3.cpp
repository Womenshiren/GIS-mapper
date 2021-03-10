#pragma once
#include "algorithm"
#include "m1.h"
#include "m3.h"
#include <queue>
#include "m3helper.h"



double maxSpeed = 0;

// compute estimated time for sorting, -1 for driving, 0 for walk, 1 for dijkstra
void compute_etime(DNode * n, int end, int stype, double speed) {
    double et;
    if(stype == 1) {
        et = 0;
    }
    else {
        auto ap = getIntersectionPosition(n->id);
        auto ep = getIntersectionPosition(end);
        auto ed = find_distance_between_two_points(std::make_pair(ap, ep));
        if(stype == -1)
            et = ed/ (0.27777777777 * maxSpeed);
        else if(stype == 0)
            et = ed/ (speed);
    }
    // the real time plus the estimated time which is the straight line time to the destination
    n->etime = n->time + et;
}


double compute_path_travel_time(const std::vector<StreetSegmentIndex>& path, const double turn_penalty) {
    double totalTime = 0;
    if(path.size() == 0)
        return 0;
    int preStId = getInfoStreetSegment(path[0]).streetID;
    for(int i = 0; i < path.size(); i ++) {
        int currentStId = getInfoStreetSegment(path[i]).streetID;
        //if the street id changed, means there is a turn
        if(preStId != currentStId) {
            totalTime += turn_penalty;
        }
        preStId = currentStId;
        totalTime += find_street_segment_travel_time(path[i]);
    }
    return totalTime;
}


//compute the path distance 
double compute_path_distance(const std::vector<StreetSegmentIndex>& path) {
    double totalD = 0;
    if(path.size() == 0)
        return 0;
    for(int i = 0; i < path.size(); i ++) {
        int currentStId = getInfoStreetSegment(path[i]).streetID;
        totalD += find_street_segment_length(path[i]);
    }
    return totalD;
}

std::vector<StreetSegmentIndex> find_path_between_intersections(const IntersectionIndex intersect_id_start, 
                                                                const IntersectionIndex intersect_id_end, 
                                                                const double turn_penalty) {
    return a_star(intersect_id_start, intersect_id_end, turn_penalty);
}



double compute_path_walking_time(const std::vector<StreetSegmentIndex>& path, const double walking_speed, const double turn_penalty) {
    double totalTime = 0;
    if(path.size() == 0)
        return 0;
    int preStId = getInfoStreetSegment(path[0]).streetID;
    for(int i = 0; i < path.size(); i ++) {
        int currentStId = getInfoStreetSegment(path[i]).streetID;
        //if the street id changed, means there is a turn
        if(preStId != currentStId) {
            totalTime += turn_penalty;
        }
        preStId = currentStId;
        totalTime += find_street_segment_length(path[i]) / walking_speed;
    }
    return totalTime;
}

std::pair<std::vector<StreetSegmentIndex>, std::vector<StreetSegmentIndex>> find_path_with_walk_to_pick_up(
                          const IntersectionIndex start_intersection, 
                          const IntersectionIndex end_intersection,
                          const double turn_penalty,
                          const double walking_speed, 
                          const double walking_time_limit) {
    std::vector<int> interr(getNumIntersections(), -1);
    std::vector<int> intersw;
    // first find all the reachable intersections within time limits
    find_inters_walklimit(start_intersection, turn_penalty, walking_speed, walking_time_limit, &interr, &intersw);
    // if the destination is within the time limit, return some dummy result
    for(int i = 0; i < intersw.size(); i++) {
        if(end_intersection == intersw[i]) {
            std::vector<int> dummy;
            dummy.push_back(-1);
            return std::make_pair(dummy, dummy);
        }
    }
    // use the found inters to do the multisource a_star
    auto drivingPath = multiple_startpoints(end_intersection, turn_penalty, intersw);
    if(drivingPath.size() == 0) {
        return std::make_pair(drivingPath, drivingPath);
    }
    int pickupPoint;

    //get the pickup point
    if(drivingPath.size() == 1) {
        if(end_intersection == getInfoStreetSegment(drivingPath[0]).from)
            pickupPoint = getInfoStreetSegment(drivingPath[0]).to;
        else
        {
               pickupPoint = getInfoStreetSegment(drivingPath[0]).from; 
        }
        
    }
    else {
        if(getInfoStreetSegment(drivingPath[0]).from == getInfoStreetSegment(drivingPath[1]).from || 
            getInfoStreetSegment(drivingPath[0]).from == getInfoStreetSegment(drivingPath[1]).to)
            pickupPoint = getInfoStreetSegment(drivingPath[0]).to;
        else 
            pickupPoint = getInfoStreetSegment(drivingPath[0]).from;
    }

    auto walkingPath = back_trace(pickupPoint, interr);

    return std::make_pair(walkingPath, drivingPath);

}

std::vector<StreetSegmentIndex> a_star(const IntersectionIndex intersect_id_start, const IntersectionIndex intersect_id_end, const double turn_penalty, bool walk, double walkspeed) {
    std::vector<int> done(getNumIntersections(),0);
    std::vector<int> intersreach(getNumIntersections(), -1);
    std::priority_queue<DNode> u;

    //initialized the first node using the start intersections
    DNode f;
    f.id = intersect_id_start;
    f.time = 0;

    // compute the estimated time for the first node    
    if(!walk) {
        compute_etime(&f, intersect_id_end);
    }
    else {
        compute_etime(&f, intersect_id_end, 0, walkspeed);
    }


    f.path = -2;
    u.push(f);


    while(done[intersect_id_end] != 1) {
        if(u.size() == 0 && done[intersect_id_end] != 1) {
            std::vector<StreetSegmentIndex> dummy;
            return dummy;
        }

        DNode cn = u.top();
        u.pop();

        if(done[cn.id] == 1)
            continue;
        intersreach[cn.id] = cn.path;
        done[cn.id] = 1;
        // if reached the destination, retrun the path
        if(cn.id == intersect_id_end) {
            // std::cout << cn.time <<"\n";
            return back_trace(intersect_id_end, intersreach);
        }


        auto connectedSegs = find_street_segments_of_intersection(cn.id);
        //go throught all the intersections that connected to the current intersections
        for(int i = 0; i < connectedSegs.size(); i++) {
            auto currentSeg = getInfoStreetSegment(connectedSegs[i]);
            //if the current seg cannot reached the next intersction, continue the loop
            if(currentSeg.oneWay && currentSeg.from != cn.id && !walk)
                continue;

            DNode tempN;

            if(!walk) {
                tempN.time = cn.time + find_street_segment_travel_time(connectedSegs[i]);
            }
            else {
                tempN.time = cn.time + (find_street_segment_length(connectedSegs[i]) / walkspeed) ;
            }

            
            if( cn.path != -2 && getInfoStreetSegment(cn.path).streetID != currentSeg.streetID )
                tempN.time += turn_penalty;

            tempN.path = connectedSegs[i];

            if(cn.id == currentSeg.from) {
                tempN.id = currentSeg.to;
            }
            else{
                tempN.id = currentSeg.from;
            }

            if(done[tempN.id] == 1)
                continue;

            if(!walk) {
                compute_etime(&tempN, intersect_id_end);
            }
            else {
                compute_etime(&tempN, intersect_id_end, 0, walkspeed);
            }

            //push the node into the priority queue
            u.push(tempN);
        }

    }
}

std::vector<StreetSegmentIndex> back_trace(const IntersectionIndex intersect_id_end, std::vector<int> intersreach, int * startID) {
        std::vector<int> tpath;
        int cuinter = intersect_id_end;
        int previouspath;
        while(intersreach[cuinter] != -2) {
            previouspath = intersreach[cuinter];
            //insert the path into the beginning of the path vector
            tpath.insert(tpath.begin(), previouspath);
            auto infopseg = getInfoStreetSegment(previouspath);
            //get the previous intersection in the path
            if(infopseg.from == cuinter) {
                cuinter = infopseg.to;
            }
            else {
                cuinter = infopseg.from;
            }
        }
        if(startID != nullptr) {
            *startID = cuinter;
        }
        return tpath;
}

//mostly the same with shortest path, except for the end condition
void find_inters_walklimit(const IntersectionIndex start_intersection, const double turn_penalty, const double walking_speed, 
                            const double walking_time_limit, std::vector<int>* intersreach, std::vector<int>* intersWithinRange) {

    std::vector<int> done(getNumIntersections(),0);
    std::priority_queue<DNode> u;
    

    DNode f;
    f.id = start_intersection;
    f.time = 0;
    compute_etime(&f, -1, 1, walking_speed);
    f.path = -2;
    u.push(f);

    

    while(u.size() != 0) {

        DNode cn = u.top();
        u.pop();


        if(done[cn.id] == 1 || cn.time > walking_time_limit)
            continue;
        (*intersreach)[cn.id] = cn.path;
        done[cn.id] = 1;
        (*intersWithinRange).push_back(cn.id);

        auto connectedSegs = find_street_segments_of_intersection(cn.id);

        for(int i = 0; i < connectedSegs.size(); i++) {
            auto currentSeg = getInfoStreetSegment(connectedSegs[i]);
            DNode tempN;
            tempN.time = cn.time + (find_street_segment_length(connectedSegs[i]) / walking_speed) ;
            if( cn.path != -2 && getInfoStreetSegment(cn.path).streetID != currentSeg.streetID )
                tempN.time += turn_penalty;

            tempN.path = connectedSegs[i];

            if(cn.id == currentSeg.from) {
                tempN.id = currentSeg.to;
            }
            else{
                tempN.id = currentSeg.from;
            }
            // if out of the walking limit, continue the loop
            if(done[tempN.id] == 1 || tempN.time > walking_time_limit)
                continue;

            compute_etime(&tempN, -1, 1, walking_speed);
            u.push(tempN);
        }
    }
}


std::vector<StreetSegmentIndex> multiple_startpoints(const IntersectionIndex intersect_id_end, const double turn_penalty, std::vector<int> intersw) {

    std::vector<int> done(getNumIntersections(),0);
    std::vector<int> intersreach(getNumIntersections(), -1);
    std::priority_queue<DNode> u;

    //Initialized all the start points
    for(int i = 0; i < intersw.size(); i ++) {
        DNode f;
        f.id = intersw[i];
        f.time = 0;
        compute_etime(&f, intersect_id_end);
        f.path = -2;
        u.push(f);
    }     

    //the rest is the same with a_star algorithm
    while(done[intersect_id_end] != 1) {
        if(u.size() == 0 && done[intersect_id_end] != 1) {
            std::vector<StreetSegmentIndex> dummy;
            return dummy;
        }

        DNode cn = u.top();
        u.pop();

        if(done[cn.id] == 1)
            continue;
        intersreach[cn.id] = cn.path;
        done[cn.id] = 1;
        if(cn.id == intersect_id_end) {
            return back_trace(intersect_id_end, intersreach);
        }

        auto connectedSegs = find_street_segments_of_intersection(cn.id);

        for(int i = 0; i < connectedSegs.size(); i++) {
            auto currentSeg = getInfoStreetSegment(connectedSegs[i]);
            if(currentSeg.oneWay && currentSeg.from != cn.id )
                continue;

            DNode tempN;

            tempN.time = cn.time + find_street_segment_travel_time(connectedSegs[i]);

            
            if( cn.path != -2 && getInfoStreetSegment(cn.path).streetID != currentSeg.streetID )
                tempN.time += turn_penalty;

            tempN.path = connectedSegs[i];

            if(cn.id == currentSeg.from) {
                tempN.id = currentSeg.to;
            }
            else{
                tempN.id = currentSeg.from;
            }

            if(done[tempN.id] == 1)
                continue;

            compute_etime(&tempN, intersect_id_end);

            u.push(tempN);
        }

    }
}