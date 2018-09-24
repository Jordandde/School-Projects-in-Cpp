#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
int main(const int argc, const char* const argv[]){
	float x1 = atof(argv[1]);
	float y1 = atof(argv[2]);
	float x2 = atof(argv[3]);
	float y2 = atof(argv[4]);
	float x3 = atof(argv[5]);
	float y3 = atof(argv[6]);
	float s1 = sqrt((pow((y2 - y1), 2.0 ) + (pow((x2 - x1), 2.0))));
	float s2 = sqrt((pow((y3 - y2), 2.0 ) + (pow((x3 - x2), 2.0))));
	float s3 = sqrt((pow((y1 - y3), 2.0 ) + (pow((x1 - x3), 2.0))));
	float ps1 = pow(s1,2);
	float ps2 = pow(s2,2);
	float ps3 = pow(s3,2);
	float xtra = 0.0000001;
	float epsilon = 0.0001f;
	
	if(abs(s1 - s2) < epsilon && abs(s2 - s3) < epsilon){
		cout << "The triangle formed by points (" << x1 <<"," << y1 << "), (" << x2 << "," << y2 << "), and (" << x3 << "," << y3 << ") is: equilateral acute" << endl;
	}else if( abs(s1 - s2) < epsilon && s2 != s3){
		if(abs(ps1 + ps2 - ps3) < epsilon) {
			cout << "The triangle formed by points (" << x1 <<"," << y1 << "), (" << x2 << "," << y2 << "), and (" << x3 << "," << y3 << ") is: isosceles right" << endl;
			}
		else if( s2 < s3){
			cout << "The triangle formed by points (" << x1 <<"," << y1 << "), (" << x2 << "," << y2 << "), and (" << x3 << "," << y3 << ") is: isosceles obtuse" << endl;
		}else{
			cout << "The triangle formed by points (" << x1 <<"," << y1 << "), (" << x2 << "," << y2 << "), and (" << x3 << "," << y3 << ") is: isosceles acute" << endl;
		}
	}else if(abs(s1 - s3) < epsilon && s1 != s2){
		if(abs(ps1 + ps3 - ps2) < epsilon) {
			cout << "The triangle formed by points (" << x1 <<"," << y1 << "), (" << x2 << "," << y2 << "), and (" << x3 << "," << y3 << ") is: isosceles right" << endl;
		}else if( s3 < s2){
			cout << "The triangle formed by points (" << x1 <<"," << y1 << "), (" << x2 << "," << y2 << "), and (" << x3 << "," << y3 << ") is: isosceles obtuse" << endl;
		}else{
			cout << "The triangle formed by points (" << x1 <<"," << y1 << "), (" << x2 << "," << y2 << "), and (" << x3 << "," << y3 << ") is: isosceles acute" << endl;
		}
	}else if(abs(s2 - s3) < epsilon && s2 != s1){
		if(abs(ps2 + ps3 - ps1) < epsilon) {
			cout << "The triangle formed by points (" << x1 <<"," << y1 << "), (" << x2 << "," << y2 << "), and (" << x3 << "," << y3 << ") is: isosceles right" << endl;
		
		}else if( s2 < s1){
			cout << "The triangle formed by points (" << x1 <<"," << y1 << "), (" << x2 << "," << y2 << "), and (" << x3 << "," << y3 << ") is: isosceles obtuse" << endl;
		}else{
			cout << "The triangle formed by points (" << x1 <<"," << y1 << "), (" << x2 << "," << y2 << "), and (" << x3 << "," << y3 << ") is: isosceles acute" << endl;
		}

	}else{
		if(s3 > s2 && s3 > s1){
			if(abs(ps1 + ps2 - ps3) < epsilon) {
				cout << "The triangle formed by points (" << x1 <<"," << y1 << "), (" << x2 << "," << y2 << "), and (" << x3 << "," << y3 << ") is: scalene right" << endl;
			}else{
				cout << "The triangle formed by points (" << x1 <<"," << y1 << "), (" << x2 << "," << y2 << "), and (" << x3 << "," << y3 << ") is: scalene obtuse" << endl;
			}
		}else if(s1 > s2 && s1 > s3){
			if(abs(ps3 + ps2 - ps1) < epsilon) {
				cout << "The triangle formed by points (" << x1 <<"," << y1 << "), (" << x2 << "," << y2 << "), and (" << x3 << "," << y3 << ") is: scalene right" << endl;
			}else{
				cout << "The triangle formed by points (" << x1 <<"," << y1 << "), (" << x2 << "," << y2 << "), and (" << x3 << "," << y3 << ") is: scalene obtuse" << endl;
			}
		}else if(s2 > s3 && s2 > s1){
			if(abs(ps1 + ps3 - ps2) < epsilon) {
				cout << "The triangle formed by points (" << x1 <<"," << y1 << "), (" << x2 << "," << y2 << "), and (" << x3 << "," << y3 << ") is: scalene right" << endl;
			}else{
				cout << "The triangle formed by points (" << x1 <<"," << y1 << "), (" << x2 << "," << y2 << "), and (" << x3 << "," << y3 << ") is: scalene obtuse" << endl;
			}
		}else{
			cout << "The triangle formed by points (" << x1 <<"," << y1 << "), (" << x2 << "," << y2 << "), and (" << x3 << "," << y3 << ") is: scalene obtuse" << endl;
		}
	}
	float s = (0.5) * (s1 + s2 + s3);
	float a = sqrt( s * ( s - s1) * ( s - s2) * ( s - s3));
	cout << "The area of the triangle formed by points (" << x1 << "," << y1 << "), (" << x2 << "," << y2 << "), and (" << x3 << "," << y3 << ") is: " << a << endl;
	return 0;
}