#include <iostream>

void insertionSort(double arr[], int n) {
    int i, j;
    double key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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

    insertionSort(arr, n);

    std::cout << "Array setelah diurutkan: ";
    printArray(arr, n);

    delete[] arr;

    return 0;
}
