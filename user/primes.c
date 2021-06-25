/**
 * Created with IntelliJ IDEA.
 * @Auther: Robin
 * @Date: 2021/6/23 / 22:01
 * @Version:
 * @Description: TODO：TODO：MIT-6.S081-util-primes
 */

//
// Created by Lenovo on 2021/6/23.
//

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#define Max 35

int
main(int argc, char *argv[])
{
    int j;
    int val[Max];
    int pid, p[2], temp, prime=2, index=Max;

    // init
    for (j = 1; j <= Max; ++j) {
        val[j] = j+1;
    }

    while (val[1] != 0) {

        pipe(p);  // 注意pipe 与 fork的顺序
        pid = fork();

        if (pid == 0) { // child
            close(p[1]);
            index = 0;
            while (read(p[0], &temp, sizeof(temp)) != 0) { // 找到下一次prime
                if (index == 0) { // 接收到的第一个数
                    prime = temp;
                    index++;
                } else {
                    if (temp%prime !=0) { // 筛选
                        val[index] = temp;
                        index++;
                    } else{
                        val[index] = 0; // 不符合条件的置为0
                    }
                }
            }
            printf("prime %d\n", prime);
            close(p[0]);

        } else { // parent
            close(p[0]);
            for ( j = 1; j <= index; ++j) {
                write(p[1], &val[j], sizeof(val[j]));
            }
            close(p[1]);

            wait(0);
            exit(0);
        }
    }

    exit(0);
}