#include <iostream>
#include "ReadFile.h"


int main()
{
    const char *file_in = "in_file.txt";
    const char *file_out = "out_file.txt";

    char **str_from_file;
    uint64_t total_num_str = 0;

    //load data from file into data structure
    str_from_file = read_from_file(file_in, &total_num_str);

    std::cout << total_num_str;

    //write data to the file
    write_to_file(str_from_file, file_out, &total_num_str);


    return 0;
}
