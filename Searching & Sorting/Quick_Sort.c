/*write a c programme to implement Quick Sort*/
#include<stdio.h>

void Swap(int *x, int *y){
	int temp=*x;
	*x=*y;
	*y=temp;	
}

int Partition(int arr[], int lb, int ub){
	int start,end,pivot;
	pivot=arr[lb];
	start=lb;
	end=ub;
	while(start<end){
		while(arr[start]<=pivot)
			start++;
		while(arr[end]>pivot)
			end--;
		if(start < end)
			Swap(&arr[start], &arr[end]);
	}
		Swap(&arr[lb],&arr[end]);
		return end;	
}

void QuickSort(int arr[], int lb,int ub){
	int loc;
	if(lb<ub){
		loc=Partition(arr,lb,ub);
		QuickSort(arr,lb,loc-1);
		QuickSort(arr,loc+1,ub);
	}
}

void PrintArray(int arr[], int size){
	int i;
	printf("\nThe Array Is After Quicksort: ");
	for(i=0;i<size;i++){
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
	QuickSort(arr,0,n-1);
	printf("\nThe Elements Are After Sorted: ");
	PrintArray(arr,n);
}
