/**
 * Created with IntelliJ IDEA.
 * @Auther: Robin
 * @Date: 2021/6/24 / 9:56
 * @Version: 
 * @Description: TODO MIT-6.S081-util-find
 */

//
// Created by Lenovo on 2021/6/24.
//

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"

char*
fmtname(char *path)
{
    static char buf[DIRSIZ+1];
    char *p;

    // Find first character after last slash.
    for(p=path+strlen(path); p >= path && *p != '/'; p--)
        ;
    p++;

    // Return blank-padded name.
    if(strlen(p) >= DIRSIZ)
        return p;
    memmove(buf, p, strlen(p));
    memset(buf+strlen(p), ' ', DIRSIZ-strlen(p));

    return buf;
}

void
find(char *path, char *name)
{
    char buf[512], *p;
    int fd;
    struct dirent de;
    struct stat st;

    if((fd = open(path, 0)) < 0){
        fprintf(2, "ls: cannot open %s\n", path);
        return;
    }

    if(fstat(fd, &st) < 0){
        fprintf(2, "ls: cannot stat %s\n", path);
        close(fd);
        return;
    }

    switch(st.type){

        case T_FILE:
            if ( 0 == strcmp(fmtname(path), name)) { // 查找到目标文件
                printf("path: %s \n", path);
            }
            break;

        case T_DIR:
            if(strlen(path) + 1 + DIRSIZ + 1 > sizeof buf){
                printf("ls: path too long\n");
                break;
            }
            strcpy(buf, path);
            p = buf+strlen(buf);
            *p++ = '/';

            while(read(fd, &de, sizeof(de)) == sizeof(de)){

                if(de.inum == 0)
                    continue;
                memmove(p, de.name, DIRSIZ);
                p[DIRSIZ] = 0;
                if(stat(buf, &st) < 0){
                    printf("ls: cannot stat %s\n", buf);
                    continue;
                }

                if (0==strcmp(de.name, name) && st.type==T_FILE) { // 类型为文件, 找到之后输出
                    printf("%s \n", buf);
                }
                /* 以下为各个参数的输出结果，供输出打印参考 */
//                printf("fmtname(buf) = %s\n", fmtname(buf));  // find
//                printf("path = %s\n", path);                  // .
//                printf("buf = %s\n", buf);                    // ./find
//                printf("de.name = %s\n", de.name);            // find
//                printf("============================\n");

//                printf("T_DIR = %d, de.name = %s, st.type = %d\n", T_DIR, de.name, st.type);
                if ((strcmp(de.name, "..")) && (strcmp(de.name, ".")) && st.type==T_DIR) { // 递归进入下一层目录
//                    printf("-------get into ------ \n");
                    find(buf, name);
                }
            }
            break;
    }
    close(fd);
}

int
main(int argc, char *argv[])
{
    if(argc < 2){
        find(".", "find");
        fprintf(2, "Usage: find filename.\n");
        exit(0);
    }

    find(argv[1], argv[2]);

    exit(0);
}
