
#ifndef F_WORDMICKLER
#define F_WORDMICKLER

#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<iterator>
#include<stdlib.h>
#include<time.h>


#define MAX_REPEAT 8

std::vector<std::string> split(const std::string sentance){
  int pos = 0;
  int lastPos = pos;
  std::vector<std::string> words;

  while (pos <= sentance.size()) {
    if(sentance[pos] == ' ' || sentance[pos] == '\n'){
      words.push_back(sentance.substr(lastPos, pos - lastPos));
      lastPos = pos + 1;
    }
    pos++;
  }
  words.push_back(sentance.substr(lastPos));
  return words;
}

void randomizeCase(std::string & word){
  for(int i = 0; i < word.size(); i++){
    if(isalpha(word[i]) && rand() % 10 < 5){
      word[i] = toupper(word[i]);
    }else if(isalpha(word[i])){
      word[i] = tolower(word[i]);
    }
  }
}

void wordscramble(){
  std::string input = " ";
  srand(time(NULL));
  while(getline(std::cin, input)){
    std::vector<std::string> words;
    words = split(input);

    for(std::string word : words ){
      //random amount
      if(rand() % 10 < 5){
        int limit = rand() % (MAX_REPEAT - 1);
        for(int i = 0; i < limit; i++){

          randomizeCase(word);

          std::cout << word << " ";
        }
      }
      if(rand() % 10 < 5){
        randomizeCase(word);
      }
      std::cout << word << " ";
    }
    std::cout << std::endl;
  }
}

#endif
