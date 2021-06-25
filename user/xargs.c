/**
 * Created with IntelliJ IDEA.
 * @Auther: Robin
 * @Date: 2021/6/24 / 20:24
 * @Version: 
 * @Description: TODO MIT-6.S081-util-xargs
 */

//
// Created by Lenovo on 2021/6/24.
//

#include "kernel/types.h"
#include "kernel/param.h"
#include "user/user.h"

#define MAXLINE 1024

int main(int argc, char *argv[])
{
    char line[MAXLINE];    // 记录管道符号前的输出参数, 后面参数交给argv
    char* params[MAXARG];  // 参数
    int n, args_index = 0;
    int i;

    // 若输入命令为 echo h t | xargs echo b, 则以下输出为
//    printf("argv[0] = >%s<\n", argv[0]); // >xargs<
//    printf("argv[1] = >%s<\n", argv[1]); // >echo<
//    printf("argv[2] = >%s<\n", argv[2]); // >b<

    char* cmd = argv[1];
//    printf("cmd = %s\n", cmd); // echo
    for (i = 1; i < argc; i++) params[args_index++] = argv[i];
//    printf("args_index = >%d< \n", args_index); // >2<
//    printf("params = >%s< >%s<\n", params[0], params[1]); // >echo< >b<

    while ((n = read(0, line, MAXLINE)) > 0)
    {
//        printf("n = %d\n", n); // 4
//        printf("line[0] = >%c<\n", line[0]); // >h<
//        printf("line[1] = >%c<\n", line[1]); // > <
//        printf("line[2] = >%c<\n", line[2]); // >t<
//        printf("line[3] = >%c<\n", line[3]); // >\n<

        if (fork() == 0) // child process
        {
            char *arg = (char*) malloc(sizeof(line));
//            printf("sizeof(line) = >%d<\n", sizeof(line)); // >1024<
//            printf("line = >%s<\n", line); // >h t\n<

            int index = 0;
            // 将line中内容转化为输出参数
            for (i = 0; i < n; i++) // n = 4
            {
                if (line[i] == ' ' || line[i] == '\n')
                {
                    arg[index] = 0;
                    params[args_index++] = arg;
                    index = 0;
                    arg = (char*) malloc(sizeof(line));
                }
                else arg[index++] = line[i];
            }
            arg[index] = 0;
            params[args_index] = 0;
//            printf("cmd = >%s<, params = >%s< >%s< >%s< >%s< >%s<\n",
//                    cmd, params[0], params[1], params[2], params[3], params[4]); //cmd = >echo<, >echo< >b< >h< >t< >(null)<
            exec(cmd, params); // 执行命令
        }
        else wait(0);
    }
    exit(0);
}