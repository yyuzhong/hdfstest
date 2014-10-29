#include "stdio.h"
#include "stdlib.h"

int main(int argc, char ** argv)
{
    const char* writePath = "/mnt/dfs/yzyan/text/bible.txt";
    //const char* writePath = "./test.c"; 
        FILE *readFile = fopen(writePath, "r");
        if(!readFile) {
          fprintf(stderr, "Failed to open for reading!\n");
          exit(-1);
        }
        char *imgBuffer = (char*) malloc (256);
        if (imgBuffer == NULL)
        {
            exit (2);
        }
        memset(imgBuffer, 0, 256);
        fread(imgBuffer,10,1, readFile);
        printf("read content:  %s \n",imgBuffer);
        printf("ready to close file\n");
        fclose(readFile);

    return 0;
}
