/*
Varios. Utilizando las operaciones del contenedor stack<> de STL, construir una serie de
procedimientos que realicen cada una de las actividades siguientes en una pila:
a) Asignar i al segundo elemento desde la parte superior de la pila, dejando la pila sin sus dos
elementos de la parte superior.
b) Asignar i al segundo elemento desde la parte superior de la pila, sin modicarla
c) Dado un entero n, asignar i al elemento n-esimo desde la parte superior de la pila, dejando la
pila sin sus n elementos superiores.
d) Asignar i al elemento del fondo de la pila, dejando la pila vacia.
e) Asignar i al elemento del fondo de la pila, dejando la pila sin modicar.
*/

#include <iostream>
#include <stack>
using namespace std;

void asignarA(stack<int>& s) {
	int i = 9;
	s.pop();
	s.pop();
	s.push(i);
}

void asignarB(stack<int>& s) {
	int i = 9, aux1 = s.top();
	s.pop();
	int aux2 = s.top();
	s.pop();
	s.push(i);
	s.push(aux2);
	s.push(aux1);
}

void asignarC(stack<int>& s, int n) {
	int i = 9;
	
	for(int i=0;i<n;i++) { 
		s.pop();
	}
	s.push(i);
}

void asignarD(stack<int>& s) {
	int i = 9;
	int s_size = s.size();
	
	for(int i=0;i<s_size;i++) { 
		s.pop();
	}
	s.push(i);
}

void asignarE(stack<int>& s) {
	int i = 9;
	int s_size = s.size();
	stack<int> aux;
	
	for(int i=0;i<s_size;i++) {
		aux.push(s.top());
		s.pop();
	}
	s.push(i);
	
	for(int i=0;i<s_size;i++) { 
		s.push(aux.top());
		aux.pop();
	}
	
	
}

int main() {
	stack<int> s;
	s.push(3);
	s.push(4);
	s.push(2);
	s.push(1);
	
	asignarE(s);
	
	while(!s.empty()) {
		cout<<s.top()<<endl;
		s.pop();
	}
	
	
	
	return 0;
}







