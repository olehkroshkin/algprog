#include <iostream>
#include <cstdlib>  
#include <ctime>    

using namespace std;


void createBArray(int a[], int b[], int i1, int i2) {
    int indexB = 0;
    for (int i = i1; i <= i2; i++) {
        b[indexB++] = a[i];
    }
}

void generateRandomArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        a[i] = rand() % 50 + 1;  
    }
}

int main() {
    const int sizeA = 12;
    int a[sizeA];
    
    srand(time(0));

    generateRandomArray(a, sizeA);


    cout << "Array A: ";
    for (int i = 0; i < sizeA; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    int i1 = 4, i2 = 10;

    int sizeB = i2 - i1 + 1;
    int b[sizeB];

    createBArray(a, b, i1, i2);

    cout << "Array B: ";
    for (int i = 0; i < sizeB; i++) {
        cout << b[i] << " ";
    }
    cout << endl;

    return 0;
}
