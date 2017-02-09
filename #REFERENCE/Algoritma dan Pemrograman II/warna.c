#include<stdio.h>
#include<windows.h>

int main(){

	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	char str[50]="Color ";
	char* numbers = new char[2];
	int colors = 0xe1;//this is what you change
	
	
	
	for(int i=0;i<5;i++){
		itoa(colors, numbers, 16);itoa(colors, numbers, 16);
		str+=numbers;
		system(str.c_str());
		SetConsoleTextAttribute(hConsole, colors);
		printf("RANGGI ANJING");
	}
	
	return 0;
}