/*! \file lkcoords.h
    \brief Header file that defines a linked list of
    coordinates and its functions.
    The functions
    This .h holds the functions that implements a singly
    linked list, used to save content related to coordinates.
*/

/*! \def TRUE, FAlSE
    \brief Macros that define the booleans true and false.
*/

/*! \def OKAY, ERROR
    \brief Macros that define flags representing error and sucess.
*/

/*! \struct tLK_C_Node
    \brief Structure that holds the content of a list
    element and a pointer to the next element.
*/

/*! \struct tLK_Coords
    \brief Structure that holds the list itself.
    Contains the head of the list and the size.
*/

/*! \struct tCoordinates
    \brief Structure that holds the content of
    coordinates. Used to retrieve an element content.
*/

/*! \fn void LKC_NewList (tLK_Coords *list)
    \brief Creates a new list, setting size to 0 and
    head to NULL.
    \param list Takes a pointer to a coordinates list.
*/

/*! \fn int LKC_IsEmpty (tLK_Coords list)
    \brief Checks if the list is empty
    \param list Takes the list itself.
*/

/*! \fn int LKC_Size (tLK_Coords list)
    \brief Returns the size of a coordinates list
    \param list Takes a pointer to a coordinates list.
*/

/*! \fn int LKC_GetItem (tLK_Coords list, int pos, tCoordinates *coords )
    \brief Returns an element content, given its position.
    \param list Takes the coordinates list itself.
    \param pos Position of the element.
    \param coords Takes a pointer to coordinates structure, to retrieve
    content.
*/

/*! \fn int LKC_Add (tLK_Coords *list, int pos, float xPosition,float yPosition,float zPosition )
    \brief Adds an element to the list, at beginning, middle or at the end.
    \param list Takes a pointer to a coordinates list.
    \param pos Position of the element.
    \param xPosition The float value of the coordinate X.
    \param yPosition The float value of the coordinate Y.
    \param zPosition The float value of the coordinate Z.
*/

/*! \fn int LKC_Remove (tLK_Coords *list, int pos)
    \brief Removes an element from the list.
    \param list Takes a pointer to a coordinates list.
    \param pos Position of the element to be removed.
*/

#ifndef LKCOORDS_H_INCLUDED
#define LKCOORDS_H_INCLUDED

#define TRUE 1
#define FALSE 0
#define OKAY -1
#define ERROR -2

typedef struct NodeCoord{
  float xPosition;
  float yPosition;
  float zPosition;
  struct NodeCoord* Next;

}tLK_C_Node;

typedef struct{
  struct NodeCoord* Head;
  int Size;
}tLK_Coords;

typedef struct{
  float xPosition;
  float yPosition;
  float zPosition;
}tCoordinates;

void LKC_NewList (tLK_Coords *list);
int LKC_IsEmpty (tLK_Coords list);
int LKC_Size (tLK_Coords list);
int LKC_GetItem (tLK_Coords list, int pos, tCoordinates *coords );
int LKC_Add (tLK_Coords *list, int pos, float xPosition,float yPosition,float zPosition );
int LKC_Remove (tLK_Coords *list, int pos);

#endif
