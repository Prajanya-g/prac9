//Prajanya Gupta 
//28/05/22
//function in teh class prefixSolver to solve a prefix expression 
#include "prefixSolver.h"
#include <iostream>
#include <stack>
#include <sstream>
#include <algorithm>
#include <string>

prefixSolver::prefixSolver(){
}

int solve(int a, int b, std::string op){
    if (op == "+"){
        return a + b;
    }
    else if(op == "-"){
        return a - b;
    }
    else if(op == "*"){
        return a * b;
    }
    else if(op == "/"){
        return a / b;
    }
    return 0;
}

int prefixSolver::solvePrefix(std::string expression){
    std::stack<std::string> infix;
    std::stack<int> result;
    std::stringstream ss;
    std::reverse(expression.begin(),expression.end());
    ss.str(expression);
    std::string input;
    while (ss >> input)
    {    
        if (input == "+"||input == "-"||input == "*"||input == "/") {
            std::string digitOne = infix.top();   
            infix.pop();
            std::string digitTwo = infix.top();   
            infix.pop();
            std::string temp = "("+digitOne + input + digitTwo +")";
            infix.push(temp);
            int val1 = result.top();   
            result.pop();
            int val2 = result.top();   
            result.pop();
            int res = solve(val1,val2,input);
            result.push(res);
        }
        else {
            std::reverse(input.begin(),input.end());
            infix.push(input);
            result.push(stoi(input));
        }
    }
    std::cout<<infix.top()<< "=" << result.top() << std::endl; 
    return result.top();
}
