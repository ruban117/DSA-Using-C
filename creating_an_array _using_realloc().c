/*Create an array by using REALLOC()[Re_Allocation Method] Dynamic memory allocation*/
#include<stdio.h>
#include<stdlib.h> //for accessing dma
int main(){
	int *ptr ;/*creating a pointer with respect of return type for accessing malloc*//*or we allocate some memory in ptr*/
	int n,m;
	char ch;
	printf("Enter The Range Of The Array: ");
	scanf("%d",&n);
	ptr = (int*) malloc(n * sizeof(int));
	for(int i=0 ; i<n ; i++){
		printf("Enter Element %d: ",i+1);
		scanf("%d",&ptr[i]);
	}
	printf("Do You Want To Add More Elements?: ");
	scanf("%s",&ch);
	if(ch=='y'|| ch=='Y'){
	printf("Enter Ading Elements: ");
	scanf("%d",&m);
	ptr=realloc(ptr , m+n * sizeof(int));/*reallocate ptr using realloc()*/
	for(int i=n ; i<m+n ; i++){
		printf("Enter Element %d: ",i+1);
		scanf("%d",&ptr[i]);
	}
	printf("The Elements Are: \n");
	for(int i=0 ; i<n+m ; i++){
		printf("%d ",ptr[i]);
	}
}
else
{
	printf("The Elements Are: \n");
	for(int i=0 ; i<n ; i++){
		printf("%d ",ptr[i]);
	}
}
	return 0;
}
