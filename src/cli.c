#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "comandos.h"
#include "cli.h"

static void cliAdicionar(int argc, char *argv[]);
static void cliDeletar(int argc, char *argv[]);
static void cliListar(char *argv[]);
static void cliEditar(int argc, char *argv[]);
static void cliMarcarCompleta(int argc, char *argv[]);
static void cliMarcarAndamento(int argc, char *argv[]);

void cliReceberComando(int argc, char *argv[])
{
    char *comando = argv[1];

    if (strcmp(comando, "add") == 0)   
        cliAdicionar(argc,argv);
    else if (strcmp(comando, "delete") == 0)
        cliDeletar(argc, argv);
    else if (strcmp(comando, "list") == 0)
        cliListar(argv);
    else if (strcmp(comando, "update") == 0)
        cliEditar(argc, argv);
    else if (strcmp(comando, "marcar_completa") == 0)
        cliMarcarCompleta(argc, argv);
    else if (strcmp(comando, "marcar_andamento") == 0)
        cliMarcarAndamento(argc, argv);
    else
        printf("Comando informado invalido!\n");
}

static void cliAdicionar(int argc, char *argv[])
{
    if (argc < 3)
        {
            printf("Syntax invalida!\n");
            printf("Exemplo: .\\tasktrack add [descricao]\n");
            return;
        }
        adicionarDados(argv[2]);
}
static void cliDeletar(int argc, char *argv[])
{
    if (argc < 3)
        {
            printf("Syntax invalida!\n");
            printf("Exemplo: .\\tasktrack delete [numero]\n");
            return;
        }
        deletarDados(atoi(argv[2]));
}
static void cliListar(char *argv[])
{
    listarDados(argv);
}
static void cliEditar(int argc, char *argv[])
{
    if (argc < 4)
        {
            printf("Syntax invalida!\n");
            printf("Exemplo: .\\tasktrack update [numero] [descricao]\n");
            return;
        }
        editarDados(atoi(argv[2]), argv[3]);
}
static void cliMarcarCompleta(int argc, char *argv[])
{
    if (argc < 3)
        {
            printf("Syntax invalida!\n");
            printf("Exemplo: .\\tasktrack marcar_completa [numero]\n");
            return;
        }
        marcarCompleta(atoi(argv[2]));
}
static void cliMarcarAndamento(int argc, char *argv[])
{
    if (argc < 3)
        {
            printf("Syntax invalida!\n");
            printf("Exemplo: .\\tasktrack marcar_andamento [numero]\n");
            return;
        }
        marcarEmAndamento(atoi(argv[2]));
}
void cliPrintarTasks(Task *tasks)
{
    char *statusTask[] = {"Pendente", "Em Andamento", "Completa"};
    
    printf("ID: %d\n", tasks->id);
    printf("Descricao: %s\n", tasks->descricao);
    printf("Status: %s\n", statusTask[tasks->status]);
    printf("Data de criacao: %s\nData de edicao: %s\n\n", tasks->dataCriacao, tasks->dataAtualizado);
}