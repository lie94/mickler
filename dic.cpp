#include<string>
#include<vector>
#include<fstream>
#include<map>

#ifndef F_DIC
#define F_DIC

namespace dic{

std::vector<std::string> split(const std::string sentance){
  int pos = 0;
  int lastPos = pos;
  std::vector<std::string> words;

  while (pos <= sentance.size()) {
    if(sentance[pos] == ' '){
      words.push_back(sentance.substr(lastPos, pos - lastPos));
      lastPos = pos + 1;
    }else if(sentance[pos] == '\n'){
      words.push_back(sentance.substr(lastPos, pos - lastPos));
      words.push_back("\n");
      lastPos = pos + 1;
    }
    pos++;
  }
  words.push_back(sentance.substr(lastPos));
  return words;
}

void swap(std::vector<std::string>  & words){
  std::ifstream dicfile;
  dicfile.open("dic.dat");
  std::string line;
  std::map<std::string, std::string> map;

  if(dicfile.is_open()){

    while(getline(dicfile, line)){
      if(line[0] == '#')
      continue;
      std::vector<std::string> words = split(line);
      map[words[0]] = words[1];
    }

    for(int i = 0; i < words.size(); i++){
      std::string lowerword = "";
      for(char c : words[i]){
        lowerword += tolower(c);
      }

      if(map.find(lowerword) != map.end()){
        words[i] = map[lowerword];
      }
    }


  }else{
    std::cerr << "Could not find dic.dat" << std::endl;
  }
}

}

#endif
