#include <stdio.h>
#include <stdlib.h>
#include <my_std.h>

S_string read_file(const char* cv_filePath)
{
        S_string s_fileContent = {0};
        FILE* iof_file = fopen(cv_filePath, "r");
        if(iof_file == NULL)
        {
                s_fileContent.e_error = FILE_ACCESS_FAILED;
                return s_fileContent;
        }

        fseek(iof_file, 0, SEEK_END);
        s_fileContent.size = ftell(iof_file);
        fseek(iof_file, 0, SEEK_SET);

        if(s_fileContent.size == 0)
        {
                s_fileContent.e_error = FILE_EMPTY;
                return s_fileContent;
        }

        s_fileContent.p_buffer = malloc(s_fileContent.size);
        if(s_fileContent.p_buffer == NULL)
        {
                s_fileContent.e_error = ALLOC_ERROR;
                return s_fileContent;
        }

        fread(s_fileContent.p_buffer, 1, s_fileContent.size, iof_file);

        fclose(iof_file);
        return s_fileContent;
}
