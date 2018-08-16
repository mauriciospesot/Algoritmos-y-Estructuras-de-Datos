/*
Concatena. Escriba procedimientos para concatenar: a) dos listas L1 y L2 usando insert; b) una
lista LL de n sublistas usando insert; c) una lista LL de n sublistas usando splice.
*/

#include <iostream>
#include <list>
using namespace std;

void concatenar(list<int> &L, list<int> L2) {
	list<int>::iterator it = L.end();
	L.insert(it, L2.begin(), L2.end());
}

void concatenarSublistas(list<int> &L, list<list<int>> LL) {
	list<list<int>>::iterator it_LL = LL.begin();
	list<int>::iterator it_L;
	
	while (it_LL != LL.end()) {
		it_L = L.end();
		L.insert(it_L, (*it_LL).begin(), (*it_LL).end());
		++it_LL;
	}
}

void concatenarSplice(list<int> &L, list<list<int>> LL) {
	list<list<int>>::iterator it_LL = LL.begin();
	list<int>::iterator it_L;
	
	while (it_LL != LL.end()) {
		it_L = L.end();
		L.splice(it_L, L, (*it_LL).begin(), (*it_LL).end());
		++it_LL;
	}
}


int main() {
	list<int> L = { 2,5,4,7 };
	list<int> L2 = { 3,4,2,1 };
	list<list<int>> LL = {
		{ 1,2,3 },
		{ 4,5,6 },
		{ 7,8,9 }
	};
	
	//a)
	///concatenar(L, L2);
	//b)
	///concatenarSublistas(L, LL);
	//c)
	///concatenarSplice(L, LL);

	
	for(int x:L) {
		cout<< x << " ";
	}

	
	return 0;
}







