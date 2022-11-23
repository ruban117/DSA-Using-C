/*write a programme to implement Linier Search*/
#include<stdio.h>

int LinierSearch(int arr[], int key, int n){
	int i;
	for(i=0;i<n;i++){
		if(arr[i] == key)
		return i;
	}
	return -1;
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
	x=LinierSearch(arr,key,n);
	if(x<0){
		printf("Not Found!");
	}
	else{
		printf("The Element %d Is Found At Pos %d",key,x);
	}
}
