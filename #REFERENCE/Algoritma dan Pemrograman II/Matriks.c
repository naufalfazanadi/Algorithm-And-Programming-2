#include <stdio.h>
typedef struct{
	int x;
	int y;
}titik;
int main(){
titik matriks[4][4];
int i, j;
for(i=0;i<4;i++){
for(j=0;j<4;j++){
printf("\nmasukkan koodinat x:\n");
scanf("%d", &matriks[i][j].x);
printf("\nmasukkan koodinat y:\n");
scanf("%d", &matriks[i][j].y);
}
}
for(i=0;i<4;i++){
for(j=0;j<4;j++){
printf("koodinat x: %d\n", matriks[i][j].x);
printf("koodinat y: %d\n", matriks[i][j].y);
}
}
return 0;
}