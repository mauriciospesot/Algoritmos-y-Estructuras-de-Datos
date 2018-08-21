/*
Invierte. Escribir una funcion void invert(list<int> &L), que invierte el orden de la lista L.
Este algoritmo debe implementarse in place y debe ser O(n). Restriccion: no utilizar el metodo size().
*/

#include <iostream>
#include <list>
using namespace std;

void invert(list<int> &L) {
	list<int>::iterator it_L = L.begin();
	list<int>::iterator it_L2 = L.end();
	--it_L2;
	
	while(it_L != it_L2) {
		swap(*it_L, *it_L2);
		++it_L;
		if(it_L == it_L2) {
			break;
		}
		--it_L2;
		
	}
	
}

int main() {
	list<int> L = { 2,5,4,7,9 };
	
	invert(L);
	
	for(int x:L) {
		cout<< x << " ";
	}
	return 0;
}







