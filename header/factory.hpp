#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include "base.hpp"
#include "add.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "op.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "sub.hpp"

#include <iostream>
#include <string>
#include <cctype>
#include <ctype.h>
#include <queue>
using namespace std;

class Factory {
	private:
		queue<Base*> operands;
		queue<string> operations;
		queue<Base*> output;

	public:
		Factory() {};

		Base* parse(char** input, int length) {
	         for(int i = 1; i < length; i++) {
                  if(isdigit(*input[i])) {
                          int val = atoi(input[i]); //atoi function converts string to integer
                          Base* temp = new Op(val);
                          operands.push(temp);
                  }
                  else if (*input[i] == '+' || *input[i] == '-' || *input[i] == '/' ||  *input[i] == '**') {
                          if (!isdigit(*input[i+1])) {
                                  cout << "Error: invalid input\n";
                                  return nullptr;
                          }
			}
                  else {
                          operations.push(input[i]);
                  }
                  }
  
  
                  output.push(operands.front());
                  operands.pop();
                  while(!operations.empty()){
                          Base* val1 = output.front();
                          output.pop();
                          Base* val2 = operands.front();
                          operands.pop();
                          Base* answer;
  
                          if(operations.front() == "+"){
                                  answer  = new Add(val1, val2);
                          }
                          else if(operations.front() == "-"){
                                  answer  = new Sub(val1, val2);
                          }
                          else if(operations.front() == "*"){
                                  answer  = new Mult(val1, val2);
                          }
                          else if(operations.front() == "/"){
                                  answer = new Div(val1, val2);
                          }
                          else if(operations.front() == "**"){
                                  answer = new Pow(val1, val2);
                          }
                          output.push(answer);
                          operations.pop();
                          }
                          return output.front();
                          output.pop();
                  }
                  //return output.front();        
          };
#endif //__FACTORY_HPP__
