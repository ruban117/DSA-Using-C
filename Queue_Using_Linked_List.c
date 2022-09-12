#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Queue{
    struct Node *front;
    struct Node *rear;
};

int IsEmpty(struct Queue q){
    if(q.front == NULL && q.rear == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void Enqueue(struct Queue *q, int data){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=NULL;
    if(q->rear == NULL){
        q->front=q->rear=ptr;
    }
    else{
        q->rear->next =ptr;
        q->rear=ptr;
    }
    printf("Node Enqued!");
}

int Dequeue(struct Queue *q){
    int temp=q->front->data;
    if(q->front == q->rear){
        free(q->front);
        q->front = q->rear = NULL;
    }
    else{
        struct Node *p;
        p=q->front;
        q->front=p->next;
        free(p);
    }
    return temp;
}

int PeeK(struct Queue *q){
    return (q->front->data);
}

int main(){
    int a, n;
    struct Queue q;
    q.front = q.rear = NULL;
    while (1)
    {
        printf("\t\t\t M E N U \t\t\t\n");
        printf("\t\t\t <1>To Enqueue Elements Into The Queue \t\t\t\n");
        printf("\t\t\t <2>To Dequeue Elements From The Queue \t\t\t\n");
        printf("\t\t\t <3>To Peek Elements From The Queue \t\t\t\n");
        //printf("\t\t\t <4>To Display Elements From The Queue \t\t\t\n");
        printf("Enter the case you want to do: ");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
                printf("Enter The Element You Want To Enquque: ");
                scanf("%d", &n);
                Enqueue(&q, n);
            break;
        case 2:
            if (IsEmpty(q))
            {
                printf("Queue Underflow!!");
            }
            else
            {
                printf("Element After dequed: %d", Dequeue(&q));
            }
            break;
        case 3:
            if (IsEmpty(q))
            {
                printf("Queue Underflow!!");
            }
            else
            {
                printf("The First Dequed Element is %d", PeeK(&q));
            }
            break;
        /*case 5:
            Display(q);
            break;
        }*/
        default:
            printf("ERROR!");
        }
    }
    return 0;
}