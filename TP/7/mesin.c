#include "head.h"

// scanning dari file
void file_scan(pack record[], char path[50]) {

  FILE *seqFile;
  seqFile = fopen(path,"r"); // read

  // ------------------- ke arrayin ------------------
  fscanf(seqFile,"%s %s %lf %d", &record[n].nim, &record[n].nama,
                                &record[n].mutu, &record[n].sks);

  while (strcmp(record[n].nim, "##") != 0){
    n++;
    fscanf(seqFile, "%s %s %lf %d", &record[n].nim, &record[n].nama,
                                    &record[n].mutu, &record[n].sks);
  }

  fclose(seqFile); // dont forget to close
}

// hitung ip
void ip(pack record[]) {
  int i;

  // ip = mutu / sks
  for (i = 0; i < n; i++) {
      record[i].ip = record[i].mutu / record[i].sks;
      // printf("%.2f\n", record[i].ip);
  }
}

// QUICK
void quick_sort (int l, int r, pack arr[]) { // dont forget about change data type to pack
    int i, j;
    pack temp;

    i = l; j = r;
    // PIVOT TENGAH
    pack pivot = arr[ (l+r) / 2];

    do {

        while((arr[i].ip > pivot.ip) || (arr[i].ip == pivot.ip && strcmp(arr[i].nim, pivot.nim) > 0) && (i<=j)){
            /* mencegah i berjalan terlalu jauh melewati batas j */
            i++;
        }
        while((arr[j].ip < pivot.ip) || (arr[j].ip == pivot.ip && strcmp(arr[j].nim, pivot.nim) < 0) && (i<=j)){
            /* mencegah i berjalan terlalu jauh melewati batas i */
            j--;
        }

        if (i < j) {
            // switching
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            i++; j--;
        }
    } while (i < j);

    //  ---------- REKURSIF ---------
    if ((l < j) && (j < r)) {
        quick_sort(l, j, arr);
    }

    if ((i < r) && (i > l)) {
        quick_sort(i, r, arr);
    }
}

// write ke result
void write (pack record[]) {
  FILE *seqFile;

  seqFile = fopen("result.txt","w"); // tipe nya write "w"

  // writing...
  int i;
  for(i = 0; i < n; i++){
    fprintf(seqFile, "%s %s %.2f\n", record[i].nim, record[i].nama,
                                      record[i].ip);
  }

  fprintf(seqFile, "%s %s %s\n", "##","##","##" ); // dummy data

  fclose(seqFile); // dont forget to close
}
