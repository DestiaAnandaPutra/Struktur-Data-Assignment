# <h1 align="center">Laporan Praktikum Modul 2 - ARRAY</h1>
<p align="center">Destia Ananda Putra - 2311102176</p>

# Dasar Teori 

Array merupakan struktur data yang paling dasar. Sebelum mempelajari struktur data
lainnya, alangkah baiknya, kita perlu mempelajari Array terlebih dahulu. Berikut ini
adalah beberapa jenis array :

1) Array Satu Dimensi</br>
Array satu dimensi adalah tipe variabel yang terdiri dari kumpulan data dengan tipe yang sama yang disusun dalam satu baris atau satu dimensi. Setiap elemen di dalam array memiliki sebuah indeks atau nomor yang digunakan untuk mengakses elemen tersebut. Indeks dimulai dari 0 dan berakhir pada jumlah elemen dikurangi satu.
Contohnya, sebuah array satu dimensi yang berisi bilangan bulat {1, 2, 3, 4, 5} memiliki lima elemen dan indeksnya dimulai dari 0. Indeks 0 merujuk pada elemen pertama, indeks 1 merujuk pada elemen kedua, dan seterusnya hingga indeks 4 merujuk pada elemen kelima Contoh : 

```C++
#include <iostream>
using namespace std;
int main() {
int arr[5] = {9, 3, 5, 2, 1}; //deklarasi array
cout<< arr[1] << endl;
cout<< arr[4];
}
```

2) Array Dua Dimensi</br>
Array dua dimensi adalah variable yang terdiri dari kumpulan array satu dimensi dengan tipe yang sama yang disusun dalam baris dan kolom. Dalam array dua dimensi, setiap elemen memiliki dua indeks, yaitu indeks baris dan indeks kolom. Indeks baris menunjukkan posisi elemen dalam baris, sementara indeks kolom menunjukkan posisi elemen dalam kolom.
Contoh :

```C++ 
#include <iostream>
using namespace std;
int main() {
int arr[2][2] = {{3, 2}, {2, 5}};
for (int i=0; i<2; i++) { //baris
for(int j=0; j<2; j++) { //kolom
cout<< arr[i][j] << ends;
};
cout << endl;
};
}
```  

3) Array Multidimensi</br>
Array multidimensi memiliki kesamaan dengan array satu dimensi dan dua dimensi, namun memiliki kapasitas memori yang lebih besar. Array ini digunakan untuk merepresentasikan array dengan dimensi lebih dari dua atau array yang memiliki lebih dari dua indeks, seperti array tiga dimensi, array empat dimensi, array lima dimensi, dan seterusnya.
Contoh : 

```C++
#include <iostream>
using namespace std;
int main() {
int arr[2][2][3] = {{{2, 8, 7}, {6, 5, 1}}, {{8, 5, 2}, {9, 2 ,7}}}; 
for (int i=0; i<2; i++) {
for(int j=0; j<2; j++) {
for(int k=0; k<3; k++) {
cout<< arr[i][j][k] << ends;
};
cout<< endl;
};
cout<< endl;
};
}
``` 

4) Array Empat Dimensi</br>
Array berdimensi empat merupakan kumpulan dari paket-paket kartu yang setiap paket mempunyai jumlah kartu yang sama, setiap kartu dengan jumlah baris yang sama, dan setiap baris mempunyai jumlah kolom yang sama.
contoh : 

```C++ 
int arr [3][2][4][4];
```

5) Array Lima Dimensi</br>
```C++ 
int arr [2][4][4][3][3];
```

# Guided

# 1. Program Input Array Tiga Dimensi

```C++
 #include <iostream>
using namespace std;
// PROGRAM INPUT ARRAY 3 DIMENSI
int main()
{
// Deklarasi array
int arr[2][3][3];
// Input elemen
for (int x = 0; x < 2; x++)
{
for (int y = 0; y < 3; y++)
{
for (int z = 0; z < 3; z++)
{
cout << "Input Array[" << x << "][" << y << "][" << z <<"] = ";
cin >> arr[x][y][z];
    }
}
cout << endl;
}
// Output Array
for (int x = 0; x < 2; x++)
{
for (int y = 0; y < 3; y++)
{
for (int z = 0; z < 3; z++)
{
cout << "Data Array[" << x << "][" << y << "][" << z <<"] = " << arr[x][y][z] << endl;
        }
    }
}
cout << endl;
// Tampilan array
for (int x = 0; x < 2; x++)
{
for (int y = 0; y < 3; y++)
{
for (int z = 0; z < 3; z++)
{
cout << arr[x][y][z] << ends;
}
cout << endl;
}
cout << endl;
}
}

```
# Output
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/563c247d-20a4-45ae-9b8c-19eb57978107)</br>
Penjelasan dari program di atas adalah bahwa setiap elemen dalam array tiga dimensi yang dimasukkan oleh pengguna akan diperiksa apakah itu angka genap atau ganjil, dan akan memberikan penjelasan sesuai dengan itu. Program ini akan meminta pengguna untuk memasukkan nilai-nilai untuk setiap elemen dalam array tiga dimensi dan kemudian menampilkan nilai-nilai tersebut.

# 2. Program Mencari Nilai Maksimal pada Array

```C++
#include <iostream>
using namespace std;
int main()
{
    int maks, a, i = 1, lokasi; 
    cout << "masukan panjang array: ";
    cin >> a; 
    int array[a];
    cout << "masukan" << a << "angka\n";
    for (i = 0; i < a; i++)
    {
        cout << "Array ke-" << (i) << ":";
        cin >> array[i];
    }
    maks = array[0];
    for (i = 0; i < a; i++)
    {
        if (array[i] > maks)
        {
            maks = array[i];
            lokasi = i;
        }
    }
    cout << "Nilai maksimum adalah" << maks << "berada di array ke" << lokasi << endl; 
}
```
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/e46a3d0e-f3de-4583-8ec5-8154e91faa9e) </br>

Program mendefinisikan sebuah array  yang berisi beberapa bilangan bulat. Kemudian, program menghitung panjang array tersebut dan mencari nilai maksimum dengan membandingkan setiap elemen array dengan nilai maksimum yang telah ditentukan sebelumnya. Setelah iterasi selesai, nilai maksimum dari array akan ditampilkan. Dalam kasus ini, nilai maksimum dari array  yang ditampilkan oleh program.

# 1. Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!
![WhatsApp Image 2024-03-20 at 16 00 23_3a113b41](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/bcecd3c2-5445-4210-8aa3-71dc543e6c48) </br>
```C++
/*
  Destia Ananda Putra-2311102176
*/
#include <iostream>

using namespace std;

int main() {
    const int SizeLimit_2176 = 10; // Maksimal 10 angka, dengan const agar tidak terubah
    int Data_2176[SizeLimit_2176]; // Array untuk menyimpan angka
    int DataAmount_2176 = 0; // Jumlah angka yang sudah dimasukkan, 0 karena belum ada angka yang dimasukkan

    cout << "\n-=-= Destia Odd and Even Number Program =-=-" << endl;
    cout << "- Program ini memperbolehkan inputan hingga 10 angka" << endl;
    cout << "- Jika ingin berhenti input atau ingin input angka kurang dari 10, silakan diakhiri dengan titik (.)" << endl;
    cout << "\nInput angka: " << endl;
    
    // DataAmount_2176 akan terus bertambah sampai DataAmount_2176 mencapai SizeLimit_2176 atau input tidak valid
    while (DataAmount_2176 < SizeLimit_2176 && cin >> Data_2176[DataAmount_2176]) { 
        DataAmount_2176++;
    }

    cout << "\n-=-=- HASIL -=-=-" << endl;

    // Menampilkan data array yang sudah diinput oleh user
    cout << "Data array: ";
    for (int i = 0; i < DataAmount_2176; ++i) // Melakukan perulangan untuk menampilkan data array
        cout << Data_2176[i] << " ";
    cout << endl;

    // Menampilkan angka genap, jika angkanya habis dibagi 2 maka akan ditampilkan
    cout << "Nomor genap  : ";
    for (int i = 0; i < DataAmount_2176; ++i) { // Melakukan perulangan untuk mengecek angka genap
        if (Data_2176[i] % 2 == 0)
            cout << Data_2176[i] << ", ";
    }
    cout << endl;

    // Menampilkan angka ganjil, jika angkanya tidak habis dibagi 2 maka akan ditampilkan
    cout << "Nomor ganjil : ";
    for (int i = 0; i < DataAmount_2176; ++i) { // Melakukan perulangan untuk mengecek angka ganjil
        if (Data_2176[i] % 2 != 0)
            cout << Data_2176[i] << ", ";
    }
    cout << endl;

    return 0;
}
```

  










