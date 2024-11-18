#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void CreateArrayWithRandomElements(int* a, int numberOfElements, int start, int end, int i) {
    a[i] = start + rand() % (end - start + 1);
    if (i < numberOfElements - 1) {
        CreateArrayWithRandomElements(a, numberOfElements, start, end, i + 1);
    }
}

void PrintArray(int* a, int size, int i) {
    cout << "a[" << setw(2) << i << " ] = " << setw(4) << a[i] << endl;
    if (i < size - 1) {
        PrintArray(a, size, i + 1);
    }
    else {
        cout << endl;
    }
}

int CountAndSumElements(int* a, int size, int& sum, int i) {
    if (i >= size) {
        return 0;
    }
    int count = 0;
    if (a[i] < 0 && a[i] % 2 == 0) {
        count++; 
        sum += a[i];
    }
    return count + CountAndSumElements(a, size, sum, i + 1);
}

void ReplaceElementsWithZero(int* a, int size, int i) {
    if (i >= size) {
        return;
    }
    if (a[i] < 0 && a[i] % 2 == 0) {
        a[i] = 0;
    }
    ReplaceElementsWithZero(a, size, i + 1);
}

int main() {
    srand((unsigned)time(NULL));

    const int size = 20;
    int array[size];
    int sum = 0;

    CreateArrayWithRandomElements(array, size, -20, 34, 0);

    cout << "Original array:" << endl;
    PrintArray(array, size, 0);

    int count = CountAndSumElements(array, size, sum, 0);
    ReplaceElementsWithZero(array, size, 0);

    cout << "\nModified array:" << endl;
    PrintArray(array, size, 0);

    cout << "\nCount: " << count << ", Sum: " << sum << endl;
    return 0;
}
