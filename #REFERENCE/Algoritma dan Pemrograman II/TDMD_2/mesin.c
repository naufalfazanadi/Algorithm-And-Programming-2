#include "header.h"
//Region wait
void wait(float x) {
	//prosedur wait
	time_t start;
	time_t current;
	time(&start);
	do
		time(&current);
	while(difftime(current,start) < x);
}
//Region Menu
void home(){
	//Prosedur menu awal
	char menu[300];
	int i;
	system("cls"); 						//clear screen
	printf("Menu:\n");
	printf("1. Operasi Rekaman Pola\n");
	printf("4. Simulasi Animasi\n");
	printf("5. Keluar\n");
	printf("Masukkan Menu\t: ");
	scanf(" %299[^\n]s",&menu);

	//handling spasi
	for(i=0;i<strlen(menu);i++){
		if(menu[i] == ' '){
			menu[i] = 'x';
		}
	}

	if(menu[0] == '1' && strlen(menu) == 1){
		nu1();
	}else if(menu[0]=='4' && strlen(menu) == 1){
		nu4();
	}else if(menu[0]=='5' && strlen(menu) == 1){
		system("cls");
		system("exit");

	}else{
		//mengatasi jika input tidak sesuai,
		//maka gunakan else sebagai default
		system("cls");
		printf("Menu tidak sesuai!");
		wait(1.0);
		for(i=3;i>=1;i--){
			system("cls");
			printf("Kembali ke menu dalam [%d]",i);
			wait(1.0);
		}
		home();
	}
}
void nu1(){
	int i;
	char menu1[300]; //var inputan
	system("cls");
	//----------
	// selalu read data sebelum print

	read();

	//-----------
	print(); //prosedur print tabel record
	printf("Menu Operasi :\n");
	printf("1. Mengisi\n");
	printf("2. Menghapus\n");
	printf("3. Kembali ke Menu Utama\n");
	printf("Masukkan Menu\t: ");
	scanf(" %299[^\n]s",&menu1);
	//handling spasi
	for(i=0;i<strlen(menu1);i++){
		if(menu1[i] == ' '){
			menu1[i] = 'x';
		}
	}

	if(menu1[0]=='1' && strlen(menu1) == 1){
		//sub menu 1 - insert data
		read();
		char newname[100];
		int newx,newy;
		printf("Nama\t: ");
		scanf("%s",&newname);
		printf("X\t: ");
		scanf("%d",&newx);
		printf("Y\t: ");
		scanf("%d",&newy);
		//write
		if(checksame(newname,newx,newy) != 1){ //cek apakah record tersebut sudah tersedia
			if((newx < 3 && newy < 3) && (newx >= 0 && newy >= 0)){ //cek apakah jangkauan X Y melampaui batas
				insert(newname,newx,newy); //prosedur insert
				printf("Data berhasil disimpan");
				wait(1.5);
			}else{
				printf("Range koordinat melampaui batas!\n");
				wait(1.0);
				system("pause");
			}

		}else{
			printf("Data gagal disimpan\n");
			wait(1.0);
			system("pause");
		}
		write();
		//----
		//go to operasi rekaman if succeed
		nu1();
	}else if(menu1[0]=='2' && strlen(menu1) == 1){
		//sub menu - delete
		read();
		char replaceWith[100];
		printf("Masukkan nama\t: ");
		scanf("%s",&replaceWith);

		//--------------------------
		finddelete(replaceWith); //find it and delete it
		write(); //flush record ke file
		//go to top
		nu1();
	}else if(menu1[0]=='3' && strlen(menu1) == 1){
		//up one level
		home();
	}else{
		int i ;
		//mengatasi inputan user yg tidak sesuai
		//else sebagai default
		system("cls");
		printf("Menu tidak sesuai!");
		wait(2.0);
		for(i=3;i>=1;i--){
			system("cls");
			printf("Kembali ke menu dalam [%d]",i);
			wait(1.0);
		}
		nu1();
	}
}
void nu4(){
	int tebal;
	int i;
	char pita[300];
	system("cls");
	printf("Kalimat pola\t: ");
	scanf(" %299[^\n]s",&pita);
	printf("Ketebalan\t: ");
	scanf("%d",&tebal);
	system("cls");
	//---------------
	// keep read data
	read();
	//Mulai mesin kata
	STARTKATA(pita);
	if(binarysearch(GETCKATA())==1){ //fungsi akan return 1 jika kata tersebut ada di record
		findpita(GETCKATA(),tebal);
	}

	while(EOPKATA(pita) == 0){
		//reset,increment,and find again
		RESETKATA();
		INCKATA(pita);
		system("cls");
		if(binarysearch(GETCKATA())==1){
			findpita(GETCKATA(),tebal);
		}
	}
	for(i=3;i>=1;i--){
		system("cls");
		printf("Kembali ke menu dalam [%d]",i);
		wait(1.0);
	}
	//go home when we finished
	home();
}
//Region SubMenu Operasi
void write(){
	//prosedur write
	FILE *data;
	data = fopen("tpola.txt","w");
	int i;
	// printf("%d",n);
	for(i=0;i<n;i++){
		fprintf(data,"%s %d %d\n",tabel[i].nama,tabel[i].x,tabel[i].y);
	}
	fprintf(data,"%s %s %s\n","##","#","#");
	fclose(data);
}
void read(){
	//prosedur read
	//beserta modifikasi
	FILE *data;
	data = fopen("tpola.txt","r");
	n=0; //n sebagai jumlah record yg terus berganti setiap prosedur ini dipanggil
	namapjg=0; //jumlah huruf pada nama sebagai patokan tabel, akan terus diganti seiring prosedur ini dipanggil
	fscanf(data,"%s %d %d\n",&tabel[n].nama,&tabel[n].x,&tabel[n].y);
	while(strcmp(tabel[n].nama,"##")!=0){
		n++;
		fscanf(data,"%s %d %d\n",&tabel[n].nama,&tabel[n].x,&tabel[n].y);
		if(strlen(tabel[n].nama) > namapjg){
			//jika record baru lebih panjang maka, replace it
			namapjg = strlen(tabel[n].nama);
		}
	}
	fclose(data);
}
void insert(char nama[100],int x,int y){
	//prosedur insert
	//if logic *data diurutkan berdasarkan nama, ketika nama sama dirutkan berdasarkan y, jika keduanya sama maka diurutkan berdasarkan x.*
	if((strcmp(nama,tabel[0].nama) < 0) || ((strcmp(nama,tabel[0].nama) == 0) && (y<tabel[0].y)) || ((strcmp(nama,tabel[0].nama)==0) && (y==tabel[0].y) && (x<tabel[0].x))){
		//kondisi ketika record di awal
		int i;
		for(i=n-1;i>=0;i--){
			strcpy(tabel[i+1].nama,tabel[i].nama);
			tabel[i+1].x = tabel[i].x;
			tabel[i+1].y = tabel[i].y;
		}
		n++;
		strcpy(tabel[0].nama, nama);
		tabel[0].x = x;
		tabel[0].y = y;
	}else if((strcmp(nama,tabel[n-1].nama) == 1) || ((strcmp(nama,tabel[n-1].nama) == 0) && (y>tabel[n-1].y)) || ((strcmp(nama,tabel[n-1].nama)==0) && (y==tabel[n-1].y) && (x>tabel[n-1].x))){
		//kondisi ketika record di akhir
		strcpy(tabel[n].nama, nama);
		tabel[n].x = x;
		tabel[n].y = y;
		n++;
	}else{
		//kondisi ketika record di tengah
		int i = 0;
		int stop = 0;
		while((i<n) && (stop == 0)){
			if((strcmp(nama,tabel[i].nama) < 0) || ((strcmp(nama,tabel[i].nama) == 0) && (y<tabel[i].y)) || ((strcmp(nama,tabel[i].nama)==0) && (y==tabel[i].y) && (x<tabel[i].x))){
				stop = 1;
			}else{
				i++;
			}
		}

		int j;
		for(j=(n-1);j>=i;j--){
			strcpy(tabel[j+1].nama, tabel[j].nama);
			tabel[j+1].x = tabel[j].x;
			tabel[j+1].y = tabel[j].y;
		}
		strcpy(tabel[i].nama, nama);
		tabel[i].x = x;
		tabel[i].y = y;
		n++;
	}
}
void finddelete(char nama[100]){
	// prosedur sequential search modifikasi

	int i ;
	int j;
	int indeks[100];
	int counter = 0;
	int status = 0;
	int newstats = 0;
	char pilih;
	int yes=0;

	i=0;
	while(i<=n) {
		if(strcmp(tabel[i].nama, nama) == 0){
			newstats = 1;
			// jika data ketemu
			//kondisi ini hanya satu kali.
			if (status == 0){
				status = 1;
				printf("Anda yakin ingin menghapus data %s dari tabel? [y/n] ",nama);
				scanf(" %c",&pilih);
			}
			if (pilih =='y' || pilih =='Y'){
				yes = 1;
			}else{
				i++;
			}
			//------------------------------------------
			//prosedur delete
			if(yes==1){
				// delete jika record diakhir
				if(i==n-1){
					n--;
				}else{
					//delete jika record di tengah
					for(j=i;j<n-1;j++){
						strcpy(tabel[j].nama,tabel[j+1].nama);
						tabel[j].x = tabel[j+1].x;
						tabel[j].y = tabel[j+1].y;
					}
					n--;
				}
			}
				printf("%d",i);
		}else{
			i++;
		}

	}
	// printf("%d",status);
	// wait(5.0);
	if(newstats == 0){
		printf("Data tidak ditemukan\n");
		system("Pause");
	}
}
int checksame(char nama[100],int x,int y){
	int i; int j; int k; int ketemu;
	i = 0;
	j = n-1;
	ketemu = 0;
	while((ketemu == 0) && (i<=j)){
		//pencarian dari tengah ke sisi
		k = (int)(i + j) / 2;
		if(strcmp(nama,tabel[k].nama)==0 && (x==tabel[k].x) && (y==tabel[k].y)){
			ketemu = 1;
		}else{
			if((strcmp(nama,tabel[k].nama) < 0) || ((strcmp(nama,tabel[k].nama) == 0) && (y<tabel[k].y)) || ((strcmp(nama,tabel[k].nama)==0) && (y==tabel[k].y) && (x<tabel[k].x))){
				j = k - 1;
			}else{
				i = k + 1;
			}
		}
	}
	//jika ketemu maka return 1;
	if(ketemu == 1){
		return 1;
	}else{
		return 0;
	}
}
//subRegion Operasi (Tabel)
void garis(){
	//prosedur garis pada tabel
	int i;
	for(i=0;i<(namapjg+7)+8;i++){
		printf("-");
	}
	printf("\n");
}
void print(){
	int i,j;
	printf("Isi tabel saat ini:\n");
	if(n==0){
		garis();
		printf("|Nama");
		for(i=0;i<(namapjg+7)-4;i++){
			printf(" ");
		}
		printf("|X ");
		printf("|Y |\n");
		garis();
		garis();

	}else{
		garis();
		printf("|Nama");
		for(i=0;i<(namapjg+7)-4;i++){
			//Angka 7 sebagai ruang kosong setelah nama (desain)
			printf(" ");
		}
		printf("|X ");
		// for(i=0;i<1;i++){
			// printf(" ");
		// }
		printf("|Y ");
		// for(i=0;i<1;i++){
			// printf(" ");
		// }
		printf("|\n");
		garis();
		for(i=0;i<n;i++){
			printf("|%s",tabel[i].nama);
			for(j=0;j<(namapjg+7)-strlen(tabel[i].nama) ; j++){
				//kondisi ini memungkinkan tabel menyesuaikan dengan strlen
				printf(" ");
			}
			printf("|%d ",tabel[i].x);
			// for(j=0;j<2-1;j++){
				// printf(" ");
			// }
			printf("|%d ",tabel[i].y);
			// for(j=0;j<2-1;j++){
				// printf(" ");
			// }
			printf("|\n");
		}
		garis();
	}
}
//Region Animasi
//subRegion Mesin Kata
void STARTKATA(char pita[]){
	//STARTKATA
	indeks = 0;
	panjangkata = 0;
	while(pita[indeks] == ' '){
		indeks++;
	}
	while((pita[indeks] != ' ') && (pita[indeks] != '.')){
		//ckata terus maju hingga spasi atau titik
		ckata[panjangkata] = pita[indeks];
		indeks++;
		panjangkata++;
	}
	ckata[panjangkata] = '\0';
}
void RESETKATA(){
	//reset all
	panjangkata = 0;
	ckata[panjangkata] = '\0';
}
void INCKATA(char pita[]){
	//increment kata
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
	//getckata disini bisa dibilang sebagai variabel yg dapat digunakan
	return ckata;
}
int GETPANJANGKATA(){
	//dapatkan kata terpanjang
	return panjangkata;
}
int EOPKATA(char pita[]){
	//end of kalimat
	if(pita[indeks] == '.'){
		return 1;
	}else{
		return 0;
	}
}
//subRegion searching & making matriks
void findpita(char kata[100],int tebal){
	//find pita
	int i,j,k,l;
	//------------------------
	// variabel dibawah untuk warna
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// ------------------------
	//Mengkondisikan isi matriks sebagai spasi (tidak terlihat)
	//ketika tidak dikondisikan maka muncul, simbol aneh
	char matriks[3][3];
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			matriks[i][j]=' ';
		}
	}

	// --------------------------
	//keep read data when needed
	read();
	//---------------------------
	// impelemntasikan x y pada record tabel ke matriks
	for(i=0;i<n;i++){
		int temp1,temp2;
		temp1 = (tabel[i].x);
		temp2 = (tabel[i].y);
		if(strcmp(kata,tabel[i].nama) == 0){
			matriks[temp2][temp1] = '0';
		}
	}

	int z; //untuk code "center"

	// wait(2.0); //wait program agar menarik
	printf("Berikut adalah pola dengan attribut berikut :\n");
	printf("Kata		: %s\n",kata);
	printf("Ketebalan	: %d\n\n",tebal);
	wait(2.0);
	system("cls");
	color = temp;

	for(i=0;i<3;i++){
		//--set warna setiap baris
		SetConsoleTextAttribute(hConsole, color); //warna merah kuning hijau
		//---

		for(l=0;l<tebal;l++){
			//for ini untuk membuat pola "center"
			// for(z=0;z<8;z++){
				// printf("\t");
			// }
			for(j=0;j<3;j++){
				for(k=0;k<tebal;k++){
					printf("%c",matriks[i][j]);
				}
			}
			printf("\n");
		}
		//wait 3 sec, sehingga membentuk animasi
		wait(1.0);
		if(color>=15){ //warna dibatasi hingga warna berlatar hitam saja.
			color = 8;
		}else{
			color++;
		}

	}
	temp = color;
	// col = color;
	SetConsoleTextAttribute(hConsole, 7);
}
int binarysearch(char kata[100]){
	//prosedur find data menggunakan binarysearch fungsi.
	int i; int j; int k; int ketemu;
	i = 0;
	j = n-1;
	ketemu = 0;
	while((ketemu == 0) && (i<=j)){
		//pencarian dari tengah ke sisi
		k = (int)(i + j) / 2;
		if(strcmp(kata,tabel[k].nama)==0){
			ketemu = 1;
		}else{
			if(strcmp(kata,tabel[k].nama)<0){
				j = k - 1;
			}else{
				i = k + 1;
			}
		}
	}
	//jika ketemu maka return 1;
	if(ketemu == 1){
		return 1;
	}else{
		return 0;
	}
}
