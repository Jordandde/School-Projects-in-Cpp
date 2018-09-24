//bubble sort
#include <iostream>
#include <math.h>
#include <stdlib.h>

int main(const int argc, const char* const argv[]){
	int sz = 9;
	int sDA[9] = { 5, 1,0, 3, 2, 14, 101, 37, 3};
	int somethingChanged = 1;
	while(somethingChanged){
		somethingChanged = 0;
		int i = 0;
		while( i < sz -1){
			if(sDA[i] > sDA[i+1]){//wrong order swap
				int temp = sDA[i];
				sDA[i] = sDA[i + 1];
				sDA[i + 1] = temp;
				somethingChanged = 1;
			}
			i++;
		}
	}
	int i = 0;
	while(i < sz){
		cout << i << ": " << sDA[i] << endl;
	}
	return 0;
}