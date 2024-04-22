#include "Password.h"
#include <string>
#include <cctype>
#include <algorithm> 
#include <iostream> 
#include <vector>

using std::string;

int Password::count_leading_characters(string phrase){
  int repetition = 0;
  if (phrase.length() > 0){
    repetition = 1;
  }
  int index = 0;
  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}

bool Password::has_mixed_case(string str)
{
  bool found = false;
  for(char c : str){
    if( !found && c >= 'A' && c <= 'Z' ){
      found = true;
    }
    else if( found && c >= 'a' && c <= 'z'){
      return true;
    }
  }
  return false;
}

Password::Password(){
  pass_history.push_back("ChicoCA-95929");
}

void Password::set(string phrase){
  if (phrase.length() >= 8 && phrase.length() <= 20){
    if (count_leading_characters(phrase) <= 3 && has_mixed_case(phrase)){
      int count_pass = count(pass_history.begin(), pass_history.end(), phrase); 
      if (count_pass == 0){
        pass_history.push_back(phrase);
      }
    }
  }
}


bool Password::authenticate(string phrase){
  if (phrase == pass_history[pass_history.size() -1 ]){
    return true;
  }
  else {
    return false;
  }
}