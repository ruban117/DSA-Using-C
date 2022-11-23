/*write a c programme to implement Bubble Sort*/
#include<stdio.h>

void Swap(int *x, int *y){
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

void BubbleSort(int arr[], int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				Swap(&arr[j],&arr[j+1]);
			}
		}
	}
}

void PrintArray(int arr[], int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}

int main(){
	int arr[100],i,n;
	printf("Enter The Range Of The Array: ");
	scanf("%d",&n);
	printf("Enter %d Elements: \n",n); 
	for(i=0;i<n;i++){
		printf("Enter arr[%d]: ",i+1);
		scanf("%d",&arr[i]);
	}
	printf("\nThe Elements Are Before Sorted: ");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	BubbleSort(arr,n);
	printf("\nThe Elements Are After Sorted: ");
	PrintArray(arr,n);
}
