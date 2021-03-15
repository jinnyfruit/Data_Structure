/*
file name: 1-2
author: Ji Woo Kim
modified: 03.15, 2021
*/
#include <stdlib.h>
#include <stdio.h>

typedef struct NODE{
    int data;
    struct NODE* next;
}Node;

typedef struct Queue{
    Node* front;
    Node* rear;
}Q;

void QueueInit(Q * q);
int queue_empty(Q * q);
void Enqueue(Q* q, int data);
int Dequeue(Q * q);
int peek(Q * q);

int main(){
    Q q;
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
                    QueueInit(&q);
                    printf("Queue is ready to use.\n");
                    break;
                case 2:
                    printf("type a integer you want to enqueue:\n");
                    scanf("%d",&data);
                    Enqueue(&q,data);
                    break;
                case 3:
                    data = Dequeue(&q);
                    printf("deleted data:%d\n",data);
                    break;
                case 4:
                    data = peek(&q);
                    printf("peek:%d\n",data);
                    break;
                case 5:
                    if(queue_empty(&q))
                        printf("Queue is empty!");
                    else{
                        Q ptr;
                        ptr.front=q.front;
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

void QueueInit(Q * q){    //queque initialization
    q->front=NULL;
    q->rear=NULL;
}

int queue_empty(Q * q){
    if(q->front==NULL){    //if queue is empty, return 1
        return 1;
    }
    else
        return 0;
}

void Enqueue(Q* q, int data){
    Node * node=(Node*)malloc(sizeof(Node));    //동적할당을 이용해서 노드 생성
    node->next=NULL;    //initialization of next
    node->data=data;

    if(queue_empty(q)){
        q->front = node;
        q->rear = node;
    }
    else{
        q->rear->next = node;  //linking prev node and cur node
        q->rear = node;    //rear is pointing new node
    }
}

int Dequeue(Q * q){
    Node* delnode;
    int deldata;

    if(queue_empty(q)){
        printf("Queue Memory is empty!\n");
        exit(-1);
    }
    delnode = q->front;    //save the address of delnode
    deldata = delnode->data;   //save the data of delnode
    q->front = q->front->next;    //change front value

    free(delnode);
    return deldata;
}

int peek(Q * q){
    if(queue_empty(q)){
        printf("Queue Memory is empty!\n");
        exit(-1);
    }
    return q->front->data;
}
