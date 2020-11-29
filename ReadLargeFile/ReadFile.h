#ifndef READFILE_H_
#define READFILE_H_

#include <iostream>
#include <array>
#include <cstdlib>
#include <cstdio>
#include <string.h>
#include <string>

const uint16_t ResizeStep = 64000;

char** read_from_file(const char *name_file, uint64_t *len);
void write_to_file(char **str_to_write,
                   const char *name_file, uint64_t *len);

#endif
