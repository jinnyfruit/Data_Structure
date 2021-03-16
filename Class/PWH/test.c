
#include<stdio.h>

#define SIZE 10

int stack1[SIZE], stack2[SIZE], top1 = -1, top2 = -1;

int main() {

    void View();//Stack viewer function
    int queue_full();//Check the queue is full(Queue means two stacks)
    int queue_empty();//Check the queue is empty(Queue means two stacks)
    int stack1_empty();//Check the stack1 is empty
    int stack2_empty();//Check the stack2 is empty
    void push1(int value);//Push value in stack1
    void push2(int value);//Push value in stack2
    int pop1();//Pop of the stack1
    int pop2();//Pop of the stack2
    int dequeueProcess();//Prcess of dequeue

    int choose, value;

    while (1) {

        printf("\n1. enqueue 2. dequeue 3. view 4.exit : ");
        scanf_s("%d", &choose);

        if (choose == 1) {

            if (queue_full()) {//defensive coding
                printf("Queue is alreay full");
                continue;
            }

            printf("Enqueue value : ");
            scanf_s("%d", &value);

            push1(value);

        }

        else if (choose == 2) {

            if (queue_empty()) {//defensive coding
                printf("Queue is alreay empty");
                continue;
            }

            printf("Dequeue value= %d\n", dequeueProcess());
        }

        else if (choose == 3)
            View();

        else if (choose == 4)
            break;

        else
            printf("error");
    }
    return 0;
}

/*Stack viewer function*/
void View()
{
    int i;

    printf("\nstack1 : ");
    for (i = 0; i <= top1; i++) printf("%d ", stack1[i]);
    printf("\nstack2 : ");
    for (i = 0; i <= top2; i++) printf("%d ", stack2[i]);
    printf("\n");
}

/*Check the queue is full(Queue means two stacks)*/
int queue_full() {
    if (top1 + top2 + 2 == SIZE)//full
        return 1;
    else
        return 0;
}

/*Check the queue is empty(Queue means two stacks)*/
int queue_empty() {
    if (top1 == -1 && top2 == -1)//empty
        return 1;

    else
        return 0;
}

/*Check the stack1 is empty*/
int stack1_empty() {
    if (top1 == -1)
        return 1;
    else
        return 0;
}

/*Check the stack2 is empty*/
int stack2_empty() {
    if (top2 == -1)
        return 1;
    else
        return 0;
}

/*Push value in stack1*/
void push1(int value)
{
    top1++;
    stack1[top1] = value;
}

/*Push value in stack2*/
void push2(int value)
{
    top2++;
    stack2[top2] = value;
}

/*Pop of the stack1*/
int pop1()
{
    int returnValue;

    returnValue = stack1[top1];
    top1--;

    return returnValue;
}

/*Pop of the stack2*/
int pop2()
{
    int returnValue;

    returnValue = stack2[top2];
    top2--;

    return returnValue;
}

/*Prcess of dequeue*/
int dequeueProcess() {

    int returnValue;

    if (stack2_empty()) {//if stack2 is empty

        while (!stack1_empty())//until stack1_empty
            push2(pop1());//move element

    }
    returnValue = pop2();

    return returnValue;
}
