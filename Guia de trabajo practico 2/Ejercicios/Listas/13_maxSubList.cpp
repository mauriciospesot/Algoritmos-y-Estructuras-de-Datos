/*
maxSubList. Programar una funcion list<int> max_sublist(list<int> &L) la cual reciba una
lista de enteros y encuentre y retorne la sublista Lmax que obtenga la mayor suma entre todos sus
elementos. Notar que debido a que algunos elementos pueden ser negativos el problema no se
resuelve simplemente tomando todos los elementos. Tambien es posible que la sublista resultado
no contenga ningun elemento, en el caso de que todos los elementos de L sean negativos. Si hay
varias sublistas que den la misma suma, debe retornar la que comience primero y sea mas corta.
Por ejemplo: [1,2,-5,4,-3,2]->[4], [5,-3,-5,1,7,-2]->[1,7], [4,-3,11,-2]->[4,-3,11].
*/

#include <iostream>
#include <list>
using namespace std;

list<int> max_sublist(list<int> &L) {
	list<int> subList;
	list<int>::iterator it_L = L.begin();
	list<int>::iterator it_L2 = L.begin();
	int sum = 0, max = 0;
	
	while(it_L != L.end()) {
		if(it_L2 != L.end()) {
			sum += *it_L2;
			if(sum>max) {
				max = sum;
				subList.clear();
				++it_L2;
				subList.insert(subList.begin(), it_L, it_L2);
			} else {
				++it_L2;
			}
		} else {
			++it_L;
			it_L2 = it_L;
			sum = 0;
		}
	}
	return subList;
}

int main() {
	list<int> L = {4,-3,11,-2};
	list<int> A = max_sublist(L);
	for(int x:A) cout<<x<<" ";
	return 0;
}







