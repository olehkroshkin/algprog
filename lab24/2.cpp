#include <iostream>

using namespace std;

int main(){
	float a, b, c, *minp, *maxp;
	
	minp = &a;
	maxp = &a;
	
	cin >> a >> b >> c;
	
	if (*minp < b && *minp < c){
	}
	else if (*minp > b && b < c){
		minp = &b;
	}
	else if (*minp > c && c < b){
		minp = &c;
	}
	
	if (*maxp > b && *maxp > c){
	}
	else if (*maxp < b && b > c){
		maxp = &b;
	}
	else if (*maxp < c && c > b){
		maxp = &c;
	}
	
	cout << "Min: " << *minp << " " << minp << endl;
	cout << "Max: " << *maxp << " " << maxp << endl;
	
	return 0;
	
}