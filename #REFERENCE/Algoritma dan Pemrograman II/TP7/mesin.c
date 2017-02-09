#include "header.h"

void read(structure* data,char path[50]){
	//we might read some path from parameter
	FILE *seq;
	seq = fopen(path,"r");	
	fscanf(seq, "%s %s %d %d\n", &data[n].code , &data[n].name, &data[n].cost, &data[n].multiple);
	while(strcmp(data[n].code,"##")!=0){
		n++;
		fscanf(seq, "%s %s %d %d\n", &data[n].code , &data[n].name, &data[n].cost, &data[n].multiple);
	}
	// n--;
	fclose(seq); //close before quit sub
}
void calculate(structure* data){
	int i;
	for(i=0;i<n;i++){
		//calculate each data into total
		data[i].total = data[i].cost * data[i].multiple;
	}
}

void sort(structure* a){
	//sort
	int i; 
	structure data_sisip; 
	int j; 
	int k;
	//insertion sort
	for(i=1; i<n; i++){
	data_sisip = a[i];
	j = i-1;
	while(((data_sisip.total > a[j].total) || ((data_sisip.total == a[j].total) &&(strcmp(data_sisip.code,a[j].code)==-1))) && (j >= 0)){
		/*jika data array lebih kecil dari data sisip maka data array
		digeser ke belakang*/
		a[j+1] = a[j];
		j--;
	}
	// menempatkan data sisip pada array
	a[j+1] = data_sisip;
	}
}

//write sub
void write(structure* data){
	FILE *seq;
	//we dont need any path from parameter
	seq = fopen("ttobi.txt","w");
	int i;
	for(i=0;i<n;i++){
		fprintf(seq, "%s %s %d\n", data[i].code, data[i].name, data[i].total);
	}
	//print dummy for end of file
	fprintf(seq, "%s %s %s\n", "##","##","##" );
	fclose(seq);
}
