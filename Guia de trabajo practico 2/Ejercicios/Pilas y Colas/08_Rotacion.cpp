/*
Rotacion. Escribir una funcion void rotacion(queue <int> &C), la cual saca una cierta cantidad
de enteros del frente de la cola C y los vuelve a insertar en fin de la misma, de tal manera que
quede en el frente de cola un numero par. Por ejemplo, si C = [1, 3, 5, 2, 4] entonces, despues
de rotacion(C), debe quedar C = [2, 4, 1, 3, 5].
*/
#include <iostream>
#include <queue>
using namespace std;

void rotacion(queue <int> &C) {
	int C_size = C.size();
	int cont = 0;
	int esPar;
	
	while(cont<C_size) {
		esPar = C.front();
		if(esPar%2 == 0) {
			return;
		} else {
			C.push(C.front());
			C.pop();
			++cont;
		}
	}
}

int main() {
	queue<int> C;
	C.push(1);
	C.push(3);
	C.push(5);
	C.push(2);
	C.push(4);
	
	rotacion(C);
	
	while(!C.empty()) {
		cout<<C.front()<<" ";
		C.pop();
	}
	
	return 0;
}







