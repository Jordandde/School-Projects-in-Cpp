#include <iostream> 
#include <math.h>
#include <stdlib.h>
float poDev(float[], float numbers, float average);
float saDev(float[], float numbers, float average);
float elements(float[], int numbers, float average, int counter, float sum);
using namespace std;
int main(const int argc, const char* const argv[]){
	if(argc == 1 || atof(argv[1]) < 0){
		cerr << "Error: unable to compute standard deviations over data set because there was no valid input" << endl;
		return -1;
	}
	if(argc == 2 && atof(argv[1]) >= 150){
		cerr << "Error: unable to compute standard deviations over data set because there was no valid input" << endl;
		return -1;
	}
	float average = 0;
	int valids = 0;
	int q = 1;
	while(atof(argv[q]) >= 0 && q < argc -1){
		if(atof(argv[q]) > 0){
			if(atof(argv[q]) < 150){
				valids++;
			}
		}
		q++;
	}
	float readings[valids];
	int rc = 0;
	int validReadings = 0;
	int i = 1;
	float validR = 0;
	while(i < argc && atof(argv[i]) > -1 ){
		if(atof(argv[i]) < 150){
			if(atof(argv[i]) > 0){
				readings[validReadings] = atof(argv[i]);
				validReadings++;
				validR++;
				average += atof(argv[i]);
			}else{
				cout << "Warning: invalid voltage reading " << atof(argv[i]) << " ignored in calculation" << endl;
				rc += 1;
			}
		}
		else{
			cout << "Warning: invalid voltage reading " << atof(argv[i]) << " ignored in calculation" << endl;
			rc += 1;
		}
		i++;
	}
	/*if(validReadings == 0){
		cerr << "Error, unable to compute median over data set because no data was input" << endl;
		return -1;
	}*/
	if(validReadings == 0){
		cerr << "Error: unable to compute standard deviations over data set because there was no valid input" << endl;
		return -1;
	}
	average /= validReadings;
	float popDev = poDev(readings, validR, average);
	float samDev = saDev(readings, validR, average);
	cout << "Number of voltage readings: " << validReadings << endl;
	
	if(validReadings <= 1){
		cout << "Population standard deviation: infinity" << endl;
		cout << "Sample standard deviation: undefined" << endl;

	}else{
		cout << "Population standard deviation: " << popDev << endl;
		cout << "Sample standard deviation: " << samDev << endl;
	}
	return rc;
}
float poDev(float readings[], float numbers, float average){
	float x = (elements(readings, numbers, average, 0, 0));
	float dev = sqrt((1 / numbers) * x);
	//cout << x << endl << dev << endl;
	return dev;
}
float saDev(float readings[], float numbers, float average){
	float x = (elements(readings, numbers, average, 0, 0));
	float dev = sqrt((1 / (numbers - 1)) * x);
	
	return dev;
}
float elements(float readings[], int numbers, float average, int counter, float sum){
	if(counter < numbers){
		//cout << readings[counter] << endl;
		//cout << pow((readings[counter] - average),2) << endl;
		sum += pow((readings[counter] - average),2);
		//cout << sum << endl;
		counter += 1;
		return elements(readings, numbers, average, counter, sum);
	}else{
		//cout << sum << endl;
		return sum;
	}
	return sum;
}