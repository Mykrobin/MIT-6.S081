// 时间：2022年3月4日15:00:25
// 参考：ls.c 查看如何如何查看目录 

#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"

char*
fmtname(char *path) // 功能：遍历当前目录下的文件及路径
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

//   printf("path: >%s< , name: >%s< \n",path, name);
// 对错误的输入或路径返回对应信息
  if((fd = open(path, 0)) < 0){
    fprintf(2, "ls: cannot open %s\n", path);
    return;
  }

  if(fstat(fd, &st) < 0){
    fprintf(2, "ls: cannot stat %s\n", path);
    close(fd);
    return;
  }

// 查找对应内容
  switch(st.type){
  case T_FILE:  // 查找到文件，直接打印当前目录
    if (0 == strcmp(fmtname(path), name)) {
        printf("path: %s \n", path);
    }
    break;

  case T_DIR:  // 查找到目录类型则进一步进入下一层子目录进行查找
    if(strlen(path) + 1 + DIRSIZ + 1 > sizeof buf){
      printf("ls: path too long\n"); // 定义文件目录名称长度为14
      break;
    }
    strcpy(buf, path);
    // printf("buf: >%s< strlen(buf): %d \n", buf, strlen(buf));
    p = buf+strlen(buf);
    // printf("p: >%s< \n", p);
    *p++ = '/';

    while(read(fd, &de, sizeof(de)) == sizeof(de)){
      
      if(de.inum == 0) continue;  // dirent 结构体包含 inum 和 名称，inum对应inode号 （fs.h 中定义）
      memmove(p, de.name, DIRSIZ);
      p[DIRSIZ] = 0;

      if(stat(buf, &st) < 0){
        printf("ls: cannot stat %s\n", buf);
        continue;
      }

      // 输出文件类型对应的目录
      if (0==strcmp(de.name, name) && st.type==T_FILE) {
          printf("%s \n", buf);
      }
      
      //  当前目录中包含子目录，采用递归方式进行查找
      if ((strcmp(de.name, ".")) && (strcmp(de.name, "..")) && (st.type==T_DIR))
        find(buf, name);
    }
    break;
  }
  close(fd);
}

int
main(int argc, char *argv[])
{
  if(argc < 2){ // 使用不当
    fprintf(2, "Usage: find filename. \n");
    exit(0);
  }
  find(argv[1], argv[2]); // 分别对应路径名称和文件名称
  exit(0);
}