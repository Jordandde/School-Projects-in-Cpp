#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
int main(const int argc, const char* const argv[]){
	int rc = 0;
	
	if( argc > 7){
		cerr << "Warning: Expected 6 arguments; received " << argc - 1 <<"; ignoring extraneous arguments" << endl;
		rc = -1;
	}
	else if( argc < 7){
		cerr << "Error: Expected 6 arguments; received  " << argc - 1 << "; exiting" << endl;
		return -1;
	}
	float p1x = atof(argv[1]);
	float p1y = atof(argv[2]);
	float p2x = atof(argv[3]);
	float p2y = atof(argv[4]);
	float p3x = atof(argv[5]);
	float p3y = atof(argv[6]);
	if(p1x == p2x && p2x == p3x){
		if(p1y == p2y && p2y == p3y){
			cerr << "The points (" << p1x << "," << p1y << "), (" << p2x << "," << p2y << "), and (" << p3x << "," << p3y << ") overlap; they do not form a triangle" << endl;
			return -1;
		}
	}else if(p1x == p2x && p1x == p2x){
		cout << "The points (" << p1x << "," << p1y << "), (" << p2x << "," << p2y << "), and (" << p3x << "," << p3y << ") form a line with slope: " << ((p1y - p3y) / (p1x - p3x)) << endl;
		return 1;
	}else if(p2x == p3x && p2x == p3x){
		cout << "The points (" << p1x << "," << p1y << "), (" << p2x << "," << p2y << "), and (" << p3x << "," << p3y << ") form a line with slope: " << ((p1y - p2y) / (p1x - p2x)) << endl;
		return 1;
	}else if(p1x == p3x && p1x == p3x){
		cout << "The points (" << p1x << "," << p1y << "), (" << p2x << "," << p2y << "), and (" << p3x << "," << p3y << ") form a line with slope: " << ((p1y - p2y) / (p1x - p2x)) << endl;
		return 1;
	}else if( ((p1y - p2y) / (p1x - p2x)) == ((p2y - p3y) / ( p2x - p3x))){
		cout << "The points (" << p1x << "," << p1y << "), (" << p2x << "," << p2y << "), and (" << p3x << "," << p3y << ") form a line with slope: " << ((p1y - p2y) / (p1x - p2x)) << endl;
		return 1;
	}else if( ((p2y - p3y) / (p2x - p3x)) == ((p1y - p2y) / ( p1x - p2x))){
		cout << "The points (" << p1x << "," << p1y << "), (" << p2x << "," << p2y << "), and (" << p3x << "," << p3y << ") form a line with slope: " << ((p1y - p2y) / (p1x - p2x)) << endl;
		return 1;
	}else if( ((p1y - p3y) / (p1x - p3x)) == ((p2y - p3y) / ( p2x - p3x))){
		cout << "The points (" << p1x << "," << p1y << "), (" << p2x << "," << p2y << "), and (" << p3x << "," << p3y << ") form a line with slope: " << ((p1y - p2y) / (p1x - p2x)) << endl;
		return 1;
	}
	float s1 = sqrt((pow((p2y - p1y), 2 ) + (pow((p2x - p1x), 2))));
	float s2 = sqrt((pow((p3y - p2y), 2 ) + (pow((p3x - p2x), 2))));
	float s3 = sqrt((pow((p1y - p3y), 2 ) + (pow((p1x - p3x), 2))));
	float s = (0.5) * (s1 + s2 + s3);
	float a = sqrt( s * ( s - s1) * ( s - s2) * ( s - s3));
	cout << "The area of the triangle formed by points (" << p1x << "," << p1y << "), (" << p2x << "," << p2y << "), and (" << p3x << "," << p3y << ") is: " << a << endl;
	return rc;
	}
	