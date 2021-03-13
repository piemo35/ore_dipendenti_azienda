#include "funzioni.h"

int main(int argc,char** argv) {
    struct dipendenti accessi;

    if(argc == 2) leggi(argv[1],&accessi) ? printf("In totale ci sono %d dipendenti",opzione1(accessi)) : printf("Errore nell'apertura del file\n");
    if(argc == 3) for(int i = 0; argv[2][i]; i++) argv[2][i] = tolower(argv[2][i]); //Converto la stringa in minuscolo
    if(argc == 3) (leggi(argv[1],&accessi) == 1) ? opzione2(argv[2],accessi) : printf("Errore nell'apertura del file");

    return 0;
}
