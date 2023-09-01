// QFileInfo fileInfo();
// qDebug () << fileInfo.isFile();
// qDebug () << fileInfo.isDir();

// //#include <sys\stat.h>
// int stat(char *path, struct stat *buf);

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
 
       
int main (int argc, char **argv){
  struct stat buf;
  if(argc != 2){
    printf("Usage: %s [path]\n",argv[0]);
    return 1;
  }
  lstat(argv[1], &buf);
  
  if(S_ISREG(buf.st_mode)){
    printf("File\n");
  }else if(S_ISDIR(buf.st_mode)){
    printf("Directory\n");
  }else if(S_ISLNK(buf.st_mode)){
    printf("Symbolic link\n");
  }
}
