#include <iostream>
#include <stdlib.h>

extern float f(float x);

using namespace std;
int main(const int argc, const char* const argv[]){
	int rc = 0;
	float epsilon = 0.001f;
	if(argc < 3){
		cerr << "Error: Not enough arguments input, exiting." << endl;
		return -1;
	}
	if(argc > 3){
		cerr << "Warning: Expected 2 arguments; received " << argc - 1 << "; ignoring extraneous arguments" << endl;
		rc = 1;
	}
	float x1 = atof(argv[1]);
	float x1Copy = x1;
	float x2 = atof(argv[2]);
	if(x1 > x2){
		cerr << "Error, second point cannot be located behind the first point" << endl;
		return -1;
	}
	if((x2 - x1) < epsilon && (x2 - x1) > -epsilon){
		cout << "The area under f(x) from " << x1Copy << " to " << x2 << " is 0" << endl;
		return rc;

	}
	float a = 0;
	float dx = 0.01;
	while((x2 - x1) > epsilon){
		a += dx * ((f(x1 + dx) + f(x1)) / 2);
		x1 += dx;
	}
	cout << "The area under f(x) from " << x1Copy << " to " << x2 << " is " << a << endl;
	return rc;
}