#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main  () {
	int fd;
	size_t size;
	char string[17];
	if((fd = open("file.txt",O_RDONLY))<0) {
	printf("ошибка при открытии файла на чтение\n");
	exit(-1);
	}
	size = read(fd, string, 17);
	if (size !=17){
		printf("Не удалось прочетать всю строку файла\n");
		exit(-1);
	}
	printf("%s", string);
	if(close(fd)<0){
		printf("Не улдалось закрыть файл\n");
		exit(-1);
	}
	return 0;
}





