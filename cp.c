#include<stdio.h>
#include<string.h> #include<stdlib.h>
 
#include<fcntl.h> #include<unistd.h> #include<sys/stat.h> #include<fcntl.h>


int main(int argc,char *argv[])
{
int fd_src,fd_des;//fd_src 为读取文件 fd_des 为写入文件char buf[4096];	//128 大小的缓冲区
int num;
if(argc-3) //cp file_src file_des 检查输入参数个数是否正确
{
printf("the format must be:cp file_src file_des"); exit(EXIT_FAILURE);
}

if((fd_src=open(argv[1],O_RDONLY))==-1) //打开 file_src 是否正确
{
perror("open1"); exit(EXIT_FAILURE);

}

if((fd_des=open(argv[2],O_CREAT|O_EXCL|O_WRONLY,0644))==-1) // 打开file_des 是否正确 0644 rw-r--r-- 用户:可读可写 用户组: 可读 其他:可读
{
perror("open2"); exit(EXIT_FAILURE);
}

do
{
num=read(fd_src,buf,128);//读取文件write(fd_des,buf,num); //写入文件
}while(num==4096);


close(fd_src);//关闭文件close(fd_des);//关闭文件return 0;
}

