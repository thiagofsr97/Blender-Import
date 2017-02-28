#include "lkcoords.h"
#include <stdlib.h>
#include <stdio.h>



/*Creating a new List*/
void LKC_NewList (tLK_Coords *list){
  list->Head = NULL;
  list->Size = 0;

}

/*Checking if list is empty*/
int LKC_IsEmpty (tLK_Coords list){
  return ((list.Size == 0)? TRUE : FALSE);
}

/*Returns the size of a list*/
int LKC_Size (tLK_Coords list){
  return list.Size;
}


int LKC_GetItem (tLK_Coords list, int pos, tCoordinates *coords ){
  // Checar se a lista esta vazia
  //Checar se a posição passada é menor que 0 ou maior que o tamanho da lista

 /*Cheking if the list is empty*/
  if(LKC_IsEmpty(list))
    return ERROR;

  /*Checking if the position passed is correct*/
  if(pos < 1 || pos > list.Size)
    return ERROR;

  tLK_C_Node *node = list.Head;
  int count = 1;

/*Serching for node given the position*/
  while(count<pos){
    node = node->Next;
    count++;
  }
  /*Returning values to tCoordinates struct*/
  coords->xPosition = node->xPosition;
  coords->yPosition = node->yPosition;
  coords->zPosition = node->zPosition;

  return OKAY;
}

int CAddBegin(tLK_Coords *list,float xPosition,float yPosition,float zPosition,int isEmpty){
  int i;
  tLK_C_Node *newNode;
  /*Allocating memory*/
  newNode = malloc(sizeof(tLK_Coords));
  

  /*Checking if there's enough memory*/
  if(newNode == NULL){
    printf("Error creating node\n");
    return ERROR;
  }
  /*Assigning Value to Node*/

  newNode->xPosition = xPosition;
  newNode->yPosition = yPosition;
  newNode->zPosition = zPosition;


  /*If list is empty, then the next is NULL, if not, points to the head */
  if(isEmpty){
    newNode->Next = NULL;
  }
  else{
    newNode->Next = list->Head;

  }
  /*Add node to the head of list*/
  list->Head = newNode;
  list->Size++;

  return OKAY;
}

int CAddMiddle(tLK_Coords *list,int pos, float xPosition,float yPosition,float zPosition){
  tLK_C_Node *newNode;
  tLK_C_Node *tempNode;
  int i;
  /*Allocating memory to newNode*/
 newNode = malloc(sizeof(tLK_C_Node));

  /*Checking if there's enough memory*/
  if(newNode == NULL){
    printf("Error creating node\n");
    return ERROR;

  }

  /*Assigning value to newNode*/
  newNode->xPosition = xPosition;
  newNode->yPosition = yPosition;
  newNode->zPosition = zPosition;

  /*Searching for node pos -1 */
  int count = 1;
  tempNode = list->Head;
  while(count<pos-1){
    tempNode = tempNode->Next;
    count++;
  }
  /*Making antecessor point to newNode and newNode point to sucessor.*/
  newNode->Next = tempNode->Next;
  tempNode->Next = newNode;
  list->Size++;

  return OKAY;

}

int CAddEnd(tLK_Coords *list, float xPosition,float yPosition,float zPosition){
  tLK_C_Node *newNode;
  tLK_C_Node *tempNode;
  int i;

  /*Allocating memory to newNode*/
 newNode = malloc(sizeof(tLK_C_Node));

  /*Checking if there's enough memory*/
  if(newNode == NULL){
    printf("Error creating node\n");
    return ERROR;

  }

  /*Assigning value to newNode*/

  newNode->xPosition = xPosition;
  newNode->yPosition = yPosition;
  newNode->zPosition = zPosition;
  /* Searching for the end of list*/

 tempNode = list->Head;
  while (tempNode->Next!=NULL) {
    tempNode = tempNode->Next;


  }

  tempNode->Next = newNode;
  newNode->Next = NULL;
  list->Size++;


  return OKAY;

}

int LKC_Add (tLK_Coords *list, int pos, float xPosition,float yPosition,float zPosition){

  if(( pos < 1 ) || (pos > list->Size + 1)){
    return ERROR;
  }
  /*Adds at the beginning of the list*/
  if(pos == 1){
   return CAddBegin(list,xPosition,yPosition,zPosition,LKC_IsEmpty(*list));
  }
  /*Adds at the end of the list*/
  else if(pos == list->Size + 1){

    return CAddEnd(list,xPosition,yPosition,zPosition);
  }
  /*Adds in the middle of the list*/
  else{
    return CAddMiddle(list,pos,xPosition,yPosition,zPosition);
  }

}
int CRemoveBegin(tLK_Coords *list, int pos){
  tLK_C_Node *tempNode = list->Head;
  list->Head = tempNode->Next;
  list->Size--;
  free(tempNode);
  return OKAY;

}

int CRemoveInList(tLK_Coords *list, int pos){
  tLK_C_Node *antNode;
  tLK_C_Node *toBeExcludedNode;

  int count = 1;

  antNode = list->Head;
  while(count < pos-1){
    antNode = antNode->Next;
    count++;
  }

  toBeExcludedNode = antNode->Next;

  antNode->Next = toBeExcludedNode ->Next;
  list->Size--;
  free(toBeExcludedNode);
  return OKAY;

}

int LKC_Remove (tLK_Coords *list, int pos){

  if(( pos < 1 ) || (pos > list->Size + 1)){
    return ERROR;
  }

  if(pos == 1){
   return CRemoveBegin(list,pos);
  }
  /*Adds at the end of the list*/
  else
    return CRemoveInList(list,pos);
  }
