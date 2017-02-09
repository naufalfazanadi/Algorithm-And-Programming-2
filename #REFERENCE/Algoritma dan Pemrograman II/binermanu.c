#include<stdio.h>
#include<string.h>

int main(){
	char string[100];
	scanf("%s",&string);
	int i;
	int total = 0;
	if (strlen(string) == 8){
		int biner=128;
		for(i=0;i<8;i++){
			if(string[i] == '1'){
				int str = string[i] - 48;
				total = total + biner;
			}
		biner /= 2;
		}
	}else if(strlen(string) == 9){
		int biner=256;
		for(i=0;i<9;i++){
			if(string[i] == '1'){
				int str = string[i] - 48;
				total = total + biner;
			}
		biner /= 2;
		}
	
	}
	
	printf("%d",total);
	return 0;
}