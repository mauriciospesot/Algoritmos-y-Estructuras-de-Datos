/*
PancakeSort. Dada una pila de numeros S, implementar la funcion
void pancake_sort(stack<int>&S) la cual ordena la pila solo haciendo operaciones en las cuales
se invierte un rango contiguo de elementos en el tope de la pila.
*/
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int ubicar_mayor(stack<int>& S, int hasta) {
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
	return ++indice;
}

void invertir(stack<int>& S, int hasta) {
	queue<int> cola;
	//se guarda el indice en donde se encuentra el mayor
	int max_index = ubicar_mayor(S, hasta);
	
	//se pasan los elementos desde el inicio hasta el mayor a una cola
	for(int i=0;i<max_index;i++) { 
		cola.push(S.top());
		S.pop();
	}
	//se invierte en S desde el principio hasta el maximo
	while(!cola.empty()) {
		S.push(cola.front());
		cola.pop();
	}
	//se pasa a una cola toda la pila hasta 'hasta'
	for(int i=0;i<hasta;i++) { 
		cola.push(S.top());
		S.pop();
	}
	//se pasa de la cola de nuevo a la pila para invertir todo el bloque
	while(!cola.empty()) {
		S.push(cola.front());
		cola.pop();
	}
	
}

void pancake_sort(stack<int>&S) {
	int S_size = S.size();
	
	while(S_size != 1) {
		invertir(S, S_size);
		--S_size;
	}
}

int main() {
	stack<int> p;
	p.push(13);
	p.push(22);
	p.push(1);
	p.push(3);
	p.push(2);
	p.push(9);
	
	pancake_sort(p);
	int p_size = p.size();
	
	for(int i=0;i<p_size;++i) { 
		cout<<p.top()<<" ";
		p.pop();
	}
	return 0;
}







