 
#include "../header/factory.hpp"

int main(int argv, char** argc){

Factory* factory = new Factory();
Base* calculate = factory -> parse(argc, argv);
if (calculate == NULL) {
          cout << "";
}
else {
        cout << "String: " << calculate -> stringify() << endl << "Number: " << calculate -> evaluate() << endl;
}
 delete factory;
 delete calculate;
cout << calculate -> stringify() << endl << calculate -> evaluate() << endl;

return 0;
}
