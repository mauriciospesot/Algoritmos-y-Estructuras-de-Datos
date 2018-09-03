/*
SortQueue. Escribir una funcion void sort(list<int> &L), que ordena los elementos de L de
menor a mayor. Para ello utilizar el siguiente algoritmo simple, utilizando una cola auxiliar C: ir
tomando el menor elemento de L, eliminarlo de L e insertarlo en C hasta que L este vacia. Luego
insertar los elementos de C en L.
*/

#include <iostream>
#include <list>
#include <queue>
using namespace std;

void eliminar_minimo(list<int> &L, queue<int> &C) {
	list<int>::iterator it_L = L.begin();
	list<int>::iterator indice;
	int min = *it_L;
	indice = it_L;
	
	
	while(it_L != L.end()) {
		if(*it_L<min) {
			min = *it_L;
			indice = it_L;
		}
		++it_L;
	}
	
	C.push(*indice);
	L.erase(indice);
}

void sort(list<int> &L) {
	queue<int> C;
	
	while(!L.empty()) {
		eliminar_minimo(L, C);
	}
	
	while(!C.empty()) {
		L.push_back(C.front());
		C.pop();
	}
}


int main() {
	list<int> L = {2,4,1,6,5,8,7,6,5};
	sort(L);
	
	for(int x:L) cout<<x<<" ";
	
	return 0;
}







