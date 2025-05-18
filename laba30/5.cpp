#include <iostream>
#include <cstdlib>  
#include <ctime>    
using namespace std;

void findMismatchIndices(int a[], int b[], int indices[], int count) {
    bool mismatchFound = false;

    for (int i = 0; i < count; i++) {
        int index = indices[i];
        if (a[index] != b[index]) {
            if (mismatchFound) {
                cout << ",";
            }
            cout << index;
            mismatchFound = true;
        }
    }

    if (!mismatchFound) {
        cout << "Don''t any matches!";
    }

    cout << endl;
}

int main() {
    int size = 12;
    int a[size];
    int b[size];

    srand(time(0));

    for (int i = 0; i < size; i++) {
        a[i] = rand() % 3 + 1;
        b[i] = rand() % 3 + 1;
    }

    int indices[] = {1, 4, 5, 9, 10};
    int count = sizeof(indices) / sizeof(indices[0]);

    cout << "a: ";
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "b: ";
    for (int i = 0; i < size; i++) {
        cout << b[i] << " ";
    }
    cout << endl;

    cout << "Indexes where values dont matches: ";
    findMismatchIndices(a, b, indices, count);

    return 0;
}
