/*Write a c programme to implement Binary Search*/

#include<stdio.h>
int Binary_Search(int arr[], int n, int key){
	int beg,end,mid;
	beg=0;
	end=n-1;
	mid=(beg + end)/2;
	while((beg<=end)&&(arr[mid]!=key)){
		if(key<arr[mid]){
			end=mid-1;
		}
		else
			beg=mid+1;
			mid=(beg+end)/2;
	}
	if(beg>end){
		return -1;
	}
	else
	return mid;	
}

int main(){
	int arr[100],i,n,key,x;
	printf("Enter The Range Of The Array: ");
	scanf("%d",&n);
	printf("Enter %d Elements: \n",n); 
	for(i=0;i<n;i++){
		printf("Enter arr[%d]: ",i+1);
		scanf("%d",&arr[i]);
	}
	printf("\nThe Elements Are: ");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\nEnter The Element You Want To Search: ");
	scanf("%d",&key);
	x=Binary_Search(arr,n,key);
	if(x == -1){
		printf("Not Found!");
	}
	else{
		printf("The Element %d Is Found At Pos %d",key,x);
	}
}
	
