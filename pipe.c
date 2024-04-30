#include<sys/types.h> 
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main(){
	int fd[2];
	pid_t result;
	size_t size;
	char string[] = "Hello, World!";
	char resstring[14];
	//Попытка создать пайп
	if (pipe(fd)<0) {
		//если пайп не удалось вывести печатаем спредупреждающее сообщение
		printf("Can\'t create pipe\n");
		exit(-1);
	}
	result = fork();
	if (result<0){
		printf("Ошибка выполнения fork()\n");
		exit(-1);
	}
	else if (result>0){
		if (close(fd[0])<0){
			printf("Ошибка при закрытии пайп на чтение\n");
			exit(-1);
		}
	
//Запишем в пайп 14 байт
		size = write(fd[1], string,14);
		if(size !=14){
			printf("Can\'t write all string\n");
			exit(-1);
		}
		printf("Процесс родитель записал информацию в пайп и заканчивает работу\n");
		if (close(fd[1])<0){
			printf("Не получилось закрыть исходящий поток\n");
			exit(-1);
		}
	}
	else {
		if (close(fd[1])<0){ 
                	printf("Не получилось закрыть исходящий поток\n");
                	exit(-1);
		}
//Если запись прошла и количество байт меньше, пишем сообщение
		size = read(fd[0],resstring,14);
		if(size<0){
			printf("Can\'t read string\n");
			exit(-1);
		}
//Закрытие пайп для записи
		printf("%s\n", resstring);
		if(close(fd[0])<0){
			printf("Can\'t close output stream\n");
			exit(-1);
		}
	}
	return 0;
}
