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
    
}