#include <stdio.h>
#include <stdlib.h>
#include <my_std.h>

S_string read_file(const u8* cvu8FilePath)
{
        S_string sFileContent = {0};
        FILE* iofFile = fopen(cvu8FilePath, "r");
        if(iofFile == NULL)
        {
                sFileContent.eError = FILE_ACCESS_FAILED;
                return sFileContent;
        }

        fseek(iofFile, 0, SEEK_END);
        sFileContent.u32Size = ftell(iofFile);
        fseek(iofFile, 0, SEEK_SET);

        if(sFileContent.u32Size == 0)
        {
                sFileContent.eError = FILE_EMPTY;
                return sFileContent;
        }

        sFileContent.pBuffer = malloc(sFileContent.u32Size);
        if(sFileContent.pBuffer == NULL)
        {
                sFileContent.eError = ALLOC_ERROR;
                return sFileContent;
        }

        fread(sFileContent.pBuffer, 1, sFileContent.u32Size, iofFile);

        fclose(iofFile);
        return sFileContent;
}
