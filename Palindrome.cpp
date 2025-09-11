#include <iostream>
#include <cstring>

using namespace std;

int main(){

  //create strings
  char input[80];
  char NonPunc[80];
  char Flipped[80];
  
  cout << "Enter a palindrome: " << endl;

  cin.get(input, 80);
  cin.get();

  //Remove punctuation
  int count = 0;
  for (int i = 0; i < 80; i++){
    int ascii = (int)input[i];
    if((ascii >= 97 && ascii <= 122) || ascii == 0){
      NonPunc[count]=input[i];
      count++;
    }

    if(ascii >= 65 && ascii <= 90){
      NonPunc[count] = (char)(ascii + 32);
      count++;
    }
  }

  //flip it
  int length = strlen(NonPunc) + 1;
  int count2 = 0;
  for(int i = length; i >= 0; i--){
    if (NonPunc[i] != '\0'){
      Flipped[count2] = NonPunc[i];
      count2++;
    }else{
      continue;
    }
  }
  
  //add null char at end
  if (count2 == length){
    cout<<"true"<<endl;
    Flipped[count2] = '\0';
  }

  //check it against removed punctution + output
  if(strcmp(NonPunc, Flipped) == 0){
    cout << "your string is a palindrome!";
  }else{
    cout << "your string is not a palindrome.";
  }
  
  return 0;
}
