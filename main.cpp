#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>

#include "point.h"
#include "rectangle.h"

using std::cout;
using std::endl;

int main(int argc, char* argv[]){
	
	//open filestream to parse data
	std::ifstream in_str(argv[1]);	
	if(!in_str.good()){
		std::cerr<<"Could not open "<<argv[1]<<" to read.\n";
	}
	
	char temp; //used to process parenthenses and commas
	double tempx;//reads in x coord
	double tempy;//reads in y coord
	//vectors to store Points and then Rectangles
	vector<Point*> pointvec;
	vector<Rectangle* > rvec;
	
	//read in data of the form (x,y) and create points
	while(in_str>>temp>>tempx>>temp>>tempy>>temp){
		Point* p = new Point(tempx,tempy);
		pointvec.push_back(p);
	}
	//Create Rectangles
	for(int i=0; i<pointvec.size();i+=2){
		Rectangle* r = new Rectangle(*pointvec[i],*pointvec[i+1]);
		rvec.push_back(r);
	}
	//if-else /switch statements for running functions from command line
	if(strcmp(argv[2],"get_width")==0){
		cout<<"The width of R1 is "<<rvec[0]->get_width()<<".\n";
	}else if(strcmp(argv[2], "get_height")==0){
		cout<<"The height of R1 is "<<rvec[0]->get_height()<<".\n";
	}else if(strcmp(argv[2], "get_perimeter")==0){
		cout<<"The perimeter of R1 is "<<rvec[0]->get_perimeter()<<".\n";
	}else if(strcmp(argv[2], "get_area")==0){
		cout<<"The area of R1 is "<<rvec[0]->get_area()<<".\n";
	}else if(strcmp(argv[2], "dist")==0){
		cout<<"The horizontal distance between R1 and R2 is "<<
			rvec[0]->dist(*rvec[1])<<" and the vertical distance is "<<
			rvec[0]->dist(*rvec[1],false)<<endl;
	}else if(strcmp(argv[2], "offset")==0){
		cout<<"The offset between R1 and R2 is "<< rvec[0]->offset(*rvec[1])
			<<".\n";
	}else if(strcmp(argv[2], "contains")==0){
		if(rvec[0]->contains(*rvec[1])){
			cout<<"R1 contains R2."<<endl;
		}else{
			cout<<"R1 does not contain R2.\n";
		}
	}else if(strcmp(argv[2], "intersects")==0){
		vector<pair<double,double> > pairvec;
		pairvec = rvec[0]->intersects(*rvec[1]);
		if(pairvec[0].first ==0 && pairvec[0].second ==0 && pairvec[1].first ==0
			 && pairvec[1].second ==0){
			cout<<"The two rectangles do not intersect."<<endl;
		}else{
			cout<<"R1 and R2 intersect at ("<<pairvec[0].first<<", "<<
				pairvec[0].second<<") and ("<<pairvec[1].first <<", "<<
				pairvec[1].second<<")."<<endl;
		}
	}else if(strcmp(argv[2], "adjacent")==0){
		if(rvec[0]->adjacent(*rvec[1])){
			cout<<"R1 is adjacent to R2"<<endl;
		}else{
			cout<<"The rectangles are not adjacent"<<endl;
		}
	}else if(strcmp(argv[2], "intersection_area")==0){
		cout<<"The area of intersection between R1 and R2 is "<<
		rvec[0]->intersection_area(*rvec[1])<<endl;
	}else if(strcmp(argv[2], "bigger")==0){
		if(rvec[0]->bigger(*rvec[1])){
			cout<<"R1 is bigger than R2."<<endl;
		}else{
			cout<<"R2 is bigger than R1."<<endl;
		}
	}else
		std::cerr<<"Invalid command.\n";

	//cleans up the point vector
	for(vector<Point*>::iterator itr = pointvec.begin(); itr!= pointvec.end();
		++itr){
		delete *itr;
	}
	pointvec.clear();
	//cleans up the rectangle vector
	for(vector<Rectangle*>::iterator itr2 = rvec.begin();itr2!= rvec.end();
		++itr2){
		delete *itr2;
	}
	rvec.clear();

	
	
	return 0;
}
