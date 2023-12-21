#include <iostream>

void shellSort(double arr[], int n) {
    for (int selang = n / 2; selang > 0; selang /= 2) {
        for (int i = selang; i < n; i++) {
            double temp = arr[i];
            int j;
            for (j = i; j >= selang && arr[j - selang] > temp; j -= selang) {
                arr[j] = arr[j - selang];
            }
            arr[j] = temp;
        }
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

    shellSort(arr, n);

    std::cout << "Array setelah diurutkan: ";
    printArray(arr, n);

    delete[] arr;

    return 0;
}
