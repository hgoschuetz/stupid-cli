#include <stdio.h>
#include <stdlib.h>

#include <math.h>

static float frequency = 0.3f;

static void lol(const char *filename);

static void cat(char c, int i);

int main(int argc, const char *argv[])
{
        int i;

        for (i = 1; i < argc; ++i)
        {
                lol(argv[i]);
        }

        return 0;
}

static void lol(const char *filename)
{
        FILE *fp = NULL;

        int c;
        int i = 0;
        int offset = 0;

        if ((fp = fopen(filename, "r")) == NULL)
        {
                fprintf(stderr, "error: could not open file '%s'\n", filename);
                exit(EXIT_FAILURE);
        }

        while ((c = getc(fp)) != EOF)
        {
                cat(c, i);

                if (c == '\n')
                        i = ++offset;
                else
                        ++i;
        }

        fclose(fp);
}

static void cat(char c, int i)
{
        int r, g, b;

        r = sinf(frequency * i) * 127 + 128;
        g = sinf(frequency * i + 2 * M_PI / 3) * 127 + 128;
        b = sinf(frequency * i + 4 * M_PI / 3) * 127 + 128;

        printf("\033[38;2;%d;%d;%dm%c", r, g, b, c);
}
