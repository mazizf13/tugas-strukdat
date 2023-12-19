#include <iostream>
#include <string>

struct Makanan {
    std::string nama;
    double harga;
};

struct Node {
    Makanan data;
    Node* next;
};

Node* head = nullptr;

void insertDiAkhir(std::string nama, double harga) {
    Node* newNode = new Node();
    newNode->data.nama = nama;
    newNode->data.harga = harga;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void hapusDiAwal() {
    if (head == nullptr) {
        std::cout << "List kosong. Tidak dapat menghapus.\n";
    } else {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void hapusDiAkhir() {
    if (head == nullptr) {
        std::cout << "List kosong. Tidak dapat menghapus.\n";
    } else if (head->next == nullptr) {
        delete head;
        head = nullptr;
    } else {
        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }
}

int hitungJumlahData() {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

void ubahDataDiTengah(std::string targetNama, double newHarga) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data.nama == targetNama) {
            current->data.harga = newHarga;
            std::cout << "Data berhasil diubah.\n";
            return;
        }
        current = current->next;
    }
    std::cout << "Data tidak ditemukan.\n";
}

void tampilkanList() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << "Nama: " << current->data.nama << ", Harga: " << current->data.harga << std::endl;
        current = current->next;
    }
}

int main() {
    insertDiAkhir("Nasi Goreng", 12.5);
    insertDiAkhir("Mie Goreng", 10.0);
    insertDiAkhir("Sate Ayam", 15.75);

    std::cout << "List Awal:\n";
    tampilkanList();
    std::cout << "Jumlah data: " << hitungJumlahData() << std::endl;

    hapusDiAwal();
    std::cout << "\nSetelah menghapus di awal:\n";
    tampilkanList();
    std::cout << "Jumlah data: " << hitungJumlahData() << std::endl;

    hapusDiAkhir();
    std::cout << "\nSetelah menghapus di akhir:\n";
    tampilkanList();
    std::cout << "Jumlah data: " << hitungJumlahData() << std::endl;

    ubahDataDiTengah("Mie Goreng", 11.0);
    std::cout << "\nSetelah mengubah data di tengah:\n";
    tampilkanList();

    // Hapus sisa node yang tersisa
    while (head != nullptr) {
        hapusDiAwal();
    }

    return 0;
}
