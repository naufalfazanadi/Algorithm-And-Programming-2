#include<stdio.h>
#include <string.h>
long long int faktorial(int n){
printf("n = %d\n", n);
if((n ==0) || (n == 1)){
return 1;
}else{
return (n * faktorial(n-1));
}
}
int sum(int n){
	if(n!=0){
		return (n + sum(n-1));
	}
}
int main(){
	int hasil = faktorial(4);
	int hasil2 = sum(2);
	printf("%d\n",hasil2);
	printf("hasil faktorial: %d\n", hasil);
	return 0;
}