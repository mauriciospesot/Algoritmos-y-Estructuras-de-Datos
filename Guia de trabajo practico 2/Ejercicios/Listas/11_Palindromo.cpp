/*
Palindromo. Escribir un predicado bool is_palindromo(char* S), que reciba como parametro
una cadena de texto S y determine si esta es un palindromo, ignorando los espacios entre palabras.
Un palindromo es una secuencia de caracteres que se lee igual hacia adelante que hacia atras, por
ejemplo: alli si maria avisa y asi va a ir a mi silla. Recordar que un string puede indexarse como
un vector. Con el fin de utilizar la estructura <list>, primero deben pasarse los elementos del
string a una lista y solo utilizar esta en el algoritmo.
*/
#include <iostream>
#include <list>
#include <cstring>
using namespace std;

bool is_palindromo(char* S) {
	list<char> C;
	
	for(int i=0; i<strlen(S); i++) {
		if(S[i] != ' ') C.push_back(S[i]);
	}
	
	list<char>::iterator it_C = C.begin();
	list<char>::iterator it_C2 = --C.end();
	
	while(it_C != it_C2) {
		if(*it_C != *it_C2) return false;
		else ++it_C;
		
		if(it_C == it_C2) return true;
		--it_C2;
	}
	
	return true;
}

int main() {
	char S[] = "alli si maria avisa y asi va a ir a mi silla";
	if(is_palindromo(S)) cout<<"Es palindromo";
	else cout<<"No es palindromo";
	
	return 0;
}







