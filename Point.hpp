#include <random>

struct Point {
	double x, y;

	Point()
	{
		x = rand();
		y = rand();
	}

	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
	}

	friend bool operator==(Point& lhs, Point& rhs)
	{
		return ((lhs.x == rhs.x) && (lhs.y = rhs.y));
	}
};