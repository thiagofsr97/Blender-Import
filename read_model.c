/****************************************
*Author: Thiago Filipe Soares da Rocha  *
*UFPB - Computer Science                *
*Registration: 11502567                 *
*Date: 27/02/2017                       *
*Professor: Liliane                     *
****************************************/

/****************************************
* The purpose of this program is to     *
* read a .x3d file, exported from       *
* blender. Doing so, the information    *
* related to vertices and their coordi- *
* nates will be added to linked lists.  *
****************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lkcoords.h"
#include "lkfaces.h"

/* Linked list to save the coordinates of vertices */
tLK_Coords coordList;
/* Linked list to save the vertices */
tLK_Faces facesList;
/* Struct to retrive content from coordinates */
tCoordinates coordinates;
/* Buffer reader */
char buffer[70];

/*! \fn int openFile(FILE **file,char *path, char *mode)
    \brief Opens a file in the chosen mode.
    \param file Takes a pointer to a file.
    \param path File path.
    \param mode Mode file will be opened.
*/
int openFile(FILE **file,char *path, char *mode){
  *file = fopen(path,mode);
  if(file){

    return TRUE;
  }
  else{
    printf("Error opening file.\n");
    return FALSE;
  }
}

/*! \fn int closeFile(FILE **file)
    \brief Closes a file, finishing operations with it.
    \param file Takes a pointer to a file.
*/

int closeFile(FILE **file){
  if(!fclose(*file))
    return TRUE;
  else
    return FALSE;
}

/*! \fn void BeginAddPoints(FILE *file)
    \brief Add the coordinates to list.
    \param file Takes a pointer to a file.
*/
void BeginAddPoints(FILE *file){
  LKC_NewList(&coordList);
  float number;
  float listElement[3];
  int i = 0;

  /* Grabbing points and adding them to list*/
  while(!feof(file)){
    fscanf(file,"%s",buffer);
    /* Stopping condition, means it's finished reading the list*/
    if(strstr(buffer,"\"")){
      printf("Finished reading points.\n");
       break;
    }
    /*Converting number to float and adding it*/
    number = strtof(buffer,NULL);
    listElement[i] = number;
    i++;
    if(i == 3){
      i = 0;
      LKC_Add(&coordList,coordList.Size + 1, listElement[0],listElement[1],listElement[2]);
    }
  }
}

/*! \fn void readPoints(FILE *file)
    \brief Reads the file until it reaches the
    beginning of coordinates.
    \param file Takes a pointer to a file.
*/

void readPoints(FILE *file){
  char c;
  int i = 0;

  /* Searching for beginning of coordinates */
  while(!feof(file)){
    fscanf(file,"%s",buffer);
    if(strstr(buffer,"<Coordinate")){
       break;
    }
  }

  /* Moving to beginning of points*/
  while(!feof(file)){
    c = fgetc(file);
    if(c == '\"')
      i++;
    if(i == 3)
      break;
  }
  printf("Reading points...\n");
  BeginAddPoints(file);
}

/*! \fn void beginAddFaces(FILE *file)
    \brief Add vertices to list.
    \param file Takes a pointer to a file.
*/
void beginAddFaces(FILE *file){
  LKF_NewList(&facesList);
  int number;
  int i = 0;
  int listElement[3];

  /* Grabbing points and adding them to list*/
  while(!feof(file)){
    fscanf(file,"%s",buffer);

    if(strstr(buffer,"\"")){
      printf("Finished reading faces.\n");
       break;
    }
    number = atoi(buffer);
    if(number != -1){
      listElement[i] = number;
      i++;
      if(i == 3){
        i = 0;
        LKF_Add(&facesList,facesList.Size + 1,listElement);
      }
    }
  }

}

/*! \fn void readFaces(FILE *file)
    \brief Reads the file until it reaches the
    beginning of vertices.
    \param file Takes a pointer to a file.
*/

void readFaces(FILE *file){
  char c;
  int i = 0;
  /* Searching for beginning of faces */
  while(!feof(file)){
    fscanf(file,"%s",buffer);
    if(strstr(buffer,"<IndexedFaceSet")){
       break;
    }
  }
  while(!feof(file)){
    c = fgetc(file);
    if(c == '\"')
      i++;
    if(i == 3)
      break;
  }

  printf("Reading faces...\n");
  beginAddFaces(file);
}

/*! \fn void showFaces(tLK_Faces faces)
    \brief Grab the vertices from linked list
    and print them to console.
    \param faces LinkedList of vertices.
*/
void showFaces(tLK_Faces faces){
  int listElements[3];
  int i = 1;
  printf("\nFaces list: \n");
  for(i;i < LKF_Size(faces) + 1; i++){
    LKF_GetItem(faces,i,listElements);
    printf("Element %d:  %d %d %d \n", i, listElements[0],listElements[1],listElements[2]);
  }
  printf("\n\n");

}

/*! \fn void showPoints(tLK_Coords coords)
    \brief Grab the coordinates from linked list
    and print them to console.
    \param faces LinkedList of coordinates.
*/
void showPoints(tLK_Coords coords){
  int i = 1;
  printf("Coordinates List: \n");
  for(i;i<LKC_Size(coords) + 1;i++){
    LKC_GetItem(coords,i,&coordinates);
    printf("Position %d: X = %f Y = %f Z = %f\n",i,coordinates.xPosition,coordinates.yPosition,coordinates.zPosition);
  }
  printf("\n\n");
}

/*! \fn int main(int argc, char *argv[])
    \brief Opens a file given the path and
    operates with it.
    \param argc Number of arguments.
    \param argv Arguments themselves.
*/
int main(int argc, char *argv[]){

  /*Checking if the correct arguments were passsed to main*/
  if(!(argc == 2)){
    printf("Wrong arguments. You need to pass the file as argument.\n");
    return 0;
  }
  /*Opening the file in reading mode*/
  FILE *file;
  if(!openFile(&file,argv[1],"r")){
      printf("Error opening file. Check file path and file name.\n");
      return 0;
  }
  /* Reading the file looking for faces and points and adding to list*/
  readFaces(file);
  readPoints(file);

  /*Operations are finished, closing the file*/
  closeFile(&file);

  /*Printing both lists*/
  showFaces(facesList);
  showPoints(coordList);

}
