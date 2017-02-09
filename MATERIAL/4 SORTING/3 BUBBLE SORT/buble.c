#include <stdio.h>

void bubble_sort (int n,  int arr[]) {
    int i;
    int temp;
    int flip;
    
    do{
        flip = 0;
        for(i = 0; i < (n-1); i++){

            if(arr[i] > arr[i+1]){
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                flip = 1;
            }

        }
    } while(flip == 1);
}

int main () {
    int tabInt[5] = {34, 67, 23, 28, 98};
    
    int i;
    int temp;
    int tukar;
    
    do{
        /*inisialisasi nilai tukar sebelum ada pertukaran diset false */
        tukar = 0;
        /*pengulangan dan memeriksa apakah ada pertukaran */
        for(i=0; i<(5-1); i++){
            /*jika ada nilai yang dipertukarkan */
            if(tabInt[i] > tabInt[i+1]){
                /* menukar posisi elemen */
                temp = tabInt[i];
                tabInt[i] = tabInt[i+1];
                tabInt[i+1] = temp;
                tukar = 1;
            }
        }
    }while(tukar == 1);
    
    return 0;
}
