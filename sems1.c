#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
int main () {
	int semid; // идентификатор ipc для массива  семафоров
	char pathname[] = "forftok.ipc"; //файл используемый для генерации ipc  ключа
	key_t key; //ipc ключ
	struct sembuf mybuf;// стректура для задания операции над семафором
	// генерация ipcключа
	if((key = ftok(pathname, 0)) < 0) {
		printf("Не удалось сгенерировать ipc ключ\n");
		exit(-1);
	}
	//получение доступа к массиву семафоров по ipc ключу
	if ((semid = semget(key, 1, 0666 | IPC_CREAT)) <0) {
		printf("не удалось получить доступ к массиву семафоров\n");
		exit(-1);
	}
	// заполняем структуру myduf кодами операций над семафором
	mybuf.sem_op = 1;
	mybuf.sem_flg = 0;
	mybuf.sem_num = 0;
	//выполнение операций
	if (semop(semid, &mybuf, 1) < 0) {
		printf("не удалось выполнить операцию над семафором 0\n");
		exit(-1);
	}
	printf("Условие установлено\n");
	return 0;
}
