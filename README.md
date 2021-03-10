# GIS-mapper
This is a complete project of daily map application, including user interface and key functionalities

m1.cpp: this file contains all functions that are used to process geographical data, by using STL structures, reformat different kinds of data(streets, buildings, Points of Interests) into operatable data structures, optimizing efficiency for rendering

m2.cpp: this file contains all graphic user interface implementations, including map rendering, user menus, search bar and other required components to connect back-end algorithms with users

m3.cpp: shortest path algorithm, used in map programs for navigation. We implemented a Dijkstra's Algorithm and A* Algorithm, which is a updated version for Dijkstra. The functions are used in m2.cpp for path rendering and other navigation information

m4.cpp: TSP(Travelling Salesman Problem) solution implementation. By implementing SA(simulated annealing) algorithm, we solved the problem of optimizing efficiency for multiple starting points and destination, the algorithm will find the best order of how to get through each point with certain restrictions in sequence. This algorithm intergrated m3.cpp A* algorithm to compute best paths between this points

For details and visual effects of this program, please check the powerpoint presentation.
