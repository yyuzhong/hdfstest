#include "hdfs.h"
int main(int argc, char ** argv)
{
    hdfsFS fs = hdfsConnect("master.pvamucscloud.edu", 8020);
    const char* writePath = "/tmp/testfile.txt";
    hdfsFile writeFile = hdfsOpenFile(fs, writePath, O_WRONLY | O_CREAT, 0, 0, 0);
    if(!writeFile)
    {
        fprintf(stderr, "Failed to open %s for writing!/n", writePath);
        exit(-1);
    }
    char* buffer = "Hello, World! why failed ?";
    tSize num_written_bytes = hdfsWrite(fs, writeFile, (void*)buffer, strlen(buffer) + 1);
    if(hdfsFlush(fs, writeFile))
    {
        fprintf(stderr, "Failed to 'flush' %s/n", writePath);
        exit(-1);
    }
    hdfsCloseFile(fs, writeFile);

        hdfsFile readFile = hdfsOpenFile(fs, "/tmp/testfile.txt", O_RDONLY, 0, 0, 0);
        if(!readFile) {
          fprintf(stderr, "Failed to open for reading!\n");
          exit(-1);
        }
        long lSize = hdfsAvailable(fs,readFile);
        printf("get the file size %d\n",lSize);
        char *imgBuffer = (char*) malloc (lSize);
        if (imgBuffer == NULL)
        {
            exit (2);
        }
        hdfsSeek(fs,readFile,0);
        hdfsRead(fs,readFile,imgBuffer,lSize);
        printf("read content:  %s \n",imgBuffer);
        printf("ready to close file\n");
        hdfsCloseFile(fs,readFile);
        

    //hdfsFlush(fs,writeFile);
    hdfsDisconnect(fs);   
    return 0;
}
