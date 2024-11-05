#include <iostream>
using namespace std;

int partition(int arr[], int startidx, int endidx) {
    int pivotelement = arr[(startidx + endidx) / 2];
    int count = 0;
    for (int i = startidx; i <= endidx; i++) {
        if (arr[i] < pivotelement) count++;
    }
    int pivotidx = startidx + count;
    swap(arr[(startidx + endidx) / 2], arr[pivotidx]);

    int i = startidx, j = endidx;
    while (i < pivotidx && j > pivotidx) {
        while (arr[i] < pivotelement) i++;
        while (arr[j] > pivotelement) j--;
        if (i < pivotidx && j > pivotidx) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return pivotidx;
}

void QuickSort(int arr[], int startidx, int endidx) {
    if (startidx >= endidx) return;
    int pivotidx = partition(arr, startidx, endidx);
    QuickSort(arr, startidx, pivotidx - 1);
    QuickSort(arr, pivotidx + 1, endidx);
}

int main() {
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array before sorting: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    QuickSort(arr, 0, n - 1);

    cout << "Array after sorting: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
