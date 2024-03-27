// LAPRAK 3 : UNGUIDED 1
// FADHEL SETIAWAN
// 2311102176
// S1 IF-11-E
#include <iostream>
using namespace std;

struct Node {
    string nama_176;
    int usia_176;
    Node* next_176;
};

Node* head_176 = nullptr;

void tampilkanList_176() {
    cout << "[ Nama ]" << "\t" << "[ Usia ]" << endl;
    Node* saatIni_176 = head_176;
    while (saatIni_176 != nullptr) {
        cout << saatIni_176->nama_176 << "\t\t" << saatIni_176->usia_176 << endl;
        saatIni_176 = saatIni_176->next_176;
    }
}

void insertDepan_176(string nama_176, int usia_176) {
    Node* baru_176 = new Node;
    baru_176->nama_176 = nama_176;
    baru_176->usia_176 = usia_176;
    baru_176->next_176 = head_176;
    head_176 = baru_176;
}

void insertBelakang_176(string nama_176, int usia_176) {
    Node* baru_176 = new Node;
    baru_176->nama_176 = nama_176;
    baru_176->usia_176 = usia_176;
    baru_176->next_176 = nullptr;
    if (head_176 == nullptr) {
        head_176 = baru_176;
    }
    else {
        Node* temp_176 = head_176;
        while (temp_176->next_176 != nullptr) {
            temp_176 = temp_176->next_176;
        }
        temp_176->next_176 = baru_176;
    }
}

void insertTengah_176(string nama_176, int usia_176, int posisi_176) {
    Node* baru_176 = new Node;
    baru_176->nama_176 = nama_176;
    baru_176->usia_176 = usia_176;
    Node* bantu_176 = head_176;
    for (int i_176 = 1; i_176 < posisi_176 - 1; i_176++) {
        if (bantu_176 != nullptr) {
            bantu_176 = bantu_176->next_176;
        }
    }
    if (bantu_176 != nullptr) {
        baru_176->next_176 = bantu_176->next_176;
        bantu_176->next_176 = baru_176;
    }
}

void hapusData_176(string nama_176) {
    Node* hapus_176 = head_176;
    Node* prev_176 = nullptr;
    while (hapus_176 != nullptr && hapus_176->nama_176 != nama_176) {
        prev_176 = hapus_176;
        hapus_176 = hapus_176->next_176;
    }
    if (hapus_176 == nullptr) {
        cout << "Data tidak ditemukan" << endl;
        return;
    }
    if (prev_176 == nullptr) {
        head_176 = hapus_176->next_176;
    }
    else {
        prev_176->next_176 = hapus_176->next_176;
    }
    delete hapus_176;
}

void ubahData_176(string nama_176, string newnama_176, int newusia_176) {
    Node* temp_176 = head_176;
    while (temp_176 != nullptr && temp_176->nama_176 != nama_176) {
        temp_176 = temp_176->next_176;
    }
    if (temp_176 != nullptr) {
        temp_176->nama_176 = newnama_176;
        temp_176->usia_176 = newusia_176;
    }
}

void tampilkanData() {
    Node* temp_176 = head_176;
    while (temp_176 != nullptr) {
        cout << temp_176->nama_176 << " " << temp_176->usia_176 << endl;
        temp_176 = temp_176->next_176;
    }
}

int main() {
    insertBelakang_176("Destia", 19);
    insertBelakang_176("John", 19);
    insertBelakang_176("Jane", 20);
    insertBelakang_176("Michael", 18);
    insertBelakang_176("Yusuke", 19);
    insertBelakang_176("Akechi", 20);
    insertBelakang_176("Hoshino", 18);
    insertBelakang_176("Karin", 18);

    char pilihan_176;
    do {
        cout << "\nMenu:\n";
        cout << "a. Tampilkan data sesuai urutan tersedia (Data pertama adalah nama dan usia pengguna)\n";
        cout << "b. Hapus data Akechi\n";
        cout << "c. Tambahkan data berikut diantara John dan Jane : Futaba 18\n";
        cout << "d. Tambahkan data berikut diawal : igor 20\n";
        cout << "e. Ubah data Michael menjadi : Reyn 18\n";
        cout << "f. Tampilkan seluruh data\n";
        cout << "g. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan_176;

        switch (pilihan_176) {
            case 'a':
                cout << "\nData yang tersedia:\n";
                tampilkanList_176();
                break;
            case 'b':
                hapusData_176("Akechi");
                cout << "Data Akechi berhasil dihapus.\n";
                cout << "\nData yang tersedia setelah penghapusan:\n";
                tampilkanList_176();
                break;
            case 'c':
                insertTengah_176("Futaba", 18, 3); 
                cout << "Data Futaba berhasil ditambahkan.\n";
                cout << "\nData yang tersedia setelah penambahan:\n";
                tampilkanList_176();
                break;
            case 'd':
                insertDepan_176("Igor", 20);
                cout << "Data Igor berhasil ditambahkan di awal.\n";
                cout << "\nData yang tersedia setelah penambahan:\n";
                tampilkanList_176();
                break;
            case 'e':
                ubahData_176("Michael", "Reyn", 18);
                cout << "Data Michael berhasil diubah menjadi Reyn 18.\n";
                cout << "\nData yang tersedia setelah perubahan:\n";
                tampilkanList_176();
                break;
            case 'f':
                cout << "\nTampilan seluruh data sekarang:\n";
                tampilkanList_176();
                break;
            case 'g':
                cout << "Terima kasih, program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid, silakan coba lagi.\n";
                break;
        }
    } while (pilihan_176 != 'g');

    return 0;
}