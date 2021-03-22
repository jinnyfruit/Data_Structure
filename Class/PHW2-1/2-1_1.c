/*
file name: PHW 2-1 (1)
author: 202035513 Ji Woo Kim
modified: 03.22, 2021
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
    int data;
    struct NODE* next;
}Node;

typedef struct LIST_STACK
{
   Node* head;  //top
}Stack;


//function prototype
void stackInit(Stack*);
int Stack_Empty(Stack*);
void push(Stack*, int);
int pop(Stack*);
int peek(Stack*);

int main(){
    
    Stack stack;
    stackInit(&stack);
    int choice;
    int i,data;
    int num;
     
    printf("type an integer to convert:");
    scanf("%d",&num);

    while(num>=1) {
        push(&stack,num%2);
        num = num/2;
    }

    printf("decimal to binary\n");

    while(Stack_Empty(&stack)!=1){
        data = pop(&stack);
        printf("%d",data);
    }
    
    printf("\n");

    return 0;
}

void stackInit(Stack* stack){
    stack->head=NULL;     //initialize head pointer to NULL
}

int Stack_Empty(Stack* stack){
    
    if(stack->head==NULL)     //if head is NULL, stack is never been used.
        return 1;
    else
        return 0;
}

void push(Stack* stack, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));    //make a new node

    newNode->data = data;
    newNode->next = stack->head;    //next points the current node
    stack->head = newNode;      //head points the new node
}
int pop(Stack* stack){
    
    int delData;
    Node* delNode;

    if(Stack_Empty(stack)==1){     //if stack is empty, print error!
        printf("Stack Memory Error!");
        exit(-1);
    }
    else{
    delData=stack->head->data;      //save the delete data 
    delNode=stack->head;        //save the address of Node

    stack->head=stack->head->next;      //point the next node of deleted node
    free(delNode);      //node delete
    return delData;     //return the deleted data
    }
}
