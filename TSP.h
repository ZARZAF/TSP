#pragma once
#include <iostream>
#include "City_Map.h"

class TSP
{
	Map map;
	vector<pair<vector<int>,double>> chromosomes;
	int mutation_rate;
	int n;
	bool from_file;

	double calc_distance(vector<int>& chromosome); // calcualtes cost of path
	void initialize_generation(); // generate Gen 1
	void reinitialize_generation(); // when stuck
	void evaluate_gen();  // Mean & Median
	void genocide_weaklings(double mean, double median); // kills all low performers
	void reproduce(); // extends chromosomes with the new generation
	void cycle_crossover(vector<int>& parent1, vector<int>& parent2, vector<int>& child1, vector<int>& child2); 
	double mutate(vector<int>& chromosome); // returns the new distance
public:
	void solve();
	TSP(int n, int mutation_rate);
	TSP(string city_file, string points_file, int mutation_rate);

	void print_best() const;
	vector<int> get_best() const;
	void print_path(vector<int>& chromosome) const;
	void print_cities(vector<int>& chromosome) const;
};
