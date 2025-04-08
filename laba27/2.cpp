#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int *createResArr(int *a, int n, int &m)
{
    m = 0;

    for (int i = 0; i < n; i++) 
	{
        if (a[i] % 2 == 0 && (i+1)%2!=0)
		{
            m++;
        }
    }

    int* b = new int[m];
    int j = 0;

    for (int i = 0; i < n; i += 2) 
	{
        if (a[i] % 2 == 0) 
		{
            b[j++] = a[i];
        }
    }

    return b;
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
        a[i] = -10 + rand() % 21;
        cout << a[i] << " ";
    }
    cout << endl;

    int m;
    int *b = createResArr(a, n, m);

    for (int i = 0; i < m; i++) 
	{
        cout << b[i] << " ";
    }
    cout << endl;

    delete[] a;
    delete[] b;

    return 0;
}
