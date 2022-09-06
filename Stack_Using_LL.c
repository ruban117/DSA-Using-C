#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int IsEmpty(struct Node *head)
{
    if (head == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Push(struct Node **head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = *head;
    *head = ptr;
    printf("Element Pushed");
}

int PoP(struct Node **head)
{
    struct Node *p = *head;
    int temp = (*head)->data;
    *head = p->next;
    free(p);
    return temp;
}

int Peek(struct Node **head)
{
    return ((*head)->data);
}

/*void Display(struct Node **head)
{
    struct Node *cur=*head;
    struct Node *prev=NULL;
     while (cur != NULL)
    {
        struct Node *temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    *head = prev;
}*/

void Disp(struct Node *head){
    struct Node *p=head;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

int main()
{
    struct Node *head = NULL;
    while (1)
    {
        printf("\t\t\t\t M E N U \t\t\t\t\n");
        printf("\t\t\t\t<1> To push elements into stack \t\t\t\t\n");
        printf("\t\t\t\t<2> To pop elements from the stack \t\t\t\t\n");
        printf("\t\t\t\t<3> To peek the topest element in the stack \t\t\t\t\n");
        printf("\t\t\t\t<4> To Display elements present in the stack \t\t\t\t\n");
        int a, n;
        printf("Enter The Case You Want To Do: ");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("Enter The Data To Push In Stack: ");
            scanf("%d", &n);
            Push(&head, n);
            break;
        case 2:
            if (IsEmpty(head))
            {
                printf("Stack Underflow!!");
            }
            else
            {
                printf("Poped Element is: %d", PoP(&head));
            }
            break;
        case 3:
            if (IsEmpty(head))
            {
                printf("Stack Underflow!!");
            }
            else
            {
                printf("The Toppest Element Is %d", Peek(&head));
            }
            break;
        case 4:
            //Display(&head);
            Disp(head);
            break;
        default:
            printf("Wrong Input!!!");
        }
    }
    return 0;
}
