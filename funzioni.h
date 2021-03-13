//
// Created by
//
// Alex Grassi
// Dario Comparotto
// Ashley Rose Conception
// Paride Pisu
// Pietro Piemontese
//
// on 26/03/2020.
//

#ifndef ES_ORE_DIPENDENTI_FUNZIONI_H
#define ES_ORE_DIPENDENTI_FUNZIONI_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Passaggi{
    int ore,minuti;
    char matricola[11];
};

struct dipendenti{
    struct Passaggi pass[2000];
    int num;
};

int leggi(char* nomefile, struct dipendenti *accessi){
    FILE* fp = fopen(nomefile,"r");
    (*accessi).num = 0;
    if(!fp) return 0; //ERR
    else{
        while (!feof(fp)){
            fscanf(fp,"%d %d %s",(int*)&(*accessi).pass[accessi->num].ore,(int*)&(*accessi).pass[accessi->num].minuti, (*accessi).pass[accessi->num].matricola);
            (*accessi).num++;
        }
    fclose(fp);
    return 1; //OK
    }
}

int opzione1(struct dipendenti accessi){
    int cont = 0;
    int controllo;
    int j;
    for (int i = 0; i < accessi.num ; ++i) {
        j=0;
        controllo=0;
        while(controllo == 0 && j < i){
            if (strcmp(accessi.pass[i].matricola,accessi.pass[j].matricola)==0) controllo=1;
            j++;
        }
        if (controllo==0) cont++;
    }
    return cont;
}


void opzione2(char matricola[],struct dipendenti accessi){
    struct Passaggi primopass,ultimopass;
    int TOT;

    for (int i = 0; i <accessi.num ; ++i) {
        if(strcmp(primopass.matricola,matricola)!=0 && strcmp(accessi.pass[i].matricola, matricola) == 0){
            primopass.ore=accessi.pass[i].ore;
            primopass.minuti=accessi.pass[i].minuti;
            strcpy(primopass.matricola,accessi.pass[i].matricola);
        } else if (strcmp(primopass.matricola,matricola)==0 && strcmp(accessi.pass[i].matricola, matricola) == 0){
            ultimopass.ore=accessi.pass[i].ore;
            ultimopass.minuti=accessi.pass[i].minuti;
            strcpy(ultimopass.matricola,accessi.pass[i].matricola);
        }
    }

    if(strcmp(primopass.matricola,matricola)!=0 && strcmp(ultimopass.matricola,matricola)!=0) printf("Dipendente non trovato\n");
    else if (strcmp(ultimopass.matricola,matricola)!=0) printf("Il dipendente ha fatto solo un passaggio\n");
    else {
        TOT=((ultimopass.ore-primopass.ore)*60)+(ultimopass.minuti-primopass.minuti);
        printf("Il dipendente %s ha lavorato %d minuti",matricola,TOT);
    }
}

#endif //ES_ORE_DIPENDENTI_FUNZIONI_H
