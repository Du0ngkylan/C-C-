#include<stdio.h>
#include<conio.h>

void dragon(int n);
void nogard(int n);

FILE *f;
void forward() {
	fprintf(f, "5 0 rlineto\n");
}
void left() {
	fprintf(f, "90 rotate\n");
}
void right() {
	fprintf(f, "-90 rotate\n");
}


int main(int argc, char **argv) {
	f = fopen("dragon.ps", "w");
	fprintf(f, "%%!PS\n");
	fprintf(f,"%% Set the page size to A4\n");
	fprintf(f,"<< /PageSize [595 842] >> setpagedevice\n");
	fprintf(f, "0.1 setlinewidth\n");
	fprintf(f, "400 400 moveto\n");
	dragon(12);
	fprintf(f, "0.8 0 0 setrgbcolor\n");
	fprintf(f, "stroke\n");
	fprintf(f, "showpage\n");
	fclose(f);
	getch();
	return 0;
}


void dragon(int n) {
	if (n == 0)
		forward();
	else {
		dragon(n-1);
		left();
		nogard(n-1);
	}
}

void nogard(int n) {
	if (n == 0)
		forward();
	else {
		dragon(n-1);
		right();
		nogard(n-1);
	}
}
