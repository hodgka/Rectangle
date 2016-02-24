#ifndef __rectangle_h_
#define __rectangle_h_

#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include "point.h"
#include <cmath>
#include <algorithm>

using std::vector;
using std::pair;
using std::abs;

class Point;
class Rectangle{
	public:
		//default and copy constructors
		Rectangle(const Point& p1, const Point& p2);
		~Rectangle();		
		//mutator member functions
		void set_top_left(const Point& p1){delete tl;tl = new Point(p1);}
		void set_bottom_right(const Point& p1){delete br; br = new Point(p1);}
		
		//accessors
		Point get_tl() const {return *tl;}
		Point  get_br() const {return *br;}

		double get_width() const {
			return abs(tl->get_x() - br->get_x());}
		double get_height() const {
			return abs(tl->get_y() - br->get_y());}
		double get_perimeter() const {
			return 2*get_width()+2*get_height();}
		
		//2 different functions to get the area of a rectangle
		double get_area() const;
		double get_area(const Point& p1, const Point& p2) const;
		
		//get the horizontal and vertical distances
		double dist(const Rectangle& r, bool m = true );
		//get euclidean distance between top left corners
		double offset(const Rectangle& r);
		//check if point is inside rectangle/range of x/y of rectangle
		bool inside(const Point& p1) const;
		bool inside(const Point& p1, bool m) const;
		
		//checks if a rectangle is contained
		bool contains(const Rectangle& r) const;
		
		//checks if r intersects the current rectangle and returns corner
		//points of the intersection
		vector<pair<double,double> > intersects(const Rectangle& r) const ;
		
		//checks if the rectangles are adjacent
		
		bool adjacent(const Rectangle& r);
		//returns the area of intersection between two rectangles
		double intersection_area(const Rectangle& r) const ;
		//returns a bool depending on if "this" rectangle is bigger(true) or smaller
		bool bigger( const Rectangle& r) const;
	private:
		//the TopLeft and BottomRight points of the rectangle
		Point* tl;
		Point* br;

};



#endif
