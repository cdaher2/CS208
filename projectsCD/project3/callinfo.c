/* callinfo.c
 * displays integers provided by common defs for read, write, lseek, ...
 */

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>

int main(void) {
   printf("End Of File:\n");
   printf("EOF = %d\n", EOF);
   printf("3 access modes:\n");
   printf("O_RDONLY = %d\n", O_RDONLY);
   printf("O_WRONLY = %d\n", O_WRONLY);
   printf("O_RDWR   = %d\n", O_RDWR);
   printf("\n");
   printf("3 feature flags:\n");
   printf("O_APPEND = %4d %3x %4o\n", O_APPEND, O_APPEND, O_APPEND);  
              // default is to start at beginning 
   printf("O_TRUNC  = %4d %3x %4o\n", O_TRUNC,  O_TRUNC, O_TRUNC);   
              // sets length of file zero (deletes contents)
   printf("O_CREAT  = %4d %3x %4o\n", O_CREAT, O_CREAT, O_CREAT);   // creates the file, if necessary
                                         // if O_CREAT used permissions must be specified
   printf("\n");
   printf("9 permission bits:\n");
   printf("Symbol   = dec hex oct\n");
   printf("S_IRUSR  = %3d %3x %3o\n", S_IRUSR, S_IRUSR, S_IRUSR);   //   Read permission for owner
   printf("S_IWUSR  = %3d %3x %3o\n", S_IWUSR, S_IWUSR, S_IWUSR);   //  Write permission for owner
   printf("S_IXUSR  = %3d %3x %3o\n", S_IXUSR, S_IXUSR, S_IXUSR);   //Execute permission for owner
   printf("S_IRGRP  = %3d %3x %3o\n", S_IRGRP, S_IRGRP, S_IRGRP);   //   Read permission for group
   printf("S_IWGRP  = %3d %3x %3o\n", S_IWGRP, S_IWGRP, S_IWGRP);   //  Write permission for group
   printf("S_IXGRP  = %3d %3x %3o\n", S_IXGRP, S_IXGRP, S_IXGRP);   //Execute permission for group
   printf("S_IROTH  = %3d %3x %3o\n", S_IROTH, S_IROTH, S_IROTH);   //   Read permission for others
   printf("S_IWOTH  = %3d %3x %3o\n", S_IWOTH, S_IWOTH, S_IWOTH);   //  Write permission for others
   printf("S_IXOTH  = %3d %3x %3o\n", S_IXOTH, S_IXOTH, S_IXOTH);   //Execute permission for others
   printf("\n");

   printf("3 seek locations for lseek:\n");
   printf("Symbol    = decimal\n");
   printf("SEEK_SET  = %3d\n", SEEK_SET);
   printf("SEEK_CUR  = %3d\n", SEEK_CUR);
   printf("SEEK_END  = %3d\n", SEEK_END);

}

