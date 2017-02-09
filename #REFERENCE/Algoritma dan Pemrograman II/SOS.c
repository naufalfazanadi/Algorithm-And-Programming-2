#include<stdio.h>
#include<string.h>

int main(){
	char matriks[3][3];
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			matriks[i][j] = '.';
		}
	}
	char kar[6];
	int x[6];
	int y[6];
	int turn = 0;
	int count = 0;
	do{
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				if(j==1){
					printf("%c",matriks[i][j]);
				}else{
					printf("|%c|",matriks[i][j]);
				}
			}
			printf("\n");
		}
		printf("NEW TURN\n");
		scanf(" %c",&kar[count]);
		printf("NEW TURNx\n");
		scanf("%d",&x[count]);
		printf("NEW TURNy\n");
		scanf("%d",&y[count]);
		
		matriks[x[count]][y[count]] = kar[count];
		turn++;
		system("cls");
		count++;
	}while(turn !=6);
	return 0;
}