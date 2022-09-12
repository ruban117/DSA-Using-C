#include<stdio.h>

#define SIZE 5

typedef struct Circular_Queue{
    int front,rear;
    int arr[SIZE];
}Circular_Queue;

int IsFull(Circular_Queue q){
    if((q.front == 0 && q.rear == SIZE-1) ||(q.front==q.rear+1)){
        return 1;
    }
    else{
        return 0;
    }
}

int IsEmpty(Circular_Queue q){
    if(q.front== -1 && q.rear == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void Enqueue(Circular_Queue *q, int data){
    if(q->rear==-1){
        q->front=q->rear=0;
    }
    else if(q->rear == SIZE-1 && q->front !=0){
        q->rear=0;
    }
    else{
        q->rear++;
    }
    q->arr[q->rear]=data;
    printf("Element Enqued!");
}

int Dequeue(Circular_Queue *q){
    int temp;
    temp=q->arr[q->front];
    if(q->front == q->rear){
        q->front=q->rear=-1;
    }
    else if(q->front == SIZE-1){
        q->front=0;
    }
    else{
        q->front++;
    }
    return temp;
}

int PeeK(Circular_Queue *q){
    return(q->arr[q->front]);
}

int main(){
     int a, n;
    Circular_Queue q;
    q.front = q.rear = -1;
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
            if (IsFull(q))
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