#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

void sortArray(int arr_for_sort[], int n){
	int swap_el;
	
	for (int i=0; i<n; i++) {
		for (int j=i; j<n; j++){
			if (arr_for_sort[i] < arr_for_sort[j]){
				swap_el = arr_for_sort[i];
				arr_for_sort[i] = arr_for_sort[j];
				arr_for_sort[j] = swap_el;
			}
		}
	}	
}

void sortMatrix(int **matrix, int n){
	int arr_for_sort[n];
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++){
			arr_for_sort[j] = matrix[i][j];
		}
		sortArray(arr_for_sort, n);
		for (int j=0; j<n; j++){
			matrix[i][j] = arr_for_sort[j];
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
			a[i][j] = 100 + rand() % 900;
		}
	}
	
	showMatrix(a, n);
	sortMatrix(a, n);
	
	ofstream outFile("output_3.txt");
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++){
			outFile << a[i][j] << " ";
		}
		outFile << endl;
    }
	outFile.close();
	
	showMatrix(a, n);
	
	for (int i=0; i<n; i++){
		delete []a[i];
	}
	
	delete []a;
	
	return 0;
}