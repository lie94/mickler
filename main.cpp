#include"wordmickler.cpp"
#include"micklerclassic.cpp"
#include<iostream>

/*
 * -c classic mickler
 * -w wordscramble mickler - reads from stdin and scrambles it
 */

int main(int argc, char * argv[]){

  for(int i = 0; i < argc; i++){
    if(argv[i][0] == '-'){
      switch(argv[i][1]){
        case 'c':
          classic();
          return 0;
        break;
        case 'w':
          wordscramble();
          return 0;
        break;
      }
    }
  }
  std::cerr << "Must use arguments -w for wordscramble or -c for micklerclassic" << std::endl;

}
