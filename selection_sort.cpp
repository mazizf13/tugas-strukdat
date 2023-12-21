#include <iostream>

void selectionSort(double arr[], int n) {
    int i, j, minIndex;
    double temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void printArray(double arr[], int size) {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main() {
    int n;

    std::cout << "Masukkan jumlah elemen array: ";
    std::cin >> n;

    double *arr = new double[n];

    std::cout << "Masukkan elemen array:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "Elemen " << i + 1 << ": ";
        std::cin >> arr[i];
    }

    std::cout << "Array sebelum diurutkan: ";
    printArray(arr, n);

    selectionSort(arr, n);

    std::cout << "Array setelah diurutkan: ";
    printArray(arr, n);

    delete[] arr;

    return 0;
}
