/*Write a c programme to implement the linked list*/
#include<stdio.h>
#include<stdlib.h>

//structure for creating a linked list
struct Node{
	int data;
	struct Node* next;
};

//function to traverse in a linked list

void TraverseInLinkedList(struct Node *ptr){
	printf("The Created Linked List Is In Bellow:::\n\n");
	while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
}

int main(){
	struct Node *head;
	struct Node *second;
	struct Node *third;
	struct Node *fourth;
	
	//Allocate memory location in heap for the all nodes using malloc()
	
	head=(struct Node *)malloc(sizeof(struct Node));
	second=(struct Node *)malloc(sizeof(struct Node));
	third=(struct Node *)malloc(sizeof(struct Node));
	fourth=(struct Node *)malloc(sizeof(struct Node));
	
	//creating first node pointing to second node
	
	head->data=10;
	head->next=second;
	
	//creating second  node pointing to third node
	
	second->data=20;
	second->next=third;
	
	//creating third node pointing to fourth node
	
	third->data=30;
	third->next=fourth;
	
	//creating fourth node pointing to fifth node
	
	fourth->data=40;
	fourth->next=NULL;
	
	TraverseInLinkedList(head);  //calling the traverse function
	
	return 0;
}