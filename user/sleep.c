/**
 * Created with IntelliJ IDEA.
 * @Auther: Robin
 * @Date: 2021/6/22 / 23:44
 * @Version: 
 * @Description: TODO: MIT-6.S081-util-sleep
 */

//
// Created by Lenovo on 2021/6/22.
//

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    int n;

    if(argc < 2){
        fprintf(2, "Usage: sleep n ticks.\n");
        exit(1);
    }

    n = atoi(argv[1]);
    sleep(n);  /* 参数n是如何传到内核的？*/

    exit(0);
}

