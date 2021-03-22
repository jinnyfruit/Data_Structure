/*
file name: PHW2-1
author: 202035513 Ji Woo Kim
modified: 03.22,2021
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int key;
	struct node* leftChild;
	struct node* rightChild;

}NODE;

struct place {
	struct place* sibling;
	struct place* child;
	int child_key;
	NODE* node;
};
typedef struct place PLACE;

NODE* rootNode;		//root node for a search
PLACE* rootPlace;

int main(void)
{
	void inputNode(int level, int key, int child_key);//Input Node at place
	void viewNode();//ViewNode although place
	void connectNode();//Connct Node by place
	void inputFunction1();//Input Case1
	void inputFunction2();//Input Case2
	void preOrder(NODE * ptr);//Preorder sequence


	inputFunction1();//Enter according to a set rule
	//viewNode();
	connectNode();
	printf("Tree1 : \n");
	preOrder(rootNode);

	inputFunction2();//Enter according to a set rule
	//viewNode();
	connectNode();
	printf("Tree2 : \n");
	preOrder(rootNode);

	return 0;
}

/*Input Node at place*/
void inputNode(int level, int key, int child_key)
{

	PLACE* ptr = rootPlace;
	int l, i;

	PLACE* newPlace = (PLACE*)malloc(sizeof(PLACE));
	newPlace->sibling = NULL;
	newPlace->child = NULL;
	newPlace->child_key = child_key;

	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->key = key;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;

	if (level == 1)
	{
		rootNode = newNode;
		rootPlace = newPlace;
		newPlace->node = newNode;
		return;
	}

	newPlace->node = newNode;

	ptr = rootPlace;
	for (l = 1; l < level; l++)
	{
		if (ptr->child == NULL)
		{
			ptr->child = newPlace;
			return;
		}

		ptr = ptr->child;
	}

	while (ptr)
	{
		if (ptr->sibling == NULL)
		{
			ptr->sibling = newPlace;
			ptr->node->rightChild = newPlace->node;
			return;
		}
		ptr = ptr->sibling;
	}

}

/*ViewNode although place*/
void viewNode()
{
	PLACE* ptrh = rootPlace;
	PLACE* ptrw;

	while (ptrh)
	{
		ptrw = ptrh;

		while (ptrw)
		{
			printf("%d ", ptrw->node->key);
			ptrw = ptrw->sibling;
		}
		printf("\n");
		ptrh = ptrh->child;

	}

}

/*Connct Node by place*/
void connectNode()
{
	PLACE* ptrh = rootPlace, * ptrw, * ptrn, * memory;

	while (ptrh)
	{
		ptrw = ptrh;
		ptrn = ptrh->child;
		memory = NULL;
		while (ptrw)
		{
			if (ptrw->child_key)
			{
				while (ptrn)
				{
					if (ptrw->child_key == ptrn->node->key)
					{
						ptrw->node->leftChild = ptrn->node;

						if (memory)
							memory->node->rightChild = NULL;

						break;
					}
					memory = ptrn;

					ptrn = ptrn->sibling;
				}
			}
			ptrw = ptrw->sibling;
		}

		ptrh = ptrh->child;
	}

}

/*Input Case1*/
void inputFunction1()
{
	inputNode(1, 100, 200);
	inputNode(2, 200, NULL);
	inputNode(2, 75, 25);
	inputNode(2, 300, NULL);
	inputNode(3, 25, NULL);
	inputNode(3, 50, NULL);
	inputNode(3, 30, 120);
	inputNode(3, 150, NULL);
	inputNode(4, 120, NULL);
	inputNode(4, 55, NULL);
}

/*Input Case2*/
void inputFunction2()
{
	inputNode(1, 100, 200);
	inputNode(2, 200, NULL);
	inputNode(2, 75, 25);
	inputNode(2, 300, NULL);
	inputNode(2, 95, 150);
	inputNode(3, 25, NULL);
	inputNode(3, 50, NULL);
	inputNode(3, 30, 120);
	inputNode(3, 150, NULL);
	inputNode(4, 120, NULL);
}

/*Preorder sequence*/
void preOrder(NODE* ptr)
{
	if (ptr)
	{
		printf("%d ", ptr->key);
		preOrder(ptr->leftChild);
		preOrder(ptr->rightChild);
	}
}