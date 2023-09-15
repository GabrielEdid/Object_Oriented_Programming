#include <iostream>
using namespace std;

class student{
  private:
  int id;
  string name;
  float mark1;
  float mark2;

  public:
  student(int i, string n, float m1, float m2){
    name = n;
    id = i;
    mark1 = m1;
    mark2 = m2;
  }
  void print(){
    cout<<"\n***Student Info***" << endl;
    cout<<"Name: " << name << endl;
    cout<<"Id: " << id << endl;
    cout<<"Mark 1: " << mark1 << endl;                  
    cout<<"Mark 2: " << mark2 << endl;
    cout<<"Average: "<<(mark1+mark2)/2<< endl;
  }
  float getAverage(){
    return (mark1+mark2)/2;  
  }
};

int main(){
  student stud1(24680, "Gabriel", 9.8, 8.5);
  student stud2(13579, "Miguel", 9.5, 7.2);
  cout<< "***Students List***\n";
  stud1.print(); cout<< "\n"; stud2.print(); cout<< "\n";
  
  cout<< "***Higher Average***\n";
  if (stud1.getAverage()>stud2.getAverage()){
    cout<<"Student 1 has Greater Average! See Below:" << endl;
    stud1.print();
  }
  else if (stud1.getAverage()==stud2.getAverage()){
    cout<<"Both Students Have the Same Average! See Below:" << endl;
    stud1.print(); cout<< "\n"; stud2.print();
  }
  else{
    cout<<"Student 2 has Greater Average! See Below:" << endl;
    stud2.print();
  }
  return 0;
}
