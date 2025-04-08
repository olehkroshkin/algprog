#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int columnDown(int **a, int n) {
    int check, c = 0;
    for (int i = 0; i < n; i++) {
        check = 0;
        for (int j = 1; j < n; j++) {
            if (a[j][i] > a[j-1][i]) {
                check = 1;
                break; 
            }
        }
        if (check == 0) {
            c++;
        }
    }
    return c;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Bad value of N:" << endl;
        return 1;
    }

    int **a = new int*[n];
    if (!a) {
        cout << "Error with memory!" << endl;
        return 1;
    }

    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
        if (!a[i]) {
            cout << "Error with memory!" << endl;
            return 1;
        }
    }

    cout << "Enter matrix elements: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    cout << "\nResult: " << columnDown(a, n) << endl;

    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}

