/*
file name: 1-4
author: Ji Woo Kim
modified: 03.16, 2021
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct array_stack
{
    int data[MAX];
    int topindex;   //checks the location of last data
}Stack;


int Stack_Empty(Stack* stack);
void push(Stack* stack, int data );
int pop(Stack* stack);
int queue_full(Stack* stack , Stack* stack2);
int queue_empty(Stack* stack1, Stack * stack2);
int enqueue(Stack* stack1,int data);
int dequeue(Stack* stack1, Stack* stack2);

int main(){
    
    Stack stack1,stack2;
    stack1.topindex=-1;     //initialization
    stack2.topindex=-1;

    int choice;
    int i,data;

       
        while(1){
        printf("1.Enqueue 2.Dequeue 3.EXIT \n");
        scanf("%d",&choice);
        if(choice==3){
            printf("EXITED\n");
            break;
        }
         else{   
            switch(choice){
                case 1:
                    
                    if(queue_full(&stack1,&stack2))
                        printf("Queue is full!\n");

                    else{
                        printf("type an integer:");
                        scanf("%d",&data);

                        push(&stack1,data);
                    }
                    break;
                case 2:
                    
                    if(queue_empty(&stack1,&stack2)){
                        printf("Queue is empty!");
                    }
                    else 
                        printf("deleted data: %d\n",dequeue(&stack1,&stack2));
                    break;
                default :
                    printf("Try again\n");
                    break;
            }
    }
        }
    return 0;
}

int Stack_Empty(Stack* stack){
    
    if(stack->topindex==-1)     //if topindex is -1, stack is never been used.
        return 1;
    else
        return 0;
}

void push(Stack* stack, int data){
    stack->topindex+=1;     //increase topindex
    stack->data[stack->topindex]=data;      //save the data
}
int pop(Stack* stack){
    int delData=stack->data[stack->topindex];
    stack->topindex-=1;
    return delData;
}

int queue_full(Stack* stack1, Stack* stack2){
    if(stack1->topindex + stack2 -> topindex +2==MAX)
        return 1;
    else 
        return 0;
}

int queue_empty(Stack* stack1, Stack* stack2){
     if (stack1->topindex == -1 && stack2->topindex == -1)
        return 1;

    else
        return 0;
}

int enqueue(Stack* stack1,int data){
    push(stack1,data);
}

int dequeue(Stack* stack1, Stack* stack2) {

   int deldata;
   
    if((Stack_Empty(stack1)!=1 && Stack_Empty(stack2)!=1)||(Stack_Empty(stack1)==1&&Stack_Empty(stack2)!=1))
        deldata = pop(stack2);
    else if(Stack_Empty(stack1)!=1 && Stack_Empty(stack2)==1){
        while(Stack_Empty(stack1)!=1){
            push(stack2,pop(stack1));
        }
        deldata = pop(stack2);
    }

    return deldata;
}
