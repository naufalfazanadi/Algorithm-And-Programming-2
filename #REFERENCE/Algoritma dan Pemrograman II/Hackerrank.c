#include<stdio.h>

int main(){
	float help1=10;
	float help2=10;
	float help3;
	int i;
	printf("KM:ke-1 10.000000\n");
	for(i=0;i<99;i++){
		help3=help2*(0.8);
		printf("KM:ke-%d %f\n",i+2,help3);
		help2=help3;
		help1=help1+help3;
		
	}
	printf("Total : %f",help1);
	



	return 0;
}