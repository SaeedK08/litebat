#include "input.h"

// void inputDescription()
// {
//     // Set kind
//     // set title
//     // Set summary

// }

static void parseArgs(int argNum, char **args, char *filePath)
{
    int opt;
    while((opt = getopt(argNum, args, "a:b:c")) != -1)
    {
        switch(opt)
        {
            case 'a': 
                printf("Option '-%c' was provided with argument: %s" ,opt ,optarg);
                break;
            case 'b': 
                printf("Option '-%c' was provided with argument: %s" ,opt ,optarg);
                break;
            case 'c': 
                printf("Option '-%c' was provided" ,opt);
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

    filePath = args[optind];
}

FILE* open(int argNum, char **args)
{
    if (argNum == 1)
    {
        char temp;
        while(1)
        {
            scanf("%c" ,temp);
            printf("%c" ,temp);
        }
    }

    char *filePath = NULL;
    parseArgs(argNum, args, filePath);
    FILE *fp;
    if (isatty(0))
    {
        fp = fopen(filePath, "r");
    }
    else
    {
        fp = fopen(stdin, "r");
    }
    if (!fp)
    {
        perror("litebat");
        exit(1);
    }
    return fp;
}




/** TODO
 * Error handeling if the provided argument is a directory
 */
