#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

"Đăng đã edit file này"

"Tân đã edit file này"
int GiaiThua (int n)
{

    int result = 1;
    for(int i=1; i<=n; i++)
    {
        result *= i;
    }
    return result;
}
int main(int argc, char* argv[])
{
	char result [100];
	int kq;
	int fp[2];
 	int pid;

	if(argc<2) {
 		printf("Doi so thieu.\n");
 		return -1;
 	}

	int n = atoi(argv[1]);
	if(n <3)
	{	
		printf("so truyen vao phai lon hon 3 %d",n);
		return -1;
	}
	if(pipe(fp)==0) {
 		pid = fork();
 		if(pid<0) {printf("Fork failed\n"); return -1;}
 		else if(pid==0) {
 			printf("Data from child: %s\n", argv[1]);
			int gt=GiaiThua(n);
            		printf("%d! = %d\n", n, gt);
            		close(fp[0]);
            		write(fp[1], &gt, sizeof(gt));
 	}
 	else {
 		close(fp[1]);
 		read(fp[0], &kq, sizeof(int));
 		printf("Read from child: %d\n", kq);
 	}
}
	else
    {
        printf("Pile failed\n"); 
        return -2;
    }
}
	
