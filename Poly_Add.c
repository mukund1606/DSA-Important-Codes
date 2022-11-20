#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int i;

struct node
{
  int coeff;
  int pow;
  struct node *next;
};

struct node * create_poly(){
  struct node *poly, *temp, *temp2;
  int c, coeff, pow;
  poly = (struct node *)malloc(sizeof(struct node));
  printf("Enter Number of Terms in Polynomial: ");
  scanf("%d", &c);
  for(i = c; i > 0; i--){
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter Coeff and Pow: ");
    scanf("%d", &coeff);
    scanf("%d", &pow);
    temp->coeff = coeff;
    temp->pow = pow;
    temp->next = NULL;
    if(i == c){
      poly = temp;
      temp2 = poly;
    }
    else{
      temp2->next = temp;
      temp2 = temp;
    }
  }
  return poly;
}

struct node * poly_add(struct node *poly1, struct node *poly2){
  struct node *temp1, *temp2, *temp, *poly, *temp3;
  int c = 0;
  temp1 = poly1;
  temp2 = poly2;
  while(temp1 != NULL && temp2 != NULL){
    temp = (struct node *)malloc(sizeof(struct node));
    if(temp1->pow == temp2->pow){
      temp->pow = temp1->pow;
      temp->coeff = temp1->coeff + temp2->coeff;
      temp1 = temp1->next;
      temp2 = temp2->next;
    }
    else if(temp1->pow > temp2->pow){
      temp->pow = temp1->pow;
      temp->coeff = temp1->coeff;
      temp1 = temp1->next;
    }
    else{
      temp->pow = temp2->pow;
      temp->coeff = temp2->coeff;
      temp2 = temp2->next;
    }
    if(c == 0){
      poly = temp;
      temp3 = temp;
      c++;
    }
    else{
      temp3->next = temp;
      temp3 = temp3->next;
    }
  }
  while(temp1 != NULL){
    temp = (struct node *)malloc(sizeof(struct node));
    temp->pow = temp1->pow;
    temp->coeff = temp1->coeff;
    temp1 = temp1->next;
    if(c == 0){
      poly = temp;
      temp3 = temp;
      c++;
    }
    else{
      temp3->next = temp;
      temp3 = temp3->next;
    }
  }
  while(temp2 != NULL){
    temp = (struct node *)malloc(sizeof(struct node));
    temp->pow = temp2->pow;
    temp->coeff = temp2->coeff;
    temp2 = temp2->next;
    if(c == 0){
      poly = temp;
      temp3 = temp;
      c++;
    }
    else{
      temp3->next = temp;
      temp3 = temp3->next;
    }
  }
  return poly;
}

void traverse(struct node *poly){
  struct node *temp;
  temp = poly;
  while(temp != NULL){
    printf("Coeff: %d   Pow: %d \n", temp->coeff, temp->pow);
    temp = temp->next;
  }
}

int main(){
  struct node *poly1, *poly2, *poly;
  poly1 = create_poly();
  poly2 = create_poly();
  poly = poly_add(poly1, poly2);
  traverse(poly);
  // getch();
  // clrscr();
  return 0;
}