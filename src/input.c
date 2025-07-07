#include "../include/input.h"

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
// static Input fileInfo;

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

Input* read_input(int argc, char **args)
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
    Input *fileInfo = malloc(sizeof(Input));
    struct stat st;
    if ((stat(filePath, &st)) == -1)
    {
        perror("litebat");
        exit(1);
    }                                        // Copy the meta data of path to st
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

    // if (S_ISFIFO(st.st_mode))
    // {
    //     fileInfo->isatty = false;
    // }
    if (isatty(STDIN_FILENO))
    {
        fileInfo->isatty = true;
    }
    else
    {
        fileInfo->isatty = false;
    }

    fclose(fp);
    fileInfo->path = filePath;

    return fileInfo;
}

char const* get_file_name(const Input *fileInfo)
{
    return fileInfo->path;
}

bool is_input_tty(const Input* fileInfo)
{
    return fileInfo->isatty;
}