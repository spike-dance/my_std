#include <my_std.h>

String read_file(char* file_path)
{
        String file_content = {0};
        FILE* file = fopen(file_path, "r");
        if(file == NULL)
        {
                file_content.error = FILE_ACCES_FAILED;
                return file_content;
        }

        fseek(file, 0, SEEK_END);
        file_content.size = ftell(file);
        fseek(file, 0, SEEK_SET);

        if(file_content.size == 0)
        {
                file_content.error = FILE_EMPTY;
                return file_content;
        }

        file_content.buffer = malloc(file_content.size);
        if(file_content.buffer == NULL)
        {
                file_content.error = ALLOC_ERROR;
                return file_content;
        }

        fread(file_content.buffer, 1, file_content.size, file);

        return file_content;
}
