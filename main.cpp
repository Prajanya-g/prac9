// Prajanya Gupta 
// 28/05/22
// main file to evaluate prefix expression 
#include "prefixSolver.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


int main(void){
    stringstream ss;
    string str;
    getline(cin, str);
    replace( str.begin(), str.end(), ',', ' ');
    ss << str;
    string input;
    int countDigit = 0;
    int countOperation = 0;
    while (ss >> input)
    {   
        if(input <= "9" && input >= "0"){
            if(stoi(input) > 99){
            }
            else{
                countDigit++;
            }
        }
        else if(input == "+"|| input == "-" || input == "*" || input == "/"){
            countOperation++; 
        }
    }
     if(countDigit == countOperation+1){
        prefixSolver solver;
        solver.solvePrefix(str);
    }
    else{
        cout<<"Error"<<endl;
    }
}