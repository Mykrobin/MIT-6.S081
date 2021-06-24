/**
 * Created with IntelliJ IDEA.
 * @Auther: Robin
 * @Date: 2021/6/23 / 21:01
 * @Version: 
 * @Description: TODO：MIT-6.S081-util-pingpong
 * 父进程向子进程输入数据，子进程向父进程输入数据 [利用管道双向]
 */

//
// Created by Lenovo on 2021/6/23.
//

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    int pid;
    int ping[2], pong[2];
    char buf[2];
    pipe(ping);
    pipe(pong);

    pid = fork();

    if (pid == 0) { // 子进程
        close(0);
        if(1 == read(ping[0], buf, 1)) {
            printf("%d: received ping\n", getpid());
        }
        close(ping[1]);
        write(pong[1], buf, 1);

    } else {
        write(ping[1], "0", 1);
        wait(0); // 等待子进程结束，控制输出顺序
        if (1 == read(pong[0], buf, 1)) {
            printf("%d: received pong\n", getpid());
        }
    }

    exit(0);
}