#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>

int main(){
    std::unordered_map<std::string, std::unordered_map<std::string, int>> Enums;
    std::unordered_map<std::string, std::unordered_map<std::string, int>>::iterator Enums_it;
    
    std::unordered_map<std::string, int>* enumgen;
    int countvalue = 0;
    std::vector<std::pair<std::string, std::string>> operands;

    operands.push_back(std::pair<std::string, std::string>("variable","x"));
    operands.push_back(std::pair<std::string, std::string>("number", "10"));

    enumgen = new std::unordered_map<std::string, int>;
    enumgen->insert(std::pair<std::string, int>("x", 10));
    Enums.insert(std::pair<std::string, std::unordered_map<std::string, int>>("noname", *enumgen));
    Enums.insert(std::pair<std::string, std::unordered_map<std::string, int>>("lelmaokelbao", *enumgen));
    std::cout << operands.front().first << std::endl;
    if(operands.front().first == "variable"){
        bool found = false;
        for(Enums_it=Enums.begin(); Enums_it!=Enums.end(); Enums_it++){
            if(found == true){
                break;
            }
            std::unordered_map<std::string,int>::iterator sec_it;
            for(sec_it=Enums_it->second.begin();sec_it!=Enums_it->second.end(); sec_it++){
                
                std::cout << sec_it->first << std::endl;
                if(sec_it->first == operands.front().second){
                    found = true;
                    operands.front().first= "number";
                    operands.front().second = std::to_string(sec_it->second);
                    break;
                }
            }
        }
        if(found == false){
            std::cout << operands.front().second << std::endl;;
            enumgen = new std::unordered_map<std::string, int>;
            Enums["noname"].insert(std::pair<std::string, int>(operands.front().second, countvalue));
            countvalue++;
        }
    }
    return 0;
}