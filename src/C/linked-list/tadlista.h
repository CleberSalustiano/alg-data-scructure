#ifndef TADLISTA_H_
#define TADLISTA_H_

typedef void *tdata;

typedef struct tnode {
	tdata data;
	struct tnode *prev; 
	struct tnode *next;
} node;

typedef node *pnode;

typedef struct {
	int length;
	pnode first;
	pnode last;
} theader;

typedef theader *TList;

TList creatList();
TList appendList(TList lst, tdata data);
TList insertList(TList lst,int i, tdata data);
tdata removeList(TList lst,int i);
tdata infoList(TList lst,int i);
int lenList(TList lst);
tdata firstList(TList lst);
tdata lastList(TList lst);

int indexList(TList lst, tdata data);
TList clearList(TList lst);
TList clonaList(TList lst);

#endif 
