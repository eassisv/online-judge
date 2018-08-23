#include <stdio.h>
#include <string.h>

#define MAX 3123456
#define MAX_CAMP 2123123

int N, E;

void update(int v[], int i, int qtd){
	for(;i <= MAX_CAMP - 5; i += i & (-i)) v[i] += qtd;
}

int rsq(int v[], int i){
	int ans = 0;
	while(i){
		ans += v[i];
		i -= i & (-i);
	}
	return ans;
}

int main(){
	int pos_a[MAX_CAMP], pos_b[MAX_CAMP];
	int A[MAX], B[MAX];
	int i, j, gols_a, gols_b;
	int impedido;
	
	while(scanf("%d %d", &N, &E), N && E){
		memset(pos_a, 0, sizeof(pos_a));
		memset(pos_b, 0, sizeof(pos_b));
		for(i = 1; i <= N/2; i++){
			scanf("%d", &A[i]);
			update(pos_a, A[i] + 1, 1);
		}
		for(i = 1; i <= N/2; i++){
			scanf("%d", &B[i]);
			update(pos_a, B[i] + 1, 1);
		}
		gols_a = gols_b = impedido = 0;
		while(E--){
			char c;
			scanf(" %c", &c);
			if(c == 'I' || c == 'P'){
				scanf(" %c %d", &c, &i);
				if(c == 'A' && (rsq(pos_a, B[i] + 1) < (N/2 * 2/11))) impedido = 1;
				if(c == 'B' && ((rsq(pos_b, MAX_CAMP - 5) - rsq(pos_b, A[i] + 1)) < (N/2 * 2/11))) impedido = 1;
			}else
				if(c == 'M'){
					scanf(" %c %d %d", &c, &i, &j);
					if(c == 'A'){	update(pos_a, A[i] + 1, -1); update(pos_a, j + 1, 1); }
					else { update(pos_b, B[i] + 1, -1); update(pos_b, j + 1, 1); }
				}
				else
					if(c == 'G'){
						scanf(" %c", &c);
						if(!impedido) (c == 'A')? gols_b++: gols_a++;
					}
		}
	}

	return 0;
}
