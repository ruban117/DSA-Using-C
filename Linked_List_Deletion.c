/*Create A Linked List For Performing Delete Operations*/

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

struct Node *DeleteAtBegin(struct Node *head){
	struct Node*p=head;
	head=head->next;
	free(p);
	return head;
}

struct Node*DeleteInBetween(struct Node*head,int key){
	struct Node *p=head;
	struct Node *q=head->next;
	int i=0;
	for(i=0;i<key-1;i++){
		p=p->next;
		q=q->next;
	}
	p->next=q->next;
	free(q);
	return head;
}

struct Node *DeleteAtEnd(struct Node*head){
	struct Node *p=head;
	struct Node *q=head->next;
	while(q->next!=NULL){
		p=p->next;
		q=q->next;
	}
	p->next=NULL;
	free(q);
	return head;
}

struct Node*DeleteByValue(struct Node*head,int data){
	struct Node *p=head;
	struct Node *q=head->next;
	while(q->data!=data && q->next!=NULL){
		p=p->next;
		q=q->next;
	}
	if(q->data==data){
		p->next=q->next;
		free(q);
	}
	else{
		printf("\nNot Into The Linked List!!!!\n");
	}
	return head;
}

int main(){
	int n,data,m,key;
	char ch;
	while(1){
	printf("\nHow Many Nodes You Want To Allocate?: ");
	scanf("%d",&n);
	createlist(n);
	printf("\nDo You Want To Delete Operations[y/n]: ");
	scanf("%s",&ch);
	if(ch=='y' || ch=='Y'){
		printf("\n\n");
		printf("DELETE OPERATIONS IN A LINKED LIST\n");
		printf("1-> To Delete At Begin\n");
		printf("2-> To Delete in between\n");
		printf("3-> To Delete at the end\n");
		printf("4-> To Delete By Value\n");
		printf("\n\nEnter The Case Do You Want: ");
		scanf("%d",&m);
		switch(m){
			case 1:
				printf("Previous Linked List Is: \n");
				TraverseInLinkedList();
				printf("\nLinked List After Deletion: \n");
				head=DeleteAtBegin(head);
				TraverseInLinkedList(head);
				break;
				
			case 2:
				printf("Previous Linked List Is: \n");
				TraverseInLinkedList();
				printf("\nEnter The Index Number You Want To Delete: ");
				scanf("%d",&key);
				printf("\nLinked List After Deletion: \n");
				head=DeleteInBetween(head,key);
				TraverseInLinkedList(head);
				break;
				
			case 3:
				printf("Previous Linked List Is: \n");
				TraverseInLinkedList();
				printf("\nLinked List After Deletion: \n");
				head=DeleteAtEnd(head);
				TraverseInLinkedList(head);
				break;
				
			case 4:
				printf("The Created Linked List Is: \n");
				TraverseInLinkedList();
				printf("\nEnter The Value You Want To Delete: ");
				scanf("%d",&data);
				printf("\nLinked List After Deletion: \n");
				head=DeleteByValue(head,data);
				TraverseInLinkedList(head);
				break;
				
			default :
				TraverseInLinkedList();
			}		
		}
		else{
		TraverseInLinkedList();
	}
		if(ch=='n'){
			break;
		}
	}
	return 0;
}
