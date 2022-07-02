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

struct Node * InsertAtBegin(struct Node *head,int data){
	struct Node *p=(struct Node*)malloc(sizeof(struct Node));
	p->next=head;
	p->data=data;
	return p;
}

struct Node * InsertAtIndex(struct Node *head,int data, int key){
	struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
	struct Node *p=head;
	int i=0;
	while (i != (key-1)){
		p=p->next;
		i++;
	}
	ptr->data=data;
	ptr->next=p->next;
	p->next=ptr;
	return head;
}

struct Node *InsertAtEnd(struct Node *head,int data){
	struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
	struct Node *p=head;
	while(p->next != NULL){
		p=p->next;
	}
	ptr->data=data;
	p->next=ptr;
	ptr->next=NULL;
	return head;
}

struct Node *InsertAfter(struct Node *head,struct Node *prev,int data){
	struct Node * ptr=(struct Node*)malloc(sizeof(struct Node));
	ptr->next=prev->next;
	prev->next=ptr;
	return head;
}

int main(){
	int n,data,m,key;
	char ch;
	printf("How Many Nodes You Want To Allocate?: ");
	scanf("%d",&n);
	createlist(n);
	printf("\nDo You Want To Insert Operations[y/n]: ");
	scanf("%s",&ch);
	if(ch=='y' || ch=='Y'){
		printf("\n\n");
		printf("INSERT OPERATIONS IN A LINKED LIST\n");
		printf("1-> To Insert At Begin\n");
		printf("2-> To Insert in between\n");
		printf("3-> To Insert at the end\n");
		printf("\n\nEnter The Case Do You Want: ");
		scanf("%d",&m);
		switch(m){
			case 1:
			printf("\nEnter The Data You Want To Insert At Begin: ");
			scanf("%d",&data);
			head=InsertAtBegin(head,data);
			TraverseInLinkedList(head);
			break;
			case 2:
				printf("\nEnter The Index Number You Want To Insert: ");
				scanf("%d",&key);
				printf("\nEnter The Data You Want To Insert With Respect To The Index: ");
				scanf("%d",&data);
				head=InsertAtIndex(head,data,key);
				TraverseInLinkedList(head);
				break;
			case 3:
				printf("\nEnter The Data You Want To Insert At End: ");
				scanf("%d",&data);
				head=InsertAtEnd(head,data);
				TraverseInLinkedList(head);
				break;
			default :
				TraverseInLinkedList();
			}
	}
	else{
		TraverseInLinkedList();
	}
	
	return 0;
}
