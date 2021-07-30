//Processes and child processes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	printf("Hey there, I am %d. My wife is pregnant. I'm about to be a parent\nEnter five numbers let my child sum 'em for you when he/she is born\n", (int) getpid());
	int num1=0,num2=0,num3=0,num4=0,num5=0;
	/*parent taking input*/
	scanf("%d %d %d %d %d", &num1, &num2, &num3, &num4, &num5); 
	/*Creating a child process*/
	int new_child_process = fork();
	/*If child process is not created*/
	if(new_child_process<0){
		fprintf(stderr, "\nMiscarriage. The fork attempt failed!!!\n");
	/*If child process is created, sum numbers and print results*/
	}else if (new_child_process == 0){
		printf("...push!\n...pusshh!!\n...pussshhh!!!\n..............\nHeyya, I am that dude's child and my name is %d\nLemme sum  you numbers for you!\n", (int) getpid());
		int sum = num1 + num2 + num3 + num4 + num5;
		printf("Result: %d + %d + %d + %d + %d = %d\n",num1,num2,num3,num4,num5, sum);
	/*If all child processes are done, parent says final words, lol*/
	}else{
		int wait_value = wait(NULL); 
		printf("\n...\n...\nHey guys, I am back. I am %d, parent of %d\nHope my child did a good job!\n", (int) getpid(), new_child_process);
	}
	return 0;
}
                                                                                                         


