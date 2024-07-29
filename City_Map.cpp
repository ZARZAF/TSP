#include "City_Map.h"
#include <sstream> 
#include <fstream>

Map::Map(int n)
{
	this->n = n;

	for (int i = 0; i < n; i++)
	{
		city_map[i] = Point();
		cities[i] = "City " + std::to_string(i);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			double x = std::abs(city_map[i].x - city_map[j].x);
			double y = std::abs(city_map[i].y - city_map[j].y);
			distances[i][j] = std::sqrt(x * x + y * y);
		}
	}
}

Map::Map(string city_file, string points_file)
{
	ifstream read_names;
	read_names.open(city_file);

	string line;
	int size = 0;
	while (getline(read_names, line))
	{
		cities[size++] = line;
	}

	n = size;
	read_names.close();
	ifstream read_points;
	read_points.open(points_file);

	string coordinate;
	for (int i = 0; i < n; i++)
	{
		getline(read_points, line);
		stringstream ss(line);
		
		getline(ss, coordinate, ',');
		city_map[i].x = stod(coordinate);

		getline(ss, coordinate, ',');
		city_map[i].y = stod(coordinate);
	}
	read_points.close();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			double x = std::abs(city_map[i].x - city_map[j].x);
			double y = std::abs(city_map[i].y - city_map[j].y);
			distances[i][j] = std::sqrt(x * x + y * y);
		}
	}
}

Point Map::get_point(int index)
{
	return city_map[index];
}

double Map::get_distance(int i, int j) const
{
	return distances[i][j];
}

string Map::get_city(int index) const
{
	return cities[index];
}

int Map::get_size() const
{
	return n;
}
