/*
Inverso. Escribir un procedimiento bool inverso(list<char>&z) para determinar si una cadena
de caracteres de entrada es de la forma z=xy donde y es la cadena inversa (o espejo) de la cadena
x, ignorando los espacios en blanco. Emplear una cola y una pila auxiliares.
*/

#include <iostream>
#include <list>
#include <stack>
#include <queue>
using namespace std;

bool inverso(list<char>&z) {
	list<char>::iterator it_z = z.begin();
	stack<char> pila;
	queue<char> cola;
	
	while(it_z != z.end()) {
		if(*it_z == ' ') it_z = z.erase(it_z);
		else ++it_z;
	}
	if(z.size()%2 != 0) return false;
	
	it_z = z.begin();
	for(unsigned i=0; i<z.size()/2; ++i) {
		cola.push(*it_z);
		++it_z;
	}
	
	for(unsigned i=z.size()/2; i<z.size(); ++i) {
		pila.push(*it_z);
		++it_z;
	}
	
	for(unsigned i=0; i<cola.size(); i++){
		if(cola.front() == pila.top()) {
			cola.pop();
			pila.pop();
		}else{
			return false;
		}
	}
	
	return true;
}

int main() {
	list<char> z = {'n','e','u','q','u','e','n'};
	if(inverso(z)) cout<<"es inverso";
	else cout<<"no es inverso";
	return 0;
}







