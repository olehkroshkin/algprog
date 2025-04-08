#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(){
	int n;
	
	cout << "Enter n: ";
		cin >> n;
	
	int **a;
		a = new int*[n];
	
	int avg = 0;
	
	srand(time(0));
	for (int i=0; i<n; i++)
	{
		a[i] = new int[n];
		for (int j=0; j<n; j++)
		{
			a[i][j] = -10 + rand() % 21;
			avg += a[i][j];
		}
	}
	avg = avg/(n*n);
	
	cout << avg << endl;
	
	int *res_arr = new int[n];
		int c;
	
	for (int i=0; i<n; i++)
	{
		c = 0;
		for (int j=0; j<n; j++)
		{
			if (avg > a[i][j])
			{
				c++;
			}
			cout << a[i][j] << " ";
		}
		cout << endl;
		res_arr[i] = c;
	}
	cout << endl;
	
	for (int i=0; i<n; i++)
	{
		delete []a[i];
	}
	
	delete []a;
	
	ofstream outFile("output_1.txt");
	
	for (int i=0; i<n; i++)
	{
		cout << res_arr[i] << " ";
		outFile << res_arr[i] << " ";
	}
	outFile.close();
	
	delete []res_arr;
	
	return 0;
}
