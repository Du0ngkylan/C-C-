/*
 * checkrightorwrong.c
 *
 *  Created on: Jul 15, 2013
 *      Author: hung
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char *get_message() {
	char *msg = "Aren’t pointers fun?";
	return msg;
}
int main() {
	char *string;
	string = get_message();
	puts(string);
	return 0;
}
