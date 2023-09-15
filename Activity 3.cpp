#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class student{
private:
int id;
string name;
int grade1, grade2;
public:
void setData(int i, string n, int g1, int g2){
  id = i;
  name = n;
  grade1 = g1;
  grade2 = g2;
  }

void print(){
  cout<<id<<"\t" << name <<"\t\t" << grade1 << "\t\t\t" << grade2<< endl;
  }

void display(){
  cout<<"ID| Name | First Mark | Second Mark " << endl << "--------------------------------------" << endl;
  }

student search(student s[], int size){
  char op;
  int studid;
  string studname;
  while(true){
  cout << "Search the Student by ID or Name? I for ID, N for Name: "; cin >> op;
    if(op=='I'){
    cout << "What is the Student´s ID? "; cin >> studid;
      for(int i=0;i<=size;i++){
        if(s[i].id == studid){
          return s[i]; }
        else if(i==size){
          cout<<"***Student ID not Found***" <<endl; }
        }
      }
   else if(op=='N'){
    cout << "What is the Student´s Name? "; cin >> studname;
    for(int i=0;i<=size;i++){
      if(s[i].name == studname){
        return s[i]; }
      else if(i==size){
        cout<<"***Student Name not Found***" <<endl; }
      }
    }
  else {
    cout << "***Invalid Input***" << endl; }
    }
  }
};

int main() {
  student stud[9];
  string row[4];
  string word;
  int j=0;
  string line;
  ifstream f;
  f.open("file.csv");
  while(getline(f,line)){
    stringstream ss(line);
    int i = 0;
    while(getline(ss,word,',')){
      row[i]=word;
      i++;
    }
    stud[j].setData(stoi(row[0]), row[1], stoi(row[2]), stoi(row[3]));
    j++;
    }
  stud[0].display();
  for(int i=0;i<9;i++){
    stud[i].print();
  }
  student x;
  x = x.search(stud, 9);
  x.display();
  x.print();
  return 0;
  }