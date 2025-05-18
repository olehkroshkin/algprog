#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void inputArray(int arr[], int n) {
    int choice;
    cout << "Choose method to create array:\n1 - Manual\n2 - Random\nYour choice: ";
    cin >> choice;

    if (choice == 1) {
        for (int i = 0; i < n; i++) {
            cout << "arr[" << i << "] = ";
            cin >> arr[i];
        }
    } else {
        srand(time(0));
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 21 - 10;  
        }
        cout << "Array generated randomly.\n";
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int findMin(int arr[], int n) {
    int minVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] < minVal)
            minVal = arr[i];
    return minVal;
}

int findMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];
    return maxVal;
}


int removeExtraMinMax(int arr[], int n) {
    int minVal = findMin(arr, n);
    int maxVal = findMax(arr, n);
    bool minFound = false, maxFound = false;
    int newSize = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == minVal) {
            if (!minFound) {
                arr[newSize++] = arr[i];
                minFound = true;
            }
        } else if (arr[i] == maxVal) {
            if (!maxFound) {
                arr[newSize++] = arr[i];
                maxFound = true;
            }
        } else {
            arr[newSize++] = arr[i];
        }
    }
    return newSize;
}


void shiftMinToFront(int arr[], int n) {
    int minIdx = 0;
    for (int i = 1; i < n; i++)
        if (arr[i] < arr[minIdx])
            minIdx = i;

    int temp[100];
    int idx = 0;

    for (int i = minIdx; i < n; i++)
        temp[idx++] = arr[i];
    for (int i = 0; i < minIdx; i++)
        temp[idx++] = arr[i];

    for (int i = 0; i < n; i++)
        arr[i] = temp[i];
}


int deleteAroundMinMax(int arr[], int n) {
    int minIdx = 0, maxIdx = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[minIdx]) minIdx = i;
        if (arr[i] > arr[maxIdx]) maxIdx = i;
    }

  
    int start = min(minIdx, maxIdx);
    int end = max(minIdx, maxIdx);

    
    int newSize = 0;

    
    for (int i = start; i <= end; i++) {
        arr[newSize++] = arr[i]; 
    }
    return newSize;
}


int createEvenOrOddArray(int arr[], int n, int result[]) {
    int evenCount = 0, oddCount = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) evenCount++;
        else oddCount++;
    }

    int idx = 0;
    for (int i = 0; i < n; i++) {
        if ((oddCount > evenCount && arr[i] % 2 != 0) ||
            (evenCount >= oddCount && arr[i] % 2 == 0)) {
            result[idx++] = arr[i];
        }
    }
    return idx;
}

int main() {
    const int MAX_SIZE = 100;
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int arr[MAX_SIZE];
    inputArray(arr, n);

    cout << "Start array:\n";
    printArray(arr, n);

    n = removeExtraMinMax(arr, n);
    cout << "After deleting MIN/MAX:\n";
    printArray(arr, n);

    shiftMinToFront(arr, n);
    cout << "After shifting MIN to start:\n";
    printArray(arr, n);

	return 0;
}
