#include <iostream>
#include <ctime>

using namespace std;

bool check2digits(int x){
	int f, s;
	f = x/10;
	s = x%10;
	
	if (f==s){
		return 1;
	}
	else return 0;
}

void sumColumns(int **matrix, int n){
	int check, sum;
	for (int i=0; i<n; i++){
		check = 0;
		for (int j=0; j<n; j++){
			if (check2digits(matrix[j][i]) == 1){
				check = 1;
			}
		}
		if (check == 0){
			sum = 0;
			for (int j=0; j<n; j++){
				sum += matrix[j][i];
			}
			cout << sum << " " << i << endl;
		}
	}
}

void showMatrix(int **matrix, int n){
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
    }
    cout << endl;
}

int main(){
	int n;
	
	cout << "Enter n: ";
	cin >> n;
	
	int **a;
	a = new int*[n];
	
	srand(time(0));
	for (int i=0; i<n; i++){
		a[i] = new int[n];
		for (int j=0; j<n; j++){
			a[i][j] = 10 + rand() % 50;
		}
	}
	
	showMatrix(a, n);
	
	sumColumns(a, n);
	
	for (int i=0; i<n; i++){
		delete []a[i];
	}
	
	delete []a;
	
	return 0;
}