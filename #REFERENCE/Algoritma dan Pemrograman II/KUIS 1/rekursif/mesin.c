#include "faisal.h"

int fibo(int kel,int a){
	//deklarasi temporarry
	int temp;
	int hasil;
	if(a<kel){
		//jika jangkauan tidak melebihi kelipatan dipastikan 0
		return 0;
	}else if(a%kel==0){
		//jika bilangan itu adalah kelipatan itu, maka lakukan fungsi
		//topdown
		temp=(a+fibo(kel,a-kel)); //e.g. 6+3
		return temp;
	}else{
		//jika bilangan lainnya
		hasil=(a/kel)*kel; //bilangan tersebut dibagi dahulu, agar tahu awalnya
		temp=(fibo(kel,hasil-kel)+hasil); //hasil tersebut digunakan untuk ditambahkan dengan yg sebelumnya
		return temp;
	}
}
