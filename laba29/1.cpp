#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void word_3_letters()
{
	int c=0;
    ifstream fileread("text.txt");
	
	char *word = new char[100];
    while (fileread >> word)
		{
    		if (strlen(word) == 3)
			{
    			c++;
    		}
    	}
    
    fileread.close();
    
    ifstream fileread2("text.txt");
    
    int i=0;
    
    char **words_arr;
		words_arr = new char *[c];
    
    while (fileread2 >> word)
		{
    		if (strlen(word) == 3)
			{
    			words_arr[i] = new char[strlen(word)+1];
    		
	    		int j=0;
	    		while (word[j] != '\0' && j<99)
				{
	    			words_arr[i][j] = word[j];
	    			j++;
				}
			words_arr[i][j] = '\0';
			i++;
			}
    	}
    fileread2.close();
    
    delete []word;
    
    cout << "With 3 symvols: ";
    for (int i=0; i<c; i++)
		{
    		cout << words_arr[i] << ", ";
    		delete []words_arr[i];
		}
	delete []words_arr;
	cout << endl;
}

void word_1_lowwer(){
	int c = 0;
	
	ifstream fileread("text.txt");

    char *word = new char[100];
    while (fileread >> word){
    	if (islower(word[0])){
			c++;
		}
    }
    fileread.close();
    
    ifstream fileread2("text.txt");
    
    int i=0;
    
    char **words_arr;
	words_arr = new char *[c];
    
    while (fileread2 >> word)
	{
    	if (islower(word[0]))
		{
    		words_arr[i] = new char[strlen(word)+1];
    		
			int j=0;
	    	while (word[j] != '\0' && j<99)
			{
	    		words_arr[i][j] = word[j];
	    		j++;
			}
			words_arr[i][j] = '\0';
			i++;
		}
    }
    
    fileread2.close();
    
    delete []word;
    
    cout << "With 1st not upper symvol: ";
    for (int i=0; i<c; i++)
		{
    		cout << words_arr[i] << ", ";
    		delete []words_arr[i];
		}
	delete []words_arr;
	cout << endl;
}

void search_word(char searchWord[])
{
	int c=0;
    ifstream fileread("text.txt");

    char *word = new char[100];
    while (fileread >> word)
		{
    		c++;
    	}
    
    fileread.close();
    
    ifstream fileread2("text.txt");
    
    int i=0;
    
    char **words_arr;
	words_arr = new char *[c];
    
    while (fileread2 >> word){
    	words_arr[i] = new char[strlen(word)+1];
    	
    	int j=0;
	    while (word[j] != '\0' && j<99)
		{
	    	words_arr[i][j] = word[j];
	    	j++;
		}
		words_arr[i][j] = '\0';
		i++;
    }
    fileread2.close();
    
    delete []word;
	
	int check, c_w = 0;
	for (int i=0; i<c; i++)
	{
		if (strlen(words_arr[i]) == strlen(searchWord))
		{
			check = 0;
			for (int j=0; j<strlen(searchWord); j++)
				{
					if (tolower(words_arr[i][j]) != tolower(searchWord[j]))
					{
						check = 1;
					}
				}
				if (check==0)
			{
				c_w++;
			}
		}
	}
    
    for (int i=0; i<c; i++)
	{
    	delete []words_arr[i];
	}
	delete []words_arr;
	
	cout << "Word is repeated " << c_w << " times" << endl;
}

int main()
{
	word_3_letters();
	word_1_lowwer();
	
	char searchWord[100];
	cout << "Enter word for a search: ";
	cin >> searchWord;
	search_word(searchWord);
    
    return 0;
}
