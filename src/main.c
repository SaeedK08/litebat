#include "../include/input.h"
#include "../include/output.h"

int main (int argc, char **argv)
{
    int exitValue = 0;
    const char *fileName = NULL;
    parseArgs(argc, argv);
    if ((argc == 1 && isatty(STDIN_FILENO)) || (argc == optind && isatty(STDIN_FILENO)))
    {
        char temp;
        while(1)
        {
            scanf("%c" ,&temp);
            printf("%c" ,temp);
        }
    }

    bool istty = check_input_source();
    if (!istty)
    {
        print_output(NULL, istty);
    }
    else 
    {
        for (int i = optind; i < argc; i++)
        {
            fileName = read_input(argv[i],&exitValue);
            if (!fileName) continue;
            print_output(fileName, istty);
        }
    }

    if (exitValue) return 1;
    else return 0;
}

