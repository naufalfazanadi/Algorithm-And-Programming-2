#include "head.h"

// fungsi untuk menghitung pembelahan
int recursive (int n, int count) {
    count++; // var penghitung pembelahan
    if (n < 1) {
        return count;
    } else {
        return recursive(n / 2, count); // rekursif
    }
}
