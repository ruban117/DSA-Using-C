#include<stdio.h>
struct Array_Polynomial
{
    int c;
    int p;
};
struct Array_Polynomial a[50],b[50],r[50];

int CreatePolynomial(struct Array_Polynomial arr[]){
    int n,i;
    printf("Enter The Range Of The Polynomial: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter Co-Officient: ");
        scanf("%d",&arr[i].c);
        printf("Enter Power: ");
        scanf("%d",&arr[i].p);
    }
    return n;
}

int AddPolynomial(int first,int second){
    int i=0,j=0,k=0;
    while(i<first && j<second){
        if(a[i].p == b[j].p){
            r[k].c=a[i].c+b[j].c;
            r[k].p=a[i].p;
            i++;
            j++;
            k++;
        }
        else if(a[i].p > b[j].p){
            r[k].c=a[i].c;
            r[k].p=a[i].p;
            i++;
            k++;
        }
        else{
            r[k].c=b[j].c;
            r[k].p=b[j].p;
            j++;
            k++;
        }
    }
    while(i<first){
        r[k].c=a[i].c;
        r[k].p=a[i].p;
        i++;
        k++;
    }
    while(j<second){
        r[k].c=b[j].c;
        r[k].p=b[j].p;
        j++;
        k++;
    }
    return k;
}

void DisplayPolynomial(struct Array_Polynomial arr[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%dX^%d+ ",arr[i].c,arr[i].p);
    }
}

int main(){
    int first,second,res;
    printf("Getting Input Of 1st Polynomial\n");
    first=CreatePolynomial(a);
    printf("Getting Input Of 2nd Polynomial\n");
    second=CreatePolynomial(b);
    printf("Displaying First Polynomial\n");
    DisplayPolynomial(a,first);
    printf("\n");
    printf("Displaying Second Polynomial\n");
    DisplayPolynomial(b,second);
    printf("\nThe Final Polynomial Is:\n");
    res=AddPolynomial(first,second);
    DisplayPolynomial(r,res);
    return 0;
}
