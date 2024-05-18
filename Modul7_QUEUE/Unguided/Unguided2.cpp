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