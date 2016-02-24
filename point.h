#ifndef __point_h_
#define __point_h_

#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <cmath>
#include <cassert>

class Point{
	//basic point class to be used by rectangle
public:
	//constructors
	Point(): x(0),y(0) {}
	Point(double xin,double yin): x(xin), y(yin) {}
	//mutators
	void set_x(double xin) {x = xin;}
	void set_y(double yin) {y = yin;}
	//accessors
	double get_x() const{return x;}
	double get_y() const{return y;}
	
	double dist(const Point& other)const {
		return sqrt(pow(get_x() - other.get_x(),2)
		+ pow(get_y() - other.get_y(),2));}
private:
	double x;
	double y;
};

#endif
