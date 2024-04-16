//Программа для иллюстрации работы процесса-родителя и процесса-ребенка 

#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main() {
        
        pid_t procid, parentid;//Индификаторы процессов
        pid_t result;//Результат системного вызова fork()
        int a = 0;// Переменна для проверки работы процессора-родителя и процессе-ребенка
        result = fork();
	a= a+1;
	procid =getpid();//Получение идентификаторатекущего процесса
	parentid = getppid();
	printf("Ид процесса :%d, ид родителя %d, занчение переменной a: %d\n" , procid, parentid ,a);
       return 0;
}
