#include "header.h"
int main(){
	int i,j,k;
	int lebar;
	char pita[500];
	scanf(" %[^\n]s",&pita);
	scanf("%d",&lebar);
	char define[100][100];
	int c1 = 0;
	// int c2 = 0;
	STARTKATA(pita);
	if(find() == 1){
		strcpy(define[c1],GETCKATA());
		c1++;
	}
	while(EOPKATA(pita)!=1){
		INCKATA(pita);
		if(find() == 1){
			strcpy(define[c1],GETCKATA());
			c1++;
		}
	}
	// for(i=0;i<c1;i++){
		// printf("%s\t",define[i]);
	// }
	char temp[50];
	int getindeks[50];
	int left = lebar;
	int row = 0;
	int stats = 0;
	int finalstats = 0;
	
	int words = 0;
	int length = 0;
	
	i=0;
	printf("C1 : %d\n",c1);
	while(i < c1){
		if(strlen(define[i]) <= left){
			left -= (strlen(define[i]) + 1);
			getindeks[words] = i;
			words++;
			printf("&@@");
		}
		if(strlen(define[i]) > left || i == c1-1){
			// i--;
			left++;
			stats = 1;
			printf("&");
		}
		if(stats==1){
			// i--;
			stats = 0;
			makespace(lebar,temp);
			printf("%d",words);
			printf("%d",left);
			for(j=0;j<words;j++){
				for(k=0;k<strlen(define[getindeks[j]]);k++){
					temp[left] = define[getindeks[j]][k];
					left++;
				}
				temp[left] = ' ';
				left++;
			}
			temp[lebar] = '\0';
			printf("%s\n",temp);
			left = lebar;
			words = 0;
		}
		printf(".");
		i++;
	}
	
	return 0;
}