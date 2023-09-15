//Eduardo Dabbah Gindi y Gabriel Edid Harari
//Programación Orientada a Objetos
//03/Mayo/2023

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

class videos{
  public:
  string id, name, genre, comment;
  int length;
  float rating;
  public:
  void set_data(string i, string n, int l, string g, float r, string c){
    id = i;
    name = n;
    genre = g;
    length = l;
    rating = r;
    comment = c;
  }
  void display(){
    cout<<"\n\nID |              Name              | Length |  Genre  | Rating |   Comment   |" << endl << "-------------------------------------------------------------------------------" << endl;
  }
  void print(){
    cout << left << setw(5) << id << left << setw(35) << name << left << setw(7) << length << left << setw(12) << genre << left << setw(7) << rating << left << setw(1) << comment << left << endl;
  }

  void menu(){
    cout<<"\n\n*** Welcome to TecFlix! ***"<< endl;
    cout << "Please Select an Option: " << endl << "1.Display All Videos" << endl << "2.Display All Movies" << endl << "3.Display Movies by Genre" << endl << "4.Search Movie by Name" << endl << "5.Evaluate Movie Between 0-5" << endl << "6.Display All Series" << endl << "7.Display Series by Genre" << endl << "8.Search Series by Name" << endl << "9.Evaluate Series Between 0-5" << endl << "10.Exit" << endl;
  }

  void print_genre(videos v[], int size){
      cout << "\n\n*** Drama ***"<<endl;
      v[0].display();
      for (int i=0;i<size;i++){
        if (v[i].genre == "Drama"){
          v[i].print();
        }}
      cout << endl <<"\n*** Action ***"<<endl;
      v[0].display();
      for (int i=0;i<size;i++){
        if (v[i].genre == "Action"){
          v[i].print();
        }}
      cout << endl <<"\n*** Mystery ***"<<endl;
      v[0].display();
      for (int i=0;i<size;i++){
        if (v[i].genre == "Mystery"){
          v[i].print();
        }
      }
    }
  };

class movies: public videos{
    public:
    int search(movies s[], int size){ //Search a Movie
    string nam;
    while (true){
    cout << "\nPlease Write the Movie's Name: ";
    getline(cin,nam);
    for(int i=0;i<=size;i++){
      if (s[i].name == nam){
        return i;
      }
      else if(i==size){
        cout << "\nMovie Was Not Found"<<endl;
      }
    }
    cout << "\nPlease Try Again!"<< endl; 
      }
    }
   
  void file(movies s[], int size){ //Rewrite the Movies File
      ofstream f;
      f.open("movies.csv");
      for (int i=0;i<size;i++){
        f<<s[i].id<<","<<s[i].name<<","<<s[i].length<<","<<s[i].genre<<","<<s[i].rating<<","<<s[i].comment<<endl;
      }
      f.close();
    }
  };

class series: public videos{
  public:
    int search(series s[], int size){ //Search A Series
    string nam;
    while (true){
    cout << "\nPlease Write the Series's Name: ";
    getline(cin,nam);
    for(int i=0;i<=size;i++){
      if (s[i].name == nam){
        return i;
      }
      else if(i==size){
        cout << "\nSeries Was Not Found"<<endl;
      }
    }
    cout << "\nInvalid Option, Please Try Again!"<< endl; 
      }
    }

    void file(series s[], int size){ //Rewrite the Series File
      ofstream fs;
      fs.open("series.csv");
      for (int i=0;i<size;i++){
        fs<<s[i].id<<","<<s[i].name<<","<<s[i].genre<<","<<s[i].length<<","<<s[i].rating<<","<<s[i].comment<<endl;
      }
      fs.close();
    }
  };

int main(){
  float rat;
  videos m;
  int ind;
  //To make the Array for all the movies and read the file
  movies movie[30];
  string row[6];
  string word, srat, sop;
  int j=0;
  string line;
  ifstream f;
  f.open("movies.csv");
  while(getline(f,line)){
    stringstream ss(line);
    int i = 0;
    while(getline(ss,word,',')){
      row[i]=word;
      i++;
    }
    movie[j].set_data(row[0], row[1], stoi(row[2]), row[3], stoi(row[4]), row[5]);
  j++;
  }
  //To make the Array for all the series and read the file
  series serie[29];
  j=0;
  ifstream s;
  s.open("series.csv");
  while(getline(s,line)){
    stringstream ss(line);
    int i = 0;
    while(getline(ss,word,',')){
      row[i]=word;
      i++;
    }
    serie[j].set_data(row[0], row[1], stoi(row[3]), row[2], stof(row[4]), row[5]);
  j++;
  }
  int option;
  movies mov;
  serie[0].menu();
  while (true){
  cout << "Option: "; cin >> sop;
  if (sop=="1" or sop=="2" or sop=="3" or sop=="4" or sop=="5" or sop=="6" or sop=="7" or sop=="8" or sop=="9" or sop=="10"){
    option = stoi(sop);
    break;
  } else{cout << "\nPlease Try Again!"<<endl;}}
  switch (option){
    case 1: //Display All Videos
      cout << "\n\n*** Movies *** " << endl;
      movie[0].display();
      for (int i=0;i<30;i++){
        movie[i].print();
      }
      cout << "\n\n*** Series ***" << endl;
      serie[0].display();
      for (int i=0;i<29;i++){
        serie[i].print();
      }
      break;
    case 2: //Display All Movies
      movie[0].display();
      for (int i=0;i<30;i++){
        movie[i].print();}
      break;
    case 3: //Dispaly All Movies by Genre
      movie[0].print_genre(movie, 30);
      break;
    case 4: //Search Movie
      cin.ignore();
      ind = mov.search(movie, 30);
      mov.display();
      movie[ind].print();
      break;
    case 5: //Rate a Movie
      cin.ignore();
      ind = mov.search(movie, 30);
      while (true){
      cout << "\nWrite Your Rating For This Movie: (Rating Must be an Integer Between 1 and 5) "; cin >> srat;
      if (srat=="1" or srat=="2" or srat=="3" or srat=="4" or srat=="5"){
        rat = stoi(srat);
        movie[ind].rating = (movie[ind].rating + rat)/2;
        cout<<"\n***Rating Registered!***" << endl;
        cout << "\n***Changes Saved!***" << endl;
        movie[0].file(movie,30);
        break;
        } 
      else{
        cout << "\nPlease Try Again!"<<endl;
        }
      }
      break;
    case 6: //Dispaly All Series
      serie[0].display();
      for (int i=0;i<29;i++){
        serie[i].print();}
      break;
    case 7: //Dispaly All Series by Genre
      serie[0].print_genre(serie, 29);
      break;
    case 8: //Search Series
      cin.ignore();
      ind = serie[0].search(serie, 29);
      m.display();
      serie[ind].print();
      break;
    case 9: //Rate a Series
      cin.ignore();
      ind = serie[0].search(serie, 29);
      while (true){
      cout << "\nWrite Your Rating for This Series: (Rating Must be an Integer Between 1 and 5) "; cin >> srat;
      if (srat=="1" or srat=="2" or srat=="3" or srat=="4" or srat=="5"){
        rat = stoi(srat);
        serie[ind].rating = (serie[ind].rating + rat)/2;
        cout<<"\n***Rating Registered!***" << endl;
        cout << "\n***Changes Saved!***" << endl;
        serie[0].file(serie,29);
        break;
        } 
        else{
        cout << "\nPlease Try Again!"<<endl;
        }
      }
      break;
    case 10: //Exit
      cout << "\n***See You Later! Thank You for Using TecFlix!***" << endl;
      return 0;
    default: //Ask For The Option Again
      cout << "\nInvalid Option, Please Try Again!" << endl; 
    }
  main();
}