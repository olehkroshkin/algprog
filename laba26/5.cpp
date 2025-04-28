#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int A[n][n];

    cout << "Enter elements: " << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int* pi = &A[i][i];
            int* pj = &A[j][j];
            if (*pi > *pj) {
                int temp = *pi;
                *pi = *pj;
                *pj = temp;
            }
        }
    }

    cout << "Array after sorting: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << A[i][j] << "\t";
        cout << endl;
    }

    return 0;
}
