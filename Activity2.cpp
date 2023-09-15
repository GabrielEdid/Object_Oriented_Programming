//Gabriel Edid Harari A01782146
//13/04/2023
//Programación Orientada a Objetos
#include <iostream>
using namespace std;

class hotel{
  protected:
  int roomNumber;
  string keyPassword;
  float pricePerNight;
  int days;
  hotel(int r, string k, float p, int d){
    roomNumber = r;
    keyPassword = k;
    pricePerNight = p;
    days = d;
  }
};

class client: private hotel{
  private:
  string name;
  int ID;
  public:
  client(int i, string n, int r, string k, float p, int d): hotel(r, k, p, d) {
    ID = i;
    name = n;
  }
  int totalPrice(){
    return days*pricePerNight;
  }
  void print(){
    cout << "Client: " << name<< "\nID: " << ID << "\nRoom Number: " << roomNumber << "\nKey Password: " << keyPassword << "\nPrice per Night: " << pricePerNight << "\nNumber of Days: " << days << "\nTotal Price: $" << totalPrice() << endl;
  }
};

int main() {
  cout << "******* HOTEL CLIENT REGISTRATION SYSTEM *******" << endl;
  string name;
  cout << "Introduce the Client´s Name: "; cin >> name;
  int ID;
  cout << "Introduce the Client´s ID: "; cin >> ID;
  int roomNumber;
  cout << "Introduce the Client´s Room Number: "; cin >> roomNumber;
  string keyPassword;
  cout << "Introduce the Client´s Key Password: "; cin >> keyPassword;
  float pricePerNight;
  cout << "Introduce the Price per Night: "; cin >> pricePerNight;
  int days;
  cout << "Introduce the Amount of Days the Client is Staying: "; cin >> days;
  
  client client1(ID, name, roomNumber, keyPassword, pricePerNight, days);
  cout << "*******************************************" << endl;
  cout << "Total Price of the Client´s Stay: $" << client1.totalPrice() << endl;
  cout << "*******************************************" << endl;
  client1.print();
  return 0;
}