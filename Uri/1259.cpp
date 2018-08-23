#include<stdio.h>
#include<stdlib.h>

int Vp[112345], Vi[112345];

int cmp(const void *a, const void *b){
	return *(int *) a - *(int *) b;	
}

int main(void){
	int i, N, num, indi, indp;
	scanf("%d", &N);
	indi = indp = 0;
	for (i = 0; i < N; i++){
		scanf("%d", &num);
		if (num % 2 == 0) Vp[indp++] = num;
		else Vi[indi++] = num;
	}
	qsort(Vp, indp, sizeof(int), &cmp);
	qsort(Vi, indi, sizeof(int), &cmp);
	for(i = 0; i < indp; i++) printf("%d\n", Vp[i]);
	for(i = indi - 1; i >= 0; i--) printf("%d\n", Vi[i]);
	return 0;
}
