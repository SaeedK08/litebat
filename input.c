#include "input.h"

// void inputDescription()
// {
//     // Set kind
//     // set title
//     // Set summary

// }

struct Input
{
    bool isatty;
    FILE *fp;
};


static void parseArgs(int argNum, char **args)
{
    int opt;
    while((opt = getopt(argNum, args, "a:b:c")) != -1)
    {
        switch(opt)
        {
            case 'a': 
                printf("Option '-%c' was provided with argument: %s\n" ,opt ,optarg);
                break;
            case 'b': 
                printf("Option '-%c' was provided with argument: %s\n" ,opt ,optarg);
                break;
            case 'c': 
                printf("Option '-%c' was provided\n" ,opt);
                break;
            case '?':
                if (optopt == 'a' || optopt == 'b')
                {
                    fprintf(stderr, "Option '-%c' requires an argument." ,optopt);
                }
                else
                {
                    fprintf(stderr, "Unknown option '-%c'" ,optopt);
                }
                exit(1);
            default:
                // Should nerver reach here
                abort();
        }
    }

}

Input* readInput(int argc, char **args)
{
    if (argc == 1)
    {
        char temp;
        while(1)
        {
            scanf("%c" ,&temp);
            printf("%c" ,temp);
        }
    }

    parseArgs(argc, args);
    if (argc == optind)
    {
        printf("litebat: No file/path was provided\n");
        exit (1);
    }
    const char *filePath = args[optind];
    Input *info = malloc(sizeof(Input));
    info->fp = fopen(filePath, "r");
    if (!info->fp)
    {
        perror("litebat");
        exit(1);
    }
    if (isatty(fileno(info->fp)))
    {
        info->isatty = true;
    }
    else
    {
        info->isatty = false;
    }

    return info;
}




/** TODO
 * Error handeling if the provided argument is a directory
 */
