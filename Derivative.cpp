#include <iostream> 
#include <stdlib.h>
#include <math.h>

using namespace std;
extern float f(float t);
	
	//float function = pow(t,2) + 3;
	//return function;
//}
int main(const int argc, const char* const argv[]){
	int rc = 0;
	if(argc < 2){
		cerr << "Error: Expected 1 arguments; received  " << argc - 1 << "; exiting" << endl;
		rc -=  1;
		return rc;
		}else if(argc > 2){
		cerr << "Error: Expected 1 arguments; received " << argc - 1 << "; ignoring extraneous arguments" << endl;
		}
	float t = atof(argv[1]);
	float change = 0.0001;
	float tSmall = t - change;
	float tBig = t + change;
	float ytS = f(tSmall);
	float ytB = f(tBig);
	float slope = (ytB - ytS) / (tBig - tSmall);

	if(slope != slope){
		cout << "The slope of f(t) at t = " << t << " is 0" << endl; 
	}else{
		cout << "The slope of f(t) at t = " << t << " is " << slope << endl;
	}
	return rc;
}