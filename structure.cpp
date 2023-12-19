// #include <iostream>
// using namespace std;

// struct kampus {
//     string namaKampus;
//     int TB;
// };

// struct mahasiswa {
//     string npm, nama, jurusan;
//     int usia;
//     string hobi[2];
// };

// int main() {
// 	return 0;
// }


// #include <iostream>
// using namespace std;

// // Cara 1 (Global)
// struct Kampus {
//     string namaKampus;
//     int TB;
// } kampus1, kampus2;

// struct Mahasiswa {
//     string npm, nama, jurusan;
//     int usia;
//     string hobi[2];
// } mhs1, mhs2;

// int main() {
//     // Cara 2 (Lokal)
//     Kampus kampus3;
//     Mahasiswa mhs3;

//     return 0;
// }


// #include <iostream>
// using namespace std;

// struct Kampus {
//     string namaKampus;
//     int TB;
// } kampus1, kampus2;

// struct Mahasiswa {
//     string npm, nama, jurusan;
//     int usia;
//     string hobi[2];
// } mhs1, mhs2;

// int main() {
//     Kampus kampus3;
//     Mahasiswa mhs3;

//     kampus1.namaKampus = "UPN \"VETERAN\" JAWA TIMUR";
//     kampus1.TB = 160;

//     mhs1.npm = "22081010030";
//     mhs1.nama = "Mukhamad Aziz Firmansyah";
//     mhs1.jurusan = "Informatika";
//     mhs1.usia = 19;
//     mhs1.hobi[0] = "Membaca";
//     mhs1.hobi[1] = "Bersepeda";

//     cout << "NPM: " << mhs1.npm << endl;
//     cout << "Nama: " << mhs1.nama << endl;
//     cout << "Jurusan: " << mhs1.jurusan << endl;
//     cout << "Usia: " << mhs1.usia << endl;
//     for (int i = 0; i < 2; i++) {
//         cout << "Hobi " << i + 1 << ": " << mhs1.hobi[i] << endl;
//     }
//     cout << "Kampus: " << kampus1.namaKampus << endl;
//     cout << "TB: " << kampus1.TB << endl;

//     return 0;
// }



// #include <iostream>
// using namespace std;

// // (GLOBAL)
// struct Kampus {
//     string namaKampus;
//     int TB;
// } kampus1, kampus2;

// struct Mahasiswa {
//     string npm, nama, jurusan;
//     int usia;
//     string hobi[2];
// } mhs1, mhs2;

// int main() {
//     // CARA 1
//     kampus1.namaKampus = "UPN \"VETERAN\" JAWA TIMUR";
//     kampus1.TB = 165;
//     mhs1.npm = "22081010030";
//     mhs1.nama = "Mukhamad Aziz Firmansyah";
//     mhs1.jurusan = "Informatika";
//     mhs1.usia = 19;
//     mhs1.hobi[0] = "Membaca";
//     mhs1.hobi[1] = "Bersepeda";

//     // CARA 2
//     kampus2 = {"Politeknik Keuangan Negara STAN", 170};
//     mhs2 = {"210455621", "Muhammad Salman", "D4 Perpajakan", 20, "Membaca", "Belajar"};

//     // CARA 3
//     Kampus kampus3 = {"Politeknik Negeri Malang", 168};
//     Mahasiswa mhs3 = {"220219887", "Muhammad Krisna Saputra", "Teknik Mesin", 19, "Membaca", "Futsal"};

//     cout << "NPM: " << mhs1.npm << endl;
//     cout << "Nama: " << mhs1.nama << endl;
//     cout << "Jurusan: " << mhs1.jurusan << endl;
//     cout << "Usia: " << mhs1.usia << endl;
//     for (int i = 0; i < 2; i++) {
//         cout << "Hobi " << i + 1 << ": " << mhs1.hobi[i] << endl;
//     }
//     cout << "Kampus: " << kampus1.namaKampus << endl;
//     cout << "TB: " << kampus1.TB << endl << endl;

//     cout << "NPM: " << mhs2.npm << endl;
//     cout << "Nama: " << mhs2.nama << endl;
//     cout << "Jurusan: " << mhs2.jurusan << endl;
//     cout << "Usia: " << mhs2.usia << endl;
//     for (int i = 0; i < 2; i++) {
//         cout << "Hobi " << i + 1 << ": " << mhs2.hobi[i] << endl;
//     }
//     cout << "Kampus: " << kampus2.namaKampus << endl;
//     cout << "TB: " << kampus2.TB << endl << endl;

//     cout << "NPM: " << mhs3.npm << endl;
//     cout << "Nama: " << mhs3.nama << endl;
//     cout << "Jurusan: " << mhs3.jurusan << endl;
//     cout << "Usia: " << mhs3.usia << endl;
//     for (int i = 0; i < 2; i++) {
//         cout << "Hobi " << i + 1 << ": " << mhs3.hobi[i] << endl;
//     }
//     cout << "Kampus: " << kampus3.namaKampus << endl;
//     cout << "TB: " << kampus3.TB << endl << endl;

//     return 0;
// }


// #include <iostream>
// using namespace std;

// // (GLOBAL)
// struct Kampus {
//     string namaKampus;
//     int TB;
// } kampus1, kampus2;

// struct Mahasiswa {
//     string npm, nama, jurusan;
//     int usia;
//     string hobi[2];
// } mhs1, mhs2;

// int main() {
//     // CARA 1
//     kampus1.namaKampus = "UPN \"VETERAN\" JAWA TIMUR";
//     kampus1.TB = 160;
//     mhs1.npm = "2208101030";
//     mhs1.nama = "Mukhamad Aziz Firmansyah";
//     mhs1.jurusan = "Informatika";
//     mhs1.usia = 19;
//     mhs1.hobi[0] = "Membaca";
//     mhs1.hobi[1] = "Bersepeda";

//     cout << "NPM: " << mhs1.npm << endl;
//     cout << "Nama: " << mhs1.nama << endl;
//     cout << "Jurusan: " << mhs1.jurusan << endl;
//     cout << "Usia: " << mhs1.usia << endl;
//     for (int i = 0; i < 2; i++) {
//         cout << "Hobi " << i + 1 << ": " << mhs1.hobi[i] << endl;
//     }
//     cout << "Kampus: " << kampus1.namaKampus << endl;
//     cout << "TB: " << kampus1.TB << endl << endl;

//     return 0;
// }


// #include <iostream>
// using namespace std;

// struct Kampus {
//     string namaKampus;
//     int TB;
// };

// struct Mahasiswa {
//     string npm, nama, jurusan;
//     int usia;
//     string hobi[2];
// };

// // (GLOBAL)
// Kampus kampus[3];

// int main() {
//     // (LOKAL)
//     Mahasiswa mhs[3];

//     // CARA 1
//     kampus[0].namaKampus = "UPN \"VETERAN\" JAWA TIMUR";
//     kampus[0].TB = 160;
//     mhs[0].npm = "22081010030";
//     mhs[0].nama = "Mukhamad Aziz Firmansyah";
//     mhs[0].jurusan = "Informatika";
//     mhs[0].usia = 19;
//     mhs[0].hobi[0] = "Membaca";
//     mhs[0].hobi[1] = "Bersepeda";

//     cout << "NPM: " << mhs[0].npm << endl;
//     cout << "Nama: " << mhs[0].nama << endl;
//     cout << "Jurusan: " << mhs[0].jurusan << endl;
//     cout << "Usia: " << mhs[0].usia << endl;
//     for (int i = 0; i < 2; i++) {
//         cout << "Hobi " << i + 1 << ": " << mhs[0].hobi[i] << endl;
//     }
//     cout << "Kampus: " << kampus[0].namaKampus << endl;
//     cout << "TB: " << kampus[0].TB << endl << endl;

//     return 0;
// }



// #include <iostream>
// using namespace std;

// struct Kampus {
//     string namaKampus;
//     int TB;
// };

// struct Mahasiswa {
//     string npm, nama, jurusan;
//     int usia;
//     string hobi[2];
//     Kampus kampus;
// };

// int main() {
//     // (LOKAL)
//     Mahasiswa mhs[3];

//     // CARA 1
//     mhs[0].npm = "22081010030";
//     mhs[0].nama = "Mukhamad Aziz Firmansyah";
//     mhs[0].jurusan = "Informatika";
//     mhs[0].usia = 19;
//     mhs[0].hobi[0] = "Membaca";
//     mhs[0].hobi[1] = "Bersepeda";
//     mhs[0].kampus.namaKampus = "UPN \"VETERAN\" JAWA TIMUR";
//     mhs[0].kampus.TB = 160;

//     cout << "NPM: " << mhs[0].npm << endl;
//     cout << "Nama: " << mhs[0].nama << endl;
//     cout << "Jurusan: " << mhs[0].jurusan << endl;
//     cout << "Usia: " << mhs[0].usia << endl;
//     for (int i = 0; i < 2; i++) {
//         cout << "Hobi " << i + 1 << ": " << mhs[0].hobi[i] << endl;
//     }
//     cout << "Kampus: " << mhs[0].kampus.namaKampus << endl;
//     cout << "TB: " << mhs[0].kampus.TB << endl << endl;

//     return 0;
// }



// #include <iostream>
// using namespace std;

// struct Kampus {
//     string namaKampus;
//     int TB;
// };

// struct Mahasiswa {
//     string npm, nama, jurusan;
//     int usia;
//     string hobi[2];
//     Kampus kampus;
// };

// void printDataMahasiswa(Mahasiswa mhs) {
//     cout << "NPM: " << mhs.npm << endl;
//     cout << "Nama: " << mhs.nama << endl;
//     cout << "Jurusan: " << mhs.jurusan << endl;
//     cout << "Usia: " << mhs.usia << endl;
//     for (int i = 0; i < 2; i++) {
//         cout << "Hobi " << i + 1 << ": " << mhs.hobi[i] << endl;
//     }
//     cout << "Kampus: " << mhs.kampus.namaKampus << endl;
//     cout << "TB: " << mhs.kampus.TB << endl << endl;
// }

// int main() {
//     Mahasiswa mhs[2];

//     mhs[0].npm = "22081010030";
//     mhs[0].nama = "Mukhamad Aziz Firmansyah";
//     mhs[0].jurusan = "Informatika";
//     mhs[0].usia = 19;
//     mhs[0].hobi[0] = "Membaca";
//     mhs[0].hobi[1] = "Bersepeda";
//     mhs[0].kampus.namaKampus = "UPN \"Veteran\" Jawa Timur";
//     mhs[0].kampus.TB = 160;

//     mhs[1].npm = "220219887";
//     mhs[1].nama = "Muhammad Krisna Saputra";
//     mhs[1].jurusan = "Teknik Mesin";
//     mhs[1].usia = 19;
//     mhs[1].hobi[0] = "Membaca";
//     mhs[1].hobi[1] = "Futsal";
//     mhs[1].kampus.namaKampus = "Politeknik Negeri Malang";
//     mhs[1].kampus.TB = 168;

//     printDataMahasiswa(mhs[0]);
//     printDataMahasiswa(mhs[1]);

//     return 0;
// }

