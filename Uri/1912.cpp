#include <stdio.h>
#include <math.h>

#define MAX 112345
#define EPS 1e-4

int N, A;
double tira[MAX];

double area(double corte){
	int i;
	double soma = 0;
	for(i = 0; i < N; i++)
		soma += (tira[i] - corte > 0) ? tira[i] - corte: 0;
	return soma;
}

double bbin(double fim){
	int i = 0;
	double m, a, ini = 0;
	while(i++ < 80){
		m = (ini + fim)/ 2; a = area(m);
		if(a > A) ini = m;
		else if (a < A) fim = m;
	}
	return (fabs(area(m) - A) < EPS) ? m : -1;
}

int main(void){
	int i;
	double m, ans;

	while(scanf("%d %d", &N, &A), N){
		m = 0;
		for(i = 0; i < N; i++){
			scanf("%lf", &tira[i]);
			if(m < tira[i])
				m = tira[i];
		}
		ans = bbin(m);
		if(fabs(ans) < EPS) printf(":D\n");
		else if(ans > 0) printf("%.4lf\n", ans);
		else printf("-.-\n");
	}
	return 0;
}
