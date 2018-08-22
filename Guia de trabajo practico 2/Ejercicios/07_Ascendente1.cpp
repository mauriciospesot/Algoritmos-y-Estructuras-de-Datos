/*
Ascendente1. Escribir una funcion void ascendente1(list<int> &L, list<list<int>> &LL)
que, dada una lista L, genera una lista de listas LL de tal forma de que cada sublista es ascendente.
*/

#include <iostream>
#include <list>
using namespace std;

void ascendente1(list<int> &L, list<list<int>> &LL) {
	list<int> A;
	list<int>::iterator it_L = L.begin();
	list<int>::iterator it_L2 = L.begin();
	list<list<int>>::iterator it_LL = LL.begin();
	int menor = *it_L;
	
	it_LL = LL.insert(LL.end(), A);
	
	it_LL->insert(it_LL->begin(), *it_L);
	++it_L;
	
	while(it_L != L.end()) {
		if(*it_L>menor) {
			it_LL->insert(it_LL->end(), *it_L);
		}
		else {
			it_LL = LL.insert(LL.end(), A);
			it_LL->insert(it_LL->begin(), *it_L);
		}
		menor = *it_L;
		++it_L;
	}
}

int main() {
	list<int> L = { 1,3,5,6,4,2,3,7,1,0,8,9,11 };
	list<list<int>> LL;
	ascendente1(L, LL);
	list<list<int>>::iterator it_LL = LL.begin();
	list<int>::iterator it_sublist = it_LL->begin();
	
	
	while(it_LL != LL.end()) {
		while(it_sublist != it_LL->end()) {
			cout<<*it_sublist<<" ";
			++it_sublist;
		}
		++it_LL;
		it_sublist = it_LL->begin();
		cout<<endl;
	}
	
	return 0;
}







