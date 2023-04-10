#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int _putchar(char c);
ssize_t read_txtfile(const char *filename, size_t letters);
int create_file(const char *filename, char *txt_content);
int append_txt_to_file(const char *filename, char *txt_content);

#endif
