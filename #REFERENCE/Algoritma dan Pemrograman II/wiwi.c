void tambah(int n,char array[],char array2[],char* array3){
	int i;
	strcpy(array3,"00000000");
	int temp3 = 0;
	for(i=7;i>=0;i--){
		int temp = array[i] - 48; 1 = 1
		int temp2= array2[i] - 48;
		int total = temp+temp2+temp3;
		if(total==0){
			temp3=0;
		}else if(total==1){
			array3[i] = '1';
			temp3=0;
		}else if(total == 2){
			temp3 = 1;
		}else if(total == 3){
			array3[i] = '1';
			temp3 = 1
		}
	}
}