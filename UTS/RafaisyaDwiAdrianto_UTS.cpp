#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Deklarasi variabel untuk func accesoris looping, agar pembatasnya 2 baris
int two = 2;
char check;

// Accesoris pembatas 1 baris
void acc(){
    for(int i = 0; i < 70; i++){
        cout << "=";
    }
    cout << endl;
}

// Accesoris pembatas 2 baris
void accl(int ulang) {
    for(int j = 0; j < ulang; j++) {
        for(int i = 0; i < 70; i++) {
            cout << "=";
        }
        cout << endl;
    }
}

// Variabel Global
struct Node {
    string data;
    Node* next;
};

class LinkedList {
public:
    LinkedList() {
        head = nullptr;
    }

    void insert(const string& data) {
        Node* new_node = new Node;
        new_node->data = data;
        new_node->next = nullptr; // Setelah node baru

        if (head == nullptr) { // Jika linked list masih kosong
            head = new_node;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = new_node; // Menambahkan node baru di belakang
        }
    }

    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << endl;
            current = current->next;
        }
    }

private:
    Node* head;
};

// Pendeklarasian variabel untuk menyimpan Nilai yang akan diinputkan 
struct Nilai {
    int absen;
    int tugas;
    int uts;
    int uas;
    float nilaiAkhir;
    char indexHuruf;
};

// Pendeklarasian variabel untuk menyiman nilai siswa didalamnya
struct Siswa {
    string npm;
    string nama;
    Nilai nilai;
};

class DataSiswa {

private:
    Siswa siswa[20];
    int jumlahData;

public:
    DataSiswa() : jumlahData(0) {}

    void tambahSiswa() {
        if (jumlahData < 20) {
            tambah:
            system("cls");
            acc();
            cout << "Masukkan NPM: ";
            cin >> siswa[jumlahData].npm;
            cin.ignore(); 
            cout << "Masukkan Nama: ";
            getline(cin, siswa[jumlahData].nama);
            cout << "Masukkan Nilai Absen: ";
            cin >> siswa[jumlahData].nilai.absen;
            cout << "Masukkan Nilai Tugas: ";
            cin >> siswa[jumlahData].nilai.tugas;
            cout << "Masukkan Nilai UTS: ";
            cin >> siswa[jumlahData].nilai.uts;
            cout << "Masukkan Nilai UAS: ";
            cin >> siswa[jumlahData].nilai.uas;
            hitungNilaiAkhir(jumlahData);
            ++jumlahData;
            acc();
            cout << "Ingin menambahkan data lagi ? (y/n)";
            cin >> check;
            if (check == 'y' || check == 'Y'){
                goto tambah;
            } else {
                cout << "Data berhasil ditambahkan\n";
                cout << "Enter..";
                cin.ignore();
                cin.get(); 
            } 
        } else {
            cout << "Maaf, kapasitas maksimum sudah tercapai." << endl;
        }
    }

    void hitungNilaiAkhir(int index) {
        Nilai& nilai = siswa[index].nilai;
        nilai.nilaiAkhir = (nilai.absen * 0.1) + (nilai.tugas * 0.2) + (nilai.uts * 0.3) + (nilai.uas * 0.4);

        if (nilai.nilaiAkhir >= 80) {
            nilai.indexHuruf = 'A';
        } else if (nilai.nilaiAkhir >= 70) {
            nilai.indexHuruf = 'B';
        } else if (nilai.nilaiAkhir >= 60) {
            nilai.indexHuruf = 'C';
        } else if (nilai.nilaiAkhir >= 50) {
            nilai.indexHuruf = 'D';
        } else {
            nilai.indexHuruf = 'E';
        }
    }

    void tampilkanSiswa() {
        if (jumlahData == 0) {
            acc();
            cout << "\t\t\tBelum ada data siswa." << endl;
            acc();
            return;
        }
        system("cls");
        acc();
        cout << "Data Siswa:" << endl;
        acc();
        for (int i = 0; i < jumlahData; ++i) {
            Siswa& sws = siswa[i];
            cout << "NPM            : " << sws.npm << endl; 
            cout << "Nama           : " << sws.nama << endl;
            cout << "Nilai Akhir    : " << sws.nilai.nilaiAkhir << endl;
            cout << "Index Huruf    : " << sws.nilai.indexHuruf << endl;
            acc();
        }
    }

    Siswa cariSiswa(string npm) {
        for (int i = 0; i < jumlahData; ++i) {
            if (siswa[i].npm == npm) {
                return siswa[i]; 
            }
        }

        Siswa siswaKosong = {"", "", {0, 0, 0, 0, 0.0, ' '}};
        return siswaKosong;
    }

    void hapusSiswa(string npm) {
        for (int i = 0; i < jumlahData; ++i) {
            if (siswa[i].npm == npm) {
                siswa[i] = siswa[jumlahData - 1];
                --jumlahData;
                accl(two);
                cout << "\tData siswa dengan NPM " << npm << " berhasil dihapus." << endl;
                accl(two);
                cout << "Tekan enter untuk melanjutkan..";
                cin.ignore();
                cin.get();
                return;
            }
        }
        accl(two);
        cout << "\tData siswa dengan NPM " << npm << " tidak ditemukan.\n";
        accl(two);
        cout << "Tekan enter untuk melanjutkan..";
        cin.ignore();
        cin.get();
        cout << endl;
    }
};

int main(){
    LinkedList menuItems;
        menuItems.insert("1. Tambah siswa");
        menuItems.insert("2. Tampilkan siswa");
        menuItems.insert("3. Hapus siswa");
        menuItems.insert("4. Cari siswa");
        menuItems.insert("5. Keluar Dari Program");
    DataSiswa dataSiswa;
    int pilihan;
    string npm;
    bool lanjutkanPencarian = true;

    do {
        system("cls");
        acc();
        cout << "SISTEM DATABASE SISWA\n";
        acc();
        menuItems.display();
        acc();
        cout << "Masukan Pilihan Menu : ";
        cin >> pilihan;

        switch(pilihan) {
            case 1:
                dataSiswa.tambahSiswa();
                break;

            case 2:
                system("cls");
                dataSiswa.tampilkanSiswa();
                cout << "Enter untuk melanjutkan..";
                cin.ignore();
                cin.get();
                break;

            case 3:
                system("cls");
                acc();
                cout << "Masukkan NPM siswa yang akan dihapus: ";
                cin >> npm;
                system("cls");
                dataSiswa.hapusSiswa(npm);
                break;

            case 4:
                do {
                    system("cls");
                    acc();
                    cout << "Masukkan NPM siswa yang ingin dicari : ";
                    cin >> npm;
                    system("cls");
                    {
                        Siswa siswaDitemukan = dataSiswa.cariSiswa(npm);
                        if (siswaDitemukan.npm != "") {
                            accl(two);
                            cout << "Siswa ditemukan:" << endl;
                            accl(two);
                            cout << "NPM            : " << siswaDitemukan.npm << endl; 
                            cout << "Nama           : " << siswaDitemukan.nama << endl;
                            cout << "Nilai Akhir    : " << siswaDitemukan.nilai.nilaiAkhir << endl;
                            cout << "Index Huruf    : " << siswaDitemukan.nilai.indexHuruf << endl;
                            acc();
                            cout << "Tekan enter..";
                            cin.ignore();
                            cin.get();
                            lanjutkanPencarian = false;
                        } else {
                            accl(two);
                            cout << "\tSiswa dengan NPM " << npm << " tidak ditemukan." << endl;
                            accl(two);
                            char pilihan;
                            cout << "\tApakah Anda ingin mencari NPM lagi? (y/n): ";
                            cin >> pilihan;
                            if (pilihan != 'y' && pilihan != 'Y') {
                                lanjutkanPencarian = false;
                            }
                        }
                    }
                } while (lanjutkanPencarian);
                break;

            case 5:
                system("cls");
                accl(two);
                cout << "\t\tKeluar dari program." << endl;
                accl(two);
                break;

            default:
                system("cls");
                accl(two);  
                cout << "Maaf Tidak Ada Pilihan Tersebut!\n\n";
                pilihan = true;
                accl(two);
        }
    } while (pilihan !=5);

    cout << endl;
    acc();
    cout << "Nama = Rafaisya Dwi Adrianto\n";
    cout << "NPM = 2310631170147\n";
    acc();

    return 0;
}
