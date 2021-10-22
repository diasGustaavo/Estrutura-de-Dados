#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tam, i, *v;
    scanf("%d", &tam);
    v = (int *)malloc(tam * sizeof(int));
    for (i = 0; i < tam; i++)
        scanf("%d", &v[i]);

    int maiorIndice = tam - 1;
    int indiceAtual = 0;

    while (indiceAtual <= maiorIndice)
    {
        int maiorItemRodadaAtual = v[indiceAtual];
        int indiceMaiorItemRodadaAtual = indiceAtual;
        for (int i = indiceAtual; i <= maiorIndice; i++)
        {
            if (v[i] > maiorItemRodadaAtual)
            {
                maiorItemRodadaAtual = v[i];
                indiceMaiorItemRodadaAtual = i;
            }
        }

        int temp = v[indiceAtual];
        v[indiceAtual] = maiorItemRodadaAtual;
        v[indiceMaiorItemRodadaAtual] = temp;

        indiceAtual++;
    }

    for (i = 0; i < tam; i++)
        printf("%d ", v[i]);

    return 0;
}