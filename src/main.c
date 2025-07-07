#include "../include/input.h"
#include "../include/output.h"

int main (int argc, char **argv)
{
    Input *fileInfo = read_input(argc, argv);
    const char* fileName = get_file_name(fileInfo);
    bool isatty = is_input_tty(fileInfo);
    print_output(fileName, isatty);

    free(fileInfo);
    return 0;
}

