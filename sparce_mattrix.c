/*C programme to represent Sparce Mattrix*/

#include<stdio.h>
int main(){
	int row,column,i,j,size,total,l,m,n;
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
	int newmat[size][3];
	int k=0;
	for(i=0;i<row;i++)
		for(j=0;j<column;j++){
			if(sparcemat[i][j]!=0){
				newmat[k][0]=i;
				newmat[k][1]=j;
				newmat[k][2]=sparcemat[i][j];
				k++;
			}
		}
		/*int flg;
    for(l=0;l<newmat[0][0];l++){
        for(m=0;m<newmat[0][1];m++){
            flg=1;
                for(n=1;n<=newmat[0][2];n++){
                    if(newmat[n][0]==i&&newmat[n][1]==j){
                        flg=0;
                        printf("%d ",newmat[n][2]);
                        break;
                    }
                }
            if(flg==1)
                printf("0 ");
        }
        printf("\n");
    }*/
	printf("The Matrix Is:\n");
	printf("%d %d %d\n",row,column,k);
	for(i=0;i<size;i++){
		for(j=0;j<3;j++){
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
