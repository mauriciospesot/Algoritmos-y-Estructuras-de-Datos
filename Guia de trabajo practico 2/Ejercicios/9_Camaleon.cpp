/*
Camaleon. Implemente los predicados bool menor(int x, int y), bool mayor(int x, int y)
y bool dist(int x, int y) que retornen verdadero si x es menor, mayor o menor en valor
absoluto que y respectivamente. Luego implemente una funcion
ordena(list<int> &L, bool (*f)(int,int)) que ordene la lista L dependiendo de la funcion
f pasada como parametro.
*/

#include <iostream>
#include <list>
using namespace std;

bool menor(int x, int y) {
	return x<y;
}

bool mayor(int x, int y) {
	return x>y;
}

bool dist(int x, int y) {
	
	return abs(x)<abs(y);
}


void ordenar(list<int> &L, bool (*f)(int, int)) {
	list<int>::iterator it_L = L.begin();
	list<int>::iterator it_L2 = ++L.begin();
	
	while(it_L != L.end() && it_L2 != L.end()) {
		while(it_L2 != L.end()) {
			if(!f(*it_L, *it_L2)) swap(*it_L, *it_L2);
			++it_L2;
		}
		++it_L;
		it_L2 = it_L;
		++it_L2;
	}
}
int main() {
	list<int> L = { 1,2,3,-4,5,1,2,3,4,5,1,2,3,4,5 };
	
	ordenar(L,mayor);
	
	for(int x:L) {
		cout<< x << " ";
	}
	return 0;
}







