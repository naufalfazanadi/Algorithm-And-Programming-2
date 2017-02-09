#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// COLOR
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m" // reset warna

// STRUCT
typedef struct {
  int x;
  int y;
  char nama[64];
  int energi;
}food; // untuk makanan

typedef struct {
  int x;
  int y;
}way; // untuk perjalanan

// VAR GLOBAL
food tmakanan[128]; // array untuk read dari file tmakanan
way tperjalanan[256]; // array untuk read dari file tperjalanan

int nFood; // jumlah array var tmakanan
int nWay; // jumlah array var tperjalanan

int max_nama; // max nama untuk responsive border tmakanan

// PAPAN
char board[1024][1024]; // var papan
int x, y; // var panjang dan luas

// ---------------------- PROCEDURE & FUNCTION HERE ----------------------

void wait(float x); // untuk menahan animasi

// ================= WILL USE AGAIN ==================

void mainMenu(int clearScreen);
void errorScreen(int whatMenu);

// ================== MENU SELECTION ==================

void menu0(); // set board
void menu1(); // table makanan
void menu2(); // table perjalanan
void menu3(); // animasi perjalanan

// ================== OTHER PROCESS ==================

void setBoard(); // nge set papan

void read(char path[50]); // scanning dari file
void write(char path[50]); // write ke file
void sort (int foodOrWay); // sort data

void printBorder(int x); // print tabel + responsive border
int len(int x); // check panjang integer

void tambah(int menu); // tambah data makanan atau perjalanan
void hapus(int menu); // hapus data makanan atau perjalanan

void setMakanan(); // masang makanan di papan
void printColor(int num, char ch); // print char berwarna