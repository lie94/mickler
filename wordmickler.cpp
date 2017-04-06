
#ifndef F_WORDMICKLER
#define F_WORDMICKLER


#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<iterator>
#include<stdlib.h>
#include<time.h>

void randomizeCase(std::string & word){
  for(int i = 0; i < word.size(); i++){
    if(isalpha(word[i]) && rand() % 10 < 5){
      word[i] = toupper(word[i]);
    }else if(isalpha(word[i])){
      word[i] = tolower(word[i]);
    }
  }
}

void wordscramble(std::vector<std::string> & words, const int MAX_REPEAT){

  srand(time(NULL));

  int size = words.size();

  for(int j = 0; j < size; j++){
    std::string word = words[j];
    if(word == "\n"){

      continue;
    }

    //random amount
    if(rand() % 10 < 5){
      int limit = rand() % (MAX_REPEAT - 1);
      for(int i = 0; i < limit; i++){

        randomizeCase(word);
        words.insert(words.begin() + j + 1 + i, word);

      }
      j += limit;
      size += limit;
    }
    if(rand() % 10 < 5){
      randomizeCase(word);
    }
    words[j] = word;
  }
}

#endif
