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
    const char *path;
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
    parseArgs(argc, args);

    if (argc == 1 || argc == optind)
    {
        char temp;
        while(1)
        {
            scanf("%c" ,&temp);
            printf("%c" ,temp);
        }
    }

    const char *filePath = args[optind];
    Input *info = malloc(sizeof(Input));
    struct stat st;
    stat(filePath, &st);                                        // Copy the meta data of path to st
    if (S_ISDIR(st.st_mode))
    {
        fprintf(stderr, "litebat: %s is a directory\n" ,filePath);
        exit(1);
    }
    FILE* fp = fopen(filePath, "r");
    if (!fp)
    {
        perror("litebat");
        exit(1);
    }

    if (isatty(fileno(fp)))
    {
        info->isatty = true;
    }
    else
    {
        info->isatty = false;
    }

    fclose(fp);
    info->path = filePath;

    return info;
}




