/*
file name: array stack
author: jinnyfruit
modified: 01.26, 2021
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct array_stack
{
    int data[MAX];
    int topindex;   //checks the location of last data
}Stack;

//function prototype
void stackInit(Stack*);
int IsStackEmpty(Stack*);
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
        if(choice=='6'){
            printf("EXITED");
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
                    printf("deleted data:%d\n",data);
                    break;
                case 4:
                    data=peek(&stack);
                    printf("peek:%d\n",data);
                    break;
                case 5:
                    if(stack.topindex==-1){//defensive coding
                        printf("Stack is empty!");
                    }
                    else{
                        for(i=stack.topindex;0<=i;i--){     //shows the data from top of the stack
                            printf("%d\t",stack.data[i]);
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
    stack->topindex=-1;     //initialize stackindex to -1
}

int IsStackEmpty(Stack* stack){
    
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
int peek(Stack* stack){

    if(IsStackEmpty(stack)){
        printf("Stack Memory Error!");
    }
    return stack->data[stack->topindex];   
}