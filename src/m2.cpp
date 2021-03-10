/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#pragma once
#include "m2.h"
#include "algorithm"
#include "m1.h"
#include "application.hpp"
#include "ezgl/graphics.hpp"
#include <cmath>
#include "StreetsDatabaseAPI.h"
#include "OSMDatabaseAPI.h"
#include "m1.cpp"
#include "internet.cpp"
#include "math.h"
#include "iostream"
#include "string.h"
#include "curl/curl.h"
#include "boost/property_tree/ptree.hpp"
#include "boost/property_tree/json_parser.hpp"
#include "boost/foreach.hpp"
#include "string"
#include "list"
#include "m3.h"
#include "m4.h"
int firstinter = -1;
int secondinter = -1;

std::string searchText1;
std::string searchText2;

bool firstBarA = false;
bool secondBarA = false;
bool drivingA = false;
bool walkingA = false;
bool wplusdA = false;

bool routeMode = false;
bool infointermode = false;
bool routeSetting = false;
bool help = false;

double walkingSpeed = 1.25;
double walkingTimeLimit = 300;

ezgl::rectangle searchBar2;
ezgl::rectangle searchBar1;

ezgl::rectangle navi_step_1;
ezgl::rectangle navi_step_2;
bool prev_step = 0;
bool next_step = 0;
int step_count = 0;

ezgl::rectangle drivingB;
ezgl::rectangle walkingB;
ezgl::rectangle wplusdB;
ezgl::rectangle swapB;
ezgl::rectangle route_background;
ezgl::rectangle routeCloseB;
ezgl::rectangle routehelpB;
ezgl::rectangle routesetB;
ezgl::rectangle infoboxGoto;

ezgl::rectangle ssearchBar1;
ezgl::rectangle ssearchBar2;
ezgl::rectangle routeSettingBack;


bool ssearchBar1A = false;
bool ssearchBar2A = false;

bool startLocation = false;
bool destination = false;
bool arrows = false;
bool driving = false;
bool walking = false;


bool searchBar1M = false;
bool searchBar2M = false;

std::vector<string> navigationInstructions;
std::vector<int> navigationPoints;
void navigation_text(ezgl::renderer *g);
void show_naviagtion(ezgl::renderer *g);
int midInter(int segment1, int segment2);
void draw_feature_info(ezgl::renderer *g);

bool routeMenuA = false;
ezgl::rectangle routeMenuB;
ezgl::rectangle routeMenuBox;
int naviCount = 0;
bool changeContain = false;
ezgl::rectangle menuUp;
ezgl::rectangle menuDown;
int naviRow = -1;
int naviPressed = -1;
bool routeMoveMid = false;

int exchangeB;
ezgl::point2d exchange_center{0,0};
void draw_route_searchBars(ezgl::renderer *g);
void draw_route_options(ezgl::renderer *g);
void draw_path_inters(ezgl::renderer *g);
void draw_path_inters_text(ezgl::renderer *g);
void draw_spath(ezgl::renderer *g);
void drawRouteBox(ezgl::renderer *g);
string lengthDisplay(double m);
string timeDisplay(double t);
double max_latitude, max_longitude, min_latitude, min_longitude;
double init_x, init_y, end_x, end_y;
std::vector<LatLon> intersectionPosition;
std::vector<std::pair<double, int>> feature_order;
double initialArea = -1;
int POI = -1;
int leftOrRight (int segment1, int segment2, ezgl::renderer *g);
//widgets
//----------------------------------------------
bool drawingWidgets = false;
ezgl::rectangle searchBar = {{50, 20}, 300, 30};
ezgl::rectangle menuB = {{20,20} , 30, 30};
ezgl::rectangle mainMenu = {{20,70}, 330, 500};
ezgl::rectangle menuPop = {{50,70}, 300, 400};
ezgl::rectangle InfoBox;
ezgl::rectangle searchBox = {{20, 70}, 550, 200};
std::string searchText;
ezgl::rectangle weatherBox;
WeatherInfo cWeather;

bool first_menu = false;
bool second_menu = false;
bool third_menu = false;
bool fourth_menu = false;
ezgl::rectangle first_menu_box = {{0, 100},370, 80};
ezgl::rectangle second_menu_box = {{0, 180},370, 80};
ezgl::rectangle third_menu_box = {{0, 260},370, 80};
ezgl::rectangle fourth_menu_box = {{0, 340},370, 80};
ezgl::rectangle fifth_menu_box = {{0, 420},370, 80};
ezgl::rectangle sub_menu = {{370,0},220,80};


int menu_switch = 0;
int sub_menu_switch = 0;

ezgl::rectangle sub_menu_1_box = {{371,0},220,60};
ezgl::rectangle sub_menu_2_box = {{371,60}, 220,60};
ezgl::rectangle sub_menu_3_box = {{371,120},220,60};
ezgl::rectangle sub_menu_4_box = {{371,180},220,60};
ezgl::rectangle sub_menu_5_box = {{371,240},220,60};
ezgl::rectangle sub_menu_6_box = {{371,300},220,60};
ezgl::rectangle sub_menu_7_box = {{371,360},220,60};
ezgl::rectangle sub_menu_8_box = {{371,420},220,60};
ezgl::rectangle sub_menu_9_box = {{371,480},220,60};
ezgl::rectangle sub_menu_10_box = {{371,540},220,60};
ezgl::rectangle sub_menu_11_box = {{371,600},220,60};
ezgl::rectangle sub_menu_12_box = {{371,660},220,60};
ezgl::rectangle sub_menu_13_box = {{371,720},220,60};
ezgl::rectangle sub_menu_14_box = {{371,780},220,60};
ezgl::rectangle sub_menu_15_box = {{371,840},220,60};
ezgl::rectangle sub_menu_16_box = {{371,900},220,60};
ezgl::rectangle route_box = {{620,40},600,200};

void draw_sub_shadow(ezgl::renderer *g);


int barClicked = 0;
bool menuActivated = false;
bool enterPressed = false;
bool onMap = false;
bool enableBuiding = false;
bool enableStreetN = true;
bool infoBoxActivated = false;
bool searchBoxActivated = false;
int clickedFoundInter = -1;
bool movedTomid = false;
int preinterID = -1;
int interID = -1;
int incidentID = -1;
std::pair<bool, OSMID> clickedOSMNode;
bool subwayEn = false;
bool trainEn = false;
bool tramEn = false;
bool weatherEn = false;
bool trafficEn = false;
int searchBI = 0;
int clickedPOI = -1;
std::vector<int> cpath;
std::vector<int> wpath;
std::pair<std::vector<int>, std::vector<int>> wplusdpaths;
int last_intersection_1 = -1;
int last_intersection_2 = -1;
int astar_intersection_1 = -1;
int astar_intersection_2 = -1;
int walk_intersection_1 = -1;
int walk_intersection_2 = -1;
bool loading_map = 0;
std::pair<double, double> worldClickedPoint;
std::string currentMap = "Toronto";
std::vector<int> foundIntersIDs;
std::vector<int> foundPOIIDs;
std::vector<OSMID> currentRelationNodes;
std::unordered_map<OSMID, std::string> nodeRname;
std::vector<IncidentInfo> currentIncidents;
std::vector<int> shownPOIs;
//----------------------------------------------

void boundary_initalize();
double get_x_lon(double longitude);
double get_y_lat(double latitude);
double get_lon_x(double x);
double get_lat_y(double y);
double get_angle(LatLon a, LatLon b);
void draw_main_canvas(ezgl::renderer *g);

//void initial_setup(ezgl::application *application);


double zoomScale (ezgl::renderer *g) ;
void initial_setup(ezgl::application *application, bool new_window);
void act_on_key_press(ezgl::application *application, GdkEventKey *event, char* key);
void act_on_mouse_move(ezgl::application *application, GdkEventButton *event, double x, double y);
void act_on_mouse_press(ezgl::application *application, GdkEventButton *event, double x, double y);
void draw_one_feature(ezgl::renderer *g, FeatureIndex id, ezgl::color featureType, double area);
void draw_all_feature(ezgl::renderer *g);
void draw_one_segments(ezgl::renderer *g, int segment_id, std::string roadType);
void draw_one_street(ezgl::renderer *g, int street_id, ezgl::color streetColor);
void draw_all_streets(ezgl::renderer *g);
void draw_all_segs(ezgl::renderer *g);
void draw_street_names(ezgl::renderer *g, int i);
void draw_bar(ezgl::renderer *g);
void draw_stext(ezgl::renderer *g);
void draw_menu (ezgl::renderer *g);
bool reloadMap(std::string name);
void redrawMap(ezgl::application *application);
void draw_clicked_inter(ezgl::renderer *g);
void draw_intersection_box(ezgl::renderer *g);
void draw_InfoBox(ezgl::renderer *g);
void draw_searchBox(ezgl::renderer *g);
void draw_clickedFoundInter(ezgl::renderer *g);
void moveToMidpoint(ezgl::renderer *g, double x, double y, double route = 0);
void draw_weather_box(ezgl::renderer *g);
void draw_relation(ezgl::renderer *g);
void draw_osmway(ezgl::renderer *g, std::vector<OSMID> nodes, ezgl::color color);
void draw_osmnodes(ezgl::renderer *g, std::vector<OSMID> nodes ,std::unordered_map<std::string, int> *nnames);
void draw_clicked_OSMnodes(ezgl::renderer *g);
OSMID find_closest_OSMnode(double x, double y);
ezgl::color getColour(std::string color);
void draw_poi (ezgl::renderer *g);
void draw_poi_en (ezgl::renderer *g);
void draw_clicked_POI(ezgl::renderer *g);
// static ezgl::rectangle initial_world{{0, 0}, 1100, 1150};
void draw_weather(ezgl::renderer *g);
void draw_incidents(ezgl::renderer *g);
int find_closest_incidents(double x, double y);
std::string convert_string(std::string input);
int find_closest_POI(double x, double y);
int hexToDe (const char *hex);
void draw_intersections(ezgl::renderer *g);
double zoomScale (ezgl::renderer *g) {
    auto area = g->get_visible_world().area();
    return 1e-4 / area;
}
void draw_path(ezgl::renderer *g);
void draw_reachable_inters(ezgl::renderer *g);
void navigation_display(ezgl::renderer *g);
bool left_right_turn(int segment1, int segment2);
//this function used for converting certain POI types into a formal presentation
std::string convert_string(std::string input)
{
    //going through all chars to check for things that are not letters
    for(unsigned int i = 0; i<input.size(); i++)
    {
        char temp_char = input[i];
        if(('A'<=temp_char &&temp_char<='Z') || ('a'<=temp_char && temp_char<='z') || temp_char == ' ')
        {
            
        }
        else
            //make everything not letters into space for better reading
        {
            input.replace(i, 1, " ");
        }
    }
    
    return input;

}


//Draw the loaded map (default toronto)
void draw_map()
{
    // std::cout << -1 << endl;
    boundary_initalize();
    // std::cout << 1 << endl;
    ezgl::application::settings settings;
    settings.main_ui_resource = "libstreetmap/resources/main.ui";
    settings.window_identifier = "MainWindow";
    settings.canvas_identifier = "MainCanvas";
    
    ezgl::application application(settings);
    ezgl::rectangle initial_world{{init_x, init_y}, {end_x, end_y}};
    application.add_canvas("MainCanvas", draw_main_canvas, initial_world);
    
    
    

// the parent window over which to add the dialog
// the content area of the dialog
// the label we will create to display a message in the content
// the dialog box we will create
//    GtkWidget* button_test;
    //gtk_container_add(GTK_CONTAINER("MainWindow"), button_test);
    
    application.add_canvas("MainCanvas", draw_main_canvas, initial_world);
    //int ret  = application.run(initial_setup, act_on_mouse_press, act_on_mouse_move, nullptr);
    int ret = application.run(initial_setup, act_on_mouse_press, act_on_mouse_move, act_on_key_press);
}

//draw map callback, used to update graphic
void draw_main_canvas(ezgl::renderer *g)
{   
    // std::cout << -1 << endl;
    // osmNodesName.clear();
    if (initialArea == -1)
        initialArea = g->get_visible_world().area();
    // std::cout << g->get_visible_world().area() << "\n";
    ezgl::point2d start_point(init_x, init_y);
    ezgl::point2d end_point(end_x, end_y);
    // std::cout<< start_point.x<<std::endl<< start_point.y<<std::endl;
    ezgl::color basic(240,240,240,255);
    g->set_color(basic);

    if(trafficEn || subwayEn || trainEn || tramEn || POI != -1) {
        routeMode = false;
    }

    //ezgl::rectangle color_rectangle = {start_point, rectangle_width, rectangle_height};
    g->fill_rectangle(start_point, end_point);
    
//    draw_intersections(g);
    draw_all_feature(g);
    draw_all_segs(g);
    
    
    
     draw_path(g);
     draw_reachable_inters(g);
    draw_spath(g);
    draw_poi(g);
    draw_poi_en(g);
    draw_feature_info(g);
    draw_relation(g);
    draw_clicked_inter(g);
    draw_clickedFoundInter(g);
    draw_path_inters(g);
    draw_clicked_OSMnodes(g);

    draw_clicked_POI(g);
    if( currentIncidents.size() != 0 )
        draw_incidents(g);
    
    draw_menu(g);
    draw_bar(g);
    drawRouteBox(g);
    draw_route_searchBars(g);
    draw_route_options(g);
    navigation_text(g);
    show_naviagtion(g);
    draw_path_inters_text(g);
    draw_stext(g);
    draw_InfoBox(g);
    draw_searchBox(g);
    draw_weather(g);
    // navigation_display(g);
}
void draw_intersections(ezgl::renderer *g)
{
    for(int i=0; i<getNumIntersections(); i++)
    {
        double x = get_x_lon(getIntersectionPosition(i).lon());
        double y =get_y_lat(getIntersectionPosition(i).lat());
        ezgl::point2d center(x,y);
        g->set_color(ezgl::PURPLE);
        
        g->fill_arc(center,g->get_visible_world().width()/300,0,360);
    }
}
double get_x_lon(double longitude)
{
    double x;
    double rad = longitude*DEGREE_TO_RADIAN;
    x = rad *cos(((min_latitude+max_latitude)/2)*DEGREE_TO_RADIAN);
    return x;
}
// get y coor using lat
double get_y_lat(double latitude)
{
    double y;
    y = latitude * DEGREE_TO_RADIAN;
    return y;
}
//get lon using x coor
double get_lon_x(double x)
{
    double lon;
    double average_lat = ((min_latitude+max_latitude)/2)*DEGREE_TO_RADIAN;
    lon = (x/cos(average_lat))/DEGREE_TO_RADIAN;
    return lon;
}
//get lat using y coor
double get_lat_y(double y)
{
    double lat;
    lat = y/DEGREE_TO_RADIAN;
    return lat;
}

//used to initialize the map parameters before drawing
//by finding the coordinates that have the smallest and largest value to set the world boundary
void boundary_initalize()
{
    
    
    clickedOSMNode.first = false;
    max_latitude = getIntersectionPosition(0).lat();
    max_longitude = getIntersectionPosition(0).lon();
    min_latitude = max_latitude;
    min_longitude = max_longitude;
    intersectionPosition.resize(getNumIntersections());

    //going through for loops to find smallest and largest x and y values
    for(int i = 0; i<getNumIntersections(); i++)
    {
        intersectionPosition[i] = getIntersectionPosition(i);
    }
    for(int i=0; i<getNumIntersections(); i++)
    {
        if(intersectionPosition[i].lat() > max_latitude)
        {
            max_latitude = intersectionPosition[i].lat();
        }
        if(intersectionPosition[i].lon() > max_longitude)
        {
            max_longitude = intersectionPosition[i].lon();
        }
        if(intersectionPosition[i].lat() < min_latitude)
        {
            min_latitude = intersectionPosition[i].lat();
        }
        if(intersectionPosition[i].lon() < min_longitude)
        {
            min_longitude = intersectionPosition[i].lon();
        }

    }
    //compare all intersections to find out the smallest lat and lon
    //set world coordinate to screen, and pass into global varibales for further use
    init_x = get_x_lon(min_longitude);
    end_x = get_x_lon(max_longitude);
    init_y = get_y_lat(min_latitude);
    end_y = get_y_lat(max_latitude);
    //also initialize features that are ordered in size sequence, so when plotted, no smaller features will be hidden
    feature_order.resize(getNumFeatures());
    for(int i=0; i<getNumFeatures(); i++)
    {
        feature_order[i].first = find_feature_area(i);
        feature_order[i].second = i;
    }
    //feature areas are sorted in the order or area, so smaller ones wouldn't be covered
    std::sort(feature_order.begin(), feature_order.end());

    //one bug determined in iceland, to avoid that
     if(getNumFeatures() == 2554 || getNumFeatures() == 183676)
        return;
    currentIncidents = getIncidentInfo(min_latitude, min_longitude,
            max_latitude, max_longitude);

   
    
}
//empty because no GTK conponents used
void initial_setup(ezgl::application *application, bool new_window){
    
    
}

// key press callback, used to response to key input
void act_on_key_press(ezgl::application *application, GdkEventKey *event, char *key)
{
    std::string keyName = key;
    drawingWidgets = false;
    //enable responses for all necessary keys that are not recognized as ASCII
    if(routeMenuA && navigationInstructions.size() != 0) {
        //when keys are pressed, some functions are triggered
        int totalSize = navigationInstructions.size();
            if(changeContain) {
                totalSize -= 1;
            }
        if(keyName == "Up") {
            //used for navigation page turn
            if(naviCount > 0) {
                naviCount --;
                naviPressed = -1;
            }
        }
        else if(keyName == "Down") {
            //used for navigation page turn
            if(naviCount < (totalSize - 1) / 5) {
                naviCount ++;
                naviPressed = -1;
            }
        }
    }
    if(keyName == "Home") { 
        menuActivated = !menuActivated;
        application->refresh_drawing();
        return;
        //turn off the menu page
    }
    if( keyName == "Delete") {
        if(barClicked)
            searchText.clear();
        else if(firstBarA)
            firstinter = -1;
        else if (secondBarA)
            secondinter = -1;
        else if(routeSetting && ssearchBar1A) 
            walkingSpeed = 1.25;
        else if(routeSetting && ssearchBar2A) 
            walkingTimeLimit = 300;
        application->refresh_drawing();
         return;
         //deleting the walking speed and limit box
    }
    if( keyName == "BackSpace" && searchText.size() != 0 && barClicked == 1 ) {
        searchText.pop_back();
        application->refresh_drawing();
         return;
         //one part of the search bar functionalities, simulating text
    }
    if( keyName.size() == 1 && barClicked == 1 && searchText.size() < 24) {
        searchText.push_back(keyName[0]);
        application->refresh_drawing();
         return;
    }
    if( keyName == "space"&& barClicked == 1 && searchText.size() < 24) {
        char a = ' ';
        searchText.push_back(a);
        application->refresh_drawing();
         return;
         //simulation of typing space key
    }
    if( keyName == "ampersand" && barClicked == 1 && searchText.size() < 24) {
        char a = '&';
        searchText.push_back(a);
        application->refresh_drawing();
         return;
    }
    if( keyName == "period" && barClicked == 1 && searchText.size() < 24) {
        char a = '.';
        searchText.push_back(a);
        application->refresh_drawing();
         return;
    }
    if(keyName == "Return") {
        enterPressed = true;
    }
    else
    {
        enterPressed = false;
    }
    //when search bar is in use, press enter to trigger searching functions
    if(enterPressed && barClicked == 1 ) {
        //when enter is pressed and search bar is activated, trigger searching function
        if(routeSetting && ssearchBar1A) {
            if(atof(searchText.c_str())) {
                walkingSpeed = atof(searchText.c_str());
            }
            searchText.clear();
            application->refresh_drawing();
            return;
        }
        
        if(routeSetting && ssearchBar2A) {
            if(atof(searchText.c_str())) {
                walkingTimeLimit = atof(searchText.c_str());
            }
            searchText.clear();
            application->refresh_drawing();
            return;
        }

        auto ss = format(searchText);
        auto first4 = ss.substr(0, 4);
        auto first6 = ss.substr(0,6); 
        auto first7 = ss.substr(0,7);
        //load different city maps
        if(first4 == "load") {
            if (reloadMap(ss.substr(4, ss.size()))) {
                redrawMap(application);
            }
            application->refresh_drawing();
             return;
        }
        //enable different components of the basic map
        else if(first6 == "enable") {
            if(ss.substr(6, ss.size()) == "building" || ss.substr(6, ss.size()) == "buildings") {
                enableBuiding = true;
                application->refresh_drawing();
                 return;
                 //choose whether to display buildings or not, alse able to be triggered by buttons
            }
            else if(ss.substr(6, ss.size()) == "streetname") {
                enableStreetN = true;
                application->refresh_drawing();
                 return;
            }
            //public transportation can be enabled here, also by buttons
            else if(ss.substr(6, ss.size()) == "subway") {
                subwayEn = true;
                tramEn = false;
                trainEn = false;
                application->refresh_drawing();
                 return;
                 //activate subways
            }
            else if(ss.substr(6, ss.size()) == "train") {
                subwayEn = false;
                tramEn = false;
                trainEn = true;
                application->refresh_drawing();
                 return;
                 //activate trains on the map
            }
            else if(ss.substr(6, ss.size()) == "tram") {
                subwayEn = false;
                tramEn = true;
                trainEn = false;
                application->refresh_drawing();
                 return;
                 //activate trams on the map
            }
            else if(ss.substr(6, ss.size()) == "findpath") {
                routeMode = true;
                application->refresh_drawing();
                 return;
                 //activate a window for findpath box
            }

        }
        else if(first7 == "disable") {
            //same functions triggered above can be disabled here
            if(ss.substr(7, ss.size()) == "building" || ss.substr(7, ss.size()) == "buildings") {
                enableBuiding = false;
                application->refresh_drawing();
                 return;
            }
            else if(ss.substr(7, ss.size()) == "streetname") {
                enableStreetN = false;
                application->refresh_drawing();
                 return;
            }
            else if(ss.substr(7, ss.size()) == "tram") {
                tramEn = false;
                application->refresh_drawing();
                 return;
            }
            else if(ss.substr(7, ss.size()) == "train") {
                trainEn = false;
                application->refresh_drawing();
                 return;
            }
            else if(ss.substr(7, ss.size()) == "subway") {
                subwayEn = false;
                application->refresh_drawing();
                 return;
            }
            else if(ss.substr(7, ss.size()) == "findpath") {
                //when pathfind window is closed, all inside functions turned off at the same time
                routeMode = false;
                firstBarA = false;
                secondBarA = false;
                drivingA = false;
                walkingA = false;
                wplusdA = false;
                application->refresh_drawing();
                 return;
            }
            
        }
        //getting two streets through special syntax, in order to find corrosponding intersections
        else if(ss.find("&&") != std::string::npos) {
            auto firstStreet = ss.substr(0, ss.find("&&"));
            auto secondStreet = ss.substr(ss.find("&&") + 2, ss.size());
            std::vector<int> allInters;
            if(firstStreet.size() == 0 || secondStreet.size() == 0) 
                return;
            //find two vectors that will contains intersections
            auto fStreetIDs = find_street_ids_from_partial_street_name(firstStreet);
            auto sStreetIDs = find_street_ids_from_partial_street_name(secondStreet);

            //double loops to find one that are contained in both
            for(int sID = 0; sID < fStreetIDs.size(); sID++) {
                for(int ssID = 0; ssID < sStreetIDs.size(); ssID++) {
                    auto cInters = find_intersections_of_two_streets(std::make_pair(fStreetIDs[sID], sStreetIDs[ssID])) ;
                    for( int ids = 0; ids < cInters.size(); ids++) {
                        if(getIntersectionName(cInters[ids]).find("<unknown>") == std::string::npos) {
                            allInters.push_back(cInters[ids]);
                        }
                    }
                }
            }
            std::map<double, int> allInD;
            auto clat = get_lat_y(application->get_renderer()->get_visible_world().center_y());
            auto clon = get_lon_x(application->get_renderer()->get_visible_world().center_x());
            LatLon cCoor (clat, clon);
            for (int i = 0; i < allInters.size(); i ++) {
                allInD.insert(std::make_pair( find_distance_between_two_points(std::make_pair(cCoor, getIntersectionPosition(allInters[i]))), allInters[i] ));
            }
            foundIntersIDs.clear();
            for (auto it = allInD.begin(); it != allInD.end(); it++) {
                if(foundIntersIDs.size() >= 5)
                    break;
                foundIntersIDs.push_back(it->second);
            }
            //display potential results under search bar
            searchBoxActivated = true;
            searchBI = 0;
            application->refresh_drawing();
            return;
        }
      
        else {
            auto pois = find_POI_ids_from_partial_POI_name(ss);

            std::map<double, int> allPOI;
            auto clat = get_lat_y(application->get_renderer()->get_visible_world().center_y());
            auto clon = get_lon_x(application->get_renderer()->get_visible_world().center_x());
            LatLon cCoor (clat, clon);
            for (int i = 0; i < pois.size(); i ++) {
                allPOI.insert(std::make_pair( find_distance_between_two_points(std::make_pair(cCoor, getPointOfInterestPosition(pois[i]))), pois[i] ));
            }

            foundPOIIDs.clear();
            for(auto it = allPOI.begin(); it != allPOI.end(); it++) {

                if(foundPOIIDs.size() >= 5)
                    break;
                foundPOIIDs.push_back(it->second);
            }
            searchBoxActivated = true;
            searchBI = 1;
            application->refresh_drawing();
            return;
        }


    }
       searchBoxActivated = false;
       application->refresh_drawing();
}

// mouse move callback, used to highlight certern blocks
void act_on_mouse_move(ezgl::application *application, GdkEventButton *event, double x, double y)
{
    ezgl::point2d wp1(x, y);
    ezgl::rectangle rec = {wp1, 1, 1};
    auto ren = application->get_renderer();
    auto srec = ren->world_to_screen(rec);
    auto sx = srec.top_left().x;
    auto sy = srec.top_left().y;
    naviRow = -1;
    //when menu button is clicked, show a menu bar, and each box in is are labelled, in order to locate mouse operation
    if(menuActivated)
    {
        if(sx<first_menu_box.right() && sx>first_menu_box.left() && sy<first_menu_box.top() &&sy>first_menu_box.bottom())
        {
            menu_switch = 1;
        }
        else if(sx<second_menu_box.right() && sx>second_menu_box.left() && sy<second_menu_box.top() &&sy>second_menu_box.bottom())
        {
            menu_switch = 2;
        }
        else if(sx<third_menu_box.right() && sx>third_menu_box.left() && sy<third_menu_box.top() &&sy>third_menu_box.bottom())
        {
            menu_switch = 3;
        }
        else if(sx<fourth_menu_box.right() && sx>fourth_menu_box.left() && sy<fourth_menu_box.top() &&sy>fourth_menu_box.bottom())
        {
            menu_switch = 4;
        }
        else if(sx<fifth_menu_box.right() && sx>fifth_menu_box.left() && sy<fifth_menu_box.top() &&sy>fifth_menu_box.bottom())
        {
            menu_switch = 5;
        }
        else if( !(sx<sub_menu.right() && sx>sub_menu.left() && sy<sub_menu.top() &&sy>sub_menu.bottom())) 
        {
            menu_switch = 0;
        }
        
        if(menu_switch == 5)
        {
            sub_menu_switch = 0;
        }
        else if(menu_switch != 0)
        {
            if(sx<sub_menu_1_box.right() && sx>sub_menu_1_box.left() && sy<sub_menu_1_box.top() &&sy>sub_menu_1_box.bottom())
            {
                sub_menu_switch = 1;
            }
            else if(sx<sub_menu_2_box.right() && sx>sub_menu_2_box.left() && sy<sub_menu_2_box.top() &&sy>sub_menu_2_box.bottom())
            {
                sub_menu_switch = 2;

            }
            else if(sx<sub_menu_3_box.right() && sx>sub_menu_3_box.left() && sy<sub_menu_3_box.top() &&sy>sub_menu_3_box.bottom())
            {
                sub_menu_switch = 3;

            }
            else if(sx<sub_menu_4_box.right() && sx>sub_menu_4_box.left() && sy<sub_menu_4_box.top() &&sy>sub_menu_4_box.bottom())
            {
                sub_menu_switch = 4;

            }
            else if(sx<sub_menu_5_box.right() && sx>sub_menu_5_box.left() && sy<sub_menu_5_box.top() &&sy>sub_menu_5_box.bottom())
            {
                sub_menu_switch = 5;

            }
            else if(sx<sub_menu_6_box.right() && sx>sub_menu_6_box.left() && sy<sub_menu_6_box.top() &&sy>sub_menu_6_box.bottom())
            {
                sub_menu_switch = 6;
            }
            else if(sx<sub_menu_7_box.right() && sx>sub_menu_7_box.left() && sy<sub_menu_7_box.top() &&sy>sub_menu_7_box.bottom())
            {
                sub_menu_switch = 7;
            }
            else if(sx<sub_menu_8_box.right() && sx>sub_menu_8_box.left() && sy<sub_menu_8_box.top() &&sy>sub_menu_8_box.bottom())
            {
                sub_menu_switch = 8;
            }
            else if(sx<sub_menu_9_box.right() && sx>sub_menu_9_box.left() && sy<sub_menu_9_box.top() &&sy>sub_menu_9_box.bottom())
            {
                sub_menu_switch = 9;
            }
            else if(sx<sub_menu_10_box.right() && sx>sub_menu_10_box.left() && sy<sub_menu_10_box.top() &&sy>sub_menu_10_box.bottom())
            {
                sub_menu_switch = 10;
            }
            else if(sx<sub_menu_11_box.right() && sx>sub_menu_11_box.left() && sy<sub_menu_11_box.top() &&sy>sub_menu_11_box.bottom())
            {
                sub_menu_switch = 11;
            }
            else if(sx<sub_menu_12_box.right() && sx>sub_menu_12_box.left() && sy<sub_menu_12_box.top() &&sy>sub_menu_12_box.bottom())
            {
                sub_menu_switch = 12;
            }
            else if(sx<sub_menu_13_box.right() && sx>sub_menu_13_box.left() && sy<sub_menu_13_box.top() &&sy>sub_menu_13_box.bottom())
            {
                sub_menu_switch = 13;
            }
            else if(sx<sub_menu_14_box.right() && sx>sub_menu_14_box.left() && sy<sub_menu_14_box.top() &&sy>sub_menu_14_box.bottom())
            {
                sub_menu_switch = 14;
            }
            else if(sx<sub_menu_15_box.right() && sx>sub_menu_15_box.left() && sy<sub_menu_15_box.top() &&sy>sub_menu_15_box.bottom())
            {
                sub_menu_switch = 15;
            }
            else if(sx<sub_menu_16_box.right() && sx>sub_menu_16_box.left() && sy<sub_menu_16_box.top() &&sy>sub_menu_16_box.bottom())
            {
                sub_menu_switch = 16;
            }
            else
            {
                sub_menu_switch = 0;
                
            }
        
        } 
        else {
            menu_switch = 0;
            sub_menu_switch = 0;
        } 

    }
    //path finding first search bar is clicked
    if( sx < searchBar1.right() && sx > searchBar1.left() && sy < searchBar1.top() && sy > searchBar1.bottom() && routeMode) {
        searchBar1M = true;
        searchBar2M = false;
        application->refresh_drawing();
        return;
    }
    searchBar1M = false;

    // else
    // {
    //     firstBarA = false;
    //     application->refresh_drawing();
    // }
    //path finding second search bar is clicked
    if( sx < searchBar2.right() && sx > searchBar2.left() && sy < searchBar2.top() && sy > searchBar2.bottom() && routeMode) {
        searchBar2M = true;
        searchBar1M = false;
        application->refresh_drawing();
        return;
    }
    //two buttons that help increment or decrement a counter, that counts through steps for navigation instructions
    searchBar2M = false;
    
    if( sx < routeMenuBox.right() && sx > routeMenuBox.left() && sy <routeMenuBox.bottom() + 60 && sy > routeMenuBox.bottom() && routeMode && routeMenuA) {
        naviRow = 0;
        application->refresh_drawing();
        return;
    }
    if( sx < routeMenuBox.right() && sx > routeMenuBox.left() && sy <routeMenuBox.bottom() + 120 && sy > routeMenuBox.bottom() + 60 && routeMode && routeMenuA) {
        naviRow = 1;
        application->refresh_drawing();
        return;
    }
    if( sx < routeMenuBox.right() && sx > routeMenuBox.left() && sy <routeMenuBox.bottom() + 180 && sy > routeMenuBox.bottom() + 120 && routeMode && routeMenuA) {
        naviRow = 2;
        application->refresh_drawing();
        return;
    }
    if( sx < routeMenuBox.right() && sx > routeMenuBox.left() && sy <routeMenuBox.bottom() + 240 && sy > routeMenuBox.bottom() + 180 && routeMode && routeMenuA) {
        naviRow = 3;
        application->refresh_drawing();
        return;
    }
    if( sx < routeMenuBox.right() && sx > routeMenuBox.left() && sy <routeMenuBox.bottom() + 300 && sy > routeMenuBox.bottom() + 240 && routeMode && routeMenuA) {
        naviRow = 4;
        application->refresh_drawing();
        return;
    }




    application->refresh_drawing();
}

//mouse press callback, used to make graphic clickable
void act_on_mouse_press(ezgl::application *application, GdkEventButton *event, double x, double y)
{
    ezgl::point2d wp1(x, y);
    ezgl::rectangle rec = {wp1, 1, 1};
    auto ren = application->get_renderer();
    auto srec = ren->world_to_screen(rec);
    auto sx = srec.top_left().x;
    auto sy = srec.top_left().y;

    //navigation is triggered by a menu button on path finding box
    if(routeMenuA && routeMode && naviRow != -1) {
        if(naviPressed != -1 && naviPressed == naviRow) {
            naviPressed = -1;
        }
        else {
            naviPressed = naviRow;
            routeMoveMid = true;
            show_naviagtion(application->get_renderer());
        }
        application->refresh_drawing();
        return;
    }
    //enable weather box on top right corner
    if(menu_switch == 3 && sub_menu_switch == 1) {
        weatherEn = !weatherEn;
        if(weatherEn) {
            cWeather = getWeatherInfo(get_lat_y(application->get_renderer()->get_visible_world().center_y()), get_lon_x(application->get_renderer()->get_visible_world().center_x()));
        }
        application->refresh_drawing();
        return;
    }
    //enable road closure display on the map
    if(menu_switch == 3 && sub_menu_switch == 2) {
        trafficEn = !trafficEn;
        application->refresh_drawing();
        return;
    }
    //buildings can be displayed here as well by button
    if(menu_switch == 2 && sub_menu_switch == 14)
    {
        enableBuiding = !enableBuiding;
        application->refresh_drawing();
        return;
    }
    //city buttons
    if(menu_switch == 4 && sub_menu_switch == 1) {
        loading_map = 1;
        reloadMap("beijing");
        redrawMap(application);
        loading_map = 0;
        application->refresh_drawing();
        return;
    }
    if(menu_switch == 4 && sub_menu_switch == 2) {
        reloadMap("toronto");
        redrawMap(application);
        application->refresh_drawing();
        return;
    }
    if(menu_switch == 4 && sub_menu_switch == 3) {
        reloadMap("newyork");
        redrawMap(application);
        application->refresh_drawing();
        return;
    }
    if(menu_switch == 4 && sub_menu_switch == 4) {
        reloadMap("hongkong");
        redrawMap(application);
        application->refresh_drawing();
        return;
    }
    if(menu_switch == 4 && sub_menu_switch == 5) {
        reloadMap("london");
        redrawMap(application);
        application->refresh_drawing();
        return;
    }
    if(menu_switch == 4 && sub_menu_switch == 6) {
        reloadMap("sydney");
        redrawMap(application);
        application->refresh_drawing();
        return;
    }
    if(menu_switch == 4 && sub_menu_switch == 7) {
        reloadMap("singapore");
        redrawMap(application);
        application->refresh_drawing();
        return;
    }
    if(menu_switch == 4 && sub_menu_switch == 8) {
        reloadMap("moscow");
        redrawMap(application);
        application->refresh_drawing();
        return;
    }

    //menu list for POI
    if(menu_switch == 2 && sub_menu_switch == 1) {
        if(POI == 0) {
            POI = -1;
        }
        else {
            POI = 0;
        }
        application->refresh_drawing();
        return;
    }
    if(menu_switch == 2 && sub_menu_switch == 2) {
        if(POI == 1) {
            POI = -1;
        }
        else {
            POI = 1;
        }
        application->refresh_drawing();
        return;
    }
    if(menu_switch == 2 && sub_menu_switch == 3) {
        if(POI == 2) {
            POI = -1;
        }
        else {
            POI = 2;
        }
        application->refresh_drawing();
        return;
    }
    if(menu_switch == 2 && sub_menu_switch == 4) {
        if(POI == 3) {
            POI = -1;
        }
        else {
            POI = 3;
        }
        application->refresh_drawing();
        return;
    }
    if(menu_switch == 2 && sub_menu_switch == 5) {
        if(POI == 4) {
            POI = -1;
        }
        else {
            POI = 4;
        }
        application->refresh_drawing();
        return;
    }
    if(menu_switch == 2 && sub_menu_switch == 6) {
        if(POI == 5) {
            POI = -1;
        }
        else {
            POI = 5;
        }
        application->refresh_drawing();
        return;
    }
    if(menu_switch == 2 && sub_menu_switch == 7) {
        if(POI == 6) {
            POI = -1;
        }
        else {
            POI = 6;
        }
        application->refresh_drawing();
        return;
    }
    if(menu_switch == 2 && sub_menu_switch == 8) {
        if(POI == 7) {
            POI = -1;
        }
        else {
            POI = 7;
        }
        application->refresh_drawing();
        return;
    }
    if(menu_switch == 2 && sub_menu_switch == 9) {
        if(POI == 8) {
            POI = -1;
        }
        else {
            POI = 8;
        }
        application->refresh_drawing();
        return;
    }
    if(menu_switch == 2 && sub_menu_switch == 10) {
        if(POI == 9) {
            POI = -1;
        }
        else {
            POI = 9;
        }
        application->refresh_drawing();
        return;
    }
    if(menu_switch == 2 && sub_menu_switch == 11) {
        if(POI == 10) {
            POI = -1;
        }
        else {
            POI = 10;
        }
        application->refresh_drawing();
        return;
    }
    if(menu_switch == 2 && sub_menu_switch == 12) {
        if(POI == 11) {
            POI = -1;
        }
        else {
            POI = 11;
        }
        application->refresh_drawing();
        return;
    }
    if(menu_switch == 2 && sub_menu_switch == 13) {
        if(POI == 12) {
            POI = -1;
        }
        else {
            POI = 12;
        }
        application->refresh_drawing();
        return;
    }
    //public transportation buttons, mutual display
    
    if(menu_switch == 1 && sub_menu_switch == 1) {
        subwayEn = !subwayEn;
        if(subwayEn) {
            trainEn = false;
            tramEn = false;
        }
        application->refresh_drawing();
        return;
    }
    if(menu_switch == 1 && sub_menu_switch == 2) {
        tramEn = !tramEn;
        if(tramEn) {
            trainEn = false;
            subwayEn = false;
        }
        application->refresh_drawing();
        return;
    }
    if(menu_switch == 1 && sub_menu_switch == 3) {
        trainEn = !trainEn;
        if(trainEn ) {
            subwayEn = false;
            tramEn = false;
        }
        application->refresh_drawing();
        return;
    }
    if(menu_switch == 5)
    {
        routeMode = !routeMode;
        if(!routeMode)
        {
            firstBarA = false;
            secondBarA = false;
            drivingA = false;
            walkingA = false;
            wplusdA = false;
        }
        else {
            tramEn = false;
            trafficEn = false;
            trainEn = false;
            POI = -1;
            subwayEn = false;
        }
        application->refresh_drawing();
        return;
    }
    //search bar clicked, turn on search bar bool, so further steps can continue
    if( sx < searchBar.right() && sx > searchBar.left() && sy < searchBar.top() && sy > searchBar.bottom()) {
        barClicked = 1;
        menuActivated = false;
        application->refresh_drawing();
    }
    else
    {
        barClicked = 0;
        application->refresh_drawing();
    }
//the menu button on the top left coner, to display the menu
  if( sx < menuB.right() && sx > menuB.left() && sy < menuB.top() && sy > menuB.bottom()) {
        menuActivated = ! menuActivated;
        application->refresh_drawing();
  }
    //clicking on path finding search bar
  if( sx < searchBar1.right() && sx > searchBar1.left() && sy < searchBar1.top() && sy > searchBar1.bottom() && routeMode) {
        firstBarA = true;
        secondBarA = false;
        walkingA = false;
        drivingA = false;
        wplusdA = false;
        onMap = false;
        help = false;
        application->refresh_drawing();
        return;
    }
    
    //clicking on path finding search bar
    if( sx < searchBar2.right() && sx > searchBar2.left() && sy < searchBar2.top() && sy > searchBar2.bottom() && routeMode) {
        secondBarA = true;
        firstBarA = false;
        walkingA = false;
        drivingA = false;
        wplusdA = false;
        onMap = false;
        help = false;
        application->refresh_drawing();
        return;
    }
    //find path that is through driving
    if( sx < drivingB.right() && sx > drivingB.left() && sy < drivingB.top() && sy > drivingB.bottom() && routeMode) {
        secondBarA = false;
        firstBarA = false;
        walkingA =false;
        wplusdA = false;
        drivingA = true;
        onMap = false;
        routeSetting = false;
        help = false;
        naviCount = 0;
        naviPressed = -1;
        application->refresh_drawing();
        return;
    }
    
    if( sx < drivingB.right() && sx > drivingB.left() && sy < drivingB.top() && sy > drivingB.bottom() && routeMode) {
        secondBarA = false;
        firstBarA = false;
        walkingA =false;
        wplusdA = false;
        drivingA = true;
        onMap = false;
        routeSetting = false;
        help = false;
        naviCount = 0;
        naviPressed = -1;
        application->refresh_drawing();
        return;
    }
    //clicking on walking option to display walking path
    if( sx < walkingB.right() && sx > walkingB.left() && sy < walkingB.top() && sy > walkingB.bottom() && routeMode) {
        secondBarA = false;
        firstBarA = false;
        walkingA =true;
        wplusdA = false;
        drivingA = false;
        onMap = false;
        routeSetting = false;
        help = false;
        naviCount = 0;
        naviPressed = -1;
        application->refresh_drawing();
        return;
    }
    //waling plus driving button
    if( sx < wplusdB.right() && sx > wplusdB.left() && sy < wplusdB.top() && sy > wplusdB.bottom() && routeMode) {
        secondBarA = false;
        firstBarA = false;
        walkingA =false;
        wplusdA = true;
        drivingA = false;
        onMap = false;
        routeSetting = false;
        help = false;
        naviCount = 0;
        naviPressed = -1;
        application->refresh_drawing();
        return;
    }
    //swap button that can help switch beginning and ending intersections
    if( sx < swapB.right() && sx > swapB.left() && sy < swapB.top() && sy > swapB.bottom() && routeMode) {
        secondBarA = false;
        firstBarA = false;
        onMap = false;
        auto tempid = firstinter;
        firstinter = secondinter;
        secondinter = tempid;
        routeSetting = false;
        help = false;
        naviCount = 0;
        naviPressed = -1;
        application->refresh_drawing();
        return;
    }
    
    if( sx < routeCloseB.right() && sx > routeCloseB.left() && sy < routeCloseB.top() && sy > routeCloseB.bottom() && routeMode) {
        routeMode = false;
        onMap = false;
        firstBarA = false;
        secondBarA = false;
        drivingA = false;
        walkingA = false;
        wplusdA = false;
        
        application->refresh_drawing();
        return;
    }
    //
    if( sx < routesetB.right() && sx > routesetB.left() && sy < routesetB.top() && sy > routesetB.bottom() && routeMode) {
        onMap = false;
        routeSetting = !routeSetting;
        drivingA = false;
        walkingA = false;
        wplusdA = false;
        help = false;
        if(routeSetting == false) {
            ssearchBar1A = false;
            ssearchBar2A = false;
        }
        application->refresh_drawing();
        return;
    }
    
    if( sx < routesetB.right() && sx > routesetB.left() && sy < routesetB.top() && sy > routesetB.bottom() && routeMode) {
        onMap = false;
        routeSetting = !routeSetting;
        drivingA = false;
        walkingA = false;
        wplusdA = false;
        help = false;
        if(routeSetting == false) {
            ssearchBar1A = false;
            ssearchBar2A = false;
        }
        application->refresh_drawing();
        return;
    }
    //help button that helps users to see what each button or bar does
    if ( sx < routehelpB.right() && sx > routehelpB.left() && sy < routehelpB.top() && sy > routehelpB.bottom() && routeMode) {
        onMap = false;
        help = !help;
        drivingA = false;
        walkingA = false;
        wplusdA = false;
        if (help == false) {
            startLocation = false;
            destination = false;
            arrows == false;
            driving == false;
            walking == false;
        }
        application->refresh_drawing();
        return;
    }
    //mutual search bars, click on one of them will activate one and disable the other one
    if( sx < ssearchBar1.right() && sx > ssearchBar1.left() && sy < ssearchBar1.top() && sy > ssearchBar1.bottom() && routeMode && routeSetting) {
        onMap = false;
        ssearchBar1A = true;
        ssearchBar2A = false;
        application->refresh_drawing();
        return;
    }

    if( sx < ssearchBar2.right() && sx > ssearchBar2.left() && sy < ssearchBar2.top() && sy > ssearchBar2.bottom() && routeMode && routeSetting) {
        onMap = false;
        ssearchBar1A = false;
        ssearchBar2A = true;
        application->refresh_drawing();
        return;
    }
    //a goto button on info box when regularly clicking on an intersection, activate path finding and set this inter as destination
    if( sx < infoboxGoto.right() && sx > infoboxGoto.left() && sy < infoboxGoto.top() && sy > infoboxGoto.bottom() && infoBoxActivated && infointermode) {
        routeMode = true;
        onMap = false;
        tramEn = false;
        trafficEn = false;
        trainEn = false;
        POI = -1;
        subwayEn = false;
        //if intersection exits, set destination
        if(interID != -1) {
            secondinter = interID;
        }
        else if(clickedFoundInter != -1) {
            secondinter = clickedFoundInter;
            //if clicked on a intersection, use this inter as dest
        }
        application->refresh_drawing();
        return;
    }
    //trigger the menu button on path finding box
    if( sx < routeMenuB.right() && sx > routeMenuB.left() && sy < routeMenuB.top() && sy > routeMenuB.bottom() && routeMode) {
        onMap = false;
        routeMenuA = !routeMenuA;
        naviPressed = -1;
        application->refresh_drawing();
        return;
    }
    
    int totalSize = navigationInstructions.size();
            if(changeContain) {
                totalSize -= 1;
            }
    //page turner of navigation instructions
    if( sx < menuUp.right() && sx >  menuUp.left() && sy <  menuUp.top() && sy >  menuUp.bottom() && routeMode && routeMenuA) {
        onMap = false;
        //navigation instruction vector starts from 0
        if(naviCount > 0) {
                naviCount --;
                naviPressed = -1;
            }
        application->refresh_drawing();
        return;
    }
    //page turner of navigation instructions
    if( sx < menuDown.right() && sx > menuDown.left() && sy < menuDown.top() && sy > menuDown.bottom() && routeMode && routeMenuA) {
        onMap = false;
        //instructions are displayed 5 each page
        if(naviCount < (totalSize - 1) / 5) {
                naviCount ++;
                naviPressed = -1;
            }
        application->refresh_drawing();
        return;
    }

    //each instruction is clicked, there is a correpsonding location where the user is at
  if( !barClicked && !(sx < menuB.right() && sx > menuB.left() && sy < menuB.top() && sy > menuB.bottom()) && !(menuActivated &&
    (sx < mainMenu.right() && sx > mainMenu.left() && sy < mainMenu.top() && sy > mainMenu.bottom()) ) && !(infoBoxActivated &&
    (sx < InfoBox.right() && sx > InfoBox.left() && sy < InfoBox.top() && sy > InfoBox.bottom()) ) 
    && !(searchBoxActivated && (sx < searchBox.right() && sx > searchBox.left() && sy < searchBox.top() && sy > searchBox.bottom()) ) 
    && !(routeMode && (sx < route_background.right() && sx > route_background.left() && sy < route_background.top() && sy > route_background.bottom()) )) {
        onMap = true;
        worldClickedPoint.first = x;
        worldClickedPoint.second = y;
        application->refresh_drawing();
  }
  else
  {
       onMap = false; 
       application->refresh_drawing();
  }
    //search a intersection or POI, relocate the center of the map to this location
  if(searchBoxActivated && searchBI == 0) {
      //first result box
      if( (sx < searchBox.right() && sx > searchBox.left() && sy < searchBox.bottom() + 40 && sy > searchBox.bottom()) && foundIntersIDs.size() >= 1) {
          clickedFoundInter = foundIntersIDs[0];
          movedTomid = false;
          moveToMidpoint(application->get_renderer(), getIntersectionPosition(clickedFoundInter).lon(), getIntersectionPosition(clickedFoundInter).lat());
          application->refresh_drawing();
          movedTomid = true;
      }
      //second result box
      else if( (sx < searchBox.right() && sx > searchBox.left() && sy < searchBox.bottom() + 80 && sy > searchBox.bottom()) && foundIntersIDs.size() >= 2 ) {
          clickedFoundInter = foundIntersIDs[1];
          movedTomid = false;
        moveToMidpoint(application->get_renderer(), getIntersectionPosition(clickedFoundInter).lon(), getIntersectionPosition(clickedFoundInter).lat());
          application->refresh_drawing();
          movedTomid = true;
      }
      //third result box
      else if( (sx < searchBox.right() && sx > searchBox.left() && sy < searchBox.bottom() + 120 && sy > searchBox.bottom())  && foundIntersIDs.size() >= 3) {
          clickedFoundInter = foundIntersIDs[2];
          movedTomid = false;
            moveToMidpoint(application->get_renderer(), getIntersectionPosition(clickedFoundInter).lon(), getIntersectionPosition(clickedFoundInter).lat());
          application->refresh_drawing();
          movedTomid = true;
      }
      //fourth result box
        else if( (sx < searchBox.right() && sx > searchBox.left() && sy < searchBox.bottom() + 160 && sy > searchBox.bottom()) && foundIntersIDs.size() >= 4 ) {
          clickedFoundInter = foundIntersIDs[3];
          movedTomid = false;
            moveToMidpoint(application->get_renderer(), getIntersectionPosition(clickedFoundInter).lon(), getIntersectionPosition(clickedFoundInter).lat());
          application->refresh_drawing();
          movedTomid = true;
      }
      //fifth result box
        else if( (sx < searchBox.right() && sx > searchBox.left() && sy < searchBox.bottom() + 200 && sy > searchBox.bottom()) && foundIntersIDs.size() >= 5) {
          clickedFoundInter = foundIntersIDs[4];
          movedTomid = false;
            moveToMidpoint(application->get_renderer(), getIntersectionPosition(clickedFoundInter).lon(), getIntersectionPosition(clickedFoundInter).lat());
          application->refresh_drawing();
          movedTomid = true;
      }
      else {
           clickedFoundInter = -1;
      }
      searchBoxActivated = false;
      application->refresh_drawing();
  }
  else if(searchBoxActivated && searchBI == 1) {

    //same as above, five results of searching item, one in each box, selecting on one of them will relocate the map
        if( (sx < searchBox.right() && sx > searchBox.left() && sy < searchBox.bottom() + 40 && sy > searchBox.bottom()) && foundPOIIDs.size() >= 1) {
          clickedFoundInter = foundPOIIDs[0];
          movedTomid = false;
          moveToMidpoint(application->get_renderer(), getPointOfInterestPosition(clickedFoundInter).lon(), getPointOfInterestPosition(clickedFoundInter).lat());
          application->refresh_drawing();
          movedTomid = true;
      }
      else if( (sx < searchBox.right() && sx > searchBox.left() && sy < searchBox.bottom() + 80 && sy > searchBox.bottom()) && foundPOIIDs.size() >= 2 ) {
          clickedFoundInter = foundPOIIDs[1];
          movedTomid = false;
        moveToMidpoint(application->get_renderer(), getPointOfInterestPosition(clickedFoundInter).lon(), getPointOfInterestPosition(clickedFoundInter).lat());
          application->refresh_drawing();
          movedTomid = true;
      }
      else if( (sx < searchBox.right() && sx > searchBox.left() && sy < searchBox.bottom() + 120 && sy > searchBox.bottom())  && foundPOIIDs.size() >= 3) {
          clickedFoundInter = foundPOIIDs[2];
          movedTomid = false;
            moveToMidpoint(application->get_renderer(), getPointOfInterestPosition(clickedFoundInter).lon(), getPointOfInterestPosition(clickedFoundInter).lat());
          application->refresh_drawing();
          movedTomid = true;
      }
        else if( (sx < searchBox.right() && sx > searchBox.left() && sy < searchBox.bottom() + 160 && sy > searchBox.bottom()) && foundPOIIDs.size() >= 4 ) {
          clickedFoundInter = foundPOIIDs[3];
          movedTomid = false;
            moveToMidpoint(application->get_renderer(), getPointOfInterestPosition(clickedFoundInter).lon(), getPointOfInterestPosition(clickedFoundInter).lat());
          application->refresh_drawing();
          movedTomid = true;
      }
        else if( (sx < searchBox.right() && sx > searchBox.left() && sy < searchBox.bottom() + 200 && sy > searchBox.bottom()) && foundPOIIDs.size() >= 5) {
          clickedFoundInter = foundPOIIDs[4];
          movedTomid = false;
            moveToMidpoint(application->get_renderer(), getPointOfInterestPosition(clickedFoundInter).lon(), getPointOfInterestPosition(clickedFoundInter).lat());
          application->refresh_drawing();
          movedTomid = true;
      }
      else {
           clickedFoundInter = -1;
      }
      searchBoxActivated = false;
      application->refresh_drawing();

  }
    //when there is no intersection clicked, search box is not triggered
  else {
      clickedFoundInter = -1;
      searchBoxActivated = false;
      application->refresh_drawing();
  }
    //the navigation step counter, is incremented or decremented if button pressed
    if(prev_step)
        
    {
        
        step_count -= 1;
        
        application->refresh_drawing();
        return;
    }
    if(next_step)
    {
        step_count += 1;
        application->refresh_drawing();
        return;
    }
}

//draw a single feature
void draw_one_feature(ezgl::renderer *g, FeatureIndex id, ezgl::color featureType, double area)
{
    g->set_coordinate_system(ezgl::WORLD);
    g->set_line_width(0);
    g->set_color(featureType);
    std::vector<ezgl::point2d> list_of_points;
    //push back a list of points that build up the boundary of each feature
    for(int i = 0; i<getFeaturePointCount(id); i++)
    {
        double x_coordinate, y_coordinate;
        x_coordinate = get_x_lon(getFeaturePoint(i, id).lon());
        y_coordinate = get_y_lat(getFeaturePoint(i, id).lat());
        ezgl::point2d point(x_coordinate, y_coordinate);
        list_of_points.push_back(point);
    }
    g->set_line_cap(ezgl::line_cap::round);
    //boundary of the feature
    if(list_of_points.size() == 1)
    {
        g->draw_line(list_of_points[0], list_of_points[0]);
    }
    //fill in color
    if((list_of_points.size() > 1) && (list_of_points[0] == list_of_points.back()))
    {
        g->fill_poly(list_of_points);
    }
    //if feature is a line, just draw the line
    else
    {
        for(int i = 0; i<list_of_points.size()-1; i++)
        {   
            if(area < 5e-6)
                g->draw_line(list_of_points[i], list_of_points[i+1]);
            else
                break;
        }
    }

    
    
}


//when the user click on the menu list of POI, relavant POI logos would show on the map
void draw_poi_en (ezgl::renderer *g){
    shownPOIs.clear();
    if(POI == -1)
        return;
    double ratio_h = g->get_visible_screen().height()/g->get_visible_world().height();
    double ratio_w = g->get_visible_screen().width()/g->get_visible_world().width();
    g->set_coordinate_system(ezgl::WORLD);
    auto world = g->get_visible_world();
    auto xmin = world.left();
    auto xmax = world.right();
    auto ymin = world.bottom();
    auto ymax = world.top();
    int count = 0;
    ezgl::surface *png;
    //preloaded pngs for each kind of POI
    if (POI == 0) {
        png = g->load_png("libstreetmap/resources/restuarant1.png");
    }
    else if (POI == 1) {
       png = g->load_png("libstreetmap/resources/cafe1.png");  
    }
    else if (POI == 2) {
        png = g->load_png("libstreetmap/resources/cinema1.png");
    }
    else if (POI == 3) {
        png = g->load_png("libstreetmap/resources/theater1.png");
    }
    else if (POI == 4) {
        png = g->load_png("libstreetmap/resources/pharmacy1.png");
    }
    else if (POI == 5) {
        png = g->load_png("libstreetmap/resources/university1.png");
    }
    else if (POI == 6) {
        png = g->load_png("libstreetmap/resources/bank1.png");
    }
    else if (POI == 7) {
        png = g->load_png("libstreetmap/resources/atm1.png");
    }
    else if (POI == 8) {
        png = g->load_png("libstreetmap/resources/hospital1.png");
    }
    else if (POI == 9) {
        png = g->load_png("libstreetmap/resources/burger1.png");
    }
    else if (POI == 10) {
        png = g->load_png("libstreetmap/resources/pub1.png");
    }
    else if (POI == 11) {
        png = g->load_png("libstreetmap/resources/dentist1.png");
    }
    else if (POI == 12) {
        png = g->load_png("libstreetmap/resources/book1.png");
    }
    //load POI that are within the screen
    for (int i=0; i< pointOfInterest[POI].size(); i++){
           auto plon = get_x_lon(getPointOfInterestPosition(pointOfInterest[POI][i]).lon());
            auto plat = get_y_lat(getPointOfInterestPosition(pointOfInterest[POI][i]).lat());
            if(plon < xmin || plon > xmax || plat < ymin || plat > ymax || count > 40)
                continue;
            ezgl::point2d plot_point(plon - (15/ratio_w), plat +(15/ratio_h));
            count ++;
            g->draw_surface(png, plot_point);
            shownPOIs.push_back(pointOfInterest[POI][i]);
     }
    g->free_surface(png);
}

//draw all the features in the map
void draw_all_feature(ezgl::renderer *g) {
    int featureNum = getNumFeatures();
    auto world = g->get_visible_world();
    auto area = world.area();
    auto xmin = get_lon_x(world.left() - 2 * world.width());
    auto xmax = get_lon_x(world.right() + 2 * world.width());
    auto ymin = get_lat_y(world.bottom() - 2 * world.height());
    auto ymax = get_lat_y(world.top() + 2 * world.height());
    bool draw = false;
    //go through all feathers and give them different colors based on types
    for(int i=0; i<featureNum; i++)
    {       
        auto featureIdx = feature_order[featureNum-i-1].second;
        FeatureType type = getFeatureType(featureIdx);
        if (type == Building && !enableBuiding) 
            continue;
        if( featureAreas[featureIdx] / (EARTH_RADIUS_METERS * EARTH_RADIUS_METERS) < 2e-4 * area && featureAreas[featureIdx] != 0 && (type == Park || type == Building))
            continue;

        if(type == Building) {
            auto currentX = getFeaturePoint(0, featureIdx).lon();
            auto currentY = getFeaturePoint(0, featureIdx).lat();
            if(! (currentX < xmax && currentX > xmin && currentY < ymax && currentY > ymin))
            {
                continue;
            } 
        }

        //each feature triggers the draw feature function and pass in color
        if(1)
        {
        
        if(type == Unknown)
        {
            ezgl::color featureColor(255, 255,255, 255);
            draw_one_feature(g, featureIdx, featureColor, area);
        }
        if(type == Park)
        {
            ezgl::color featureColor(186, 228,185, 255);
            draw_one_feature(g, featureIdx, featureColor, area);
        }
        if(type == Beach)
        {
            ezgl::color featureColor(255, 237,183, 255);
            draw_one_feature(g, featureIdx, featureColor, area);
        }
        if(type == Lake)
        {
            ezgl::color featureColor(155, 208,254, 255);
            draw_one_feature(g, featureIdx, featureColor, area);
        }
        if(type == River)
        {   
            ezgl::color featureColor(155,208,254, 255);
            draw_one_feature(g, featureIdx, featureColor, area);
        }
        if(type == Island)
        {
            ezgl::color featureColor(238, 236,233, 255);
            draw_one_feature(g, featureIdx, featureColor, area);
        }
        if(type == Building)
        {
           ezgl::color featureColor(220,220,220, 255);
           draw_one_feature(g, featureIdx, featureColor, area);
        }
        if(type == Greenspace)
        {
            ezgl::color featureColor(198, 234,197, 255);
            draw_one_feature(g, featureIdx, featureColor, area);
        }
        if(type == Golfcourse)
        {
            ezgl::color featureColor(190, 230,188, 255);
            draw_one_feature(g, featureIdx, featureColor, area);
        }
        if(type == Stream)
        {
            ezgl::color featureColor(155, 208,254, 255);
            draw_one_feature(g, featureIdx, featureColor, area);
           
        }
        }
    }

    
}

void draw_feature_info(ezgl::renderer *g) {
    g->set_coordinate_system(ezgl::WORLD);
    int featureNum = getNumFeatures();
    auto world = g->get_visible_world();
    auto area = world.area();
    auto xmin = get_lon_x(world.left() - 2 * world.width());
    auto xmax = get_lon_x(world.right() + 2 * world.width());
    auto ymin = get_lat_y(world.bottom() - 2 * world.height());
    auto ymax = get_lat_y(world.top() + 2 * world.height());

    for(int i=0; i<getNumFeatures(); i++)
    {       
        FeatureType type = getFeatureType(i);
        if (type == Building && !enableBuiding) 
            continue;
        if( featureAreas[i] / (EARTH_RADIUS_METERS * EARTH_RADIUS_METERS) < 2e-4 * area && featureAreas[i] != 0 && (type == Park || type == Building))
            continue;

        if(type == Building) {
            auto currentX = getFeaturePoint(0, i).lon();
            auto currentY = getFeaturePoint(0, i).lat();
            if(! (currentX < xmax && currentX > xmin && currentY < ymax && currentY > ymin))
            {
                continue;
            } 
        }

        if(getFeatureName(i) != "<noname>" && (zoomScale(g) > 500)) {
            g->set_text_rotation(0);
            g->set_font_size(10);
            g->set_color(50, 50, 50, 255);
            g->draw_text( { get_x_lon( featuresMidP[i].lon()),  get_y_lat( featuresMidP[i].lat()) } , getFeatureName(i) , get_x_lon(featuresMaxX[i]) * 2/3, get_x_lon(featuresMaxX[i]));
        }
    }
}

//draw a single streetseg
void draw_one_segments(ezgl::renderer *g, int segment_id, std::string roadType) {
    std::vector<ezgl::point2d> segment;
    InfoStreetSegment info = getInfoStreetSegment(segment_id);
    auto world = g->get_visible_world();
    auto xmin = get_lon_x(world.left() - 1 * world.width());
    auto xmax = get_lon_x(world.right() + 1 * world.width());
    auto ymin = get_lat_y(world.bottom() - 1 * world.height());
    auto ymax = get_lat_y(world.top() + 1 * world.height());
    auto sfrom = getIntersectionPosition(info.from);
    auto sto = getIntersectionPosition(info.to);
    if( ! ( (sfrom.lon() < xmax && sfrom.lon() > xmin && sfrom.lat() < ymax && sfrom.lat() > ymin ) || (sto.lon() < xmax && sto.lon() > xmin && sto.lat() < ymax && sto.lat() > ymin ) ) )
        return;

    ezgl::color lineColor(255, 255, 255, 255);
    double roadWidth;
    //determine the width of displaying the road by checking the zoom in level of the map
    auto lineWidth = zoomScale(g) / 1000;
    if (lineWidth > 20)
        lineWidth = 20;
    //using OSM in M1 to categorize all streets, and give them different colors
    if (roadType == "primary")
        {
            roadWidth = (lineWidth + 3);
            lineColor.red = 253;
            lineColor.green = 215;
            lineColor.blue = 161;
        }
        else if (roadType == "motorway")
        {
            roadWidth = (lineWidth + 3);
            lineColor.red = 233;
            lineColor.green = 144;
            lineColor.blue = 160;
        }
        else if (roadType == "trunk")
        {
            roadWidth = (lineWidth + 3);
            lineColor.red = 251;
            lineColor.green = 178;
            lineColor.blue = 154;
        }
        else if (roadType == "secondary")
        {
            roadWidth = (lineWidth + 2);
            lineColor.red = 254;
            lineColor.green = 240;
            lineColor.blue = 160;
        }
        else if (roadType == "tertiary")
        {
            roadWidth = (lineWidth + 2);

        }
        else if (roadType == "else"){
            roadWidth = (lineWidth + 0);
        }
        else if(roadType == "path") {
            roadWidth = (10);
            lineColor.red = 103;
            lineColor.green = 158;
            lineColor.blue = 245;
        }
        else if(roadType == "pathf") {
            roadWidth = (10);
            lineColor.red = 229;
            lineColor.green = 138;
            lineColor.blue = 116;
        } 
 
        ezgl::point2d begin_point(get_x_lon(getIntersectionPosition(info.from).lon()), get_y_lat(getIntersectionPosition(info.from).lat()));
        ezgl::point2d end_point(get_x_lon(getIntersectionPosition(info.to).lon()), get_y_lat(getIntersectionPosition(info.to).lat()));
        segment.push_back(begin_point);
        //draw street segments with all curve points
        for(int i=0; i<info.curvePointCount; i++)
        {
            LatLon curvePoints = getStreetSegmentCurvePoint(i, segment_id);
            ezgl::point2d curvePoint(get_x_lon(curvePoints.lon()), get_y_lat(curvePoints.lat()));
            segment.push_back(curvePoint);
        }
        segment.push_back(end_point);
        //draw streets names in the middle of street segments
        for(int i=0; i<segment.size()-1; i++)
        {   
            if(roadWidth >= 2)
            {   g->set_line_cap(ezgl::line_cap::butt);
                g->set_line_width(roadWidth + 2);
                g->set_color(210, 210, 210, 255);
                g->draw_line(segment[i], segment[i+1]);
            }
            g->set_line_cap(ezgl::line_cap::round);
            g->set_line_width(roadWidth);
            g->set_color(lineColor);
            g->draw_line(segment[i], segment[i+1]);
            if(zoomScale(g) > 5000 && getInfoStreetSegment(segment_id).oneWay) {
                ezgl::point2d cmid = {(segment[i].x + segment[i+1].x)/2, (segment[i].y + segment[i+1].y)/2};
                g->set_color(120, 120, 120, 255);
                g->set_font_size(12);
                auto angle =  atan( (segment[i+1].y - segment[i].y) / (segment[i+1].x - segment[i].x)) / DEGREE_TO_RADIAN ;
                g->set_text_rotation(angle) ;
                double curLength = std::sqrt( (segment[i].x - segment[i+1].x) * (segment[i].x - segment[i+1].x) +  (segment[i].y - segment[i+1].y) * (segment[i].y - segment[i+1].y));
                g->format_font("Serif", ezgl::font_slant::normal, ezgl::font_weight::bold);
                if ( (segment[i+1].x - segment[i].x) < 0)
                    g->draw_text(cmid, "  <--  " ,curLength, curLength);
                else
                    g->draw_text(cmid, "  -->  " ,curLength, curLength);
                g->format_font("Noto Sans Mono CJK SC",ezgl::font_slant::normal, ezgl::font_weight::normal);
            }
        }

}

//draw all the streets
void draw_all_segs(ezgl::renderer *g) {

    auto area = g->get_visible_world().area();
    //each zoom level displays different 
    //for each kind of road, there is specific color and different fonts for street names
    if (area < 6e-7) {
        for(int i = 0; i < elseSegs.size(); i++) {
            draw_one_segments(g, elseSegs[i], "else");
        }
    }
    
    if (area < 4.6e-6) {
        for(int i = 0; i < tertiarySegs.size(); i++) {
            draw_one_segments(g, tertiarySegs[i], "tertiary");
        }
    }

    
    if (area < 1e-4) {

        for(int i = 0; i < primarySegs.size(); i++) {
            draw_one_segments(g, primarySegs[i], "primary");
        }
        for(int i = 0; i < secondarySegs.size(); i++) {
            draw_one_segments(g, secondarySegs[i], "secondary");
        }
    }

    for(int i = 0; i < trunkSegs.size(); i++) {
        draw_one_segments(g, trunkSegs[i], "trunk");
    }

    for(int i = 0; i < motorwaySegs.size(); i++) {
         draw_one_segments(g, motorwaySegs[i], "motorway");
    }

    if (area < 6e-7) {
        for(int i = 0; i < elseSegs.size(); i++) {
            if (area < 6e-8) {
                g->set_color(100, 100, 100, 255);
                g->set_font_size(13);
                draw_street_names(g,elseSegs[i]);
            }
        }
    }

    if (area < 4.6e-6) {
        for(int i = 0; i < tertiarySegs.size(); i++) {
            if (area < 4.6e-7) {
                g->set_color(100, 100, 100, 255);
                g->set_font_size(13);
                draw_street_names(g,tertiarySegs[i]);
            }
        }
    }

    

    if (area < 1e-04 && area > 6.1e-08) {
        for(int i = 0; i < primarySegs.size(); i++) {
            g->set_color(223, 84, 49, 255);
            g->set_font_size(13);
            draw_street_names(g, primarySegs[i]);
        }
        for(int i = 0; i < secondarySegs.size(); i++) {
            g->set_color(244, 96, 96, 255);
            g->set_font_size(13);
            draw_street_names(g,secondarySegs[i]);
        }
    }
    if (area < 6.1e-08 ) {
        for(int i = 0; i < primarySegs.size(); i++) {
            g->set_color(223, 84, 49, 255);
            g->set_font_size(15);
            draw_street_names(g, primarySegs[i]);
        }
        for(int i = 0; i < secondarySegs.size(); i++) {
            g->set_color(244, 96, 96, 255);
            g->set_font_size(15);
            draw_street_names(g,secondarySegs[i]);
        }
    }
        
    for(int i = 0; i < trunkSegs.size(); i++) {
        g->set_color(181, 47, 7, 255);
        g->set_font_size(16);
        draw_street_names(g, trunkSegs[i]);
    }
    
  
    for(int i = 0; i < motorwaySegs.size(); i++) {
        g->set_color(143, 63, 10, 255);
        g->set_font_size(13);
        draw_street_names(g, motorwaySegs[i]);
    }
    
}


// get the angle of the points
double get_angle(LatLon a, LatLon b)
{
    double x_begin = get_x_lon(a.lon());
    double x_end = get_x_lon(b.lon());
    double y_begin = get_y_lat(a.lat());
    double y_end = get_y_lat(b.lat());
    double angle = atan((y_end-y_begin)/(x_end-x_begin))/DEGREE_TO_RADIAN;
    return angle;
}

// draw streets name on the segments
void draw_street_names(ezgl::renderer *g, int i){       
    InfoStreetSegment info = getInfoStreetSegment(i);
    if(curvatureSegs[i] > 1.001 || !enableStreetN)
        return;
    auto world = g->get_visible_world();
    double xmin = get_lon_x(world.left() - 1 * world.width());
    double xmax = get_lon_x(world.right() + 1 * world.width());
    double ymin = get_lat_y(world.bottom() - 1 * world.height());
    double ymax = get_lat_y(world.top() + 1 * world.height());
    auto sfrom = getIntersectionPosition(info.from);
    auto sto = getIntersectionPosition(info.to);
    if( ! ( (sfrom.lon() < xmax && sfrom.lon() > xmin && sfrom.lat() < ymax && sfrom.lat() > ymin ) || (sto.lon() < xmax && sto.lon() > xmin && sto.lat() < ymax && sto.lat() > ymin ) ) )
        return;

    //set fonts for street names
    g->format_font("Noto Sans Mono CJK SC",ezgl::font_slant::normal, ezgl::font_weight::normal);
            InfoStreetSegment segment = streetSegmentsInfo[i];
            LatLon begin_point = getIntersectionPosition(segment.from);
            LatLon end_point = getIntersectionPosition(segment.to);
            if(begin_point.lat() == end_point.lat() && begin_point.lon() == end_point.lon())
                return;
            std::string name = getStreetName(segment.streetID);
            ezgl::point2d mid_point((get_x_lon(begin_point.lon())+get_x_lon(end_point.lon()))/2, (get_y_lat(end_point.lat())+get_y_lat(begin_point.lat()))/2);
            //there are streets called "<unknown>" filter them out
            if(name != "<unknown>")
            {
                g->set_text_rotation(get_angle(begin_point, end_point));
                double distance_max = std::sqrt(pow(get_x_lon(begin_point.lon())-get_x_lon(end_point.lon()),2)+pow(get_x_lon(begin_point.lon())-get_x_lon(end_point.lon()),2));
                g->draw_text(mid_point, name, distance_max*3/4, distance_max*3/4);
                
            }

}

//draw the serach bar
void draw_bar(ezgl::renderer *g) {
    g->set_coordinate_system (ezgl::SCREEN);
    if (menuActivated)
    {
        g->set_color(230, 230, 230, 255);
        g->fill_rectangle(menuB);
    }
        
    else
    {
        g->set_color(255, 255, 255, 255);
        g->fill_rectangle(menuB);
    }
    ezgl::surface *png = g->load_png("libstreetmap/resources/menu3.png");
    
    ezgl::point2d menu_icon(20, 20);
    g->draw_surface(png, menu_icon);
    g->free_surface(png);

    
    g->set_color(176, 140, 200, 255);

    g->set_line_width(2);
    
    g->draw_rectangle(menuB);
    g->set_color(255, 255, 255, 255);
    g->fill_rectangle(searchBar);
    g->set_color(176, 140, 200, 255);
    g->set_line_width(1);
    g->draw_rectangle(searchBar);
    
    // the blinking bar resembles the real text input
    if(barClicked) {
        ezgl::point2d p1(58 + 12 * (searchText.size() -1) + 8, searchBar.top() - 2);
        ezgl::point2d p2(58 + 12 * (searchText.size() -1) + 8, searchBar.bottom() + 2);
        g->set_color(120, 120, 120, 255);
        g->set_line_width(2);
        g->draw_line(p1, p2);
    }

    g->set_coordinate_system (ezgl::WORLD);
}

//draw the search bar input text
void draw_stext(ezgl::renderer *g) {
    g->set_coordinate_system (ezgl::SCREEN);
    g->set_color(100, 100, 100, 255);
    for (int i = 0; i < searchText.size(); i++){
        ezgl::point2d a(58 + 12 * i, 35);
        std::string s;
        //display text that you typed into search bar
        s.push_back(searchText[i]);
        g->set_text_rotation(0);
        g->set_font_size(20);
        g->draw_text(a, s);
    }
    g->set_coordinate_system (ezgl::WORLD);

}

//draw the main menu
void draw_menu (ezgl::renderer *g) {

    //the menu bar that helps with 
    if (!menuActivated)
        return;
    g->set_coordinate_system (ezgl::SCREEN);
    g->set_color(245,245,245,255);
    mainMenu = {{0,0},370,g->get_visible_screen().height()};
    //draw a box as menu background
    ezgl::rectangle menu_icon = {{0,0}, 370, 100};
    g->fill_rectangle(mainMenu);
    g->set_color(157,110,183);
    g->fill_rectangle(menu_icon);
    
    g->set_text_rotation(0);
    g->set_font_size(30);
    

    //draw current city name under the search bar
    ezgl::point2d namesp(185, 75);
    g->set_color(255,255,255,255);
    g->set_text_rotation(0);
    if(!loading_map)
    {
        std::string map_name = currentMap + " Map";
        g->draw_text(namesp, map_name);
    }
    else
    {
        std::string map_name = "Loading Map...";
        g->draw_text(namesp, map_name);
    }
    //put png picture on the buttons to indicate their purpose
    auto pt = g->load_png("libstreetmap/resources/transportation.png");
    g->draw_surface(pt, first_menu_box.bottom_left());
    auto poi = g->load_png("libstreetmap/resources/explore.png");
    g->draw_surface(poi, second_menu_box.bottom_left());
    auto wd = g->load_png("libstreetmap/resources/cities.png");
    g->draw_surface(wd, fourth_menu_box.bottom_left());
    auto we = g->load_png("libstreetmap/resources/online.png");
    g->draw_surface(we, third_menu_box.bottom_left());
    auto rt = g->load_png("libstreetmap/resources/route2.png");
    g->draw_surface(rt, fifth_menu_box.bottom_left());
    g->format_font("Arial",ezgl::font_slant::normal, ezgl::font_weight::normal);
    g->set_font_size(24);
    g->set_color(207,173,229, 200);
    g->free_surface(pt);
    //if mouse moves over a button, highlight it with light color 
    if(menu_switch == 1)
    {
        g->fill_rectangle(first_menu_box);
        g->set_color(255,255,255);
        sub_menu = {{370,0},220, g->get_visible_screen().height()};
        g->fill_rectangle(sub_menu);
        //draw the submenu contents
        g->set_color(121,121,121);
        ezgl::point2d subway(480, 30);
        g->draw_text(subway, "Subway");
        ezgl::point2d tram(480, 90);
        g->draw_text(tram, "Tram");
        ezgl::point2d train(480, 150);
        g->draw_text(train, "Train");
        //if one of the submenu is activated, highlight them to show they are in use
        if(subwayEn) {
            g->set_color(170,170,170,160);
            g->fill_rectangle(sub_menu_1_box);
        }
        else if(tramEn) {
            g->set_color(170,170,170,160);
            g->fill_rectangle(sub_menu_2_box);
        }
        else if(trainEn) {
            g->set_color(170,170,170,160);
            g->fill_rectangle(sub_menu_3_box);
        }
        
    }
    if(menu_switch == 2)
    {
        //put png picture on the buttons to indicate their purpose
        g->fill_rectangle(second_menu_box);
        g->set_color(255,255,255);
        sub_menu = {{370,0},220, g->get_visible_screen().height()};
        g->fill_rectangle(sub_menu);
        g->set_color(101,101,101);
        ezgl::point2d restaurant(480, 30);
        g->draw_text(restaurant, "Restaurant");
        ezgl::point2d cafe(480, 90);
        g->draw_text(cafe, "Cafe");
        ezgl::point2d cinema(480, 150);
        g->draw_text(cinema, "Cinema");
        ezgl::point2d theatre(480, 210);
        g->draw_text(theatre, "Theatre");
        ezgl::point2d pharmacy(480, 270);
        g->draw_text(pharmacy, "Pharmacy");
        ezgl::point2d school(480, 330);
        g->draw_text(school, "School");
        ezgl::point2d bank(480, 390);
        g->draw_text(bank, "Bank");
        ezgl::point2d ATM(480, 450);
        g->draw_text(ATM, "ATM");
        ezgl::point2d hospital(480, 510);
        g->draw_text(hospital, "Hospital");
        ezgl::point2d fast_food(480, 570);
        g->draw_text(fast_food, "Fast food");
        ezgl::point2d pub(480, 630);
        g->draw_text(pub, "Pub");
        ezgl::point2d dentist(480, 690);
        g->draw_text(dentist, "Dentist");
        ezgl::point2d Library(480, 750);
        g->draw_text(Library, "Library");
        ezgl::point2d Building(480, 810);
        g->draw_text(Building, "Building");
        
       //if one of the submenu is activated, highlight them to show they are in use
        g->set_color(170,170,170,160);
        if(POI == 0)
        {
            g->fill_rectangle(sub_menu_1_box);
        }
        else if(POI == 1)
        {
            g->fill_rectangle(sub_menu_2_box);
        }
        else if(POI == 2)
        {
            g->fill_rectangle(sub_menu_3_box);
        }
        else if(POI == 3)
        {
            g->fill_rectangle(sub_menu_4_box);
        }
        else if(POI == 4)
        {
            g->fill_rectangle(sub_menu_5_box);
        }
        else if(POI == 5)
        {
            g->fill_rectangle(sub_menu_6_box);
        }
        else if(POI == 6)
        {
            g->fill_rectangle(sub_menu_7_box);
        }
        else if(POI == 7)
        {
            g->fill_rectangle(sub_menu_8_box);
        }
        else if(POI == 8)
        {
            g->fill_rectangle(sub_menu_9_box);
        }
        else if(POI == 9)
        {
            g->fill_rectangle(sub_menu_10_box);
        }
        else if(POI == 10)
        {
            g->fill_rectangle(sub_menu_11_box);
        }
        else if(POI == 11)
        {
            g->fill_rectangle(sub_menu_12_box);
        }
        else if(POI == 12)
        {
            g->fill_rectangle(sub_menu_13_box);
        }
        else if(POI == 13)
        {
            g->fill_rectangle(sub_menu_14_box);
        }
        if(enableBuiding)
        {
            g->fill_rectangle(sub_menu_14_box);
        }
        
    }
    if(menu_switch ==3)
    {
        //put png picture on the buttons to indicate their purpose
        g->fill_rectangle(third_menu_box);
        g->set_color(255,255,255);
        sub_menu = {{370,0},220, g->get_visible_screen().height()};
        g->fill_rectangle(sub_menu);
        g->set_color(101,101,101);
        ezgl::point2d weather(480, 30);
        g->draw_text(weather, "Weather");
        ezgl::point2d Road(480, 90);
        g->draw_text(Road, "Closure");
        g->set_color(170,170,170,160);
        //if one of the submenu is activated, highlight them to show they are in use
        if(weatherEn)
        {
            g->fill_rectangle(sub_menu_1_box);
        }
        if(trafficEn)
        {
            g->fill_rectangle(sub_menu_2_box);
        }
        
    }
    if(menu_switch ==4)
    {
        //put png picture on the buttons to indicate their purpose
        g->fill_rectangle(fourth_menu_box);
        g->set_color(255,255,255);
        sub_menu = {{370,0},220, g->get_visible_screen().height()};
        g->fill_rectangle(sub_menu);
        g->set_color(101,101,101);
        ezgl::point2d beijing(480, 30);
        g->draw_text(beijing, "Beijing");
        ezgl::point2d Toronto(480, 90);
        g->draw_text(Toronto, "Toronto");
        ezgl::point2d new_york(480, 150);
        g->draw_text(new_york, "New York");
        ezgl::point2d hong_kong(480, 210);
        g->draw_text(hong_kong, "Hong Kong");
        ezgl::point2d London(480, 270);
        g->draw_text(London, "London");
        ezgl::point2d Sydney(480, 330);
        g->draw_text(Sydney, "Sydney");
        ezgl::point2d Singapore(480, 390);
        g->draw_text(Singapore, "Singapore");
        ezgl::point2d Moscow(480, 450);
        g->draw_text(Moscow, "Moscow");
    }
    //if one of the submenu is activated, highlight them to show they are in use
    if(menu_switch ==5)
    {
        g->fill_rectangle(fifth_menu_box);
        
    }
    g->set_color(207,173,229, 200);
    if(sub_menu_switch == 1)
    {
        g->fill_rectangle(sub_menu_1_box);
    }
    else if(sub_menu_switch ==2)
    {
        g->fill_rectangle(sub_menu_2_box);
    }
    else if(sub_menu_switch ==3)
    {
        g->fill_rectangle(sub_menu_3_box);
    }
    else if(sub_menu_switch ==4)
    {
        g->fill_rectangle(sub_menu_4_box);
    }
    else if(sub_menu_switch ==5)
    {
        g->fill_rectangle(sub_menu_5_box);
    }
    else if(sub_menu_switch ==6)
    {
        g->fill_rectangle(sub_menu_6_box);
    }
    else if(sub_menu_switch ==7)
    {
        g->fill_rectangle(sub_menu_7_box);
    }
    else if(sub_menu_switch ==8)
    {
        g->fill_rectangle(sub_menu_8_box);
    }
    else if(sub_menu_switch ==9)
    {
        g->fill_rectangle(sub_menu_9_box);
    }
    else if(sub_menu_switch ==10)
    {
        g->fill_rectangle(sub_menu_10_box);
    }
    else if(sub_menu_switch ==11)
    {
        g->fill_rectangle(sub_menu_11_box);
    }
    else if(sub_menu_switch ==12)
    {
        g->fill_rectangle(sub_menu_12_box);
    }
    else if(sub_menu_switch ==13)
    {
        g->fill_rectangle(sub_menu_13_box);
    }
    else if(sub_menu_switch ==14)
    {
        g->fill_rectangle(sub_menu_14_box);
    }
    else if(sub_menu_switch ==15)
    {
        g->fill_rectangle(sub_menu_15_box);
    }
    else if(sub_menu_switch ==16)
    {
        g->fill_rectangle(sub_menu_16_box);
    }
    
    else
    {
        
    }
    //physical shadow at the side of menu, to add more element of reality
    draw_sub_shadow(g);
    g->format_font("Noto Sans Mono CJK SC",ezgl::font_slant::normal, ezgl::font_weight::normal);
}


//draw menu shadow

void draw_sub_shadow(ezgl::renderer *g)
{
    for(int i =0; i<5; i++)
    {
        //a fading shadow effect by drawing lines of different darkness
        g->set_line_width(3);
        g->set_color(120+25*i,120+25*i,120+25*i, 90);
        ezgl::point2d shadow_begin(first_menu_box.right()+i, 0);
        ezgl::point2d shadow_end(first_menu_box.right()+i, g->get_visible_screen().height());
        g->draw_line(shadow_begin, shadow_end);
    }
}

//reload another map and clear data structure for current map
bool reloadMap (std::string name) {
    std::string path;
    bool load = false;
    if (name == format(currentMap))
        return false;
    if (name == "beijing") {
        path = "/cad2/ece297s/public/maps/beijing_china.streets.bin";
        load = true;
        currentMap = "Beijing";
    }
    else if (name == "goldenhorseshoe") {
        path = "/cad2/ece297s/public/maps/golden-horseshoe_canada.streets.bin";
        load = true;
        currentMap = "Golden Horseshoe";
    }
    else if (name == "iceland") {
        path = "/cad2/ece297s/public/maps/iceland.streets.bin";
        load = true;
        currentMap = "Iceland";
    }
    else if (name == "newdelhi") {
        path = "/cad2/ece297s/public/maps/new-delhi_india.streets.bin";
        load = true;
        currentMap = "New Delhi";
    }
    else if (name == "sainthelena") {
        path = "/cad2/ece297s/public/maps/saint-helena.streets.bin";
        load = true;
        currentMap = "Saint Helena";
    }
    else if (name == "tehran") {
        path = "/cad2/ece297s/public/maps/tehran_iran.streets.bin";
        load = true;
        currentMap = "Tehran";
    }
    else if (name == "interlaken") {
        path = "/cad2/ece297s/public/maps/interlaken_switzerland.streets.bin";
        load = true;
        currentMap = "Interlaken";
    }
    else if (name == "tokyo") {
        path = "/cad2/ece297s/public/maps/tokyo_japan.streets.bin";
        load = true;
        currentMap = "Tokyo";
    }
    else if (name == "cairo") {
        path = "/cad2/ece297s/public/maps/cairo_egypt.streets.bin";
        load = true;
        currentMap = "Cario";
    }
    else if (name == "hamilton") {
        path = "/cad2/ece297s/public/maps/hamilton_canada.streets.bin";
        load = true;
        currentMap = "Hamilton";
    }
    else if (name == "london") {
        path = "/cad2/ece297s/public/maps/london_england.streets.bin";
        load = true;
        currentMap = "London";
    }
    else if (name == "newyork") {
        path = "/cad2/ece297s/public/maps/new-york_usa.streets.bin";
        load = true;
        currentMap = "New York";
    }
    else if (name == "singapore") {
        path = "/cad2/ece297s/public/maps/singapore.streets.bin";
        load = true;
        currentMap = "Singapore";
    }
    else if (name == "toronto") {
        path = "/cad2/ece297s/public/maps/toronto_canada.streets.bin";
        load = true;
        currentMap = "Toronto";
    }
    else if (name == "hongkong") {
        path = "/cad2/ece297s/public/maps/hong-kong_china.streets.bin";
        load = true;
        currentMap = "Hong Kong";
    }
    else if (name == "sydney") {
        path = "/cad2/ece297s/public/maps/sydney_australia.streets.bin";
        load = true;
        currentMap = "Sydney";
    } 
    else if (name == "capetown") {
        path = "/cad2/ece297s/public/maps/cape-town_south-africa.streets.bin";
        load = true;
        currentMap = "Cape Town";
    }
    else if (name == "moscow") {
        path = "/cad2/ece297s/public/maps/moscow_russia.streets.bin";
        load = true;
        currentMap = "Moscow";
    }
    else if (name == "riodejaneiro" || name == "rio") {
        path = "/cad2/ece297s/public/maps/rio-de-janeiro_brazil.streets.bin";
        load = true;
        currentMap = "Rio De Janeiro";
    }                   
    if (load) {
        //clear all created data structures to avoid mem leak
        close_map();
        intersectionPosition.clear();
        feature_order.clear();
        foundIntersIDs.clear();
        foundPOIIDs.clear();
        currentRelationNodes.clear();
        nodeRname.clear();
        currentIncidents.clear();
        cIncidents.clear();
        cIncidents.clear();
        shownPOIs.clear();
        searchText1.clear();
        searchText2.clear();
        firstinter = -1;
        secondinter = -1;
        routeMenuA = false;
        cpath.clear();
        wpath.clear();
        navigationPoints.clear();
        navigationInstructions.clear();
        wplusdpaths.first.clear();
        wplusdpaths.second.clear();
        
        load_map(path);
    }
    return load;
}
//redraw another map
void redrawMap (ezgl::application *application) {
    boundary_initalize();
    //reinitialize the boundaries of the map, recreated the canvas size and acquire weather info
    ezgl::rectangle world{{init_x, init_y}, {end_x, end_y}};
    application->get_canvas("MainCanvas")->get_camera().reset_world(world);
    application->get_canvas("MainCanvas")->get_camera().set_world(world);
    application->get_renderer()->set_visible_world(world);
    cWeather = getWeatherInfo(get_lat_y(application->get_renderer()->get_visible_world().center_y()), get_lon_x(application->get_renderer()->get_visible_world().center_x()));
	application->refresh_drawing();
}

// draw the clicked intersection
void draw_clicked_inter(ezgl::renderer *g) {
    if (!onMap || tramEn || subwayEn || trainEn || trainEn || (trafficEn && currentIncidents.size() !=0 ) || clickedPOI != -1) {
        interID = -1;
        preinterID = -1;
        return;
    }
    //if one intersection or POI or transportation(if activated)
    auto x = worldClickedPoint.first;
    auto y = worldClickedPoint.second;
    auto lat = get_lat_y(y);
    auto lon = get_lon_x(x);
    LatLon clickedPoint(lat, lon);
    //get the closest intersection id is click on a certain area
    auto closestInterID = find_closest_intersection(clickedPoint);
    auto closestInter = getIntersectionPosition(closestInterID);
    auto distance = find_distance_between_two_points(std::make_pair(clickedPoint, closestInter));
    if (distance > 10) {
        interID = -1;
        preinterID = -1;
        return;
    }
    if(closestInterID != interID)
        preinterID = interID;
    interID = closestInterID;
    if(routeMode)
        return;
    g->set_coordinate_system(ezgl::WORLD);
    ezgl::point2d png_point(get_x_lon(closestInter.lon()), get_y_lat(closestInter.lat()));
    double ratio_h = g->get_visible_screen().height()/g->get_visible_world().height();
    double ratio_w = g->get_visible_screen().width()/g->get_visible_world().width();
    //plot the png on the location of intersection or something else
    ezgl::point2d plot_point(get_x_lon(closestInter.lon())-(20/ratio_w), get_y_lat(closestInter.lat())+(40/ratio_h));
    ezgl::surface *png = g->load_png("libstreetmap/resources/alpha.png");
    g->draw_surface(png, plot_point);
    g->free_surface(png);
    
}

// draw the inter box
void draw_intersection_box(ezgl::renderer *g)
{
    g->set_coordinate_system(ezgl::SCREEN);
    g->set_color(255, 255, 255, 200);
    g->fill_rectangle(menuPop);
    
}
// draw information box
void draw_InfoBox(ezgl::renderer *g) {
    auto screenRec = g->get_visible_screen();

    double midX = (screenRec.left() + screenRec.right())/2;
    InfoBox = {{midX - 325, screenRec.top() - 160}, 650, 120};
    infoBoxActivated = false;
    infoboxGoto = {{InfoBox.right() - 80, InfoBox.bottom() + 35}, 50, 50};
    infointermode = false;
    if (incidentID >=0 && trafficEn) {
        //if this is activated, the info box will support closure information
        infoBoxActivated = true;
        g->set_coordinate_system(ezgl::SCREEN);
        ezgl::surface *png = g->load_png("libstreetmap/resources/infobox.png");
        g->draw_surface(png, {InfoBox.left() - 5, InfoBox.bottom() - 5});
        g->free_surface(png);
        g->set_color(50,50,50,255);

        g->set_text_rotation(0);
        g->set_font_size(13);
         g->draw_text({(InfoBox.left() + InfoBox.right())/2 , InfoBox.bottom() + 30}, currentIncidents[incidentID].desc);
         g->set_color(getColour("#330033"));
        g->set_font_size(17);
         g->draw_text({(InfoBox.left() + InfoBox.right())/2 , InfoBox.bottom() + 90}, "Road Closure");

        //  std::string coorText = std::to_string(getIntersectionPosition(interID).lon()) + ", " + std::to_string(getIntersectionPosition(interID).lat());
         g->set_color(120,120,120,255);
         g->set_font_size(12);
         g->draw_text({(InfoBox.left() + InfoBox.right())/2 , InfoBox.bottom() + 60}, "Start Time: " + currentIncidents[incidentID].startime + " End Time:" + currentIncidents[incidentID].endtime);
         g->set_coordinate_system(ezgl::WORLD);
    }
    else if(interID >= 0 && !routeMode) {
        //if not in path finding mode, info box will display regular info
        infoBoxActivated = true;
        g->set_coordinate_system(ezgl::SCREEN);
        ezgl::surface *png = g->load_png("libstreetmap/resources/infobox.png");
        g->draw_surface(png, {InfoBox.left() - 5, InfoBox.bottom() - 5});
        g->free_surface(png);
        g->set_text_rotation(0);
        
         g->set_color(50,50,50,255);
        g->set_font_size(15);
         g->draw_text({(InfoBox.left() + InfoBox.right())/2 , InfoBox.bottom() + 30}, getIntersectionName(interID));
         g->set_color(238,129,102,255);
        g->set_font_size(17);
         g->draw_text({(InfoBox.left() + InfoBox.right())/2 , InfoBox.bottom() + 90}, "Intersection");
        //road closure information
         g->set_color(120,120,120,255);
         g->set_font_size(12);
         g->draw_text({(InfoBox.left() + InfoBox.right())/2 , InfoBox.bottom() + 60}, getLocationInfo(getIntersectionPosition(interID).lat(),getIntersectionPosition(interID).lon()));

        ezgl::surface *gpng = g->load_png("libstreetmap/resources/traffic.png");
        g->draw_surface(gpng, infoboxGoto.bottom_left());
        g->free_surface(gpng);

        infointermode = true;

         g->set_coordinate_system(ezgl::WORLD);
     }
    //if not route mode, clicked on some intersection
     else if(clickedFoundInter >= 0 && searchBI ==0 && !routeMode) {
        infoBoxActivated = true;
        g->set_coordinate_system(ezgl::SCREEN);
        ezgl::surface *png = g->load_png("libstreetmap/resources/infobox.png");
        g->draw_surface(png, {InfoBox.left() - 5, InfoBox.bottom() - 5});
        g->free_surface(png);
        g->set_text_rotation(0);

        ezgl::surface *gpng = g->load_png("libstreetmap/resources/traffic.png");
        g->draw_surface(gpng, infoboxGoto.bottom_left());
        g->free_surface(gpng);
        infointermode = true;
         g->set_color(50,50,50,255);
             g->set_font_size(15);
         g->draw_text({(InfoBox.left() + InfoBox.right())/2 , InfoBox.bottom() + 30}, getIntersectionName(clickedFoundInter));
         g->set_color(238,129,102,255);
             g->set_font_size(17);
         g->draw_text({(InfoBox.left() + InfoBox.right())/2 , InfoBox.bottom() + 90}, "Intersection");
         //use online api to get specific address of intersection
         std::string coorText = std::to_string(getIntersectionPosition(clickedFoundInter).lon()) + ", " + std::to_string(getIntersectionPosition(clickedFoundInter).lat());
         g->set_color(120,120,120,255);
             g->set_font_size(12);
         g->draw_text({(InfoBox.left() + InfoBox.right())/2 , InfoBox.bottom() + 60}, getLocationInfo(getIntersectionPosition(clickedFoundInter).lat(),getIntersectionPosition(clickedFoundInter).lon()));
         g->set_coordinate_system(ezgl::WORLD);
     }

     else if(clickedFoundInter >= 0 && searchBI ==1 && !routeMode) {
        infoBoxActivated = true;
        g->set_coordinate_system(ezgl::SCREEN);
        ezgl::surface *png = g->load_png("libstreetmap/resources/infobox.png");
        g->draw_surface(png, {InfoBox.left() - 5, InfoBox.bottom() - 5});
        g->free_surface(png);
        g->set_text_rotation(0);

         g->set_color(50,50,50,255);
             g->set_font_size(15);
         g->draw_text({(InfoBox.left() + InfoBox.right())/2 , InfoBox.bottom() + 30}, getPointOfInterestName(clickedFoundInter));
         g->set_color(238,129,102,255);
             g->set_font_size(17);
         g->draw_text({(InfoBox.left() + InfoBox.right())/2 , InfoBox.bottom() + 90}, convert_string(getPointOfInterestType(clickedFoundInter)));

         std::string coorText = std::to_string(getPointOfInterestPosition(clickedFoundInter).lon()) + ", " + std::to_string(getPointOfInterestPosition(clickedFoundInter).lat());
         g->set_color(120,120,120,255);
             g->set_font_size(12);
         g->draw_text({(InfoBox.left() + InfoBox.right())/2 , InfoBox.bottom() + 60}, getLocationInfo(getPointOfInterestPosition(clickedFoundInter).lat(),getPointOfInterestPosition(clickedFoundInter).lon()));
         g->set_coordinate_system(ezgl::WORLD);
     }

     else if( clickedPOI >= 0) {
         //if clicked on POI, display information from OSM
         infoBoxActivated = true;
        g->set_coordinate_system(ezgl::SCREEN);
        ezgl::surface *png = g->load_png("libstreetmap/resources/infobox.png");
        g->draw_surface(png, {InfoBox.left() - 5, InfoBox.bottom() - 5});
        g->free_surface(png);
        g->set_text_rotation(0);

         g->set_color(50,50,50,255);
             g->set_font_size(15);
         g->draw_text({(InfoBox.left() + InfoBox.right())/2 , InfoBox.bottom() + 30}, getPointOfInterestName(clickedPOI));
         g->set_color(238,129,102,255);
             g->set_font_size(17);
             //display POI type and name on the info box
         g->draw_text({(InfoBox.left() + InfoBox.right())/2 , InfoBox.bottom() + 90}, convert_string(getPointOfInterestType(clickedPOI)));

         std::string coorText = std::to_string(getPointOfInterestPosition(clickedPOI).lon()) + ", " + std::to_string(getPointOfInterestPosition(clickedPOI).lat());
         g->set_color(120,120,120,255);
             g->set_font_size(12);
         g->draw_text({(InfoBox.left() + InfoBox.right())/2 , InfoBox.bottom() + 60}, getLocationInfo(getPointOfInterestPosition(clickedPOI).lat(),getPointOfInterestPosition(clickedPOI).lon()));
         g->set_coordinate_system(ezgl::WORLD);
     }

     else if (clickedOSMNode.first) {
         //get information from OSM database of public transportation 
         infoBoxActivated = true;
         g->set_coordinate_system(ezgl::SCREEN);
         ezgl::surface *png = g->load_png("libstreetmap/resources/infobox.png");
        g->draw_surface(png, {InfoBox.left() - 5, InfoBox.bottom() - 5});
        g->free_surface(png);
        g->set_text_rotation(0);

        auto rname = nodeRname.find(clickedOSMNode.second)->second;
        std::string nname;
        for(int j = 0; j < getTagCount(OSMID_OSMNodes.find(clickedOSMNode.second)->second); j++) {
                auto pair = getTagPair(OSMID_OSMNodes.find(clickedOSMNode.second)->second, j);
                if(pair.first == "name") {
                    nname = pair.second;
                    break;
                }
        }
        g->set_color(50,50,50,255);
            g->set_font_size(15);
         g->draw_text({(InfoBox.left() + InfoBox.right())/2 , InfoBox.bottom() + 30}, nname);
         std::string prename;
         //if one button of transportation is clicked, set different colors for each type
         if(trainEn) {
             g->set_color(getColour("#8A916F"));
             prename = "Train ";

         }
         if(tramEn) {
             g->set_color(getColour("#5E6BA2"));
             prename = "Tram ";
         }
         if(subwayEn) {
            
             g->set_color(getColour("#B34D8A"));
              prename = "Subway ";
         }
             g->set_font_size(17);
         g->draw_text({(InfoBox.left() + InfoBox.right())/2 , InfoBox.bottom() + 90}, prename + "Station");
         g->set_font_size(13);
    
         g->set_color(120,120,120,255);
         g->draw_text({(InfoBox.left() + InfoBox.right())/2 , InfoBox.bottom() + 60}, rname);
        
        
     }

}

// draw search results
void draw_searchBox(ezgl::renderer *g) {
    if (searchBoxActivated) {
        //show the best matching 5 results when search bar is used
        g->set_coordinate_system(ezgl::SCREEN);
        g->set_color(245,245,245,200);
        g->fill_rectangle(searchBox);
        g->set_color(200,200,200,200);
        g->set_line_width(0);
        for(int i = 0; i < 5; i++) {
            g->draw_line({searchBox.left(), searchBox.bottom() + (i+1) * 40} , {searchBox.right(), searchBox.bottom() + (i+1) * 40});
        }
        g->set_color(100,100,100,200);
        g->set_text_rotation(0);
        g->set_font_size(15);
        //when searching a intersection
        if (searchBI == 0)
            for(int i = 0; i < foundIntersIDs.size(); i++) {
                g->draw_text({ (searchBox.right() + searchBox.left())/2, searchBox.bottom() + 20 + i * 40}, getIntersectionName(foundIntersIDs[i]));
            }
        else if(searchBI == 1) {
            //when searching a POI
            for(int i = 0; i < foundPOIIDs.size(); i++) {
                g->draw_text({ (searchBox.right() + searchBox.left())/2, searchBox.bottom() + 20 + i * 40}, getPointOfInterestName(foundPOIIDs[i]) + " (" + 
                getLocationInfo(getPointOfInterestPosition(foundPOIIDs[i]).lat(), getPointOfInterestPosition(foundPOIIDs[i]).lon()) + ")");
            }
        }
    }
}

//draw clicked search results
void draw_clickedFoundInter(ezgl::renderer *g) {
    if(clickedFoundInter < 0 || movedTomid == false || routeMode) 
        return;
    LatLon inter;
    if(searchBI == 0)
        inter = getIntersectionPosition(clickedFoundInter);
    if(searchBI == 1)
        inter = getPointOfInterestPosition(clickedFoundInter);
    ezgl::point2d png_point(get_x_lon(inter.lon()), get_y_lat(inter.lat()));
    double ratio_h = g->get_visible_screen().height()/g->get_visible_world().height();
    double ratio_w = g->get_visible_screen().width()/g->get_visible_world().width();
    //clicking on a intersection will label it
    ezgl::point2d plot_point(get_x_lon(inter.lon())-(20/ratio_w), get_y_lat(inter.lat())+(40/ratio_h));
    ezgl::surface *png = g->load_png("libstreetmap/resources/alpha.png");
    g->draw_surface(png, plot_point);
    g->free_surface(png);
}

//move to a point on map
void moveToMidpoint(ezgl::renderer *g, double x, double y, double route) {
    auto cX = get_x_lon(x);
    auto cY = get_y_lat(y);
    auto cW = g->get_visible_world();
    //relocate the center of the map to certain point
    ezgl::rectangle fW;
    if(route == 0)
        fW = {{cX - cW.width() / 2, cY - cW.height() /2}, cW.width(), cW.height()};
    else
    {
        double lsizex = route * 1.3;
        double lsizey = ( lsizex / cW.width() ) * cW.height();
        fW = {{cX - lsizex / 2, cY - lsizey /2}, lsizex, lsizey};
    }
    
    g->set_visible_world(fW);
}
void drawRouteBox(ezgl::renderer *g)
{
//    g->set_coordinate_system(ezgl::SCREEN);
//    int middle point = 
//    ezgl::rectangle route = 
//    if(routeMode)
//    {
//        g->set_color(176, 140, 200);
//        g->fill_rectangle(route_box);
//        
//    }
    
}
//draw the public transportation route
void draw_relation(ezgl::renderer *g) {
    //there are real colors in each cities' transportation
    if(subwayEn) {
        std::vector<OSMID> nodes;
        std::unordered_map<std::string, int> nnames;
        auto np = &nnames;
        std::unordered_map<OSMID, std::string> nodeRnameTemp;
        for(int i = 0; i < OSMsubway.size(); i++) {
            
            ezgl::color color;
            std::string rName;
            // get the OSM data of this line, including color and line name
            for(int j = 0; j < getTagCount(OSMsubway[i]); j++) {
                auto tagpair = getTagPair(OSMsubway[i], j);
                if(tagpair.first == "colour") {
                    // std::cout << tagpair.second << "\n";
                    color =  getColour(tagpair.second);
                }
                else if(tagpair.first == "name") {
                    rName = tagpair.second;
//                    std::cout << tagpair.second << "\n";
                }
            }

            //use OSM data to draw transportation lines
            std::vector<TypedOSMID> route_members = getRelationMembers(OSMsubway[i]);
            for (int j = 0; j < route_members.size(); j++) {
                if(route_members[j].type() == TypedOSMID::Way) {
                    auto currentWay = getWayByIndex(OSMID_OSMWayID.find(route_members[j])->second);
                    //OSM API
                    auto waynodes = getWayMembers(currentWay);
                    //use OSM info to draw special transportation line
                    draw_osmway(g, waynodes, color);
                }
                else if(route_members[j].type() == TypedOSMID::Node) {
                    nodes.push_back(route_members[j]);
                    nodeRnameTemp.insert(std::make_pair(route_members[j], rName));
                }
            }
            
        }
        //on each node like stops, stations, draw name of them at the location
        draw_osmnodes(g, nodes,np);
        currentRelationNodes = nodes;
        nodeRname = nodeRnameTemp;
    }

    if(tramEn) {
        //there are real colors in each cities' transportation
        std::unordered_map<std::string, int> nnames;
        auto np = &nnames;
        std::vector<OSMID> nodes;
        std::unordered_map<OSMID, std::string> nodeRnameTemp;
        for(int i = 0; i < OSMtram.size(); i++) {
            
            ezgl::color color;
            std::string rName;
            for(int j = 0; j < getTagCount(OSMtram[i]); j++) {
                auto tagpair = getTagPair(OSMtram[i], j);
                if(tagpair.first == "colour") {
                    // std::cout << tagpair.second << "\n";
                    color =  getColour(tagpair.second);
                }
                else if(tagpair.first == "name") {
                    rName = tagpair.second;
//                    std::cout << tagpair.second << "\n";
                }
            }


            std::vector<TypedOSMID> route_members = getRelationMembers(OSMtram[i]);
            for (int j = 0; j < route_members.size(); j++) {
                if(route_members[j].type() == TypedOSMID::Way) {
                    //OSM API
                    auto currentWay = getWayByIndex(OSMID_OSMWayID.find(route_members[j])->second);
                    auto waynodes = getWayMembers(currentWay);
                    draw_osmway(g, waynodes, color);
                }
                //use OSM info to draw special transportation line
                else if(route_members[j].type() == TypedOSMID::Node) {
                    nodes.push_back(route_members[j]);
                    nodeRnameTemp.insert(std::make_pair(route_members[j], rName));
                }
            }
            
        }
        draw_osmnodes(g, nodes,np);
        currentRelationNodes = nodes;
        //on each node like stops, stations, draw name of them at the location
        nodeRname = nodeRnameTemp;
    }

    if(trainEn) {
        //there are real colors in each cities' transportation
        std::unordered_map<std::string, int> nnames;
        auto np = &nnames;
        std::vector<OSMID> nodes;
        std::unordered_map<OSMID, std::string> nodeRnameTemp;
        for(int i = 0; i < OSMtrain.size(); i++) {
            
            ezgl::color color;
            std::string rName;
            for(int j = 0; j < getTagCount(OSMtrain[i]); j++) {
                auto tagpair = getTagPair(OSMtrain[i], j);
                if(tagpair.first == "colour") {
                    // std::cout << tagpair.second << "\n";
                    color =  getColour(tagpair.second);
                }
                else if(tagpair.first == "name") {
                    rName = tagpair.second;
//                    std::cout << tagpair.second << "\n";
                }
            }


            std::vector<TypedOSMID> route_members = getRelationMembers(OSMtrain[i]);
            for (int j = 0; j < route_members.size(); j++) {
                if(route_members[j].type() == TypedOSMID::Way) {
                    auto currentWay = getWayByIndex(OSMID_OSMWayID.find(route_members[j])->second);
                    auto waynodes = getWayMembers(currentWay);
                    //use OSM info to draw special transportation line
                    draw_osmway(g, waynodes, color);
                }
                else if(route_members[j].type() == TypedOSMID::Node) {
                    nodes.push_back(route_members[j]);
                    nodeRnameTemp.insert(std::make_pair(route_members[j], rName));
                }
            }
            
        }
        //on each node like stops, stations, draw name of them at the location
        draw_osmnodes(g, nodes,np);
        currentRelationNodes = nodes;
        nodeRname = nodeRnameTemp;
    }
}

//convert hex to dec
int hexToDe (const char *hex) {
        if(*hex == 'a' || *hex == 'A')
            return 10;
        if(*hex == 'b' || *hex =='B')
            return 11;
        if(*hex == 'c' || *hex =='C')
            return 12;
        if(*hex == 'd' || *hex =='D')
            return 13;
        if(*hex == 'e' || *hex =='E')
            return 14;
        if(*hex == 'f' || *hex =='F')
            return 15;
        return int(*hex) - int('0');
}

//convert color code to ezgl color
ezgl::color getColour(std::string color) {
    std::string icolor;
//    std::cout << color << "\n";
    if(color == "green") 
        icolor = "008000";
    else if(color == "red") 
        icolor = "FF0000";
    else if(color == "yellow") 
        icolor = "FFFF00";
    else if(color == "blue") 
        icolor = "0000FF";
    else if(color == "purple") 
        icolor = "800080";
    else if(color == "darkgreen") 
        icolor = "006400";
    else if(color == "brown") 
        icolor = "A52A2A";
    else if(color == "orange") 
        icolor = "FFA500";
    else
        icolor = "A9A9A9";

    if(color[0] == '#') {
        icolor = color.substr(1, color.size());
    }
    int r =16 * hexToDe(&icolor[0]) +  hexToDe(&icolor[1]);
    int g = 16 * hexToDe(&icolor[2]) + hexToDe(&icolor[3]);
    int b = 16 * hexToDe(&icolor[4]) + hexToDe(&icolor[5]);

//    std::cout << r <<" " << g << " " << b <<"\n";

    ezgl::color s(r, g, b, 255);
    return s;
}

// draw osm way
void draw_osmway(ezgl::renderer *g, std::vector<OSMID> nodes, ezgl::color color) {
    for (int i = 0; i < nodes.size() - 1; i++) {
        //use OSM API to draw special information of OSM
        auto fn = *OSMID_OSMNodes.find(nodes[i]);
        auto sn = *(OSMID_OSMNodes.find(nodes[i+1]));
        auto firstp = getNodeCoords( fn.second );
        auto secondp = getNodeCoords( sn.second );
        g->set_line_width(2);
        g->set_line_cap(ezgl::line_cap::round);
        g->set_color(color);
        g->draw_line( { get_x_lon(firstp.lon()) , get_y_lat(firstp.lat())} , { get_x_lon(secondp.lon()) , get_y_lat(secondp.lat())});
    }
}

//draw osm node
void draw_osmnodes(ezgl::renderer *g, std::vector<OSMID> nodes, std::unordered_map<std::string, int> *nnames) {
    if (zoomScale(g) < 10) 
        return;
    //use special data to draw nodes like subway stations, tram stations
    for (int i = 0; i < nodes.size(); i ++) {

        auto fn = *OSMID_OSMNodes.find(nodes[i]);
        auto firstp = getNodeCoords( fn.second );
        g->set_coordinate_system(ezgl::WORLD);
        g->set_color(230, 230, 230, 255);
        auto rec = g->get_visible_world();
        //draw dots to indication stations/nodes
        g->fill_arc({ get_x_lon(firstp.lon()) , get_y_lat(firstp.lat())} , rec.width() * 5e-3, 0, 360);
        g->set_color(100, 100, 100, 255);
        g->set_line_width(0);
        g->draw_arc({ get_x_lon(firstp.lon()) , get_y_lat(firstp.lat())} , rec.width() * 5e-3, 0, 360);
            std::string nodeName;

            for(int j = 0; j < getTagCount(fn.second); j++) {
                auto pair = getTagPair(fn.second, j);
                if(pair.first == "name") {
                    nodeName = pair.second;
                    break;
                }
            }

            //draw all the node names
            if(nodeName.size() == 0)
                continue;
            
            if(nnames->find(nodeName) != nnames->end()) {
                continue;
            }
            nnames->insert(std::make_pair(nodeName, 0));
            g->set_color(70, 70, 70, 255);
            g->set_text_rotation(0);
            g->draw_text({ get_x_lon(firstp.lon()) , get_y_lat(firstp.lat()) + rec.width() * 10e-3}, nodeName);
    }

}

//draw clicked station
void draw_clicked_OSMnodes(ezgl::renderer *g) {
    if (!onMap || !(trainEn || subwayEn || tramEn) || (trafficEn && currentIncidents.size() !=0 )) {
        clickedOSMNode.first = false;
        return;
    }
    auto x = worldClickedPoint.first;
    auto y = worldClickedPoint.second;
    auto lat = get_lat_y(y);
    auto lon = get_lon_x(x);
    LatLon clickedPoint(lat, lon);
    //when click on the OSM node, acquire OSM information of this node
    auto closestnodeID = find_closest_OSMnode(x, y);
    auto closestnode = getNodeCoords(OSMID_OSMNodes.find(closestnodeID)->second);
    auto distance = find_distance_between_two_points(std::make_pair(clickedPoint, closestnode));
    if (distance > 20) {
        clickedOSMNode.first = false;
        return;
    }
    clickedOSMNode.second = closestnodeID;
    g->set_coordinate_system(ezgl::WORLD);

    ezgl::point2d png_point(get_x_lon(closestnode.lon()), get_y_lat(closestnode.lat()));
    double ratio_h = g->get_visible_screen().height()/g->get_visible_world().height();
    double ratio_w = g->get_visible_screen().width()/g->get_visible_world().width();
    //same as other node, when clicked, label it with the icon
    ezgl::point2d plot_point(get_x_lon(closestnode.lon())-(20/ratio_w), get_y_lat(closestnode.lat())+(40/ratio_h));
    ezgl::surface *png = g->load_png("libstreetmap/resources/alpha.png");
    g->draw_surface(png, plot_point);
    ezgl::renderer::free_surface(png);
    clickedOSMNode.first = true;
}

//find closest station
OSMID find_closest_OSMnode(double x, double y) {
    double min;
    OSMID closestNode;
    //find the closest stations by x y coordinates, for search bar to display the best 5 results
    for (int i =0; i < currentRelationNodes.size(); i++) {
        //OSM API to get information
        auto inode = getNodeCoords(OSMID_OSMNodes.find(currentRelationNodes[i])->second);
        LatLon curp (get_lat_y(y), get_lon_x(x));
        auto d = find_distance_between_two_points(std::make_pair(inode, curp));
        if(i == 0) {
            min = d;
            closestNode = currentRelationNodes[i];
        }
        else if( min > d) {
             min = d;
            closestNode = currentRelationNodes[i];
        }
    }
    return closestNode;
}

//draw current city weather
void draw_weather(ezgl::renderer *g) {
    if(weatherEn) {
        
        weatherBox = {{g->get_visible_screen().width()-140, 10}, 130, 160};
        g->set_coordinate_system(ezgl::SCREEN);
        g->set_color(245,245,245,170);
        g->fill_rectangle(weatherBox);
        g->set_text_rotation(0);
        //different weather conditions, each has a corresponding PNG 
        if(cWeather.icon == "partly-cloudy-day")
        {    
            ezgl::point2d plot_point(g->get_visible_screen().width()-120, 20);
            ezgl::surface *png = g->load_png("libstreetmap/resources/partly_cloudy.png");
            g->draw_surface(png, plot_point);
            g->free_surface(png);
            
        }
        if(cWeather.icon == "partly-cloudy-night")
        {    
            ezgl::point2d plot_point(g->get_visible_screen().width()-120, 20);
            ezgl::surface *png = g->load_png("libstreetmap/resources/partly_NIGHT.png");
            g->draw_surface(png, plot_point);
            g->free_surface(png);
            
        }
        if(cWeather.icon == "cloudy")
        {    
            ezgl::point2d plot_point(g->get_visible_screen().width()-120, 20);
            ezgl::surface *png = g->load_png("libstreetmap/resources/cloudy.png");
            g->draw_surface(png, plot_point);
            g->free_surface(png);
            
        }
        if(cWeather.icon == "fog")
        {    
            ezgl::point2d plot_point(g->get_visible_screen().width()-120, 20);
            ezgl::surface *png = g->load_png("libstreetmap/resources/fog.png");
            g->draw_surface(png, plot_point);
            g->free_surface(png);
            
        }
        if(cWeather.icon == "wind")
        {    
            ezgl::point2d plot_point(g->get_visible_screen().width()-120, 20);
            ezgl::surface *png = g->load_png("libstreetmap/resources/wind.png");
            g->draw_surface(png, plot_point);
            g->free_surface(png);
            
        }
        if(cWeather.icon == "sleet")
        {    
            ezgl::point2d plot_point(g->get_visible_screen().width()-120, 20);
            ezgl::surface *png = g->load_png("libstreetmap/resources/sleet.png");
            g->draw_surface(png, plot_point);
            g->free_surface(png);
            
        }
        if(cWeather.icon == "snow")
        {    
            ezgl::point2d plot_point(g->get_visible_screen().width()-120, 20);
            ezgl::surface *png = g->load_png("libstreetmap/resources/snow.png");
            g->draw_surface(png, plot_point);
            g->free_surface(png);
            
        }
        if(cWeather.icon == "rain")
        {    
            ezgl::point2d plot_point(g->get_visible_screen().width()-120, 20);
            ezgl::surface *png = g->load_png("libstreetmap/resources/rain.png");
            g->draw_surface(png, plot_point);
            g->free_surface(png);
            
        }
        if(cWeather.icon == "clear-night")
        {    
            ezgl::point2d plot_point(g->get_visible_screen().width()-120, 20);
            ezgl::surface *png = g->load_png("libstreetmap/resources/clear_night.png");
            g->draw_surface(png, plot_point);
            g->free_surface(png);
            
        }
        if(cWeather.icon == "clear-day")
        {    
            ezgl::point2d plot_point(g->get_visible_screen().width()-120, 20);
            ezgl::surface *png = g->load_png("libstreetmap/resources/clear_day.png");
            g->draw_surface(png, plot_point);
            g->free_surface(png);
            
        }
        
        
        
        g->set_font_size(15);
        g->set_color(238,129,102,255);
        g->draw_text({g->get_visible_screen().width()-70, 130}, cWeather.summary);
        
        g->set_font_size(17);
        //temperature information at the bottom of the weather box
        int ctemp = round((cWeather.temperature-32)/1.8);
         g->draw_text({g->get_visible_screen().width()-70, 145}, std::to_string(ctemp ) + "°C");
         g->set_coordinate_system(ezgl::WORLD);
    }
}
//draw current  traffic incidents
void draw_incidents(ezgl::renderer *g) {
    if(trafficEn) {
            double ratio_h = g->get_visible_screen().height()/g->get_visible_world().height();
            double ratio_w = g->get_visible_screen().width()/g->get_visible_world().width();
            //the function declared to find the closest read closure by where the intersection is currently at
            auto closestIn = find_closest_incidents(worldClickedPoint.first, worldClickedPoint.second);
            auto lat = get_lat_y(worldClickedPoint.second);
            auto lon = get_lon_x(worldClickedPoint.first);
            LatLon clickedPoint(lat, lon);
            LatLon closestnode (currentIncidents[closestIn].coor.first, currentIncidents[closestIn].coor.second);
            auto distance = find_distance_between_two_points(std::make_pair(clickedPoint, closestnode));
            if(distance > 15/ratio_w * EARTH_RADIUS_METERS || !onMap) {
                incidentID = -1;
            }
            else {
                incidentID = closestIn;
            }
            g->set_coordinate_system(ezgl::WORLD);
            for(int i = 0; i< currentIncidents.size(); i++) {

                //label the closure node with certain PNG
                ezgl::point2d plot_point(get_x_lon(currentIncidents[i].coor.second)-(15/ratio_w), get_y_lat(currentIncidents[i].coor.first)+(15/ratio_h));
                ezgl::surface *png = g->load_png("libstreetmap/resources/alert.png");
                if( i != incidentID) {
                    g->draw_surface(png, plot_point);
                    
                }
                g->free_surface(png);
            }
            ezgl::surface *png1 = g->load_png("libstreetmap/resources/alert1.png");
            //label the closure node with certain PNG
            ezgl::point2d plot_point1(get_x_lon(currentIncidents[incidentID].coor.second)-(25/ratio_w), get_y_lat(currentIncidents[incidentID].coor.first)+(25/ratio_h));
            g->draw_surface(png1, plot_point1);
            g->free_surface(png1);
        }

}

//find closest traffic incident
int find_closest_incidents(double x, double y) {
    double min;
    int rid;
    //use xy as the center to locate the nearest incident location and get info from OSM database
    for(int i = 0; i< currentIncidents.size(); i++) {
        LatLon curp (get_lat_y(y), get_lon_x(x));
        LatLon cIn (currentIncidents[i].coor.first, currentIncidents[i].coor.second);
        auto d = find_distance_between_two_points(std::make_pair(cIn, curp));
        if(i == 0) {
            min = d;
            rid = i;
        }
        else if( min > d) {
             min = d;
             rid = i;
        }
    }
    return rid;
}



//two layers to show the poi logos 

void draw_poi (ezgl::renderer *g) {

    //only show the poi logos in this range
    if(zoomScale(g) < 7000 ) 
    {
        return;
    }
    double ratio_h = g->get_visible_screen().height()/g->get_visible_world().height();
    double ratio_w = g->get_visible_screen().width()/g->get_visible_world().width();
    g->set_coordinate_system(ezgl::WORLD);
    g->set_text_rotation(0);
    auto world = g->get_visible_world();
    auto xmin = get_lon_x(world.left() );
    auto xmax = get_lon_x(world.right() );
    auto ymin = get_lat_y(world.bottom() );
    auto ymax = get_lat_y(world.top());

    int count = 0;
    //get the positions of poi and load png
    for (int i = 0; i < getNumPointsOfInterest(); i++) {
        if(count > 40) {
            break;
        }
        auto poicoor = getPointOfInterestPosition(i);
        if( poicoor.lat() < ymin || poicoor.lat() > ymax || poicoor.lon() < xmin || poicoor.lon() > xmax) {
            continue;
        }
        //put each icon on the designated location, small window and large window's ratio calculated
        ezgl::point2d plot_point(get_x_lon(poicoor.lon())-(10/ratio_w), get_y_lat(poicoor.lat())+(10/ratio_h));
        ezgl::surface *png = g->load_png("libstreetmap/resources/place2.png");
        if(getPointOfInterestType(i)=="university" || getPointOfInterestType(i)=="school") {
            png = g->load_png("libstreetmap/resources/university2.png");
        }
        if(getPointOfInterestType(i)=="theatre") {
            png = g->load_png("libstreetmap/resources/theater2.png");
        }
        if(getPointOfInterestType(i)=="pharmacy") {
            png = g->load_png("libstreetmap/resources/pharmacy2.png");
        }
        if(getPointOfInterestType(i)=="cafe") {
            png = g->load_png("libstreetmap/resources/cafe2.png");
        }
        if(getPointOfInterestType(i)=="atm") {
            png = g->load_png("libstreetmap/resources/atm2.png");
        }
        if(getPointOfInterestType(i)=="bank") {
            png = g->load_png("libstreetmap/resources/bank2.png");
        }
        if(getPointOfInterestType(i)=="dentist") {
            png = g->load_png("libstreetmap/resources/dentist2.png");
        }
        if(getPointOfInterestType(i)=="embassy") {
            png = g->load_png("libstreetmap/resources/embassy2.png");
        }
        if(getPointOfInterestType(i)=="hospital") {
            png = g->load_png("libstreetmap/resources/hospital2.png");
        }
        if(getPointOfInterestType(i)=="pub") {
            png = g->load_png("libstreetmap/resources/pub2.png");
        }
        if(getPointOfInterestType(i)=="restaurant") {
            png = g->load_png("libstreetmap/resources/restuarant2.png");
        }
        if(getPointOfInterestType(i)=="library") {
            png = g->load_png("libstreetmap/resources/book2.png");
        }
        if(getPointOfInterestType(i)=="fast_food") {
            png = g->load_png("libstreetmap/resources/burger2.png");
        }


        g->draw_surface(png, plot_point);
        g->set_color(getColour("#636363"));
        g->set_font_size(12);
        g->free_surface(png);
        count ++;
        //when zooming in to this level, the names of poi would be shown on the map
        if(zoomScale(g) > 40000) {
            g->draw_text({get_x_lon(poicoor.lon()), get_y_lat(poicoor.lat())+(18/ratio_h)}, getPointOfInterestName(i));
        }
    }
}

//find closest poi
int find_closest_POI(double x, double y) {
    double minDistance;
    int minIn =shownPOIs[0];
    // same as finding closest closure, intersection, use coordinate to find the closest POI
    for (int i=0; i< shownPOIs.size(); i++){
            auto clon = get_lon_x(x);
            auto clat = get_lat_y(y);
            LatLon myp (clat, clon);
            if( i == 0) {
                minDistance = find_distance_between_two_points(std::make_pair(getPointOfInterestPosition(shownPOIs[i]), myp));
                minIn = shownPOIs[i];
            }
            else if (minDistance > find_distance_between_two_points(std::make_pair(getPointOfInterestPosition(shownPOIs[i]), myp))){
                minDistance = find_distance_between_two_points(std::make_pair(getPointOfInterestPosition(shownPOIs[i]), myp));
                minIn = shownPOIs[i];
            }
     }
    return minIn;
}
//draw clicked poi
void draw_clicked_POI(ezgl::renderer *g) {
    if( ! onMap || POI < 0) {
        clickedPOI = -1;
        return;
    }
    //if clicked on a POI, it will be labeled with same icon as intersection
    auto x = worldClickedPoint.first;
    auto y = worldClickedPoint.second;
    auto lat = get_lat_y(y);
    auto lon = get_lon_x(x);
    LatLon clickedPoint(lat, lon);
    int cpoi = find_closest_POI(x, y);
    double ratio_h = g->get_visible_screen().height()/g->get_visible_world().height();
    double ratio_w = g->get_visible_screen().width()/g->get_visible_world().width();

    if( find_distance_between_two_points(std::make_pair(  clickedPoint, getPointOfInterestPosition(cpoi))) > 15/ratio_w * EARTH_RADIUS_METERS) {
        clickedPOI = -1 + 1 -1 ;
        return;
    }

    clickedPOI = cpoi;
    //label with the PNG
    ezgl::point2d plot_point(get_x_lon(getPointOfInterestPosition(cpoi).lon())-(20/ratio_w) , get_y_lat(getPointOfInterestPosition(cpoi).lat())+(40/ratio_h));
    ezgl::surface *png = g->load_png("libstreetmap/resources/alpha.png");
    g->draw_surface(png, plot_point);
    g->free_surface(png);

}

void draw_path(ezgl::renderer *g) {

    if(preinterID == -1 || interID == -1)
        return;
    cpath = find_path_between_intersections(preinterID, interID, 15);
    for(int i = 0; i <cpath.size(); i++) {
            draw_one_segments(g, cpath[i], "path"); 
    }
}

void draw_reachable_inters(ezgl::renderer *g) {
    if(interID == -1) {
        return;
    }
    std::vector<int> interr(getNumIntersections(), -1);
    std::vector<int> intersw;
    find_inters_walklimit(interID, 15, 1.25, 300, &interr, &intersw);
    std::vector< std::vector<int> > interspath;

    for(int i = 0; i < intersw.size(); i ++) {
        auto cpath = back_trace(intersw[i], interr);
        // interspath.push_back(cpath);
        for(int j = 0; j <cpath.size(); j++) {
            draw_one_segments(g, cpath[j], "path"); 
        }

    }
}

void draw_route_searchBars(ezgl::renderer *g) {
    if(routeMode == false)
        return;
    //search bars that are prepared for path finding, two of them, not supporting typing in, information directed from the previous search bar
    g->set_coordinate_system(ezgl::SCREEN);    
    auto screenRec = g->get_visible_screen();
    double midX = (screenRec.left() + screenRec.right())/2;
    g->set_color(196, 160, 220);
    if(screenRec.area() <500000)
    {
        route_background = {{20, 60}, 740, 120};
    }
    
    else
    {
        route_background = {{midX - 370, 20}, 740, 120};

    }

    if(route_background.left() <= searchBar.right() + 10) {
        route_background = {{midX - 370, 60}, 740, 120};
    }

    // g->fill_rectangle(route_background);
    //we used png to improve quality of display instead of EZGL rectangle
    ezgl::surface *bpng = g->load_png("libstreetmap/resources/shadow.png");
    g->draw_surface(bpng, {route_background.left() - 5, route_background.bottom() - 5});
    g->free_surface(bpng);

    searchBar1 = {{midX - 340, route_background.bottom() + 20}, 600, 30};
    searchBar2 = {{midX - 340, route_background.top() - 50}, 600, 30};

    ezgl::surface *fpng = g->load_png("libstreetmap/resources/SW.png");
    ezgl::surface *spng = g->load_png("libstreetmap/resources/SW.png");
    //indicate when the searched is clicked, for you to know whether you are selecting begin or end point
    if(firstBarA || searchBar1M) {
        g->free_surface(fpng);
        fpng = g->load_png("libstreetmap/resources/SC.png");
    }

    if(secondBarA || searchBar2M)  {
        g->free_surface(spng);
        spng = g->load_png("libstreetmap/resources/SC.png");
    }


    g->draw_surface(fpng, searchBar1.bottom_left());
    g->free_surface(fpng);


    g->draw_surface(spng, searchBar2.bottom_left());
    g->free_surface(spng);


    g->set_coordinate_system (ezgl::WORLD);
}
//the beginning and ending point of the path
void draw_path_inters(ezgl::renderer *g) {
    g->set_coordinate_system (ezgl::WORLD);
    if(!routeMode) {
        secondinter = -1;
        firstinter = -1;
    }
    if(firstBarA && interID != -1) {
        firstinter = interID;
    }
    else if(secondBarA && interID != -1  && firstinter != -1) {
        
            secondinter = interID;
    }

    if(firstBarA && clickedFoundInter >=0 && (searchBI == 0 )) {
        firstinter = clickedFoundInter;
    }
    else if(secondBarA && clickedFoundInter >=0 && (searchBI == 0) ) {
        if(firstinter != clickedFoundInter)
            secondinter = clickedFoundInter;
    }

    if(firstBarA && clickedFoundInter >=0 && (searchBI == 1 )) {
        firstinter =  find_closest_intersection( getPointOfInterestPosition(clickedFoundInter) );
    }
    else if(secondBarA && clickedFoundInter >=0 && (searchBI == 1) ) {
        if(firstinter != clickedFoundInter)
            secondinter = find_closest_intersection( getPointOfInterestPosition(clickedFoundInter) );
    }
    //when the first intersection exits, label it with an icon with 1 on it to show the path starts here
    if(firstinter != -1) {
        auto firstP = getIntersectionPosition(firstinter);
        g->set_coordinate_system(ezgl::WORLD);
        ezgl::point2d png_point(get_x_lon(firstP.lon()), get_y_lat(firstP.lat()));
        double ratio_h = g->get_visible_screen().height()/g->get_visible_world().height();
        double ratio_w = g->get_visible_screen().width()/g->get_visible_world().width();
        ezgl::point2d plot_point(get_x_lon(firstP.lon())-(20/ratio_w), get_y_lat(firstP.lat())+(40/ratio_h));
        ezgl::surface *png = g->load_png("libstreetmap/resources/start.png");
        g->draw_surface(png, plot_point);
        g->free_surface(png);
    }
    //when the second intersection exits, label it with an icon with 2 on it to show the path ends here
    if(secondinter != -1) {
        auto secondP = getIntersectionPosition(secondinter);
        g->set_coordinate_system(ezgl::WORLD);
        ezgl::point2d png_point(get_x_lon(secondP.lon()), get_y_lat(secondP.lat()));
        double ratio_h = g->get_visible_screen().height()/g->get_visible_world().height();
        double ratio_w = g->get_visible_screen().width()/g->get_visible_world().width();
        ezgl::point2d plot_point(get_x_lon(secondP.lon())-(20/ratio_w), get_y_lat(secondP.lat())+(40/ratio_h));
        ezgl::surface *png = g->load_png("libstreetmap/resources/end.png");
        g->draw_surface(png, plot_point);
        g->free_surface(png);
    }

}

void draw_path_inters_text(ezgl::renderer *g) {
    if(!routeMode) {
        return;
    }
    //when there is an intersection for the search bar, get name from API, will be used for displaying on the search bar
    if(firstinter != -1) {
        searchText1 = getIntersectionName(firstinter);
    }    
    else
    
    {
        searchText1.clear();
    }

    if(secondinter != -1) {
        //same as above
        searchText2 = getIntersectionName(secondinter);
    }       
    else
    {
        searchText2.clear();
    }

    if(help)
        return;
    
    g->set_coordinate_system (ezgl::SCREEN);
    g->set_color(100, 100, 100, 255);
    //locate the center of the search bar, to display the name of this intersection selected
    ezgl::point2d a( (searchBar1.left() + searchBar1.right() )/2, (searchBar1.top() + searchBar1.bottom()) / 2);
    ezgl::point2d b( (searchBar2.left() + searchBar2.right() )/2, (searchBar2.top() + searchBar2.bottom()) / 2);

    g->set_text_rotation(0);
    g->set_font_size(15);
    
    g->draw_text(a, searchText1);
    g->draw_text(b, searchText2);

    g->set_coordinate_system (ezgl::WORLD);
}
//draw the path from M3 functions
void draw_spath(ezgl::renderer *g) {
    if(routeMode && firstinter != -1 && secondinter != -1 && drivingA && (firstinter != secondinter)) {
        int midp;
        //a lock to prevent the map from repeatedly calculating the same path, slow down the program
        if(last_intersection_1 != firstinter || last_intersection_2 != secondinter)
        {
            cpath = find_path_between_intersections(firstinter, secondinter, 15);
        }
        if(cpath.size() == 0)
            return;
        //find the location of the middle of the path, ready for a window to display related info, distance, travel time
        for(int i = 0; i <cpath.size(); i++) {
            draw_one_segments(g, cpath[i], "path"); 
            if(i == int(cpath.size() / 2) )
                midp = getInfoStreetSegment(cpath[i]).from;
        }
        auto midpp = getIntersectionPosition(midp);

        if(cpath.size() == 1) {
            //if it's only a line, just draw the window in the middle of this segment
            auto fromp = getIntersectionPosition(getInfoStreetSegment(cpath[0]).from);
            auto top = getIntersectionPosition(getInfoStreetSegment(cpath[0]).to);
            LatLon tempp ( (fromp.lat() + top.lat())/2,  (fromp.lon() + top.lon())/2);
            midpp = tempp;
        }

        double ratio_h = g->get_visible_screen().height()/g->get_visible_world().height();
        double ratio_w = g->get_visible_screen().width()/g->get_visible_world().width();
        ezgl::point2d plot_point(get_x_lon(midpp.lon())-(40/ratio_w), get_y_lat(midpp.lat())+(68/ratio_h));
        ezgl::surface *png = g->load_png("libstreetmap/resources/diabox80.png");
        g->draw_surface(png, plot_point);
        g->free_surface(png);

        auto totalT = int(compute_path_travel_time(cpath, 15));
        auto totalD = int(compute_path_distance(cpath));
        //draw infomation for the box, that helps display the details of this path
        g->set_font_size(15);
        g->set_color(0,50,50,255);
        g->set_text_rotation(0);
        g->draw_text({plot_point.x + (40/ratio_w), plot_point.y - 40/ratio_h},  lengthDisplay(totalD));

        g->draw_text({plot_point.x + (40/ratio_w), plot_point.y - 20/ratio_h},  timeDisplay(totalT));
        //synchronize the lock above, keep it locked when there is no need for new path
        last_intersection_1 = firstinter;
        last_intersection_2 = secondinter;
        // std::cout<< std::to_string(totalD ) + "m" << "\n";
    }
    //if the user choose to walk
    if(routeMode && firstinter != -1 && secondinter != -1 && walkingA && (firstinter != secondinter)) {
        int midp;
        //cpath = a_star(firstinter, secondinter, 15, true, walkingSpeed);
        //lock down the path finding algorithm
        if(walk_intersection_1 != firstinter || walk_intersection_2 != secondinter)
        {
            wpath = a_star(firstinter, secondinter, 15, true, walkingSpeed);
        }
        if(wpath.size() == 0) {
            return;
        }
        //find the location of the middle of the path, ready for a window to display related info, distance, travel time
        for(int i = 0; i <wpath.size(); i++) {
            draw_one_segments(g, wpath[i], "pathf"); 
            if(i == int(wpath.size() / 2) )
                midp = getInfoStreetSegment(wpath[i]).from;
        }
        auto midpp = getIntersectionPosition(midp);

        if(wpath.size() == 1) {
            //if it's only a line, just draw the window in the middle of this segment
            auto fromp = getIntersectionPosition(getInfoStreetSegment(wpath[0]).from);
            auto top = getIntersectionPosition(getInfoStreetSegment(wpath[0]).to);
            LatLon tempp ( (fromp.lat() + top.lat())/2,  (fromp.lon() + top.lon())/2);
            midpp = tempp;
        }

        double ratio_h = g->get_visible_screen().height()/g->get_visible_world().height();
        double ratio_w = g->get_visible_screen().width()/g->get_visible_world().width();
        ezgl::point2d plot_point(get_x_lon(midpp.lon())-(40/ratio_w), get_y_lat(midpp.lat())+(68/ratio_h));
        ezgl::surface *png = g->load_png("libstreetmap/resources/diabox80.png");
        //draw the window png for better quality
        g->draw_surface(png, plot_point);
        g->free_surface(png);

        auto totalT = int(compute_path_walking_time(wpath, walkingSpeed, 15));
        auto totalD = int(compute_path_distance(wpath));

        g->set_font_size(15);
        g->set_color(0,50,50,255);
        g->set_text_rotation(0);
        g->draw_text({plot_point.x + (40/ratio_w), plot_point.y - 40/ratio_h},  lengthDisplay(totalD));

        g->draw_text({plot_point.x + (40/ratio_w), plot_point.y - 20/ratio_h},  timeDisplay(totalT));
        //synchronize the lock above, keep it locked when there is no need for new path
        walk_intersection_1 = firstinter;
        walk_intersection_2= secondinter;
    }

    if(routeMode && firstinter != -1 && secondinter != -1 && wplusdA && (firstinter != secondinter))  {
        if(astar_intersection_1 != firstinter || astar_intersection_2 != secondinter)
            wplusdpaths = find_path_with_walk_to_pick_up(firstinter, secondinter, 15, walkingSpeed, walkingTimeLimit);
        auto walkingpath = wplusdpaths.first;
        auto drivingpath = wplusdpaths.second;
        if(walkingpath.size()==0 && drivingpath.size() == 0) {
            return;
        }
        int midp;

        double totalT;
        double totalD;

        std::vector<int> wopath;

        int pathmid = ( walkingpath.size() + drivingpath.size() ) / 2;
        //finding the middle point of this path for window
        if( !(walkingpath.size() == 1 && walkingpath[0] == -1) ) {
            for(int i = 0; i <walkingpath.size(); i++) {
                draw_one_segments(g, walkingpath[i], "pathf");
                if(i == pathmid)
                    midp = getInfoStreetSegment(walkingpath[i]).from;
            }

            for(int i = 0; i <drivingpath.size(); i++) {
                draw_one_segments(g, drivingpath[i], "path");
                if(i == pathmid - walkingpath.size())
                    midp = getInfoStreetSegment(drivingpath[i]).from;
            }

            totalT = compute_path_travel_time(drivingpath, 15) + compute_path_walking_time(walkingpath, walkingSpeed, 15);
            totalD = compute_path_distance(drivingpath) + compute_path_distance(walkingpath);
        }

        else {
            // get the second half of this path, for driving and seperate with the walking path
            wopath = a_star(firstinter, secondinter, 15, true, walkingSpeed);
            for(int i = 0; i <wopath.size(); i++) {
                draw_one_segments(g, wopath[i], "pathf");
                if(i == int (wopath.size() / 2 ))
                    midp = getInfoStreetSegment(wopath[i]).from;
            }

            totalD = compute_path_distance(wopath);
            totalT = compute_path_walking_time(wopath, walkingSpeed, 15)   ;
        }


        auto midpp = getIntersectionPosition(midp);

        if(wopath.size() == 1) {
            //if the path is only a segment, locate the window in the middle of the segment
            auto fromp = getIntersectionPosition(getInfoStreetSegment(wopath[0]).from);
            auto top = getIntersectionPosition(getInfoStreetSegment(wopath[0]).to);
            LatLon tempp ( (fromp.lat() + top.lat())/2,  (fromp.lon() + top.lon())/2);
            midpp = tempp;
        }

        double ratio_h = g->get_visible_screen().height()/g->get_visible_world().height();
        double ratio_w = g->get_visible_screen().width()/g->get_visible_world().width();
        ezgl::point2d plot_point(get_x_lon(midpp.lon())-(40/ratio_w), get_y_lat(midpp.lat())+(68/ratio_h));
        ezgl::surface *png = g->load_png("libstreetmap/resources/diabox80.png");
        g->draw_surface(png, plot_point);
        g->free_surface(png);

        //information displayed in the window, details of this path
        g->set_font_size(15);
        g->set_color(0,50,50,255);
        g->set_text_rotation(0);
        g->draw_text({plot_point.x + (40/ratio_w), plot_point.y - 40/ratio_h},  lengthDisplay(totalD));

        g->draw_text({plot_point.x + (40/ratio_w), plot_point.y - 20/ratio_h},  timeDisplay(totalT));

        astar_intersection_1 = firstinter;
        astar_intersection_2= secondinter;

    }
}



void draw_route_options(ezgl::renderer *g) {
    if(!routeMode) {
        return;
    }

    g->set_coordinate_system (ezgl::SCREEN);
    //initialize all the buttons, options for each path, walking/driving, swap two intersections, help, display detailed instructions of navigation
    drivingB = {{searchBar1.right() + 47, route_background.bottom() + 15}, 27, 27};
    walkingB = {{searchBar1.right() + 47, route_background.bottom() + 15 + 33}, 27, 27};
    wplusdB = {{searchBar1.right() + 47, route_background.bottom() + 15 + 33+ 33}, 27, 27};
    swapB = {{searchBar1.right() + 9, ( route_background.top() + route_background.bottom() )/ 2 - 18}, 36, 36};
    routeCloseB = { {drivingB.right() + 15, drivingB.bottom() - 8}, 16, 16};
    routehelpB = { {drivingB.right() + 15, wplusdB.top() - 8}, 18, 18};
    routesetB = { {drivingB.right() + 15, walkingB.bottom() + 6}, 17, 17};
//    exchangeB = {{searchBar1.left() - 50, 50}, 30, 30};
    exchangeB = 36;
    routeSettingBack = {{route_background.right() + 30 - 5, route_background.bottom() - 5}, 300, 120};
    ssearchBar1 = {{routeSettingBack.center_x() - 120, routeSettingBack.bottom() + 25 }, 260, 30};
    ssearchBar2 = {{routeSettingBack.center_x() - 120, routeSettingBack.top() - 40 }, 260, 30};


    if(drivingA) {
        //when activated, highlight with a different color
        g->set_color(193,130,180, 255);
        // g->fill_rectangle(drivingB);
        g->fill_arc(drivingB.center(), 19, 0, 360);
    }


    if(walkingA) {
        //when activated, highlight with a different color
        g->set_color(193,130,180, 255);
        // g->fill_rectangle(walkingB);
        g->fill_arc(walkingB.center(), 19, 0, 360);
    }


    if(wplusdA) {
        //when activated, highlight with a different color
        g->set_color(193,130,180, 255);
        g->fill_arc(wplusdB.center(), 19, 0, 360);
    }
        
    // prepared pngs for each button for better visualizing quality
    ezgl::surface *dpng = g->load_png("libstreetmap/resources/car.png");
    g->draw_surface(dpng, drivingB.bottom_left());
    g->free_surface(dpng);

    ezgl::surface *wpng = g->load_png("libstreetmap/resources/walk.png");
    g->draw_surface(wpng, walkingB.bottom_left());
    g->free_surface(wpng);

    ezgl::surface *ppng = g->load_png("libstreetmap/resources/taxi.png");
    g->draw_surface(ppng, wplusdB.bottom_left());
    g->free_surface(ppng);

    ezgl::surface *cpng = g->load_png("libstreetmap/resources/close.png");
    g->draw_surface(cpng, routeCloseB.bottom_left());
    g->free_surface(cpng);

    ezgl::surface *hpng = g->load_png("libstreetmap/resources/question.png");
    g->draw_surface(hpng, routehelpB.bottom_left());
    g->free_surface(hpng);

    ezgl::surface *sepng = g->load_png("libstreetmap/resources/settings.png");
    g->draw_surface(sepng, routesetB.bottom_left());
    g->free_surface(sepng);


    ezgl::surface *spng = g->load_png("libstreetmap/resources/sort.png");
    g->draw_surface(spng, swapB.bottom_left());
    g->free_surface(spng);

    if(routeSetting) {
        //the setting of walking speed and time limit, each info bar is a png, load them here
        spng = g->load_png("libstreetmap/resources/sblock.png");
        g->draw_surface(spng, routeSettingBack.bottom_left());
        g->free_surface(spng);

        spng = g->load_png("libstreetmap/resources/ssbw.png");
        g->draw_surface(spng, ssearchBar1.bottom_left());
        g->free_surface(spng);

        spng = g->load_png("libstreetmap/resources/ssbw.png");
        g->draw_surface(spng, ssearchBar2.bottom_left());
        g->free_surface(spng);

        if(ssearchBar1A) {
            //highlighter png, to match the shape of the bar
            spng = g->load_png("libstreetmap/resources/ssbc.png");
            g->draw_surface(spng, ssearchBar1.bottom_left());
            g->free_surface(spng);
        }

        if(ssearchBar2A) {
            //highlighter png, to match the shape of the bar
            spng = g->load_png("libstreetmap/resources/ssbc.png");
            g->draw_surface(spng, ssearchBar2.bottom_left());
            g->free_surface(spng);
        }

        stringstream ss;
        ss.setf(ios::fixed);
        ss.precision(2);
        ss << walkingSpeed ;

        string l = ss.str().c_str();

        g->set_text_rotation(0);
        g->set_font_size(15);
        g->set_color(0,50,50,255);
        g->draw_text(ssearchBar1.center(), "Walking Speed: " + l + " m/s");
        g->draw_text(ssearchBar2.center(), "Walking Time Limit: " + to_string(int(walkingTimeLimit))  + " s");
    }
    
    if (help) { 
        ezgl::surface *toppng = g->load_png("libstreetmap/resources/tstart.png");
        ezgl::point2d start_point(searchBar1.bottom_left().x , (searchBar1.bottom_left().y)+4);
        g->draw_surface(toppng, start_point);
        g->free_surface(toppng);
        
        ezgl::point2d left_point(searchBar2.bottom_left().x , (searchBar2.bottom_left().y)+4);
        ezgl::surface *botpng = g->load_png("libstreetmap/resources/tdesti.png");
        g->draw_surface(botpng, left_point);
        g->free_surface(botpng);
        
        ezgl::point2d top_point((swapB.top_left().x ) - 150, (searchBar1.top_left().y) + 75);
        ezgl::surface *arrpng = g->load_png("libstreetmap/resources/tarro.png");
        g->draw_surface(arrpng, top_point);
        g->free_surface(arrpng);
        
        ezgl::point2d tr_point((routeCloseB.top_right().x ) + 15, (routeCloseB.bottom_right().y)+6);
        ezgl::surface *dripng = g->load_png("libstreetmap/resources/tdri.png");
        g->draw_surface(dripng, tr_point);
        g->free_surface(dripng);
        
        ezgl::point2d mr_point((routesetB.top_right().x ) + 15, (routesetB.bottom_right().y)-8);
        ezgl::surface *walpng = g->load_png("libstreetmap/resources/twal.png");
        g->draw_surface(walpng, mr_point);
        g->free_surface(walpng);
        
        ezgl::point2d br_point((routehelpB.top_right().x ) + 15, (routehelpB.bottom_right().y)-20);
        ezgl::surface *pickpng = g->load_png("libstreetmap/resources/tpickup.png");
        g->draw_surface(pickpng, br_point);
        g->free_surface(pickpng);
        
        ezgl::point2d nv_point((routeMenuB.top_left().x ) - 100, (routeMenuB.top_right().y)+5);
        ezgl::surface *navpng = g->load_png("libstreetmap/resources/tnavi.png");
        g->draw_surface(navpng, nv_point);
        g->free_surface(navpng);
    }
        
    
    g->set_coordinate_system (ezgl::WORLD);
}


string lengthDisplay(double m) {
    stringstream ss;
    ss.setf(ios::fixed);
    ss.precision(1);
    //calculate the length of the path and change into string using std function
    ss << double(int(m / 100)) / 10 ;
    string l = ss.str().c_str();
    if(m < 1000)
        return std::to_string( int(m))  + "m";
    else {
        return   l + "km";
    }
}

string timeDisplay(double t) {
    int min = t / 60 ;
    int hour = min / 60;
    int day = hour / 24;

    if(hour == 0) {
        if( min == 1) 
            return to_string(min) + "min";
        return to_string(min) + "mins";
    }

    if(day == 0) {
        if( min % 60 == 1)
            return to_string(hour) + "h" + to_string(min % 60) + "min";
        return to_string(hour) + "h" + to_string(min % 60) + "mins";
    }

    if( min % 60 == 1)
        return to_string(day) + "d" + to_string(hour % 24) + "h" + to_string(min % 60) + "min";
    return to_string(day) + "d" + to_string(hour % 24) + "h" + to_string(min % 60) + "mins";

        

}

void navigation_text(ezgl::renderer *g) {

    navigationPoints.clear();
    if(firstinter == -1 && secondinter == -1) {
        return;
    }
    //when one of the path finding option is turned on
    if( (drivingA || walkingA || (wplusdA && (wplusdpaths.first.size() == 1 && wplusdpaths.first[0] == -1))) && firstinter != -1 && secondinter != -1) {

        auto ccpath = cpath;
        if(walkingA) {
            ccpath = wpath;
        }
        if(wplusdA) {
            ccpath = a_star(firstinter, secondinter, 15, true, walkingSpeed);
        }
        //create a vector of string to store all instructions of navigation, so users can turn to previous step, even to the beginning point
        std::vector<std::string> navigation;
        std::vector<int> streetIDs(ccpath.size());
        std::string beginning = "You are starting at ";
        beginning += searchText1;
        navigation.push_back(beginning);

        navigationPoints.push_back(firstinter);
        //separately store all street IDs, easier to check whether there is a turn
        for(int i = 0; i<ccpath.size(); i++)
        {
            streetIDs[i] = getInfoStreetSegment(ccpath[i]).streetID;
        }

        int prepath = 0;
        int nowpath = 0;
        //go through all the segments in the path to load instructions into the string vector
        for(int i = 1; i < streetIDs.size(); i ++) {
                if(streetIDs[i] != streetIDs[i - 1]) {
                    nowpath = i;
                    int re = leftOrRight(ccpath[i - 1], ccpath[i], g);
                    std::vector<int> mpath(ccpath.begin() + prepath, ccpath.begin() + nowpath);
                    auto ctime = compute_path_distance(mpath);
                    auto stime = lengthDisplay(ctime);
                    prepath = nowpath;
                    //information to index under each condition
                    if (re == 1)
                    {
                        std::string displaytext = "Turn left onto " + getStreetName(streetIDs[i]) + " after " + stime;
                        navigation.push_back(displaytext);

                    }
                    else if(re == 0){
                        std::string displaytext = "Turn right onto " + getStreetName(streetIDs[i])  + " after " + stime;
                        navigation.push_back(displaytext);
                    }
                    else if(re == -1){
                        std::string displaytext = "Go straight onto " + getStreetName(streetIDs[i])  + " after " + stime;
                        navigation.push_back(displaytext);
                    }
                    //push back the street segment name of each seg on the path
                    navigationPoints.push_back(midInter(ccpath[i - 1], ccpath[i]));
                    
                }
        }


        navigation.push_back("You have arrived at " + searchText2 );
        // for(int i = 0; i < navigation.size(); i ++) {
        //     std::cout << navigation[i] << "\n";
        // }
        //load the ending point
        navigationPoints.push_back(secondinter);
        navigationInstructions = navigation;
        //if there is a change from driving to walking, a "change" will be inserted
        changeContain = false;
    }

    //repeat the last process, when a different option is clicked
    else if( wplusdA && firstinter != -1 && secondinter != -1) {
        if((firstinter == secondinter) || (wplusdpaths.first.size() ==0 && wplusdpaths.second.size() == 0)) {
            navigationInstructions.clear();
            return;
        }
        std::vector<std::string> navigation;
        std::vector<int> streetIDs(wplusdpaths.first.size() + wplusdpaths.second.size());
        for(int i = 0; i<wplusdpaths.first.size(); i++)
        {
            streetIDs[i] = getInfoStreetSegment(wplusdpaths.first[i]).streetID;
        }
        for(int i = 0; i<wplusdpaths.second.size(); i++)
        {
            streetIDs[i + wplusdpaths.first.size()] = getInfoStreetSegment(wplusdpaths.second[i]).streetID;
        }
        // insert the beginning
        std::string beginning = "You are starting at ";
        beginning += searchText1;
        navigation.push_back(beginning);
        navigationPoints.push_back(firstinter);

        int prepath = 0;
        int nowpath = 0;
    //go through all the segments in the path to load instructions into the string vector
        for(int i = 1; i < wplusdpaths.first.size(); i ++) {
                if(streetIDs[i] != streetIDs[i - 1]) {
                    int re = leftOrRight(wplusdpaths.first[i - 1], wplusdpaths.first[i], g);

                    nowpath = i;
                    std::vector<int> mpath(wplusdpaths.first.begin() + prepath, wplusdpaths.first.begin() + nowpath);
                    auto ctime = compute_path_distance(mpath);
                    auto stime = lengthDisplay(ctime);
                    prepath = nowpath;
                    //information to index under each condition
                    if (re == 1)
                    {
                        std::string displaytext = "Turn left onto " + getStreetName(streetIDs[i]) + " after " + stime;
                        navigation.push_back(displaytext);
                    }
                    else if(re == 0){
                        std::string displaytext = "Turn right onto " + getStreetName(streetIDs[i]) + " after " + stime;
                        navigation.push_back(displaytext);
                    }
                    else if(re == -1){
                        std::string displaytext = "Go straight onto " + getStreetName(streetIDs[i]) + " after " + stime;
                        navigation.push_back(displaytext);
                    }
                    navigationPoints.push_back(midInter(wplusdpaths.first[i - 1], wplusdpaths.first[i]));
                    
                }
        }

        if(getInfoStreetSegment(wplusdpaths.first[wplusdpaths.first.size() - 1]).from == getInfoStreetSegment(wplusdpaths.first[wplusdpaths.first.size() - 1]).from ||
            getInfoStreetSegment(wplusdpaths.first[wplusdpaths.first.size() - 1]).from == getInfoStreetSegment(wplusdpaths.second[0]).to) {
                std::string displaytext = "Your pick up intersection is " + getIntersectionName( getInfoStreetSegment(wplusdpaths.first[wplusdpaths.first.size() - 1]).from);
                navigation.push_back(displaytext);
            }
        else {
            std::string displaytext = "Your pick up intersection is " + getIntersectionName( getInfoStreetSegment(wplusdpaths.first[wplusdpaths.first.size() - 1]).to);
            navigation.push_back(displaytext);
        }

        navigationPoints.push_back(midInter( wplusdpaths.first[wplusdpaths.first.size() - 1], wplusdpaths.second[0] ) );
        



        prepath = 0;
        nowpath = 0;
        //the second part of the path, for driving
        for(int i = 1; i < wplusdpaths.second.size(); i ++) {
                if(streetIDs[i + wplusdpaths.first.size()] != streetIDs[i - 1 + wplusdpaths.first.size()]) {
                    int re = leftOrRight(wplusdpaths.second[i - 1], wplusdpaths.second[i], g);

                    nowpath = i;
                    //new vector to conbine two parts of the path
                    std::vector<int> mpath(wplusdpaths.second.begin() + prepath, wplusdpaths.second.begin() + nowpath);
                    auto ctime = compute_path_distance(mpath);
                    auto stime = lengthDisplay(ctime);
                    prepath = nowpath;
                    //repeat the navigation process
                    if (re == 1)
                    {
                        std::string displaytext = "Turn left onto " + getStreetName( streetIDs[i + wplusdpaths.first.size()] ) + " after " + stime;
                        navigation.push_back(displaytext);
                    }
                    else if(re == 0){
                        std::string displaytext = "Turn right onto " + getStreetName( streetIDs[i + wplusdpaths.first.size()] ) + " after " + stime;
                        navigation.push_back(displaytext);
                    }
                    else if(re == -1){
                        std::string displaytext = "Go straight onto " + getStreetName( streetIDs[i + wplusdpaths.first.size()] ) + " after " + stime;
                        navigation.push_back(displaytext);
                    }
                    navigationPoints.push_back(midInter(wplusdpaths.second[i - 1], wplusdpaths.second[i]));
                    
                }
        }

        navigation.push_back("You have arrived at " + searchText2 );
        // for(int i = 0; i < navigation.size(); i ++) {
        //     std::cout << navigation[i] << "\n";
        // }
        navigationPoints.push_back(secondinter);
        navigationInstructions = navigation;
    }

    else {
        navigationInstructions.clear();
        //the counter is reset after the path finding is turned off
        naviCount = 0;
    }

}


//check if the change of street id is a right or left turn
int leftOrRight (int segment1, int segment2, ezgl::renderer *g) {

    InfoStreetSegment firstSeg= getInfoStreetSegment(segment1);
    InfoStreetSegment SecondSeg = getInfoStreetSegment(segment2);
    //seg 1 is where it's from, seg 2 is destination
    bool firstReverse, secondReverse;
    if(firstSeg.from == SecondSeg.to || firstSeg.from == SecondSeg.from) {
        firstReverse = true;
    }
    else {
        firstReverse = false;
    }
    
    if(SecondSeg.from == firstSeg.to || SecondSeg.from == firstSeg.from) {
        secondReverse = false;
    }
    else {
        secondReverse = true;
    }
    //check if driving through either of them is a reverse of "from" to "to" intersection
    std::vector<LatLon> totalPoints;
    //if one seg is reversed, picking the first curve point and from as a line
    if(firstReverse) {
        totalPoints.push_back(getIntersectionPosition(firstSeg.to));

        for( int i = firstSeg.curvePointCount - 1; i > -1; i --) {
            totalPoints.push_back(getStreetSegmentCurvePoint(i, segment1));
        }
        totalPoints.push_back(getIntersectionPosition(firstSeg.from));
    }
    //otherwise, pick last curve point and to
    else {
        totalPoints.push_back(getIntersectionPosition(firstSeg.from));

        for( int i = 0; i < firstSeg.curvePointCount ; i ++) {
            totalPoints.push_back(getStreetSegmentCurvePoint(i, segment1));
        }

        totalPoints.push_back(getIntersectionPosition(firstSeg.to));
    }

    int pID = totalPoints.size() - 1;
    //same as the first segment
    if(secondReverse) {

        for( int i = SecondSeg.curvePointCount - 1; i > -1; i --) {
            totalPoints.push_back(getStreetSegmentCurvePoint(i, segment2));
        }
        totalPoints.push_back(getIntersectionPosition(SecondSeg.from));
    }
    else {

        for( int i = 0; i < SecondSeg.curvePointCount ; i ++) {
            totalPoints.push_back(getStreetSegmentCurvePoint(i, segment2));
        }

        totalPoints.push_back(getIntersectionPosition(SecondSeg.to));
    }

    auto p1 = totalPoints[pID - 1];
    auto p2 = totalPoints[pID ];
    auto p3 = totalPoints[pID + 1];

    // g->set_coordinate_system(ezgl::WORLD);

    // g->set_color(50,50,50,255);
    // g->fill_arc( {get_x_lon(p1.lon()), get_y_lat(p1.lat())} , 5/EARTH_RADIUS_METERS, 0, 360);

    // g->set_color(150,150,150,255);
    // g->fill_arc( {get_x_lon(p2.lon()), get_y_lat(p2.lat())} , 5/EARTH_RADIUS_METERS, 0, 360);

    // g->set_color(230,230,230,255);
    // g->fill_arc( {get_x_lon(p3.lon()), get_y_lat(p3.lat())} , 5/EARTH_RADIUS_METERS, 0, 360);

    //after picking two line, calculate how are they forming the angle
    g->set_coordinate_system(ezgl::SCREEN);
    auto s = ( get_x_lon(p1.lon()) - get_x_lon(p3.lon())) * (get_y_lat(p2.lat()) - get_y_lat(p3.lat()));
    s -= ( get_x_lon(p2.lon()) - get_x_lon(p3.lon())) * (get_y_lat(p1.lat()) - get_y_lat(p3.lat()));
    //return the direction 
    if(s > 0)
        return 1;
    if(s < 0 )
        return 0;
    else
        return -1;

}

//load all navigation intructions and display them on the screen
void show_naviagtion(ezgl::renderer *g) {
    // std::cout<<navigationPoints.size()<<"\n";
    routeMenuB = {{ route_background.center_x() - 8, route_background.top() - 16}, 16, 16};
    routeMenuBox = {{route_background.left(), route_background.top() + 30} , 740 , 300};

    g->set_coordinate_system(ezgl::SCREEN);
    if(!routeMode) {
        naviCount = 0;
        routeMenuA = false;
        return;
    }
    //navi count starts from 0, continue as the button is pressed to turn to different step of the instruction
    ezgl::rectangle adujstB = {{routeMenuBox.right() + 20, routeMenuBox.bottom() + 60 }, 50, 180};
    menuUp = {{adujstB.center_x() - 15, adujstB.bottom() + 15}, 30, 30};
    menuDown = {{adujstB.center_x() - 15, adujstB.top() - 45}, 30, 30};
    
    
    ezgl::surface *png = g->load_png("libstreetmap/resources/routemenu.png");
    g->draw_surface(png, {routeMenuB.left(), routeMenuB.bottom()});
    g->free_surface(png);

    
    //if menu is turned on, display the background and five instructions
    if(routeMenuA) {
        png = g->load_png("libstreetmap/resources/navigation.png");
        g->draw_surface(png, {routeMenuBox.left() - 7, routeMenuBox.bottom() - 7});
        g->free_surface(png);
        g->set_text_rotation(0);
    g->set_font_size(13);
    g->set_color(50,50,50,255);

    // cout << navigationInstructions.size() << "\n";

    if(navigationInstructions.size() != 0 ) {
        int j = 0;

        for(int i = 5 * naviCount; j < 5 && i < navigationInstructions.size(); i ++) {
            if(navigationInstructions[i] == "change") {
                continue;
            }
            if( j == naviRow || j == naviPressed) 
                g->set_color(196,160,220,255);
            g->draw_text( {routeMenuBox.center_x() ,  routeMenuBox.bottom() + 30 + 60 * j}, navigationInstructions[i]);
            g->set_color(50,50,50,255);
            j ++;
        }

        j = 0;

        g->set_coordinate_system(ezgl::SCREEN);

        for(int i = 5 * naviCount; j < 5 && i < navigationInstructions.size(); i ++) {
            if(navigationInstructions[i] == "change") {
                continue;
            }

            if(navigationInstructions[i].at(0) == 'T' && navigationInstructions[i].at(5) == 'r') {
                png = g->load_png("libstreetmap/resources/turn-right.png");
                g->draw_surface(png, {routeMenuBox.left() + 10, routeMenuBox.bottom() + 30 + 60 * j - 20});
                g->free_surface(png);
            }
            else if(navigationInstructions[i].at(0) == 'T' && navigationInstructions[i].at(5) == 'l') {
                png = g->load_png("libstreetmap/resources/turn-left.png");
                g->draw_surface(png, {routeMenuBox.left() + 10, routeMenuBox.bottom() + 30 + 60 * j - 20});
                g->free_surface(png);
            }
            else if(navigationInstructions[i].at(0) == 'G') {
                png = g->load_png("libstreetmap/resources/upload.png");
                g->draw_surface(png, {routeMenuBox.left() + 10, routeMenuBox.bottom() + 30 + 60 * j - 20});
                g->free_surface(png);
            }

            
            g->set_coordinate_system(ezgl::WORLD);
            if(j == naviPressed) {

                double ratio_h = g->get_visible_screen().height()/g->get_visible_world().height();
                double ratio_w = g->get_visible_screen().width()/g->get_visible_world().width();
                ezgl::point2d plot_point(get_x_lon(getIntersectionPosition(navigationPoints[i]).lon())-(12.5/ratio_w), get_y_lat(getIntersectionPosition(navigationPoints[i]).lat())+(12.5/ratio_h));
                
                png = g->load_png("libstreetmap/resources/shadowpoint.png");
                g->draw_surface(png, plot_point );
                g->free_surface(png);

                if (routeMoveMid) {
                    routeMoveMid = false;
                    auto rsize = (get_x_lon(getIntersectionPosition(firstinter).lon()) - get_x_lon(getIntersectionPosition(secondinter).lon()) ); 
                    rsize = rsize * rsize;
                    rsize = rsize + (get_y_lat(getIntersectionPosition(firstinter).lat()) - get_y_lat(getIntersectionPosition(secondinter).lat()) ) * (get_y_lat(getIntersectionPosition(firstinter).lat()) - get_y_lat(getIntersectionPosition(secondinter).lat()) );
                    rsize = sqrt(rsize);
                    moveToMidpoint(g, getIntersectionPosition(navigationPoints[i]).lon(), getIntersectionPosition(navigationPoints[i]).lat() , rsize);
                }
                // moveToMidpoint(g, getPointOfInterestPosition(navigationPoints[i]).lon(), getPointOfInterestPosition(navigationPoints[i]).lat() );
                // cout << i << "\n";
            }
             g->set_coordinate_system(ezgl::SCREEN);

            // g->draw_text( {routeMenuBox.center_x() ,  routeMenuBox.bottom() + 30 + 60 * j}, navigationInstructions[i]);
            j ++;
        }

    }

    png = g->load_png("libstreetmap/resources/adjust.png");
    g->draw_surface(png, {adujstB.left() - 5, adujstB.bottom() - 5});
    g->free_surface(png);

    png = g->load_png("libstreetmap/resources/sort-up.png");
    g->draw_surface(png, {menuUp.left() , menuUp.bottom() });
    g->free_surface(png);

    png = g->load_png("libstreetmap/resources/sort-down.png");
    g->draw_surface(png, {menuDown.left() , menuDown.bottom() });
    g->free_surface(png);

    g->set_text_rotation(0);
    g->set_font_size(18);
    g->set_color(170,170,170,255);

    int totalSize = navigationInstructions.size();
            if(changeContain) {
                totalSize -= 1;
            }

    g->draw_text(adujstB.center(), to_string(naviCount + 1)  + "/" +to_string( (totalSize - 1) / 5 + 1) );
    }

    g->set_coordinate_system(ezgl::WORLD);
    
    // cout<< routeMenuBox.left() << " " << routeMenuBox.bottom() <<"\n";

    

    
}

int midInter(int segment1, int segment2) {
    InfoStreetSegment firstSeg= getInfoStreetSegment(segment1);
    InfoStreetSegment SecondSeg = getInfoStreetSegment(segment2);

    if(firstSeg.from == SecondSeg.to || firstSeg.from == SecondSeg.from) {
        return firstSeg.from;
    }

    return firstSeg.to;
}