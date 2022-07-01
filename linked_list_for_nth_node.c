#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *next;
}*head;

void createlist(int n){
	struct Node *newnode,*temp;
	int data,i;
	head=(struct Node*)malloc(sizeof(struct Node));
	if(head==NULL){
		printf("Unable To Allocate Memory");
		exit(0);
	}
	printf("Enter the data of node 1: ");
    scanf("%d", &data);
	head->data=data;
	head->next=NULL;
	temp=head;
	for(i=2;i<=n;i++){
		newnode=(struct Node*)malloc(sizeof(struct Node));
		if(newnode==NULL){
		printf("Unable To Allocate Memory");
		exit(0);
	}
	printf("Enter the data of node %d: ",i);
	scanf("%d",&data);
	newnode->data=data;
	newnode->next=NULL;
	temp->next=newnode;
	temp=temp->next;
	}
}

void TraverseInLinkedList(){
	struct Node *ptr;
	printf("The Created List Is In Bellow:\n\n");
	ptr=head;
	while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
}

int main(){
	int n;
	printf("How Many Nodes You Want To Allocate?: ");
	scanf("%d",&n);
	createlist(n);
	TraverseInLinkedList();
	return 0;
}
