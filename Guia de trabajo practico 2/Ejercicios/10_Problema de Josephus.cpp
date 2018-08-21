/*
Problema de Josephus. Un grupo de soldados se haya rodeado por una fuerza enemiga. No hay
esperanzas de victoria si no llegan refuerzos y existe solamente un caballo disponible para el
escape. Los soldados se ponen de acuerdo en un pacto para determinar cual de ellos debe escapar y
solicitar ayuda. Forman un circulo y se escoge un numero n al azar. Igualmente se escoge el
nombre de un soldado. Comenzando por el soldado cuyo nombre se ha seleccionado, comienzan a
contar en la direccion del reloj alrededor del circulo. Cuando la cuenta alcanza el valor n, este
soldado es retirado del circulo y la cuenta comienza de nuevo, con el soldado siguiente. El proceso
continua de tal manera que cada vez que se llega al valor de n se retira un soldado. El ultimo
soldado que queda es el que debe tomar el caballo y escapar. Entonces, dados un numero n y una
lista de nombres, que es el ordenamiento en el sentido de las agujas del reloj de los soldados en el
circulo (comenzando por aquel a partir del cual se inicia la cuenta), escribir un procedimiento
list<string> josephus(list<string>& nombres, int n) que retorna una lista con los
nombres de los soldados en el orden que han de ser eliminados y en ultimo lugar el nombre del
soldado que escapa.
*/

#include <iostream>
#include <cstdlib>
#include <list>
#include <ctime>
using namespace std;

int main() {
	list<string> L = { "Davidson", "Kenney", "Fellers", "Brooks", "Franks", "Upham", "Diaz", "Caparzo", "Ryan", "Miller" };
	list<string>::iterator it_L = L.begin();
	srand(time(NULL));
	int random;
	for(string x:L) cout<<x<<" ";
	cout<<endl;
	
	while(L.size() != 1) {
		random = 1+rand()%(11-1);
		cout<<"Numero aleatorio: "<<random<<endl;
		for(int i=0; i<random; ++i) {
			if(it_L != L.end()) {
				++it_L;
				if(it_L == L.end()) it_L = L.begin();
			}
		}
		cout<<"Se retira: "<<*it_L<<endl;
		it_L = L.erase(it_L);
		if(it_L == L.end()) it_L = L.begin();
		cout<<"Se empieza por: "<<*it_L<<endl;
		for(string x:L) cout<<x<<" ";
		cout<<endl;
	}
	
	cout<<"El soldado que escapa es: "<<*it_L;
	return 0;
}







