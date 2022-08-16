#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

void TraverseCircularLinkedList(struct Node *head)
{
	if (head == NULL)
	{
		printf("Your List Is Empty!!!");
		printf("\n");
	}
	else
	{
		struct Node *p = head;
		printf("\nYour Created Linked List Is In Bellow::::\n");
		do
		{
			printf("%d ", p->data);
			p = p->next;
		} while (p != head);
		printf("\n\n");
	}
}

void InsertAtBeg(struct Node **head, int val)
{
	struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
	struct Node *p;
	ptr->data = val;
	if (ptr == NULL)
	{
		printf("Unable To Create");
	}
	else if (*head == NULL)
	{
		ptr->next = ptr;
		*head = ptr;
	}
	else
	{
		p = *head;
		while (p->next != *head)
		{
			p = p->next;
		}
		p->next = ptr;
		ptr->next = *head;
		*head = ptr;
	}
}

void InsertAtEnd(struct Node **head, int val)
{
	struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
	struct Node *p;
	ptr->data = val;
	if (ptr == NULL)
	{
		printf("Unable To Create");
	}
	else if (*head == NULL)
	{
		ptr->next = ptr;
		*head = ptr;
	}
	else
	{
		p = *head;
		while (p->next != *head)
		{
			p = p->next;
		}
		p->next = ptr;
		ptr->next = *head;
	}
}

void InsertAtPosInCricular(struct Node **head, int pos, int val)
{
	struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
	struct Node *p = *head;
	int i;
	ptr->data = val;
	if (ptr == NULL)
	{
		printf("Unable To Create");
	}
	else if (*head == NULL)
	{
		printf("You Have To Create At Least A Linked List");
		exit(0);
	}
	else if (*head == NULL && pos == 1)
	{
		ptr->next = ptr;
		*head = ptr;
	}
	else if (pos == 1)
	{
		while (p->next != *head)
		{
			p = p->next;
		}
		p->next = ptr;
		ptr->next = *head;
		ptr = *head;
	}
	else
	{
		{
			for (i = 1; i < pos - 1; i++)
			{
				p = p->next;
			}
			ptr->next = p->next;
			p->next = ptr;
		}
	}
}

void DeleteFirstPositionInSinglyCircular(struct Node **head)
{
	struct Node *p = *head;
	if (*head == NULL)
	{
		printf("Unable to delete!!");
	}
	else if (p->next == *head)
	{
		*head = NULL;
		free(*head);
	}
	else
	{
		while (p->next != *head)
		{
			p = p->next;
		}
		p->next = (*head)->next;
		free(*head);
		*head = p->next;
	}
}

void DeleteLastPositionInSinglyCircular(struct Node **head)
{
	struct Node *lastnode = *head;
	struct Node *prelastnode;
	if (*head == NULL)
	{
		printf("Unable to delete!!");
	}
	else if ((*head)->next == *head)
	{
		*head = NULL;
		free(*head);
	}
	else
	{
		while (lastnode->next != *head)
		{
			prelastnode = lastnode;
			lastnode = lastnode->next;
		}
		prelastnode->next = lastnode->next;
		free(lastnode);
	}
}

void DeleteNthPositionInSinglyCircular(struct Node **head, int pos)
{
	struct Node *p = *head;
	struct Node *q = (*head)->next;
	int i;
	if (*head == NULL)
	{
		printf("Unable to delete!!");
	}
	else if ((*head)->next == *head)
	{
		*head = NULL;
		free(*head);
	}
	else
	{
		for (i = 1; i < pos - 1; i++)
		{
			p = p->next;
			q = q->next;
		}
		p->next = q->next;
		free(q);
	}
}

int main()
{
	struct Node *head = NULL;
	while (1)
	{
		printf("\t\t\t\t\tCIRCULAR LINKED LIST\n\n");
		printf("\t\t\t\t1->Create A Circular Linked List: \n");
		printf("\t\t\t\t2->Insert At Beginning To The Circular Linked List: \n");
		printf("\t\t\t\t3->Insert At Last To The Circular Linked List: \n");
		printf("\t\t\t\t4->Insert At Position To The Circular Linked List: \n");
		printf("\t\t\t\t5->Traverse Circular Linked List: \n");
		printf("\t\t\t\t6->Delete At First PositionTo The Circular Linked List: \n");
		printf("\t\t\t\t7->Delete At Last Position To The Circular Linked List: \n");
		printf("\t\t\t\t8->Delete By Position In Circular Linked List: \n");
		int a, num, val;
		char ch;
		printf("Enter Your Choice: ");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			printf("Enter Value: ");
			scanf("%d", &num);
			InsertAtEnd(&head, num);
			break;
		case 2:
			printf("Enter The Value You Want To Insert At Begin: ");
			scanf("%d", &num);
			InsertAtBeg(&head, num);
			break;
		case 3:
			printf("Enter Value: ");
			scanf("%d", &num);
			InsertAtEnd(&head, num);
			break;
		case 4:
			printf("Enter The Position You Want To Insert: ");
			scanf("%d", &num);
			printf("Enter The Value You Want To Insert: ");
			scanf("%d", &val);
			InsertAtPosInCricular(&head, num, val);
			break;
		case 5:
			if (head == NULL)
				printf("Empty List");
			else
				TraverseCircularLinkedList(head);
			break;
		case 6:
			printf("The Circular List Is (Before Deletion):\n");
			TraverseCircularLinkedList(head);
			printf("The Circular List Is (After Deletion):\n");
			DeleteFirstPositionInSinglyCircular(&head);
			TraverseCircularLinkedList(head);
			break;
		case 7:
			printf("The Circular List Is (Before Deletion):\n");
			TraverseCircularLinkedList(head);
			printf("The Circular List Is (After Deletion):\n");
			DeleteLastPositionInSinglyCircular(&head);
			TraverseCircularLinkedList(head);
			break;
		case 8:
			TraverseCircularLinkedList(head);
			printf("Enter The Position You Want To Insert: ");
			scanf("%d", &num);
			DeleteNthPositionInSinglyCircular(&head, num);
			TraverseCircularLinkedList(head);
			break;
		default:
			TraverseCircularLinkedList(head);
		}
		printf("Do You Want To Stop?: ");
		scanf("%s", &ch);
		if (ch == 'b' || ch == 'B')
			break;
	}
	return 0;
}
