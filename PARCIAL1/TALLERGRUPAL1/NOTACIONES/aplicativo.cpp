#include <iostream>
#include "Posfijo.h"

using namespace std;

int main()
{
  string input;
  cout << "Ingrese la expresion infija a convertir: ";
  getline(cin,input);
    
  cout << "Postfijo: " << Postfijo::infijoAPostfijo(input) << endl;
  cout << "/////////////////////////////////////////////////////////\n \n";
  cout << "Prefijo: " << Postfijo::infijoAPrefijo(input) << endl;


    

    

    return 0;
}
