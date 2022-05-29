//Prajanya Gupta 
//28/05/22
//function in teh class prefixSolver to solve a prefix expression 
#include "prefixSolver.h"
#include <iostream>
#include <stack>

prefixSolver::prefixSolver(){
}

int solve(int a, int b, char op){
    switch(op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

int prefixSolver::solvePrefix(std::string expression){
    std::stack<std::string> infix;
    std::stack<int> result;
    for (int index = expression.size()-1; index >= 0; index--) {
        if (expression[index] == '+'||expression[index] == '-'||expression[index] == '*'||expression[index] == '/') {
            std::string digitOne = infix.top();   
            infix.pop();
            std::string digitTwo = infix.top();   
            infix.pop();
            std::string temp = "("+digitOne + expression[index] + digitTwo +")";
            infix.push(temp);
            int val1 = result.top();   
            result.pop();
            int val2 = result.top();   
            result.pop();
            int res = solve(val1,val2,expression[index]);
            result.push(res);
        }
        else {
            infix.push(std::string(1,expression[index]));
            result.push(expression[index] - '0');
        }
    }
    std::cout<<infix.top()<< "=" << result.top() << std::endl; 
    return result.top();
}
