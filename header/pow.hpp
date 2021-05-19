

#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include "op.hpp"
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

class Pow : public Base {
        private:
                Base* leftChild = NULL;
                Base* rightChild = NULL;
        public:
                Pow(Base* left, Base* right) {
                       this->leftChild = left;
                       this->rightChild = right;
                }
                virtual double evaluate() {
                        return pow(leftChild->evaluate(), rightChild->evaluate()); 
                }
                virtual std::string stringify() {
                        ostringstream out;
                        out << setprecision(5) << leftChild->stringify() << " ** " << rightChild->stringify();
                        return out.str();
                }
};

#endif //__POW_HPP__

