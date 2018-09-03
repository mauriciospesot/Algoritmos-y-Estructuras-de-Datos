/*
SortStack. Escribir una funcion void sort(list<int> &L), que ordena los elementos de L de
mayor a menor. Para ello emplear el siguiente algoritmo simple, utilizando una pila auxiliar P: ir
tomando el menor elemento de L, eliminarlo de L e insertarlo en P hasta que L este vacia. Luego
insertar los elementos de P en L.
*/

#include <iostream>
#include <list>
#include <stack>
using namespace std;

void eliminar_minimo(list<int> &L, stack<int> &P) {
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
	
	P.push(*indice);
	L.erase(indice);
}

void sort(list<int> &L) {
	stack<int> P;
	
	while(!L.empty()) {
		eliminar_minimo(L, P);
	}
	
	while(!P.empty()) {
		L.push_back(P.top());
		P.pop();
	}
}
	

int main() {
	list<int> L = {2,4,1,6,5,8,7,6,5};
	sort(L);
	
	for(int x:L) cout<<x<<" ";
	
	return 0;
}







