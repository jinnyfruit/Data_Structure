 #include <stdio.h>

#define SIZE 10

int queue1[SIZE], queue2[SIZE];
int front1 = -1, rear1 = -1, front2 = -1, rear2 = -1;

int main(void)
{
	void view();//Stack viewer function
	int stack_full();//Check the stack is full(Stack means two queue)
	int stack_empty();//Check the stack is empty(Stack means two queue)
	int queue2_empty();//Check the queue1 is empty*/
	void enqueue1(int value);//Enqueue value in queue1
	void enqueue2(int value);//Enqueue value in queue2
	int dequeue1();//Dequeue of the queue1
	int dequeue2();//Dequeue of the queue2
	int popProcess();//Process of pop

	int choose, value;

	while (1) {

		printf("\n1. push 2. pop 3. view 4.exit : ");
		scanf("%d", &choose);

		if (choose == 1) {

			if (stack_full()) {//defensive coding
				printf("Stack is alreay full");
				continue;
			}

			printf("Push value : ");
			scanf("%d", &value);
			 
			enqueue1(value);//insert value to queue1
		}

		else if (choose == 2) {

			if (stack_empty()) {//defensive coding
				printf("Stack is alreay empty");
				continue;
			}

			printf("%d", popProcess());
		}

		else if (choose == 3)
			view();

		else if (choose == 4)
			break;

		else
			printf("error");
	}
}

/*Stack viewer function*/
void view()
{
	int i;

	for (i = front1; i <= rear1; i++)
		printf("%d ", queue1[i]);
	printf("\n");
}

/*Check the stack is full(Stack means two queue)*/
int stack_full()
{
	if (rear1 - front1 == SIZE - 1)
		return 1;

	else
		return 0;
}

/*Check the stack is empty(Stack means two queue)*/
int stack_empty()
{
	if (front1 > rear1 || front1 == -1)//no data Or first time
		return 1;

	else
		return 0;
}

/*Check the queue1 is empty*/
int queue2_empty()
{
	if (front2 > rear2 || front2 == -1)//no data Or first time
		return 1;

	else
		return 0;
}

/*Enqueue value in queue1*/
void enqueue1(int value)
{
	rear1++;

	if (front1 == -1)//first time insert of queue
		front1++;

	queue1[rear1] = value;
}

/*Enqueue value in queue2*/
void enqueue2(int value)
{
	rear2++;

	if (front2 == -1)//first time insert of queue
		front2++;

	queue2[rear2] = value;
}

/*Dequeue of the queue1*/
int dequeue1()
{
	int returnValue;

	returnValue = queue1[front1];

	front1++;
	return returnValue;
}

/*Dequeue of the queue2*/
int dequeue2()
{
	int returnValue;

	returnValue = queue2[front2];

	front2++;
	return returnValue;
}

/*Process of pop*/
int popProcess()
{
	int returnValue;

	while (front1 != rear1)//instead queue1_empty()-1
		enqueue2(dequeue1());

	returnValue = dequeue1();

	while (!queue2_empty())
		enqueue1(dequeue2());//queue2 pop and push in queue1

	return returnValue;
}