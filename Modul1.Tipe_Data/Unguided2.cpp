/*
oleh Destia Ananda Putra - 2311102176
*/

// Contoh Program Struct dan Class
#include <iostream>

using namespace std;

// Struct Person_2176 yang berisi data nama string dan umur int
struct Person_2176 {
    string Name_2176;
    int Age_2176;
};

// Class Vehicle_2176 yang berisi data brand string, model string, dan tahun rilis int dalam akses public
class Vehicle_2176 {
  public:
    string Brand_2176;   
    string Model_2176;
    int YearReleased_2176;
};

int main() {
    cout << "-=-= Declaration of Struct and Class by Destia =-=-" << endl;

    // Deklarasi Struct Person_2176
    Person_2176 person{"Destia Ananda Putra", 20};
    cout << "\n- Biography - " << endl;
    cout << "Name: " << person.Name_2176 << endl;
    cout << "Age: " << person.Age_2176 << endl;

    // Deklarasi Class Vehicle_2176
    Vehicle_2176 vehicle;
    vehicle.Brand_2176 = "Honda";
    vehicle.Model_2176 = "CB750";
    vehicle.YearReleased_2176 = 1969;
    cout << "\n- Destia Vehicle -" << endl;
    cout << "Vehicle brand: " << vehicle.Brand_2176 << endl;
    cout << "Vehicle model: " << vehicle.Model_2176 << endl;
    cout << "Vehicle year released: " << vehicle.YearReleased_2176 << endl;

    return 0;
}