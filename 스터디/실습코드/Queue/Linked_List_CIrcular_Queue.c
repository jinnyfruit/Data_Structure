/*
file name: Linked List circular Queue
author: jinnyfruit
modified: 02.04, 2021
*/
#include <stdlib.h>
#include <stdio.h>

#define MAX 100

typedef struct NODE{
    int data;
    struct NODE* next;
}Node;

typedef struct Circular_Queue{
    Node* front;
    Node* rear;
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
                        CQ ptr;
                        ptr.front=cq.front;
                        while(ptr.front!=NULL){
                            printf("%d\t",ptr.front->data);
                            ptr.front=ptr.front->next;
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
    cq->front=NULL;
    cq->rear=NULL;
}

int isQEmpty(CQ * cq){
    if(cq->front==NULL){    //if queue is empty, return 1
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
    Node * node=(Node*)malloc(sizeof(Node));    //동적할당을 이용해서 노드 생성
    node->next=NULL;    //initialization of next
    node->data=data;

    if(isQEmpty(cq)){
        cq->front = node;
        cq->rear = node;
    }
    else{
        cq->rear->next = node;  //linking prev node and cur node
        cq->rear = node;    //rear is pointing new node
    }
}

int Dequeue(CQ * cq){
    Node* delnode;
    int deldata;

    if(isQEmpty(cq)){
        printf("Queue Memory Error!");
        exit(-1);
    }
    delnode = cq->front;    //save the address of delnode
    deldata = delnode->data;   //save the data of delnode
    cq->front = cq->front->next;    //change front value

    free(delnode);
    return deldata;
}

int peek(CQ * cq){
    if(isQEmpty(cq)){
        printf("Queue Memory Error!");
        exit(-1);
    }
    return cq->front->data;
}
