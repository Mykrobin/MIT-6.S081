#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int i;

  if(argc < 2){ // 当输入仅有一个参数时，报错
    fprintf(2, "Usage: rm files...\n");
    exit(1);    // 表示异常退出
  }

  for(i = 1; i < argc; i++){ // 超过一个输入时，进行相应操作并通过 fprintf() 输出信息
    if(unlink(argv[i]) < 0){ // unlink() 函数功能是删除文件，通过返回值判断删除是否成功
      fprintf(2, "rm: %s failed to delete\n", argv[i]);
      break;
    }
  }

  exit(0);
}
