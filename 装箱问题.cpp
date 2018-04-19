#include<stdio.h>
#include<stdlib.h>
#define V 40
#define N 5

typedef struct{
	int gno;
	int gv;
}Goods;
typedef struct gnode{
	int gno;
	struct gnode *next;
}GNode;
typedef struct bnode{
	int restV;
	GNode *hg;
	struct bnode *next;
}BNode;


Goods *createG(){
	Goods *g = (Goods *)malloc(N*sizeof(Goods));
	for(int i=0;i<N;i++){
		g[i].gno=i;
		scanf("%d",&g[i].gv);
	}
	return g;
}

BNode *createB(){
	BNode *b = (BNode *)malloc(sizeof(BNode));
	b->hg=NULL;
	b->next=NULL;
	b->restV=V;
	return b;
	
}

BNode *Box(Goods *g){
	BNode *B=NULL;
	int i;
	BNode *b;
	BNode *P = B;
//	B=b;
//	b->restV-=g[i].gv;
//	b->hg = (GNode *)malloc(sizeof(GNode));
//	b->hg->gno=g[i].gno;
//	b->hg->next=NULL;
//	b->next=NULL;
	for(i=0;i<N;i++){
//	 	if(B==NULL){
//	 		B=createB();
//	 	}
		for(b=B;b!=NULL&&b->restV<g[i].gv;b=b->next);
		if(b==NULL){
			b=createB();
			P=P->next=b;
		}
		for(GNode *t=b->hg;t!=NULL&&t->next!=NULL;t=t->next);
		
// 			if(g[i].gv<=b->restV){
// 				GNode *node = (GNode *)malloc(sizeof(GNode));
//	 			node->gno=g[i].gno;
//				node->next=b->hg->next;
//				b->hg->next=node;
//	 		
//	 		}
//			else
//	 			b=b->next; 
		} 
	 
	 	
	}
	return B;
}

void print(BNode *B){
	while(B){
		GNode *node = B->hg;
		while(node){
			printf("%d	",B->hg->gno);
			node=node->next;
		}
		printf("\n");
		B=B->next;
	}
}

int main(void){
	Goods *G = createG();
	BNode *B = Box(G);
	print(B);
	return 0;
}
