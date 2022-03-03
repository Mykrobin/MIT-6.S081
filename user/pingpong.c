#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    int pid;
    int ping[2], pong[2]; // 构建父子进程通讯的双管道
    char buf[1];
    pipe(ping);
    pipe(pong);

    pid = fork();  // fork 之后父子进程都链接到 ping pong 两个管道描述符
    // 管道描述符：0 代表读端口； 1 代表写端口
    if (pid == 0) { // 子进程目标：接收父进程写入ping管道的内容，并向pong写入内容
        close(pong[0]); // 关闭pong管道读
        close(ping[1]); // 关闭ping管道写
        if(1 == read(ping[0], buf, 1)) { // 从ping管道读
            printf("%d: received ping\n", getpid()); 
        }
        close(ping[0]); // 读取ping 管道内容后关闭
        write(pong[1], buf, 1); // 向pong管道写
        close(pong[1]); // 写入pong 管道后关闭
    } else { // 父进程目标：接收子进程写入pong管道的内容
        close(pong[1]); // 关闭pong 管道写
        close(ping[0]); // 关闭ping 管道读
        write(ping[1], "c", 1); // 向ping 管道写入
        close(ping[1]); // 写入后关闭
        wait(0); // 等待子进程结束，控制输出顺序
        if (1 == read(pong[0], buf, 1)) { // 读入pong 管道内容
            printf("%d: received pong\n", getpid());
        }
        close(pong[0]); // 读后关闭pong 管道读
    }

    exit(0);
}