#include<stdio.h>
#include<stdlib.h>
struct Stack{

    int capacity;
    int top;
    int * arr;
};

struct Stack* CreateStack(int capacity){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity= capacity;
    stack->top = -1;
    stack->arr = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int IsEmpty(struct Stack *ptr){
    if(ptr->top==-1)
    return 1;
    return 0;
}

int IsFull(struct Stack *ptr){
    if(ptr->top==ptr->capacity-1)
    return 1;
    return 0;
}

void Push(struct Stack *ptr,int val){
    if(IsFull(ptr))
    printf("Stack Overflow");
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}

int Pop(struct Stack *ptr){
    if(IsEmpty(ptr)){
    printf("Stack Underflow!!!!");
    return -1;
    }
    else{
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int Peek(struct Stack *ptr){
    if(IsEmpty(ptr)){
        printf("Stack Underflow!!!!");
        return -1;
    }
        return (ptr->arr[ptr->top]);
}

int main(){
    struct Stack *sp=CreateStack(50);
    int i,a;
    printf("Enter The Size Of The Stack: ");
    scanf("%d",&a);
    printf("Creating Your Stack:::\n");
    sp=CreateStack(a);
    for(i=0;i<sp->capacity;i++){
        printf("Enter Stack Value At Pos %d: ",i);
        scanf("%d",&a);
        Push(sp,a);
    }
    printf("\nThe Topmost Element Is Into The Stack:");
    printf("%d ",Peek(sp));

    printf("\nThe Values Are Into The Stack:::\n");
    for(i=0;i<sp->capacity;i++){
        printf("%d ",Pop(sp));
    }
    return 0;
}