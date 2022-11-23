/*write a programme to sort an element using merge sort*/
#include<stdio.h>
#define MAX 7

void Merge(int arr[], int mid, int lb, int ub){
	int i,j,k,brr[MAX];
	i=lb;
	j=mid+1;
	k=lb;
	while(i<=mid && j<=ub){
		if(arr[i]<=arr[j]){
			brr[k]=arr[i];
			i++;
			k++;
		}
		else{
			brr[k]=arr[j];
			j++;
			k++;
		}
	}
	if(i>mid){
		while(j<=ub){
			brr[k]=arr[j];
			k++;
			j++;
		}
	}
	else{
		while(i<=mid){
			brr[k]=arr[i];
			i++;
			k++;
		}
	}
	for(k=lb;k<=ub;k++){
		arr[k]=brr[k];
	}
}

void MergeSort(int arr[], int lb, int ub){
	int mid;
	if(lb<ub){
		mid=(lb+ub)/2;
		MergeSort(arr,lb,mid);
		MergeSort(arr,mid+1,ub);
		Merge(arr,mid,lb,ub);
	}
}

void PrintArray(int arr[], int n){
	int i;
	printf("\nThe Array Is After Sorted: ");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}
int main(){
	int arr[MAX],i;
	printf("\nEnter The Number Of The Elements: \n");
	for(i=0;i<MAX;i++){
		printf("Enter arr[%d]: ",i+1);
		scanf("%d",&arr[i]);
	}
	printf("\nThe Elements Are (After Sorted): ");
	for(i=0;i<MAX;i++){
		printf("%d ",arr[i]);
	}
	MergeSort(arr,0,MAX-1);
	PrintArray(arr,MAX);
}
