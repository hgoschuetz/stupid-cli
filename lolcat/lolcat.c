#include <stdio.h>
#include <stdlib.h>

#include <math.h>

#define TABSIZE 8

static float frequency = 0.1f;

static void lol(const char *filename);
static void cat(FILE *fp);

static void rainbow(char c, int i);

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

        if ((fp = fopen(filename, "r")) == NULL)
        {
                fprintf(stderr, "error: could not open file '%s'\n", filename);
                exit(EXIT_FAILURE);
        }

        cat(fp);

        fclose(fp);
}

static void cat(FILE *fp)
{
        int c;

        int col, off;

        col = off = 0;

        while ((c = getc(fp)) != EOF)
        {
                rainbow(c, (col + off));

                switch (c)
                {
                case '\n':
                        col = 0;
                        ++off;
                        break;
                case '\t':
                        col += TABSIZE - (col % TABSIZE);
                        break;
                default:
                        ++col;
                        break;
                }
        }
}

static void rainbow(char c, int i)
{
        int r, g, b;

        r = sinf(frequency * i) * 127 + 128;
        g = sinf(frequency * i + 2 * M_PI / 3) * 127 + 128;
        b = sinf(frequency * i + 4 * M_PI / 3) * 127 + 128;

        printf("\033[38;2;%d;%d;%dm%c", r, g, b, c);
}
