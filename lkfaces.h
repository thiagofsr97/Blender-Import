/*! \file lkfaces.h
    \brief Header file that defines a linked list of
    vertices and its functions.
    This .h holds the functions that implements a singly
    linked list, used to save content related to vertices.
*/

/*! \def TRUE, FAlSE
    \brief Macros that define the booleans true and false.
*/

/*! \def OKAY, ERROR
    \brief Macros that define flags representing error and sucess.
*/

/*! \struct tLK_F_Node
    \brief Structure that holds the content of a list
    element and a pointer to the next element.
*/

/*! \struct tLK_Faces
    \brief Structure that holds the list itself.
    Contains the head of the list and the size.
*/


/*! \fn void LKF_NewList (tLK_Faces *list)
    \brief Creates a new list, setting size to 0 and
    head to NULL.
    \param list Takes a pointer to a vertices list.
*/

/*! \fn int LKF_IsEmpty (tLK_Faces list)
    \brief Checks if the list is empty
    \param list Takes the list itself.
*/

/*! \fn int LKC_Size (tLK_Faces list)
    \brief Returns the size of a vertices list
    \param list Takes a pointer to a vertices list.
*/

/*! \fn int LKF_GetItem (tLK_Faces list, int pos, int *data )
    \brief Returns an element content, given its position.
    \param list Takes the vertices list itself.
    \param pos Position of the element.
    \param coords Takes a pointer to an int, waiting for a 3 sized array.
*/

/*! \fn int LKF_Add (tLK_Faces *list, int pos,int *data)
    \brief Adds an element to the list, at beginning, middle or at the end.
    \param list Takes a pointer to a vertices list.
    \param pos Position of the element.
    \param data Takes a pointer to an int, waiting for a 3 sized array.
*/

/*! \fn int LKF_Remove (tLK_Faces *list, int pos)
    \brief Removes an element from the list.
    \param list Takes a pointer to a vertices list.
    \param pos Position of the element to be removed.
*/


#ifndef LKFACES_H_INCLUDED
#define LKFACES_H_INCLUDED

#define TRUE 1
#define FALSE 0
#define OKAY -1
#define ERROR -2

typedef struct NodeFace{
  int points[3];
  struct NodeFace* Next;

}tLK_F_Node;

typedef struct{
  struct NodeFace* Head;
  int Size;
}tLK_Faces;

void LKF_NewList (tLK_Faces *list);
int LKF_IsEmpty (tLK_Faces list);
int LKF_Size (tLK_Faces list);
int LKF_GetItem (tLK_Faces list, int pos, int *data );
int LKF_GetPosition (tLK_Faces list,int *pos, int *data);
int LKF_Add (tLK_Faces *list, int pos, int *data );
int LKF_Remove (tLK_Faces *list, int pos);

#endif
