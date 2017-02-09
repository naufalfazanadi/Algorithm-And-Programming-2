#include"header.h"

int main(){
	//deklarasi variabel
	int m,n,o;
	int i;
	char sesuatu[100];//char string pemilihan algorithym
	//-------------------------------------------------------------
	scanf(" %s",&sesuatu);
	//-------------------------------------------------------------
	//array1
	scanf("%d",&m);
	risna faisal[m+1];
	
	for(i=0;i<m;i++){
		scanf(" %s",&faisal[i].string);
		scanf(" %s",&faisal[i].string2);
	}
	
	//-------------------------------------------------------------
	//array2
	scanf("%d",&n);
	risna lusan[n+1];
	
	for(i=0;i<n;i++){
		scanf(" %s",&lusan[i].string);
		scanf(" %s",&lusan[i].string2);
	}
	//-------------------------------------------------------------
	//array3
	scanf("%d",&o);
	risna eagan[o+1];
	for(i=0;i<o;i++){
		scanf(" %s",&eagan[i].string);
		scanf(" %s",&eagan[i].string2);
	}
	//-------------------------------------------------------------
	risna merge1[m+n]; //variabel untuk merge awal (array1&array2) (banyakdataarray1+banyakdataarray2)
	risna merge2[m+n+o]; //variabel untuk merge akhir (merge1&array3) (banyakdatamerge1+banyakdatarray3)
	//-------------------------------------------------------------
	// pencarian vokal konsonan menggunakan prosedur
	vokon(faisal,m);
	vokon(lusan,n);
	vokon(eagan,o);
	
	//pengurutas sorting tergantung pemilihan user
	if(strcmp(sesuatu,"selectionsort")==0){
		selection(faisal,m);
		selection(lusan,n);
		selection(eagan,o);
	}else if(strcmp(sesuatu,"bubblesort")==0){
		bubble(faisal,m);
		bubble(lusan,n);
		bubble(eagan,o);
	}else if(strcmp(sesuatu,"insertionsort")==0){
		insertion(faisal,m);
		insertion(lusan,n);
		insertion(eagan,o);
	}else if(strcmp(sesuatu,"quicksort")==0){
		quickSortPivotPinggir(faisal,0,m-1);
		quickSortPivotPinggir(lusan,0,n-1);
		quickSortPivotPinggir(eagan,0,o-1);
	}
	//penggabungan array/tabel menggunakan prosedur
	mergetable(faisal,lusan,merge1,m,n);
	mergetable(merge1,eagan,merge2,m+n,o);
	for(i=0;i<m+n+o;i++){
		printf("%d\n",merge2[i].voko);
	}
	return 0;
}