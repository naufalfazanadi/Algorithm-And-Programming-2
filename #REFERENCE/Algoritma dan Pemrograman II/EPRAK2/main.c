#include "header.h"

int main(){
	//read file tpita sebelum mulai, karena digunakan untuk berbagai opsi (replace & delete)
	read();
	//varaibel
	int i;
	int counter;
	char process[50];
	char replaceWith[500];
	char deleteWith;
	
	scanf("%s",&process);
	
	if(strcmp(process,"replace") == 0){
		//jika proses adalah replace
		scanf(" %499[^\n]s",&replaceWith);
		//---------------------------------
		//replace seluruh isi tpita (timpa) dengan yg baru
		FILE *data;
		data = fopen("tpita.txt","w");
		fprintf(data,"%s",replaceWith);
		fclose(data);
		
	}else if(strcmp(process,"delete") == 0){
		//jika proses adalah delete
		scanf(" %c",&deleteWith);
		row = 0;
		//--------------------------------
		counter = 0; //memmbuat 0 counter 
		//---------------------------------
		STARTKATA(pita);
		for(i=0;i<GETPANJANGKATA();i++){
			// cari huruf yg sesuai dan simpan di result!
			if(ckata[i] != deleteWith){
				result[row][counter] = ckata[i];
				counter++;
			}
		}
		if(counter != 0){ //meng handle ketika ada kata yg telah dihapus dan tidak mempunyai huruf sama sekali! ex: i , dihapus "i";
			result[row][counter]='\0'; //akhiri kata dengan null!
			// row sebanding jumlah kata tiap kalimat
			row++;
		}
		while(EOPKATA(pita) == 0){
			counter = 0;
			INCKATA(pita);
			for(i=0;i<GETPANJANGKATA();i++){
				//cari huruf yg sesuai dan simapn di result!
				if(ckata[i] != deleteWith){
					result[row][counter] = ckata[i];
					counter++;
				}
			}
			if(counter != 0){ //meng handle ketika ada kata yg telah dihapus dan tidak mempunyai huruf sama sekali! ex: i , dihapus "i";
				result[row][counter]='\0'; //akhiri dengan null
				row++; //row terus bertambah selama kata masih ada.
			}
			printf(".");
		}
		printf("%d",row);
		write(); //write ke toutput
	}
	return 0;
}