#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
int main(const int argc, const char* const argv[]){
	int rc = 0;
	float ep& silon = 0.0001f;
	if(argc == 1){
		cerr << "Error: no information was input" << endl;
		rc = -1;
		return rc;
	}

	float a = atof(argv[1]);
	if(a - 0 < epsilon || 1 - a < epsilon){
		cerr << "Error: invalid input for alpha, terminating" << endl;
		rc = -1;
		return rc;
	}
	if(argc < 3){
		cerr << "Error: there are not enough arguments" << endl;
		rc = -1;
		return rc;
	}
	float s = atof(argv[2]);
	float average = 0;
	int counter = 2;
	int invalidCounter = 1;
	
	cout << "Sample " << "Value " << "EWMA " << endl;
	while(counter < argc && atof(argv[counter]) > -1){
		s = atof(argv[counter]);
		if(s - 149 > epsilon || s - 0 < epsilon){
			cout << "Warning: invalid voltage reading " << s << " ignored in calculation" << endl;
			rc += 1;
			invalidCounter++;
		}else{
			if(average == 0){
				average = atof(argv[counter]);
			}
			average = (a * s) + (1 - a) * average;
			cout <<  counter - 1 << "        " << s << "    " << average << endl;

		}
	counter++;
	}
	if(argc - 2 == invalidCounter){
		cerr << "Error: unable to calculate EWMA as there were no valid voltage readings" << endl;
		rc = -1;
		return rc;
	}
	if(counter - argc == 0){
		cerr << "Error: readings were not terminated; exiting" << endl;
		rc = -1;
		return rc;
	}
	return rc;
}