#include <stdlib.h>
#include <stdio.h>

struct site
{
    int url;
    struct site *elo;
};

typedef struct site site;

int removerURL(site **ponteiroURL);
int novaURL(site **ponteiroURL, int dados);
void historicoNavegacao(site *ponteiroURL);

int main()
{
    site *ponteiroURL;
    ponteiroURL = NULL;
    int opcao, dados;
    //char dados[20];
    do
    {
        printf("\n[1] Nova URL\n");
        printf("[2] Historico de navegacao\n");
        printf("[3] Remover historico de navegacao\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            scanf("%d", &dados);
            novaURL(&ponteiroURL, dados);
            break;

        case 2:
            historicoNavegacao(ponteiroURL);
            break;

        case 3:
            removerURL(&ponteiroURL);
            break;
        }
    } while (opcao != 0);
}
int removerURL(site **ponteiroURL)
{
    site *p;
    if(*ponteiroURL == NULL)
    {
        printf("Historico limpo\n");
        return 1;
    }
        else
        {
            p = *ponteiroURL;
            p = p->elo;
            *ponteiroURL = p;
            if(*ponteiroURL != NULL)
                printf("URL atual: %d\t", p->url);
            p = NULL;
            free(p);
        }
    
}
int novaURL(site **ponteiroURL, int dados)
{
    site *novoPonteiro = (site *)malloc(sizeof(site));
    if (novoPonteiro == NULL)
        return 1;
    else
    {
        novoPonteiro->url = dados;
        novoPonteiro->elo = *ponteiroURL;
        *ponteiroURL = novoPonteiro;
    }
}
void historicoNavegacao(site *ponteiroURL)
{
    site *p;
    for (p = ponteiroURL; p != NULL; p = p->elo)
        printf("%d\t", p->url);
}