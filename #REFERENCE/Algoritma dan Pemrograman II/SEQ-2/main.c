#include<stdio.h>
#include<string.h>
typedef struct{
	char nama[100];
	char nim[50];
	char grade[50];
}bungkusan;
int main(){
	FILE *data1;
	FILE *data2;
	bungkusan a[100];
	int n=0,i=0;
	data1 = fopen("dota1.txt","r");
	fscanf(data1,"%s %s %s\n",&a[n].nama , &a[n].nim ,&a[n].grade);
	while(strcmp(a[n].nim,"XX")!=0){
		fscanf(data1,"%s %s %s\n",&a[n+1].nama , &a[n+1].nim ,&a[n+1].grade); 
		n++;
	}
	fclose(data1);
	data2 = fopen("dota2.txt","r");
	fscanf(data2,"%s %s %s\n",&a[n].nama , &a[n].nim ,&a[n].grade);
	while(strcmp(a[n].nim,"XX")!=0){
		fscanf(data2,"%s %s %s\n",&a[n+1].nama , &a[n+1].nim ,&a[n+1].grade); 
		n++;
	}
	fclose(data2);
	bungkusan data_sisip; 
	int j;
	// for(i=1; i<n+1; i++){
		// data_sisip = a[i];
		// j = i-1;
		// while((data_sisip.nim < a[j].nim) && (j >= 0)){
			// /*jika data array lebih kecil dari data sisip maka data array
			// digeser ke belakang*/
			// a[j+1] = a[j];
			// j--;
		// }
		// /*menempatkan data sisip pada array*/
		// a[j+1] = data_sisip;
	// }
	for(i=0;i<n+1;i++){
		printf("%s",a[i].nim);
	}
	return 0;
}