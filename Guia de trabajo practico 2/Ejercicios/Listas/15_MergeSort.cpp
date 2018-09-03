/*
MergeSort. Programar una funcion void mergesort(list<int> &L) que reciba una lista L
desordenada y la ordene en forma ascendente mediante la siguiente estrategia recursiva: Si la lista
esta vacia o tiene un solo elemento ya esta ordenada. Sino se parte la lista en dos sublistas y se las
ordena a cada una de forma recursiva. Luego se mezclan (fusionan) cada una de las sublistas ya
ordenadas. Para partir una lista puede utilizarse el metodo de la clase list
void list::splice (iterator position, list& x, iterator first, iterator last) el
cual transfiere los elementos desde la lista x al contenedor que realiza la llamada en la posicion
position. Se sugiere utilizar la funcion merge(..) implementada en el punto anterior.
*/

#include <iostream>
#include <list>
using namespace std;

void merge(list<int> &L1, list<int> &L2, list<int>& L) {
	list<int>::iterator it_L1 = L1.begin();
	list<int>::iterator it_L2 = L2.begin();
	
	while(it_L1 != L1.end() && it_L2 != L2.end()) {
		if(*it_L1<=*it_L2) {
			L.push_back(*it_L1);
			++it_L1;
		} else {
			L.push_back(*it_L2);
			++it_L2;
		}
	}
	if(it_L1 == L1.end()) L.insert(L.end(),it_L2, L2.end());
	else {
		if(it_L2 == L2.end()) L.insert(L.end(),it_L1, L1.end());
	}
}

void mergesort(list<int> &L) {
	list<int> L1, L2;
	list<int>::iterator it_L = L.begin();
	advance(it_L, L.size()/2);
	
	if(L.size()<2) return;
	
	L1.splice(L1.begin(), L, L.begin(), it_L);
	L2.splice(L2.begin(), L, it_L, L.end());
	
	mergesort(L1); mergesort(L2);
	
	merge(L1, L2, L);
}

int main() {
	list<int> L = { 2,1,3,6,4,8,6,7,9,15,11,16,5 };
	
	mergesort(L);
	
	for(int x:L) cout<<x<<" ";
	
	return 0;
}







