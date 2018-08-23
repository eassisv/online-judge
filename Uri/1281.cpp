#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;

int n, m;
double p, ans;

int main(void){
	string s;
	int i, q;
	cin >> n;
	map < string , double > mapa;
	while(n--){
		cin >> m;
		for(i = 0; i < m; i++){
			cin >> s >> p;
			mapa[s] = p;		
		}
		cin >> m;
		ans = 0.00;
		for(i = 0; i < m; i++){
			cin >> s >> q;
			ans += mapa[s] * q;
		}
		printf("R$ %.2lf\n", ans - 0.00499999);
		mapa.clear();
	}
	return 0;
}