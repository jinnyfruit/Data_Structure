/*
file name:  PHW2-1 (2)
author:202035513 Ji Woo Kim
modified: 03.22,2021
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
    int data;
    struct NODE* left;
    struct NODE* right;
}Node;

Node* root;    //root를 알려주는 ptr
Node* cur_ptr;
Node* down_ptr;    // 자식이 NULL이 아닐 때 부모의 주소 저장했다가 연결
int compare_level;
Node* ptr;

void init();
void newNode(int level, int data, int child_data);
void input1();
void input2();
void Inorder(Node* ptr);
void Postorder(Node* ptr);
void Preorder(Node* ptr);

int main(){
    
    init();     //first input
    input1();

    printf("\nInorder\n");
    Inorder(root);
    printf("\n");
    
    printf("\nPostorder\n");
    Postorder(root);
    printf("\n");

    printf("\nPreorder\n");
    Preorder(root);
    printf("\n");

    init();     //second input
    input2();

    printf("\nInorder\n");
    Inorder(root);
    printf("\n");

    printf("\nPostorder\n");
    Postorder(root);
    printf("\n");

    printf("\nPreorder\n");
    Preorder(root);
    printf("\n");

    return 0;
}

void init(){
    root=NULL;    
    cur_ptr=NULL;
    down_ptr=NULL;    
    compare_level=0;
    ptr=NULL; 
}

void newNode(int level, int data, int child_data){

    Node* new_node = (Node*)malloc(sizeof(Node));   //노드 하나 생성
  
    if(level==1)  {  //root노드일 때
        root = new_node;    //root ptr이 새 노드를 가리키게 만듬
        cur_ptr = new_node;
        new_node->data = data;
        new_node->right=NULL;
        compare_level=1;
        printf("\nroot data:%d\n",root->data);
    }
    else{

        if(cur_ptr==root){  //root의 자식일 때는 
            new_node->data=data;     //일단 데이터 저장
            printf("data:%d\n",new_node->data);
            cur_ptr->left=new_node; //root의 첫번째 자식은 무조건 left
            cur_ptr = new_node; //현재 ptr을 루트에서 첫번째 자식으로 옮겨준다.
            compare_level++;
           
        }
        else{
            if(level==compare_level+1){ //한층 내려갔다면
                down_ptr->left = new_node;  //위층에 자식이 있던 노드와 새로운 층의 첫 자식과 연결
                cur_ptr = new_node; //새층의 새 노드를 cur_ptr로 설정
                compare_level++;    //레벨을 현재 레벨로 맞춰줌 
                new_node ->data = data;
                printf("data:%d\n",new_node->data);
            }
            else{
                new_node ->data = data;
                printf("data:%d\n",new_node->data);
                cur_ptr->right = new_node;  //현 ptr의 right와 연결
                cur_ptr = new_node;   //cur_ptr의 값을 현재 노드의 주소로 바꿔줌
            }

        if(child_data){    //순서와 상관없이 자식이 존재한다면,
            down_ptr=new_node;  //나중에 부모와 연결해야 하기 때문에 부모의 주소값 저장
         }
        }
    }
}

void input1(){
    newNode(1,100,200);
    newNode(2,200,NULL);
    newNode(2,75,25);
    newNode(2,300,NULL);
    newNode(3,25,NULL);
    newNode(3,50,NULL);
    newNode(3,30,120);
    newNode(3,150,NULL);
    newNode(4,120,NULL);
    newNode(4,55,NULL);
}


void input2(){
    newNode(1,100,200);
    newNode(2,200,NULL);
    newNode(2,75,25);
    newNode(2,300,NULL);
    newNode(2,95,150);
    newNode(3,25,NULL);
    newNode(3,50,NULL);
    newNode(3,30,120);
    newNode(3,150,NULL);
    newNode(4,120,NULL);
}

void Inorder(Node* ptr){
    if(ptr) //ptr이 NULL이 아니라면
    {
        Inorder(ptr->left);
        printf("%d\t",ptr->data);
        Inorder(ptr->right);
    }
}

void Postorder(Node* ptr){
    if(ptr)
    {
        Postorder(ptr->left);
        Postorder(ptr->right);
        printf("%d\t",ptr->data);
    }
}

void Preorder(Node* ptr){
    if(ptr)
    {
        printf("%d\t",ptr->data);
        Preorder(ptr->left);
        Preorder(ptr->right);
    }
}