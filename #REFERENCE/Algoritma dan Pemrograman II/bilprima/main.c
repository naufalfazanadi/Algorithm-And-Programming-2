#include "header.h"

int main(){
	int i,n;
	scanf("%d",&n);
	int array[n];
	int dup1[n];
	for(i=0;i<n;i++){
		scanf("%d",&array[i]);
		dup1[i]=array[i];
	}
	bungkus diget=digat(n,array);

	bungkusan has=reverse(diget,n,array);
	// for(i=0;i<n;i++){
		// printf("%d>>digit\n",diget.digit[i]);
		// printf("%d<<hasil\n",has.rev[i]);
	// }
	hasil(n,dup1,has);
	return 0; 
}
