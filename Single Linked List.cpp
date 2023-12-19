#include <iostream>
using namespace std;

struct makanan {
    string nama;
    int harga;
    makanan* next;
};

class SingleLinkedList {
private:
    makanan* head;

public:
    SingleLinkedList() {
        head = nullptr;
    }

    // Fungsi menambahkan makanan di akhir
    void insert_di_akhir(string nama, int harga) {
        makanan* newMakanan = new makanan;
        newMakanan->nama = nama;
        newMakanan->harga = harga;
        newMakanan->next = nullptr;

        if (head == nullptr) {
            head = newMakanan;
        } else {
            makanan* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newMakanan;
        }
    }

    // Fungsi  menghapus makanan di awal
    void hapus_di_awal() {
        if (head != nullptr) {
            makanan* temp = head;
            head = head->next;
            delete temp;
        } else {
            cout << "Linked list makanan kosong." << endl;
        }
    }

    // Fungsi menghapus makanan di akhir
    void hapus_di_akhir() {
        if (head == nullptr) {
            cout << "Linked Linked list makanan kosong." << endl;
            return;
        } else if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        makanan* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }

    // Fungsi menghitung jumlah data
    int hitung_jumlah_data() {
        int count = 0;
        makanan* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    // Fungsi  mengubah data di tengah
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

    cout << " PENERAPAN SINGLE LINKED LIST" << endl;
    cout << "==============================" << endl;
    SingleLinkedList linkedList;

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
