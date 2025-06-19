#include <stdio.h>

int g(int p){
	printf("%d\n", p); return p;
}

int h(int q){
	printf("%d\n", q); return q;
}

void f(int x, int y){
	g(x);
	h(y);
}

int main(){
	f(g(10), h(20));
}