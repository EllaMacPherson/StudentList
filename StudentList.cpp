#include <iostream>
#include <cstring>
#include <vector> //kind of like arrays but can change in size

using namespace std;

struct Student{
  char first[10];
  char last[10];
  int id;
  float gpa;
};

//define functions
void Print(vector<Student*>& vS);
void Add(vector<Student*>& vS);
void Delete(vector<Student*>& vS);


int main(){
  //var to track what they want to do
  bool go = true;

  //create vector of students
  vector<Student*> vS;
  
  while(go == true){
    char input[10];
    cout<<"Would you like to: ADD, DELETE, PRINT, or QUIT" << endl; 
    cin.get(input, 9);
    cin.ignore();
    
    if(strcmp(input, "ADD") == 0){
      Add(vS);
    }
    else if(strcmp(input, "DELETE") == 0){
      Delete(vS);
    }
    else if(strcmp(input, "PRINT") == 0){
      Print(vS);
    }
    else if(strcmp(input, "QUIT") == 0){
      return 0;
    }
    else{
      cout<<"Please enter a valid command";
      break;
    }
  }
}

void Print(vector<Student*>& vS){
  cout<<"Print"<<endl;
  for(int i =0; i < vS.size(); i++){
    cout<<i+1<<". ";
    cout<<vS[i]->first<<" "; //thake pointer and point to memory and access first in that
    cout<<vS[i]->last<<", ";
    cout<<vS[i]->id<<", ";
    cout<<vS[i]->gpa<<endl;
  }
}

 
void Add(vector<Student*>& vS){ //BREAKS when: char is entered into ID or GPA, sometimes weird char at end look at
  Student*s = new Student;
  char FIRST[10];
  char LAST[80];
  
  cout<<"Enter the first name: "<<endl;
  cin.get(FIRST, 9);
  cin.ignore();
  strcpy(s->first,FIRST);
 
  cout<<"Enter the last name: "<<endl;
  cin.get(LAST, 79);
  cin.ignore();
  strcpy(s->last, LAST);
 
  cout<<"Enter the student ID: "<<endl;
  cin>>s->id;
  cin.ignore();
 
  cout<<"Enter the GPA: "<<endl;
  cin>>s->gpa;
  cin.ignore();
  
  vS.push_back(s);
}

 
void Delete(vector<Student*>& vS){
  cout<<"Enter the ID number of the student you'd like to delete: "<<endl;
  int idDelete;
  bool exists = false;

  cin>>idDelete;
  cin.ignore();
  
  for(auto it = vS.begin(); it != vS.end(); it++){
    //if the id matches the delete
    if((*it)->id == idDelete){
      exists = true;
      delete (*it);
      vS.erase(it);
      return;
    }
    if(exists == false){
      cout<<"ID not found, try again."<<endl;
    }
  }
  
}

 
