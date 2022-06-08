/*programme to declare an array using C(User Input + Traversal)*/
#include<stdio.h>
int main(){
	int arr[100];//creating the array with size
	int i,n;
	printf("Enter The Size Of The Array: ");
	scanf("%d",& n);
	for(i=0;i<n;i++){
		printf("Enter arr[%d]: ",i+1);//array index alawyas starts with 0 so i used i+1
		scanf("%d",&arr[i]);
	}
	printf("The Array Is\n");
	for(i=0;i<n;i++){//loop for traversing the array
		printf("%d ", arr[i]);
	}
	return 0;
}