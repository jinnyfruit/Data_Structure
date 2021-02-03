/*
file name: array circular Queue
author: jinnyfruit
modified: 02.04, 2021
*/
#include <stdlib.h>
#include <stdio.h>

#define MAX 100

typedef struct Circular_Queue{
    int front;
    int rear;
    int arrQueque[MAX];
}CQ;

void QueueInit(CQ * cq);
int isQEmpty(CQ * cq);
int nextPosInx(int pos);
void Enqueue(CQ* cq, int data);
int Dequeue(CQ * cq);
int peek(CQ * cq);

int main(){
    CQ cq;
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
                    data = Dequeue(&cq);
                    printf("deleted data:%d\n",data);
                    break;
                case 4:
                    data = peek(&cq);
                    printf("peek:%d\n",data);
                    break;
                case 5:
                    if(isQEmpty(&cq))
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

void QueueInit(CQ * cq){    //queque initialization
    cq->front=0;
    cq->rear=0;
}

int isQEmpty(CQ * cq){
    if(cq->front==cq->rear){    //if queue is empty, return 1
        return 1;
    }
    else
        return 0;
}

int nextPosInx(int pos){
    if(pos==MAX-1)
        return 0;
    else 
        return pos+1;
}

void Enqueue(CQ* cq, int data){
    if(nextPosInx(cq->rear)==cq->front){    //if queue is full
        printf("Queue Memory error!");
        exit(-1);
    }
    cq->rear = nextPosInx(cq->rear);    //move rear
    cq->arrQueque[cq->rear] = data;     //sava data in the space that rear is pointing
}

int Dequeue(CQ * cq){
    if(isQEmpty(cq)){
        printf("Queue Memory Error!");
        exit(-1);
    }
    cq->front = nextPosInx(cq->front);
    return cq->arrQueque[cq->front];
}

int peek(CQ * cq){
    if(isQEmpty(cq)){
        printf("Queue Memory Error!");
        exit(-1);
    }
    return cq->arrQueque[nextPosInx(cq->front)];
}
