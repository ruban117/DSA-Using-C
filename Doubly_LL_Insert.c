#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next, *prev;
};

void InsertAtBegin(struct Node **head, int data)
{
    // struct Node *p=*head;
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = *head;
    if (*head != NULL)
        (*head)->prev = ptr;
    *head = ptr;
}

void InsertAtEnd(struct Node **head, int data)
{
    struct Node *p;
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    if (*head == NULL)
    {
        ptr->prev = NULL;
        ptr->next = NULL;
        *head = ptr;
    }
    else
    {
        p = *head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = ptr;
        ptr->prev = p;
        ptr->next = NULL;
    }
}

void InsertAtPos(struct Node **head, int data, int pos)
{
    struct Node *p;
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    if (pos == 1)
    {
        ptr->data = data;
        ptr->prev = NULL;
        ptr->next = *head;
        if (*head != NULL)
            (*head)->prev = ptr;
        *head = ptr;
    }
    else
    {
        p = *head;
        for (int i = 1; i < pos - 1; i++)
        {
            p = p->next;
        }
        ptr->next = p->next;
        if (p->next != NULL)
        {
            p->next->prev = ptr;
        }
        p->next = ptr;
        ptr->prev = p;
    }
}

void InsertAfterNode(struct Node **head, int pos, int data)
{
    struct Node *p = *head;
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    while (p->data != pos && p->next != NULL)
    {
        p = p->next;
    }
    if (p->data == pos)
    {
        ptr->next = p->next;
        if (p->next != NULL)
        {
            p->next->prev = ptr;
        }
        p->next = ptr;
        ptr->prev = p;
    }
}

void DeleteAtBegin(struct Node **head)
{
    struct Node *p = *head;
    if (*head == NULL)
    {
        printf("Invalid!!");
    }
    else
    {
        if (p->next != NULL)
            p->next->prev = NULL;
        *head = p->next;
        free(p);
    }
}

void DeleteAtLast(struct Node **head)
{
    if (*head == NULL)
    {
        printf("Invalid!!");
    }
    else if ((*head)->next == NULL)
    {
        *head = NULL;
        free(*head);
    }
    else
    {
        struct Node *p = *head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->prev->next = NULL;
        free(p);
    }
}

void DeleteByNthNode(struct Node **head, int pos)
{
    struct Node *p = *head;
    struct Node *q;
    if (*head == NULL)
    {
        printf("Invalid!!");
    }
    else if (pos == 1)
    {
        *head = p->next;
        free(p);
        if (*head != NULL)
        {
            (*head)->prev = NULL;
        }
    }
    else
    {
        for (int i = 1; i <= pos - 1; i++)
        {
            p = p->next;
            // q = q->next;
        }
        p->prev->next = p->next;
        if (p->next != NULL)
            p->next->prev = p->prev;
        free(p);
    }
}

void DeleteByValue(struct Node **head, int val)
{
    struct Node *p = *head;
    struct Node *q;
    if (*head == NULL)
    {
        printf("Invalid!!");
    }
    else if (val == p->data)
    {
        *head = p->next;
        free(p);
        if (*head != NULL)
        {
            (*head)->prev = NULL;
        }
    }
    else
    {
        while (p->data != val && p->next != NULL)
        {
            p = p->next;
            // q = q->next;
        }
        if (p->data == val)
        {
            p->prev->next = p->next;
            if (p->next != NULL)
                p->next->prev = p->prev;
            free(p);
        }
        else
        {
            printf("Elemet Not Found");
        }
    }
}

void ReverseDoubly(struct Node *head)
{
    while(head->next !=NULL){
        head=head->next;
    }
    while(head !=NULL){
        printf("%d ",head->data);
        head=head->prev;
    }
}

void Display(struct Node *head)
{
    if (head == NULL)
    {
        printf("Here Is Not Any Head!!!");
    }
    else
    {
        struct Node *p = head;
        while (p != NULL)
        {
            printf("%d ", p->data);
            p = p->next;
        }
    }
}

int main()
{
    struct Node *head = NULL;
    while (1)
    {
        printf("\n");
        printf("\t\t\t\t\t\t\t1->To Create A Doubly Linked List\n");
        printf("\t\t\t\t\t\t\t2->Insert At Begin In Doubly Linked List\n");
        printf("\t\t\t\t\t\t\t3->Insert At End In Doubly Linked List\n");
        printf("\t\t\t\t\t\t\t4->Traverse In Doubly Linked List\n");
        printf("\t\t\t\t\t\t\t5->Insert After Node In Doubly Linked List:\n");
        printf("\t\t\t\t\t\t\t6->Insert At Position In Doubly Linked List\n");
        printf("\t\t\t\t\t\t\t->->->->->->->->->->->->->->->\n");
        printf("\t\t\t\t\t\t\t7->Delete At Begin In Doubly Linked List\n");
        printf("\t\t\t\t\t\t\t8->Delete By Nth Node In Doubly Linked List:\n");
        printf("\t\t\t\t\t\t\t9->Delete The Node By Value In Doubly Linked List:\n");
        printf("\t\t\t\t\t\t\t10->Delete The Last Node In Doubly Linked List:\n");
        printf("\t\t\t\t\t\t\t->->->->->->->->->->->->->->->\n");
        printf("\t\t\t\t\t\t\t11->Reverse The Linked List In Doubly Linked List:\n");
        printf("\t\t\t\t\t\t\t->->->->->->->->->->->->->->->\n");
        printf("\t\t\t\t\t\t\tEnter C or c To Continue In Doubly Linked List: \n");
        printf("\t\t\t\t\t\t\tEnter B or b To Stop In Doubly Linked List: \n");
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
            // ReverseLinkedList(&head);
            break;
        case 2:
            printf("Enter The Value You Want To Insert At Begin: ");
            scanf("%d", &num);
            InsertAtBegin(&head, num);
            break;
        case 3:
            printf("Enter Value: ");
            scanf("%d", &num);
            InsertAtEnd(&head, num);
            break;
        case 4:
            if (head == NULL)
                printf("Empty List");
            else
                Display(head);
            break;
        case 5:
            Display(head);
            printf("\nEnter The Element You Want To Insert After: ");
            scanf("%d", &num);
            printf("Enter The Value: ");
            scanf("%d", &val);
            InsertAfterNode(&head, num, val);
            break;
        case 6:
            Display(head);
            printf("\nEnter the pos you want to insert a element: ");
            scanf("%d", &num);
            printf("Enter the Value: ");
            scanf("%d", &val);
            InsertAtPos(&head, val, num);
            break;
        case 7:
            Display(head);
            printf("\nThe Linked List Is After Delete The First Node->->->->\n");
            DeleteAtBegin(&head);
            Display(head);
            break;
        case 8:
            Display(head);
            printf("Enter The Node Pos You Want To Delete?: ");
            scanf("%d", &num);
            DeleteByNthNode(&head, num);
            Display(head);
            break;
        case 9:
            Display(head);
            printf("Enter The Node Value(Must Be Present Into The List) You Want To Delete?: ");
            scanf("%d", &num);
            DeleteByValue(&head, num);
            Display(head);
            break;
        case 10:
            Display(head);
            printf("\nThe Linked List Is After Delete The Last Node->->->->\n");
            DeleteAtLast(&head);
            Display(head);
            break;
        case 11:
            Display(head);
            printf("\nThe Linked List Is After Reverse->->->->\n");
            ReverseDoubly(head);
            break;
        default:
            Display(head);
        }
        printf("\nDo You Want To Stop?: ");
        scanf("%s", &ch);
        if (ch == 'b' || ch == 'B')
            break;
    }
    return 0;
}
