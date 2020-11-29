#include "ReadFile.h"


char **read_from_file(const char *name_file, uint64_t *len)
{
    char buffer[1000];
    int64_t numbers_of_lines = 0;

    //determining the memory size for lines
    uint64_t arr_length = ResizeStep;

    //allocate space for arr_length char*
    char **lines = (char**) malloc(arr_length * sizeof(char*));
    char *str;

    FILE *file_in;
    file_in = fopen(name_file, "r");

    if(!file_in){
        std::cerr << "File can not open!" << std::endl;
        exit(EXIT_FAILURE);
    }
    else{

       if(file_in != nullptr){

            while(fgets(buffer, 1000, file_in)){

                //if data structure is full
                if(numbers_of_lines == arr_length){

                    //adding a new size
                    arr_length += ResizeStep;

                    //reallocating the data structure with a new size
                    char **new_lines = (char**) realloc(lines, arr_length * sizeof(char*));

                    if(!new_lines){
                        fprintf(stderr, "Can not reallocate memory!\n");
                        exit(1);
                    }
                    //we give the new size of the data structure to the old address
                    lines = new_lines;
                }

                //get the length of the string in the buffer
                uint64_t length_str = strlen(buffer);

                //allocate memory according to the length of the string
                str = (char*) malloc((length_str + 1) * sizeof(char*));

                strcpy(str, buffer);

                //insert a line in a data struct
                lines[numbers_of_lines] = str;

                ++numbers_of_lines;

            }

       }
    }

    fclose(file_in);

    *len = numbers_of_lines;

    return lines;
}

void write_to_file(char **str_to_write, const char * name_file, uint64_t *len)
{
    FILE *out_file;

    out_file = fopen(name_file, "w");

    if(!out_file){
        std::cerr << "File can not open!" << std::endl;
        exit(EXIT_FAILURE);
    }
    else{

        for(int64_t i{0}; i != *len; ++i){

        fputs(str_to_write[i], out_file);
    }

  }

    fclose(out_file);

}

