/* 
 * Copyright 2020 University of Toronto
 *
 * Permission is hereby granted, to use this software and associated 
 * documentation files (the "Software") in course work at the University 
 * of Toronto, or for personal use. Other uses are prohibited, in 
 * particular the distribution of the Software either publicly or to third 
 * parties.
 *
 * The above copyright notice and this permission notice shall be included in 
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
// master branch
#pragma once
#include "m1.h"
#include "m3.cpp"

#include "StreetsDatabaseAPI.h"
#include <cmath>
#include "algorithm"
#include "iterator"
#include <map>
#include <unordered_map>
#include "OSMDatabaseAPI.h"
std::string format(std::string s1);
double determinant(LatLon p1, LatLon p2, double latave);
//Define your map related data structures here

    //Gengyang Wang-----------------------------------------------------------------------------------------
    std::multimap<std::string, int> streetName;//to store street names
    std::vector<InfoStreetSegment> streetSegmentsInfo;//prepare all segment information in order to gain quick access
    std::vector<double>featureAreas; //in order to store all areas for quick access
    
    
    
    //Gengyang Wang-----------------------------------------------------------------------------------------
    
    //Xin Zhao----------------------------------------------------------------------------------------------
    std::vector<double> streetSegLengthData;//to store every seg's length
    std::vector<double> streetSegTimeData;//to store travel time for streetsegs
    std::vector<double> OSMWayLengthData;//to store OSMWay length by index
    std::unordered_map<OSMID, const OSMNode*> OSMID_OSMNodes;//to store OSMNode's OSMID infos
    std::unordered_map<OSMID, int> OSMID_OSMWayID;//to store OSMWay's OSMID infos
    std::vector<int> primarySegs;
    std::vector<int> motorwaySegs;
    std::vector<int> trunkSegs;
    std::vector<int> secondarySegs;
    std::vector<int> tertiarySegs;
    std::vector<int> elseSegs;
    std::vector<double> curvatureSegs;
    std::vector<const OSMRelation *> OSMbus;
    std::vector<const OSMRelation *> OSMsubway;
    std::vector<const OSMRelation *> OSMtrain;
    std::vector<const OSMRelation *> OSMtram;
    std::multimap<std::string, int> pointOfInterestName;
    std::vector<LatLon> featuresMidP;
    std::vector<double> featuresMaxX;

    // double maxSpeed = 0;
    //Xin Zhao----------------------------------------------------------------------------------------------
    //Yanchi Fang-------------------------------------------------------------------------------------------
    std::vector< std::pair< std::vector<int>, std::vector<std::string> > > intersectionsInfo; //to store the street segments and street names of intersections
    std::vector<std::vector<int>> streetSegId; //to store all street segments of a street (for all streets)
    std::vector<std::vector<int>> streetIntersectionId; //to store all intersections on a street (for all streets)
    std::vector<std::vector<int>> pointOfInterest;
    //Yanchi Fang-------------------------------------------------------------------------------------------

    //
//helper function to remove space and upper letter
std::string format(std::string s1) {
    std::string s2;
    for (int j = 0; j < s1.size(); j ++) {
        if(s1.at(j) != char(32)) {
            s2.push_back(std::tolower(s1.at(j)));
        }
    }
    return s2;
}
std::vector<int> find_POI_ids_from_partial_POI_name(std::string POI_prefix);
//helper function to calculate the derterminant of 2 points
double determinant(LatLon p1, LatLon p2, double latave) {
    double latCOS = std::cos(latave);
    double X1 = p1.lon() * DEGREE_TO_RADIAN * latCOS;
    double X2 = p2.lon() * DEGREE_TO_RADIAN * latCOS;
    double Y1 = p1.lat() * DEGREE_TO_RADIAN;
    double Y2 = p2.lat() * DEGREE_TO_RADIAN;
    return (X1 * Y2 - X2 * Y1) * EARTH_RADIUS_METERS * EARTH_RADIUS_METERS;
}

bool load_map(std::string map_path) {

    bool load_successful = false; //Indicates whether the map has loaded 
    load_successful = loadStreetsDatabaseBIN(map_path);
    std::string OSMMap_path = map_path;
    for(int i = 0; i < 11; i ++) {
        OSMMap_path.pop_back();
    }
    OSMMap_path += "osm.bin";
    if (!load_successful)
        return false; //return false if load..BIN fail
    load_successful = loadOSMDatabaseBIN(OSMMap_path);
    if (!load_successful)
        return false; //return false if load..BIN fail
    //successfully
    streetSegId.resize(getNumStreets());
    streetIntersectionId.resize(getNumStreets());
    //
    //Load your map related data structures here

    //Gengyang Wang-----------------------------------------------------------------------------------------
    //resize data containers to avoid push_back time waste
    featureAreas.resize(getNumFeatures());
    featuresMidP.resize(getNumFeatures());
    featuresMaxX.resize(getNumFeatures());
    streetSegmentsInfo.resize(getNumStreetSegments());
    //store all infoStreetSegment to avoid API usage
    for(int i = 0; i<getNumStreetSegments(); i++)
    {
        streetSegmentsInfo[i]= getInfoStreetSegment(i);
    }
    
    //area calculation and storing
    for(int i=0; i<getNumFeatures(); i++)
    {
        int pointsCount = getFeaturePointCount(i);
        //get the first point and last point to make sure it's closed
        LatLon point0 = getFeaturePoint(0, i);
        LatLon pointn = getFeaturePoint(pointsCount - 1, i);
        //return 0 if it is not closed
        if( point0.lat() != pointn.lat() || point0.lon() != pointn.lon()) {
            
            featureAreas[i] = 0;
            continue;
        }

        //calculate feature points avg lat
        double latave = 0;
        double lonave = 0;
        double maxLon = getFeaturePoint(0, i).lon();
        double minLon = getFeaturePoint(0, i).lon();

        double maxLat = getFeaturePoint(0, i).lat();
        double minLat = getFeaturePoint(0, i).lat();
        for(int j = 0; j < pointsCount; j ++) {
            if(getFeaturePoint(j, i).lon() > maxLon) {
                maxLon = getFeaturePoint(j, i).lon();
            }
            if(getFeaturePoint(j, i).lon() < minLon) {
                minLon = getFeaturePoint(j, i).lon();
            }
            if(getFeaturePoint(j, i).lat() > maxLat) {
                maxLat = getFeaturePoint(j, i).lat();
            }
            if(getFeaturePoint(j, i).lat() < minLat) {
                minLat = getFeaturePoint(j, i).lat();
            }
            latave += getFeaturePoint(j, i).lat() * DEGREE_TO_RADIAN;
            lonave += getFeaturePoint(j, i).lon() * DEGREE_TO_RADIAN;

        }
        latave = (latave / DEGREE_TO_RADIAN) / pointsCount;
        lonave = (lonave / DEGREE_TO_RADIAN) / pointsCount;

        LatLon midP((maxLat + minLat) / 2, (maxLon + minLon) / 2);
        // if(getFeatureName(i) == "Ron Searle Park") {
        //     std::cout<< latave << " " << lonave << "\n";
        // }
        featuresMidP[i] = midP;
        featuresMaxX[i] = maxLon - minLon;

        double area = 0;
        //accumulate all the dets to find the total area
        for(int j = 0; j < pointsCount - 1; j ++) {
            if(i == pointsCount - 2) {
                area += determinant(getFeaturePoint(j, i), getFeaturePoint(0, i), latave);
            }
            else {
                area += determinant(getFeaturePoint(j, i), getFeaturePoint(j + 1, i), latave);
            }
        }
        //make sure area values are positive
        
        featureAreas[i] = fabs(0.5 * area);
    }

    //Gengyang Wang-----------------------------------------------------------------------------------------

    //Xin Zhao----------------------------------------------------------------------------------------------
    //load streetsegs infos
    for(int j = 0, m = getNumStreetSegments(); j < m; j ++) {
        //load length
        InfoStreetSegment streetSeg = getInfoStreetSegment(j);
        if(maxSpeed < streetSeg.speedLimit)
            maxSpeed = streetSeg.speedLimit;
        double length = 0;
        std::pair<LatLon, LatLon> points;
        LatLon from = getIntersectionPosition(streetSeg.from);
        LatLon to = getIntersectionPosition(streetSeg.to);
        //loop over the curve points to compute the total length
        for(int i = 0, n = streetSeg.curvePointCount; i <= n; i ++) {
            if (i == 0 && n != 0) {
                points.first = from;
                points.second = getStreetSegmentCurvePoint(i, j);
            }
            //when there is no curve point
            else if (i == 0 && n == 0) {
                points.first = from;
                points.second = to;
            }
            else if (i == n) {
                points.first = getStreetSegmentCurvePoint(i - 1, j);
                points.second = to;
            }
            else {
                points.first = getStreetSegmentCurvePoint(i - 1, j);
                points.second = getStreetSegmentCurvePoint(i, j);
            }
            length += find_distance_between_two_points(points);
        }
        auto directLength = find_distance_between_two_points(std::make_pair(from, to));
        streetSegLengthData.push_back(length);

        auto curvature = length / directLength;

        curvatureSegs.push_back(curvature);

        //load travel time
        streetSegTimeData.push_back( length / (0.27777777777 * streetSeg.speedLimit) );
    
    }

    //load OSMNodes by OSMID
    for(int i = 0; i < getNumberOfNodes(); i ++) {
        auto node = getNodeByIndex(i);
        OSMID_OSMNodes.insert( std::make_pair(node->id(), node) );
    }
    //load OSMWays by OSMID 
    for(int i = 0; i < getNumberOfWays(); i ++) {
            auto way = getWayByIndex(i);
            OSMID_OSMWayID.insert( std::make_pair(way->id(), i) );
        }
        //load and compute length for each OSMWay
        
    for(int i = 0; i < getNumberOfWays(); i ++) {
        double length = 0;
        auto Way = getWayByIndex(i);
        auto nodes = getWayMembers(Way);
        std::vector<LatLon> points;
        for(int j = 0; j < nodes.size(); j ++) {
            points.push_back( (OSMID_OSMNodes.find(nodes[j]))->second->coords() );
        }
        for(int j = 0; j < points.size() - 1; j ++) {
            length += find_distance_between_two_points(std::make_pair(points[j], points[j + 1]));
        }
        OSMWayLengthData.push_back(length);
    }

    for(int j = 0; j < getNumStreetSegments(); j++) {
        
        InfoStreetSegment info = getInfoStreetSegment(j);
        auto osmid = info.wayOSMID;
        auto osmwayid = OSMID_OSMWayID.find(osmid)->second;
        auto osmway = getWayByIndex(osmwayid);
        bool loadC = false;
    
        for (unsigned w = 0; w < getTagCount(osmway); w++) 
        {
            auto tagPair = getTagPair(osmway, w);
            if (tagPair.first == "highway" && (tagPair.second == "primary" || tagPair.second == "primary_link"))
            {
                primarySegs.push_back(j);
                loadC = true;
                break;
            }
            else if (tagPair.first == "highway" && (tagPair.second == "motorway" || tagPair.second == "motorway_link"))
            {
                motorwaySegs.push_back(j);
                loadC = true;
                break;
            }
            else if (tagPair.first == "highway" && (tagPair.second == "trunk" || tagPair.second == "trunk_link"))
            {
                trunkSegs.push_back(j);
                loadC = true;
                break;
            }
            else if (tagPair.first == "highway" && (tagPair.second == "secondary" || tagPair.second == "secondary_link"))
            {
                secondarySegs.push_back(j);
                loadC = true;
                break;
            }
            else if (tagPair.first == "highway" && (tagPair.second == "tertiary" || tagPair.second == "tertiary_link"))
            {
                tertiarySegs.push_back(j);
                loadC = true;
                break;
            }
        }

        if(!loadC) {
            elseSegs.push_back(j);
        }
    }

    for(int i = 0;i < getNumberOfRelations(); i++) {
        const OSMRelation *currRel = getRelationByIndex(i);
        for (unsigned j = 0; j < getTagCount(currRel); j++) {
            std::pair<std::string, std::string> tagPair = getTagPair(currRel, j);
            if (tagPair.first == "route" && tagPair.second == "subway") {
                OSMsubway.push_back(currRel);
                break;
            }
            if (tagPair.first == "route" && tagPair.second == "bus") {
                OSMbus.push_back(currRel);
                break;
            }
            if (tagPair.first == "route" && tagPair.second == "train") {
                OSMtrain.push_back(currRel);
                break;
            }
            if (tagPair.first == "route" && tagPair.second == "tram") {
                OSMtram.push_back(currRel);
                break;
            }


        }

    }

    // for(int i = 0; i < OSMsubway.size(); i++) {
    //     for(int j =0; j < getTagCount(OSMsubway[i]); j ++) {
    //         auto tagpair = getTagPair(OSMsubway[i], j);
    //         if(tagpair.first == "colour") {
    //             std::cout << tagpair.second << "\n";
    //         }
    //     }
    // }
    //Xin Zhao----------------------------------------------------------------------------------------------
    
    //Yanchi Fang-------------------------------------------------------------------------------------------
    //load intersection info
    //go to one intersection each time
    pointOfInterest.resize(13);
    for (int i=0; i<getNumPointsOfInterest(); i++){ 
        pointOfInterestName.insert(std::make_pair(format(getPointOfInterestName(i)), i));

        if (getPointOfInterestType(i)=="restaurant"){
            pointOfInterest[0].push_back(i);
        }
        else if (getPointOfInterestType(i)=="cafe"){
            pointOfInterest[1].push_back(i);
        }
        else if (getPointOfInterestType(i)=="cinema"){
            pointOfInterest[2].push_back(i);
        }
        else if (getPointOfInterestType(i)=="theatre"){
            pointOfInterest[3].push_back(i);
        }
        else if (getPointOfInterestType(i)=="pharmacy"){
            pointOfInterest[4].push_back(i);
        } 
        else if (getPointOfInterestType(i)=="university" || getPointOfInterestType(i)=="school"){
            pointOfInterest[5].push_back(i);
        } 
        else if (getPointOfInterestType(i)=="bank"){
            pointOfInterest[6].push_back(i);
        } 
        else if (getPointOfInterestType(i)=="atm"){
            pointOfInterest[7].push_back(i);
        }
        else if (getPointOfInterestType(i)=="hospital"){
            pointOfInterest[8].push_back(i);
        }
        else if (getPointOfInterestType(i)=="fast_food"){
            pointOfInterest[9].push_back(i);
        }
        else if (getPointOfInterestType(i)=="pub"){
            pointOfInterest[10].push_back(i);
        }
        else if (getPointOfInterestType(i)=="dentist"){
            pointOfInterest[11].push_back(i);
        }
        else if (getPointOfInterestType(i)=="library"){
            pointOfInterest[12].push_back(i);
        }
    }

    for (int i = 0; i< 13 ; i++) {
        random_shuffle(pointOfInterest[i].begin(), pointOfInterest[i].end());
    }
    for (int i=0, n=getNumIntersections(); i < n; i++) {
        std::vector<int> streetSegOneIntersection;
        std::vector<std::string> streetNameOneIntersection; 
        //get all street segments for one intersection 
        int streetSegCount = getIntersectionStreetSegmentCount (i);
        //add each street seg into the vector of intersection
        //add each street name into the vector of intersection
        for (int j=0; j<streetSegCount; j++) {
            streetSegOneIntersection.push_back(getIntersectionStreetSegment(i, j));
            //first use street segments to get streetID
            //then use streetID to get street names
            //add each street name into the vector each time
            streetNameOneIntersection.push_back(getStreetName(getInfoStreetSegment(getIntersectionStreetSegment(i, j)).streetID));
        }
        //make pair of these two vectors of intersection
        //add to the global vector of intersection
        intersectionsInfo.push_back(std::make_pair(streetSegOneIntersection,streetNameOneIntersection));
    }
    
    //load street info
    //load street segments to the vector of street
    for (int i=0; i<getNumStreetSegments(); i++) {
        streetSegId[getInfoStreetSegment(i).streetID].push_back(i);
    }
    
    //use street segments to get intersections
    //load intersections to the vector of street
    for (int i=0; i<getNumStreets(); i++) {
        for(int j=0; j<streetSegId[i].size(); j++){
            streetIntersectionId[i] .push_back(getInfoStreetSegment(streetSegId[i][j]).from);
            streetIntersectionId[i] .push_back(getInfoStreetSegment(streetSegId[i][j]).to);

        }
        //delete duplicate intersections
        std::sort(streetIntersectionId[i].begin(), streetIntersectionId[i].end());
        streetIntersectionId[i].erase(std::unique(streetIntersectionId[i].begin(), streetIntersectionId[i].end()), streetIntersectionId[i].end());
        std::sort(streetSegId[i].begin(), streetSegId[i].end());
        streetSegId[i].erase(std::unique(streetSegId[i].begin(), streetSegId[i].end()), streetSegId[i].end());
        //load streetNames
        std::string s1 = getStreetName(i);
        streetName.insert(std::make_pair(format(s1), i));
    }
    //Yanchi Fang-------------------------------------------------------------------------------------------

    //
    load_successful = true; //Make sure this is updated to reflect whether
                            //loading the map succeeded or failed
    std::cout << "Load map completed" << "\n";
    return load_successful;
}

void close_map() {
    //Clean-up your map related data structures here
    //Gengyang Wang-----------------------------------------------------------------------------------------
    streetSegmentsInfo.clear();
    featureAreas.clear();
    //Gengyang Wang-----------------------------------------------------------------------------------------
    
    //Xin Zhao----------------------------------------------------------------------------------------------
    streetSegLengthData.clear();
    streetSegTimeData.clear();
    OSMID_OSMNodes.clear();
    OSMWayLengthData.clear();
    OSMID_OSMWayID.clear();
    streetName.clear();
    primarySegs.clear();
    motorwaySegs.clear();
    trunkSegs.clear();
    secondarySegs.clear();
    tertiarySegs.clear();
    elseSegs.clear();
    OSMsubway.clear();
    OSMtrain.clear();
    OSMtram.clear();
    OSMbus.clear();
    featuresMidP.clear();
    featuresMaxX.clear();
    //Xin Zhao----------------------------------------------------------------------------------------------
    
    //Yanchi Fang-------------------------------------------------------------------------------------------
    intersectionsInfo.clear();
    streetSegId.clear();
    streetIntersectionId.clear();
    pointOfInterest.clear();
    pointOfInterestName.clear();
    //Yanchi Fang-------------------------------------------------------------------------------------------
    //
    closeStreetDatabase();
    closeOSMDatabase();
    
}

//ZX O(1)
//Returns the distance between two coordinates in meters
double find_distance_between_two_points(std::pair<LatLon, LatLon> points) {
    double latave;
    latave = (points.first.lat() * DEGREE_TO_RADIAN + points.second.lat() * DEGREE_TO_RADIAN) / 2; //calculate average lat
    //Compute distance using the equation from m1.pdf
    double latCOS = std::cos(latave);
    double X1_X2 = points.first.lon() * DEGREE_TO_RADIAN * latCOS - points.second.lon() * DEGREE_TO_RADIAN * latCOS;
    double Y1_Y2 = points.first.lat() * DEGREE_TO_RADIAN - points.second.lat() * DEGREE_TO_RADIAN;
    return std::sqrt(X1_X2 * X1_X2 + Y1_Y2 * Y1_Y2) * EARTH_RADIUS_METERS;
}

//ZX O(1)
//Returns the length of the given street segment in meters
double find_street_segment_length(int street_segment_id) {
    return streetSegLengthData[street_segment_id];
}

//ZX O(1)
//Returns the travel time to drive a street segment in seconds 
//(time = distance/speed_limit)
double find_street_segment_travel_time(int street_segment_id) {
    return streetSegTimeData[street_segment_id];
}

//ZX O(N)
//Returns the nearest intersection to the given position
int find_closest_intersection(LatLon my_position) {
    std::pair<LatLon, LatLon> points;
    double minDistance;
    int minIn = 0;
    points.first = my_position;
    //lopp over every intersection to find the closest one
    for(int i = 0, n = getNumIntersections(); i < n; i ++) {
        points.second = getIntersectionPosition(i);
        if(i == 0) {
            minDistance = find_distance_between_two_points(points);
            minIn = i;
        }
        else if(minDistance > find_distance_between_two_points(points)) {
            minDistance = find_distance_between_two_points(points);
            minIn = i;
        }
    }
    return minIn;
}

//YF O(1)
//Returns the street segments for the given intersection 
std::vector<int> find_street_segments_of_intersection(int intersection_id){
    return intersectionsInfo[intersection_id].first;
}
    

//YF O(1)
//Returns the street names at the given intersection (includes duplicate street 
//names in returned vector)
std::vector<std::string> find_street_names_of_intersection(int intersection_id) {
    return intersectionsInfo[intersection_id].second;
}

//WGY O(1)
//Returns true if you can get from intersection_ids.first to intersection_ids.second using a single 
//street segment (hint: check for 1-way streets too)
//corner case: an intersection is considered to be connected to itself
bool are_directly_connected(std::pair<int, int> intersection_ids) {

    
    
    std::vector<int> segment_id1 = find_street_segments_of_intersection(intersection_ids.first);
    std::vector<int> segment_id2 = find_street_segments_of_intersection(intersection_ids.second);
    if (intersection_ids.first == intersection_ids.second)
    {
        return true;
    }
    for(int i = 0; i<segment_id1.size(); i++)
    {
        InfoStreetSegment firstSeg = streetSegmentsInfo[segment_id1[i]];
        bool direction = firstSeg.oneWay;
         int from = firstSeg.from;
         int to = firstSeg.to;
        if(((from == intersection_ids.first)&&(to == intersection_ids.second) )
                || ((from == intersection_ids.second) && (to == intersection_ids.first) && (direction != 1)))
        {
            return true;
        }
        
    }
    return false;
    
}

//WGY O(1)
//Returns all intersections reachable by traveling down one street segment 
//from given intersection (hint: you can't travel the wrong way on a 1-way street)
//the returned vector should NOT contain duplicate intersections
std::vector<int> find_adjacent_intersections(int intersection_id) {
    std::vector<int> adjacentIntersections;
    std::vector<int> streetSegments = find_street_segments_of_intersection(intersection_id);
    //go through all segments of the intersection and check if their segments are one way or both way and whether they satisfy directly connected conditions
    for(int i=0; i<streetSegments.size(); i++) {
        InfoStreetSegment streetSeg = streetSegmentsInfo[streetSegments[i]];
        if(!streetSeg.oneWay) {
            //if it's one way road, check if the intersection is at from, if it is, intersections are still directly connected
            if(streetSeg.from == intersection_id) {
                adjacentIntersections.push_back(streetSeg.to);
            }
            else {
                adjacentIntersections.push_back(streetSeg.from);
            }
        }
        else if(streetSeg.from == intersection_id) {
            adjacentIntersections.push_back(streetSeg.to);
        }
    }
    //delete duplicate elements
    std::sort(adjacentIntersections.begin(), adjacentIntersections.end());
    adjacentIntersections.erase(std::unique(adjacentIntersections.begin(), adjacentIntersections.end()), adjacentIntersections.end());
    return adjacentIntersections;
}

//YF
//O(1)
//Returns all street segments for the given street
std::vector<int> find_street_segments_of_street(int street_id) {
    return streetSegId[street_id];
}

//YF 
//O(1)
//Returns all intersections along the a given street
std::vector<int> find_intersections_of_street(int street_id) {
    return streetIntersectionId[street_id];
}

//WGY O(1)
//Return all intersection ids for two intersecting streets
//This function will typically return one intersection id.
std::vector<int> find_intersections_of_two_streets(std::pair<int, int> street_ids) { 
    std::vector<int> intersections;
    std::vector<int> streetInter1 = find_intersections_of_street(street_ids.first);
    std::vector<int> streetInter2 = find_intersections_of_street(street_ids.second);
    // sort all intersections and use the offered function from library to find intersections of two vectors
    std::sort(streetInter1.begin(), streetInter1.end());
    std::sort(streetInter2.begin(), streetInter2.end());
    std::set_intersection(streetInter1.begin(), streetInter1.end(), streetInter2.begin(), streetInter2.end(), std::back_inserter(intersections));   
    return intersections;
}

//WGY O(LOGN)
//Returns all street ids corresponding to street names that start with the given prefix
//The function should be case-insensitive to the street prefix. You should ignore spaces.
//For example, both "bloor " and "BloOrst" are prefixes to "Bloor Street East".
//If no street names match the given prefix, this routine returns an empty (length 0) 
//vector.
//You can choose what to return if the street prefix passed in is an empty (length 0) 
//string, but your program must not crash if street_prefix is a length 0 string.
std::vector<int> find_street_ids_from_partial_street_name(std::string street_prefix)  {
    std::vector<int> streets;
    std::vector<int> dummy;
    if(street_prefix.size() == 0) {
        return dummy;
    }
    std::string slf, sla;
    slf = format(street_prefix);
    sla = slf;
    //find the one with same key
    for(auto it = streetName.equal_range(slf); it.first != it.second; it.first ++) {
        streets.push_back(it.first->second);
    }
    //insert the lower bound and upper bound to find matched key
    sla.at(sla.size() - 1) = char(int(sla.at(sla.size() - 1)) + 1);
    auto it1 = streetName.insert(std::make_pair(slf, -1));
    auto it2 = streetName.insert(std::make_pair(sla, -1));
    for(auto it = it1; it != it2; it ++) {
        if(it != it1) 
            streets.push_back(it->second);
    }
    streetName.erase(it2);
    streetName.erase(it1);
    return streets;
}

//WGY O(1)
//Returns the area of the given closed feature in square meters
//Assume a non self-intersecting polygon (i.e. no holes)
//Return 0 if this feature is not a closed polygon.
double find_feature_area(int feature_id) {
    //return a certain value from calculated container
    
    return featureAreas[feature_id];
}

//ZX O(1)
//Returns the length of the OSMWay that has the given OSMID, in meters.
//To implement this function you will have to  access the OSMDatabaseAPI.h 
//functions.
double find_way_length(OSMID way_id) {
    auto wayID = OSMID_OSMWayID.find(way_id)->second;
    return OSMWayLengthData[wayID];
}



std::vector<int> find_POI_ids_from_partial_POI_name(std::string POI_prefix)  {
    std::vector<int> streets;
    std::vector<int> dummy;
    if(POI_prefix.size() == 0) {
        return dummy;
    }
    std::string slf, sla;
    slf = format(POI_prefix);
    sla = slf;
    //find the one with same key
    for(auto it = pointOfInterestName.equal_range(slf); it.first != it.second; it.first ++) {
        streets.push_back(it.first->second);
    }
    //insert the lower bound and upper bound to find matched key
    sla.at(sla.size() - 1) = char(int(sla.at(sla.size() - 1)) + 1);
    auto it1 = pointOfInterestName.insert(std::make_pair(slf, -1));
    auto it2 = pointOfInterestName.insert(std::make_pair(sla, -1));
    for(auto it = it1; it != it2; it ++) {
        if(it != it1) 
            streets.push_back(it->second);
    }
    pointOfInterestName.erase(it2);
    pointOfInterestName.erase(it1);
    return streets;
}
