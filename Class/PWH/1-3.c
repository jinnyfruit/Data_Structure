/*
file name: 1-3
author: Ji Woo Kim
modified: 03.16,2021
*/
#include <stdlib.h>
#include <stdio.h>

#define MAX 10

typedef struct Queue{
    int front;
    int rear;
    int arrQueque[MAX];
}Q;

int queue_empty(Q * q);
int queue_full(Q * q);
void Enqueue(Q* q, int data);
int Dequeue(Q * q);
void Push(Q* q1,int data);
int Pop(Q* q1, Q* q2);

int main(){
    Q q1,q2;    //there are two queue

    q1.front=-1;    //initialize queue
    q1.rear=-1;
    q2.front=-1;
    q2.rear=-1;

    int choice;
    int i,data;

       
        while(1){
        printf("1.Push 2.POP 3.EXIT\n");
        scanf("%d",&choice);
        if(choice==3){
            printf("EXITED\n");
            break;
        }
         else{   
            switch(choice){
                case 1:
                    if(queue_full(&q1))
                        printf("Stack is full\n");
                    else{
                        printf("Type integer:");
                        scanf("%d",&data);
                        Push(&q1,data);
                    }
                    break;
                case 2:
                    if(queue_empty(&q1))
                        printf("Stack is empty\n");
                    else{
                        printf("deleted data:%d\n",Pop(&q1,&q2));
                    }
                    break;
                default :
                    printf("Try again\n");
                    break;
            }
    }
        }
    return 0;

}


int queue_empty(Q * q){
    if(q->front > q->rear|| q->front == -1){    //if queue is empty, return 1
        return 1;   
    }  
    else
        return 0;
}

int queue_full(Q * q){
    if(q->rear-q->front==MAX - 1) 
        return 1;
    else
        return 0;
}


void Enqueue(Q* q, int data){
 
    q->rear+=1;
    if(q->front == -1){
        q->front ++;
    }
    q->arrQueque[q->rear]=data; 
  
}

int Dequeue(Q * q){
    
    int data = q->arrQueque[q->front];
    q->front++;
    return data; 
}

void Push(Q* q1,int data){
    if(queue_full(q1))
        printf("Stack is full!\n");
    else {
        Enqueue(q1,data);
    }
}

int Pop(Q * q1,Q* q2){
    
    int deldata;
    while(q1->front!=q1->rear){
        Enqueue(q2,Dequeue(q1));
    }
    deldata = Dequeue(q1);

    while(!queue_empty(q2)){
        Enqueue(q1, Dequeue(q2));
    }
    return deldata;
}