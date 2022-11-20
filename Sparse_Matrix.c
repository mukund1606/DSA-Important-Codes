#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node{
  int r;
  int c;
  int data;
  struct node *next;
};


int ** createMatrix(int r, int c){
  int **mat, i, j;
  mat = (int **)malloc(r*sizeof(int *));
  for(i = 0; i < c; i++){
    mat[i] = (int *)malloc(c*sizeof(int));
  }
  printf("Enter Elements of Matrix:\n");
  for(i = 0; i < r; i++){
    for(j = 0; j < c; j++){
      scanf("%d", &mat[i][j]);
    }
  }
  return mat;
}


struct node * sparseMatrix(int **matrix, int r, int c){
  int i, j;
  struct node *sparse = NULL, *temp, *temp2;
  for(i = 0; i < r; i++){
    for(j = 0; j < c; j++){
      if(matrix[i][j] != 0){
        temp = (struct node *)malloc(sizeof(struct node));
        temp->r = i;
        temp->c = j;
        temp->data = matrix[i][j];
        if(sparse == NULL){
          sparse = temp;
          temp2 = temp;
        }
        else{
          temp2->next = temp;
          temp2 = temp2->next;
        }
      }
    }
  }
  return sparse;
}


void traverse(struct node *head){
  struct node *temp;
  temp = head;
  while(temp != NULL){
    printf("Row:%d  Column:%d  Value:%d\n", temp->r, temp->c, temp->data);
    temp = temp->next;
  }
}

int main(){
  int **matrix, r, c, i;
  struct node *sparse;
  printf("Enter Number of Rows and Columns: ");
  scanf("%d", &r);
  scanf("%d", &c);
  matrix = createMatrix(r, c);
  sparse = sparseMatrix(matrix, r, c);
  traverse(sparse);
  // getch();
  // clrscr();
  return 0;
}