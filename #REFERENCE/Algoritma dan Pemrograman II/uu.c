#include<stdio.h>
#include<string.h>
typedef struct{
	char string[100];
	int konsonan;
}risna;
risna array3[100];
void carikon(risna* a,int n);
void selection(risna* a,int n);
void carikon(risna* a,int n){
	int i,j;
	for(i=0;i<n;i++){
		a[i].konsonan = 0;
		for(j=0;j<strlen(a[i].string);j++){
			if(a[i].string[j] != 'a' && a[i].string[j] != 'i' && a[i].string[j] != 'u' && a[i].string[j] != 'o' && a[i].string[j] != 'e'){
				a[i].konsonan++;
			}
		}
	}
}
void selection(risna* a,int n){
	int i, minIndex, j;
	risna temp;
	for(i=0 ; i<(n-1) ; i++){
		minIndex = i;
		for(j=(i+1) ; j<n ; j++){
			if(a[minIndex].konsonan < a[j].konsonan){
				minIndex = j;
			}
		}
	strcpy(temp.string,a[minIndex].string);
	temp.konsonan=a[minIndex].konsonan;
	strcpy(a[minIndex].string,a[i].string);
	a[minIndex].konsonan = a[i].konsonan;
	strcpy(a[i].string, temp.string);
	a[i].konsonan = temp.konsonan;
	
	// temp = angka[minIndex];
	// angka[minIndex] = angka[i];
	// angka[i] = temp;	
	}
}
void mergetable(risna* array1,risna* array2,int n,int m){
	int i;
	int i1 = 0;
	int i2 = 0;
	int i3 = 0;
	while((i1 < n) && (i2 < m)){
		if(array1[i1].konsonan < array2[i2].konsonan){
			array3[i3] = array1[i1];
			i1 = i1 + 1;
			i3 = i3 + 1;
		}else if(array2[i2].konsonan < array1[i1].konsonan){
			array3[i3] = array2[i2];
			i2 = i2 + 1;
			i3 = i3 + 1;
		}else{
			array3[i3] = array1[i1];
			i1 = i1 + 1;
			i3 = i3 + 1;
			array3[i3] = array2[i2];
			i2 = i2 + 1;
			i3 = i3 + 1;
		}
	}

	if(i1 < n){
		for(i=i1; i<n; i++){
			array3[i3] = array1[i];
			i3 = i3 + 1;
		}
	}
	if(i2 < m){
		for(i=i2; i<m; i++){
			array3[i3] = array2[i];
			i3 = i3 + 1;
		}
	}

}
int main(){
	int m,n,o;
	int i;
	char sesuatu[100];
	scanf("%s",&sesuatu);
	scanf("%d",&m);
	risna faisal[100];
	risna lusan[100];
	risna eagan[100];
	for(i=0;i<m;i++){
		scanf(" %s",&faisal[i].string);
	}
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf(" %s",&lusan[i].string);
	}scanf("%d",&o);
	for(i=0;i<o;i++){
		scanf(" %s",&eagan[i].string);
	}
	carikon(faisal,m);
	carikon(lusan,n);
	carikon(eagan,o);
	mergetable(faisal,lusan,tabelawal,m,n);
	mergetable(tabelawal,eagan,tabelakhir,m+n,o);
	
	if(strcmp(sesuatu,"selectionsort")==0){
		selection(faisal,m);
		selection(lusan,n);
		selection(eagan,o);
	}
	for(i=0;i<m;i++){
		printf("%d\n",faisal[i].konsonan);
		printf("%s\n",faisal[i].string);
	}
	for(i=0;i<n;i++){
		printf("%d\n",lusan[i].konsonan);
	}
	for(i=0;i<o;i++){
		printf("%d\n",eagan[i].konsonan);
	}
	
	return 0;
}