#include "head.h"

// fungsi untuk update matriks
day cek_jam (day jam, int hari, int masuk, int keluar) {
	int i;

	for (i = masuk - 7; i < keluar - 7; i++) { // karena mulai dari 7 maka -7
		jam.hari[hari-1][i] = TRUE; // mengisi matriks
	}

	return jam;
}

// fungsi untuk search irisan pada matriks
di_searching search_irisan(day jam) {
	int i, j, k;

	int bol;

	// inisialisasi
	di_searching x;
	x.count = 0;
	x.bol = FALSE;

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 11; j++) {
			bol = FALSE; // set boolean to false

			if (jam.hari[i][j] == FALSE) {
				x.bol = TRUE; // just once

				bol = TRUE;

				x.hari[x.count] = i;
				x.masuk[x.count] = j + 7;

				// cek kedepannya sampe udah ga 0
				while (j < 11 && bol == TRUE) {
					j++;
					if (jam.hari[i][j] == TRUE || j == 11) { // jika udah sampe akhir atau
						bol = FALSE;													 // true maka ...

						x.keluar[x.count] = j + 7;
						x.count++;
					}
				}
			}
		}
	}

	return x;
}

