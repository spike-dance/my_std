#ifndef MY_STD_H
#define MY_STD_H

#include <stdint.h>

#define MAX(x, y) (x > y : x ? y)
#define MIN(x, y) (x < y : x ? y)

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef const uint8_t cu8;
typedef const uint16_t cu16;
typedef const uint32_t cu32;
typedef const uint64_t cu64;

typedef const int8_t ci8;
typedef const int16_t ci16;
typedef const int32_t ci32;
typedef const int64_t ci64;

typedef enum
{
        NO_ERROR,

        FILE_EMPTY,

        ALLOC_ERROR,
        FILE_ACCESS_FAILED,
        CREATION_FAILED
} E_error;

typedef struct
{
        u32 u32Size;
        void* pBuffer;
        E_error eError;
} S_string;

#define STRING_ALLOC(x) {.u32Size = x, .pBuffer = malloc(x)}

#define ANSI_RED_TEXT(x) "\e[0;31m" x "\e[0m"
#define ANSI_GREEN_TEXT(x) "\e[0;32m" x "\e[0m"
#define ANSI_YELLOW_TEXT(x) "\e[0;33m" x "\e[0m"
#define ANSI_BLUE_TEXT(x) "\e[0;34m" x "\e[0m"
#define ANSI_PURPLE_TEXT(x) "\e[0;35m" x "\e[0m"
#define ANSI_CYAN_TEXT(x) "\e[0;36m" x "\e[0m"

extern S_string read_file(const u8* cvu8FilePath);

#endif
