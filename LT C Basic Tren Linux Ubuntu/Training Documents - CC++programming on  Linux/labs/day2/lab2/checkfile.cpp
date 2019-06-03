#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
using namespace std;

int main(int argc, char* argv[]){
	if (argc != 2){
		perror("Invalid argument");
		return 1;
	}
	char pathfile[250];
	char directory[250];
	char* slash;
	strncpy(pathfile, argv[1], 250);
	memset(directory, 0, 250);
	slash = strchr(pathfile, '/');
	
	while(slash != NULL){
		strncpy(directory, pathfile, slash - pathfile + 1);
		cout << "Directory: "<< directory << endl;
		if (access(directory, F_OK) == -1){
			fprintf(stderr, "Directory: %s doesn't exist\n", directory);
			return 1;
		}
		if (access(directory, X_OK) == -1){
			fprintf(stderr, "Directory: %s doesn't permiss execution\n", directory);
			cout<<"Set execution permission" << endl;
			if (chmod(directory, S_IRUSR | S_IWUSR | S_IXUSR) == -1){
				perror("Can't set execution permission");
				return 1;
			}
		}
		slash = strchr(slash + 1, '/');
	}
	cout << "pathfile: " << pathfile << endl;
	if (access(pathfile, F_OK) == -1){
		fprintf(stderr, "pathfile: %s doesn't exist\n", directory);
		return 1;
	}
	if (access(pathfile, R_OK) == -1){
		fprintf(stderr, "pathfile: %s doesn't permiss read\n", pathfile);
		return 1;
	}
	
	cout << "pathfile permiss read" << endl;
	
	return 0;
}
