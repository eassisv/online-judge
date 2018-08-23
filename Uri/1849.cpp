#include <stdio.h>

int min(int x, int y){
	return (x < y)? x: y;
}

int max(int x, int y){
	return (x > y)? x: y;
}

int main(void){
	int ld, cd, lv, cv, l;

	scanf("%d %d %d %d", &ld, &cd, &lv, &cv);
	l = min(max(ld, cd), max(lv, cv));
	l = min(l, min(ld, cd) + min(lv, cv));
	printf("%d\n", l*l);

	return 0;
}
