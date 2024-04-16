//подключение библеотек
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
//главная функция программы с аргументом 
int main(int argc, char *argv[], char *envp[]) {
	int result; 
	//запуск программы cat с аргументом отчетпт.тчт
	result = execle("/bin/cat", "/bin/cat", "otchetPT.txt", 0, envp);
	//принтф выполняется тольо в случае ошибки вызова эксесл
	printf("Ошибка при выполнении системного execle()\n");
	exit(-1);
	return 0; //никогда не выполняется
}
