#include <bits/stdc++.h>
using namespace std;

struct No{
  int v;
  No *l, *r;
  No(int _v) : v(_v), l(NULL), r(NULL) {}
};

No* insere(No *tree, int v){
  if(tree == NULL){
    No node(v);
    tree = (No*) malloc(sizeof(No));
    *tree = node;
    return tree;
  }
  if(v > tree->v) tree->r = insere(tree->r, v);
  else tree->l = insere(tree->l, v);
  return tree;
}

No* libera(No *tree){
  if(tree == NULL) return tree;
  libera(tree->l);
  libera(tree->r);
  free(tree);
  return NULL;
}

void pre(No *tree){
  if(tree == NULL) return;
  printf(" %d", tree->v);
  pre(tree->l);
  pre(tree->r);
}

void in(No *tree){
  if(tree == NULL) return;
  in(tree->l);
  printf(" %d", tree->v);
  in(tree->r);
}

void post(No *tree){
  if(tree == NULL) return;
  post(tree->l);
  post(tree->r);
  printf(" %d", tree->v);
}

int main(void){
  No *tree;
  int c, n;
  scanf("%d", &c);
  for(int i = 1; i <= c; i++){
    scanf("%d", &n);
    int x;
    tree = NULL;
    for(int j = 0; j < n; j++){
      scanf("%d", &x);
      tree = insere(tree, x);
    }
    printf("Case %d:\n", i);
    printf("Pre.:"); pre(tree); printf("\n");
    printf("In..:"); in(tree); printf("\n");
    printf("Post:"); post(tree); printf("\n\n");
    tree = libera(tree);
  }  
  return 0;
}
