#include "lkfaces.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


/*Creating a new List*/
void LKF_NewList (tLK_Faces *list){
  list->Head = NULL;
  list->Size = 0;

}

/*Checking if list is empty*/
int LKF_IsEmpty (tLK_Faces list){
  return ((list.Size == 0)? TRUE : FALSE);
}

/*Returns the size of a list*/
int LKF_Size (tLK_Faces list){
  return list.Size;
}


int LKF_GetItem (tLK_Faces list, int pos, int *data ){

 /*Cheking if the list is empty*/
  if(LKF_IsEmpty(list))
    return ERROR;

  /*Checking if the position passed is correct*/
  if(pos < 1 || pos > list.Size)
    return ERROR;

  tLK_F_Node *node = list.Head;
  int count = 1;

/*Serching for node given the position*/
  while(count<pos){
    node = node->Next;
    count++;
  }
  /* Returning value*/
  memcpy(data,node->points,3*sizeof(int));

  return OKAY;
}

int FAddBegin(tLK_Faces *list,int *data,int isEmpty){
  int i;
  tLK_F_Node *newNode;
  /*Allocating memory*/
  newNode = malloc(sizeof(tLK_F_Node));


  /*Checking if there's enough memory*/
  if(newNode == NULL){
    printf("Error creating node\n");
    return ERROR;
  }
  /*Assigning Value to Node*/

  memcpy(newNode->points,data,3*sizeof(int));


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

int FAddMiddle(tLK_Faces *list,int pos, int *data){
  tLK_F_Node *newNode;
  tLK_F_Node *tempNode;
  int i;
  /*Allocating memory to newNode*/
 newNode = malloc(sizeof(tLK_F_Node));

  /*Checking if there's enough memory*/
  if(newNode == NULL){
    printf("Error creating node\n");
    return ERROR;

  }

  /*Assigning value to newNode*/
  memcpy(newNode->points,data,3*sizeof(int));

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

int FAddEnd(tLK_Faces *list, int *data){
  tLK_F_Node *newNode;
  tLK_F_Node *tempNode;
  int i;

  /*Allocating memory to newNode*/
 newNode = malloc(sizeof(tLK_F_Node));

  /*Checking if there's enough memory*/
  if(newNode == NULL){
    printf("Error creating node\n");
    return ERROR;

  }

  /*Assigning value to newNode*/

  memcpy(newNode->points,data,3*sizeof(int));
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

int LKF_Add (tLK_Faces *list, int pos, int *data){

  if(( pos < 1 ) || (pos > list->Size + 1)){
    return ERROR;
  }
  /*Adds at the beginning of the list*/
  if(pos == 1){
   return FAddBegin(list,data,LKF_IsEmpty(*list));
  }
  /*Adds at the end of the list*/
  else if(pos == list->Size + 1){

    return FAddEnd(list,data);
  }
  /*Adds in the middle of the list*/
  else{
    return FAddMiddle(list,pos,data);
  }

}

int FRemoveBegin(tLK_Faces *list, int pos){
  tLK_F_Node *tempNode = list->Head;
  list->Head = tempNode->Next;
  list->Size--;
  free(tempNode);
  return OKAY;

}

int FRemoveInList(tLK_Faces *list, int pos){
  tLK_F_Node *antNode;
  tLK_F_Node *toBeExcludedNode;

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

int LKF_Remove (tLK_Faces *list, int pos){

  if(( pos < 1 ) || (pos > list->Size + 1)){
    return ERROR;
  }

  if(pos == 1){
   return FRemoveBegin(list,pos);
  }

  else
    return FRemoveInList(list,pos);
  }
