/*
  Ella MacPherson
  C++ StudentList
  10/17/25
  Create a list of students that can have additions, deletions and be printer oud
*/

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

//create Student struct to hold all attributes
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
  bool go = true;

  //create vector of pointers to student structs
  vector<Student*> vS;

  //loop that goes forever until main returns
  while(go == true){
    //cstring to hold input
    char input[10];
    cout<<"Would you like to: ADD, DELETE, PRINT, or QUIT" << endl; 
    cin.get(input, 9);
    cin.ignore(); //clear buffer
    
    if(strcmp(input, "ADD") == 0 || strcmp(input, "add") == 0){
      Add(vS);
    }
    else if(strcmp(input, "DELETE") == 0 || strcmp(input, "delete") == 0){
      Delete(vS);
    }
    else if(strcmp(input, "PRINT") == 0 || strcmp(input, "print") == 0){
      Print(vS);
    }
    else if(strcmp(input, "QUIT") == 0 || strcmp(input, "quit") == 0){
      return 0;
    }
    else{
      cout<<"Please enter a valid command" <<endl;
      input[0] = '\0'; //clear input
    }
  }
}

//Print function
void Print(vector<Student*>& vS){
  //loop through vector, access each element in the struct corresponding to the index
  for(int i =0; i < vS.size(); i++){
    cout<<i+1<<". ";
    cout<<vS[i]->first<<" ";
    cout<<vS[i]->last<<", ";
    cout<<vS[i]->id<<", ";
    cout<<vS[i]->gpa<<endl;
  }
}

//Add function
void Add(vector<Student*>& vS){
  //create new student pointer
  //create cstrings to hold inputs
  Student*s = new Student;
  char FIRST[20];
  char LAST[80];
  
  cout<<"Enter the first name: "<<endl;
  cin.get(FIRST, 20);
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

  //Add the student pointer with all the new defined elements into the vector
  vS.push_back(s);
}


//Delete function
void Delete(vector<Student*>& vS){
  cout<<"Enter the ID number of the student you'd like to delete: "<<endl;
  //var to hold id to be deleted and to hold if that number exists
  int idDelete;
  bool exists = false;

  cin>>idDelete;
  cin.ignore();

  //use iterator to go through vector
  for(auto it = vS.begin(); it != vS.end(); it++){
    //if the id matches then delete
    if((*it)->id == idDelete){
      exists = true;
      delete (*it);
      vS.erase(it);
      return;
    }
  }
  //if id doesnt exist inform user
  if(exists == false){
    cout<<"ID not found, try again."<<endl;
  }
}

 
