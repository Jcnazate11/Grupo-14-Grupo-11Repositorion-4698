//Universidad de las Fuerzas Armadas ESPE
// Enunciado: Notacion infija, prefija, postfija
// Autor: Jeanhela Nazate, Milena Maldonado, Johan Romo y Cristhopher Villamarin 
// Fecha de creación: 15/05/2022
// Fecha de modificación: 17/05/2022
// Github: https://github.com/Jcnazate11/Grupo-14-Grupo-11Repositorion-4698/edit/main/PARCIAL1/TALLERGRUPAL1/NOTACIONES/posfijo.h

#ifndef PROYECTO_POSTFIJO_H
#define PROYECTO_POSTFIJO_H
#include <bits/stdc++.h>
#include <iostream>
#include "Pila.h"
#include <cstdlib>
#include <string>
#include <string.h>
#include <stack>
#include <cmath>
#include<string.h>
#define PI 3.1415
#define N_operators 10

using namespace std;

class Postfijo {
    private:
        static bool is_operator(const string );
        static int precedence(const string );
    public:
        Postfijo() = default;

        static string infijoAPostfijo(string&);
        static string infijoAPrefijo( string&);
        static void imprimir( );
       
};
const string operators[N_operators] = {"+", "-", "*", "/", "%", "^", "r", "s", "t","c"};
int precedences[N_operators] = {1, 1, 2, 2, 2, 3,3, 4, 4, 4};

string Postfijo::infijoAPostfijo( string &infix)
{
	string postfix, token;
    	stack <string> standby;
    	stack <double> result;
    	size_t i;
    	char c;
    	double A, B;
     
    	/* Cadena de entrada 
    	cout << "Ingrese una expresion infija: ";
    	getline( cin, infix );
    	cout << endl;*/
     
    	/*************************************************************
    	  PRIMERA PARTE: Procesar la cadena infijo, y crear posfijo 
    	 *************************************************************/
    	 
    	for ( i = 0; i < infix.size(); i++ ) {
    		
    		c = infix[i];
    		token.clear();
    		token += c;		
   //  for ()
    	
    		if ( c == ' ' ) continue;
     
    	//	cout << "Analizando token: '" << c << "'" << endl;
     
    		
    		if ( c >= '0' && c <= '9' ) {
    		//	cout << "\tes numero: pasado a posfijo" << endl << endl;
    			postfix = postfix + " " + c;
    			continue;
    		}
     
    	
    		if ( is_operator( token ) ) {
    		//	cout << "\tes operador:" << endl;
    			while ( !standby.empty() && precedence( standby.top() ) 
    						>= precedence( token ) ) {
    			//	cout << "\tpasado operador '" + standby.top() + 
    				//	"' de la pila a posfijo" << endl;
    				postfix = postfix + " " + standby.top();
    				standby.pop();
    			}
    			standby.push( token );
    		//	cout << "\tcolocar '" << token << "' en la pila" << endl << endl;
    			continue;
    		}
     
    	
    		if ( token == "(" ) {
    		//	cout << "pasado a posfijo" << endl << endl;
    			standby.push( token );
    			continue;
    		}
     
    
    		if ( token == ")" ) {
    			while ( !standby.empty() && standby.top() != "(" ) {
    			//	cout << "\tpasado operador '" + standby.top() + 
    			//		"' de la pila a posfijo" << endl << endl;
    				postfix = postfix + " " + standby.top();
    				standby.pop();
    			}
    			if ( !standby.empty() )
    				standby.pop();	/* descartar el "(" */
    		}
    	}
     
    	while ( !standby.empty() ) {
    	//	cout << "Pasado operador '" + standby.top() + 
    	//		"' de la pila a posfijo" << endl << endl;
    		postfix = postfix + " " + standby.top();
    		standby.pop();
    	}
     
    	/* Imprimir el posfijo */
    	//cout << "Posfijo es: \n\t" << postfix << endl << endl;
     
    	/****************************************************************
    	  SEGUNDA PARTE: Procesar la cadena posfijo, y devolver resultado
    	 ****************************************************************/
     
    	A = 0;
    	cout << "Evaluando la expresion ..." << endl;
    	for ( i = 0; i < postfix.size(); i++ ) {
     
    		c = postfix[i];
    		token.clear();
    		token += c;
     
    		//233+
    		if ( c >= '0' && c <= '9' ) {
    			result.push( c - '0' );
    			continue;
    		}
     
    	
    		if ( is_operator( token ) ) {
    			
   
    			cout << "\tResultado parciales: " << A << token << B << " = ";
    			if ( token == "+" ) { //SUMA 
    				///////////////////////////////////////////////////////////////////////////////////////
    			if ( !result.empty() ) {
    				B = result.top();
    				result.pop();
    				
    			}
    			else {
    				cout << "Argumentos insuficientes para '" << c << "'" << endl;
    				return 0;
    			}
     
    			if ( !result.empty() ) {
    				A = result.top();
    				result.pop();
    			
    			}
    			else {
    				cout << "Argumentos insuficientes para '" << c << "'" << endl;
    				return 0;
    			}
     ///////////////////////////////////////////////////////////////////////////////////////////
    				A += B;
    				result.push( A );
    			}
    			else if ( token == "-" ) { //RESTA
    /////////////////////////////////////////////////////////////////////////////
    				 			
    			if ( !result.empty() ) {
    				B = result.top();
    				result.pop();
    				
    			}
    			else {
    				cout << "Argumentos insuficientes para '" << c << "'" << endl;
    				return 0;
    			}
     
    			if ( !result.empty() ) {
    				A = result.top();
    				result.pop();
    			
    			}
    			else {
    				cout << "Argumentos insuficientes para '" << c << "'" << endl;
    				return 0;
    			}
     //////////////////////////////////////////////////////////////////////////////////////
    				A -= B;
    				result.push( A );
    			}
    			else if ( token == "*" ) { //MULTIPLICACION
    	/////////////////////////////////////////////////////////////////////////////////////// 			
    			if ( !result.empty() ) {
    				B = result.top();
    				result.pop();
    				
    			}
    			else {
    				cout << "Argumentos insuficientes para '" << c << "'" << endl;
    				return 0;
    			}
     
    			if ( !result.empty() ) {
    				A = result.top();
    				result.pop();
    			
    			}
    			else {
    				cout << "Argumentos insuficientes para '" << c << "'" << endl;
    				return 0;
    			}
     //////////////////////////////////////////////////////////////////////////////////////////
    				A *= B;
    				result.push( A );
    			}
    			else if ( token == "/" ) { //DIVISION
    		/////////////////////////////////////////////////////////////////////////////////////////
    			if ( !result.empty() ) {
    				B = result.top();
    				result.pop();
    				
    			}
    			else {
    				cout << "Argumentos insuficientes para '" << c << "'" << endl;
    				return 0;
    			}
     
    			if ( !result.empty() ) {
    				A = result.top();
    				result.pop();
    			
    			}
    			else {
    				cout << "Argumentos insuficientes para '" << c << "'" << endl;
    				return 0;
    			}
     ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    				A /= B;
    				result.push( A );
    			}
    			else if ( token == "%" ) { //PORCENTAJE
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////				 			
    			if ( !result.empty() ) {
    				B = result.top();
    				result.pop();
    				
    			}
    			else {
    				cout << "Argumentos insuficientes para '" << c << "'" << endl;
    				return 0;
    			}
     
    			if ( !result.empty() ) {
    				A = result.top();
    				result.pop();
    			
    			}
    			else {
    				cout << "Argumentos insuficientes para '" << c << "'" << endl;
    				return 0;
    			}
     /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    				A = (int )A % (int )B;
    				result.push( A );
    			}
    			else if ( token == "^" ) {//EXPONENTE
    				/////////////////////////////////////////////////////////////////////////////////
    				 			
    			if ( !result.empty() ) {
    				B = result.top();
    				result.pop();
    				
    			}
    			else {
    				cout << "Argumentos insuficientes para '" << c << "'" << endl;
    				return 0;
    			}
     
    			if ( !result.empty() ) {
    				A = result.top();
    				result.pop();
    			
    			}
    			else {
    				cout << "Argumentos insuficientes para '" << c << "'" << endl;
    				return 0;
    			}
     //////////////////////////////////////////////////////////////////////////////////////////
    				A = pow(A, B);
    				result.push( A );
    			}else if ( token == "r" ) {//RAIZ
    				/////////////////////////////////////////////////////////////////////////////////
    				 			
    			if ( !result.empty() ) {
    				A = result.top();
    				result.pop();
    			
    			}
    			else {
    				cout << "Argumentos insuficientes para '" << c << "'" << endl;
    				return 0;
    			}
     //////////////////////////////////////////////////////////////////////////////////////////
    				A = sqrt(A);
    				result.push( A );
    			}
    				else if ( token == "s" ) { //SENO
    		////////////////////////////////////////////////////////
    		if ( !result.empty() ) {
    				A = result.top();
    				result.pop();
    			
    			}
    			else {
    				cout << "Argumentos insuficientes para '" << c << "'" << endl;
    				return 0;
    			}
    			////////////////////////////////////////////////////////////////////////
    			double rad;
			
    				rad= (A*PI)/180;
  
    				A= sin(rad);
    				result.push( rad);
    			}
    				else if ( token == "t" ) { //TANGENTE
    		////////////////////////////////////////////////////////
    		if ( !result.empty() ) {
    				A = result.top();
    				result.pop();
    			
    			}
    			else {
    				cout << "Argumentos insuficientes para '" << c << "'" << endl;
    				return 0;
    			}
    			////////////////////////////////////////////////////////////////////////
    			double rad;
			
    				rad= (A*PI)/180;
  
    				A= tan(rad);
    				result.push( rad);
    			}	else if ( token == "c" ) { // COSENO
    		////////////////////////////////////////////////////////
    		if ( !result.empty() ) {
    				A = result.top();
    				result.pop();
    			
    			}
    			else {
    				cout << "Argumentos insuficientes para '" << c << "'" << endl;
    				return 0;
    			}
    			////////////////////////////////////////////////////////////////////////
    			double rad;
			
    				rad= (A*PI)/180;
  
    				A= cos(rad);
    				result.push( rad);
    			}

    			
    			cout << A << endl;
    		}
    	}
     
    	if ( !result.empty() )
    		cout << endl << "El resultado es: " << result.top() << endl;
       
   return postfix;
}

string Postfijo::infijoAPrefijo( string &infix){
 int l = infix.size();
 
    // Reverse infix
    reverse(infix.begin(), infix.end());
 
    // Replace ( with ) and vice versa
    for (int i = 0; i < l; i++) {
 
        if (infix[i] == '(') {
            infix[i] = ')';
            i++;
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
            i++;
        }
    }
 
    string prefix = infijoAPostfijo(infix);
 
    // Reverse postfix
    reverse(prefix.begin(), prefix.end());
 
    return prefix; 
    
}


bool Postfijo::is_operator(const string token)
{
     	for ( int i = -1; i < N_operators; i++ )
    		if ( operators[i] == token ) 
    			return true;
     
    	return false;
}

int Postfijo::precedence(const string token)
{
    	for ( int i = 0; i < N_operators; i++ )
    		if ( operators[i] == token ) 
    			return precedences[i];
     
    	return -1;

}

#endif //PROYECTO_POSTFIJO_H
