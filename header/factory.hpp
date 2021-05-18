#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include "../header/add.hpp"
#include "../header/div.hpp"
#include "../header/mult.hpp"
#include "../header/op.hpp"
#include "../header/pow.hpp"
#include "../header/rand.hpp"
#include "../header/sub.hpp"

#include <iostream>
#include <cstring>
#include <vector>
#include <stdlib.h>
#include <queue>
using namespace std;


class Factory
{
  public:
     Factory() { };
     Base* parse(char** input, int length){
	queue<string> q;
	string str;
	int counter = 0;
        for(unsigned i = 1; i < length; i++){
	   str = static_cast<string>(input[i]);
           q.push(str);
	   counter++;
        }
	Base* prev;
	Base* cur;
	bool prevBool = false, curBool = false, isOper = false, isNumber = true;
	char oper;
	double val;
	string::size_type sz;
	string s;
	while(!q.empty())
	{
	   s = q.front();
	   q.pop();
	  if(!prevBool)
	  {
	    if(is_number(s)){
	       val = stod(s);
	       prev = new Op(val);
	       prevBool = true;
	    }
	    else
	    {
	       cout << "Invalid input" << endl;
	       return NULL;
	    }
	   }
	  else if(prevBool && !isOper && !curBool)
	  {
	     if(s == "-") {
		 oper = '-';
	     }             
             else if(s == "+") {
		oper = '+';
             }     
	     else if(s == "*") {
		oper = '*';
	     }             
	    else if(s == "/") {
		oper = '/';
	    }            
          else if(s == "**") {
	        oper = '^';
	     }	
         else return NULL;
             isOper = true;	
	  }
	else{
	  if(is_number(s)){
	     val = stod(s);
	     cur = new Op(val);
	     prev = calculate(prev, cur, oper);
	     isOper = false;
	  }
	  else
	  {
	     cout << "Invalid input" << endl;
	     return NULL;
	  }
	}
	}
	return prev;
}

Base* calculate(Base* prevValue, Base* curValue, char operand) {
        switch(operand)
        {
           case '-' :
             return new Sub(prevValue, curValue);
             break;

           case '+' :
             return new Add(prevValue, curValue);
             break;

           case '*' :
             return new Mult(prevValue, curValue);
             break;

          case '/' :
            return new Div(prevValue, curValue);
            break;
	  
	  case '^':
	    return new Pow(prevValue, curValue);
	    break;

          default :
            return NULL;

        }

    }
   
bool is_number(string str){
     for(int i = 0;i < (strlen(str.c_str()) - 1);i++) {
		if(isdigit(str[i]) == false) return false;
	}
	return true;
   }

};

#endif //__FACTORY_HPP
