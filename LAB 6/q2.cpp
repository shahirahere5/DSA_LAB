#include <iostream>
using namespace std;

void shellSort(int array[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = array[i];
            int j;
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
}

int main() {
int array[] = {32,25,40,12,18,50,28};
int size = sizeof(array) / sizeof(array[0]);

cout << "unsorted array:" << endl;
for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
}
cout << endl;
cout << "----------" << endl;

shellSort(array, size);
cout << "Sorted array:" << endl;
for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
}
cout << endl;
return 0;
}