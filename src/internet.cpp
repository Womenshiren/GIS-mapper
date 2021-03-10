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

/* This example shows how to use Boost to parse JSON data and store it into
 * a Property Tree data structure. The tree can than be searched based on
 * keyword paths, so prior knowledge of the JSON data's schema is required.
 *
 * Further reading and references:
 *  https://www.boost.org/doc/libs/1_65_1/doc/html/property_tree.html
 *  http://www.ce.unipr.it/~medici/boost_ptree.html
 */
#pragma once
#include <iostream>
#include <string.h>
#include <curl/curl.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <string>

using namespace std;
using boost::property_tree::ptree;
using boost::property_tree::read_json;
string myLocationInfo;

typedef struct MyCustomStruct {
    const char *url = nullptr;
    unsigned int size = 0;
    char *response = nullptr;
} MyCustomStruct;

typedef struct WeatherInfo {
    string summary;
    string icon;
    double temperature;
} ;

WeatherInfo currentWeather;

typedef struct IncidentInfo {
    pair<double, double> coor;
    string startime;
    string endtime;
    string desc;
} ;

vector<IncidentInfo> cIncidents;

/* buffer holds the data received from curl_easy_perform()
 * size is always 1
 * nmemb is the number of bytes in buffer
 * userp is a pointer to user data (i.e. myStruct from main)
 *
 * Should return same value as nmemb, else it will signal an error to libcurl
 * and curl_easy_perform() will return an error (CURLE_WRITE_ERROR). This is
 * useful if you want to signal an error has occured during processing.
 */
static size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp) {
    if (buffer && nmemb && userp) {
        MyCustomStruct *pMyStruct = (MyCustomStruct *)userp;

        // Writes to struct passed in from main
        if (pMyStruct->response == nullptr) {
            // Case when first time write_data() is invoked
            pMyStruct->response = new char[nmemb + 1];
            strncpy(pMyStruct->response, (char *)buffer, nmemb);
        }
        else {
            // Case when second or subsequent time write_data() is invoked
            char *oldResp = pMyStruct->response;

            pMyStruct->response = new char[pMyStruct->size + nmemb + 1];

            // Copy old data
            strncpy(pMyStruct->response, oldResp, pMyStruct->size);

            // Append new data
            strncpy(pMyStruct->response + pMyStruct->size, (char *)buffer, nmemb);

            delete []oldResp;
        }

        pMyStruct->size += nmemb;
        pMyStruct->response[pMyStruct->size] = '\0';
    }

    return nmemb;
}

/* Boost uses the following JSON to property tree mapping rules:
 *   1) JSON objects are mapped to nodes. Each property is a child node.
 *   2) JSON arrays are mapped to nodes.
 *      Each element is a child node with an empty name. If a node has both
 *      named and unnamed child nodes, it cannot be mapped to a JSON representation.
 *   3) JSON values are mapped to nodes containing the value.
 *      However, all type information is lost; numbers, as well as the literals
 *      "null", "true" and "false" are simply mapped to their string form.
 *   4) Property tree nodes containing both child nodes and data cannot be mapped.
 */
void getLocationInfoHelper(ptree &ptRoot) {

    BOOST_FOREACH(ptree::value_type &featVal, ptRoot.get_child("results")) {

        auto locationnode = featVal.second.get_child("formatted_address");
        auto locationinfo = locationnode.get_value<string>();

        if(myLocationInfo.size() == 0)
            myLocationInfo += locationinfo;
    }

    return;
}

string getLocationInfo(double lat, double lon) {
    stringstream latlonstream ;
    latlonstream << lat <<","<<lon<<flush;
    auto latlonstring = latlonstream.str();
    CURLcode res = curl_global_init(CURL_GLOBAL_ALL);
    if (res != CURLE_OK) {
        cout << "ERROR: Unable to initialize libcurl" << endl;
        cout << curl_easy_strerror(res) << endl;
        return 0;
    }

    CURL *curlHandle = curl_easy_init();
    if ( !curlHandle ) {
        cout << "ERROR: Unable to get easy handle" << endl;
        return 0;
    } else {
        char errbuf[CURL_ERROR_SIZE] = {0};
        MyCustomStruct myStruct;
        string urlstring = "https://maps.googleapis.com/maps/api/geocode/json?latlng=" + latlonstring + "&key=AIzaSyBPMsk9ygdVKGJXF7W8G9ow5odCgpM9kkY&language=en";
        const char *targetURL = urlstring.c_str();

        res = curl_easy_setopt(curlHandle, CURLOPT_URL, targetURL);
        if (res == CURLE_OK)
            res = curl_easy_setopt(curlHandle, CURLOPT_ERRORBUFFER, errbuf);
        if (res == CURLE_OK)
            res = curl_easy_setopt(curlHandle, CURLOPT_WRITEFUNCTION, write_data);
        if (res == CURLE_OK)
            res = curl_easy_setopt(curlHandle, CURLOPT_WRITEDATA, &myStruct);

        myStruct.url = targetURL;

        if (res != CURLE_OK) {
            cout << "ERROR: Unable to set libcurl option" << endl;
            cout << curl_easy_strerror(res) << endl;
        } else {
            res = curl_easy_perform(curlHandle);
        }

        if (res == CURLE_OK) {
            // Create an empty proper tree
            ptree ptRoot;

            /* Store JSON data into a Property Tree
             *
             * read_json() expects the first parameter to be an istream object,
             * or derived from istream (e.g. ifstream, istringstream, etc.).
             * The second parameter is an empty property tree.
             *
             * If your JSON data is in C-string or C++ string object, you can
             * pass it to the constructor of an istringstream object.
             */
            istringstream issJsonData(myStruct.response);
            read_json(issJsonData, ptRoot);

            // Parsing and printing the data
            try {
                getLocationInfoHelper(ptRoot);
            } catch (const char *errMsg) {
                cout << "ERROR: Unable to fully parse the TTC JSON data" << endl;
                cout << "Thrown message: " << errMsg << endl;
            }
        } else {
            cout << "ERROR: res == " << res << endl;
            cout << errbuf << endl;
        }

        if (myStruct.response)
            delete []myStruct.response;

        curl_easy_cleanup(curlHandle);
        curlHandle = nullptr;
    }

    curl_global_cleanup();

    auto returnString = myLocationInfo;
    myLocationInfo.clear();

    return returnString;
}

void getWeatherInfoHelper(ptree &ptRoot) {

    auto csummary = ptRoot.get_child("currently.summary");

    auto cicon = ptRoot.get_child("currently.icon");

    auto ctemp = ptRoot.get_child("currently.temperature");

    currentWeather.summary = csummary.get_value<string>();

    currentWeather.icon = cicon.get_value<string>();

    currentWeather.temperature = ctemp.get_value<double>();

    return;
}

WeatherInfo getWeatherInfo(double lat, double lon) {
    stringstream latlonstream ;
    latlonstream << lat <<","<<lon<<flush;
    auto latlonstring = latlonstream.str();
    CURLcode res = curl_global_init(CURL_GLOBAL_ALL);
    if (res != CURLE_OK) {
        cout << "ERROR: Unable to initialize libcurl" << endl;
        cout << curl_easy_strerror(res) << endl;
    }

    CURL *curlHandle = curl_easy_init();
    if ( !curlHandle ) {
        cout << "ERROR: Unable to get easy handle" << endl;
    } else {
        char errbuf[CURL_ERROR_SIZE] = {0};
        MyCustomStruct myStruct;
        string urlstring = "https://api.darksky.net/forecast/8b5efe6c68647d74e5729e7447c0cb30/" + latlonstring;
        const char *targetURL = urlstring.c_str();

        res = curl_easy_setopt(curlHandle, CURLOPT_URL, targetURL);
        if (res == CURLE_OK)
            res = curl_easy_setopt(curlHandle, CURLOPT_ERRORBUFFER, errbuf);
        if (res == CURLE_OK)
            res = curl_easy_setopt(curlHandle, CURLOPT_WRITEFUNCTION, write_data);
        if (res == CURLE_OK)
            res = curl_easy_setopt(curlHandle, CURLOPT_WRITEDATA, &myStruct);

        myStruct.url = targetURL;

        if (res != CURLE_OK) {
            cout << "ERROR: Unable to set libcurl option" << endl;
            cout << curl_easy_strerror(res) << endl;
        } else {
            res = curl_easy_perform(curlHandle);
        }

        if (res == CURLE_OK) {
            // Create an empty proper tree
            ptree ptRoot;

            /* Store JSON data into a Property Tree
             *
             * read_json() expects the first parameter to be an istream object,
             * or derived from istream (e.g. ifstream, istringstream, etc.).
             * The second parameter is an empty property tree.
             *
             * If your JSON data is in C-string or C++ string object, you can
             * pass it to the constructor of an istringstream object.
             */
            istringstream issJsonData(myStruct.response);
            read_json(issJsonData, ptRoot);

            // Parsing and printing the data
            try {
                getWeatherInfoHelper(ptRoot);
            } catch (const char *errMsg) {
                cout << "ERROR: Unable to fully parse the TTC JSON data" << endl;
                cout << "Thrown message: " << errMsg << endl;
            }
        } else {
            cout << "ERROR: res == " << res << endl;
            cout << errbuf << endl;
        }

        if (myStruct.response)
            delete []myStruct.response;

        curl_easy_cleanup(curlHandle);
        curlHandle = nullptr;
    }

    curl_global_cleanup();

    return currentWeather;
}

void getIncidentInfoHelper(ptree &ptRoot) {

    cIncidents.clear();

    BOOST_FOREACH(ptree::value_type &featVal, ptRoot.get_child("incidents")) {
        auto latnode = featVal.second.get_child("lat");
        auto latinfo = latnode.get_value<double>();
        auto lonnode = featVal.second.get_child("lng");
        auto loninfo = lonnode.get_value<double>();
        auto startnode = featVal.second.get_child("startTime");
        auto startinfo = startnode.get_value<string>();
        auto endnode = featVal.second.get_child("endTime");
        auto endinfo = endnode.get_value<string>();
        auto descnode = featVal.second.get_child("shortDesc");
        auto descinfo = descnode.get_value<string>();

        IncidentInfo in;
        in.coor= make_pair(latinfo, loninfo);
        in.startime = startinfo;
        in.endtime = endinfo;
        in.desc = descinfo;
        // cout<<descinfo<<endl;
        cIncidents.push_back(in);
    }


    return;
}

vector<IncidentInfo> getIncidentInfo(double lat1, double lon1, double lat2, double lon2) {


    stringstream latlonstream ;
    latlonstream << lat1 <<","<<lon1<< ","<<lat2 <<","<<lon2<<flush;
    auto latlonstring = latlonstream.str();
    CURLcode res = curl_global_init(CURL_GLOBAL_ALL);
    if (res != CURLE_OK) {
        cout << "ERROR: Unable to initialize libcurl" << endl;
        cout << curl_easy_strerror(res) << endl;
    }

    CURL *curlHandle = curl_easy_init();
    if ( !curlHandle ) {
        cout << "ERROR: Unable to get easy handle" << endl;
    } else {
        char errbuf[CURL_ERROR_SIZE] = {0};
        MyCustomStruct myStruct;
        string urlstring = "http://www.mapquestapi.com/traffic/v2/incidents?key=EhIME9Qq7ncwEYTG6gTc85B7gBGmwyBj&boundingBox="+ latlonstring +"&filters=construction,incidents";
        const char *targetURL = urlstring.c_str();

        res = curl_easy_setopt(curlHandle, CURLOPT_URL, targetURL);
        if (res == CURLE_OK)
            res = curl_easy_setopt(curlHandle, CURLOPT_ERRORBUFFER, errbuf);
        if (res == CURLE_OK)
            res = curl_easy_setopt(curlHandle, CURLOPT_WRITEFUNCTION, write_data);
        if (res == CURLE_OK)
            res = curl_easy_setopt(curlHandle, CURLOPT_WRITEDATA, &myStruct);

        myStruct.url = targetURL;

        if (res != CURLE_OK) {
            cout << "ERROR: Unable to set libcurl option" << endl;
            cout << curl_easy_strerror(res) << endl;
        } else {
            res = curl_easy_perform(curlHandle);
        }

        if (res == CURLE_OK) {
            // Create an empty proper tree
            ptree ptRoot;

            /* Store JSON data into a Property Tree
             *
             * read_json() expects the first parameter to be an istream object,
             * or derived from istream (e.g. ifstream, istringstream, etc.).
             * The second parameter is an empty property tree.
             *
             * If your JSON data is in C-string or C++ string object, you can
             * pass it to the constructor of an istringstream object.
             */
            istringstream issJsonData(myStruct.response);
            read_json(issJsonData, ptRoot);

            // Parsing and printing the data
            try {
               getIncidentInfoHelper(ptRoot);
            } catch (const char *errMsg) {
                cout << "ERROR: Unable to fully parse the TTC JSON data" << endl;
                cout << "Thrown message: " << errMsg << endl;
            }
        } else {
            cout << "ERROR: res == " << res << endl;
            cout << errbuf << endl;
        }

        if (myStruct.response)
            delete []myStruct.response;


        curl_easy_cleanup(curlHandle);
        curlHandle = nullptr;
    }

    curl_global_cleanup();

    return cIncidents;
}