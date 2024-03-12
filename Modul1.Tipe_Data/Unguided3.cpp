/*
oleh Destia Ananda Putra - 2311102176
*/

// Contoh Program Fungsi Map
#include <iostream>
#include <map> // Library supaya bisa menggunakan fungsi map dibawah

using namespace std;

int main() {
    
    // Deklarasi map dengan key int dan value string
    map<int, string> food_2176;
  
    // Menambahkan elemen-elemen ke dalam map
    food_2176[1] = "Hamburger";
    food_2176[2] = "Fried Chicken";
    food_2176[3] = "Stew";
    food_2176[4] = "Roasted Duck";
    food_2176[5] = "Ramen";

    cout << "-=-= Welcome to Destia Food Menu! =-=-" << endl;
    for (int i = 1; i <= food_2176.size(); ++i) { // Looping untuk menampilkan semua elemen map
        cout << "No." << i << " " << food_2176[i] << endl; // Menampilkan elemen map
    }

    return 0;
}