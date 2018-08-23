#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 112
#define MAX_S 1123

typedef struct _vec{
	int c, i;
}vec;

int cmp(const void *a, const void *b){
	vec w, x;
	w = *(vec*)a; x = *(vec*)b;
	if(w.i != x.i) return w.i - x.i;
	return x.c - w.c;
}

int main(void){
	char s[MAX_S];
	int i, len = 0, caso = 0;
	vec v[MAX];
	while(scanf(" %s", s) != EOF){
		if(caso++) printf("\n");
		len = (int)strlen(s);
		memset(v, 0, sizeof(v));
		for(i = 0; i < len; i++){
			v[s[i]-32].c = s[i];
			v[s[i]-32].i++;
		}
		qsort(v, MAX, sizeof(vec), &cmp);
		for(i = 0; i < MAX; i++)
			if(v[i].i)
				printf("%d %d\n", v[i].c, v[i].i);
	}
	return 0;
}