#pragma once
#include "m4.h"
#include "m3.h"
#include "m3helper.h"
#include "m1.h"
#include <map>
#include <unordered_map>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <cmath>
#define TIME_LIMIT 45

std::chrono::_V2::system_clock::time_point startTime;

int NUMINTERS;
int pickNum;

struct NodeInfo {
    bool type; // false for pickup, true for drop off
    int intersectionID;
    int pickupID;
    bool depot = false;
    double weight;
    NodeInfo(bool _type, int _intersectionID, int _pickupID, double _weight) : type( _type), intersectionID(_intersectionID), pickupID(_pickupID), depot(false), weight(_weight) {};
    NodeInfo() {
        ;
    }
};

//struct to store certain intersecrtion to other inters
struct PathInfo {
    std::vector<std::vector<int>> paths;
    std::vector<double> pathTimes;
    int id;
};

struct Depot2Node {
    std::vector<int> path;
    double time;
    int depotInterId;
};


std::vector<int> find_paths_to_all_points(const NodeInfo startNode, const double turn_penalty, std::vector<NodeInfo> & allNodes) {
    //store the inters that needed to be computed
    std::vector<int> idNeeded(getNumIntersections(),0);
    std::vector<int> allIDs;
    std::vector<int> dummy;

    

    for(int i = 0; i < allNodes.size(); i ++) {
        allIDs.push_back(allNodes[i].intersectionID);
        idNeeded[allNodes[i].intersectionID] = 1;
    }

    std::sort(allIDs.begin(), allIDs.end());
    allIDs.erase(std::unique(allIDs.begin(), allIDs.end()), allIDs.end());

    int remainingID = allIDs.size();

    std::vector<int> done(getNumIntersections(),0);
    std::priority_queue<DNode> u;
    std::vector<int> intersreach(getNumIntersections(),-1);

    DNode f;
    f.id = startNode.intersectionID;
    f.time = 0;
    compute_etime(&f, -1, 1, 0);
    f.path = -2;
    u.push(f);

    

    while(u.size() != 0 || remainingID != 0) {

        DNode cn = u.top();
        u.pop();


        if(done[cn.id] == 1 )
            continue;

        if(idNeeded[cn.id] == 1) {
            // std::cout << remainingID <<"\n";
            remainingID --;
        }
        intersreach[cn.id] = cn.path;
        done[cn.id] = 1;

        auto connectedSegs = find_street_segments_of_intersection(cn.id);

        for(int i = 0; i < connectedSegs.size(); i++) {
            auto currentSeg = getInfoStreetSegment(connectedSegs[i]);

            if(currentSeg.oneWay && currentSeg.from != cn.id)
                continue;

            DNode tempN;

            tempN.time = cn.time + find_street_segment_travel_time(connectedSegs[i]) ;

            if( cn.path != -2 && getInfoStreetSegment(cn.path).streetID != currentSeg.streetID )
                tempN.time += turn_penalty;

            tempN.path = connectedSegs[i];

            if(cn.id == currentSeg.from) {
                tempN.id = currentSeg.to;
            }
            else{
                tempN.id = currentSeg.from;
            }
            if(done[tempN.id] == 1 )
                continue;

            compute_etime(&tempN, -1, 1, 0);
            u.push(tempN);
        }
    }

    return intersreach;
}

std::vector<int> find_multiple_depots_paths_to_all_points(const std::vector<NodeInfo>& depots, const double turn_penalty, const std::vector<NodeInfo> &allNodes) {
    //store the inters that needed to be computed
    std::vector<int> idNeeded(getNumIntersections(),0);
    std::vector<int> allIDs;

    for(int i = 0; i < allNodes.size(); i ++) {
        allIDs.push_back(allNodes[i].intersectionID);
        idNeeded[allNodes[i].intersectionID] = 1;
    }

    std::sort(allIDs.begin(), allIDs.end());
    allIDs.erase(std::unique(allIDs.begin(), allIDs.end()), allIDs.end());

    int remainingID = allIDs.size();

    std::vector<int> done(getNumIntersections(),0);
    std::priority_queue<DNode> u;
    std::vector<int> intersreach(getNumIntersections(),-1);

    for(int i = 0; i < depots.size(); i ++) {
        DNode f;
        f.id = depots[i].intersectionID;
        f.time = 0;
        compute_etime(&f, -1, 1, 0);
        f.path = -2;
        u.push(f);
    }
    

    while(u.size() != 0 || remainingID != 0) {

        DNode cn = u.top();
        u.pop();


        if(done[cn.id] == 1 )
            continue;

        if(idNeeded[cn.id] == 1)
            remainingID --;

        intersreach[cn.id] = cn.path;
        done[cn.id] = 1;

        auto connectedSegs = find_street_segments_of_intersection(cn.id);

        for(int i = 0; i < connectedSegs.size(); i++) {
            auto currentSeg = getInfoStreetSegment(connectedSegs[i]);

            if(currentSeg.oneWay && currentSeg.from != cn.id)
                continue;

            DNode tempN;

            tempN.time = cn.time + find_street_segment_travel_time(connectedSegs[i]) ;

            if( cn.path != -2 && getInfoStreetSegment(cn.path).streetID != currentSeg.streetID )
                tempN.time += turn_penalty;

            tempN.path = connectedSegs[i];

            if(cn.id == currentSeg.from) {
                tempN.id = currentSeg.to;
            }
            else{
                tempN.id = currentSeg.from;
            }
            if(done[tempN.id] == 1 )
                continue;

            compute_etime(&tempN, -1, 1, 0);
            u.push(tempN);
        }
    }

    return intersreach;
}

//return the paths between each nodes
std::unordered_map<int, PathInfo> compute_path_between_points(const std::vector<NodeInfo>& nodes, const double turn_penalty, const std::vector<NodeInfo> &depots) {

    std::vector< std::vector<int> > backTraceInfo(nodes.size()); //back_trace info for each node
    std::unordered_map<int, PathInfo> dummy;
    std::vector<NodeInfo> allNodes;

    allNodes.insert(allNodes.end(), nodes.begin(), nodes.end());
    allNodes.insert(allNodes.end(), depots.begin(), depots.end());

    #pragma omp parallel for
    for(int i = 0; i < nodes.size(); i ++) {
        backTraceInfo[i] = find_paths_to_all_points(nodes[i], turn_penalty, allNodes);
    }

    PathInfo tempPath;
    std::vector<std::vector<int> >tempa(NUMINTERS);
    tempPath.paths = tempa;
    std::vector<double> tempt (NUMINTERS);
    tempPath.pathTimes = tempt;


    std::unordered_map<int, PathInfo> allPaths;
    for(int i = 0; i < nodes.size(); i++) {
        allPaths.insert(std::make_pair(nodes[i].intersectionID, tempPath));
    }
    
    

    for(int i = 0; i < nodes.size(); i ++) {
        for(int j = 0; j < allNodes.size(); j ++) {

            

            //if can not reach another places, means there is no path;
            if(backTraceInfo[i][allNodes[j].intersectionID] == -1) {
                return dummy;
            }

            

            (*allPaths.find(nodes[i].intersectionID)).second.paths[allNodes[j].intersectionID] = back_trace(allNodes[j].intersectionID, backTraceInfo[i]);
            (*allPaths.find(nodes[i].intersectionID)).second.id = nodes[i].intersectionID;
            (*allPaths.find(nodes[i].intersectionID)).second.pathTimes[allNodes[j].intersectionID] = compute_path_travel_time((*allPaths.find(nodes[i].intersectionID)).second.paths[allNodes[j].intersectionID], turn_penalty);
        }
        
    }

    return allPaths;
}

std::pair<std::vector<Depot2Node>, std::multimap<double, int> > find_paths_from_depots_to_nodes(const std::vector<NodeInfo>&  depots, const double turn_penalty, const std::vector<NodeInfo> & allnodes) {
    std::vector<Depot2Node> allInterDepotPath(getNumIntersections());
    std::multimap<double, int> orderedNodes;
    std::vector<NodeInfo> nodes;

    for(int i = 0; i < allnodes.size(); i ++) {
        if(allnodes[i].type == false) {
            nodes.push_back(allnodes[i]);
        }
    }

    std::vector<int> backTraceInfo;
    backTraceInfo = find_multiple_depots_paths_to_all_points(depots, turn_penalty, nodes);
    for(int i = 0; i < nodes.size(); i ++) {
        allInterDepotPath[nodes[i].intersectionID].path = back_trace(nodes[i].intersectionID, backTraceInfo, &(allInterDepotPath[nodes[i].intersectionID].depotInterId) );
        allInterDepotPath[nodes[i].intersectionID].time = compute_path_travel_time(allInterDepotPath[nodes[i].intersectionID].path, turn_penalty);
        orderedNodes.insert(std::make_pair(allInterDepotPath[nodes[i].intersectionID].time, nodes[i].intersectionID) );
    }

    //return the nearest depot for the fist node and the travel time corresponding to each in order
    return std::make_pair(allInterDepotPath, orderedNodes);

}

double getPathTime(const std::unordered_map<int, PathInfo> &allPaths, int start, int end) {
    return allPaths.find(start)->second.pathTimes[end];
}

std::vector<int> getPath(const std::unordered_map<int, PathInfo> &allPaths, int start, int end) {
    return allPaths.find(start)->second.paths[end];
}


//compute the travel time for the given path(not contain depots), make sure it is legal first
double pathCost(const std::vector<NodeInfo>& nodes, const std::vector<Depot2Node> &allInterDepotPath, const std::unordered_map<int, PathInfo> &allPaths, const std::vector<NodeInfo> &depots) {
    double time = 0;
    if(nodes.size() == 0) {
        return 0;
    }
    for(int i = 0; i < nodes.size() - 1; i ++) {
        time += getPathTime(allPaths, nodes[i].intersectionID, nodes[i+1].intersectionID);
    }

    time += allInterDepotPath[nodes[0].intersectionID].time;
    // auto nearest =  nearestDepot[nodes[nodes.size() - 1].intersectionID];


    int minT = getPathTime(allPaths, nodes[nodes.size() - 1].intersectionID, depots[0].intersectionID);
    int minD = depots[0].intersectionID;

    for(int i = 0; i < depots.size(); i++) {
        if(minT > getPathTime(allPaths, nodes[nodes.size() - 1].intersectionID, depots[i].intersectionID)) {
            minT = getPathTime(allPaths, nodes[nodes.size() - 1].intersectionID, depots[i].intersectionID);
            minD = depots[i].intersectionID;
        }
    }

    time += getPathTime(allPaths, nodes[nodes.size() - 1].intersectionID, minD);

    return time;

}

std::vector<int> get_nearestDepot_for_nodes(const std::unordered_map<int, PathInfo> & allPaths, const std::vector<NodeInfo> & depots, const std::vector<NodeInfo> & nodes) {
    std::vector<NodeInfo> realNodes;

    for(int i = 0; i < nodes.size(); i++) {
        if(nodes[i].type == true) {
            realNodes.push_back(nodes[i]);
        }
    }

    std::vector<int> nearestDepot(getNumIntersections());

    for(int i = 0; i < realNodes.size(); i ++) {
        std::map<double, int> depotRank;
        for(int j = 0; j < depots.size(); j ++) {
            auto time = getPathTime(allPaths, realNodes[i].intersectionID, depots[j].intersectionID);
            depotRank.insert(std::make_pair(time, depots[j].intersectionID));
        }
        nearestDepot[realNodes[i].intersectionID] = depotRank.begin()->second;
    }

    return nearestDepot;
}

//determine whether the path is legal or not
bool isPathLegal(const std::vector<NodeInfo>& nodes, bool isPathComplete, int pickupNum, const float truck_capacity) {

    // std::cout << "cost start" << "\n";
    if(nodes[nodes.size() - 1].type == false && isPathComplete)
        return false;

    std::vector<bool> isPickup(pickupNum, false);

    double currentWeight = 0;

    for(int i = 0; i < nodes.size(); i ++) {
        //if drop off item before pick up, the path is illegal
        if(nodes[i].pickupID < 0 || nodes[i].pickupID > isPickup.size() - 1) {
            // std::cout << "cost1 end" << "\n";
            return false;
        }
            
        if(nodes[i].type == true && isPickup[nodes[i].pickupID] == false) {
            // std::cout << "cost2 end" << "\n";
            return false;
        }
            
        if(nodes[i].type == false) {
            isPickup[nodes[i].pickupID] = true;
            currentWeight += nodes[i].weight;
            //if carry too many items, the path is illegal
            if(currentWeight > truck_capacity) {
                // std::cout << "cost3 end" << "\n";
                return false;
            }
                
        }
        if(nodes[i].type == true) {
            currentWeight -= nodes[i].weight;
        }

    }

    // std::cout << "cost4 end" << "\n";

    return true;
}

std::pair<std::vector<NodeInfo>, std::vector<NodeInfo> > DeliveryInfo2NodeInfo (const std::vector<DeliveryInfo>& deliveries, const std::vector<int>& depots) {
    std::vector<NodeInfo> nodes;
    std::vector<NodeInfo> depotsNode;

    for(int i = 0; i < deliveries.size(); i ++) {
        NodeInfo a, b;
        a.depot = false;
        a.intersectionID = deliveries[i].pickUp;
        a.pickupID = i;
        a.type = false;
        a.weight = deliveries[i].itemWeight;

        b.depot = false;
        b.intersectionID = deliveries[i].dropOff;
        b.pickupID = i;
        b.type = true;
        b.weight = deliveries[i].itemWeight;

        nodes.push_back(a);
        nodes.push_back(b);
    }

    for(int i = 0; i < depots.size(); i ++) {
        NodeInfo a;
        a.intersectionID = depots[i];
        a.depot = true;
        depotsNode.push_back(a);
    }

    return std::make_pair(nodes, depotsNode);
}

//use greedy algorithm
std::vector<NodeInfo> basic_find_path(const std::vector<DeliveryInfo>& deliveries,
	       	        const std::vector<int>& depots, 
		            const float turn_penalty, 
		            const float truck_capacity,
                    const std::pair<std::vector<Depot2Node>, std::multimap<double, int> > & depotPathandTime,
                    const std::unordered_map<int, PathInfo> & allPaths,
                    const std::pair<std::vector<NodeInfo>, std::vector<NodeInfo>>& nodesAndDepots) {

    std::vector<NodeInfo> dummy;
    auto nodes = nodesAndDepots.first;
    auto depotNodes = nodesAndDepots.second;
    

    // std::srand(std::time(0));

    int randStart = std::rand() % 3;
    int randNext = std::rand() % 2;
    
    // std::cout<< "c" <<"\n";

    if(allPaths.size() == 0) {
        
        return dummy;
    }
    
    std::vector<NodeInfo> path;
    NodeInfo firstPickup;

    // std::cout<< depotPathandTime.second.size() <<"\n";



    if(randStart == 0 || depotPathandTime.second.size() == 1) {
        // std::cout << "first" <<"\n";
        for(int i = 0; i < nodes.size(); i ++) {
            if(nodes[i].intersectionID == (*depotPathandTime.second.begin()).second && nodes[i].type == false) {
                firstPickup = nodes[i];
                nodes.erase(nodes.begin() + i);
                break;
            }
        }
    }
    else if (randStart == 1 || depotPathandTime.second.size() == 2){

        //  std::cout << "second" <<"\n";
        for(int i = 0; i < nodes.size(); i ++) {
           
            if(nodes[i].intersectionID == (*( ++ depotPathandTime.second.begin() )).second && nodes[i].type == false) {
                firstPickup = nodes[i];
                nodes.erase(nodes.begin() + i);
                break;
            }
        }
    }
    else {

        //  std::cout << "second" <<"\n";
        for(int i = 0; i < nodes.size(); i ++) {
           
            if(nodes[i].intersectionID == (*( ++ ( ++ depotPathandTime.second.begin() ) )).second && nodes[i].type == false) {
                firstPickup = nodes[i];
                nodes.erase(nodes.begin() + i);
                break;
            }
        }
    }

    
    // std::cout<< "e" <<"\n";


    
    path.push_back(firstPickup);
    // std::cout<< firstPickup.pickupID <<"\n";

    int startDepot = depotPathandTime.first[firstPickup.intersectionID].depotInterId;

    while(nodes.size() != 0) {
        double min = -1;
        int minID;
        std::multimap<double, int> surroundingN;

        
    
        // std::cout<< "m" <<"\n";

        for(int j = 0; j < nodes.size(); j ++) {

            if( nodes[j].intersectionID == path[path.size() - 1].intersectionID && nodes[j].pickupID == path[path.size() - 1].pickupID && nodes[j].type == path[path.size() - 1].type) {
                continue;
            }

            std::vector<NodeInfo> test = path;
            test.push_back(nodes[j]);

            // std::cout<< nodes[j].pickupID <<"\n";

            // for(int m = 0; m < test.size(); m++){
            //     // std::cout<< test[m].intersectionID <<"->";
            //     std::cout<< test[m].pickupID <<"->";
            // }
                
            
            //  std::cout<< "\n-----------------------------------------------" <<"\n";

            if(isPathLegal(test, false, pickNum, truck_capacity) == false) {
                
                continue;
            }


            // std::cout<< "o" <<"\n";

            if(min == -1) {
                min = getPathTime(allPaths, path[path.size() - 1].intersectionID, nodes[j].intersectionID);
                minID = j;
            }
            else if(min > getPathTime(allPaths, path[path.size() - 1].intersectionID, nodes[j].intersectionID)) {
                min = getPathTime(allPaths, path[path.size() - 1].intersectionID, nodes[j].intersectionID);
                minID = j;
            }
            // if(min == -1)
                // minID = j;
            surroundingN.insert( std::make_pair(getPathTime(allPaths, path[path.size() - 1].intersectionID, nodes[j].intersectionID), j) );
            
        }

        // std::cout<< "p" <<"\n";
        if(randNext != 0 || surroundingN.size() == 1) {
            path.push_back(nodes[minID]);
            nodes.erase(nodes.begin() + minID);
        }
            
        else
        {
            path.push_back( nodes[(*( ++ surroundingN.begin())).second ] );
            nodes.erase(nodes.begin() + (*( ++ surroundingN.begin())).second);
        }
        
        // if(minID == (*(surroundingN.begin())).second) {
        //     std::cout<<"yes" <<"\n";
        // }
        
        
    }

    // std::cout<< "f" <<"\n";
    

    path.erase(path.begin() + nodesAndDepots.first.size(), path.end());
    //  std::cout << pathCost(path, depotPathandTime.first, allPaths, depotNodes) << "\n";

    // for(int i = 0; i < path.size(); i++) {
    //     std::cout << path[i].intersectionID << "->" ;
    // }

    // std::vector<NodeInfo> test;
    // test.push_back(path[0]);
    // test.push_back(path[1]);

    // std::cout<<"---------------------------------------------------------------------------" <<"\n";
    // std::cout<< isPathLegal(test, false, pickNum, truck_capacity)<<"\n";
    // std::cout << path[1].type << "\n" ;
    // std::cout << path[path.size() - 1].type <<"\n";

    // std::cout<< "g" <<"\n";
    NodeInfo fdepot;
    fdepot.depot = true;
    fdepot.intersectionID = startDepot;

    path.push_back(fdepot);

    // std::cout<< "h" <<"\n";

    

    // auto nearestDepot = get_nearestDepot_for_nodes(allPaths, depotNodes, nodes);
    int minT = getPathTime(allPaths, path[path.size() - 2].intersectionID, depotNodes[0].intersectionID);
    int minD = depotNodes[0].intersectionID;

    // std::cout<< "i" <<"\n";

    for(int i = 0; i < depotNodes.size(); i++) {
        if(minT > getPathTime(allPaths, path[path.size() - 2].intersectionID, depotNodes[i].intersectionID)) {
            minT = getPathTime(allPaths, path[path.size() - 2].intersectionID, depotNodes[i].intersectionID);
            minD = depotNodes[i].intersectionID;
        }
    }

    // std::cout<< "j" <<"\n";

    fdepot.intersectionID = minD;

    path.push_back(fdepot);

    // path = nodes;
    // path.push_back(fdepot);
    // path.push_back(fdepot);


    // path = nodes;
    // do {
    //     std::random_shuffle(path.begin(), path.end());
    // }while(isPathLegal(path, true, nodes.size() / 2, truck_capacity) == false);

    // path.push_back(fdepot);
    // path.push_back(fdepot);

    return path; 


}

std::vector<CourierSubpath> convertNodepathtoCourierSubPath(const std::vector<NodeInfo>& path, const std::pair<std::vector<Depot2Node>, std::multimap<double, int> > & depotPathandTime,
                    const std::unordered_map<int, PathInfo> & allPaths) {
    std::vector<CourierSubpath> cpath;
    // for(int i = 0; i < path.size() - 2; i ++) {
        
    // }

    CourierSubpath fisrtPath;
    fisrtPath.start_intersection = depotPathandTime.first[path[0].intersectionID].depotInterId;
    fisrtPath.end_intersection = path[0].intersectionID;
    // fisrtPath.subpath = find_path_between_intersections(path[path.size() - 2].intersectionID, path[0].intersectionID, 15);
    fisrtPath.subpath = depotPathandTime.first[path[0].intersectionID].path;
    cpath.push_back(fisrtPath);

    for(int i = 0; i < path.size() - 3; i ++) {
        CourierSubpath tempPath;
        if(path[i].type == true) {
            tempPath.start_intersection = path[i].intersectionID;
            tempPath.end_intersection = path[i + 1].intersectionID;
            // tempPath.subpath = find_path_between_intersections(path[i].intersectionID, path[i + 1].intersectionID, 15);
            tempPath.subpath = getPath(allPaths, path[i].intersectionID, path[i + 1].intersectionID);
            cpath.push_back(tempPath);
            continue;
        }
        int j = i;
        tempPath.start_intersection = path[i].intersectionID;
        // tempPath.end_intersection = path[i + 1].intersectionID;
        // tempPath.subpath = allPaths[path[i].intersectionID].paths[path[i + 1].intersectionID];
        tempPath.pickUp_indices.push_back(path[i].pickupID);
        while(j + 1 < path.size() - 2 && path[j].type == false && path[j].intersectionID == path[j + 1].intersectionID && path[j + 1].type == false) {
            tempPath.pickUp_indices.push_back(path[j + 1].pickupID);
            j ++;
        }
        i = j;
        tempPath.end_intersection = path[i + 1].intersectionID;
        // tempPath.subpath = find_path_between_intersections(path[i].intersectionID, path[i + 1].intersectionID, 15);
        tempPath.subpath = getPath(allPaths, path[i].intersectionID, path[i + 1].intersectionID);
        cpath.push_back(tempPath);
    }

    CourierSubpath lastPath;

    lastPath.start_intersection = path[path.size() - 3].intersectionID;
    lastPath.end_intersection = path[path.size() - 1].intersectionID;
    // lastPath.subpath = find_path_between_intersections(path[path.size() - 3].intersectionID, path[path.size() - 1].intersectionID, 15);
    lastPath.subpath = getPath(allPaths, path[path.size() - 3].intersectionID, path[path.size() - 1].intersectionID);

    // lastPath.end_intersection = fisrtPath.start_intersection;
    // lastPath.subpath = getPath(allPaths, path[path.size() - 3].intersectionID, fisrtPath.start_intersection);

    cpath.push_back(lastPath);

    return cpath;

}

std::vector<NodeInfo> swapNodes(const std::vector<NodeInfo>& oldPath, int pickupNum, const float truck_capacity) {
    
    int indexA = std::rand() % oldPath.size();
    int indexB = std::rand() % oldPath.size();
    if(indexB <= indexA) {
            int temp;
            temp = indexB;
            indexB = indexA;
            indexB = temp;
            }

    std::vector<NodeInfo> newPath;

    do{
        
        newPath = oldPath;
        indexB = std::rand() % oldPath.size();

         while(indexA == indexB && !( (oldPath[indexA].pickupID == oldPath[indexB].pickupID) &&  (oldPath[indexA].type == false) && (oldPath[indexB].type == true) ) ){
            indexB = std::rand() % oldPath.size();
            if(indexB < indexA) {
                int temp;
                temp = indexB;
                indexB = indexA;
                indexB = temp;
            }
        }
        std::swap(newPath[indexB], newPath[indexA]);
    }while(isPathLegal(newPath, true, pickNum, truck_capacity) == false);
    // std::cout << indexB << indexA << "\n";


    return newPath;
}

std::vector<NodeInfo> OrderOpt(const std::vector<NodeInfo> & oldPath,const float truck_capacity, bool type) {
    // std::srand(std::time(0)) ;
    // int u = std::rand() % oldPath.size();
    // int v = std::rand() % (oldPath.size() - u - 1) + 1 + u;
    // int w = std::rand() % (oldPath.size() - v - 1) + 1 + v;

    int size = oldPath.size();

    // std::cout << "opt start" << "\n";

    if(type) {
        // std::cout << "opt 1" << "\n";
        std::vector<NodeInfo> vec1;
        do{
            
            vec1 = oldPath;
            // std::cout << "opt 1 5" << "\n";
            int u = std::rand() % (size - 2);
            // std::cout << "opt 1 55" << "\n";
            int v = std::rand() % (size - u - 1) + 1 + u;
            // std::cout << "opt 1 2" << "\n";
            // int w = std::rand() % (oldPath.size() - v - 1) + 1 + v;
            std::reverse(vec1.begin()+u, vec1.begin() + v +1) ;
        }while(isPathLegal(vec1, true, pickNum, truck_capacity) == false);
        // std::cout << "opt end" << "\n";
        return vec1;
    }
    else {
        // std::cout << "opt 2" << "\n";
        std::vector<NodeInfo> vec3;
        
        do {
            // std::cout << "opt 2 1" << "\n";
            vec3.clear();
            // std::cout << "opt 2 1 5" << "\n";

            int u = std::rand() % (size - 3);
            // std::cout << "opt 2 1 55" << "\n";
            int v = std::rand() % (size - u - 2) + 1 + u;
            // std::cout << "opt 2 1 555" << "\n";
            // std::cout << "opt 2 1 5555" << "\n";
            // std::cout << size - v - 1 << "\n";
            int w = std::rand() % (size - v - 1) + 1 + v;
            // std::cout << "opt 2 1 55555" << "\n";

            // int u = 3;
            // int v = 6;
            // int w = 9;
            // std::cout << "opt 2 2" << "\n";
            vec3.insert(vec3.end(), oldPath.begin(), oldPath.begin() + u );
            vec3.insert(vec3.end(), oldPath.begin() + v + 1, oldPath.begin() + w + 1);
            vec3.insert(vec3.end(), oldPath.begin() + u, oldPath.begin() + v + 1);
            vec3.insert(vec3.end(), oldPath.begin() + w + 1, oldPath.end());
            // std::cout << "opt 2 3" << "\n";
        }while(isPathLegal(vec3, true, pickNum, truck_capacity) == false);
        //  std::cout << "opt end" << "\n";
        return vec3;
    }

}

double ramdom0to1() {
    double a = rand() % 100;
    double b = a / double(100);
    return b;
}

std::vector<NodeInfo> perturb(const std::vector<NodeInfo>& oldPath, const float truck_capacity) {
    auto b = ramdom0to1();

    // if(b < 0.16) {
    //     return swapNodes(oldPath, pickNum, truck_capacity);
    // }
    // else 
    if(b < 0.5) {
        return OrderOpt(oldPath, truck_capacity, true);
    }
    else {
        return OrderOpt(oldPath, truck_capacity, false);
    }
    // return swapNodes(oldPath, pickNum, truck_capacity);
    
}

std::vector<NodeInfo> SimulatedAnnealing(const std::vector<NodeInfo>& oldPath, const float truck_capacity, const std::vector<Depot2Node> &allInterDepotPath, 
const std::unordered_map<int, PathInfo> &allPaths, const std::vector<NodeInfo> &depots) {
    const double Tmin = 0.001;
    const double Tinitial = 100000;
    double T = Tinitial;
    int l = 20;
    auto result = oldPath;
    double cost;
    double time = 0;
    if(oldPath.size() <= 8)
        return oldPath;
    std::vector<NodeInfo> bestR = oldPath;
    auto bestCost = pathCost(result, allInterDepotPath, allPaths, depots);
    cost = pathCost(result, allInterDepotPath, allPaths, depots);

    // std::cout<< "start at " << pathCost(result, allInterDepotPath, allPaths, depots) <<"\n" ;
    while(1) {
        for (int i = 0; i <= l ; i ++) {

            

            auto newResult = perturb(result, truck_capacity);
            // newResult = perturb(newResult, truck_capacity);
            if(ramdom0to1() <  std::exp(- 1 / (T *T) )){
                newResult = perturb(newResult, truck_capacity);
                if(ramdom0to1() < std::exp(- 1 /  T )) {
                    newResult = perturb(newResult, truck_capacity);
                    // if(ramdom0to1() < std::exp(- 10 /  T )) {
                    //     newResult = perturb(newResult, truck_capacity);
                    // }
                }
            }
                
            auto newCost = pathCost(newResult, allInterDepotPath, allPaths, depots);

            if(newCost < bestCost) {
                bestCost = newCost;
                bestR = newResult;
            }
            // std::cout<< newCost <<"\n" ;
            if( newCost < cost  ){
                // std::cout << "swap" <<"\n";
                result = newResult;
                cost = newCost;
                // std::cout<< newCost <<"\n" ;

            }
            else if(ramdom0to1() < std::exp( -(newCost - cost) / (T/100 ) ) && i == 0) {
                result = newResult;
                cost = newCost;
                // std::cout<< newCost <<"\n" ;
            }
        }
        time += 1;
        // T = Tinitial / (1 + time);
        T = 0.998 * T;
        // std::cout<< cost <<"\n" ;
        auto currentTime= std::chrono::high_resolution_clock::now(); 
        auto wallClock =std::chrono::duration_cast<std::chrono::duration<double>>(currentTime - startTime);
        if(wallClock.count() > TIME_LIMIT)
            break;
        
    }

    if(bestCost < pathCost(result, allInterDepotPath, allPaths, depots))
        return bestR;

    // std::cout<< "final result returned" <<"\n" ;
    return result;
}

std::vector<NodeInfo> completePath(const std::vector<NodeInfo>& path, const float truck_capacity, const std::vector<Depot2Node> &allInterDepotPath, 
const std::unordered_map<int, PathInfo> &allPaths, const std::vector<NodeInfo> &depots) {
    
    std::vector<NodeInfo> cpath = path;
    NodeInfo fn;
    fn.intersectionID = allInterDepotPath[path[0].intersectionID].depotInterId;
    fn.depot = true;
    cpath.push_back( fn );
    // auto nearest =  nearestDepot[nodes[nodes.size() - 1].intersectionID];


    int minT = getPathTime(allPaths, path[path.size() - 1].intersectionID, depots[0].intersectionID);
    int minD = depots[0].intersectionID;

    for(int i = 0; i < depots.size(); i++) {
        if(minT > getPathTime(allPaths, path[path.size() - 1].intersectionID, depots[i].intersectionID)) {
            minT = getPathTime(allPaths, path[path.size() - 1].intersectionID, depots[i].intersectionID);
            minD = depots[i].intersectionID;
        }
    }

    fn.intersectionID = minD;
    cpath.push_back(fn);

    return cpath;

}

std::vector<CourierSubpath> traveling_courier(
		            const std::vector<DeliveryInfo>& deliveries,
	       	        const std::vector<int>& depots, 
		            const float turn_penalty, 
		            const float truck_capacity) {

    startTime= std::chrono::high_resolution_clock::now();
    std::srand(1586343441);
    //  std::srand(time(0));
    // auto y = 1586363211 / 2;
    // std::srand(y);
    // std::cout << y << "\n";


    NUMINTERS = getNumIntersections();
    pickNum = deliveries.size();
    std::vector<CourierSubpath> dummy;
    auto nodesAndDepots = DeliveryInfo2NodeInfo(deliveries, depots);
    auto nodes = nodesAndDepots.first;
    auto depotNodes = nodesAndDepots.second;
    

    std::pair<std::vector<Depot2Node>, std::multimap<double, int> > depotPathandTime;
    std::unordered_map<int, PathInfo> allPaths;

    depotPathandTime = find_paths_from_depots_to_nodes(depotNodes, turn_penalty, nodes);
    allPaths = compute_path_between_points(nodes, turn_penalty, depotNodes);



    
    

    
   
    bool firstShow = true;
    bool returnDummy = false;

    double minCost = 3000000;
    int minI;
    std::map<double, std::vector<NodeInfo> > paths;
    std::vector<std::vector<NodeInfo>> pathsVec(4);
    std::map<double, std::vector<NodeInfo> > sapaths;

    // return convertNodepathtoCourierSubPath(basic_find_path(deliveries, depots, turn_penalty, truck_capacity, depotPathandTime, allPaths, nodesAndDepots), depotPathandTime, allPaths);

    
    auto beforeTime= std::chrono::high_resolution_clock::now();

   

   

     
    // while(wallClock.count() < 0.4 * TIME_LIMIT){
        #pragma omp parallel for
        for(int i = 0; i < 4; i ++) {

            auto tpath = basic_find_path(deliveries, depots, turn_penalty, truck_capacity, depotPathandTime, allPaths, nodesAndDepots);
            auto vpath = tpath;
            if(tpath.size() == 0 && firstShow){
                returnDummy = true;
            }
            vpath.pop_back();
            vpath.pop_back();

            if(tpath.size() != 0) {
                paths.insert(std::make_pair(pathCost(vpath, depotPathandTime.first, allPaths, depotNodes), tpath));
                pathsVec[i] = tpath;
            }

            firstShow = false;
        }



        if(returnDummy)
            return dummy;

        if(deliveries.size() < 10)
             return convertNodepathtoCourierSubPath( paths.begin()->second , depotPathandTime, allPaths);

        #pragma omp parallel for
        for(int i = 0; i < 4; i ++) {
            auto tempPa = pathsVec[i];
            if(tempPa.size() == 0)
                continue;
            tempPa.pop_back();
            tempPa.pop_back();

            auto cupath = SimulatedAnnealing(tempPa, truck_capacity, depotPathandTime.first, allPaths, depotNodes);

            pathsVec[i] = cupath;
            sapaths.insert(std::make_pair(pathCost(cupath, depotPathandTime.first, allPaths, depotNodes), cupath));
        }

        auto afterTime= std::chrono::high_resolution_clock::now(); 
        auto wallClock1 =std::chrono::duration_cast<std::chrono::duration<double>>(afterTime - beforeTime);

        // std::cout<< wallClock1.count() << "\n";



        auto currentTime= std::chrono::high_resolution_clock::now(); 
        auto wallClock =std::chrono::duration_cast<std::chrono::duration<double>>(currentTime - startTime);

        // while(wallClock.count() + wallClock1.count()/2  < 0.9 * TIME_LIMIT) {

        //     // std::cout<< "second in" << "\n";
            
        //     #pragma omp parallel for
        //     for(int i = 0; i < 1; i ++) {

        //     auto tpath = pathsVec[i];
            
            

        //     if(tpath.size() != 0) {
        //         // paths.insert(std::make_pair(pathCost(vpath, depotPathandTime.first, allPaths, depotNodes), tpath));
        //         pathsVec[i] = tpath;
        //     }

        // }



        // #pragma omp parallel for
        // for(int i = 0; i < 4; i ++) {
        //     auto tempPa = pathsVec[i];
        //     if(tempPa.size() == 0)
        //         continue;
            

        //     auto cupath = SimulatedAnnealing(tempPa, truck_capacity, depotPathandTime.first, allPaths, depotNodes);

        //     sapaths.insert(std::make_pair(pathCost(cupath, depotPathandTime.first, allPaths, depotNodes), cupath));

        //     pathsVec[i] = cupath;
        // }

        // currentTime= std::chrono::high_resolution_clock::now(); 
        // wallClock =std::chrono::duration_cast<std::chrono::duration<double>>(currentTime - startTime);

        // }

        // std::cout << sapaths.begin()->first << "\n";


    //     currentTime= std::chrono::high_resolution_clock::now();
    //              wallClock =std::chrono::duration_cast<std::chrono::duration<double>>(currentTime - startTime);
    // }
    

    // auto tempPa = paths.begin()->second;
    // tempPa.pop_back();
    // tempPa.pop_back();


    // SimulatedAnnealing(tempPa, truck_capacity, depotPathandTime.first, allPaths, depotNodes);
    
    // auto testPath = OrderOpt(tempPa, truck_capacity, true);
    // for(int i = 0; i < paths.begin()->second.size(); i ++) {
    //     std::cout<< paths.begin()->second[i].pickupID << ":" << paths.begin()->second[i].type << "->";
    // }
    // std::cout << "\n------------------------------------------------\n" ;

    // for(int i = 0; i < testPath.size(); i ++) {
    //     std::cout<< testPath[i].pickupID << ":" << testPath[i].type << "->";
    // }
    // std::cout << "\n------------------------------------------------\n" << isPathLegal(testPath, true, pickNum, truck_capacity) << "\n";


    

    return convertNodepathtoCourierSubPath( completePath(sapaths.begin()->second, truck_capacity, depotPathandTime.first, allPaths, depotNodes) , depotPathandTime, allPaths);
    // completePath(paths.begin()->second, truck_capacity, depotPathandTime.first, allPaths, depotNodes)
    
}

