#include"header.h"

int main(){
	bungkus aku[100];
	bungkus kamu[100];
	bungkus dirimu[100];
	int m, n, o;
	int i, j;
	
	scanf("%d", &m);
	for(i=0; i<m; i++){
		scanf("%s %d", &aku[i].kata, &aku[i].angka);
	}
	
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%s %d", &kamu[i].kata, &kamu[i].angka);
	}
	
	scanf("%d", &o);
	for(i=0; i<o; i++){
		scanf("%s %d", &dirimu[i].kata, &dirimu[i].angka);
	}
	
	
	int tampung=cek(aku, m);
	// printf("%d ", tampung);

	int tampung2=cek(kamu, n);
	// printf("%d ", tampung2);

	int tampung3=cek(dirimu, o);
	// printf("%d ", tampung3);
	
	//ini risna nampung lagi ide bagus (y)
	bungkus risna[100];
	bungkus isal[100];
	bungkus faisal[100];
	int check1 = 0;
	int check2 = 0;
	int check3 = 0;
	if( tampung >=(int) m/2){
		for(i=0; i<m; i++){
			risna[i] = aku[i];
		}
		check1 = 1;
	}					                    //else if??---------
	if( tampung2 >=(int)n/2){
		for(i=0; i<n; i++){
			isal[i] = kamu[i];
		}		
		check2= 1;
	}										// else if???---------
	if(tampung3 >=(int)o/2){
		for(i=0; i<o; i++){             // m harusnya o-----------------------
			faisal[i] = dirimu[i];
		}
		check3 = 1;
	}
	bungkus hasil1[m+n];
	bungkus hasil2[m+n+o];
	// kondisi if banyak aja gapapa da hehe
	if(check1 == 1 && check2 == 1 && check3 == 1){
		mergetable(risna,isal,hasil1,m,n);
		mergetable(hasil1,faisal,hasil2,n,o);
		for(i=0;i<m+n+o;i++){
			printf("%s ",hasil2[i].kata);
			printf("%d\n",hasil2[i].angka);
		}
	
	}else if(check1 == 1 && check2 == 1){
		mergetable(risna,isal,hasil1,m,n);
		for(i=0;i<m+n;i++){
		printf("%s ",hasil1[i].kata);
		printf("%d\n",hasil1[i].angka);
	}
	}else if(check1 == 1 && check3 == 1){
		mergetable(risna,faisal,hasil1,m,o);
		for(i=0;i<m+o;i++){
			printf("%s ",hasil1[i].kata);
			printf("%d\n",hasil1[i].angka);
		}
	}else if(check2 == 1 && check3 == 1){
		mergetable(isal,faisal,hasil1,n,o);
		for(i=0;i<n+o;i++){
			printf("%s ",hasil1[i].kata);
			printf("%d\n",hasil1[i].angka);
		}
	}

	
	// printf(" %d",check1);
	// printf("%d",check2);
	// printf("%d\n",check3);
	
	/* int tampung[100];
	int tampung2[100];
	int tampung3[100];
	
	for(i=0; i<m; i++){
		tampung[i]=cek(aku, m);
	}
	for(i=0; i<n; i++){
		tampung2[i]=cek(kamu, n);
	}
	for(i=0; i<o; i++){
		tampung[i]=cek(dirimu, o);
	}
	
	for(i=0; i<m; i++){
		printf("%d ", tampung[i]);
	}
	
	for(i=0; i<n; i++){
		printf("%d ", tampung2[i]);
	}
	for(i=0; i<o; i++){
		printf("%d ", tampung2[i]);
	} */
	
	/* for(i=0; i<m; i++){
		if(cek(aku, m) == 1){
			printf("oke ");
		}
	}	 */
	return 0;
}