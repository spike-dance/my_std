#ifndef MY_STD_H
#define MY_STD_H

#include <stdint.h>

#define MAX(x, y) (x > y : x ? y)
#define MIN(x, y) (x < y : x ? y)

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

typedef enum
{
        NO_ERROR,

        FILE_EMPTY,

        ALLOC_ERROR,
        FILE_ACCESS_FAILED,
        CREATION_FAILED
} Error_enum;

typedef struct
{
        size_t size;
        void* buffer;
        Error_enum error;
} String;

#define STRING_ALLOC(x) {.size = x, .buffer = malloc(x)}

#define ANSI_RED_TEXT(x) "\e[0;31m" x "\e[0m"
#define ANSI_GREEN_TEXT(x) "\e[0;32m" x "\e[0m"
#define ANSI_YELLOW_TEXT(x) "\e[0;33m" x "\e[0m"
#define ANSI_BLUE_TEXT(x) "\e[0;34m" x "\e[0m"
#define ANSI_PURPLE_TEXT(x) "\e[0;35m" x "\e[0m"
#define ANSI_CYAN_TEXT(x) "\e[0;36m" x "\e[0m"

extern String read_file(char* file_path);

#endif
