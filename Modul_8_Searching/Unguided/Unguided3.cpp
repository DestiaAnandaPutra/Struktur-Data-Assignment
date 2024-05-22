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

    cout << "\n-=-=-=-  HITUNGLAH Berapa Banyak Nomer 4 Dengan algoritma Sequential Search-=-=-=-" << endl;
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