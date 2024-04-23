#include<sys/types.h> 
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main(){
	int fd[2];
	size_t size;
	char string[] = "Hello, World!";
	char resstring[14];
	//Попытка создать пайп
	if (pipe(fd)<0){
	//если пайп не удалось вывести печатаем спредупреждающее сообщение
	printf("Can\'t create pipe\n");
	exit(-1);
}
//Запишем в пайп 14 байт
	size = write(fd[1], string,14);
	if(size !=14){
	printf("Can\'t write all string\n");
	exit(-1);
}
//Усли запись прошла и количество байт меньше, пишем сообщение
	size = read(fd[0],resstring,14);
	if(size<0){
	printf("Can\'t read string\n");
	exit(-1);
}
	printf("%s\n",resstring);
	if(close(fd[0])<0){
	printf("Can\'t close output stream\n");
}
	return 0;
}
