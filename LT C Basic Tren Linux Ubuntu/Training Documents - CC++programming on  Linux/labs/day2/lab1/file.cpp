#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

struct record{
	char cd[20];
	char nameSong[30];
	char artist[30];
};

void printRecord(record* buff){
	printf("\n------------------------\n");
	printf("cd: %s\n", buff->cd);
	printf("name of song: %s\n", buff->nameSong);
	printf("artist: %s\n", buff->artist);
	printf("------------------------\n\n");
}

int readRecord(FILE* file, int number, record* buff){
	if (fseek(file, 0, SEEK_END) == -1){
		perror("Can't move file control to end of file");
		return 0;
	}
	int size = ftell(file);
	if (number*sizeof(record) >= size){
		printf("The record %d doesn't exist in file\n", number);
		return 0;
	}
	if (fseek(file, number*sizeof(record), SEEK_SET) == -1){
		fprintf(stderr, "Can't move file control to postion: %d\n", 
			number*sizeof(record));
		return 0;
	}
	if (fread(buff, sizeof(record), 1, file) <= 0){
		perror("Can't read data from file");
		return 0;
	}
	printf("Read record %d is successful:\n", number);
	printRecord(buff);
	return 1;
}

int writeRecord(FILE* file, int number, record* buff){
	if (fseek(file, number*sizeof(record), SEEK_SET) == -1){
		fprintf(stderr, "Can't move file control to postion: %d\n", 
			number*sizeof(record));
		return 0;
	}
	if (fwrite(buff, sizeof(record), 1, file) <= 0){
		perror("Can't write data to file");
		return 0;
	}
	printf("write record %d is successful\n", number);
	return 1;
}

int main(){
	record buff[1];
	FILE* file;
	if ((file = fopen("record.dat", "r+")) == NULL)
		if ((file = fopen("record.dat", "w+")) == NULL)
			perror("Can't open file");
	
	strcpy(buff->cd, "love songs");
	strcpy(buff->nameSong, "Song tinh");
	strcpy(buff->artist, "TuanVA6");
	writeRecord(file, 0, buff);
	
	strcpy(buff->cd, "love songs");
	strcpy(buff->nameSong, "Mat den");
	strcpy(buff->artist, "TuanVA6");
	writeRecord(file, 1, buff);
	
	strcpy(buff->cd, "Rock");
	strcpy(buff->nameSong, "Cay bang");
	strcpy(buff->artist, "TuanVA6");
	writeRecord(file, 9, buff);
	
	strcpy(buff->cd, "Rock");
	strcpy(buff->nameSong, "Tam hon cua da");
	strcpy(buff->artist, "TuanVA6");
	writeRecord(file, 10, buff);
	
	memset(buff, 0, sizeof(buff));
	readRecord(file, 0, buff);
	memset(buff, 0, sizeof(buff));
	readRecord(file, 1, buff);
	memset(buff, 0, sizeof(buff));
	readRecord(file, 5, buff);
	memset(buff, 0, sizeof(buff));
	readRecord(file, 9, buff);
	memset(buff, 0, sizeof(buff));
	readRecord(file, 10, buff);
	memset(buff, 0, sizeof(buff));
	readRecord(file, 11, buff);
	
	int fd = fileno(file);
	lseek(fd, 0, SEEK_SET);
	record* addr = (record*)mmap(NULL, 11*sizeof(record), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if ((void*)addr == (void*)-1){
		perror("Can't map file to memory");
		return 1;
	}
	record* ptr = addr;
	ptr += 10;
	printf("record 10:\n");
	printRecord(ptr);
	strcpy(ptr->cd, "Vang");
	strcpy(ptr->nameSong, "Ve dau doi mat nguoi thuong");
	strcpy(ptr->artist, "TuanVA6");
	printf("record 10:\n");
	printRecord(ptr);
	msync(addr, 11*sizeof(record), MS_SYNC);
	memset(buff, 0, sizeof(buff));
	readRecord(file, 10, buff);
	
	close(fd);
	fclose(file);
	munmap(addr, 11*sizeof(record));
	
	return 0;
}

