#include <bits/stdc++.h>
using namespace std;

#define MAX 112

void make_tree(char *btree, char c){
  for(int i = 0; i < MAX;){
    if(!btree[i]){
      btree[i] = c;
      break;
    }
    else{
      if(c > btree[i]) i = i*2+2;
      else i = i*2+1;
    }
  }
}

void posfixa(char *btree, int i){
  if(!btree[i]) return;
  posfixa(btree, i*2+1);
  posfixa(btree, i*2+2);
  cout << btree[i];
}

int main(void){
  char s[MAX], btree[MAX];
  memset(btree, 0, sizeof(btree));
  while(fgets(s, MAX, stdin) != NULL){
    for(int i = 0; s[i] != ' '; i++){
      make_tree(btree, s[i]);
    }
    for(int i = 0; i < MAX; i++)
      if(btree[i])
	cout << btree[i] << endl;
    posfixa(btree, 0);
    printf("\n");
    memset(btree, 0, sizeof(btree));
  }  
  return 0;
}
