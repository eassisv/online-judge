#include <stdio.h>
#include <string.h>
#include <deque>

using namespace std;

#define MAX 51
#define LETRA (c >='A'&&c <='Z') || (c >='a'&&c <='z')

int main(void){
	char s, c;
	deque<char> w;
	int cont = 0, p = 0, i, media;
	while(scanf("%c", &s) != EOF){
		if(s != ' ' && s != '\n')
			w.push_back(s);
		else{
			if(w.back() == '.')
				w.pop_back();
			i = 0;
			while(!w.empty()){
				c = w.front();
				w.pop_front();
				if(LETRA){
					i++;
				}else{
					i = 0;
					w.clear();
					break;
				}
			}
			cont += i;
			p += (i != 0);
			if(s == '\n'){
				if(p){
					media = cont / p;
					if(media < 4) printf("250\n");
					else if(media < 6) printf("500\n");
					else printf("1000\n");
				}else
					printf("250\n");
				p = 0; cont = 0;
			}}}
	return 0;
}

