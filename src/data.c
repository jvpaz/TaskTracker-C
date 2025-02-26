#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "comandos.h"

void carregarDados(char data[]){

    FILE *Arq = fopen(data,"r");
    if (Arq == NULL)
    {
        printf("Erro ao ler arquivo JSON!\n");
        return;
    }
    
    fseek(Arq, 0, SEEK_END);
    long Arq_Tamanho = ftell(Arq);
    fseek(Arq, 0, SEEK_SET);

    if (Arq_Tamanho == 0) //Caso o arquivo esteja vazio, pula a etapa de procurar por tarefas.
    {
        return;
    }
    

    char *buffer = (char *)malloc(Arq_Tamanho * sizeof(char) + 1);

    fread(buffer, 1, Arq_Tamanho, Arq);
    buffer[Arq_Tamanho] = '\0';
    fclose(Arq);

    if (buffer == NULL && totalTasks != 0)
    {
        printf("Erro ao analisar arquivo JSON!\n");
        return;
    }
    
    char *array_inicio = strchr(buffer, '[');
    char *arrays = strchr(array_inicio, '{');
    int contadorTemp = 0;
    int tempStatus;
    while (arrays)
    {
        char *getId = strstr(arrays,"\"id\":");
        char *getDescricao = strstr(arrays,"\"descricao\":");
        char *getStatus = strstr(arrays,"\"status\":");
        char *getCriacao = strstr(arrays,"\"criacao\":");
        char *getEdicao = strstr(arrays, "\"edicao\":");

        totalTasks++;
        tasks = (Task*)realloc(tasks, totalTasks * sizeof(Task));

        sscanf(getId, "\"id\": %d", &tasks[contadorTemp].id);
        sscanf(getDescricao, "\"descricao\": \"%[^\"]", tasks[contadorTemp].descricao);
        sscanf(getStatus, "\"status\": %d", &tempStatus);
        sscanf(getCriacao, "\"criacao\": \"%[^\"]", tasks[contadorTemp].dataCriacao);
        sscanf(getEdicao, "\"edicao\": \"%[^\"]", tasks[contadorTemp].dataAtualizado);

        tasks[contadorTemp].status = (Taskstatus)tempStatus;

        contadorTemp++;
        arrays = strchr(arrays + 1, '{');
    }
}

void salvarDados(char data[])
{ 
    FILE *Arq = fopen(data,"w");
    fprintf(Arq,"{\n");
    fprintf(Arq, "\t\"Array\": [\n");
    for (int i = 0; i < totalTasks; i++)
    {
        fprintf(Arq,"\t\t{\n");
        fprintf(Arq,"\t\t\"id\": %d,\n", tasks[i].id);
        fprintf(Arq,"\t\t\"descricao\": \"%s\",\n", tasks[i].descricao);
        fprintf(Arq,"\t\t\"status\": %d,\n", tasks[i].status);
        fprintf(Arq,"\t\t\"criacao\": \"%s\",\n", tasks[i].dataCriacao);
        fprintf(Arq,"\t\t\"edicao\": \"%s\"\n", tasks[i].dataAtualizado);
        if (i == totalTasks - 1)
            fprintf(Arq,"\t\t}");
        else
        fprintf(Arq,"\t\t},\n");
    }
    fprintf(Arq, "]\n");
    fprintf(Arq,"}");

        fclose(Arq);
}

