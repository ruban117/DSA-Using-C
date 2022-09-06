#include <stdio.h>
#define size 5

struct Stack
{
    int top;
    int arr[size];
};

int IsEmpty(struct Stack s)
{
    if (s.top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int IsFull(struct Stack s)
{
    if (s.top == size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Push(struct Stack *s, int data)
{
    s->top++;
    s->arr[s->top] = data;
    printf("Element Pushed!");
}

int PoP(struct Stack *s)
{
    int val;
    val = s->arr[s->top];
    s->top--;
    return val;
}

void Display(struct Stack s)
{
    for (int i = 0; i <= s.top; i++)
    {
        printf("%d ", s.arr[i]);
    }
}

int Peek(struct Stack *s)
{
    return (s->arr[s->top]);
}

int main()
{
    struct Stack s;
    s.top = -1;
    int n, a;
    while (1)
    {
        printf("\t\t\t\t M E N U \t\t\t\t\n");
        printf("\t\t\t\t<1> To push elements into stack \t\t\t\t\n");
        printf("\t\t\t\t<2> To pop elements from the stack \t\t\t\t\n");
        printf("\t\t\t\t<3> To peek the topest element in the stack \t\t\t\t\n");
        printf("\t\t\t\t<4> To Display elements present in the stack \t\t\t\t\n");
        printf("Enter The Case You Want To Do: ");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            if (IsFull(s))
            {
                printf("Stack Overflow");
            }
            else
            {
                printf("Enter The Data To Push In Stack: ");
                scanf("%d", &n);
                Push(&s, n);
            }
            break;
        case 2:
            if (IsEmpty(s))
            {
                printf("Stack Underflow!!");
            }
            else
            {
                printf("Poped Element is: %d", PoP(&s));
            }
            break;
        case 3:
            if (IsEmpty(s))
            {
                printf("Stack Underflow!!");
            }
            else
            {
                printf("The Toppest Element Is %d", Peek(&s));
            }
            break;
        case 4:
            printf("The Elements Are::;\n\n");
            Display(s);
            break;
        default :
            printf("Wrong Input!!");
        }
    }
    return 0;
}
