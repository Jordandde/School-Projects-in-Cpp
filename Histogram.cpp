#include <iostream>
#include <stdlib.h>
using namespace std;
int main(const int argc, const char* const argv[]){
	int bucket[10] = {0,0,0,0,0,0,0,0,0,0};
	if(argc < 1){
		cerr << "Error: unable to compute histogram over data set because there was no data" << endl;
		return -1;
	}
	int rc = 0;
	int counter = 1;
	while(counter < argc  && atof(argv[counter]) > -1){
		if(atof(argv[counter]) < 1){
			bucket[9] += 1;
			counter++;
			
		}else if(atof(argv[counter]) < 106){
			bucket[0] += 1;
			counter++;
		}else if(atof(argv[counter]) < 109){
			bucket[1] += 1;
			counter++;
		}else if(atof(argv[counter]) < 112){
			bucket[2] += 1;
			counter++;
		}else if(atof(argv[counter]) < 115){
			bucket[3] += 1;
			counter++;
		}else if(atof(argv[counter]) < 118){
			bucket[4] += 1;
			counter++;
		}else if(atof(argv[counter]) < 121){
			bucket[5] += 1;
			counter++;
		}else if(atof(argv[counter]) < 124){
			bucket[6] += 1;
			counter++;
		}else if(atof(argv[counter]) < 128){
			bucket[7] += 1;
			counter++;
		}else if(atof(argv[counter]) < 150){
			bucket[8] += 1;
			counter++;
		}else{
			cout << "Warning: invalid voltage reading " << atof(argv[counter]) << " ignored in calculations" << endl;
			bucket[9] += 1;
			rc += 1;
			counter++;
		}
	}
	if(bucket[9] + 3 > argc){
		cerr << "Error: unable to compute histogram over data set because there was no valid data" << endl;
		return -1;
	}
	counter -= bucket[9];
	cout << "Number of voltage readings: " << counter - 1 << endl;
	cout << "Voltage readings (0-106): " << bucket[0] << endl;
	cout << "Voltage readings [106-109): " << bucket[1] << endl;
	cout << "Voltage readings [109-112): " << bucket[2] << endl;
	cout << "Voltage readings [112-115): " << bucket[3] << endl;
	cout << "Voltage readings [115-118): " << bucket[4] << endl;
	cout << "Voltage readings [118-121): " << bucket[5] << endl;
	cout << "Voltage readings [121-124): " << bucket[6] << endl;
	cout << "Voltage readings [124-127]: " << bucket[7] << endl;
	cout << "Voltage readings (127-150): " << bucket[8] << endl;
	cout << "Invalid readings: " << bucket[9] << endl;
	return rc;
}