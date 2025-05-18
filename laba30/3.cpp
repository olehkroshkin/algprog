#include <iostream>
#include <algorithm> 
#include <cstdlib>  
#include <ctime>     

using namespace std;


void generateB(int a[], int b[], int sizeA, int sizeB) {
 
    int temp[12];
    for (int i = 0; i < sizeA; ++i) {
        temp[i] = a[i];
    }

    for (int i = sizeA - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        swap(temp[i], temp[j]);
    }

    for (int i = 0; i < sizeB; ++i) {
        b[i] = temp[i];
    }
}

int main() {
    const int sizeA = 12;
    const int sizeB = 8;

    
    int a[sizeA] = {13, 4, 2, 28, 34, 7, 10, 21, 43, 50, 37, 11};
    int b[sizeB];


    srand(time(0));
    generateB(a, b, sizeA, sizeB);

    cout << "Array A: ";
    for (int i = 0; i < sizeA; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "Array B: ";
    for (int i = 0; i < sizeB; ++i) {
        cout << b[i] << " ";
    }
    cout << endl;

    return 0;
}
