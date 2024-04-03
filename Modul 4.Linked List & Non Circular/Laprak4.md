# <h1 align="center">Laporan Praktikum Modul 4 - Linked List Circular dan Non Circular</h1>
<p align="center">Destia Ananda Putra - 2311102176</p>

## Dasar Teori
Linked list adalah strukur data linier berbentuk rantai simpul di mana setiap simpul menyimpan 2 item, yaitu nilai data dan pointer ke simpul elemen berikutnya. Berbeda dengan array, elemen linked list tidak ditempatkan dalam alamat memori yang berdekatan melainkan elemen ditautkan menggunakan pointer. Linked list dapat dibagi lagi berdasarkan struktur penunjuknya, yaitu:</br> 

- Single Linked List</br>
Single linked list adalah struktur data linear dimana setiap node memiliki dua bagian, yaitu Data (informasi aktual yang disimpan di dalam node) dan Next Link (Pointer yang menunjuk ke node berikutnya di dalam urutan). Single Linked List ini dibagi menjadi dua macam, yaitu:
    - Single Linked List non Circular</br>
    Sebuah Single Linked List non-circular adalah struktur data linear yang tersusun dari node-node yang terhubung satu sama lain. Namun, pada Single Linked List non-circular, pointer next pada node terakhir akan menunjuk ke NULL. Ini menandakan akhir dari list. Setiap node pada linked list mempunyai field yang berisi pointer ke node berikutnya, dan juga memiliki field yang berisi data. Node terakhir akan menunjuk ke NULL yang akan digunakan sebagai kondisi berhenti pada saat pembacaan isi linked list.</br>
    - Single Linked List Cirucular</br>
    Sebuah Single Linked List circular mirip dengan Single Linked List non-circular, namun dengan perbedaan pada pointer next pada node terakhir. Dalam Single Linked List circular, pointer next pada node terakhir akan menunjuk kembali ke node pertama (head) sehingga membentuk lingkaran tertutup. Setiap node pada linked list mempunyai field yang berisi pointer ke node berikutnya, dan juga memiliki field yang berisi data. Pada akhir linked list, node terakhir akan menunjuk ke node terdepan sehingga linked list tersebut berputar. Node terakhir akan menunjuk lagi ke head.</br>
<p>Perbedaan single circular linked list dan single non circular linked list adalah penunjuk next pada node terakhir pada circular linked list akan selalu merujuk ke node pertama. Untuk Single Linked List non Circular, pada node terakhir/ ekor yang semula menunjuk ke NULL, sedangkan untuk Single Linked List Circular, pada node terakhir/ ekor yang semula menunjuk ke kepala atau head.</p>

- Double Linked List</br>
Doubly linked list (DLL) adalah jenis struktur data khusus yang termasuk dalam linked list.  Berbeda dengan single linked list yang hanya memiliki penunjuk ke node selanjutnya, pada doubly linked list setiap node memiliki dua buah penunjuk, yaitu prev dan next.</br>
    - Double Linked List non Circular</br>
    DLLnC adalah DLL pada umumnya, dimana pointer prev dan next pada node terakhir akan menunjuk ke NULL. Tidak ada hubungan melingkar antar node. Navigasi bisa dilakukan maju dan mundur, namun terhenti di node pertama (tidak bisa mundur lagi) dan node terakhir (tidak bisa maju lagi).</br>
    - Double Linked List Circular</br>
    DLLC memiliki struktur melingkar. Pointer next pada node terakhir akan menunjuk kembali ke node pertama, dan pointer prev pada node pertama akan menunjuk ke node terakhir. Navigasi bisa dilakukan terus menerus, maju bisa kembali ke awal, dan mundur bisa kembali ke akhir.
<p>Double linked list non-circular memiliki struktur linear dengan pointer null di awal dan akhir, sedangkan double linked list circular memiliki struktur melingkar tanpa pointer null dan memungkinkan navigasi data maju dan mundur terus menerus.</p>

## Guided 

### 1. Linked List Non Circular

```C++
#include <iostream>

using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR

// Deklarasi struct node
struct Node
{
    int data;
    Node *next;
};

Node *head; // Deklarasi head
Node *tail; // Deklarasi tail

// Inisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}

// Pengecekkan apakah linked list kosong
bool isEmpty()
{
    if (head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
    // Tambah depan
    void insertDepan(int nilai)
    {

        // buat node baru
        Node *baru = new Node();
        baru->data = nilai;
        baru->next = NULL;
        if (isEmpty() == true)
        {
            head = tail = baru;
            head->next = NULL;
        }
        else
        {
            baru->next = head;
            head = baru;
        }
    }

    // Tambah belakang
    void insertBelakang(int nilai)
    {
        // buat node baru
        Node *baru = new Node();
        baru->data = nilai;
        baru->next = NULL;
        if (isEmpty() == true)
        {
            head = tail = baru;
            head->next = NULL;
        }
        else
        {
            tail->next = baru;
            tail = baru;
        }
    }

    // Hitung jumlah list
    int hitungList()
    {
        Node *hitung;
        hitung = head;
        int jumlah = 0;
        while (hitung != NULL)
        {
            jumlah++;
            hitung = hitung->next;
        }
        return jumlah;
    }

    // Tambah tengah
    void insertTengah(int data, int posisi)
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else
        {
            Node *baru, *bantu;
            baru = new Node();
            baru->data = data;

            // tranversing
            bantu = head;
            int nomor = 1;
            while (nomor < posisi - 1)
            {
                bantu = bantu->next;
                nomor++;
            }

            baru->next = bantu->next;
            bantu->next = baru;
        }
    }

    // Hapus depan
    void hapusDepan()
    {
        Node *hapus;
        if (isEmpty() == false)
        {
            if (head->next != NULL)
            {
                hapus = head;
                head = head->next;
                delete hapus;
            }
            else
            {
                head = tail = NULL;
            }
        }
        else
        {
            cout << "Linked list masih kosong" << endl;
        }
    }

    // Hapus belakang
    void hapusBelakang()
    {
        Node *hapus;
        Node *bantu;
        if (isEmpty() == false)
        {
            if (head != tail)
            {
                hapus = tail;
                bantu = head;
                while (bantu->next != tail)
                {
                    bantu = bantu->next;
                }
                tail = bantu;
                tail->next = NULL;
                delete hapus;
            }
            else
            {
                head = tail = NULL;
            }
        }
        else
        {
            cout << "Linked list masih kosong" << endl;
        }
    }
    // Hapus tengah
    void hapusTengah(int posisi)
    {
        Node *hapus, *bantu, *sebelum;
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else
        {
            int nomor = 1;
            bantu = head;
            while (nomor <= posisi)
            {
                if (nomor == posisi - 1)
                {
                    sebelum = bantu;
                }
                if (nomor == posisi)
                {
                    hapus = bantu;
                }
                bantu = bantu->next;
                nomor++;
            }
            sebelum->next = bantu;
            delete hapus;
        }
    }

    // ubah depan
    void ubahDepan(int data)
    {
        if (isEmpty() == 0)
        {
            head->data = data;
        }
        else
        {
            cout << "Linked list masih kosong" << endl;
        }
    }

    // ubah tengah
    void ubahTengah(int data, int posisi)
    {
        Node *bantu;
        if (isEmpty() == 0)
        {
            if (posisi < 1 || posisi > hitungList())
            {
                cout << "Posisi di luar jangkauan" << endl;
            }
            else if (posisi == 1)
            {
                cout << "Posisi bukan posisi tengah" << endl;
            }
            else
            {
                int nomor = 1;
                bantu = head;
                while (nomor < posisi)
                {
                    bantu = bantu->next;
                    nomor++;
                }
                bantu->data = data;
            }
        }
        else
        {
            cout << "Linked list masih kosong" << endl;
        }
    }

    // ubah belakang
    void ubahBelakang(int data)
    {
        if (isEmpty() == 0)
        {
            tail->data = data;
        }
        else
        {
            cout << "Linked list masih kosong" << endl;
        }
    }

    // Hapus list
    void clearList()
    {
        Node *bantu, *hapus;
        bantu = head;
        while (bantu != NULL)
        {
            hapus = bantu;
            bantu = bantu->next;
            delete hapus;
        }
        head = tail = NULL;
        cout << "List berhasil terhapus!" << endl;
    }

    // Tampilkan list
    void tampil()
    {
        Node *bantu;
        bantu = head;
        if (isEmpty() == false)
        {
            while (bantu != NULL)
            {
                cout << bantu->data << " ";
                bantu = bantu->next;
            }
            cout << endl;
        }
        else
        {
            cout << "Linked list masih kosong" << endl;
        }
    }

    int main()
    {
        init();
        insertDepan(3);
        tampil();
        insertBelakang(5);
        tampil();
        insertDepan(2);
        tampil();
        insertDepan(1);
        tampil();
        hapusDepan();
        tampil();
        hapusBelakang();
        tampil();
        insertTengah(7, 2);
        tampil();
        hapusTengah(2);
        tampil();
        ubahDepan(1);
        tampil();
        ubahBelakang(8);
        tampil();
        ubahTengah(11, 2);
        tampil();

        return 0;
    }
```
Kode di atas digunakan untuk menjalankan linked list non circular. Struct node ini dideklarasikan dengan int data dan Node *next. Inisialisasi node nya juga dengan prosedur void init(), head dan tailnya dideklarasikan NULL. Ada juga fungsi bool isEmpty() untuk mengecek apakah kosong atau tidak. Berikut ini adalah fungsi-fungsi yang akan dipanggil dalam int main():
- void insertDepan(int nilai)</br>
    Digunakan untuk menambahkan data di depan
- void insertBelakang(int nilai)</br>
    Digunakan untuk menambahkan data di belakang
- int hitungList()</br>
    Digunakan untuk menghitung jumlah data yang ada
- void insertTengah(int data, int posisi)</br>
    Digunakan untuk menambahkan data sesuai posisi yang diinginkan user
- void hapusDepan()</br>
    Digunakan untuk menghapus data di depan
- void hapusBelakang()</br>
    Digunakan untuk menghapus data di belakang
- void hapusTengah(int posisi)</br>
    Digunakan untuk menghapus data sesuai posisi yang diinginkan user
- void ubahDepan(int data)</br>
    Digunakan untuk mengubah data di depan
- void ubahTengah(int data, int posisi)</br>
    Digunakan untuk mengubah data sesuai posisi yang diinginkan user
- void ubahBelakang(int data)</br>
    Digunakan untuk mengubah data di belakang
- void clearList()</br>
    Digunakan untuk menghapus seluruh data
- void tampil()</br>
    Digunakan untuk menampilkan data</br>
<p>Lalu, di dalam int main() dideklarasikan fungsi-fungsi tersebut. Hasil akhir pada pendeklarasian tersebut adalah 1 11.</p>

### 2. Linked List Circular

```C++
#include <iostream>

using namespace std;

// PROGRAM SINGLE LINKED LIST CIRCULAR

// Deklarasi struct node
struct Node
{
    string data;
    Node *next;
};

Node *head, *tail, *baru, *bantu, *hapus;

// Inisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}

// Pengecekkan apakah linked list kosong
int isEmpty()
{
    if (head == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Buat node baru
void buatNode(string data)
{
    baru = new Node();
    baru->data = data;
    baru->next = baru;
}

// Hitung list
int hitungList()
{
    int jumlah = 0;
    bantu = head;
    while (bantu->next != head)
    {
        jumlah++;
        bantu = bantu->next;
    }
    return jumlah;
}

// Tambah depan
void insertDepan(string data)
{
    // Buat node baru
    buatNode(data);
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// Tambah belakang
void insertBelakang(string data)
{
    // Buat node baru
    buatNode(data);
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        tail->next = baru;
        baru->next = head;
    }
}

// Tambah tengah
void insertTengah(string data, int posisi)
{
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        baru->data = data;

        // transversing
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus depan
void hapusDepan()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;

        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;
            delete hapus;
        }
        else
        {
            while (tail->next != head)
            {
                tail = tail->next;
            }
            head = head->next;
            tail->next = head;
            delete hapus;
        }
    }
    else
    {
        cout << "Linked list kosong" << endl;
    }
}

// Hapus belakang
void hapusBelakang()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;

        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;
            delete hapus;
        }
        else
        {
            while (hapus->next != head)
            {
                tail = hapus;
                hapus = hapus->next;
            }
            tail->next = head;
            delete hapus;
        }
    }
    else
    {
        cout << "Linked list kosong" << endl;
    }
}

// hapus tengah
void hapusTengah(int posisi)
{
    if (isEmpty() == 0)
    {
        // transversing
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus list
void hapusList()
{
    if (head != NULL)
    {
        hapus = head->next;
        while (hapus != head)
        {
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }
        delete head;
        head = NULL;
    }
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan list
void tampil()
{
    if (isEmpty() == 0)
    {
        tail = head;
        do
        {
            cout << tail->data << ends;
            tail = tail->next;
        } while (tail != head);
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

int main()
{
    init();
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();
    return 0;
}
```
Kode di atas digunakan untuk menjalankan linked list circular. Struct Node ini dideklarasikan dengan string data dan Node *next. Kemudian ada pointer Node *head, *tail, *baru, *bantu, *hapus. Ada juga void init() untuk menginisiasi di mana head = NULL dan tail = head. Lalu ada int isEmpty() untuk mengecek apakah kosong atau tidak. Terakhir ada void buatNode(string data) untuk membuat node baru. Berikut ini adalah fungsi-fungsi yang akan dipanggil dalam int main():
- int hitungList()</br>
    Digunakan untuk menghitung jumlah yang ada pada list
- void insertDepan()</br>
    Digunakan untuk menambahkan data di depan
- void insertBelakang()</br>
    Digunakan untuk menambahkan data di belakang
- void insertTengah()</br>
    Digunakan untuk menambahkan data di tengah
- void hapusDepan()</br>
    Digunakan untuk menghapus data di depan
- void hapusBelakang()</br>
    Digunakan untuk menghapus data di belakang
- void hapusTengah()</br>
    Digunakan untuk menghapus data di tengah
- void clearList()</br>
    Digunakan untuk menghapus semua
- void tampil()</br>
    Digunakan untuk menampilkan data yang ada pada list</br>
<p>Lalu, di dalam int main() dideklarasikan fungsi-fungsi tersebut. Hasil akhir pada pendeklarasian tersebut adalah AyamSapiCicak.</p>

## Unguided 
   Buatlah program menu Linked List Non Circular untuk menyimpan Nama dan NIM mahasiswa, dengan menggunakan input dari user

```C++
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
```
### 1. Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan NIM mahasiswa
#### Output Unguided 1:
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/6ada597d-f79e-4150-ac3b-74262a8c2f3b)</br>
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/a4947a1f-a2eb-4ea5-8135-026ad293ea7a)</br>
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/5c699c4e-8214-4c06-8f0e-0294b7f760b9)</br>
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/3dbae2f4-37be-47dd-9201-ceb54d1ad524)</br>
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/2376edc1-8886-4619-b09f-3a938e233462)</br>
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/13493c15-2883-4890-af5f-ffb3d33b5a23)</br>
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/691dabad-03f9-443e-a091-e1b6c38d2b0b)</br>
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/381d1e3a-307c-47da-8c70-6ed0556fbecc)</br>

### 2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah)
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/83ab6ccf-bc5a-4313-a554-f6cb76218e53)</br>

#### Output Unguided 2:
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/587dbf17-5a96-4345-abec-bedffef3d158)</br>
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/e1ab98e0-4f7e-4bfc-a0b7-d68605574056)</br>
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/19971b18-ac00-406b-b893-fa02662e6c0a)</br>
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/801fd5fc-c629-46a0-b165-632179d851fc)</br>
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/9d0da450-a15e-4200-9120-90c908e0fc6c)</br>
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/2b34e258-0abe-4018-a921-a230302da712)</br>
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/89b12880-e675-4d50-a34f-807ad33831dd)</br>
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/1578447d-ce06-4952-8743-630cb3b138c7)</br>
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/7969201d-6d12-4fc6-b8cc-e097ea4383bb)</br>
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/7c1c9796-728a-4581-9af4-b1b2884b976a)</br>

### 3. Lakukan perintah berikut:</br> a) Tambahkan data berikut diantara Farrel dan Denis: Wati 2330004</br> b) Hapus data Denis</br> c) Tambahkan data berikut di awal: Owi 2330000</br> d) Tambahkan data berikut di akhir: David 23300100</br> e) Ubah data Udin menjadi data berikut: Idin 23300045</br> f) Ubah data terkahir menjadi berikut: Lucy 23300101 g) Hapus data awal</br> h) Ubah data awal menjadi berikut: Bagas 2330002</br> i) Hapus data akhir</br> j) Tampilkan seluruh data

#### Output Unguided 3:
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/680413a9-95de-4529-a6ac-497747d59fab)</br>
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/30ec7cee-2af1-4aea-b656-34a139a11aef)</br>
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/9dbae6a7-3474-4e71-bee8-e80155b9f001)</br>
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/192f4c73-f948-41a3-8ca5-f3c444d2f335)</br>
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/d527677c-5428-4362-b841-8927e8f41517)</br>
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/d73b375a-dcfe-4f54-bcad-4bf35cf99846)</br>
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/2000175f-ee34-4382-99fa-3065fdb26a90)</br>
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/564267b5-6a39-4f89-a0e0-dba65d98c198)</br>
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/b00ebc50-3c26-44aa-963e-323e4b7c738e)</br>

Kode di atas digunakan untuk menjalankan linked list non circular untuk menyimpan nama dan NIM mahasiswa, dengan input dari user. Struct node ini dideklarasikan dengan long long NIM_2176, string Name_2176, dan Node* next. Inisialisasi node nya juga dengan prosedur void Initialize_2176(), head dan tailnya dideklarasikan NULL. Ada juga fungsi bool ItsEmpty_2176() untuk mengecek apakah kosong atau tidak. Berikut ini adalah fungsi-fungsi yang akan dipanggil dalam int main():
- void InsertFront_2176(string name, int age)</br>
    Digunakan untuk menambahkan data di depan
- void InsertBack_2176(string name, int age)</br>
    Digunakan untuk menambahkan data di belakang
- int CountList_2176()</br>
    Digunakan untuk menghitung jumlah data yang ada
- void InsertMiddle_2176(string name, int age, int posisi)</br>
    Digunakan untuk menambahkan data sesuai posisi yang diinginkan user
- void EraseFront_2176()</br>
    Digunakan untuk menghapus data di depan
- void EraseBack_2176()</br>
    Digunakan untuk menghapus data di belakang
- void EraseMiddle_2176(int posisi)</br>
    Digunakan untuk menghapus data sesuai posisi yang diinginkan user
- void ChangeFront_2176(string name, int age)</br>
    Digunakan untuk mengubah data di depan
- void ChangeMiddle_2176(string name, int age, int posisi)</br>
    Digunakan untuk mengubah data sesuai posisi yang diinginkan user
- void ChangeBack_2176(string name, int age)</br>
    Digunakan untuk mengubah data di belakang
- void EraseList_2176()</br>
    Digunakan untuk menghapus seluruh data
- void Reveal_2176()</br>
    Digunakan untuk menampilkan data, dilengkapi dengan setw left & right dari library iomanip supaya outputnya rapi dan linear. </br>
<p>Lalu, pada int main(), diawali dengan inisialisasi linked list non circular ini dengan Initialize_2176(). Pertama, program ini dijalankan terlebih dahulu supaya user dapat menginput data-datanya melalui cin. User menginput data Jawad (23300001) hingga Budi (23300099) dari Unguided 2 dengan bantuan InsertFront_2176 dan InsertBack_2176. Setelah semua data telah diinput oleh user, data tersebut kemudian dimodifikasi.</p></br>
    a. Menambahkan data Wati (2330004) dengan InsertMiddle_2176()</br>
    b. Menghapus data Denis dengan EraseMiddle_2176()</br>
    c. Menambahkan data Owi (2330000) dengan InsertFront_2176()</br>
    d. Menambahkan data David (23300100) dengan InsertBack_2176()</br>
    e. Mengubah data Udin menjadi Idin (23300045) dengan ChangeMiddle_2176()</br>
    f. Mengubah data akhir menjadi Lucy (23300101) dengan ChangeBack_2176()</br>
    g. Menghapus data awal dengan EraseFront_2176()</br>
    h. Mengubah data awal menjadi Bagas (2330002) dengan ChangeFront_2176()</br>
    i. Menghapus data akhir dengan EraseBack_2176()</br>
    j. Tampilkan seluruh data dengan Reveal_2176()</br>

  ## Kesimpulan
   Linked list adalah struktur data linear yang terdiri dari node-node yang terhubung. Single linked list memiliki pointer next untuk menghubungkan node, sedangkan double linked list memiliki pointer prev dan next untuk navigasi dua arah.

Single Linked List</br>
- Non-circular: Pointer next pada node terakhir menunjuk ke NULL.</br>
- Circular: Pointer next pada node terakhir menunjuk kembali ke node pertama.</br>

Double Linked List</br>
- Non-circular: Pointer prev dan next pada node terakhir menunjuk ke NULL.</br>
- Circular: Pointer next pada node terakhir menunjuk kembali ke node pertama, dan pointer prev pada node pertama menunjuk ke node terakhir.</br>

Pemilihan jenis linked list tergantung pada kebutuhan operasi yang akan dilakukan pada data.</br>
- Circular linked list: Cocok untuk navigasi data maju dan mundur terus menerus, serta lebih fleksibel dalam hal navigasi.</br>
- Non-circular linked list: Lebih sederhana dan efisien dalam hal memori.</br>

## Referensi
[1] Anita Sindar RMS, Struktur Data dan Algoritma C++, Banten: CV. AA. Rizky, 2019.</br>
[2] Muhammad Nugraha, Dasar Pemrograman Dengan C++, Materi Paling Dasar untuk Menjadi Programmer Berbagai Platform. Yogyakarta: Deepublish, 2021.




































