#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void CreateStack(struct Node **top){
    *top=NULL;
}

int IsFull(struct Node *top){
    struct Node *p=(struct Node*)malloc(sizeof(struct Node));
    if(p==NULL)
    return 1;
    return 0;
}

int IsEmpty(struct Node *top){
    if(top==NULL)
    return 1;
    return 0;
}

void Push(struct Node **top,int data){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    if(ptr==NULL){
        printf("Unable To Insert Data Into Stack!!!!!");
        return;
    }
    else{
        ptr->data=data;
        ptr->next=*top;
        *top=ptr;
    }
}

int PoP(struct Node **top){
    int temp;
        struct Node *ptr;
        temp=(*top)->data;
        ptr=*top;
        *top=(*top)->next;
        free(ptr);
        return temp;
}

int Peek(struct Node **top){
    if(IsEmpty(*top))
    return 1;
    return ((*top)->data);
}

void TraverseInLL(struct Node *top){
    while(top!=NULL){
        printf("%d ",top->data);
        top=top->next;
    }
}

int main(){
        int a,val,ele;
        struct Node *top;
        CreateStack(&top);
        while (1)
    {
        printf("\n");
        printf("1->To Create A Stack Using LL Linked List\n");
        printf("2->To See The Topest Element\n");
        printf("3->To PoP Elements\n");
        printf("4->Traverse\n");
        printf("Enter Your Choice: ");
        scanf("%d",&a);
        switch(a){
        case 1:
            if(IsFull(top)){
                printf("Stack Overflow");
            }
            
                printf("Enter Value: ");
                scanf("%d",&val);
                Push(&top,val);
            break;
        case 2:
            printf("The Toppest Element Is %d",Peek(&top));
            break;
        case 3:
            if(IsEmpty(top)){
                printf("Stack Underflow");
                exit(0);
            }
            printf("Poped Element Is %d\n",PoP(&top));
            break;
        case 4:
            TraverseInLL(top);
            break;
        }
    }
        return 0;
}