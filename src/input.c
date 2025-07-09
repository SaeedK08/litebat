#include "../include/input.h"

// void inputDescription()
// {
//     // Set kind
//     // set title
//     // Set summary

// }

struct Input
{
   // bool isatty;
    const char *path;
};

void parseArgs(int argNum, char **args)
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

Input* read_input(char *arg, int *exitValue)
{
    
    const char *filePath = arg;
    Input *fileInfo = malloc(sizeof(Input));
    
    struct stat st;                                         // Copy the meta data of path to st
    if ((stat(filePath, &st)) == -1)
    {
        (*exitValue) = 1;
        fprintf(stderr, "litebat: %s: %s\n" ,filePath, strerror(errno));
        return NULL;
    }              

    if (S_ISDIR(st.st_mode))
    {
        (*exitValue) = 1;
        fprintf(stderr, "litebat: %s: Is a directory\n" ,filePath);
        return NULL;
    }
    
    FILE* fp = fopen(filePath, "r");
    if (!fp)
    {
        (*exitValue) = 1;
        fprintf(stderr, "litebat: %s: %s\n" ,filePath, strerror(errno));
        return NULL;
    }

    // if (S_ISFIFO(st.st_mode))
    // {
    //     fileInfo->isatty = false;
    // }
    // if (isatty(STDIN_FILENO))
    // {
    //     printf("Input is a tty\n");
    //     fileInfo->isatty = true;
    // }
    // else
    // {
    //     printf("Input is from STDIN / PIPE\n");
    //     fileInfo->isatty = false;
    // }

    fclose(fp);
    fileInfo->path = filePath;

    
    return fileInfo;
}

char const* get_file_name(const Input *fileInfo)
{
    return fileInfo->path;
}

// bool is_input_tty(const Input* fileInfo)
// {
//     return fileInfo->isatty;
// }

bool check_input_source(void)
{
    if (isatty(STDIN_FILENO))
    {
        return true;
    }
    else 
    {
        return false;
    }
}


// TODO: Work on piping 