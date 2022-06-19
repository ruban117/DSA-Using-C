/*Create an array by using MALLOC()[Memory Allocation Method] Dynamic memory allocation*/
#include<stdio.h>
#include<stdlib.h> //for accessing dma
int main(){
	int *ptr ;/*creating a pointer with respect of return type for accessing malloc*//*or we allocate some memory in ptr*/
	int n;
	printf("Enter The Range Of The Array: ");
	scanf("%d",&n);
	ptr = (int*) malloc(n * sizeof(int));
	for(int i=0 ; i<n ; i++){
		printf("Enter Element %d: ",i+1);
		scanf("%d",&ptr[i]);
	}
	printf("The Elements Are: \n");
	for(int i=0 ; i<n ; i++){
		printf("%d ",ptr[i]);
	}
	return 0;
}