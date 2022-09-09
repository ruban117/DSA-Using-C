#include <stdio.h>
#define SIZE 5
struct Queue
{
    int front, rear;
    int arr[SIZE];
};

int IsFull(struct Queue *q)
{
    if (q->rear == SIZE - 1 && q->front == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int IsEmpty(struct Queue *q)
{
    if (q->front == -1 && q->rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Enqueue(struct Queue *q, int data)
{
    int i, j = 0;
    if (q->rear == -1)
    {
        q->front = q->rear = 0;
    }
    else if (q->rear == SIZE - 1 && q->front != 0)
    {
        for (i = q->front; i < SIZE; i++)
        {
            q->arr[j++] = q->arr[i];
        }
        q->front = 0;
        q->rear = j;
    }
    else
    {
        q->rear++;
    }
    q->arr[q->rear] = data;
    printf("Element Enqued!");
}

int Dequeue(struct Queue *q)
{
    int temp;
    temp=q->arr[q->front];
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front++;
        return temp;
    }
}

int PeeK(struct Queue *q)
{
    return q->arr[q->front];
}

/*void Display(struct Queue q){
    int i;
    for(i=q.front;i<=q.rear;i++){
        printf("%d ",q.arr[i]);
    }
}*/

int main()
{
    int a, n;
    struct Queue q;
    q.front = q.rear = -1;
    while (1)
    {
        printf("\t\t\t M E N U \t\t\t\n");
        printf("\t\t\t <1>To Enqueue Elements Into The Queue \t\t\t\n");
        printf("\t\t\t <2>To Dequeue Elements From The Queue \t\t\t\n");
        printf("\t\t\t <3>To Peek Elements From The Queue \t\t\t\n");
        printf("\t\t\t <4>To Display Elements From The Queue \t\t\t\n");
        printf("Enter the case you want to do: ");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            if (IsFull(&q))
            {
                printf("Queue Overflow!");
            }
            else
            {
                printf("Enter The Element You Want To Enquque: ");
                scanf("%d", &n);
                Enqueue(&q, n);
            }
            break;
        case 2:
            if (IsEmpty(&q))
            {
                printf("Queue Underflow!!");
            }
            else
            {
                printf("Element After dequed: %d", Dequeue(&q));
            }
            break;
        case 3:
            if (IsEmpty(&q))
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
