//Exam Object Oriented Programming
//Gabriel Edid Harari A01782146
//26-04-2023
#include <iostream>
using namespace std;

class employee{
  protected:
  string name;
  string curp;
  int hoursPerWeek;
  int salaryPerHour;
  public:
  employee(string n, string c, int h, int s){
    name = n;
    curp = c;
    hoursPerWeek = h;
    salaryPerHour = s;
  }
};

class programmer : public employee{
  protected:
  int bonusPerExtraHour;
  public:
  programmer(string n, string c, int h, int s, int b):employee(n,c,h,s){
    bonusPerExtraHour = b;
  }
  int getSalary(){
    return hoursPerWeek*salaryPerHour;
  }
  int getBonus(){
    int extraHours;
    if(hoursPerWeek > 40){
      extraHours = hoursPerWeek - 40;
      return extraHours * bonusPerExtraHour;
    }
    else{
      return 0;
    }
    }
    string showInfo(){
    return "Name: " + name + "   CURP: " + curp + "   HoursPerWeek: " + to_string(hoursPerWeek) + "   SalaryPerHour: " + to_string(salaryPerHour) + "   TotalSalary: " + to_string(getSalary()) + "   Bonus Total: " + to_string(getBonus());
    }
};

int main() {
  string name, curp;
  int hours, salary, bonus;
  cout << "Please Introduce Employee´s Name: "; cin >> name;
  cout << "Please Introduce Employee´s CURP: "; cin >> curp;
  cout << "Please Introduce Employee´s Hours per Week: "; cin >> hours;
  cout << "Please Introduce Employee´s Salary per Hour: "; cin >> salary;
  cout << "Please Introduce Employee´s Bonus per Hour: "; cin >> bonus;
  programmer p1(name, curp, hours, salary, bonus);
  cout<< p1.showInfo() << endl;
}