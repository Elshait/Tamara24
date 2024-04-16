#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc, char *argv[], char *envp[]) {
	int result;
	result = execle("/bin/cat", "/bin/cat", "otchetPT.txt", 0, envp);
	printf("Ошибка при выполнении системного execle()\n");
	exit(-1);
	return 0;
}
