/*
PancakeSort. Dada una pila de numeros S, implementar la funcion
void pancake_sort(stack<int>&S) la cual ordena la pila solo haciendo operaciones en las cuales
se invierte un rango contiguo de elementos en el tope de la pila.
*/
#include <iostream>
#include <stack>
using namespace std;

void ubicacion_mayor(stack<int>& S, int hasta) {
	stack<int> S_aux = S;
	int mayor = 0;
	int indice;
	
	for(int i=0; i<hasta; ++i) {
		if(mayor<S_aux.top()) {
			mayor = S_aux.top();
			indice = i;
			S_aux.pop();
		}else{
			S_aux.pop();
		}
	}
}

void invertir(stack<int>& S, int hasta) {
	
}

void pancake_sort(stack<int>&S) {
//	stack<int> S_aux = S;
//	
//	
//	while(!S.empty) {
//		if()
//	}
}

int main() {
	stack<int> p;
	for(int i=0; i<3; ++i) {
		p.push(i+1);
	}
	ubicacion_mayor(p, p.size());
	
	return 0;
}







