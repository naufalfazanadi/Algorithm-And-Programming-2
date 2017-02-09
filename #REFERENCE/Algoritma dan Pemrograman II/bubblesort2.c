#include<stdio.h>>

int main(){
	int n;
	scanf("%d",&n);
	char mahasiswa[n][100]
	char temp[100];
	for(i=0;i<n;i++){
		scanf("%s", &mahasiswa[i]);
	}
	
	do{
		tukar = 0;
		
		for(i=0;i<n-1;i++){
			if(strcmp(mahasiswa[i],mahasiswa[i+i]==1){
				strcpy(temp,mahasiswa[i]);
				strcpy(mahasiswa[i],mahasiswa[i+1];
				strcpy(mahasiswa[i+1],temp);
				tukar = 1;
			}
		}
	}while(tukar==1)
	printf("\n");
	for(i=0;i<n;i++){
		printf("%s\n",mahasiswa[i]");
	}
	return 0;
}