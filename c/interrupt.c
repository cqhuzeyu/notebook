#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
int iteration=0;
char crlf []={0xd,0xa, 0};
void handler(int s)
{
    int c=getchar(); /* read a character */
    printf("got char %c, at count %d %s",c,iteration,crlf);
    if (c=='q') {
        system("stty sane");
        exit(0);
    }
}
int main()
{
    sigset(SIGPOLL, handler); /* set up the handler */
    system("stty raw -echo");
    ioctl(0, I_SETSIG, S_RDNORM); /* ask for interrupt driven input */
    for(;;iteration++);      /* can do other stuff here */
}