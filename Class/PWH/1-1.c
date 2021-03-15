/*
file name: Linked-list stack
author: Ji-Woo,Kim
modified: 03.15, 2021
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
    int choice;
    int i,data;

       
        while(1){
        printf("1.INIT 2.PUSH 3.POP 4.PEEK 5.SHOW 6.EXIT\n");
        scanf("%d",&choice);
        
        if(choice==6){
            printf("EXITED\n");
            break;
        }
         else{   
            switch(choice){
                case 1:
                    stackInit(&stack);
                    printf("Stack is ready to use.\n");
                    break;
                case 2:
                    printf("type a integer you want to push:\n");
                    scanf("%d",&data);
                    push(&stack,data);
                    break;
                case 3:
                    
                    data=pop(&stack);
                    if(data==NULL)
                        break;
                    else 
                        printf("deleted data:%d\n",data);
                        break;
                case 4:
                    data=peek(&stack);
                    printf("peek:%d\n",data);
                    
                    break;
                case 5:
                    if(Stack_Empty(&stack)){//defensive coding
                        printf("Stack is empty!");
                    }
                    else{
                        Stack Sptr; //make a new pointer
                        Sptr.head=stack.head;
                        while(Sptr.head!=NULL){
                            printf("%d\t",Sptr.head->data);
                            Sptr.head=Sptr.head->next;
                        }
                        printf("\n");
                    }
                    break;
                default :
                    printf("해당사항 없음\n");
                    break;
            }
    }
        }
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

    if(Stack_Empty(stack)){     //if stack is empty, print error!
        printf("Stack Memory is empty!\n");
        exit(-1);
    }
    else {
    delData=stack->head->data;      //save the delete data 
    delNode=stack->head;        //save the address of Node

    stack->head=stack->head->next;      //point the next node of deleted node
    free(delNode);      //node delete
    return delData;     //return the deleted data
    }
}
int peek(Stack* stack){

    if(Stack_Empty(stack)){
        printf("Stack Memory is empty!\n");
        return -1;
    }
    else{
        return stack->head->data;      //return data that head is pointing 
    }
}