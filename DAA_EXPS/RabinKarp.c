#include <stdio.h>
#include <string.h>

#define d 256
void search(char pat[], char txt[], int q)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;

    int h = 1;

    int p = 0;
    int t = 0;
    // M-1
    // M
    // <=N-M

    for (i = 0; i < M - 1; i++)
    {
        h = (h * 256) % q;
    }

    // MAIN
    for (i = 0; i < M; i++)
    {
        p = (256 * p + pat[i]) % q;
        t = (256 * t + txt[i]) % q;
    }
    
    for (i = 0; i <= N - M; i++)
    {
        if (p == t)
        {
            for (j = 0; j < M; j++)
            {
                if (txt[i + j] != pat[j])
                {
                    break;
                }
            }
            if (j == M)
            {
                printf("Pattern found at index %d \n", i);
            }
        }
        
        if (i < N - M)
        {
            t = (256 * (t - txt[i] * h) + txt[i + M]) % q;
            if (t < 0)
            {
                t = (t + q);
            }
        }
    }
}

int main()
{
    char txt[100], pat[100];
    int q;

    printf("Enter the text: ");
    scanf("%s", txt);

    printf("Enter the pattern: ");
    scanf("%s", pat);

    printf("Enter a prime number: ");
    scanf("%d", &q);

    search(pat, txt, q);
    return 0;
}
