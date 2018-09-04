// GITVERSION: tpl1-recup-2015-32-gd022f91
#include "eval.hpp"
#include <climits>
#include <cstdlib>
#include <stack>

using namespace aed;
using namespace std;

// Retorna true si L1 es prefijo de L2
bool isprefix(list<int> &L1, list<int> &L2) {
	list<int>::iterator it_L2 = L2.begin();
	list<int>::iterator it_L1 = L1.begin();
	
	while(it_L2 != L2.end() && it_L1 != L1.end()) {
		if(*it_L2 != *it_L1) {
			return false;
		} else {
			++it_L1;
			++it_L2;
		}
	}
	L2.erase(L2.begin(), it_L2);
	return true;
}

// Retorna true si L es una combinacion de los VL
bool iscomb(vector< list<int> > &VL, list<int> &L) {
	if(VL.empty() && L.empty()) return true;
	if(VL.empty() || L.empty()) return false;
	vector<list<int>>::iterator it_VL = VL.begin();
	unsigned sum = 0, VL_size = VL.size();
	
	for(unsigned i=0;i<VL.size();i++) { 
		sum += VL[i].size();
	}
	
	if(sum != L.size()) return false;
	
	for(unsigned i=0;i<VL_size;i++) { 
		if(!isprefix(VL[i], L)) continue;
		
		VL.erase(VL.begin()+i);
		
		list<int>::iterator it_L = L.begin();
		int del_L_element = VL[i].size();
		
		for(int i=0;i<del_L_element;i++) { 
			L.erase(L.begin());
		}
		if(iscomb(VL, L)) return true;
	}
	return false;
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
// Retorna la sublista contigua cuya suma es maxima
list<int> max_sublist(list<int> &L){
	list<int> subList;
	list<int>::iterator it_L = L.begin();
	list<int>::iterator it_L2 = L.begin();
	int sum = 0, max = 0;
	
	while(it_L != L.end()) {
		while(it_L2 != L.end()) {
			sum += *it_L2;
			++it_L2;
			if(sum>max) {
				subList.clear();
				subList.insert(subList.begin(), it_L, it_L2);
				max = sum;
			}
		}
		it_L2 = ++it_L;
		sum = 0;
	}
	return subList;    
}

// Fusiona dos listas ordenadas L1,L2 en L
void merge(list<int> &L1, list<int> &L2, list<int>& L){
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
	if(it_L2 == L2.end()) L.insert(L.end(),it_L1, L1.end());
}

// Ordena una lista L por fusión recursiva
void mergesort(list<int>&L){
	if(L.size()<=1) {
		return;
	} else {
		list<int> L1, L2;
		list<int>::iterator it_L = L.begin();
		for(unsigned i=0;i<L.size()/2;i++) ++it_L;
		L1.splice(L1.begin(), L, L.begin(), it_L);
		L2.splice(L2.begin(), L, L.begin(), L.end());
	  
		mergesort(L1);
		mergesort(L2);
		merge(L1, L2, L);
	}
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs = 0;

  ev.eval1(iscomb,vrbs);
  ev.eval2(max_sublist,vrbs);
  ev.eval3(mergesort,vrbs);
  return 0;
}
