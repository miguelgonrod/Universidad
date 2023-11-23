#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
int main(int argc, char * argv[])
{
    int p;
    int a;
    int estado;
    int i,j;
    pid_t hijopid;

    if(argc!=3) {
        printf("Argumentos invalidos");
        exit(0);
    }

    p = atoi(argv[1]);
    a = atoi(argv[2]);
    
    for( i=0; i<p-1; i++) {
        for( j=0; j<a; j++) {
            if ((hijopid=fork()) == 0) {
                printf("Soy el proceso: %d- Mi padre es: %d\n\n", getpid(), getppid());
                break;
            }
        } 
        if (hijopid !=0) break;
    }
    
    while ((hijopid = wait(&estado)) != -1);
    return (0);
}