/*
2) SelectionSort. Escribir una funcion void selection_sort(list<int> &L), que ordena los
elementos de L de menor a mayor. Para ello debe tomarse el menor elemento de L e intercambiarlo
(swap) con el primer elemento de la lista. Luego intercambiar el menor elemento de la lista
restante, con el segundo elemento, y asi sucesivamente. Esta funcion debe ser IN PLACE.
*/
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

void selection_sort(list<int> &L) {
	list<int>::iterator it = L.begin();
	list<int>::iterator it_min = min_element(L.begin(), L.end());
	
	while (it != L.end()) {
		swap(*it, *it_min);
		it++;
		it_min = min_element(it, L.end());
	}
	
}

int main() {
	list<int> L = { 2,5,4,6,7,3,2,6,4,3,1 };
	for(int x:L) {
		cout<< x << " ";
	}
	
	cout << endl;
	
	selection_sort(L);
	
	for(int x:L) {
		cout<< x << " ";
	}
	return 0;
}







