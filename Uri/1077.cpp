#include <stdio.h>

#define MAX 312
#define NORL (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')
#define OPERADOR c == '+' || c == '-' || c == '*' || c == '/' || c == '^'

int N;
char exp[MAX];

int priority(char c, char t){
	int pc = 0, pt = 0;
	if(c == '-' || c == '+') pc = 1;
	else if(c == '*' || c == '/') pc = 2;
	else if(c == '^') pc = 3;
	else if(c == '(') pc = 4;
	if(t == '-' || t == '+') pt = 1;
	else if(t == '*' || t == '/') pt = 2;
	else if(t == '^') pt = 3;
	else if(t == '(') pt = 0;
	return (pc > pt);
}

void in2pos(){
	int i = 0, topo = 0;
	char c, pilha[MAX];
	while(exp[i] != '\0'){
		c = exp[i++];
		if(NORL) printf("%c", c);
		else if(c == '(') pilha[topo++] = c;
		else if(c == ')'){
			while(pilha[--topo] != '('){
				printf("%c", pilha[topo]);
			}
		}else if(OPERADOR){
			if(topo)
				while(!priority(c, pilha[topo-1])){
					printf("%c", pilha[--topo]);
				}
			pilha[topo++] = c;
		}
  }
	while(topo){
		printf("%c", pilha[--topo]);
	}
	printf("\n");
}

int main(void){
	scanf("%d ", &N);
	while(N--){
		scanf(" %s", exp);
		in2pos();
	}
	return 0;
}
