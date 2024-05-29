#include <iostream>
#include <vector> // library ini digunakan untuk fungsi vector
#include <iomanip> // library ini digunakan untuk fungsi setw()

//Nama : Destia Ananda Putra
//NIM  : 2311102176

using namespace std;

int main() {
    int Destia_2311102176; // variabel ini digunakan untuk menyimpan jumlah simpul
    cout << "-=-=-=- Destia' Program Grafis Jarak Kota -=-=-=-\n";

    do {
    cout << "\nsilahkan masukan jumlah simpul (0 to exit): "; cin >> Destia_2311102176;

    vector<string> cities(Destia_2311102176); // vector ini digunakan untuk menyimpan nama-nama simpul
    cout << "\nMasukan Nama Simpul" << endl;
    for (int i = 0; i < Destia_2311102176; ++i) {
        cout << "Simpul " << i + 1 << " : ";
        cin >> cities[i]; 
    }

    vector<vector<int>> Matrix_2176(Destia_2311102176, vector<int>(Destia_2311102176)); // vector ini digunakan untuk menyimpan jarak antar simpul, vector<int> ini digunakan untuk menyimpan jarak antar simpul
    cout << "\nSilahkan Masukan Bobot Antar Simpul\n";
    for (int i = 0; i < Destia_2311102176; ++i) {
        for (int j = 0; j < Destia_2311102176; ++j) { // perulangan ini digunakan untuk menginput jarak antar simpul
            cout << cities[i] << " --> " << cities[j] << " = ";
            cin >> Matrix_2176[i][j]; // Matrix_2176 ini digunakan untuk menyimpan jarak antar simpul, i adalah simpul asal dan j adalah simpul tujuan
        }
    }

    cout << "\n-=-=-=-=-=- Grafik Jarak Kota -=-=-=-=-=-";
    cout << "\n           ";
    for (const auto& city : cities) { // barisan ini digunakan untuk menampilkan nama-nama simpul, const auto& digunakan untuk mengambil nilai dari vector cities
        cout << setw(10) << city;
    }
    cout << '\n';

    for (int i = 0; i < Destia_2311102176; ++i) { // perulangan ini digunakan untuk menampilkan jarak antar simpul
        cout << setw(10) << cities[i];
        for (int j = 0; j < Destia_2311102176; ++j) {
            cout << setw(10) << Matrix_2176[i][j]; // perulangan ini digunakan untuk Matrix_2176[i][j]
        }
        cout << '\n';
    }
    } while (Destia_2311102176 != 0); // perulangan ini digunakan untuk mengulang program jika Destia_2311102176 tidak sama dengan 0
    cout << "Hope it helps!";
    return 0;
}