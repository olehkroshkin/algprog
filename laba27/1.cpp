#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	int n, m;
	
	cout << "Enter n: ";
		cin >> n;
	cout << "Enter m: ";
		cin >> m;
		
	int *a = new int[n];
	int *b = new int[m];
	
	int not_mult3_a = 0;
	int not_mult3_b = 0;
	
	srand(time(0));
	for (int i=0; i<n; i++)
	{
		a[i] = -10 + (rand() % 21);
			cout << a[i] << " ";
			if (a[i] % 3 != 0)
		{
			not_mult3_a++;
		}
	}
	cout << endl;
	
	for (int i=0; i<m; i++)
	{
		b[i] = -10 + (rand() % 21);
			cout << b[i] << " ";
			if (b[i] % 3 != 0)
		{
			not_mult3_b++;
		}
	}
	cout << endl;
	cout << endl;
	
	if (not_mult3_a > not_mult3_b)
	{
		for (int i=0; i<n; i++)
		{
			cout << a[i] << " ";
		}
	}
	else if (not_mult3_a < not_mult3_b)
	{
		for (int i=0; i<m; i++)
		{
			cout << b[i] << " ";
		}
	}
	else{
		for (int i=0; i<n; i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;
		for (int i=0; i<m; i++)
		{
			cout << b[i] << " ";
		}
	}
	
	delete []a;
	delete []b;
		
	return 0;
}
