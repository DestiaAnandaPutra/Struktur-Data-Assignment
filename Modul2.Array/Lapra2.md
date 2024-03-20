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
# Output 
![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/e040f2e3-acec-4bec-a8ff-45a981197744) </br>

Kode di atas digunakan untuk menentukan bilangan ganjil dan genap dari inputan user. Pada kode di atas, terdapat tiga variabel, yaitu:
- const int SizeLimit_2176 untuk menentukan maksimal angka yang dapat diinput user, dilengkapi dengan const supaya tidak bisa diubah
- int Data_2176[SizeLimit_2176] untuk wadah array menyimpan angka yang diinput user
- int DataAmount_2176 untuk wadah jumlah angka yang sudah dimasukkan user, defaultnya 0 karena sudah pasti di awal tidak ada angka yang diinput<br/>
<p>Jadi user bisa menginput hingga 10 angka sebelum programnya menampilkan hasil output data array beserta bilangan genap dan ganjilnya. Jika user ingin menginput jumlah angka dibawah 10, user dapat mengakhiri dengan karakter selain angka, seperti tanda titik (.). Jika user sudah menginput, program dapat menampilkan output data array dengan perulangan for, output bilangan genap dengan perulangan for dan percabangan if jika bilangan tersebut habis dibagi 2, dan bilangan ganjil dengan perulangan for dan percabangan if jika bilangan tersebut tidak habis dibagi 2.</p>

# 2. Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!

```C++
/*
  Destia Ananda Putra-2311102176
*/  

#include <iostream>
using namespace std;

int main() {
    int x_size, y_size, z_size;

    // Meminta pengguna untuk memasukkan ukuran elemen array tiga dimensi
    cout << "Masukkan ukuran array tiga dimensi:" << endl;
    cout << "Ukuran dimensi x: ";
    cin >> x_size;
    cout << "Ukuran dimensi y: ";
    cin >> y_size;
    cout << "Ukuran dimensi z: ";
    cin >> z_size;

    // Deklarasi array tiga dimensi sesuai dengan ukuran yang dimasukkan pengguna
    int arr[x_size][y_size][z_size];

    // Input elemen array
    for (int x = 0; x < x_size; x++) {
        for (int y = 0; y < y_size; y++) {
            for (int z = 0; z < z_size; z++) {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }

    // Output elemen array
    cout << "Data Array:" << endl;
    for (int x = 0; x < x_size; x++) {
        for (int y = 0; y < y_size; y++) {
            for (int z = 0; z < z_size; z++) {
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }

    // Tampilan array
    cout << "Tampilan array:" << endl;
    for (int x = 0; x < x_size; x++) {
        for (int y = 0; y < y_size; y++) {
            for (int z = 0; z < z_size; z++) {
                cout << arr[x][y][z] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
```
# Output

![image](https://github.com/DestiaAnandaPutra/Struktur-Data-Assignment/assets/162514636/c52847a8-b480-4181-8cd4-f87afc0a76a7) </br>

elemen array tiga dimensi (x, y, z), program akan meminta pengguna untuk memasukkan nilai untuk setiap elemen array. Setelah semua nilai dimasukkan, program akan menampilkan kembali nilai dari setiap elemen array yang dimasukkan oleh pengguna, sesuai dengan indeksnya. Misalnya, jika pengguna memasukkan nilai 3 untuk x, 2 untuk y, dan 3 untuk z, maka program akan meminta pengguna untuk memasukkan nilai untuk setiap elemen arr[0][0][0], arr[0][0][1], arr[0][1][0], dan seterusnya, hingga arr[1][2][1]. Kemudian, program akan menampilkan kembali nilai dari setiap elemen array sesuai dengan indeksnya.

# 3. Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!

```C++
/*
    Destia Ananda Putra-2311102176
*/  
#include <iostream>
using namespace std;

int input;
int bil[10];
int minim, maksim;
double rata;

int main(){

    while(true){
    cout << "\t" "\t" << "MENU" << endl;
    cout << "\t" << "1. INPUT ARRAY" << endl;
    cout << "\t" << "2. TAMPIL ARRAY" << endl;
    cout << "\t" << "3. CARI NILAI MINIMMUM" << endl;
    cout << "\t" << "4. CARI NILAI MAKSIMUM" << endl;
    cout << "\t" << "5. HITUNG RATA - RATA" << endl;

    cout << "MASUKAN PILIHAN : ";
    cin >> input;

    cout << endl;



    switch (input)
    {
    case 1 : 
        {
            for(int i = 0; i < 10; i++){
                cout << "MASUKAN BILANGAN KE - " << i + 1 << " : ";
                cin >> bil[i];
            }
            cout << endl;
        break;
        }
    case 2 : 
        {
            cout << "ARRAY YANG DI INPUT : ";
            for (int i = 0; i < 10; i++){
                cout << bil[i] << " ";
            }
        cout << endl;
        }
    cout << endl;
    break;
    case 3 :
        {
            minim = bil[0];
            for(int i = 0; i < 10; i++){
                if(bil[i] < minim){
                    minim = bil[i];
                }
            }
            cout << "NILAI MINIMUM DARI ARRAY TERSEBUT : " << minim << endl;
            cout << endl;
        }
    break;
    case 4 :
        {
            maksim = bil[0];
            for (int i = 0; i < 10; i++){
                if(bil[i] > maksim){
                    maksim = bil[i];
                }
            }
            cout << "NILAI MAKSIMUM DARI ARRAY TERSEBUT : " << maksim << endl;
            cout << endl;
        }
    break;
    case 5 :
        {
            for(int i = 0; i < 10; i++){
                rata += bil[i] / 12;
            }
            cout << "RATA - RATA DARI ARRAY TERSEBUT : " << rata;
        }
        cout << endl;
        cout << endl;
        break;
    }
}
    return 0;
}
```
# Output






  










