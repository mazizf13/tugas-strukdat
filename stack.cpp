#include <iostream>
using namespace std;

struct DataMakanan {
    string namaMakanan;
    int hargaMakanan;
    DataMakanan* prev;
    DataMakanan* next;
};

class MakananStack {
private:
    DataMakanan* head;
    DataMakanan* tail;
    int maksimalMakanan;

public:
    MakananStack(int maksimal) : maksimalMakanan(maksimal), head(NULL), tail(NULL) {}

    bool isFull() {
        return countMakanan() == maksimalMakanan;
    }

    bool isEmpty() {
        return head == NULL;
    }

    void push(string namaMakanan, int hargaMakanan) {
        if (!isFull()) {
            DataMakanan* newNode = new DataMakanan();
            newNode->namaMakanan = namaMakanan;
            newNode->hargaMakanan = hargaMakanan;
            newNode->prev = tail;
            newNode->next = NULL;

            if (isEmpty()) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            cout << "Fungsi: Push\n";
            cout << "Makanan '" << namaMakanan << "' berhasil ditambahkan ke dalam stack." << endl << endl;
        } else {
            cout << "Fungsi: Push\n";
            cout << "Stack penuh, tidak dapat menambahkan item." << endl << endl;
        }
    }

    void pop() {
        if (!isEmpty()) {
            cout << "Fungsi: Pop\n";
            cout << "Makanan '" << tail->namaMakanan << "' berhasil dihapus dari stack." << endl << endl;
            DataMakanan* del = tail;
            tail = tail->prev;
            delete del;
            if (tail == NULL) {
                head = NULL;
            } else {
                tail->next = NULL;
            }
        } else {
            cout << "Fungsi: Pop\n";
            cout << "Stack kosong, tidak dapat menghapus item." << endl << endl;
        }
    }

    void peek(int posisi) {
        if (!isEmpty()) {
            cout << "Fungsi: Peek\n";
            DataMakanan* cur = tail;
            int nomor = 1;
            while (cur != NULL && nomor < posisi) {
                cur = cur->prev;
                nomor++;
            }
            if (cur != NULL) {
                cout << "Data Makanan Posisi ke-" << posisi << " : " << cur->namaMakanan << " - Rp." << cur->hargaMakanan << endl << endl;
            } else {
                cout << "Posisi tidak valid." << endl << endl;
            }
        } else {
            cout << "Fungsi: Peek\n";
            cout << "Stack kosong." << endl << endl;
        }
    }

    int countMakanan() {
        int count = 0;
        DataMakanan* cur = head;
        while (cur != NULL) {
            cur = cur->next;
            count++;
        }
        return count;
    }

    void change(int posisi, string namaMakanan, int hargaMakanan) {
        if (!isEmpty()) {
            cout << "Fungsi: Change\n";
            DataMakanan* cur = tail;
            int nomor = 1;
            while (cur != NULL && nomor < posisi) {
                cur = cur->prev;
                nomor++;
            }
            if (cur != NULL) {
                cur->namaMakanan = namaMakanan;
                cur->hargaMakanan = hargaMakanan;
                cout << "Data Makanan pada posisi ke-" << posisi << " berhasil diubah." << endl << endl;
            } else {
                cout << "Posisi tidak valid." << endl << endl;
            }
        } else {
            cout << "Fungsi: Change\n";
            cout << "Stack kosong." << endl << endl;
        }
    }

    void display() {
        if (!isEmpty()) {
            cout << "Fungsi: Display\n";
            cout << "Isi stack (dari atas ke bawah): " << endl;
            DataMakanan* cur = tail;
            while (cur != NULL) {
                cout << "Data Makanan: " << cur->namaMakanan << " - Rp." << cur->hargaMakanan << endl;
                cur = cur->prev;
            }
            cout << endl;
        } else {
            cout << "Fungsi: Display\n";
            cout << "Stack kosong." << endl << endl;
        }
    }

    void destroy() {
        while (!isEmpty()) {
            pop();
        }
        cout << "Fungsi: Destroy\n";
        cout << "Stack berhasil dihapus." << endl << endl;
    }
};

int main() {
    MakananStack stack(5);
    stack.push("Nasi Goreng", 15000);
    stack.push("Bakso", 12000);
    stack.push("Sate", 18000);
    stack.display();
    stack.pop();
    stack.display();
    stack.peek(1);
    stack.change(1, "Mie Ayam", 13000);
    stack.display();
    stack.destroy();
    stack.display();

    return 0;
}
