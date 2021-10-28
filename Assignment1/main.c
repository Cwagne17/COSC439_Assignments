#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(){
	char buff[21];
	// Write your code here!
	/*
	 open()
	 creat()
	 read()
	 lseek()
	 write()
	*/
	int fileRead = open("lseek.txt", O_RDONLY);
	int fileWrite = creat("output.txt", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

	if (fileRead == -1) {
		printf("ERROR opening 'lseek.txt'");
		return 0;
	}
	int count = 4;
	lseek(fileRead, count, SEEK_SET); // Init the current position of file to index 4
	while(read(fileRead, buff, 1)) { // Reads char at cursor
		printf("%.*s", (int)sizeof(buff), buff); // Prints char in buff
		write(fileWrite, buff, 1);
		count += 5; // Incr by 5
		lseek(fileRead, count, SEEK_SET); // Sets file index to 4 + 5i
	}
	close(fileRead);
	close(fileWrite);
	return 0; 
}
