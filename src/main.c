#include "../include/input.h"
#include "../include/output.h"

int main (int argc, char **argv)
{
    int exitValue = 0;
    parseArgs(argc, argv);
    bool istty = check_input_source();
    if (istty) printf("Input comming from terminal\n");
    else printf("Input coming from non-tty stdin or pipe\n");
    
    if ((argc == 1 && isatty(STDIN_FILENO)) || (argc == optind && isatty(STDIN_FILENO)))
    {
        char temp;
        while(1)
        {
            scanf("%c" ,&temp);
            printf("%c" ,temp);
        }
    }
    for (int i = optind; i < argc; i++)
    {
        Input *fileInfo = read_input(argv[i],&exitValue);
        if (!fileInfo) continue;
        const char* fileName = get_file_name(fileInfo);
        // bool isatty = is_input_tty(fileInfo);
        print_output(fileName, istty);
        free(fileInfo);
    }

    if (exitValue) return 1;
    else return 0;
}

