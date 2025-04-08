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

	for (int i = 0; i < n; i++) {
        int minIndx = 0; 
        	for (int j = 1; j < n; j++) {
            if (*(A[i] + j) < *(A[i] + minIndx)) 
				{
                minIndx = j;  
            	}
        }
        
        cout << minIndx << " ";  
    }
    cout << endl;

    return 0;
}
