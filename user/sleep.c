#include "kernel/types.h"
#include "user/user.h"

int main(int argc,char *argcv[])
{
	if(argc!=2)
	{
		write(2, "Error message", strlen("Error message"));
	}

	int x = atoi(argcv[1]);
	sleep(x);
	exit();
}

