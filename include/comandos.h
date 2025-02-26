#ifndef COMANDOS_H
#define COMANDOS_H

void adicionarDados(char descricao[]);
void deletarDados(int id);
void listarDados(char *argv[]);
void editarDados(int id, char novaDescricao[]);
void marcarCompleta(int id);
void marcarEmAndamento(int id);

typedef enum status {
    PENDENTE = 0,
    EM_ANDAMENTO = 1,
    COMPLETO = 2
} Taskstatus;

typedef struct task {
    int id;
    char descricao[500];
    char dataCriacao[20]; //DD/MM/YYYY HH:MM:SS
    char dataAtualizado[20]; //DD/MM/YYYY HH:MM:SS
    Taskstatus status;
} Task;

extern Task *tasks;
extern int totalTasks;

#endif