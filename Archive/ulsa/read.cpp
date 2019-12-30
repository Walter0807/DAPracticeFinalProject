#include <stdio.h>
using namespace std;

void loadinstance(const char *filename)
{
    FILE *fp = fopen(filename, "r");
    char line[1000];
    int readflag = 1;
    while (readflag)
    {
        char *f = fgets(line, 1000, fp);
        if (f == NULL)
        {
            readflag = 0;
        }
        else
        {
            // printf("%s\n", line);
            if (line[0] == 'e')
            {
                int v1, v2;
                sscanf(&(line[2]), "%d %d", &v1, &v2);
                printf("%d %d\n", v1, v2);
                //     whichconstraint[(v1 - 1) / domain][(v1 - 1) % domain][(v2 - 1) / domain] |= (1ULL << ((v2 - 1) % domain)); /* Assume node numbering starts at 1. */
                //     whichconstraint[(v2 - 1) / domain][(v2 - 1) % domain][(v1 - 1) / domain] |= (1ULL << ((v1 - 1) % domain));
            }

        }
    }
    fclose(fp);
}
int main()
{
    loadinstance("./C125.9.clq");
    return 0;
}