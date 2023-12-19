#include <iostream>
using namespace std;

#define YELLOW_TEXT "\033[33m"
#define RESET_COLOR "\033[0m"

struct Mahasiswa {
    string nama, npm;
    int usia;
    Mahasiswa *next;
};

Mahasiswa *head, *tail, *cur, *newNode, *del;

void createSLL(string nama, string npm, int usia) {
    head = new Mahasiswa();
    head->nama = nama;
    head->npm = npm;
    head->usia = usia;
    head->next = NULL;
    tail = head;
}

void addFirst(string nama, string npm, int usia) {
    newNode = new Mahasiswa();
    newNode->nama = nama;
    newNode->npm = npm;
    newNode->usia = usia;
    newNode->next = head;
    head = newNode;
}

void addMiddle(string nama, string npm, int usia, int position) {
    if (position < 1) {
        cout << "Invalid position." << endl;
        return;
    }
    newNode = new Mahasiswa();
    newNode->nama = nama;
    newNode->npm = npm;
    newNode->usia = usia;
    cur = head;
    for (int i = 1; i < position - 1 && cur != NULL; ++i) {
        cur = cur->next;
    }
    if (cur == NULL) {
        cout << "Position out of bounds." << endl;
        return;
    }
    newNode->next = cur->next;
    cur->next = newNode;
}

void addLast(string nama, string npm, int usia) {
    newNode = new Mahasiswa();
    newNode->nama = nama;
    newNode->npm = npm;
    newNode->usia = usia;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
}

void changeFirst(string nama, string npm, int usia) {
    if (head != NULL) {
        head->nama = nama;
        head->npm = npm;
        head->usia = usia;
    } else {
        cout << "List is empty." << endl;
    }
}

void changeMiddle(string nama, string npm, int usia, int position) {
    if (position < 1) {
        cout << "Invalid position." << endl;
        return;
    }
    cur = head;
    for (int i = 1; i < position && cur != NULL; ++i) {
        cur = cur->next;
    }
    if (cur == NULL) {
        cout << "Position out of bounds." << endl;
        return;
    }
    cur->nama = nama;
    cur->npm = npm;
    cur->usia = usia;
}

void changeLast(string nama, string npm, int usia) {
    if (tail != NULL) {
        tail->nama = nama;
        tail->npm = npm;
        tail->usia = usia;
    } else {
        cout << "List is empty." << endl;
    }
}

void deleteFirst() {
    if (head != NULL) {
        del = head;
        head = head->next;
        delete del;
    } else {
        cout << "List is empty." << endl;
    }
}

void deleteMiddle(int position) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    if (position < 1) {
        cout << "Invalid position." << endl;
        return;
    }
    cur = head;
    Mahasiswa *prev = NULL;
    for (int i = 1; i < position && cur != NULL; ++i) {
        prev = cur;
        cur = cur->next;
    }
    if (cur == NULL) {
        cout << "Position out of bounds." << endl;
        return;
    }
    if (prev == NULL) {
        head = cur->next;
    } else {
        prev->next = cur->next;
    }
    delete cur;
}

void deleteLast() {
    if (head != NULL) {
        if (head == tail) {
            delete head;
            head = NULL;
              tail = NULL;
        } else {
            cur = head;
            while (cur->next != tail) {
                cur = cur->next;
            }
            delete tail;
            tail = cur;
            tail->next = NULL;
        }
    } else {
        cout << "List is empty." << endl;
    }
}

void cetakSLL() {
    cur = head;
    while (cur != NULL) {
        cout << "Nama Mhs : " << cur->nama << endl;
        cout << "NPM Mhs : " << cur->npm << endl;
        cout << "Usia Mhs : " << cur->usia << endl;
        cur = cur->next;
    }
}

int main() {
    cout << YELLOW_TEXT << "=== CREATE SSL ===" << RESET_COLOR << endl;
    createSLL("Yusron", "2008180004", 20);
    cetakSLL();
    cout << "\n";

    cout << YELLOW_TEXT << "=== ADD FIRST ===" << RESET_COLOR << endl;
    addFirst("Sarah", "2008180014", 17);
    cetakSLL();
    cout << "\n";

    cout << YELLOW_TEXT << "=== ADD MIDDLE ===" << RESET_COLOR << endl;
    addMiddle("Aziz", "22081010030", 19, 2);
    cetakSLL();
    cout << "\n";

    cout << YELLOW_TEXT << "=== ADD LAST ===" << RESET_COLOR << endl;
    addLast("Vendy", "2008180024", 18);
    cetakSLL();
    cout << "\n";

    cout << YELLOW_TEXT << "=== CHANGE FIRST ===" << RESET_COLOR << endl;
    changeFirst("Putri", "2008180034", 18);
    changeLast("Sandy", "2008180044", 18);
    cetakSLL();
    cout << "\n";

    cout << YELLOW_TEXT << "=== CHANGE MIDDLE ===" << RESET_COLOR << endl;
    changeMiddle("Asep", "22081010020", 20, 2);
    changeMiddle("Rafi", "22081010234", 20, 3);
    cetakSLL();
    cout << "\n";

    cout << YELLOW_TEXT << "=== CHANGE LAST ===" << RESET_COLOR << endl;
    changeLast("Jojo", "2008180343", 18);
    cetakSLL();
    cout << "\n";

    cout << YELLOW_TEXT << "=== DELETE FIRST ===" << RESET_COLOR << endl;
    deleteFirst();
    cetakSLL();
    cout << "\n";

    cout << YELLOW_TEXT << "=== DELETE MIDDLE ===" << RESET_COLOR << endl;
    deleteMiddle(2);
    cetakSLL();
    cout << "\n";

    cout << YELLOW_TEXT << "=== DELETE LAST ===" << RESET_COLOR << endl;
    deleteLast();
    cetakSLL();
    cout << "\n";

    return 0;
}
