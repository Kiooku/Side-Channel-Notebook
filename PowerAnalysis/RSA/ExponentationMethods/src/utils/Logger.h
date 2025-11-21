#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>

// https://stackoverflow.com/questions/3585846/color-text-in-terminal-applications-in-unix
#define RED   "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW   "\x1B[33m"
#define BLUE   "\x1B[34m"
#define MAGENTA   "\x1B[35m"
#define CYAN   "\x1B[36m"
#define WHITE   "\x1B[37m"
#define RESET "\x1B[0m"

// https://en.wikipedia.org/wiki/Variadic_macro_in_the_C_preprocessor#Example
// https://www.theurbanpenguin.com/4184-2/
#define LOG_INFO(fmt, ...) \
    printf(YELLOW "[INFO] " RESET fmt, ##__VA_ARGS__)

#define LOG_ERROR(fmt, ...) \
    fprintf(stderr, RED "[ERROR] " RESET fmt, ##__VA_ARGS__)

#define LOG_DEBUG(fmt, ...) \
    printf(BLUE "[DEBUG] " RESET fmt, ##__VA_ARGS__)

#define LOG_TITLE(fmt, ...) \
    printf(MAGENTA fmt RESET, ##__VA_ARGS__)

#define LOG_SECTION(fmt, ...) \
    printf(CYAN fmt "\033[0m" RESET, ##__VA_ARGS__)

#define LOG_PERFORMANCE(fmt, ...)  \
    printf(GREEN "[PERFORMANCE] " RESET fmt , ##__VA_ARGS__)


#endif //LOGGER_H
