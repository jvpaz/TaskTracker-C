# Task Tracker

Um simples **Gerenciador de Tarefas** desenvolvido em C, inspirado pela idéia de projeto apresentada em [Roadmap.sh](https://roadmap.sh/projects/task-tracker). 

## Configuração e compilação
1. Clone o repositório:
   ```bash
   git clone https://github.com/jvpaz/TaskTracker-C.git
   ```

2. Compile o projeto utilizando o *Makefile*
   ```bash
   make all
   ```

3. Limpe os arquivos gerados, caso seja necessário:
   ```bash
   make clean
   ```
---
   
# Comandos *CLI*

## Adicionar tarefa
   ```bash
   .\taskTracker add "Descrição"
  ```
---

## Deletar tarefa
  ```bash
  .\taskTracker delete <id_da_tarefa>
  ```
---

## Listar tarefas
 ```bash
.\taskTracker list
```
### Listar tarefas completas
```bash
.\taskTracker list completa
```
### Listar tarefas em andamento
```bash
.\taskTracker list em_andamento
```
### Listar tarefas pendentes
```bash
.\taskTracker list pendente
```
---

## Editar tarefas
```bash
.\taskTracker update <tarefa_id> "Nova descrição"
```
---


