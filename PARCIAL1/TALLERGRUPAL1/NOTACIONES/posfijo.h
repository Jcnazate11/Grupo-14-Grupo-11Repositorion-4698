#include <iostream>
#include "Pila.h"
#include <cstdlib>
#include <string>
#include <stack>
#include <cmath>
#include<string.h>
#define N_operators 7

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
const string operators[N_operators] = {"+", "-", "*", "/", "%", "^","s"};
int precedences[N_operators] = {1, 1, 2, 2, 2, 3, 4};
const double pi = std::acos(-1);

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
     
    	
    		if ( c == ' ' ) continue;
     
    	//	cout << "Analizando token: '" << c << "'" << endl;
     
    		
    		if ( c >= '0' && c <= '10' ) {
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
     
    		
    		if ( c >= '0' && c <= '9' ) {
    			result.push( c - '0' );
    			continue;
    		}
     
    	
    		if ( is_operator( token ) ) {
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
     
    			cout << "\tOperar " << A << token << B << " = ";
    			if ( token == "+" ) {
    				A += B;
    				result.push( A );
    			}
    			else if ( token == "-" ) {
    				A -= B;
    				result.push( A );
    			}
    			else if ( token == "*" ) {
    				A *= B;
    				result.push( A );
    			}
    			else if ( token == "/" ) {
    				A /= B;
    				result.push( A );
    			}
    			else if ( token == "%" ) {
    				A = (int )A % (int )B;
    				result.push( A );
    			}
    			else if ( token == "^" ) {
    				A = pow(A, B);
    				result.push( A );
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
     	for ( int i = 0; i < N_operators; i++ )
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
