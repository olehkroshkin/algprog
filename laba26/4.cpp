#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int A[n][n];
    cout << "Enter elements:" << endl;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    int* p = &A[0][0]; 

    int posSum = 0, posCount = 0;
    int negSum = 0, negCount = 0;
    int zeroCount = 0;

    for (int i = 0; i < n * n; i++) {
        if (*(p + i) > 0) {
            posSum += *(p + i);
            posCount++;
        } else if (*(p + i) < 0) {
            negSum += *(p + i);
            negCount++;
        } else {
            zeroCount++;
        }
    }

    if (posCount)
        cout << "Average of positive numbers: " << (float)posSum / posCount << endl;
    else
        cout << "No positive numbers." << endl;

    if (negCount)
        cout << "Average of negative numbers: " << (float)negSum / negCount << endl;
    else
        cout << "No negative numbers." << endl;

    cout << "Number of zeros: " << zeroCount << endl;

    return 0;
}
