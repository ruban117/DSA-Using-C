/*C programme to represent Sparce Mattrix*/

#include<stdio.h>
int main(){
	int row,column,i,j,size,total;
	printf("How Many Rows?: ");
	scanf("%d",&row);
	printf("How Many Columns?: ");
	scanf("%d",&column);
	int sparcemat[row][column];
	printf("Enter Only Sparce Mattrix Value Contains With 0\n");
	for(i=0;i<row;i++){
		for(j=0;j<column;j++){
			printf("Enter sparcemat[%d][%d]: ",i,j);
			scanf("%d",&sparcemat[i][j]);
		}
		printf("\n");
	}
	total=0;
		for(i=0;i<row;i++){
		for(j=0;j<column;j++){
			if(sparcemat[i][j]==0)
			total++;
		}
	}
	if(total >= (i * j)/2){  //check if a matrix is sparce or not
	size=0;
	for(i=0;i<row;i++){
		for(j=0;j<column;j++){
			if(sparcemat[i][j]!=0){
				size++;
			}
		}
	}
	int newmat[3][size];
	int k=0;
	for(i=0;i<row;i++){
		for(j=0;j<column;j++){
			if(sparcemat[i][j]!=0){
				newmat[0][k]=i;
				newmat[1][k]=j;
				newmat[2][k]=sparcemat[i][j];
				k++;
			}
		}
	}
	printf("The Matrix Is:\n");
	for(i=0;i<3;i++){
		for(j=0;j<size;j++){
			printf("%d ",newmat[i][j]);
		}
		printf("\n");
	}
}
else{
	printf("The given matrix is not Sparse matrix You go and study!!!");
}
	return 0;
}