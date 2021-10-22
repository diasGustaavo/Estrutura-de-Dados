#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tam, i, *v;
    scanf("%d", &tam);
    v = (int *)malloc(tam * sizeof(int));
    for (i = 0; i < tam; i++)
        scanf("%d", &v[i]);

    int n = tam - 1;

    while (n >= 1)
    {
        for (int i = 0; i < n; i++)
            if (v[i] > v[i + 1])
            {
                int temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
            }
        n--;
    }

    for (i = 0; i < tam; i++)
        printf("%d ", v[i]);

    return 0;
}