#include <iostream>
#include <cassert>
#include "rectangle.h"
#include "point.h"
#include <algorithm>

using std::min;
using std::max;
using std::abs;
using std::vector;
using std::pair;


Rectangle::Rectangle(const Point & p1, const Point & p2){
	tl = new Point;
	br = new Point;
	tl->set_x(p1.get_x());
	tl->set_y(p1.get_y());

	br->set_x(p2.get_x());
	br->set_y(p2.get_y());
}
Rectangle::~Rectangle(){
	delete tl;
	delete br;
}

//gets the area of the rectangle object
double Rectangle::get_area() const {
	return abs((br->get_x() - tl->get_x())*(tl->get_y() - br->get_y()));
}
//gets the area of the rectangle specified by points tl and br
double Rectangle::get_area(const Point& p1, const Point& p2) const {
	return abs((p1.get_x() - p2.get_x())*(p1.get_y() - p2.get_y()));
}

//gets the distance between the two rectangles either horiz. or vert.
//returns horizontal distance unless m is specified as false
double Rectangle::dist(const  Rectangle&  r, bool m){
	if(m ==true){
		double minx = min(abs(tl->get_x() - r.br->get_x()),
						abs(br->get_x() - r.tl->get_x()));
		return minx;
	} else{
		double miny = min(abs(tl->get_y() - r.br->get_y()),
						abs(br->get_y() - r.tl->get_y()));
		return miny;
	}
}

//returns euclidean distance between top left corners
double Rectangle::offset(const Rectangle& r){
	return tl->Point::dist(*(r.tl));
}

//helper function used for contains and adjacent
bool Rectangle::inside(const Point& p1) const {
	if(p1.get_x()>tl->get_x() && p1.get_x()<br->get_x() && p1.get_y()<tl->get_y()
		&& p1.get_y()>br->get_y()){
		return true;
	}
	return false;
}
//alternate form of the other inside function, used for check if x/y is in range
bool Rectangle::inside(const Point& p1,bool m) const{
	if(m==true){
		//check if p1 is within range in x direction
		if(p1.get_x() >= tl->get_x() && p1.get_x() <= br->get_x())
			return true;
		
	}else{
		//check if p1 is within range in y direction
		if(p1.get_y()>=br->get_y() && p1.get_y()<=tl->get_y())
			return true;
	}
	return false;
}
//gets the area left in larger rectangle 
bool Rectangle::contains(const Rectangle& r) const {
	assert(get_area() >= get_area(*(r.tl),*(r.br)));
	//make sure that every corner is inside the rectangle
	vector<bool> invec;
	invec.push_back(inside(r.get_tl()));
	invec.push_back(inside(Point(r.br->get_x(),r.tl->get_y())));
	invec.push_back(inside(Point(r.tl->get_x(),r.br->get_y())));
	invec.push_back(inside(r.get_br()));
	if(std::count(invec.begin(),invec.end(),true) == 4){
		 return true;
	}
	return false;
}

//returns a 
vector<pair<double,double> > Rectangle::intersects
	(const Rectangle& r) const {
	//getting old x,y coords from rectangle
	double x1 = tl->get_x();
	double y1 = tl->get_y();
	double x2 = br->get_x();
	double y2 = br->get_y();
	double x3 = r.tl->get_x();
	double y3 = r.tl->get_y();
	double x4 = r.br->get_x();
	double y4 = r.br->get_y();
	//intersection points
	double x5 = max(x1,x3);
	double y5 = max(y1,y3);
	double x6 = min(x2,x4);
	double y6 = min(y2,y4);
	
	//	inside(*r.br,false)&&inside(*r.br,true));
	//if x5>x6 or y5>y6 the rectangles don't intersect, so return ((0,0),(0,0))
	//need to check case where no points are inside the rectangle(plus shape)
	if((x5>=x6 ||y5>=y6) && !(inside(*r.tl,true)||inside(*r.tl,false)||
		inside(*r.br,false)||inside(*r.br,true))){
		return vector<pair<double,double> >(2,std::make_pair(0,0));
	}else{
		//create a vector of pairs with the corners of the rectangle
		//created by the intersection
		vector<pair<double,double> > pairvec;
		pairvec.push_back(std::make_pair(x5,y5));
		pairvec.push_back(std::make_pair(x6,y6));
		return pairvec;
	}
}

//boolean function the returns true if two rectangles share part of a side
bool Rectangle::adjacent(const Rectangle& r)  {
	//make sure no points are inside the rectangle
	vector<bool> invec;
	invec.push_back(inside(r.get_tl()));
	invec.push_back(inside(r.get_br()));
	if(std::count(invec.begin(),invec.end(),true) !=0){
		return false;
	}
	//if the distance is 0, and either  the x poisitions or y positions
	//are on the rectangle
	//awful logic statement to check if the distance away

	if((dist(r,true)==0 &&(inside(r.get_tl(),false) ||
	 inside(r.get_br(),false)||r.inside(*(this->tl),false)|| r.inside(*(this->br),false) ) ) ||
	  (dist(r,false)==0 && (inside(r.get_tl(),true) ||inside(r.get_br(),true)||
	  	r.inside(*(this->tl),true)|| r.inside(*(this->br),true)))) {
		return true;
	}
	return false;
}

//returns the area of intersection of two rectangles
double Rectangle::intersection_area(const Rectangle& r) const  {
	vector<pair<double, double> > pairvec = intersects(r);
	return get_area(Point(pairvec[0].first,pairvec[0].second),
					Point(pairvec[1].first,pairvec[1].second));	
}

//sees which rectangle has a larger area
bool Rectangle::bigger(const Rectangle& r) const {
	if(r.get_area() > get_area()){
		return false;
	}
	return true;
}
