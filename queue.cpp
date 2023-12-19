#include <iostream>
using namespace std;

struct antrianBarang {
    string namaBarang;
    double harga;
    antrianBarang* next;
};

int maksimalAntrianLL = 3;
antrianBarang* head = nullptr;
antrianBarang* tail = nullptr;
antrianBarang* cur = nullptr;
antrianBarang* del = nullptr;
antrianBarang* newNode = nullptr;

int countLL() {
    if (head == nullptr) {
        return 0;
    } else {
        int banyak = 0;
        cur = head;
        while (cur != nullptr) {
            cur = cur->next;
            banyak++;
        }
        return banyak;
    }
}

bool isFullLL() {
    return countLL() == maksimalAntrianLL;
}

bool isEmptyLL() {
    return countLL() == 0;
}

void enqueueLL(string namaBarang, double harga) {
    if (isFullLL()) {
        cout << "Antrian Penuh!" << endl;
    } else {
        if (isEmptyLL()) {
            head = new antrianBarang();
            head->namaBarang = namaBarang;
            head->harga = harga;
            head->next = nullptr;
            tail = head;
        } else {
            newNode = new antrianBarang();
            newNode->namaBarang = namaBarang;
            newNode->harga = harga;
            newNode->next = nullptr;
            tail->next = newNode;
            tail = newNode;
        }
    }
}

void dequeueLL() {
    if (isEmptyLL()) {
        cout << "Data Antrian Kosong!" << endl;
    } else {
        del = head;
        head = head->next;
        del->next = nullptr;
        delete del;
    }
}

void clearLinkedList() {
    if (isEmptyLL()) {
        cout << "Data Antrian Kosong!!" << endl;
    } else {
        cur = head;
        while (cur != nullptr) {
            del = cur;
            cur = cur->next;
            del->next = nullptr;
            delete del;
        }
        head = nullptr;
        tail = nullptr;
    }
}

void displayLL() {
    cout << "Data Antrian Barang : " << endl;
    if (isEmptyLL()) {
        cout << "Data Antrian Kosong!!" << endl;
    } else {
        cout << "Banyak data antrian : " << countLL() << endl;
        cur = head;
        int nomor = 1;
        while (nomor <= maksimalAntrianLL) {
            if (cur != nullptr) {
                cout << nomor << ". " << cur->namaBarang << " - Rp " << cur->harga << endl;
                cur = cur->next;
            } else {
                cout << nomor << ". " << "(kosong)" << endl;
            }
            nomor++;
        }
    }
    cout << "\n" << endl;
}

int main() {
    enqueueLL("Buku", 50000.0);
    enqueueLL("Pensil", 2000.0);
    enqueueLL("Gelang", 10000.0);
    displayLL();

    dequeueLL();
    displayLL();

    enqueueLL("Sepatu", 150000.0);
    displayLL();

    clearLinkedList();
    displayLL();

    return 0;
}
