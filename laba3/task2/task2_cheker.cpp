#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

 int main(int argc, char const *argv[])
 {
    if (argc<2){
        std::cout << " введите названия файла для проверки"<<std::endl;
    }
    std::ifstream file(argv[1]); 
    if (!file.is_open()) {
        std::cerr << "Unable to open file." << std::endl;
        return 1;
    }
    int all = 0;
    int accepted = 0;
    std::string line;
    while (std::getline(file, line)) { 
        std::istringstream iss(line);
        std::vector<std::string> tokens;

        std::string token;
        while (iss >> token) {
            tokens.push_back(token);
        }

        if (tokens[0]=="pow"){
            if (std::pow(stoi(tokens[1]),stoi(tokens[2]))==stoi(tokens[4])){
            accepted++;
            }
            all++;
        }
          if (tokens[0]=="sin"){
              if (std::abs(std::sin(stod(tokens[1]))-stod(tokens[3]))<1e-5){
                 accepted++;
            }
            all++;
        }
        if (tokens[0]=="sqrt"){
            if (std::abs(std::sqrt(stod(tokens[1]))-stod(tokens[3]))<1e-5){
                accepted++;
            }
            all++;
        }
    }
    std::cout<<"файл "<<argv[1]<<" точность = "<< static_cast<double>(accepted)/static_cast<double>(all)<<std::endl;

    file.close();

    return 0;
}