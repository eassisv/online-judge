#include <cstdio>
#include <cstring>
using namespace std;

void compact(int n, char c){
	if(!n) return;
	if(n < 3) if(n & 1) printf("%c", c); else printf("%c%c", c, c);
	else{
		char k = c == '0' ? '#' : '$';
		do{
			if(n > 255) { printf("%c%c", k, 255); n -= 255; }
			else { printf("%c%c", k, n); n = 0; }
		}while(n);
	}
}

int main(void){
	int N;
	char s[2123];
	scanf("%d ", &N);
	while(N--){
		char c, last;
		int nuls = 0, t;
		memset(s, 0, sizeof(s));
		fgets(s, 2123, stdin);
		t = strlen(s);
		for(int i = 0; i < t - 1; i++){
			c = s[i];
			if(c != '0' && c != ' '){
				compact(nuls, last);
				nuls = 0;
				printf("%c", c);
			}else{
				if(!nuls){ last = c; nuls++; }
				else{
					if(last == c) nuls++;
					else{
						compact(nuls, last);
						last = c;
						nuls = 1;
					}
				}
			}		
		}
		printf("\n");
	}
	return 0;
}
