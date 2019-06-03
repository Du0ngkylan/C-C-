#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
void searchfile(char* tab, char* directory, char* filename);
int main(int argc, char* argv[]){
	if (argc != 3){
		cout<<"Invalid argument"<<endl;
		return 1;
	}
	char directory[250];
	char file[30];
	strncpy(directory, argv[1], 250);
	strncpy(file, argv[2], 30);
	cout << "directory: " << directory << endl;
	cout << "file: " << file << endl;
	if ((access(directory, F_OK) == -1) || (access(directory, X_OK) == -1)){
		perror("Directory doesn't exist or can't access");
		return 1;
	}
	char tab[30];
	memset(tab, 0, 30);
	strcpy(tab, "");
	searchfile(tab,directory, file);
	return 0;
}

void searchfile(char* tab, char* directory, char* filename){
	chdir(directory);
	cout << tab << "searchfile directory: " << directory << endl;
	DIR* dirp = opendir(".");
	dirent* direntptr;
	while((direntptr = readdir(dirp)) != NULL){
		struct stat buf;
		if (stat(direntptr->d_name, &buf) == -1){
			perror("Can't read information of file");
			closedir(dirp);
			return;
		}
		if ((buf.st_mode & S_IFMT) == S_IFDIR){
			if (strcmp(direntptr->d_name, "..") && strcmp(direntptr->d_name, ".")){
				char tab1[30];
				strcpy(tab1, tab);
				strcat(tab1, "\t");
				searchfile( tab1, direntptr->d_name, filename);
				chdir("..");
			}
		} else {
			cout<< tab <<  "\tdirentptr->d_name: " << direntptr->d_name << endl;
			if (strcmp(direntptr->d_name, filename) == 0){
				cout << tab <<  "\tDirectory of file is: " << directory << "/" <<
						direntptr->d_name <<endl;
				break;
			}
		}
	}
	closedir(dirp);
}

