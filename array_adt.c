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

void InsertArray(struct myArray * a, int key , int num){
	printf("\nEnter the position you want to insert: ");
	scanf("%d",&key);
	printf("\nEnter the number You want to insert: ");
	scanf("%d",&num);
	int j=a->total_size;
	a->used_size=a->used_size+1;
	while(j >= key){
		(a->ptr)[j+1]=(a->ptr)[j];
		j--;
	}
	(a->ptr)[key-1]=num;
	for(int i=0;i<a->used_size-1;i++){
		printf("%d ",(a->ptr)[i]);
	}
}

void DeleteArray(struct myArray * a, int key){
	printf("\nEnter the position you want to delete: ");
	scanf("%d",&key);
	int j=key;
	while(j < a->used_size){
		(a->ptr)[j-1]=(a->ptr)[j];
		j++;
	}
	a->used_size=a->used_size-1;
	for(int i=0;i<a->used_size-1;i++){
		printf("%d ",(a->ptr)[i]);
	}
}

void update(struct myArray * a ,int key ,int num){
	printf("\nEnter the position you want to update: ");
	scanf("%d",&key);
	printf("\nEnter the number You want to insert: ");
	scanf("%d",&num);
	(a->ptr)[key-1]=num;
	for(int i=0;i<a->used_size-1;i++){
		printf("%d ",(a->ptr)[i]);
	}
}

int main(){
	struct myArray adt;
	int key, num;
	char ch;
	printf("Enter the total size of the array: ");
	scanf("%d",&adt.total_size);
	printf("Enter the used size of the array: ");
	scanf("%d",&adt.used_size);
	createarray(&adt , adt.total_size, adt.used_size);
	printf("We Are In Set Stage Now!!\n");
	setVal(&adt);
	printf("\nThe Elements Are:\n");
	showVal(&adt);
	printf("\nDo You Want To Insert?[y/n]: ");
	scanf("%s",&ch);
	if(ch=='y'|| ch=='Y'){
	InsertArray(&adt,key,num);
	}
	if(ch=='n'||ch=='N'){
		printf("Goodbye :)");
	}
	printf("\nDo You Want To Delete?[y/n]: ");
	scanf("%s",&ch);
	if(ch=='y'|| ch=='Y'){
	DeleteArray(&adt,key);
	}
	if(ch=='n'||ch=='N'){
		printf("Goodbye :)");
	}
	printf("\nDo You Want To Update?[y/n]: ");
	scanf("%s",&ch);
	if(ch=='y'|| ch=='Y'){
	update(&adt,key,num);
	}
	if(ch=='n'||ch=='N'){
		printf("Goodbye :)");
	}
	return 0;
}
