// Prajanya Gupta 
// 28/05/22
// main file to evaluate prefix expression 
#include "prefixSolver.h"
#include <iostream>
#include <string>
#include <sstream>

bool expressionCheck(std::string input){
    int countDigit = 0;
    int countOperation = 0;
    for (int i = 0; i < input.size(); i++)
    {
        if(input[i] <= '9' && input[i] >= '0'){
            countDigit++;
        }
        else{
            countOperation++; 
        }
    }
    if(countDigit == countOperation+1){
        return true;
    }
    return false;
}

int main(void){
    std::string str;
    std::cin >> str;
    if(expressionCheck(str) == true){
        prefixSolver solver;
        std::cout<< solver.solvePrefix(str)<<std::endl;
    }
    else{
        std::cout<<"Error"<<std::endl;
    }
}