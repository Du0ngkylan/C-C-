#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <iostream>
using namespace std;

void newhandler(int sig){
	cout << "Don't stop me by Ctrl + C\n";
}

int main(){
	signal(SIGINT, newhandler);
	for (int i = 0; i < 60; i++){
		cout << "Process is calculating ... "<< i << endl;
		sleep(1);
	}
	return 0;
}
