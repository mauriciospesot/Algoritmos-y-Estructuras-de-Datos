/*
1) BasicSort. Escribir una funcion void basic_sort(list<int> &L), que ordena los elementos de L
de menor a mayor. Para ello emplear el siguiente algoritmo simple: utilizando una lista auxiliar L2,
tomar el menor elemento de L, eliminarlo de L e insertarlo al final de L2 hasta que L este vacia.
Luego insertar los elementos de L2 en L.
*/

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

void basic_sort(list<int> &L) {
	list<int> L2;
	list<int>::iterator it_min;
	
	while(!L.empty()) {
		it_min = min_element(L.begin(), L.end());
		L2.push_back(*it_min);
		L.erase(it_min);
	}
	swap(L,L2); //L apunta a L2 y L2 a L
}

int main() {
	list<int> L = { 2,5,4,6,7,3,2,6,4,3,1 };
	
	for(int x:L) {
		cout<< x << " ";
	}
	
	cout << endl;
	
	basic_sort(L);
	
	for(int x:L) {
		cout<< x << " ";
	}
	return 0;
}







