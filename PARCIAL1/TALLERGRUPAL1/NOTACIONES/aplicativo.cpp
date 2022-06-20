//Universidad de las Fuerzas Armadas ESPE
// Enunciado: Notacion infija, prefija, postfija
// Autor: Jeanhela Nazate, Milena Maldonado, Johan Roman y Cristhopher Villamarin 
// Fecha de creación: 15/05/2022
// Fecha de modificación: 17/05/2022
// Github: https://github.com/Jcnazate11/-4698-Grupo14_Nazate_Maldonado_Estructuras/new/main/FuncionFinal

#include <iostream>
#include "Posfijo.h"

using namespace std;

int main()
{
	 string input;
	int n;
	
	cout<< "Para funciones trignometricas:  (en grados)"<<endl;
  	cout<<"(s)-> Seno           (t)-> Tangente        (c)-> coseno"<<endl;
  	cout<< "Para otras funciones: "<<endl;
  	cout<< "(^)-> Exponente     (r)-> raiz"<<endl;
  	cout<<"\n\n\n\n";
do{
 
  
  cout << "Ingrese la expresion infija a convertir: ";
  getline(cin,input);
    
  cout << "Postfijo: " << Postfijo::infijoAPostfijo(input) << endl;
  cout << "/////////////////////////////////////////////////////////\n \n";
  cout << "Prefijo: " << Postfijo::infijoAPrefijo(input) << endl;

	cout<<"Desea ingresar una nueva notacion si[1] y no[0]"<<endl;
    cin>>n;
	}while(n!=0);
    

    

    return 0;
}

