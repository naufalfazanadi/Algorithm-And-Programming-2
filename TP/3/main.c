#include "head.h"

int main () {
    // jumlah input
    int n;

    scanf("%d", &n);

    data mahasiswa[n]; // array mahasiswa berdata bungkusan

    int i;
    for (i = 0; i < n; i++) {
        // input data
        scanf("%s %s %d", &mahasiswa[i].nama, &mahasiswa[i].kelas, &mahasiswa[i].nilai);
    }

    // lempar ke prosedur
    sorting(n, mahasiswa);

    return 0;
}
