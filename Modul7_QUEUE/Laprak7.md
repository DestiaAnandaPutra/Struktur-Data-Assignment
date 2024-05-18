# <h1 align="center">Laporan Praktikum Modul 7 - QUEUE </h1>
<p align="center">Fadhel Setiawan - 2311102171</p>

# TUJUAN PRAKTIKUM
1. Mahasiswa mampu menjelaskan definisi dan konsep dari double queue
2. Mahasiswa mampu menerapkan operasi tambah, menghapus pada queue
3. Mahasiswa mampu menerapkan operasi tampil data pada queue

# DASAR TEORI
Queue adalah struktur data yang digunakan untuk menyimpan data dengan metode FIFO (First-In First-Out). Data yang pertama dimasukkan ke dalam queue akan menjadi data yang pertama pula untuk dikeluarkan dari queue. Queue mirip dengan konsep antrian pada kehidupan sehari-hari, dimana konsumen yang datang lebih dulu akan dilayani terlebih dahulu.</br>
Implementasi queue dapat dilakukan dengan menggunakan array atau linked list. Struktur data queue terdiri dari dua pointer yaitu front dan rear. Front/head adalah pointer ke elemen pertama dalam queue dan rear/tail/back adalah pointer ke elemen terakhir dalam queue.</br>

![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/279e44ff-07a3-4389-a98a-c17e0879bbaa)</br>

Perbedaan antara stack dan queue terdapat pada aturan penambahan dan penghapusan elemen. Pada stack, operasi penambahan dan penghapusan elemen dilakukan di satu ujung. Elemen yang terakhir diinputkan akan berada paling dengan dengan ujung atau dianggap paling atas sehingga pada operasi penghapusan, elemen teratas tersebut akan dihapus paling awal, sifat demikian dikenal dengan LIFO.</br>

maupun delete. Prosedur ini sering disebut Enqueue dan Dequeue pada kasus Queue. Untuk Enqueue, cukup tambahkan elemen setelah elemen terakhir Queue, dan untuk Dequeue, cukup "geser"kan Head menjadi elemen selanjutnya.</br>

# Operasi pada Queue
- enqueue() : menambahkan data ke dalam queue.
- dequeue() : mengeluarkan data dari queue.
- peek() : mengambil data dari queue tanpa menghapusnya.
- isEmpty() : mengecek apakah queue kosong atau tidak.
- isFull() : mengecek apakah queue penuh atau tidak.
- size() : menghitung jumlah elemen dalam queue.

# Guided 1

```C++
#include <iostream>
using namespace std;

const int maksimalQueue = 5; 
int front = 0; 
int back = 0; 
string queueTeller[5]; 

bool isFull() { 
    if (back == maksimalQueue) {
        return true; 
    } else {
        return false;
    }
}

bool isEmpty() { 
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) { 
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        if (isEmpty()) { 
            queueTeller[0] = data;
            front++;
            back++;
        } else {
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() { 
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() { 
    return back;
}

void clearQueue() { 
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() { 
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```
# Output
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/13ddd298-6e0b-4c09-9e26-113660161163)</br>
<p align="justify">Program tersebut adalah sebuah implementasi sederhana dari struktur data queue dalam pemrograman. Queue adalah struktur data yang mengikuti prinsip "First In First Out" (FIFO), yang berarti elemen pertama yang dimasukkan ke dalam queue akan menjadi elemen pertama yang dihapus dan Program ini berfungsi untuk mengelola sebuah queue dengan batasan 5 elemen, menyediakan fungsi-fungsi dasar seperti menambah, menghapus, dan melihat isi queue serta mengecek apakah queue kosong atau penuh  Program ini memberikan penggunaan dasar dari queue dalam konteks antrian (queue) layanan.

# UNGUIDED 1 
```c++
#include <iostream>
using namespace std;

//Nama : Destia Ananda Putra
//NIM  : 2311102176


// Struktur node untuk linked list
struct Node {
  string Data_2176;
  Node* next;
};

// Deklarasi variabel awal
Node* head = NULL; // Penunjuk ke node head
Node* tail = NULL; // Penunjuk ke node tail

// Fungsi untuk memeriksa antrian kosong atau tidak
bool isEmpty() {
  return head == NULL;
}

// Fungsi untuk menambahkan Data_2176 ke antrian
void enqueueAntrian(string Data_2176) {
  Node* newNode = new Node; // Buat node baru
  newNode->Data_2176 = Data_2176; // Isi Data_2176 ke node
  newNode->next = NULL; // Set pointer next ke NULL

  if (isEmpty()) { // Jika antrian kosong
    head = newNode;
    tail = newNode;
  } else { // Jika antrian tidak kosong
    tail->next = newNode;
    tail = newNode;
  }
}

// Fungsi untuk mengeluarkan Data_2176 dari antrian
void dequeueAntrian() {
  if (isEmpty()) {
    cout << "Huh, this queue is empty! Nothing to dequeue!" << endl;
    return;
  }

  Node* temp = head; // Simpan head ke variabel temp
  head = head->next; // Pindahkan head ke node berikutnya
  delete temp; // Hapus node yang dikeluarkan

  if (head == NULL) { // Jika head menjadi NULL
    tail = NULL;
  }
}

// Fungsi untuk menghitung jumlah Data_2176 dalam antrian
int countQueue() {
  int count = 0;
  Node* current = head;
  while (current != NULL) {
    count++;
    current = current->next;
  }
  return count;
}

// Fungsi untuk menghapus semua Data_2176 dalam antrian
void clearQueue() {
  while (!isEmpty()) {
    dequeueAntrian();
  }
}

// Fungsi untuk menampilkan Data_2176 dalam antrian
void viewQueue() {
  if (isEmpty()) {
    cout << "The queue is empty!" << endl;
    return;
  }

  cout << "Data antrian teller:" << endl;
  Node* current = head;
  int i = 1;
  while (current != NULL) {
    cout << i << ". " << current->Data_2176 << endl;
    i++;
    current = current->next;
  }
}

int main() {
    cout << "\n-=-=-=- TELLER QUEUE -=-=-=-\n" << endl;
    cout << "-=- Enqueue/Add Tellers -=-" << endl;
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian: " << countQueue() << endl;

    cout << "\n-=- Dequeue/Remove Tellers -=-" << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian: " << countQueue() << endl;

    cout << "\n-=- Remove All Tellers -=-" << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian: " << countQueue() << endl;

    return 0;
}
```
# Output
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/23634eba-b802-4265-995a-7db4e2c6d72f)</br>
<p align="justify">Pada Program digunakan untuk menjalankan sebuah program queue dengan linked list. Pada guided, program queue dijalankan dengan array, tapi unguided 1 ini menjalankan program queue yang sama tetapi dengan konsep linked list. Pada program ini, terdapat struct Node, di mana struct ini memiliki string Data_2176 dan Node* next. Ada juga deklarasi Node* head = NULL dan Node* tail = NULL. Program ini tidak ada fungsi isFull() karena linked list tidak ada limit yang ditentukan Pada int main(), program ini menambahkan data "Andi" dan "Maya" dalam queue menggunakan enqueueAntrian("string"), ditampilkan dengan viewQueue(), dan jumlah queue ditampilkan dengan countQueue(). Lalu, program ini menghapus data pertama, yaitu "Andi" dengan dequeueAntrian(), ditampilkan dengan viewQueue(), dan jumlah queue ditampilkan sekali lagi dengan countQueue(). Terakhir, program ini menghapus seluruh queue dengan clearQueue() dan ditampilkan dengan viewQueue(), ditampilkan juga jumlah queue dengan countQueue().

# Unguided 2
```c++
#include <iostream>
using namespace std;

//Nama : Destia Ananda Putra
//NIM  : 2311102176


// Struktur node untuk linked list
struct Node {
  string NamaMahasiswa_2176;
  long long int NIMMahasiswa_2176;
  Node* next;
};

// Deklarasi variabel awal
Node* head = NULL; // Penunjuk ke node head
Node* tail = NULL; // Penunjuk ke node tail

// Fungsi untuk memeriksa antrian kosong atau tidak
bool isEmpty() {
  return head == NULL;
}

// Fungsi untuk menambahkan data ke antrian
void enqueueAntrian(string nama, long long int NIM) {
  Node* newNode = new Node; // Buat node baru
  newNode->NamaMahasiswa_2176 = nama;
  newNode->NIMMahasiswa_2176 = NIM;
  newNode->next = NULL; // Set pointer next ke NULL

  if (isEmpty()) { // Jika antrian kosong
    head = newNode;
    tail = newNode;
  } else { // Jika antrian tidak kosong
    tail->next = newNode;
    tail = newNode;
  }
}

// Fungsi untuk mengeluarkan data dari antrian
void dequeueAntrian() {
  if (isEmpty()) {
    cout << "Yo! The queue is empty! There's nothing to dequeue!" << endl;
    return;
  }

  Node* temp = head; // Simpan head ke variabel temp
  head = head->next; // Pindahkan head ke node berikutnya
  delete temp; // Hapus node yang dikeluarkan

  if (head == NULL) { // Jika head menjadi NULL
    tail = NULL;
  }
}

// Fungsi untuk menghitung jumlah data dalam antrian
int countQueue() {
  int count = 0;
  Node* current = head;
  while (current != NULL) {
    count++;
    current = current->next;
  }
  return count;
}

// Fungsi untuk menghapus semua data dalam antrian
void clearQueue() {
  while (!isEmpty()) {
    dequeueAntrian();
  }
}

// Fungsi untuk menampilkan data dalam antrian
void viewQueue() {
  if (isEmpty()) {
    cout << "Hey, the queue is empty!" << endl;
    return;
  }

  cout << "Mahasiswa Queue Data:" << endl;
  Node* current = head;
  int i = 1;
  while (current != NULL) {
    cout << i << ". " << current->NamaMahasiswa_2176 << " (" << current->NIMMahasiswa_2176 << ")" << endl;
    i++;
    current = current->next;
  }
}

int main() {
  cout << "\n-=-=-=- Queue Mahasiswa -=-=-=-" << endl;

  cout << "\n-=- Enqueue/Add Queue Mahasiswa -=-" << endl;
  enqueueAntrian("Destia", 2311102176);
  enqueueAntrian("Ananda", 2311102176);
  enqueueAntrian("Putra", 6712011132);
  enqueueAntrian("desap", 3211102176);
  viewQueue();
  cout << "Jumlah antrian: " << countQueue() << endl;

  cout << "\n-=- Dequeue/Remove Queue Mahasiswa -=-" << endl;
  dequeueAntrian();
  viewQueue();
  cout << "Jumlah antrian: " << countQueue() << endl;

  cout << "\n-=- Clear All Queues -=-" << endl;
  clearQueue();
  viewQueue();
  cout << "Jumlah antrian: " << countQueue() << endl;

  return 0;
}
```
# Output
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/9d0057cb-6c95-4ddb-85bc-458ceded5298)</br>
<p align="justify">Pada Program ini  digunakan untuk menjalankan sebuah program queue dengan linked list. Pada program ini, terdapat struct Node, di mana struct ini memiliki string NamaMahasiswa_2176, long long int NIMMahasiswa_2176, dan Node* next. Ada juga deklarasi Node* head = NULL dan Node* tail = NULL.dimana Program ini  sebuah antrian (queue) menggunakan linked list dimana Program ini mengimplementasikan operasi-operasi dasar pada antrian seperti enqueue (menambahkan elemen), dequeue (menghapus elemen), menghitung jumlah elemen, menghapus semua elemen, dan menampilkan elemen-elemen dalam antrian.Lalu ditampilkan dengan viewQueue(), dan jumlah queue ditampilkan dengan countQueue(). Lalu, program ini menghapus data pertama, yaitu "Destia"  dengan dequeueAntrian(), ditampilkan dengan viewQueue(), dan jumlah queue ditampilkan sekali lagi dengan countQueue(). Terakhir, program ini menghapus seluruh queue dengan clearQueue() dan ditampilkan dengan viewQueue(), ditampilkan juga jumlah queue dengan countQueue(). 

# Kesimpulan
<p align="justify">Program ini merupakan implementasi sederhana dari struktur data queue dimana Ada dua pendekatan yang digunakan untuk mengimplementasikan queue menggunakan array dan menggunakan linked list.implementasi menggunakan array, di mana ukuran maksimum queue telah ditentukan sebelumnya. Operasi dasar seperti enqueue (penambahan elemen), dequeue (penghapusan elemen), menghitung jumlah elemen dalam queue, mengosongkan queue, dan menampilkan isi queue telah diimplementasikan.ni menyediakan fungsionalitas yang sama, yaitu untuk mengelola data dalam antrian. Namun, menggunakan linked list memungkinkan fleksibilitas dalam hal ukuran queue karena tidak memerlukan alokasi memori sebesar ukuran maksimum queue seperti pada implementasi dengan array. Meskipun demikian, implementasi dengan array mungkin lebih efisien dalam hal akses elemen-elemen queue karena dapat diakses secara langsung melalui indeks Operasi-operasi yang digunakan pada Queue juga sebagai berikut:
  
- Create(): Digunakan untuk membuat dan menginisialisasi antrian.
- IsEmpty(): Digunakan untuk memeriksa apakah antrian masih kosong.
- IsFull(): Digunakan untuk mengecek apakah antrian sudah penuh atau belum.
- Enqueue(): Digunakan untuk menambahkan elemen ke dalam antrian. Penambahan elemen selalu dilakukan di elemen paling belakang.
- Dequeue(): Digunakan untuk menghapus elemen terdepan/pertama (head) dari antrian.
- Clear(): Digunakan untuk menghapus elemen-elemen antrian dengan cara membuat Tail dan Head = -1.
- Tampil(): Digunakan untuk menampilkan nilai-nilai elemen antrian.

# Referensi
[1] 


