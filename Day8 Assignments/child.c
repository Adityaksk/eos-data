#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int ret1,ret2,ret3,s1,s2,s3;
	ret1 = fork();
	if(ret1 == 0)
	{
		ret2 = fork();
		if(ret2 == 0)
		{
			ret3 = fork();
			if(ret3 == 0)
			{
				printf("child3 is child of child2 \n");
				printf("child of %d is %d\n", getppid(), getpid());
				_exit(1);
			}
                        printf(" child2 is child of child1 \n");
			printf("child of %d is %d \n", getppid(), getpid());
			waitpid(ret3,&s1,0);
			_exit(1);
		}
	                printf(" child1 is main child \n");
                        printf("child of %d is %d \n", getppid(), getpid());
                        waitpid(ret2,&s2,0);
                        _exit(1);
                }       
	printf("parent: %d\n", getpid());
	waitpid(ret1,&s3,0);

}

