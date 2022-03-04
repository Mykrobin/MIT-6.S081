// 时间：2022年3月4日11:15:02

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#define Max 35

int
main(int argc, char *argv[])
{
    int i;
    int temp = 0, num = 0; // 设置最小的素数，当前队列元素个数
    int pipe_p[2]; // 构建管道
    int pid;
    int val[Max]; // 构建数组

    // 初始化数组
    for (i = 1; i < Max; i++)
    {
        val[i] = i+1;
        num ++; // 记录当前数组元素个数
    }
    
    while (num != 0)
    {
        pipe(pipe_p);
        pid = fork();
        if (0 == pid){ // 子进程
            close(pipe_p[1]); // 关闭管道写
            // 从管道读取数据，找到最小素数
            temp = 0;
            for (i = 1; i < Max; i++)
            {   
                read(pipe_p[0], &val[i], sizeof(int));
                if (temp==0 && val[i]!=0)
                {
                    temp = val[i]; // 确定当前最小素数
                }
                
            }
            if (0 != temp)
            {
                printf("prime %d \n", temp); // 每次遍历打印最小素数，当全部元素为0，停止fork   
            } else {
                num = 0;
                break;
            }

            // 筛选素数
            for (i = 1; i < Max; i++)
            {
                if (0 == val[i]%temp) {
                    val[i] = 0;
                    num--;  // 重置当前数组个数，个数为0 的时候停止fork
                }
            }
            close(pipe_p[0]);// 关闭管道读
        } else { // 父进程
            close(pipe_p[0]); // 关闭管道读
            for (i = 1; i < Max; i++)
            {
                // printf("parent prime: %d \n", val[i]);
                write(pipe_p[1], &val[i], sizeof(int)); // 写入管道
            }
            close(pipe_p[1]); // 关闭管道写
            wait(0);
            exit(0);
        }
    }
    
    exit(0);
}