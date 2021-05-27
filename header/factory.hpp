
#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include "../header/base.hpp"
#include "../header/mult.hpp"
#include "../header/div.hpp"
#include "../header/sub.hpp"
#include "../header/add.hpp"
#include "../header/op.hpp"
#include "../header/rand.hpp"
#include "../header/pow.hpp"

#include <string>
#include <stack>
#include <cctype>
#include <algorithm>

using namespace std;

class Factory {
    public:
        Factory() {}
	
        Base* parse(char** input, int length){
           
            stack<Base*> OperandStack;
            stack<string> OperatorStack;
           stack<Base*> OutputStack;  
	  for (int i = length - 1; i >= 1; i--){
                if (isdigit(*input[i])) {
                    int val = stoi(input[i]);
		    Base* temp = new Op(val);
		    OperandStack.push(temp);
		}
		else if (*input[i] == '+' || *input[i] == '-' || *input[i] == '*' || *input[i] == '/' || *input[i] == '**') {	;
			if(!isdigit(*input[i+1])) {
				cout <<"Error: invalid input\n";
		 		return nullptr;
			}
			else {
				OperatorStack.push(input[i]);
			}
		}
	    }						                  								     while (!OperatorStack.empty()){
                string temp = OperatorStack.top();
                Base* lC = OperandStack.top();
                OperandStack.pop();
                Base* rC = OperandStack.top();
                OperandStack.pop();
                if (temp == "+"){
                    OperandStack.push(new Add(lC, rC));
                }
                else if (temp == "-"){
                    OperandStack.push(new Sub(lC, rC));
                }
                else if (temp == "*"){
                    OperandStack.push(new Mult(lC, rC));
                }
                else if (temp == "/"){
                    OperandStack.push(new Div(lC, rC));
                }
                else if (temp == "**"){
                    OperandStack.push(new Pow(lC, rC));
                }
                else {
		    return nullptr;
                }
                OperatorStack.pop();
            }
            return OperandStack.top();
        }

        bool is_number(const std::string s){
            char* end = nullptr;
            double val = strtod(s.c_str(), &end);
            return end != s.c_str() && *end == '\0' && val != HUGE_VAL; //macro constant that expands to a double positive expression
        }
};

#endif

