#include "head.h"

// PROSEDUR SORTING
void sorting (int n, data arr[n]) {
    int i, j, status = 0;
    data temp;

    // SORTING NILAI
    for (i = 1; i < n; i++) {
        temp = arr[i];
        j = i - 1;

        while ((temp.nilai > arr[j].nilai) && (j >= 0)) { // disini dibandingkan mana nilai yg lebih besar dan kecil
            arr[j+1] = arr[j]; // dipindahkan var nya bukan dalem bungkusannya
            j--;
        }

        arr[j+1] = temp;
    }

    // SORTING NAMA
    for (i = 1; i < n; i++) {
        temp = arr[i];
        j = i - 1;

        // disini jika nilai sama dan compare stringnya lebih besar maka sortir desc
        while ((temp.nilai == arr[j].nilai) && (strcmp(temp.nama, arr[j].nama) > 0) && (j >= 0)) {
            arr[j+1] = arr[j]; // dipindahkan var nya bukan dalem bungkusannya
            j--;
        }
        
        arr[j+1] = temp;
    }

    // OUTPUT
    for (i = 0; i < n; i++) {
        printf("%s %s %d\n", arr[i].nama, arr[i].kelas, arr[i].nilai);
    }
}
