#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() 
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    int *a = new int[n];
    int even_c = 0;

    srand(time(0));

    for (int i = 0; i < n; i++) 
	{
        a[i] = -10 + rand() % 21;
        cout << a[i] << " ";
        if (a[i] % 2 == 0)
		{
        	even_c++;
		}
    }
    cout << endl;

    int *b = new int[even_c];
    int res_i = 0, swap_el;

    for (int i = 0; i < n; i++)
	{
    	if (a[i] % 2 == 0){
	    	for (int j=i; j<n; j++)
			{
	    		if (a[j] % 2 == 0)
				{
	    			if (a[i] > a[j])
					{
		    			swap_el = a[i];
		    			a[i] = a[j];
		    			a[j] = swap_el;
		    		}
				}
			}
			b[res_i] = a[i];
    		res_i++;
    	}
    }
    
    for (int i=0; i<even_c; i++)
	{
    	cout << b[i] << " ";
	}

    delete []a;
    delete []b;

    return 0;
}
