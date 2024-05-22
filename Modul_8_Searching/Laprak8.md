# <h1 align="center">Laporan Praktikum Modul 8 Searching </h1>
<p align="center">Destia Ananda Putra</p>
<p align="center">2311102176</p>
<p align="center">IF 11 E</p>

# Dasar Teori
## Searching
 Algoritma pencarian(Searching) dalam pemrograman adalah proses mencari elemen tertentu dalam kumpulan data yang diberikan. Tujuannya adalah untuk menemukan apakah elemen tersebut ada dalam data, dan jika ya, di mana posisinya. Algoritma pencarian biasanya dibagi menjadi dua jenis utama: pencarian linier (sequential search) dan pencarian biner (binary search). Pencarian linier melakukan pencarian elemen satu per satu secara berurutan dalam data, sementara pencarian biner membagi data menjadi dua bagian setiap langkahnya untuk mencari elemen target dalam logaritma waktu[1].

# Guided
## Guided 1
```C++
#include <iostream> 
using namespace std; 
int main() 
{ 
    int n = 10; 
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}; 
    int cari = 10; 
    bool ketemu = false; 
    int i; 
    // algoritma Sequential Search 
    for (i = 0; i < n; i++) 
    { 
        if (data[i] == cari) 
        { 
            ketemu = true; 
            break; 
        } 
    } 
    cout << "\t Program Sequential Search Sederhana\n " << endl; 
    cout<< "data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl; 
    if (ketemu){ 
        cout << "\n angka " << cari << " ditemukan pada indeks ke " << i << endl; 
    } 
    else 
    { 
        cout << cari << " tidak dapat ditemukan pada data." <<endl; 
    } 
    return 0; 
 
} 
```
## Output Guided 1
<p align="justify">Pada Program Sequential Search sederhana menampilkan data array {9, 4, 1, 7, 5, 12, 4, 13, 4, 10} dan berhasil menemukan angka 10 pada indeks ke-9. Pada pencarian memeriksa setiap elemen dalam array satu per satu hingga menemukan nilai yang dicari. Jika nilai 10 tidak ditemukan dalam array, program akan mencetak pesan bahwa nilai tersebut tidak dapat ditemukan pada data. Namun, dalam kasus ini, angka 10 ditemukan sehingga pesan yang ditampilkan adalah "angka 10 ditemukan pada indeks ke-9". Program ini menunjukkan cara kerja pencarian sekuensial secara sederhana dan efektif untuk menemukan elemen dalam array kecil.

## Guided 2
```C++
#include <iostream> 
#include <iomanip> 
using namespace std; 
 
// Deklarasi array dan variabel untuk pencarian 
int arrayData[7] = {1, 8, 2, 5, 4, 9, 7}; 
int cari; 
 
void selection_sort(int arr[], int n) { 
    int temp, min; 
    for (int i = 0; i < n - 1; i++) { 
        min = i; 
        for (int j = i + 1; j < n; j++) { 
            if (arr[j] < arr[min]) { 
                min = j; 
            } 
        } 
        // Tukar elemen 
        temp = arr[i]; 
        arr[i] = arr[min]; 
        arr[min] = temp; 
    } 
} 
 
void binary_search(int arr[], int n, int target) { 
    int awal = 0, akhir = n - 1, tengah, b_flag = 0; 
     
    while (b_flag == 0 && awal <= akhir) { 
        tengah = (awal + akhir) / 2; 
        if (arr[tengah] == target) { 
            b_flag = 1; 
 
            break; 
        } else if (arr[tengah] < target) { 
            awal = tengah + 1; 
        } else { 
            akhir = tengah - 1; 
        } 
    } 
     
    if (b_flag == 1) 
        cout << "\nData ditemukan pada index ke-" << tengah << 
endl; 
    else 
        cout << "\nData tidak ditemukan\n"; 
} 
 
int main() { 
    cout << "\tBINARY SEARCH" << endl; 
    cout << "\nData awal: "; 
    // Tampilkan data awal 
    for (int x = 0; x < 7; x++) { 
        cout << setw(3) << arrayData[x]; 
    } 
    cout << endl; 
     
    cout << "\nMasukkan data yang ingin Anda cari: "; 
    cin >> cari; 
     
    // Urutkan data dengan selection sort 
    selection_sort(arrayData, 7); 
     
    cout << "\nData diurutkan: "; 
    // Tampilkan data setelah diurutkan 
    for (int x = 0; x < 7; x++) { 
        cout << setw(3) << arrayData[x]; 
    } 
    cout << endl; 
     
    // Lakukan binary search 
    binary_search(arrayData, 7, cari); 
     
    return 0;
} 
```
## Output Guided 2
<p align="justify">program ini adalah hasil pencarian nilai yang dimasukkan pengguna dalam array yang telah diurutkan. Jika nilai tersebut ditemukan, program akan menampilkan pesan "Data ditemukan pada index ke index", di mana index adalah posisi di mana nilai tersebut ditemukan setelah array tersebut diurutkan terlebih dahulu dengan menggunakan algoritma selection sort. Program dimulai dengan mendeklarasikan sebuah array arrayData yang berisi 7 elemen integer dan sebuah variabel cari untuk menyimpan nilai yang akan dicari.

## Unguided

## Unguided 1
```C++
#include <iostream>
#include <string>

//Nama : Destia Ananda Putra
//NIM  : 2311102176


using namespace std;

bool binarySearch(string kalimat176, char carikalimat176) {
 
  int low176 = 0;
  int high176 = kalimat176.length() - 1;

  
  while (low176 <= high176) {
    
    int mid = (low176 + high176) / 2;

   
    if (kalimat176[mid] == carikalimat176) {
      
      return true;
    } else if (kalimat176[mid] < carikalimat176) {
      
      low176 = mid + 1;
    } else {
     
      high176 = mid - 1;
    }
  }


  return false;
}

int main() {
  
  string kalimat176;
  char carikalimat176;


  cout << "Masukkan kalimat176: ";
  getline(cin, kalimat176);

 
  cout << "Masukkan huruf yang ingin dicari: ";
  cin >> carikalimat176;

  
  bool ditemukan = binarySearch(kalimat176, carikalimat176);

 
  if (ditemukan) {
    cout << "Huruf '" << carikalimat176 << "' ditemukan dalam kalimat." << endl;
  } else {
    cout << "Huruf '" << carikalimat176 << "' tidak ditemukan dalam kalimat." << endl;
  }

  return 0;
}
```
## Output Unguided1
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/b1269171-11e9-42f0-a3f7-727610e56174)
<p align="justify">Kode program ini adalah hasil dari pencarian huruf yang dimasukkan pengguna dalam kalimat yang juga dimasukkan oleh pengguna. Setelah pengguna memasukkan kalimat dan huruf yang ingin dicari, program akan melakukan pencarian menggunakan algoritma binary search. Jika huruf tersebut ditemukan dalam kalimat, program akan menampilkan pesan "Huruf 'huruf' ditemukan dalam kalimat." yang memberikan informasi bahwa huruf tersebut ada dalam kalimat yang dimasukkan pengguna. Jika tidak ditemukan, program akan menampilkan pesan "Huruf 'huruf' tidak ditemukan dalam kalimat." yang memberitahu pengguna bahwa huruf tersebut tidak ada dalam kalimat yang dimasukkan.

## Unguided 2
```C++
#include <iostream>
#include <cctype>

//Nama : Destia Ananda Putra
//NIM  : 2311102176


using namespace std;

bool isVowel(char karakter176) { 
    karakter176 = tolower(karakter176); 
    return (karakter176 == 'a' || karakter176 == 'e' || karakter176 == 'i' || karakter176 == 'o' || karakter176 == 'u'); 
}

void countVowels(const string &kata176, int vocal176[5]) { 
   
    for (char karakter176 : kata176) {
        if (isVowel(karakter176)) {  
            switch (tolower(karakter176)) { 
                case 'a': 
                    vocal176[0]++; 
                    break;
                case 'e':
                    vocal176[1]++; 
                    break;
                case 'i':
                    vocal176[2]++; 
                    break;
                case 'o':
                    vocal176[3]++; 
                    break;
                case 'u':
                    vocal176[4]++; 
                    break;
            }
        }
    }
}

int main() {
    string kata176;
    cout << "\n Menghitung Banyak Huruf Vokal" << endl;

    do
    {
    cout << "\n------------------------------" << endl;
    cout << "\nMasukan Sebuah Kalimat :"; getline(cin, kata176);

    int vocal176[5] = {0}; 

    countVowels(kata176, vocal176); 

    cout << "\nKalimat yang kamu masukan terdiri dari huruf vokal ini:\n";
    cout << "a: " << vocal176[0] << endl;
    cout << "e: " << vocal176[1] << endl;
    cout << "i: " << vocal176[2] << endl;
    cout << "o: " << vocal176[3] << endl;
    cout << "u: " << vocal176[4] << endl;
    
    } while (kata176 != "!");
    return 0;
}
```
## Output Unguided 2
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/4e236519-08d0-4f4a-a519-5f368b3a13d1)</br>
<p align="justify">Pada program akan menghitung jumlah masing-masing huruf vokal dalam sebuah kalimat yang dimasukkan pengguna dimana Program akan menampilkan jumlah masing-masing huruf vokal (a, e, i, o, u) yang terdapat dalam kalimat yang dimasukkan oleh pengguna. Jumlah masing-masing huruf vokal ditampilkan dalam format yang terpisah untuk setiap huruf vokal.Program dimulai dengan meminta pengguna untuk memasukkan sebuah kalimat. Kemudian, fungsi countVowels memproses kalimat tersebut dengan memeriksa setiap karakter apakah termasuk vokal menggunakan fungsi isVowel. Jika karakter adalah vokal, program akan meningkatkan jumlah hitungan vokal yang sesuai dalam array vocal176.Pengguna diminta untuk memasukkan sebuah kalimat. Program akan terus meminta input kalimat dan menghitung huruf vokal dalam kalimat tersebut hingga pengguna memasukkan tanda seru (!) sebagai tanda akhir input.

## Unguided 3
```c++
#include <iostream>
using namespace std;

//Nama : Destia Ananda Putra
//NIM  : 2311102176


int main() {
    int n = 10;
    int data[n] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int cari = 4;
    int count = 0;  
    int indeks[n]; 
    int i;

    
    for (i = 0; i < n; i++) {
        if (data[i] == cari) {
            indeks[count] = i; 
            count++;
        }
    }

    cout << "\n-=-=-=-  HITUNGLAH Banyak Nomer 4 Dengan algoritma Sequential Search-=-=-=-" << endl;
    cout << "\nData : {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}" << endl;

    cout << "\nSo, the number " << cari << " has appeared in that data " << count << " times!" << endl;

    
    if (count > 0) {
        cout << "\nThe number " << cari << " is found in this(these) index(es): ";
        for (i = 0; i < count; i++) {
            cout << indeks[i];
            if (i != count - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    } else {
        cout << "\nHuh? The number " << cari << " isn't found anywhere!" << endl;
    }
    cout << "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    return 0;
}
```
## Output Unguided 3
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/137667bd-eecf-43b7-b991-4dda6613234b)</br>
<p align="justify"> program dengan sequential search. Pada program ini, terdapat variabel int data[n] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4} untuk mengisi array integer dengan int n = 10; untuk jumlah elemen yang ada pada array. Selanjutnya ada int cari = 4 untuk menentukan angka yang dicari, yaitu 4. int count = 0; adalah variabel untuk menghitung jumlah angka 4 dan int indeks[n]; adalah array untuk menyimpan indeks di mana angka 4 ditemukan. Bukti bahwa kode ini menggunakan sequential search adalah perulangan for dari indeks 0 hingga n-1 (karena array dimulai dari 0). Dalam setiap iterasi, kondisi if memeriksa apakah nilai elemen array pada indeks i sama dengan nilai cari. Jika sama, variabel ketemu diubah menjadi true dan loop dihentikan menggunakan break.Lalu pada int main(), dinampilkan pesan "Program Sequential Search" dan isi array data. Kemudian, menggunakan kondisi if untuk: Jika ketemu bernilai true, maka menampilkan pesan bahwa nilai cari ditemukan pada indeks ke-i. Jika ketemu bernilai false, maka menampilkan pesan bahwa nilai cari tidak ditemukan. Dalam program ini, dikhususkan untuk mencari jumlah angka 4 dan di indeks mana saja

## Kesimpulan 
<p align="justify">Algoritma pencarian adalah serangkaian Program ini mencakup tiga bagian yang berbeda, dengan fokus pada berbagai jenis pencarian: binary search pada string, menghitung jumlah huruf vokal dalam sebuah kalimat, dan sequential search pada array. Untuk menggabungkan ketiganya menjadi satu program, kita dapat menggabungkan logika dari setiap bagian ke dalam satu program utama dengan menu untuk memilih jenis pencarian yang ingin dilakukan. Program ini memberikan pilihan kepada pengguna untuk melakukan pencarian menggunakan algoritma binary search pada string, menghitung jumlah huruf vokal dalam sebuah kalimat, atau melakukan pencarian sekuen pada array. Pengguna diminta untuk memilih jenis pencarian yang diinginkan, kemudian memasukkan data yang relevan dan program akan memberikan output sesuai dengan jenis pencarian yang dipilih.Algoritma ini mudah diimplementasikan, tetapi tidak efisien untuk kumpulan data yang besar. Binary search atau pencarian biner adalah algoritma yang lebih efisien daripada sequential search. Algoritma ini bekerja dengan cara membagi kumpulan data menjadi dua bagian secara berulang, dan kemudian mencari elemen yang dicari di bagian yang sesuai. Algoritma ini hanya dapat digunakan untuk kumpulan data yang terurut.

## Refrensi
[1] Zheng Li dkk, C++ Programming. Republic State of China: De Gruyter, 2019.</br>
[2] Saputro, F. E., & Khasanah, F. N. Teknik Selection Sort dan Bubble Sort Menggunakan Borland  C++. 2018.</br>




