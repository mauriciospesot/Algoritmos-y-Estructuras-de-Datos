/*
ReemplazaSecuencia. Dada una lista de enteros L y dos listas SEQ y REEMP, posiblemente de
distintas longitudes, escribir una funcion void reemplaza(list<int> &L, list<int>& SEQ,
list<int> &REEMP), que busca todas las secuencias de SEQ en L y las reemplaza por REEMP. Por
ejemplo, si L=(1,2,3,4,5,1,2,3,4,5,1,2,3,4,5), SEQ=(4,5,1) y REEMP=(9,7,3), entonces
despues de llamar a reemplaza(L,SEQ,REEMP), debe quedar
L=(1,2,3,9,7,3,2,3,9,7,3,2,3,4,5). Para implementar este algoritmo primero buscar desde el
principio la secuencia SEQ, al encontrarla, reemplazar por REEMP, luego seguir buscando a partir
del siguiente elemento al ultimo de REEMP.
*/
#include <iostream>
#include <list>
using namespace std;

void reemplazarSecuencia(list<int> &L, list<int> SEQ, list<int> REEMP) {
	list<int>::iterator it_L = L.begin();
	list<int>::iterator it_auxL = it_L;
	list<int>::iterator it_SEQ = SEQ.begin();
	
	while(it_L != L.end()) {
		while(*it_auxL == *it_SEQ && it_auxL != L.end()) {
			++it_auxL;
			++it_SEQ;
		}
		if(it_SEQ == SEQ.end()) {
			it_L = L.erase(it_L, it_auxL);
			it_L = L.insert(it_L, REEMP.begin(), REEMP.end());
			advance(it_L, REEMP.size());
			it_SEQ = SEQ.begin();
		}else {
			++it_L;
			it_auxL = it_L;
			it_SEQ = SEQ.begin();
		}
	}
}

int main() {
	list<int> L = { 1,2,3,4,5,1,2,3,4,5,1,2,3,4,5 };
	list<int> SEQ = { 4,5,1 };
	list<int> REEMP = { 9,7,3 };
	reemplazarSecuencia(L, SEQ, REEMP);
	
	for(int x:L) {
		cout<< x << " ";
	}
	return 0;
}



