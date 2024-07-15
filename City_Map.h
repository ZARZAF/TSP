#pragma once
#include <string>
#include <vector>
#include "Point.hpp"


using namespace std;

class Map
{
	static const int MAX_SIZE = 100;		  //for now static
	Point city_map[MAX_SIZE];				  //for now static might move to
	string cities[MAX_SIZE];				  //for now static might move to heap
	int n;									  //for now static might move to
	double distances[MAX_SIZE][MAX_SIZE];	  //for now static
public:
	Map(int n);
	Map(string city_file, string points_file);
	Point get_point(int index);
	double get_distance(int i, int j) const;
	string get_city(int index) const;
	int get_size() const;
};
