/*Write a c programme to implement Insertion Sort*/
#include<stdio.h>

void InsertionSort(int arr[], int n){
	int i,j,temp;
	for(i=1;i<n;i++){
		temp=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>=temp){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;
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
	InsertionSort(arr,n);
	printf("\nThe Elements Are After Sorted: ");
	PrintArray(arr,n);
}
