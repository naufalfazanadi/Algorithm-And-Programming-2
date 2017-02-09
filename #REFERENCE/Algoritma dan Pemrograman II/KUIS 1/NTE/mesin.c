#include "faisal.h"
//Fungsi mencari angka paling besar
int fungsi(int a,int b,int c){

	if(a>b&&a>c){ //jika a paling besar
		return a; //maka lempar a ke main
	}else if(b>a&&b>c){ //jika b paling besar
		return b;		//do same
	}else if(c>a&&c>b){ //jika c lebih besar dari a dan b
		return c;		//throw to main
	}
}

