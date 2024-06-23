#include <stdio.h>
#define N 5

struct Paciente
{
    int codigo;
    char nome[10];
};

typedef struct Paciente Paciente;

int menu(int *opcao);
int inserirInicio(Paciente listaLinear[], int IA, int FA, int *IL, int *FL, Paciente infoNodo);
int inserirEmergencia(Paciente listaEmergencia[], int IA, int FA, int *IE, int *FE, Paciente infoNodo);
int mostrarLista(Paciente listaLinear[], Paciente listaEmergencia[], int IA, int FA, int IL, int FL, int IE, int FE);
int proximoLista(Paciente listaLinear[], Paciente listaEmergencia[], int IA, int FA, int *IL, int *FL, int *IE, int *FE);

int main()
{
    Paciente listaLinear[N], listaEmergencia[N], infoNodo;
    int IA = 0, FA = N - 1, IL = -1, FL = -1, IE = -1, FE = -1, opcao;

    do
    {
        menu(&opcao);
        switch (opcao)
        {
        case 1:
            printf("Inserindo paciente...\n");
            printf("Código..: ");
            scanf("%d", &infoNodo.codigo);
            printf("Nome....: ");
            scanf("%s", infoNodo.nome);
            inserirInicio(listaLinear, IA, FA, &IL, &FL, infoNodo);
            break;
        case 2:
            printf("Inserindo emergência...\n");
            printf("Código..: ");
            scanf("%d", &infoNodo.codigo);
            printf("Nome....: ");
            scanf("%s", infoNodo.nome);
            inserirEmergencia(listaEmergencia, IA, FA, &IE, &FE, infoNodo);
            break;
        case 3:
            printf("Mostrando...\n");
            mostrarLista(listaLinear, listaEmergencia, IA, FA, IL, FL, IE, FE);
            break;
        case 4:
            printf("Proxímo da fila...\n");
            proximoLista(listaLinear, listaEmergencia, IA,  FA,  &IL,  &FL,  &IE,  &FE);
            break;
        case 0:
            printf("Tchau! Já vai tarde...\n");
            break;
        default:
            printf("Opção inválida!\n");
            break;
        }
    } while (opcao != 0);

    return 0;
}

int menu(int *opcao)
{
    printf(":::::::: M E N U ::::::::\n");
    printf("[1] Inserir paciente\n");
    printf("[2] Inserir na emergência\n");
    printf("[3] Mostrar listas\n");
    printf("[4] Proxímo\n");
    printf("[0] Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", opcao);
    return 0;
}

int proximoLista(Paciente listaLinear[], Paciente listaEmergencia[], int IA, int FA, int *IL, int *FL, int *IE, int *FE)
{
    int i;
    if(*IE > -1)
    {
        for ( i = *IE; i <= *FE; i++)
        {
            listaEmergencia[i - 1] = listaEmergencia[i];
        }
        *IE = *IE - 1;
        *FE = *FE - 1;
    } else if(*IE == -1)
    {
        for ( i = *IL; i <= *FL; i++)
        {
            listaLinear[i - 1] = listaLinear[i];
        }
        *IL = *IL - 1;
        *FL = *FL - 1;
    }else if(*IL == -1)
    {
        printf("Nenhum paciente nas filas");
    }    
}

int inserirInicio(Paciente listaLinear[], int IA, int FA, int *IL, int *FL, Paciente infoNodo)
{
    int i;
    if (IA == *IL && FA == *FL)
        return 1;
    if (*IL == -1)
        *IL = *FL = IA;
    else if (*FL < FA)
        *FL = *FL + 1;
    else
    {
        for ( i = *IL; i <= *FL; i++)
        {
            listaLinear[i - 1] = listaLinear[i];
        }
        *IL = *IL - 1;
    }
    listaLinear[*FL] = infoNodo;
    return 0;
}
int inserirEmergencia(Paciente listaEmergencia[], int IA, int FA, int *IE, int *FE, Paciente infoNodo)
{
    int i;
    if (IA == *IE && FA == *FE)
        return 1; 
    if (*IE == -1)
        *IE = *FE = IA;
    else if (*FE < FA)
        *FE = *FE + 1;
    else
    {
        for (i = *IE; i <= *FE; i++)
        {
            listaEmergencia[i - 1] = listaEmergencia[i];
        }
        *IE = *IE - 1;
    }

    listaEmergencia[*FE] = infoNodo;
    return 0;
}

int mostrarLista(Paciente listaLinear[], Paciente listaEmergencia[], int IA, int FA, int IL, int FL, int IE, int FE)
{
    int i;
    printf("Emergência\n");
    for (i = IA; i <= FA; i++)
        if(i>=IE && i<=FE)
        {
            printf("%3d - %s\n", listaEmergencia[i].codigo, listaEmergencia[i].nome);
        }

    printf("Fila normal\n");
    for (i = IA; i <= FA; i++)
        if(i>=IL && i<=FL)
        {
            printf("%3d - %s\n", listaLinear[i].codigo, listaLinear[i].nome);
        }

    return 0;
}
