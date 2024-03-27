# <h1 align="center">Laporan Praktikum Modul 3 - SINGLE AND DOUBLE LINKED LIST</h1>
<p align="center">Destia Ananda Putra - 2311102176</p>

# A.Dasar Teori 

1) Single Linked List</br>
Linked List merupakan suatu bentuk struktur data yang berisi kumpulan data yang disebut sebagai node yang tersusun secara sekuensial, saling sambung menyambung, dinamis, dan terbatas. Setiap elemen dalam linked list dihubungkan ke elemen lain melalui pointer. Masing-masing komponen sering disebut dengan simpul atau node atau verteks. Pointer adalah alamat elemen.
Setiap simpul pada dasarnya dibagi atas dua bagian pertama disebut bagian isi atau informasi atau data yang berisi nilai yang disimpan oleh simpul. Bagian kedua disebut bagian pointer yang berisi alamat dari node berikutnya atau sebelumnya. Dengan menggunakan struktur seperti ini, linked list dibentuk dengan cara menunjuk pointer next suatu elemen ke elemen yang mengikutinya. Pointer next pada elemen terakhir merupakan NULL, yang menunjukkan akhir dari suatu list. Elemen pada awal suatu list disebut head dan elemen terakhir dari suatu list disebut tail.</br>

![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/628d5dd1-9587-4365-b3aa-0acc1fd921e1) </br>

Dalam operasi Single Linked List, umumnya dilakukan operasi penambahan dan penghapusan simpul pada awal atau akhir daftar, serta pencarian dan pengambilan nilai pada simpul tertentu dalam daftar. Karena struktur data ini hanya memerlukan satu pointer untuk setiap simpul, maka Single Linked List umumnya lebih efisien dalam penggunaan memori dibandingkan dengan jenis
Linked List lainnya, seperti Double Linked List dan Circular Linked List. Single linked list yang kedua adalah circular linked list. Perbedaan circularlinked list dan non circular linked adalah penunjuk next pada node terakhir pada circular linked list akan selalu merujuk ke node pertama.</br>

![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/38bf0ab5-3345-49d2-8d63-2606939ffc77) </br>

2) Double Linked List
Double Linked List adalah struktur data Linked List yang mirip dengan Single Linked List, namun dengan tambahan satu pointer tambahan pada setiap simpul yaitu pointer prev yang menunjuk ke simpul sebelumnya. Dengan adanya pointer prev, Double Linked List memungkinkan untuk melakukan operasi penghapusan dan penambahan pada simpul mana saja secara efisien. Setiap simpul pada Double Linked List memiliki tiga elemen penting, yaitu elemen data (biasanya berupa nilai), pointer next yang menunjuk ke simpul berikutnya, dan pointer prev yang menunjuk ke simpul sebelumnya.</br>

Keuntungan dari Double Linked List adalah memungkinkan untuk melakukan operasi penghapusan dan penambahan pada simpul dimana saja dengan efisien, sehingga sangat berguna dalam implementasi beberapa algoritma yang membutuhkan operasi tersebut. Selain itu, Double Linked List juga memungkinkan kita untuk melakukan traversal pada list baik dari depan (head) maupun dari belakang (tail) dengan mudah. Namun, kekurangan dari Double Linked List adalah penggunaan memori yang lebih besar dibandingkan dengan Single Linked List, karena setiap simpul membutuhkan satu pointer tambahan. Selain itu, Double Linked List juga membutuhkan waktu eksekusi yang lebih lama dalam operasi penambahan dan penghapusan jika dibandingkan dengan Single Linked List.</br>

Representasi sebuah double linked list dapat dilihat pada gambar berikut ini:</br>

![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/cc09662c-8be9-4dbc-8d51-d51a0394c0ad)</br>

Di dalam sebuah linked list, ada 2 pointer yang menjadi penunjuk utama, yakni pointer HEAD yang menunjuk pada node pertama di dalam linked list itu sendiri dan pointer TAIL yang menunjuk pada node paling akhir di dalam linked list. Sebuah linked list dikatakan kosong apabila isi pointer head adalah NULL. Selain itu, nilai pointer prev dari HEAD selalu NULL, karena merupakan data pertama. Begitu pula dengan pointer next dari TAIL yang selalu bernilai NULL sebagai penanda data terakhir.

# B. Guided

# 1. Latihan Single Linked List

```C++
#include <iostream>
using namespace std;

///PROGRAM SINGLE LINKED LIST NON-CIRCULAR
//Deklarasi Struct Node
struct Node{
//komponen/member
int data;
Node *next;
};
Node *head;
Node *tail;
//Inisialisasi Node
void init(){
head = NULL;
tail = NULL;
}
// Pengecekan
bool isEmpty(){
if (head == NULL)
return true;
else
return false;
}
//Tambah Depan
void insertDepan(int nilai){
//Buat Node baru
Node *baru = new Node;
baru->data = nilai;
baru->next = NULL;
if (isEmpty() == true){
head = tail = baru;
tail->next = NULL;

}
else{
baru->next = head;
head = baru;
}
}
//Tambah Belakang
void insertBelakang(int nilai){
//Buat Node baru
Node *baru = new Node;
baru->data = nilai;
baru->next = NULL;
if (isEmpty() == true){
head = tail = baru;
tail->next = NULL;
}
else{
tail->next = baru;
tail = baru;
}
}
//Hitung Jumlah List
int hitungList(){
Node *hitung;
hitung = head;
int jumlah = 0;
while( hitung != NULL ){
jumlah++;
hitung = hitung->next;
}
return jumlah;
}
//Tambah Tengah
void insertTengah(int data, int posisi){
if( posisi < 1 || posisi > hitungList() ){
cout << "Posisi diluar jangkauan" << endl;

}
else if( posisi == 1){
cout << "Posisi bukan posisi tengah" <<

endl;
}
else{
Node *baru, *bantu;
baru = new Node();
baru->data = data;
// tranversing
bantu = head;
int nomor = 1;
while( nomor < posisi - 1 ){
bantu = bantu->next;
nomor++;
}
baru->next = bantu->next;
bantu->next = baru;
}
}
//Hapus Depan
void hapusDepan() {
Node *hapus;
if (isEmpty() == false){
if (head->next != NULL){
hapus = head;
head = head->next;
bantu = head;
while( nomor <= posisi ){

if( nomor == posisi-1 ){
bantu2 = bantu;
}
if( nomor == posisi ){
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
void ubahDepan(int data){
if (isEmpty() == false){
head->data = data;
}
else{
cout << "List masih kosong!" << endl;
}
}
//Ubah Tengah
void ubahTengah(int data, int posisi){
Node *bantu;
if (isEmpty() == false){
if( posisi < 1 || posisi > hitungList() ){
cout << "Posisi di luar jangkauan" <<

endl;
}
else if( posisi == 1){
cout << "Posisi bukan posisi tengah" <<

endl;
}
else{
bantu = head;
int nomor = 1;

while (nomor < posisi){
bantu = bantu->next;nomor++;
}
bantu->data = data;
}
}
else{
cout << "List masih kosong!" << endl;
}
}
//Ubah Belakang
void ubahBelakang(int data){
if (isEmpty() == false){
tail->data = data;
}
else{
cout << "List masih kosong!" << endl;
}
}
//Hapus List
void clearList(){
Node *bantu, *hapus;
bantu = head;
while (bantu != NULL){
hapus = bantu;
bantu = bantu->next;
delete hapus;
}
head = tail = NULL;
cout << "List berhasil terhapus!" << endl;
}
//Tampilkan List
void tampil(){
Node *bantu;
bantu = head;
if (isEmpty() == false){

while (bantu != NULL){
cout << bantu->data << ends;
bantu = bantu->next;
}
cout << endl;
}
else{
cout << "List masih kosong!" << endl;
}
}
int main(){
init();
insertDepan(3);tampil();
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
insertTengah(7,2);
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
#output</br>
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/3d9f0380-6328-46d0-b178-6ef41f02998e)</br>
Output tersebut menunjukkan bahwa linked list berisi empat simpul, di mana setiap simpul menyimpan nama dan usia mahasiswa. Dalam hal ini, nama dan usia ditampilkan untuk setiap simpul dalam urutan yang sesuai dengan struktur linked list.
# 2. Latihan Double Linked List Source
```C++
#include <iostream>
using namespace std;
class Node {
public:int data;
Node* prev;
Node* next;
};
class DoublyLinkedList {

public:
Node* head;
Node* tail;
DoublyLinkedList() {
head = nullptr;
tail = nullptr;

}
void push(int data) {
Node* newNode = new Node;
newNode->data = data;
newNode->prev = nullptr;
newNode->next = head;
if (head != nullptr) {
head->prev = newNode;
}
else {
tail = newNode;
}
head = newNode;
}
void pop() {
if (head == nullptr) {
return;
}
Node* temp = head;
head = head->next;
if (head != nullptr) {
head->prev = newNode;
}
else {
tail = newNode;
}
head = newNode;
}
void pop() {
if (head == nullptr) {
return;
}
Node* temp = head;
head = head->next;
if (head != nullptr) {
head->prev = nullptr;
}
else {
tail = nullptr;
}
delete temp;
}
bool update(int oldData, int newData) {
Node* current = head;while (current != nullptr) {
if (current->data == oldData) {
current->data = newData;
return true;
}
current = current->next;
}

return false;
}
void deleteAll() {
Node* current = head;
while (current != nullptr) {
Node* temp = current;
current = current->next;
delete temp;
}
head = nullptr;
tail = nullptr;
}
void display() {
Node* current = head;
while (current != nullptr) {
cout << current->data << " ";
current = current->next;
}
cout << endl;
}
};
int main() {
DoublyLinkedList list;
while (true) {
cout << "1. Add data" << endl;
cout << "2. Delete data" << endl;
cout << "3. Update data" << endl;
cout << "4. Clear data" << endl;
cout << "5. Display data" << endl;
cout << "6. Exit" << endl;int choice;
cout << "Enter your choice: ";
cin >> choice;
switch (choice) {
case 1: {
int data;
cout << "Enter data to add: ";
cin >> data;
list.push(data);
break;
}
case 2: {
list.pop();
break;
}
case 3: {
int oldData, newData;
cout << "Enter old data: ";
cin >> oldData;
cout << "Enter new data: ";
cin >> newData;
bool updated = list.update(oldData,

newData);

if (!updated) {
cout << "Data not found" << endl;
}
break;

}
case 4: {
list.deleteAll();
break;
}
case 5: {
list.display();
break;
}
case 6: {
return 0;
}
default: {
cout << "Invalid choice" << endl;
break;
}
}
}
return 0;
}
```
# Output
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/e778f516-c02a-4eef-9b72-726621aa5c04)

 program akan tergantung pada operasi yang dilakukan pengguna melalui menu. Misalnya, jika pengguna memilih untuk menambahkan produk baru, produk tersebut akan ditambahkan ke daftar dan output akan mencantumkan produk tersebut. Begitu juga untuk operasi lainnya seperti menghapus atau memperbarui produk. Program ini memberikan fleksibilitas bagi pengguna untuk mengelola daftar produk sesuai kebutuhan</br>

# Unguided 

# 1. Soal mengenai Single Linked List
Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan dari user. Lakukan operasi berikut:

a.	Masukkan data sesuai urutan berikut. (Gunakan insert depan, belakang atau tengah). Data pertama yang dimasukkan adalah nama dan usia anda.
[Nama_anda]	[Usia_anda]
John	            19
Jane	            20
Michael	          18
Yusuke	          19
Akechi	          20
Hoshino	          18
Karin	            18
b.	Hapus data Akechi
c.	Tambahkan data berikut diantara John dan Jane : Futaba	18
d.	Tambahkan data berikut diawal : Igor	20
e.	Ubah data Michael menjadi : Reyn	18
f.	Tampilkan seluruh data
```C++
// LAPRAK 3 : UNGUIDED 1
// Destia Ananda Putra
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
```
# Output
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/98f206be-ec07-4959-83c8-f03ef59af2ac)</br>
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/c4aa2f26-f898-41f9-891a-841a26762d28)</br>
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/a942f7bd-85d5-45e4-a875-4a8a11a37272)</br>
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/5610b273-a97c-4f60-93e7-cc0376798f3a)</br>

Program yang diminta adalah menu Single Linked List Non-Circular yang memungkinkan pengguna untuk memasukkan data mahasiswa, melakukan operasi seperti insert di depan, belakang, atau di tengah, serta menampilkan seluruh data. Setiap data mahasiswa terdiri dari nama dan usia.memberikan fungsionalitas yang cukup baik untuk pengelolaan data mahasiswa. Pengguna dapat dengan mudah menambahkan data baru, menghapus data yang tidak diperlukan, atau mengubah data yang ada,Dengan menggunakan menu, program ini menjadi lebih mudah digunakan oleh pengguna. Mereka dapat memilih operasi yang diinginkan tanpa perlu mengetikkan kode langsung.</br>

# 2. Soal mengenai Double Linked List
Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga.<br>
Nama           |    Produk	Harga
---------------|-----------------
Originote	   |        60.000
Somethinc	   |        150.000
Skintific	   |        100.000
Wardah	       |        50.000
Hanasui	       |        30.000
</br>

Case:</br>
1.	Tambahkan produk Azarine dengan harga 65000 diantara
Somethinc dan Skintific
2.	Hapus produk wardah
3.	Update produk Hanasui menjadi Cleora dengan harga 55.000
4.	Tampilkan menu seperti dibawah ini
Toko Skincare Purwokerto
1.	Tambah Data
2.	Hapus Data
3.	Update Data
4.	Tambah Data Urutan Tertentu
5.	Hapus Data Urutan Tertentu
6.	Hapus Seluruh Data
7.	Tampilkan Data
8.	Exit
Pada menu 7, tampilan akhirnya akan menjadi seperti dibawah
ini :</br>
![alt text](<Screenshot 2024-03-26 225640.png>)</br>
```C++
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
```
# Output
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/b140d5fb-9bac-4a52-a128-51e686fbeedc)</br>
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/e3b6a47c-2f61-4b38-a7d4-2eafa82c14f5)</br>
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/a877da2d-fbff-4729-9766-5df747e5087d)</br>
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/c10de1ba-8893-4d96-b7ee-79c0cec4fe2a)</br>

Output dari program ini akan menampilkan menu berisi opsi-opsi yang dapat dilakukan pengguna, seperti menambah data, menghapus data, memperbarui data, dan lain-lain. Setiap kali opsi dipilih, program akan menampilkan hasil operasi yang dilakukan, serta menampilkan data terkini dalam linked list.
program ini akan menampilkan menu berisi opsi-opsi yang dapat dilakukan pengguna, seperti menambah data, menghapus data, memperbarui data, dan lain-lain. Setiap kali opsi dipilih, program akan menampilkan hasil operasi yang dilakukan, serta menampilkan data terkini dalam linked list.
program yang dimodifikasi telah menambahkan operasi-operasi tambahan untuk menambah data di urutan tertentu, menghapus data tertentu, serta memperbarui data tertentu. Semua operasi tersebut telah diimplementasikan dengan memanfaatkan struktur Double Linked List.

# Kesimpulan 
Linked List adalah struktur data linear yang terdiri dari sejumlah simpul yang saling terhubung. Single Linked List hanya memiliki pointer ke simpul berikutnya, sementara Double Linked List memiliki pointer ke simpul sebelumnya dan berikutnya. Meskipun kedua jenis linked list dapat melakukan operasi dasar seperti penambahan, penghapusan, dan pencarian data, Double Linked List lebih fleksibel karena dapat melakukan traversing mundur dan operasi di tengah-tengah linked list dengan lebih efisien. Namun, Double Linked List menggunakan lebih banyak memori karena setiap simpul memiliki dua pointer tambahan, sementara Single Linked List hanya memiliki satu pointer untuk setiap simpul. Oleh karena itu, pemilihan antara kedua jenis linked list tergantung pada kebutuhan spesifik aplikasi, dengan pertimbangan utama antara efisiensi operasi dan penggunaan memori.

# Referensi
[1] Putra, A. k. (2019, April 25). Single linked list.
[2] Dharma, A. (2018). Aplikasi Sistem Linked List Berbasis Mobile Learning.







