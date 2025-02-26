#include "comandos.h"
#include "cli.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int totalTasks;
Task *tasks = NULL;

static void listarCompletas();
static void listarEmAndamento();
static void listarPendentes();

void adicionarDados(char descricao[])
{
    time_t horaAgora = time(NULL);
    struct tm *tm_info = localtime(&horaAgora);

    totalTasks++;
    tasks = realloc(tasks, totalTasks * sizeof(Task));

    tasks[totalTasks - 1].id = totalTasks;
    strcpy(tasks[totalTasks - 1].descricao,descricao);
    tasks[totalTasks - 1].status = PENDENTE;

    strftime(tasks[totalTasks - 1].dataCriacao, sizeof(tasks->dataCriacao), "%d/%m/%y %H:%M", tm_info);
    strftime(tasks[totalTasks - 1].dataAtualizado, sizeof(tasks->dataAtualizado), "%d/%m/%y %H:%M", tm_info);
}

void deletarDados(int id)
{
    if(totalTasks == 0)
    {
        printf("Nao ha tarefas a serem deletadas!\n");
        return;
    }

    for (int i = 0; i < totalTasks; i++)
    {
        if (tasks[i].id == id)
        {
            for (int j = i; j < totalTasks - 1; j++)
            {
                tasks[j].id = tasks[j + 1].id - 1;
                tasks[j].status = tasks[j + 1].status;

                strcpy(tasks[j].descricao, tasks[j + 1].descricao);
                strcpy(tasks[j].dataCriacao, tasks[j + 1].dataCriacao);
                strcpy(tasks[j].dataAtualizado, tasks[j + 1].dataAtualizado);
            }
            totalTasks--;
            return;
        }
        printf("Tarefa informada nao encontrada!\n");
    }
    
}
void listarDados(char *argv[])
{
    if (totalTasks == 0)
    {
        printf("Nao ha tarefas a serem listadas!\n");
        return;
    }

    if (argv[2] != NULL)
    {
    if (strcmp(argv[2], "completa") == 0)
        listarCompletas();
    else if (strcmp(argv[2], "em_andamento") == 0)
        listarEmAndamento();
    else if (strcmp(argv[2], "pendente") == 0)
        listarPendentes();
    else
    {
        printf("Status informado invalido!\n");
        printf("Exemplo: completa : em_andamento : pendente\n");
    }
    }
    else
    for (int i = 0; i < totalTasks; i++)
        cliPrintarTasks(&tasks[i]);
}

void editarDados(int id, char novaDescricao[])
{

    time_t horaAgora = time(NULL);
    struct tm *tm_info = localtime(&horaAgora);

    for (int i = 0; i < totalTasks; i++)
    {
        if (tasks[i].id == id)
        {       
                strcpy(tasks[i].descricao, novaDescricao);
                strftime(tasks[i].dataAtualizado, sizeof(tasks->dataAtualizado), "%d/%m/%y %H:%M", tm_info);
                return;
        }
    }
    printf("Tarefa informada nao encontrada!\n");
}

void marcarCompleta(int id)
{
    for (int i = 0; i <= totalTasks; i++)
    {
        if (tasks[i].id == id)
        {
            tasks[i].status = COMPLETO;
            return;
        }
        
    }
    
}
void marcarEmAndamento(int id)
{
    for (int i = 0; i <= totalTasks; i++)
    {
        if (tasks[i].id == id)
        {
            tasks[i].status = EM_ANDAMENTO;
            return;
        }
        
    }
}

static void listarCompletas()
{
    for (int i = 0; i < totalTasks; i++)
    {
        if (tasks[i].status == COMPLETO)
        {
            cliPrintarTasks(&tasks[i]);
        }
        
    }
}
static void listarEmAndamento()
{
    for (int i = 0; i < totalTasks; i++)
    {
        if (tasks[i].status == EM_ANDAMENTO)
        {
            cliPrintarTasks(&tasks[i]);
        }
        
    }
}
static void listarPendentes()
{
    for (int i = 0; i < totalTasks; i++)
    {
        if (tasks[i].status == PENDENTE)
        {
            cliPrintarTasks(&tasks[i]);
        }
        
    }
}