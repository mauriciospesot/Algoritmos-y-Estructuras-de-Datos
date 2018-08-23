/*
Ascendente2. Escribir una funcion void ascendente2(list<int> &L, vector<list<int>> &VL)
que, dada una lista L, genera un vector de listas VL de tal forma de que cada sublista es ascendente.
*/

#include <iostream>
#include <list>
#include <vector>
using namespace std;

void ascendente2(list<int> &L, vector<list<int>> &VL) {
	list<int> A;
	list<int>::iterator it_L = L.begin();
	list<int>::iterator it_L2 = L.begin();
	vector<list<int>>::iterator it_VL = VL.begin();
	int num_anterior = *it_L;
	
	it_VL = VL.insert(VL.end(), A);
	
	it_VL->insert(it_VL->begin(), *it_L);
	++it_L;
	
	while(it_L != L.end()) {
		if(*it_L>num_anterior) {
			it_VL->insert(it_VL->end(), *it_L);
		}
		else {
			it_VL = VL.insert(VL.end(), A);
			it_VL->insert(it_VL->begin(), *it_L);
		}
		num_anterior = *it_L;
		++it_L;
	}
}

int main() {
	list<int> L = { 1,3,5,6,4,2,3,7,1,0,8,9,11 };
	vector<list<int>> VL;
	ascendente2(L, VL);
	vector<list<int>>::iterator it_VL = VL.begin();
	list<int>::iterator it_sublist = it_VL->begin();
	
	
	while(it_VL != VL.end()) {
		while(it_sublist != it_VL->end()) {
			cout<<*it_sublist<<" ";
			++it_sublist;
		}
		++it_VL;
		it_sublist = it_VL->begin();
		cout<<endl;
	}
	return 0;
}







