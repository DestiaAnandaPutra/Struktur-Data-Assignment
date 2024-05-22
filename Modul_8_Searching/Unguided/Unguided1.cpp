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