/*Write a c programme to implement selection sort*/
#include<stdio.h>

void Swap(int *x, int *y){
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

void SelectionSort(int arr[],int n){
	int i,j,pos,min;
	for(i=0;i<n-1;i++){
		min=arr[i];
		pos=i;
		for(j=i+1;j<n;j++){
			if(arr[j]<min){
				min=arr[j];
				pos =j;
			}
		}
		if(pos!=j){
			Swap(&arr[i],&arr[pos]);
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
	SelectionSort(arr,n);
	printf("\nThe Elements Are After Sorted: ");
	PrintArray(arr,n);
}
