#include <iostream>
using namespace std;

struct makanan {
    string nama;
    int harga;
    makanan* next;
    makanan* prev;
};

class DoubleLinkedList {
private:
    makanan* head;
    makanan* tail;

public:
    DoubleLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Fungsi menambahkan makanan di akhir
    void insert_di_akhir(string nama, int harga) {
        makanan* newMakanan = new makanan;
        newMakanan->nama = nama;
        newMakanan->harga = harga;
        newMakanan->next = nullptr;

        if (head == nullptr) {
            head = newMakanan;
            tail = newMakanan;
            newMakanan->prev = nullptr;
        } else {
            tail->next = newMakanan;
            newMakanan->prev = tail;
            tail = newMakanan;
        }       
    }

    // Fungsi menghapus makanan di awal
    void hapus_di_awal() {
        if (head != nullptr) {
            makanan* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }
            delete temp;
        } else {
            cout << "Linked list makanan kosong." << endl;
        }
    }

    // Fungsi menghapus makanan di akhir
    void hapus_di_akhir() {
        if (tail != nullptr) {
            makanan* temp = tail;
            tail = tail->prev;
            if (tail != nullptr) {
                tail->next = nullptr;
            } else {
                head = nullptr;
            }
            delete temp;
        } else {
            cout << "Linked list makanan kosong." << endl;
        }
    }

    // Fungsi menghitung jumlah data/node
    int hitung_jumlah_data() {
        int count = 0;
        makanan* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    // Fungsi mengubah data di tengah
    void ubah_data_tengah(string nama_target, string nama_baru, int harga_baru) {
        makanan* current = head;
        while (current != nullptr) {
            if (current->nama == nama_target) {
                current->nama = nama_baru;
                current->harga = harga_baru;
                return;
            }
            current = current->next;
        }
        cout << "Makanan " << nama_target << " tidak ada." << endl;
    }

    // Fungsi mencetak semua makanan dalam Linked List
    void cetak_semua_makanan() {
        makanan* current = head;
        int i = 0;
        while (current != nullptr) {
            cout << i+1 << ". " << current->nama << " - " << current->harga << endl;
            current = current->next;
            i++;
        }
    }
};

int main() {
    cout << " PENERAPAN DOUBLE LINKED LIST" << endl;
    cout << "==============================" << endl;
    DoubleLinkedList linkedList;

    linkedList.insert_di_akhir("Soto Ayam", 15000);
    linkedList.insert_di_akhir("Bakso Urat", 17000);
    linkedList.insert_di_akhir("Iga Bakar", 40000);

    cout << "List Makanan dan Harga:" << endl;
    linkedList.cetak_semua_makanan();

    linkedList.hapus_di_awal();

    cout << "\nList makanan setelah penghapusan di awal:" << endl;
    linkedList.cetak_semua_makanan();

    linkedList.hapus_di_akhir();

    cout << "\nList makanan setelah penghapusan di awal dan di akhir:" << endl;
    linkedList.cetak_semua_makanan();

    int jumlah_data = linkedList.hitung_jumlah_data();
    cout << "\nJumlah data dalam Linked List: " << jumlah_data << endl;

    linkedList.ubah_data_tengah("Bakso Urat", "Ayam Goreng", 13000);

    cout << "\nList Makanan setelah mengubah data di tengah:" << endl;
    linkedList.cetak_semua_makanan();

    return 0;
}
