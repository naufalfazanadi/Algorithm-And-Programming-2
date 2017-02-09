#include "header.h"

int main(){

	char pita[500]; //alokasi pita sebesar mungkin
	scanf("%499[^\n]s",&pita);

	int result = 0;
	char q,w,e,r;

	//q w e r sebagai 4 variabel yg dibandingkan, previous next now dsb.
	//awali program dengan mendefenisikan q w e r
	start(pita);
	q = getcc();
	inc(pita);
	w = getcc();
	inc(pita);
	e = getcc();
	inc(pita);
	r = getcc();
	while(EOP() == 0){
		//kondisi q w e r sesuai syarat
		if(q == ' '){
			if(w >= 'a' && w <= 'z'){
				if(e >= 'a' && e <= 'z'){
					if(r == ' '){
						result++;
					}
				}
			}
		}
		//geser q w e r dan ganti r menjadi karakter baru
		q = w;
		w = e;
		e = r;
		inc(pita);
		r = getcc();
	}
	printf("%d\n",result);

	return 0;
}
