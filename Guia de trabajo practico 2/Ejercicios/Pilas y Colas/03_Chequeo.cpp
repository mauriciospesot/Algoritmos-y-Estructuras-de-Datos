/*
Chequeo. Escribir un segmento de programa que lea expresiones aritmeticas del estilo:
((a - b)*(5 - c))/4 y verique si los parentesis estan embebidos correctamente. Es decir,
debemos vericar si: a) Existe igual numero de parentesis a izquierda y derecha; b) Cada
parentesis de la derecha esta precedido de su correspondiente parentesis a la izquierda.
*/
#include <iostream>
#include <stack>
using namespace std;
bool chequear(stack<char>& c) {
	stack<char> aux = c;
	char parentesis_open = 0, parentesis_close = 0;
	
	while(!aux.empty()) {
		if(aux.top() == '(') parentesis_open += 1;
		if(aux.top() == ')') parentesis_close += 1;
		aux.pop();
	}
	
	if(parentesis_open == parentesis_close) return true;
	
	return false;
}
int main() {
	stack<char> c;
	c.push('(');
	c.push('(');
	c.push('a');
	c.push('-');
	c.push('b');
	c.push(')');
	c.push('*');
	c.push('(');
	c.push('-');
	c.push('c');
	c.push(')');
	c.push(')');
	c.push('/');
	c.push('4');
	
	if(chequear(c)) return true;
	else return false;
	
	return 0;
}







