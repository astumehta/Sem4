#include <stdio.h>
#include <string.h>

char Text[100];
char Pattern[100];
int pi[100];
int m, n;

void prefix()
{
    m = strlen(Pattern);
    pi[0] = 0;
    pi[1] = 0;
    int k = 0;
    for (int q = 2; q <= m; q++)
    {
        while (k > 0 && Pattern[k] != Pattern[q - 1])
        {
            k = pi[k];
        }
        if (Pattern[k] == Pattern[q - 1])
        {
            k = k + 1;
        }
        pi[q] = k;
    }
    printf("Prefix array: ");
    for (int i = 1; i <= m; i++)
    {
        printf("%d ", pi[i]);
    }
    printf("\n");
}

void KMP()
{
    n = strlen(Text);
    m = strlen(Pattern);
    int q = 0;
    for (int i = 0; i < n; i++)
    {
        while (q > 0 && Pattern[q] != Text[i])
        {
            q = pi[q];
        }
        if (Pattern[q] == Text[i])
        {
            q = q + 1;
        }
        if (q == m)
        {
            printf("Pattern found at shift %d\n", i - m + 1);
            q = pi[q];
        }
    }
}

int main()
{
    printf("Enter text: ");
    scanf("%s", Text);
    printf("Enter pattern: ");
    scanf("%s", Pattern);
    prefix();
    KMP();
    return 0;
}