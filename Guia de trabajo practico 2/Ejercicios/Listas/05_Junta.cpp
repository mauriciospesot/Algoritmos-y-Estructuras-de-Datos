/*
#include <list>
using namespace std;
Junta. Escribir una funcion void junta(list<int> &L, int c) que, dada una lista L, agrupa de
a c elementos, dejando su suma in place. Por ejemplo, si se le pasa como argumento la lista
L=(1,3,2,4,5,2,2,3,5,7,4,3,2,2), despues de aplicar el algoritmo junta(L,3) debe quedar
L=(6,11,10,14,4) (notar que se agrupan los ultimos elementos, pese a no completar los tres
requeridos). El algoritmo debe tener un tiempo de ejecucion O(n).
*/

#include <iostream>
#include <list>
using namespace std;

void juntar(list<int> &L, int c) {
	list<int>::iterator it_L = L.begin();
	list<int>::iterator it_L2 = it_L;
	int sum = 0;
	
	while(it_L != L.end()) {
		for(int i=0; i<c; ++i) {
			if(it_L2 == L.end()) break;
			sum = sum + *it_L2;
			++it_L2;
		}
		it_L = L.erase(it_L, it_L2);
		it_L = L.insert(it_L, sum);
		++it_L;
		it_L2 = it_L;
		sum = 0;
	}
	
}

int main() {
	list<int> L = { 1,2,3,4,5,1,2,3,4,5,1,2,3,4,5 };
	
	juntar(L, 3);
	
	for(int x:L) cout<<x<<" ";
	return 0;
}







