#include "../include/output.h"

void print_output(const char *fileName, bool istty)
{
    char *line = NULL;
    size_t linecap = 0;
    ssize_t linelen;
    FILE* fp = NULL;
    if (istty)
    {
        fp = fopen(fileName, "r");
    }
    else
    {
        fp = fdopen(STDIN_FILENO, "r");
    }
    while ((linelen = getline(&line, &linecap, fp)) > 0)
    {
        fwrite(line, linelen, 1, stdout);
    }
    fclose(fp);
    free(line);
}