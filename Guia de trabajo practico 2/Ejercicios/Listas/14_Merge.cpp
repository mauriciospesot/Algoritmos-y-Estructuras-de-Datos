/*
Merge. Escribir una funcion void merge(list<int> &L1, list<int> &L2, list<int>& L) la
cual recibe dos listas ordenadas (que pueden ser de distinto tama~no) de forma ascendente L1 y L2
y retorna una lista L, pasada como parametro, con los elementos de ambas ordenados tambien en
forma ascendente. Por ejemplo si L1=[1, 3, 6, 11] y L2=[2, 4, 6, 10], la lista L debe quedar
como L=[1, 2, 3, 4, 6, 6, 10, 11].
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

int main() {
	list<int> L;
	list<int> L1 = { 1, 3, 6, 11 };
	list<int> L2 = { 2, 4, 6, 10 };
	
	merge(L1, L2, L);
	
	for(int x:L) cout<<x<<" ";
	return 0;
}







