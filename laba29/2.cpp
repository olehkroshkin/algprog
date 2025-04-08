#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <cstdlib>

using namespace std;

int main()
{
	int n;
	char not_vovels[] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'z'};
	char vovels[] = {'a', 'e', 'i', 'o', 'u', 'y'};
	
	cout << "Enter n: ";
		cin >> n;
	
	char **arr = new char *[n];
	
	srand(time(0));
	for (int i=0; i<n; i++)
	{
		arr[i] = new char [n];
			for (int j=0; j<n; j++)
		{
			if (i==j || i+j == n-1)
			{
				arr[i][j] = vovels[0 + (rand() % 6)];
			}
			else
			{
				arr[i][j] = not_vovels[0 + (rand() % 20)];
			}
		}
	}
	
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	char searchWord[n];
	cout << "Enter word: ";
    cin >> searchWord;
    
    int check, len = strlen(searchWord);
    
    for (int i=0; i<n; i++)
	{
    	for (int j=0; j<=n-len; j++)
		{
    		check = 0;
    		for (int k=0; k<len; k++)
			{
    			if (arr[i][k+j] != searchWord[k])
				{
    				check = 1;
    				break;
				}
			}
			if (check == 0)
			{
				cout << "Row type word" << endl;
				cout << i << "." << j << " - " << i << "." << j+len-1 << endl;
			}
		}
	}
	
	for (int i=0; i<n; i++)
	{
    	for (int j=0; j<=n-len; j++)
		{
    		check = 0;
    			for (int k=0; k<len; k++)
			{
    			if (arr[k+j][i] != searchWord[k])
				{
    				check = 1;
    				break;
				}
			}
			if (check == 0)
			{
				cout << "col type word" << endl;
				cout << j << "." << i << " - " << j+len-1 << "." << i << endl;
			}
		}
	}
	
	for (int i=0; i<n; i++)
	{
    	delete []arr[i];
	}
	delete []arr;
    
    return 0;
}

