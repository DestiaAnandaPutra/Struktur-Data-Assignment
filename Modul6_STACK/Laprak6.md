# <h1 align="center">Laporan Praktikum Modul 6 - Stack</h1>
<p align="center">Destia Ananda Putra - 2311102176</p>

# Tujuan Pratikum
a. Mampu memahami konsep stack pada struktur data dan algoritma
b. Mampu mengimplementasikan operasi-operasi pada stack
c. Mampu memecahkan permasalahan dengan solusi stack

# Dasar Teori 
<p align="justify">Stack adalah struktur data sederhana yang digunakan untuk menyimpan data (mirip dengan Linked Lists). Dalam tumpukan, urutan kedatangan data penting. Sebuah tumpukan piring di kafetaria adalah contoh bagus dari tumpukan. Piring ditambahkan ke tumpukan saat mereka dibersihkan dan ditempatkan di bagian atas. Ketika sebuah piring dibutuhkan, diambil dari bagian atas tumpukan. Piring pertama yang ditempatkan di tumpukan adalah yang terakhir digunakan. </p></br>

Definisi: Sebuah tumpukan adalah daftar terurut di mana penyisipan dan penghapusan dilakukan di satu ujung, disebut atas. Elemen terakhir yang dimasukkan adalah yang pertama dihapus. Oleh karena itu, disebut daftar Last in First out (LIFO).</br>

![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/c19a6ebd-ffb5-4440-b3dd-a68368133bce)</br>

### Operasi pada stack melibatkan beberapa fungsi dasar yang dapat dilakukan pada
struktur data ini. Berikut adalah beberapa operasi umum pada stack:
- Push (Masukkan): Menambahkan elemen ke dalam tumpukan pada posisi paling
atas atau ujung.
- Pop (Keluarkan): Menghapus elemen dari posisi paling atas atau ujung tumpukan.
- Top (Atas): Mendapatkan nilai atau melihat elemen teratas pada tumpukan tanpa
menghapusnya.
- IsEmpty (Kosong): Memeriksa apakah tumpukan kosong atau tidak.
- IsFull (Penuh): Memeriksa apakah tumpukan penuh atau tidak (terutama pada
implementasi tumpukan dengan kapasitas terbatas).
- Size (Ukuran): Mengembalikan jumlah elemen yang ada dalam tumpukan.
- Peek (Lihat): Melihat nilai atau elemen pada posisi tertentu dalam tumpukan
tanpa menghapusnya.
- Clear (Hapus Semua): Mengosongkan atau menghapus semua elemen dari
tumpukan.
- Search (Cari): Mencari keberadaan elemen tertentu dalam tumpukan.

## Guided

```c++
#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull()
{
    return (top == maksimal);
}

bool isEmpty()
{
    return (top == 0);
}

void pushArrayBuku(string data)
{
    if (isFull())
    {
        cout << "Data telah penuh" << endl;
    }
    else
    {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku()
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang dihapus" << endl;
    }
    else
    {
        arrayBuku[top - 1] = "";
        top--;
    }
}

void peekArrayBuku(int posisi)
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    }
    else
    {
        int index = top;
        for (int i = 1; i <= posisi; i++)
        {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

int countStack()
{
    return top;
}

void changeArrayBuku(int posisi, string data)
{
    if (posisi > top)
    {
        cout << "Posisi melebihi data yang ada" << endl;
    }
    else
    {
        int index = top;
        for (int i = 1; i <= posisi; i++)
        {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArraybuku()
{
    for (int i = top; i >= 0; i--)
    {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku()
{
    if (isEmpty())
    {
        cout << "Tidak ada data yang dicetak" << endl;
    }
    else
    {
        for (int i = top - 1; i >= 0; i--)
        {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main()
{
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";

    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;

    peekArrayBuku(2);
    popArrayBuku();

    cout << "Banyaknya data = " << countStack() << endl;

    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();
    cout << "\n";

    destroyArraybuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;
    cetakArrayBuku();

    return 0;
}
```
# Output

![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/8dfdca0a-a096-4766-bde1-23d66a6bed3e)</br>

# Penjelasan 
Stack adalah sebuah kumpulan data dimana data yang diletakkan di atas data  yang lain. Dengan demikian stack adalah struktur data yang menggunakan konsep LIFO (Last In First Out). Dengan demikian, elemen terakhir yang disimpan dalam stack menjadi elemen pertama yang diambil. Dalam proses komputasi, untuk meletakkan sebuah elemen pada bagian atas dari stack, maka dilakukan operasi push. Dan untuk memindahkan dari tempat yang atas tersebut, maka dilakukan operasi pop.</p>

# Unguided
## 1) Unguided 1
   
```c++
#include <iostream>
#include <stack>

//Nama : Destia Ananda Putra
//NIM  : 2311102176


using namespace std;

bool Palindrome_176(string kalimat176)
{
  for (int i = 0; i < kalimat176.length(); i++)
  { // Konversi kalimat ke huruf kecil
    kalimat176[i] = tolower(kalimat176[i]);
  }

  stack<char> s; // Buat stack untuk menyimpan karakter kalimat

  for (int i = 0; i < kalimat176.length(); i++)
  { // Masukkan karakter kalimat ke stack
    s.push(kalimat176[i]);
  }

  for (int i = 0; i < kalimat176.length() / 2; i++)
  { // Bandingkan karakter dari depan dan belakang kalimat
    if (kalimat176[i] != s.top())
    {
      return false;
    }
    s.pop();
  }

  return true;
}

int main()
{
  string kalimat176;
  cout << "-=-=- DESTIA -=-=-" << endl;

  do
  {
    cout << "\n Masukkan kalimat: "; // Input kalimat dari pengguna
    getline(cin, kalimat176);

    if (Palindrome_176(kalimat176))
    { // Periksa apakah kalimat palindrom atau bukan
      cout << " Kalimat " << kalimat176 << " adalah : Palindrom!" << endl;
    }
    else
    {
      cout << " Kalimat " << kalimat176 << " bukan : Palindrom!" << endl;
    }

  } while (kalimat176 != "exit");
  return 0;
}
```
# Output

![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/1ea2069b-2234-4aa3-bbe4-e799e256e36e)</br>

# Penjelasan
Program ini merupakan implementasi dari struktur data stack menggunakan array dalam bahasa pemrograman C++. Stack adalah struktur data yang mengikuti prinsip Last In First Out (LIFO), yang berarti elemen terakhir yang dimasukkan akan menjadi elemen pertama yang dikeluarkan berfungsi untuk memeriksa apakah sebuah kalimat yang dimasukkan pengguna adalah palindrom atau bukan. Itu dilakukan dengan memasukkan setiap karakter dari kalimat ke dalam stack, lalu membandingkan karakter tersebut dengan karakter-karakter di depan kalimat. Jika kalimat tersebut dapat dibaca dari depan dan belakang dengan hasil yang sama, maka kalimat itu adalah palindrom. 

## 2) Unguided 2

```c++
#include <iostream>
#include <stack>

//Nama : Destia Ananda Putra
//NIM  : 2311102176


using namespace std;

string pengulang176(string kalimat176) {
  stack<char> s; // Buat stack untuk menyimpan karakter kalimat

  for (int i = 0; i < kalimat176.length(); i++) { // Masukkan karakter kalimat ke stack
    s.push(kalimat176[i]);
  }

  string setelahmengulangi176; // Membalik kalimat dengan mengeluarkan karakter dari stack
  while (!s.empty()) {
    setelahmengulangi176 += s.top();
    s.pop();
  }

  return setelahmengulangi176;
}

int main() {
  string kalimat176;
  cout << "-=-=- Membalik Kata -=-=-" << endl;

  do {
  cout << "\n Masukkan kalimat yang ingin dibalikkan: ";  // Input kalimat dari pengguna
  getline(cin, kalimat176);

  string setelahmengulangi176 = pengulang176(kalimat176);  // Membalik kalimat

  cout << " Kalimat yang dibalik: " << setelahmengulangi176 << endl; // Menampilkan kalimat yang dibalik

  } while (kalimat176 != "exit");
  return 0;
}
```
# Output
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/b6b872e1-21ad-40ea-a25d-0d880ca83bbf)</br>

# Penjelasan 
Kode di atas digunakan untuk menjalankan sebuah program stack dimana program ini dapat melakukan pembalikan terhadap kalimat yang diinput oleh user. Dengan adanya fungsi BeforeReverse_2176(string sentence_2176), program dapat membalikkan sebuah kalimat yang diterima sebagai parameter. Fungsi ini menggunakan stack untuk menyimpan karakter-karakter dari kalimat secara terbalik. Stack s dibuat untuk menyimpan karakter-karakter dari kalimat lalu setiap karakter dari kalimat dimasukkan ke dalam stack. Kemudian, karakter-karakter tersebut diambil dari stack satu per satu, dan digabungkan menjadi string  Hal ini menyebabkan urutan karakter pada kalimat dibalik.
Pada int main(), user dapat menginput sebuah kalimat yang ingin dibalikkan. Inputan itu akan melalui proses BeforeReverse_2176 menjadi AfterReverse_2176. Jika sudah dilalui, program akan menampilkan output kalimat yang telah dibalikkan. Program ini akan mengulang sampai user mengetik kata 'exit'dan Program tersebut merupakan program yang meminta pengguna memasukkan sebuah kalimat dan kemudian membalikkan kalimat tersebut. Ini dilakukan dengan menggunakan struktur data stack untuk membalikkan urutan karakter dalam kalimat. Program akan terus berjalan dan membalikkan setiap kalimat yang dimasukkan oleh pengguna. 
# Kesimpulan
Program ini menerima input sebuah kalimat dari pengguna, kemudian membalikkan kalimat tersebut karakter per karakter menggunakan struktur data stack. Setiap karakter dari kalimat dimasukkan ke dalam stack, kemudian dikeluarkan dari stack satu per satu untuk membalikkan urutan karakternya. Hasilnya adalah kalimat yang sudah dibalik.
serta program menggunakan struktur data stack untuk membandingkan setiap karakter kalimat dari depan dengan karakter kalimat dari belakang secara berurutan. Jika semua karakter cocok, maka kalimat tersebut merupakan palindrom.
Program akan terus berjalan dan memeriksa apakah input yang diberikan oleh pengguna merupakan palindrom atau bukan hingga pengguna memasukkan kata "exit".

# Referensi
[1] Muhammad Nugraha, Dasar Pemrograman Dengan C++, Materi Paling Dasar untuk Menjadi Programmer Berbagai Platform. Yogyakarta: Deepublish, 2021.<br/>
[2] uinn, R., Advanced C++ Programming Cookbook. United Kingdoms: Packt Publishing Ltd., 2020.












