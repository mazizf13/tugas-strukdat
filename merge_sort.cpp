#include <iostream>

void merge(double arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    double L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(double arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
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

    mergeSort(arr, 0, n - 1);

    std::cout << "Array setelah diurutkan: ";
    printArray(arr, n);

    delete[] arr;

    return 0;
}
