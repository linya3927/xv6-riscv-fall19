#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/param.h"
#include "user/user.h"

int main(int argc,char* argv[])
{
        char buf[256]={0};
        char buf2[32][32];
        int argv_len = 0;
        for(int i=1; i<argc;i++)
        {
               strcpy(buf2[i-1],argv[i]);
              // buf2[i-1] = argv[1];
        }
        char *last[32];

        for(int i=0;i<32;i++){
                last[i]=buf2[i];
        }
        int num=0;
        while((num=read(0,buf,sizeof(buf)))>0)
        {


                argv_len=argc-1;

                char *c = buf2[argv_len];
                 for (char *p = buf; *p; p++) {
                         if (*p == ' ' || *p == '\n') {
                                 *c = '\0';
                                 argv_len++;
                                 c = buf2[argv_len];
                } else
                         *c++ = *p;
                 }
                 *c = '\0';
                 argv_len++;
                 last[argv_len] = 0;

                if (argv_len >= MAXARG){
                         printf("xargs too many args\n");
                         exit();
                 }
                 if (argv_len < 1){
                         printf("xargs too few args\n");
                         exit();
                 }

                 if(fork())
                 {
                         wait();
                 }
                 else
                 {
                         exec(last[0],last);

                 }
        }

        exit();
}


