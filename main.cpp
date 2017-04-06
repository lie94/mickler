#include"wordmickler.cpp"
#include"micklerclassic.cpp"
#include"dic.cpp"
#include<string>

#include<iostream>

#define MAX_REPEAT 5

void printWords(std::vector<std::string> s){

  std::cout << std::endl;
  for(int i = 0; i < s.size() - 1; i++){
    std::cout << s[i];

    if(s[i] != "\n"){
        std::cout << " ";
    }
  }
  std::cout << std::endl;
}

std::vector<std::string> read(){
  std::string text = "";
  std::string input;
  while(getline(std::cin, input)){

    text.append(input);
    text.append("\n");

  }
  return dic::split(text, ' ');
}


/*
 * -c                      - classic mickler
 * -w wordscramble mickler - reads from stdin and scrambles it
 * -d dictionary           - used words are changed if in ordbok.dat
 */

int main(int argc, char * argv[]){
  bool c = false;
  bool w = false;
  bool d = false;
  for(int i = 0; i < argc; i++){
    if(argv[i][0] == '-'){
      int j = 1;
      while(argv[i][j] != '\0'){
        switch(argv[i][j]){
          case 'c':
          c = true;
          break;
          case 'w':
          w = true;
          break;
          case 'd':
          d = true;
          break;

        }
        j++;
      }
    }
  }
  if(!(c || w || d)){
    std::cerr << "Must use at least one of arguments:" << std::endl;
    std::cerr << "  -c      " << std::endl;
    std::cerr << "      classic mickler" << std::endl;

    std::cerr << "  -d      " << std::endl;
    std::cerr << "      swaps word with help of dictionary" << std::endl;

    std::cerr << "  -w      " << std::endl;
    std::cerr << "      scramles case and number of words" << std::endl;

    return 1;
  }

  std::vector<std::string> words = read();

  if(c && w){
    std::cerr << "Can't use both classic mickler and wordscramble" << std::endl;
  }
  if(d){
    dic::swap(words);
  }
  if(w){
    wordscramble(words, MAX_REPEAT);
  }
  printWords(words);
  return 0;
}
