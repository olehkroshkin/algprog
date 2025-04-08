#include <iostream>

using namespace std;

int main() 
{
    int n;
    
    cout << "Enter array size:";
    cin >> n;
    
    	int A[n][n];
    
    cout << "Enter array elements: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    
    	int maxMain = A[0][0];   
    	int minSide = A[0][n-1];
    
    for (int i = 0; i < n; i++) {
        
        if (A[i][i] > maxMain) 	
		{
        maxMain = A[i][i];
        }
        
        if (A[i][n-i-1] < minSide) 
		{
        minSide = A[i][n-i-1];
        }
    }
    
    	cout << "Max element of main diagonal: " << maxMain << endl;
    	cout << "Max element of side diagonal: " << minSide << endl;
    	cout << "Difference between diagonals: " << maxMain - minSide << endl;

    return 0;
}
