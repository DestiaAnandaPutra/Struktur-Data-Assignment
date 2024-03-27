// LAPRAK 3 : UNGUIDED 2
// Destia Ananda Putra
// 2311102176
// S1 IF-11-E
#include <iostream>
#include <iomanip> 
using namespace std;

// Deklarasi Struct Node
class Node {
public:
    string produk_176;
    int harga_176;
    Node* prev_176;
    Node* next_176;
};

// Deklarasi Class DoublyLinkedList
class DoublyLinkedList {
public:
    Node* head_176;
    Node* tail_176;

    // Constructor
    DoublyLinkedList() {
        head_176 = nullptr;
        tail_176 = nullptr;
    }

    // Prosedur untuk menambahkan data di depan
    void Push(int harga_176, string produk_176) {
        Node* newNode_176 = new Node;
        newNode_176->harga_176 = harga_176;
        newNode_176->produk_176 = produk_176;
        newNode_176->prev_176 = nullptr;
        newNode_176->next_176 = head_176;

        if (head_176 != nullptr) {
            head_176->prev_176 = newNode_176;
        }
        else {
            tail_176 = newNode_176;
        }

        head_176 = newNode_176;
    }

    // Prosedur untuk menambahkan data pada posisi tertentu
    void PushPosition(int posisi_176, int harga_176, string produk_176) {
        if (posisi_176 < 1) {
            cout << "Posisi tidak valid!" << endl;
            return;
        }

        Node* newNode_176 = new Node;
        newNode_176->harga_176 = harga_176;
        newNode_176->produk_176 = produk_176;
        newNode_176->prev_176 = nullptr;
        newNode_176->next_176 = nullptr;

        if (posisi_176 == 1) {
            newNode_176->next_176 = head_176;
            if (head_176 != nullptr)
                head_176->prev_176 = newNode_176;
            else
                tail_176 = newNode_176;
            head_176 = newNode_176;
            return;
        }

        Node* saatIni_176 = head_176;
        for (int i = 1; i < posisi_176 - 1 && saatIni_176 != nullptr; ++i)
            saatIni_176 = saatIni_176->next_176;

        if (saatIni_176 == nullptr) {
            cout << "Posisi tidak valid!" << endl;
            delete newNode_176;
            return;
        }

        newNode_176->next_176 = saatIni_176->next_176;
        newNode_176->prev_176 = saatIni_176;
        if (saatIni_176->next_176 != nullptr)
            saatIni_176->next_176->prev_176 = newNode_176;
        else
            tail_176 = newNode_176;
        saatIni_176->next_176 = newNode_176;
    }

    // Prosedur untuk menghapus data di depan
    void Pop() {
        if (head_176 == nullptr) {
            cout << "Tidak ada data yang bisa dihapus!" << endl;
            return;
        }

        Node* temp_176 = head_176;
        head_176 = head_176->next_176;

        if (head_176 != nullptr) {
            head_176->prev_176 = nullptr;
        }
        else {
            tail_176 = nullptr;
        }

        delete temp_176;
    }

    // Prosedur untuk menghapus data pada posisi tertentu
    void PopPosition(int posisi_176) {
        if (head_176 == nullptr) {
            cout << "Tidak ada data yang bisa dihapus!" << endl;
            return;
        }

        Node* temp_176 = head_176;
        for (int i = 1; i < posisi_176 && temp_176 != nullptr; ++i) {
            temp_176 = temp_176->next_176;
        }

        if (temp_176 == nullptr) {
            cout << "Posisi tidak valid!" << endl;
            return;
        }

        if (temp_176->prev_176 != nullptr) {
            temp_176->prev_176->next_176 = temp_176->next_176;
        } else {
            head_176 = temp_176->next_176;
        }

        if (temp_176->next_176 != nullptr) {
            temp_176->next_176->prev_176 = temp_176->prev_176;
        } else {
            tail_176 = temp_176->prev_176;
        }

        delete temp_176;
    }

    // Fungsi untuk mengupdate data
    bool Update(string oldProduk_176, string newProduk_176, int newharga_176) {
        Node* saatIni_176 = head_176;

        while (saatIni_176 != nullptr) {
            if (saatIni_176->produk_176 == oldProduk_176) {
                saatIni_176->produk_176 = newProduk_176;
                saatIni_176->harga_176 = newharga_176;
                return true;
            }
            saatIni_176 = saatIni_176->next_176;
        }

        return false;
    }

    // Prosedur untuk menghapus semua data
    void DeleteAll() {
        Node* saatIni_176 = head_176;

        while (saatIni_176 != nullptr) {
            Node* temp_176 = saatIni_176;
            saatIni_176 = saatIni_176->next_176;
            delete temp_176;
        }

        head_176 = nullptr;
        tail_176 = nullptr;
    }

    // Prosedur untuk menampilkan data
    void Display_176() {
        Node* saatIni_176 = head_176;

        cout << left << setw(20) << "[ Nama Produk ]" << setw(10) << "[ Harga ]" << endl;

        while (saatIni_176 != nullptr) {
            cout << setw(20) << saatIni_176->produk_176 << setw(10) << saatIni_176->harga_176 << endl;
            saatIni_176 = saatIni_176->next_176;
        }

        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;

    cout << "\n== MENU TOKO SKINCARE PURWOKERTO Destia Ananda Putra ==" << endl;

    // Inisialisasi data awal
    list.Push(30000, "Hanasui");
    list.Push(50000, "Wardah");
    list.Push(100000, "Skintific");
    list.Push(150000, "Somethinc");
    list.Push(60000, "Originote");
    list.Display_176(); 

    // Loop untuk menu interaktif
    while (true) {
        cout << "\nToko Skincare Purwokerto" << endl;
        cout << "   1. Tambah Data" << endl;
        cout << "   2. Hapus Data" << endl;
        cout << "   3. Update Data" << endl;
        cout << "   4. Tambah Data pada Posisi Tertentu" << endl;
        cout << "   5. Hapus Data pada Posisi Tertentu" << endl;
        cout << "   6. Hapus Semua Data" << endl;
        cout << "   7. Tampilkan Data" << endl;
        cout << "   8. Exit" << endl;

        int pilihan_176;
        cout << "Pilih Nomor: ";
        cin >> pilihan_176;

        switch (pilihan_176) {
            case 1: {
                int harga_176;
                string produk_176;

                cout << "\nTAMBAH PRODUK SKINCARE" << endl;
                cout << "Nama produk: ";
                cin.ignore();
                getline(cin, produk_176);
                cout << "Harga produk: ";
                cin >> harga_176;
                list.Push(harga_176, produk_176);
                cout << "Produk berhasil ditambahkan!" << endl;
                list.Display_176(); 
                break;
            }

            case 2: {
                list.Pop();
                cout << "PRODUK PALING ATAS BERHASIL DIHAPUS!" << endl;
                list.Display_176(); 
                break;
            }

            case 3: {
                string oldProduk_176, newProduk_176;
                int newharga_176;

                cout << "\nUPDATE DATA PRODUK SKINCARE" << endl;
                cout << "Masukkan nama produk yang ingin diubah: ";
                cin.ignore();
                getline(cin, oldProduk_176);
                cout << "Masukkan nama produk baru: ";
                getline(cin, newProduk_176);
                cout << "Masukkan harga baru: ";
                cin >> newharga_176;

                bool update_176 = list.Update(oldProduk_176, newProduk_176, newharga_176);
                if (update_176) {
                    cout << "Data berhasil diperbarui!" << endl;
                } else {
                    cout << "Data tidak ditemukan!" << endl;
                }
                list.Display_176(); 
                break;
            }

            case 4: {
                int posisi_176, harga_176;
                string produk_176;

                cout << "\nTAMBAH PRODUK SKINCARE PADA POSISI TERTENTU" << endl;
                cout << "Masukkan posisi untuk produk baru: ";
                cin >> posisi_176;
                cout << "Nama produk: ";
                cin.ignore();
                getline(cin, produk_176);
                cout << "Harga produk: ";
                cin >> harga_176;
                list.PushPosition(posisi_176, harga_176, produk_176);
                cout << "Produk berhasil ditambahkan pada posisi ke-" << posisi_176 << "!" << endl;
                list.Display_176(); 
                break;
            }

            case 5: {
                int posisi_176;

                cout << "\nHAPUS PRODUK SKINCARE PADA POSISI TERTENTU" << endl;
                cout << "Masukkan posisi untuk menghapus data: ";
                cin >> posisi_176;
                list.PopPosition(posisi_176);
                cout << "Data berhasil dihapus pada posisi ke-" << posisi_176 << "!" << endl;
                list.Display_176(); 
                break;
            }

            case 6: {
                list.DeleteAll();
                cout << "SEMUA DATA BERHASIL DI HAPUS!" << endl;
                list.Display_176(); 
                break;
            }

            case 7: {
                cout << "\nTAMPILAN DATA PRODUK TOKO SKINCARE PURWOKERTO SEKARANG" << endl;
                list.Display_176(); 
                break;
            }

            case 8: {
                cout << "Terimakasih telah menggunakan program ini!" << endl;
                return 0;
            }

            default: {
                cout << "Pilihan anda tidak valid!" << endl;
                break;
            }
        }
    }

    return 0;
}