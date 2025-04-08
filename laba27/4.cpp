#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int findMin(int *arr, int n) 
{
    int minVal = arr[0];
    for (int i = 1; i < n; i++) 
	{
        if (arr[i] < minVal) 
		{
            minVal = arr[i];
        }
    }
    return minVal;
}

int findMax(int *arr, int n) 
{
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) 
	{
        if (arr[i] > maxVal) 
		{
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int main() 
{
    int n;
    
    cout << "Enter n: ";
    cin >> n;

    int *a = new int[n];

    srand(time(0));
    
    for (int i = 0; i < n; i++) 
	{
        a[i] = -2 + rand() % 6;
    }

    for (int i = 0; i < n; i++)
	{
        cout << a[i] << " ";
    }
    cout << endl;

    int new_n = n;
    for (int i = 0; i < n; i++) 
	{
        if (a[i] < 0) 
		{
            new_n++;
        }
    }

    int *b = new int[new_n];
    int res_i = 0, min, max; 

    for (int i = 0; i < n; i++) 
	{
        b[res_i] = a[i];
        res_i++;

        if (a[i] < 0)
		{
            min = findMin(b, res_i - 1);
            max = findMax(b, res_i - 1);
            cout << min << " " << max << endl;
            b[res_i] = min + max;
            res_i++;
        }
    }

    for (int i = 0; i < res_i; i++) 
	{
        cout << b[i] << " ";
    }
    cout << endl;

    delete[] a;
    delete[] b;

    return 0;
}
