#include <iostream>

using namespace std;

int main(){
	float a, b, c, d, *p;
	
	cout << "Enter a, b, c, d: ";
	cin >> a >> b >> c >> d;
	
	float arr[4] = {a, b, c, d};
	float avg = 0;
	
	p = &arr[0];
	
	for (int i=0; i<4; i++){
		for (int j=0; j<4; j++){
			if (*p == arr[j] && j!=i){
				cout << "Array values not unique" << endl;
				return 1;
			}
		}
		avg += *p/4;
		p++;
	}
	
	cout << "Avg: " << avg << endl;
	
	float *minp, *maxp;
	
	minp = &a;
	maxp = &a;
	
	if (*minp < b && *minp < c && *minp < d){
	}
	else if (b < *minp && b < c && b < d){
		minp = &b;
	}
	else if (c < *minp && c < b && c < d){
		minp = &c;
	}
	else if (d < *minp && d < b && d < c){
		minp = &d;
	}
	
	if (*maxp > b && *maxp > c && *maxp > d){
	}
	else if (b > *maxp && b > c && b > d){
		maxp = &b;
	}
	else if (c > *maxp && c > b && c > d){
		maxp = &c;
	}
	else if (d > *maxp && d > b && d > c){
		maxp = &d;
	}
	
	cout << "Not maximum and minimum values: ";
	
	for (int i=0; i<4; i++){
		if (arr[i] != *maxp && arr[i] != *minp){
			cout << arr[i] << " ";
		}
	}
	cout << endl;
	
	return 0;
	
}