#include "header.h"

int main(){
	int i;
	int stats;
	int result = 0;
	
	char pita[500]; //alokasi kan pita sebanyak 500
	scanf("%499[^\n]s",&pita);
	
	STARTKATA(pita); //awali mesin dengan start kata;
	while(EOPKATA(pita) == 0){
		i = 0;
		stats = 0;
		//cari bintang di salah satu huruf pada setiap kata
		while(stats == 0 && i<GETPANJANGKATA()){
			if(ckata[i] == '*'){
				stats = 1;
			}
			i++;
		}
		//jika bintang ketemu maka counter bertambah
		if(stats == 0){
			result++;
		}
		INCKATA(pita); //untuk Increment disimpan di akhir karena jika di awal kondisi if(stats == 0) akan membaca kata akhir sebelum EOP.
	}
	printf("%d\n",result);
	return 0;
}