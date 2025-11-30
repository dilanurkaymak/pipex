#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
int main(void) {
	int fork_donus_degeri = fork();
	int sonuc;
	if (fork_donus_degeri == 0) { // burasi child processte calisir cunku == 0 degerini o saglayabilir
		sonuc = 0;
		int i;
		for(i=0;i<10;i++) {
			sleep(1);
			sonuc = sonuc + 1; 
			printf("child_dongu_%d : sonuc : %d \n", i, sonuc);
		}
		printf("CHILD SONUCU : %d \n", sonuc);
	}
	else if (fork_donus_degeri > 0) { // burasi parent processte calisir cunku > 0 degerini o saglayabilir
		sonuc = 1;
		int i;
		for(i=0;i<10;i++) { 
			sleep(1);
			sonuc = sonuc * 2;
			printf("parent_dongu_%d : sonuc : %d \n", i, sonuc);
		}
		printf("PARENT SONUU : %d \n", sonuc);
	} 
	else if (fork_donus_degeri == -1) {
		printf("ERROR : \n %d", errno);
		return 1;
	}
	return 0;
}
