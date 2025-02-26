#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "cli.h"

#define DATA "data/data.json"

int main(int argc, char *argv[]) {

    carregarDados(DATA);
    cliReceberComando(argc, argv);
    salvarDados(DATA);

    return 0;
}