/*Implementing Array As ADT*/
#include<stdio.h>
#include<stdlib.h>
struct myArray{
	int total_size;
	int used_size;
	int *ptr;
};

void createarray(struct myArray * a,int tSize, int uSize){
	a->total_size=tSize;
	a->used_size=uSize;
	a->ptr=(int*)malloc(tSize * sizeof(int));
}

void setVal(struct myArray * a){
	for(int i=0 ;i<a->used_size ; i++){
		printf("Enter the element %d: ",i+1);
		scanf("%d",&(a->ptr)[i]);
	}
}

void showVal(struct myArray * a){
	for(int i=0 ;i<a->used_size ; i++){
		printf("%d ",(a->ptr)[i]);
	}
}

int main(){
	struct myArray adt;
	printf("Enter the total size of the array: ");
	scanf("%d",&adt.total_size);
	printf("Enter the used size of the array: ");
	scanf("%d",&adt.used_size);
	createarray(&adt , adt.total_size, adt.used_size);
	printf("We Are In Set Stage Now!!\n");
	setVal(&adt);
	printf("\nThe Elements Are:\n");
	showVal(&adt);
	return 0;
}