#include <stdio.h>

int main(void){
	int n, k, m, i, j;
	int hr, ant, v[21];
	scanf("%d %d %d", &n, &k, &m);
	while(n || k || m){
		for(i = 0; i <= n; i++) v[i] = 1;
		hr = 0; ant = 0;
		j = 0;
		while(j < n){
			for(i = 0; i < k; i++){
				if(hr >= n) hr = 1;
				else hr++;
				if(!v[hr])
					while(!v[hr]){
						if(hr < n) hr++;
						else hr = 1;
					}
			}	
			for(i = 0; i < m; i++){
				if(ant <= 1) ant = n;
				else ant--;
				if(!v[ant])
					while(!v[ant]){
						if(ant > 1) ant--;
						else ant = n;
					}
			}
			if(hr == ant){
				printf("%3d", hr);
				v[hr] = 0; j++;
				if(j < n) printf(",");
			}
			else{
				printf("%3d%3d", hr, ant);
				v[hr] = v[ant] = 0;
				j+=2;
				if(j < n) printf(",");
			}
		}
		printf("\n");
		scanf("%d %d %d", &n, &k, &m);
	}
	return 0;
}
