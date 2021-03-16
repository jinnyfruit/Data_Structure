/*
file name: non-circular Queue
author: jinnyfruit
modified: 03.10,2021
*/
#include <stdlib.h>
#include <stdio.h>

#define MAX 10

typedef struct Queue{
    int front;
    int rear;
    int arrQueque[MAX];
}Q;



int main(){
    Q cq;
    int choice;
    int i,data;

    while(1){
        printf("1.INIT 2.Enqueue 3.Dequeue 4.Queue_PEEK 5.SHOW 6.EXIT\n");
        scanf("%d",&choice);
        if(choice==6){
            printf("EXITED\n");
            break;
        }
        else{
            switch(choice){
                case 1:
                    QueueInit(&cq);
                    printf("Circular Queue is ready to use.\n");
                    break;
                case 2:
                    printf("type a integer you want to enqueue:\n");
                    scanf("%d",&data);
                    Enqueue(&cq,data);
                    break;
                case 3:
                    if(queue_empty(&cq)==1){
                        printf("Queue is empty!\n");
                    }
                    else{
                        data = Dequeue(&cq);
                        printf("deleted data:%d\n",data);
                    }
                    break;
                case 4:
                    data = peek(&cq);
                    printf("peek:%d\n",data);
                    break;
                case 5:
                    if(queue_empty(&cq))
                        printf("Queue is empty!");
                    else{
                        for(i=cq.front+1;i<=cq.rear;i++){
                            printf("%d\t",cq.arrQueque[i]);
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

void QueueInit(Q * cq){    //queque initialization
    cq->front=-1;
    cq->rear=-1;
}

int queue_empty(Q * cq){
    if(cq->front==cq->rear){    //if queue is empty, return 1
        return 1;   
    }  
    else
        return 0;
}

int queue_full(Q * cq){
    if(cq->rear==9) 
        return 1;
    else
        return 0;
}


void Enqueue(Q* cq, int data){
  if(queue_full(cq)==1){
      printf("Queue is full\n");
  }
  else{
    cq->rear+=1;
    cq->arrQueque[cq->rear]=data; 
    
  }
}

int Dequeue(Q * cq){
    cq->front+=1;
    int data = cq->arrQueque[cq->front];
    return data; 
}
int peek(Q * cq){
    if(queue_empty(cq)){
        printf("Queue is empty!");
        exit(-1);
    }
    return cq->arrQueque[cq->rear];
}
