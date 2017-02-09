#include "faisal.h"

void wait(float x) {
	time_t start;
	time_t current;
	time(&start);
	do
		time(&current);
	while(difftime(current,start) < x);
}
void home(){
	int i = 0;

	int menu;
	int menu1;
	int hps[100];
	int tebal;
	char pita[300];
	int ketebalan;
	system("cls");
	printf("Menu:\n");
	printf("1. Operasi Rekaman Pola\n");
	printf("4. Simulasi Animasi\n");
	printf("5. Keluar\n");
	printf("Masukkan Menu: ");
	scanf("%d",&menu);
	
	if(menu==1){
	nu1:
		system("cls");
		FILE *data;
		data = fopen("tpola.txt","r");
		read(data);
		fclose(data);
		print();
		printf("%d\n",n);
		printf("Menu Operasi :\n");
		printf("   1. Mengisi\n");
		printf("   2. Menghapus\n");
		printf("   3. Kembali ke Menu Utama\n");
		printf("Masukkan Menu: ");
		scanf("%d",&menu1);
		
		if(menu1==1){
			char newname[100],newx[2],newy[2];
			printf("nama : ");
			scanf("%s",&newname);
			printf("x    : ");
			scanf("%s",&newx);
			printf("y    : ");
			scanf("%s",&newy);
			data = fopen("tpola.txt","r");
			read(data);
			fclose(data);
			data = fopen("tpola.txt","w");
			// add(newname,newx,newy);
			insert(newname,newx,newy);
			n++;
			write(data);
			fclose(data);
			goto nu1;
		}else if(menu1==2){
			char replacewith[100];
			printf("Masukkan nama : ");
			scanf("%s",&replacewith);
			data = fopen("tpola.txt","r");
			read(data);
			fclose(data);
			finddelete(replacewith);
			data = fopen("tpola.txt","w");
			write(data);
			fclose(data);
			goto nu1;
		}else if(menu1==3){
			home();
		}else{
			goto nu1;
		}
	}else if(menu==4){
		int boolean = 0;
		system("cls");
		printf("Kalimat pola : ");
		scanf(" %229[^\n]s",&pita);
		printf("Ketebalan : ");
		scanf("%d",&tebal);
		STARTKATA(pita);
		findpita(ckata,tebal);
		while(EOPKATA(pita) == 0){
			RESETKATA();
			INCKATA(pita);
			system("cls");
			findpita(ckata,tebal);
		}
		wait(4.0);
		home();
	}else if(menu==5){
		system("exit");
	}else{
		home();
	}
}
void add(char nama[100],char x[2],char y[2]){
	strcpy(tabel[n].nama,nama);
	strcpy(tabel[n].x,x);
	strcpy(tabel[n].y,y); 
}
void write(FILE *data){
	int i;
	printf("%d",n);
	for(i=0;i<n;i++){
		fprintf(data,"%s %s %s\n",tabel[i].nama,tabel[i].x,tabel[i].y);
	}
	fprintf(data,"%s %s %s\n","##","#","#");
}
void garis(){
	int i;
	for(i=0;i<(namapjg+3)+8;i++){
		printf("-");
	}
	printf("\n");
}
void read(FILE *data){
	n=0;
	namapjg=0;
	fscanf(data,"%s %s %s\n",&tabel[n].nama,&tabel[n].x,&tabel[n].y);
	while(strcmp(tabel[n].nama,"##")!=0){
		n++;
		fscanf(data,"%s %s %s\n",&tabel[n].nama,&tabel[n].x,&tabel[n].y);
		if(strlen(tabel[n].nama) > namapjg){
			namapjg = strlen(tabel[n].nama);
		}
	}
	// makingmatriks();
}
void print(){
	int i,j;
	printf("Isi tabel saat ini:\n");
	garis();
	printf("|nama");
	for(i=0;i<(namapjg+3)-4;i++){
		printf(" ");
	}
	printf("|x");
	for(i=0;i<1;i++){
		printf(" ");
	}
	printf("|y");
	for(i=0;i<1;i++){
		printf(" ");
	}
	printf("|\n");
	garis();
	for(i=0;i<n;i++){
		printf("|%s",tabel[i].nama);
		for(j=0;j<(namapjg+3)-strlen(tabel[i].nama) ; j++){
			printf(" ");
		}
		printf("|%s",tabel[i].x);
		for(j=0;j<2-1;j++){
			printf(" ");
		}
		printf("|%s",tabel[i].y);
		for(j=0;j<2-1;j++){
			printf(" ");
		}
		printf("|\n");
	}
	garis();
}
//prosedur sequential modifikasi
void finddelete(char nama[100]){
	int i ;
	int j;
	int indeks[100];
	int counter = 0;
	int status =0;
	char pilih;
	int yes=0;
	i=0;
	while(i<n) {
		if(strcmp(tabel[i].nama, nama) == 0){
			//jika data ketemu
			if (status == 0){
				status = 1;
				printf("Anda yakin ingin menghapus data %s dari tabel? [y/n] ",nama);
				scanf(" %c",&pilih);
			}
			if (pilih =='y' || pilih =='Y'){
				yes = 1;
			}
			if(yes==1){
				//delete jika diakhir
				if(i==n-1){
					n--;
				}else{
					for(j=i;j<n-1;j++){
						strcpy(tabel[j].nama,tabel[j+1].nama);
						strcpy(tabel[j].x,tabel[j+1].x);
						strcpy(tabel[j].y,tabel[j+1].y);
					}
				n--;
				}
				printf("%d",i);
				// wait(2.0);
			}
		}else{
			i = i + 1;
		}
	}
}
void STARTKATA(char pita[]){
	indeks = 0;
	panjangkata = 0;
	while(pita[indeks] == ' '){
		indeks++;
	}
	while((pita[indeks] != ' ') && (pita[indeks] != '.')){
		ckata[panjangkata] = pita[indeks];
		indeks++;
		panjangkata++;
	}
	ckata[panjangkata] = '\0';
}
void RESETKATA(){
	panjangkata = 0;
	ckata[panjangkata] = '\0';
}
void INCKATA(char pita[]){
	panjangkata = 0;
	while(pita[indeks] == ' '){
		indeks++;
	}
	while((pita[indeks] != ' ') && (pita[indeks] != '.')){
		ckata[panjangkata] = pita[indeks];
		indeks++;
		panjangkata++;
	}
	ckata[panjangkata] = '\0';
}
char* GETCKATA(){
	return ckata;
}
int GETPANJANGKATA(){
	return panjangkata;
}
int EOPKATA(char pita[]){
	if(pita[indeks] == '.'){
		return 1;
	}else{
		return 0;
	}
}
void findpita(char kata[100],int tebal){
	int i,j,k,l;
	FILE *data;
	//------------------------
	char matriks[3][3];
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			matriks[i][j]='-';
		}
	}
	//--------------------------
	data = fopen("tpola.txt","r");
	read(data);
	// printf("%s",kata);
	fclose(data);
	for(i=0;i<n;i++){
		int temp1;
		temp1 = (tabel[i].x[0]) - 48;
		int temp2;
		temp2 = (tabel[i].y[0]) - 48;
		if(strcmp(kata,tabel[i].nama) == 0){
			matriks[temp2][temp1] = '0';
		}
	}
	wait(2.0);
	for(i=0;i<3;i++){
		for(l=0;l<tebal;l++){
			for(j=0;j<3;j++){
				for(k=0;k<tebal;k++){
					printf("%c",matriks[i][j]);
				}
			}
			printf("\n");
		}
		wait(2.0);
	}
}

void insert(char nama[100],char x[2],char y[2]){
	printf("%d",n-1);
	printf("%d",n);
	wait(2.0);
	if((strcmp(nama,tabel[0].nama) == -1)){
		int i;
		for(i=n-1;i>=0;i--){
			strcpy(tabel[i+1].nama,tabel[i].nama);
			strcpy(tabel[i+1].x,tabel[i].x);
			strcpy(tabel[i+1].y,tabel[i].y);
		}
		n++;
		strcpy(tabel[0].nama, nama);
		strcpy(tabel[0].x,x);
		strcpy(tabel[0].y,y);
	}else if((strcmp(nama,tabel[n-1].nama) > 0)){
		strcpy(tabel[n].nama, nama);
		strcpy(tabel[n].x,x);
		strcpy(tabel[n].y,y);
	}else{
		int i = 0;
		int stop = 0;
		while((i<n) && (stop == 0)){
			if((strcmp(nama,tabel[i].nama) == 0)){
				stop = 1;
			}else{
				i++;
			}
		}
		printf("%d",stop);
		printf("%d",i);
		wait(4.0);
		int j;
		for(j=(n-1);j>=i;j--){
			strcpy(tabel[j+1].nama, tabel[j].nama);
			strcpy(tabel[j+1].x,tabel[j].x);
			strcpy(tabel[j+1].y,tabel[j].y);
		}
		strcpy(tabel[i].nama, nama);
		strcpy(tabel[i].x,x);
		strcpy(tabel[i].y,y);
		n++;
	}
}
// void insertData(bungkus masukan2){
	// int i;
	// int status=findData(masukan2.nama,masukan2.x,masukan2.y);
	// int j;
	
	// readFile();
	
	// if(status==0){
		// if(strcmp(masukan2.nama,masukan[0].nama)<0 || strcmp(masukan2.nama,masukan[0].nama)==0 && strcmp(masukan2.y,masukan[0].y)<0 || strcmp(masukan2.nama,masukan[0].nama)==0 && strcmp(masukan2.y,masukan[0].y)==0 && strcmp(masukan2.x,masukan[0].x)<0){
			// for(i=(n-1);i>=0;i--){
				// strcpy(masukan[i+1].nama,masukan[i].nama);
				// strcpy(masukan[i+1].x,masukan[i].x);
				// strcpy(masukan[i+1].y,masukan[i].y);
			// }
			// strcpy(masukan[0].nama,masukan2.nama);
			// strcpy(masukan[0].x,masukan2.x);
			// strcpy(masukan[0].y,masukan2.y);
			// n++;
			// writeFile();
			// system("cls");
		// }
		// else if(strcmp(masukan2.nama,masukan[n-1].nama)>0 || strcmp(masukan2.nama,masukan[n-1].nama)==0 && strcmp(masukan2.y,masukan[n-1].y)>0 || strcmp(masukan2.nama,masukan[n-1].nama)==0 && strcmp(masukan2.y,masukan[n-1].y)==0 && strcmp(masukan2.x,masukan[n-1].x)>0){
			// strcpy(masukan[n].nama,masukan2.nama);
			// strcpy(masukan[n].x,masukan2.x);
			// strcpy(masukan[n].y,masukan2.y);
			// n++;
			// writeFile();
			// system("cls");
		// }
		// else{
			// i=0;
			// int stop=0;
			// while(i<n && stop==0){
				// if(strcmp(masukan[i].nama,masukan2.nama)>0 || strcmp(masukan[i].nama,masukan2.nama)==0 && strcmp(masukan[i].y,masukan2.y)>0 || strcmp(masukan[i].nama,masukan2.nama)==0 && strcmp(masukan[i].y,masukan2.y)==0 && strcmp(masukan[i].x,masukan2.x)>0){
					// stop=1;
				// }else{
					// i++;
				// }
			// }
			// for(j=(n-1);j>=i;j--){
				// strcpy(masukan[j+1].nama,masukan[j].nama);
				// strcpy(masukan[j+1].x,masukan[j].x);
				// strcpy(masukan[j+1].y,masukan[j].y);
			// }
			// strcpy(masukan[i].nama,masukan2.nama);
			// strcpy(masukan[i].x,masukan2.x);
			// strcpy(masukan[i].y,masukan2.y);
			// n++;
			// writeFile();
			// system("cls");
		// }
	// }else{
		// system("cls");
		// printf("pola sudah ada\n");
		// printf("\n");
	// }
// }