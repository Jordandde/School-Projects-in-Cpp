#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;
int main(const int argc, const char* const argv[]){
	if(argc < 3){
		cerr << "Error: not enough arguments were input, exiting" << endl;
		return -1;
	}
	if(atof(argv[1]) < 1){
		cerr << "Error: invalid window size, exiting" << endl;
		return -1;
	}
	int windowSize = atoi(argv[1]);
	int rc = 0;
	//float window[windowSize];
	int counter = 2;
	int validCounter = windowSize;
	int validNumbers = 0;
	int startPoint = 2;
	int invalidCounter = 0;
	float sampleMin = 150;
	float sampleMax = 0;
	float sampleAverage = 0;
	float average = 0;
	int sampleNumber = 1;
	float number;
	float epsilon = 0.0001;
	cout << "Window Size: " << windowSize << endl;
	cout << "Sample   " << "Value   " << "SWMinimum   " << "SWMaximum" << endl;
	while(atof(argv[counter]) > -1 && counter < (argc - 1)){
		for(int i = 0; i < windowSize; i++){
			if(argc < windowSize && counter == argc){
				return 0;
			}if(atof(argv[counter]) < 0){
				return 0;
			}
			number = atof(argv[counter]);
			if(number - (150 - epsilon) < epsilon){
				if(number < sampleMin){
					sampleMin = number;
				}if(number > sampleMax){
					sampleMax = number;
				}
				average += number;
				validNumbers++;
				sampleAverage = average / (validNumbers);
				}
			if(sampleNumber < windowSize){
				if(number - 150 > -epsilon){
					cout << "Warning: invalid voltage reading " << number << " ignored in calculations" << endl;
					sampleNumber++;
					invalidCounter++;
					rc += 1;
				}else{
					cout << sampleNumber << "  " << number << "  " << sampleMin << "  " << sampleMax << endl;	
					sampleNumber++;
				}
			}
			counter++;

			if(argc - 1 == counter && atof(argv[counter]) >= 0){
				cerr << "Error, readings were not terminated, exiting" << endl;
				return -1;
			}
			if(argc - 2 == invalidCounter){
				cerr << "Error, unable to calculate SWStats, as no valid information was input" << endl;
				return -1;
			}
		}
		
		if(number < 150){
			cout << sampleNumber << "  " << number << "  " << sampleMin << "  " << sampleMax << endl;
			sampleNumber++;
		}else{
			cout << "Warning: invalid voltage reading " << number << " ignored in calculations" << endl;
		}
		
		startPoint++;
		sampleMin = 150;
		sampleMax = 0;
		validCounter++;
		counter = startPoint;
		if(atof(argv[validCounter + 1]) < 0){
			return rc;
		}
	}
	

	return rc;
}
