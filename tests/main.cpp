
#include <iostream>
#include <string>
#include "../header/factory.hpp"
using namespace std;

int main(int argc, char** argv)
{
    Factory* factory = new Factory();
    Base* calc = factory->parse(argv, argc);
    if(calc == NULL) cout << "";
    else
    {
    	cout << "Number: " << calc->evaluate() << endl;
	cout << "String: " << calc->stringify() << endl;
    }
    delete factory;
    delete calc;
    return 0;
}
