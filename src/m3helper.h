#pragma once
#include "algorithm"
#include "m1.h"
#include <queue>



//Defined the struct that will be use in the priority queue
struct DNode {
    int id;
    double time;
    double etime; // used in astar algoritm
    int path; // the segment that will reach this intersection
    friend bool operator < (struct DNode a, struct DNode b)
    {
        return a.etime >= b.etime;
    }
};
// compute the estimated time that will be use in a_star

void compute_etime(DNode * n, int end = -1, int stype = -1, double speed = -1.0);

//use dijkstra to find all reachable intersections within the walking time limits
void find_inters_walklimit(const IntersectionIndex start_intersection, const double turn_penalty, const double walking_speed, 
                            const double walking_time_limit, std::vector<int>* intersreach, std::vector<int>* intersWithinRange);
// trace back the path that reach the endpoint
std::vector<StreetSegmentIndex> back_trace(const IntersectionIndex intersect_id_end, std::vector<int> intersreach, int * startID = nullptr);
// astat algoritm to find the shortest path
std::vector<StreetSegmentIndex> a_star(const IntersectionIndex intersect_id_start, const IntersectionIndex intersect_id_end, 
                                    const double turn_penalty, bool walk = false, double walkspeed = -1);
// multiple sources shortest path algorithm
std::vector<StreetSegmentIndex> multiple_startpoints(const IntersectionIndex intersect_id_end, const double turn_penalty, std::vector<int> intersw);