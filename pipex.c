#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
	int main(void) { 
		printf("Hello, World \n"); 
		int fork_donus_degeri = fork(); 
		printf("Bye Bye, World \n");
		printf("fork donus degeri : %d", fork_donus_degeri);
		return 0; 
	} 
