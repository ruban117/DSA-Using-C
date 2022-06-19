/*Create an array by using CALLOC()[Contigous Memory Allocation Method] Dynamic memory allocation*/
#include<stdio.h>
#include<stdlib.h> //for accessing dma
int main(){
	int *ptr ;/*creating a pointer with respect of return type for accessing calloc*//*or we allocate some memory in ptr*/
	int n;
	printf("Enter The Range Of The Array: ");
	scanf("%d",&n);
	ptr = (int*) calloc(n , sizeof(int));
	for(int i=0 ; i<n ; i++){              /*If we do not enter any value then wtr to calloc all the default value will be 0*/
		printf("Enter Element %d: ",i+1);
		scanf("%d",&ptr[i]);
	}
	printf("The Elements Are: \n");
	for(int i=0 ; i<n ; i++){
		printf("%d ",ptr[i]);
	}
	return 0;
}