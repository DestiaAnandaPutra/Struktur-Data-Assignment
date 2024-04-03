#include <iostream>
#include <iomanip>
using namespace std;

//Nama : Destia Ananda Putra
//NIM  : 2311102176

//Deklarasi Struct Node
struct Node {
    string Name_2176;
    long long NIM_2176;
    Node* next;
};

Node* head;
Node* tail;

//Inisialisasi Node
void Initialize_2176() {
    head = NULL;
    tail = NULL;
}

// Pengecekan
bool ItsEmpty_2176() {
    if (head == NULL)
        return true;
    else
        return false;
}

//Tambah Depan
void InsertFront_2176(string name, long long NIM) {
    //Buat Node baru
    Node* baru = new Node;
    baru->Name_2176 = name;
    baru->NIM_2176 = NIM;
    baru->next = NULL;

    if (ItsEmpty_2176() == true) {
        head = tail = baru;
        tail->next = NULL;
    }
    else {
        baru->next = head;
        head = baru;
    }
}

//Tambah Belakang
void InsertBack_2176(string name, long long NIM) {
    //Buat Node baru
    Node* baru = new Node;
    baru->Name_2176 = name;
    baru->NIM_2176 = NIM;
    baru->next = NULL;

    if (ItsEmpty_2176() == true) {
        head = tail = baru;
        tail->next = NULL;
    }
    else {
        tail->next = baru;
        tail = baru;
    }
}

//Hitung Jumlah List
int CountList_2176() {
    Node* hitung;
    hitung = head;
    int jumlah = 0;

    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }

    return jumlah;
}

//Tambah Tengah
void InsertMiddle_2176(string name, long long NIM, int posisi) {
    if (posisi < 1 || posisi > CountList_2176()) {
        cout << "Heyyy, the position is out of range!" << endl;
    }
    else if (posisi == 1) {
        cout << "Wow, the position you input wasn't the middle." << endl;
    }
    else {
        Node* baru, * bantu;
        baru = new Node();
        baru->Name_2176 = name;
        baru->NIM_2176 = NIM;

        // tranversing
        bantu = head;
        int nomor = 1;

        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }

        baru->next = bantu->next;
        bantu->next = baru;
    }
}

//Hapus Depan
void EraseFront_2176() {
    Node* hapus;

    if (ItsEmpty_2176() == false) {
        if (head->next != NULL) {
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else {
            head = tail = NULL;
        }
    }
    else {
        cout << "ITS EMPTY!" << endl;
    }
}

//Hapus Belakang
void EraseBack_2176() {
    Node* hapus;
    Node* bantu;

    if (ItsEmpty_2176() == false) {
        if (head != tail) {
            hapus = tail;
            bantu = head;

            while (bantu->next != tail) {
                bantu = bantu->next;
            }

            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else {
            head = tail = NULL;
        }
    }
    else {
        cout << "ITS EMPTY!" << endl;
    }
}

//Hapus Tengah
void EraseMiddle_2176(int posisi) {
    Node* hapus, * bantu, * bantu2;

    if (posisi < 1 || posisi > CountList_2176()) {
        cout << "Heyyy, the position is out of range!" << endl;
    }
    else if (posisi == 1) {
        cout << "Wow, the position you input wasn't the middle." << endl;
    }
    else {
        int nomor = 1;
        bantu = head;

        while (nomor <= posisi) {
            if (nomor == posisi - 1) {
                bantu2 = bantu;
            }

            if (nomor == posisi) {
                hapus = bantu;
            }

            bantu = bantu->next;
            nomor++;
        }

        bantu2->next = bantu;
        delete hapus;
    }
}

//Ubah Depan
void ChangeFront_2176(string name, long long NIM) {
    if (ItsEmpty_2176() == false) {
        head->Name_2176 = name;
        head->NIM_2176 = NIM;
    }
    else {
        cout << "THERE'S NOTHING TO CHANGE!" << endl;
    }
}

//Ubah Tengah
void ChangeMiddle_2176(string name, long long NIM, int posisi) {
    Node* bantu;

    if (ItsEmpty_2176() == false) {
        if (posisi < 1 || posisi > CountList_2176()) {
            cout << "Heyyy, the position is out of range!" << endl;
        }
        else if (posisi == 1) {
            cout << "Wow, the position you input wasn't the middle." << endl;
        }
        else {
            bantu = head;
            int nomor = 1;

            while (nomor < posisi) {
                bantu = bantu->next;
                nomor++;
            }

            bantu->Name_2176 = name;
            bantu->NIM_2176 = NIM;
        }
    }
    else {
        cout << "ITS EMPTY!" << endl;
    }
}

//Ubah Belakang
void ChangeBack_2176(string name, long long NIM) {
    if (ItsEmpty_2176() == false) {
        tail->Name_2176 = name;
        tail->NIM_2176 = NIM;
    }
    else {
        cout << "ITS EMPTY" << endl;
    }
}

//Hapus List
void EraseList_2176() {
    Node* bantu, * hapus;
    bantu = head;

    while (bantu != NULL) {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }

    head = tail = NULL;
    cout << "Hoorah! You erased EVERYTHING YOU WORKED HARD FOR!" << endl;
}

//Tampilkan List
void Reveal_2176() {
    Node* bantu;
    bantu = head;

    cout << left << setw(15) << "-Name-" << right << setw(7) << "-NIM-" << endl; // Supaya rapi

    if (ItsEmpty_2176() == false) {
        while (bantu != NULL) {
            cout << left << setw(15) << bantu->Name_2176 << right << setw(4) << bantu->NIM_2176 << endl; // Supaya lurus di output
            bantu = bantu->next;
        }

        cout << endl;
    }
    else {
        cout << "ITS EMPTY!" << endl;
    }
}

int main() {
    Initialize_2176(); // Inisialisasi Linked List
    cout << "\n-=-=-= WELCOME TO Destia STUDENT NAME & NIM PROGRAM  =-=-=-" << endl;

    while (true) {
        cout << "\n-=- ADMIN MENU -=-" << endl;
        cout << "1. Add Front" << endl;
        cout << "2. Add Back" << endl;
        cout << "3. Add Middle" << endl;
        cout << "4. Change Front" << endl;
        cout << "5. Change Back" << endl;
        cout << "6. Change Middle" << endl;
        cout << "7. Delete Front" << endl;
        cout << "8. Delete Back" << endl;
        cout << "9. Delete Middle" << endl;
        cout << "10. Delete List" << endl;
        cout << "11. DISPLAY" << endl;
        cout << "0. EXIT" << endl;
        int choice;
        cout << "Insert your choice here: ";
        cin >> choice;

        switch (choice) {
    case 1: { // Add Front
        string name;
        long long NIM;
        cout << "\n-- ADD FRONT --" << endl;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter NIM: ";
        cin >> NIM;
        InsertFront_2176(name, NIM);
        cout << "Yes congrats!! Data " << name << " with NIM " << NIM << " has been added to the front!" << endl;
        break;
    }
    case 2: { // Add Back
        string name;
        long long NIM;
        cout << "\n-- ADD BACK --" << endl;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter NIM: ";
        cin >> NIM;
        InsertBack_2176(name, NIM);
        cout << "Yes congrats!! Data " << name << " with NIM " << NIM << " has been added to the back!" << endl;
        break;
    }
    case 3: { // Add Middle
        string name;
        long long NIM;
        int position;
        cout << "\n-- ADD MIDDLE --" << endl;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter NIM: ";
        cin >> NIM;
        cout << "Enter position: ";
        cin >> position;
        InsertMiddle_2176(name, NIM, position);
        cout << "Yes congrats!! Data " << name << " with NIM " << NIM << " has been added to position " << position << "!" << endl;
        break;
    }
    case 4: { // Change Front
        string oldName = head->Name_2176; // Mendapatkan data nama yang lama
        long long oldNIM = head->NIM_2176; // Mendapatkan data NIM yang lama
        string newName;
        long long newNIM;
        cout << "\n-- CHANGE FRONT --" << endl;
        cout << "Enter new Name: ";
        cin >> newName;
        cout << "Enter new NIM: ";
        cin >> newNIM;
        ChangeFront_2176(newName, newNIM);
        cout << "Yes congrats!! Data " << oldName << " (NIM: " << oldNIM << ") has been changed to " << newName << " with NIM " << newNIM << " at the front!" << endl;
        break;
    }
    case 5: { // Change Back
        string oldName = tail->Name_2176; // Mendapatkan data nama yang lama
        long long oldNIM = tail->NIM_2176; // Mendapatkan data NIM yang lama
        string newName;
        long long newNIM;
        cout << "\n-- CHANGE BACK --" << endl;
        cout << "Enter new name: ";
        cin >> newName;
        cout << "Enter new NIM: ";
        cin >> newNIM;
        ChangeBack_2176(newName, newNIM);
        cout << "Yes congrats!! Data " << oldName << " (NIM: " << oldNIM << ") has been changed to " << newName << " with NIM " << newNIM << " at the back!" << endl;
        break;
    }
    case 6: { // Change Middle
        int position;
        cout << "\n-- CHANGE MIDDLE --" << endl;
        cout << "Enter position: ";
        cin >> position;
        string oldName = "Huh?";
        long long oldNIM = -1; // Inisialisasi data lama
        if (position >= 1 && position <= CountList_2176()) { // Jika posisi valid
            Node* temp = head; // Maka, cari data lama
            for (int i = 1; i < position; ++i) { // Untuk setiap node sampai posisi
                temp = temp->next; // Pindah ke node selanjutnya
            }
            oldName = temp->Name_2176; // Simpan nama lama
            oldNIM = temp->NIM_2176; // Simpan NIM lama
        }
        string newName;
        long long newNIM;
        cout << "Enter new name: ";
        cin >> newName;
        cout << "Enter new NIM: ";
        cin >> newNIM;
        ChangeMiddle_2176(newName, newNIM, position);
        cout << "Yes congrats!! Data " << oldName << " (NIM: " << oldNIM << ") has been changed to " << newName << " with NIM " << newNIM << " at position " << position << "!" << endl;
        break;
    }
    case 7: { // Delete Front
        if (!ItsEmpty_2176()) { // Jika list tidak kosong
            string deletedName = head->Name_2176; // Simpan nama yang dihapus
            long long deletedNIM = head->NIM_2176; // Simpan NIM yang dihapus
            EraseFront_2176(); // Hapus depan
            cout << "Yes congrats!! Data " << deletedName << " with NIM " << deletedNIM << " has been deleted from the front!" << endl;
        } else {
            cout << "List is empty!?" << endl;
        }
        break;
    }
    case 8: { // Delete Back
        if (!ItsEmpty_2176()) { // Jika list tidak kosong
            string deletedName = tail->Name_2176; // Simpan nama yang dihapus
            long long deletedNIM = tail->NIM_2176; // Simpan NIM yang dihapus
            EraseBack_2176(); // Hapus belakang
            cout << "Yes congrats!! Data " << deletedName << " with NIM " << deletedNIM << " has been deleted from the back!" << endl;
        } else {
            cout << "List is empty!?" << endl;
        }
        break;
    }
    case 9: { // Delete Middle
        int position;
        cout << "\n-- DELETE MIDDLE --" << endl;
        cout << "Enter position: ";
        cin >> position;
        if (position >= 1 && position <= CountList_2176()) { // Jika posisi valid
            string deletedName = "Huh?"; // Inisialisasi nama yang dihapus
            long long deletedNIM = -1; // Inisialisasi NIM yang dihapus
            Node* temp = head; // Cari data yang dihapus
            for (int i = 1; i < position; ++i) { // Untuk setiap node sampai posisi
                temp = temp->next; // Pindah ke node selanjutnya
            }
            deletedName = temp->Name_2176; // Simpan nama yang dihapus
            deletedNIM = temp->NIM_2176; // Simpan NIM yang dihapus
            EraseMiddle_2176(position); // Hapus di posisi
            cout << "Yes congrats!! Data " << deletedName << " (NIM: " << deletedNIM << ") has been deleted from position " << position << "!" << endl;
        } else {
            cout << "Such position does not exist!?" << endl;
        }
        break;
    }
    case 10: { // Delete List
        EraseList_2176();
        break;
    }
    case 11: { // Display
    cout << "\n-=- STUDENT & NIM DATA LIST BY Destia -=-" << endl;
        Reveal_2176();
        break;
    }
    case 0: { // Exit
        return 0;
    }
    default: { // Invalid choice
        cout << "Oops! Invalid choice!" << endl;
        break;
          }
       }
    }
}