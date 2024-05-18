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