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
        if (i % 2 == 0) {
       
    for (int j = 0; j < n; j++)
			{
        	cout << *(A[i] + j) << " "; 
        	}
        
        		} 
				else 
				{
      
            		for (int j = n - 1; j >= 0; j--) 
						{
            			cout << *(A[i] + j) << " "; 
            			}
        }
    }

    return 0;
}
