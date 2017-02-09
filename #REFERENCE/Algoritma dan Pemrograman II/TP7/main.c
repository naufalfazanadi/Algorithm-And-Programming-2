#include "header.h"

int main(){
	//last file
	structure report[50];

	//read each file.
	read(report,"thepi.txt");
	read(report,"tmoni.txt");
	read(report,"tpiyu.txt");
	int i;
	for (i = 0; i < n; i++) {
    printf("%s %s %d %d\n", report[i].code, report[i].name, report[i].cost,
                              report[i].multiple);
  }
	//calculate it, sort it, and write it down
	calculate(report);
	// int i = 0;
	sort(report);
	write(report);
	return 0;
}