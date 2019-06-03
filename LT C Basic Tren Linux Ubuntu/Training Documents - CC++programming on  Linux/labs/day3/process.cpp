#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>
using namespace std;

int main(){
	printf("Start program\n");
	
	pid_t pid = fork();
	
	if (pid == -1){
		perror("Can't create new process");
		return 1;
	} else if (pid == 0){
		for (int i = 0; i< 10; i++){
			cout << "Here is child process\n";
			sleep(1);
		}
		exit(0);
	} else {
		for (int i = 0; i< 5; i++){
			cout << "Here is main process\n";
			sleep(1);
		}
	}
	int status;
	waitpid(pid, &status, 0);
	cout << "Exit program"<<endl;
	return 0;
}
