#include <stdlib.h>
#include "tadlista.h"

TList creatList() {
	TList c = (theader *)malloc(sizeof(theader));

	c->length = 0;
	c->first = NULL;
	c->last = NULL;

	return c;
}

TList appendLista(TList lst, tdata data) {
	pnode newnode = (node *)malloc(sizeof(node));

	newnode->data = data;
	newnode->prev = lst->last; 
	newnode->next = NULL;

	if(lst->tamanho == 0){
		lst->first = newnode;
		lst->last = newnode;
	} else {
		lst->last->next = newnode;
    lst->last = newnode;
	}

	lst->length++;

	return lst;
}

int lenList(TList lst) {
	return lst->length;
}

tdata firstList(TList lst) {
	return lst->first->data;
}

tdata lastList(TLista lst) {
	return lst->last->data;
}

TList insertList(TList lst,int i, tdata data) {
  int length = lenList(lst);

  if((i < 0) || (i > length)) return NULL;

  if(lenList(lst) == 0)
    appendList(lst,data);
  else
    if(i==length)
      appendList(lst,data);
    else {
        if(i == 0) {
          pnode newnode = (node *)malloc(sizeof(node));
          newnode->data = data;

          lst->first->prev = newnode;
          newnode->next = lst->first;
          newnode->prev = NULL;
          lst->first = newnode;
        } else {
          pnode newnode = (node *)malloc(sizeof(node));
          newnode->data = data;

          pnode findPositionNode = lst->next;
          int pos = 0;

          while(pos != (i - 1)){
            findPositionNode = findPositionNode->next;
            pos++;
          }
          newnode->next = findPositionNode->next;
          findPositionNode->next = newnode;
          newnode->prev = findPositionNode;
          findPositionNode = newnode->next;
          findPositionNode->prev = newnode;
        }

        lst->length++;
    }

  return lst;
}

tdata infoList(TList lst,int i) {
  int length = lenList(lst);

  if((length == 0) || (i < 0) || (i > length))
    return NULL;

  if(i == 0) return lst->first->data;

  else if(i == length - 1 ) return lst->last->data;
  else if (i < ((length-1)/2) && i >= 0){
    pnode findPositionNode = lst->first;
    int position = 0;

    while(position != i){
      findPositionNode = findPositionNode->next;
      position++;
    }

    return findPositionNode->data;
  }else{
    pnode findPositionNode = lst->last;
    int position = length - 1;

    while(position != i){
      findPositionNode = findPositionNode->prev;
      position--;
    }
    return findPositionNode->data;

  }
}

tdata removeList(TList lst,int i){
  int length = lenList(lst);

  if((i < 0) || (i > length) || (length == 0)) return NULL;

  if(length == 1) { 
     pnode findPositionNode = lst->next;
     lst->next = NULL;
     lst->last = NULL;
     lst->length--;

     tdata d =findPositionNode->data;
     free(findPositionNode);

     return d;
  } else { 
	 if(i == 0){
	   pnode findPositionNode = lst->first;
	   lst->first = findPositionNode->next;
     lst->next->prev = NULL; 
	   lst->length--;

	   tdata d =findPositionNode->data;
	   free(findPositionNode);

	   return d;
	 } else {
	   if(i == length - 1) {
		 pnode aux = lst->last;

		 pnode pnult = lst->last->prev;
		 
		 pnult->next = NULL;
		 lst->last = pnult;

		 lst->length--;

	     tdado d =findPositionNode->dado;
	     free(findPositionNode);

	     return d;
	   } else {
		 pnode prev = lst->first;
		 int position = 0;

		 while(position != i-1){
			 prev = prev->next;
			 pos++;
		 }

		 pnode findPositionNode = prev->next;
		 prev->next = findPositionNode->next;
     prev->next->prev = prev;
		 lst->tamanho--;

		 tdata d = findPositionNode->data;
		 free(findPositionNode);

		 return d;
	   } 
	 } 
  } 
} 

int indexList(TList lst, tdata data){
  int length = lenList(lst);
  int i;
  tdata lstData;

  if(length == 0) return -1;

  i = 0;
  lstData = infoList(lst,i);
  while((i < length) && (data != lstData)){
	  i++;
  	  lstData = infoList(lst,i);
  }

  if(i < length) return i;
  else return -1;
} 

TList clearList(TList lst){
  int length = lenList(lst);

  if(length == 0) return lst;

  while(lenList(lst) > 0)
	  removeList(lst,0);

  return lst;
} 

TList clonaList(TList lst){
  TList clone = creatList();
  int length = lenList(lst);

  if(length == 0) return clone;

  for(int i=0;i < length; i++)
	 appendList(clone,infoList(lst,i));

  return clone;
}