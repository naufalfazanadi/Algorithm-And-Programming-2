#include <stdio.h>
void tulis(int n){
	int counter;
	counter = n;
	if(counter > 0){
		printf("proses rekursif dengan nilai counter: %d\n", counter);
		counter = counter-1;
		tulis(counter);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	tulis(n);
	return 0;
}