/*C programme to implement the basic operations of array(Insertion,Deletion,Update)*/

#include<stdio.h>
void Insertion(int*,int,int,int,int);
void Deletion(int*,int,int,int);
void Update(int*,int,int,int,int);
int main(){
	
	printf("PRESS 1 TO INSERTION\n...............\nPRESS 2 TO DELETION\n...............\nPRESS 3 TO UPDATE\n................\nPRESS OTHER NUMBER TO EXIT\n.............\n");
	int c,arr[100],i,n,key,num;
	while(1){
	printf("\nEnter The Case You want to use: ");
	scanf("%d",&c);
	switch(c){
		case 1:
			Insertion(arr,n,key,num,i);
			break;
			case 2:
			Deletion(arr,n,key,i);
			break;
			case 3:
			Update(arr,n,key,num,i);
			break;	
	}
	if(c!=1 && c!=2 && c!=3){
		printf("Goodbye!!");
		break;
	}
}
	return 0;
}
	void Insertion(int arr[],int n, int key , int num, int i){
		printf("Enter the range of the array: ");
			scanf("%d",&n);
			for(i=0;i<n;i++){
				printf("Enter arr[%d]: ",i+1);
				scanf("%d",& arr[i]);
			}
			printf("The Array Is: \n");
			for(i=0;i<n;i++){
				printf("%d ", arr[i]);
			}
			printf("\nEnter the position you want to insert: ");
			scanf("%d",& key);
			printf("Enter the number you want to insert: ");
			scanf("%d",&num);
			printf("The Array Is(AFTER INSERTION) \n");
			int j=n;
			n = n + 1;
			while( j >= key) {
     	 	arr[j+1] = arr[j];
     	 	j = j - 1;
   		}
			arr[key] = num;
			for(i = 0; i<n; i++) {
      		printf("%d ",arr[i]);
   }
}
	void Deletion(int arr[],int n, int key,int i){
		printf("Enter the range of the array: ");
			scanf("%d",&n);
			for(i=0;i<n;i++){
				printf("Enter arr[%d]: ",i+1);
				scanf("%d",& arr[i]);
			}
			printf("The Array Is: \n");
			for(i=0;i<n;i++){
				printf("%d ", arr[i]);
			}
			printf("\nEnter the pos you want to delete: ");
			scanf("%d",&key);
			printf("The Array Is(AFTER DELETION) \n");
			int j;
			j = key;
			while( j < n) {
     		 arr[j-1] = arr[j];
     		 j = j + 1;
   		}
  	 n = n -1;
   	for(i = 0; i<n; i++) {
      	printf("%d ",arr[i]);
   }
}
	void Update(int arr[],int n, int key , int num, int i){
		printf("Enter the range of the array: ");
			scanf("%d",&n);
			for(i=0;i<n;i++){
				printf("Enter arr[%d]: ",i+1);
				scanf("%d",& arr[i]);
			}
			printf("The Array Is: \n");
			for(i=0;i<n;i++){
				printf("%d ", arr[i]);
			}
			printf("\nEnter the position you want to update: ");
			scanf("%d",&key);
			printf("Enter the value: ");
			scanf("%d",&num);
			printf("The Array Is(AFTER UPDATE) \n");
			int j;
		 	arr[key-1] = num;
		 	for(i = 0; i<n; i++) {
      			printf("%d ",arr[i]);
   			}
	}
