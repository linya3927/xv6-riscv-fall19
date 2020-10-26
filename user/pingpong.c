#include "kernel/types.h"
#include "user/user.h"

int main(int argv,char* argc[])
{
        int child_fd[2];
        int parent_fd[2];
        pipe(child_fd);
        pipe(parent_fd);
        char buf[100];
        if(fork()==0)
        {
                //children
                read(parent_fd[0],buf,4);
                printf("%d: received %s\n",getpid(),buf);
                write(child_fd[1],"pong",strlen("pong"));

        }
        else
        {
                write(parent_fd[1],"ping",strlen("ping"));
                read(child_fd[0],buf,4);
                printf("%d: received %s\n",getpid(),buf);
        }

        exit();
}

