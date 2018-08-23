#include<stdio.h>
#include<stdlib.h>

int po[11234];

int cmp(const void *a, const void *b){
	//int x;
	
	//x
	return -(*(int *) a - *(int *) b);
	/*if(x > 0) return -1;
	else if(x < 0) return 1;
	else return 0;*/
}

int main(void){
	int N, M, i, p[11234], x;
		
	scanf("%d", &N);
	while(N--){
		scanf("%d", &M);
		for (i = 0; i < M; i++) {scanf("%d", &p[i]); po[i] = p[i];}
		qsort(po, M, sizeof(int), &cmp);
		x = 0;					
		for (i = 0; i < M; i++)
			if(p[i] == po[i]) x++;
		printf("%d\n", x);
		
	}	
	return 0;
}
