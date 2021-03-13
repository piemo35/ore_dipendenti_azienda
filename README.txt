ANALISI DELLA RICHIESTA:

Progettazione di un programma in linguaggio C che accetti piu parametri
in modo di poterlo lanciare da riga di comando.

Il programma avra' lo scopo di gestire gli ingressi e le uscite dei 
dipendenti di un'azienda dall'azienda stessa.

I parametri che possono essere passati sono:
char** argv[1] = nome del file contenente i passaggi ("passaggi.txt")
char** argv[2] = nome della matricola scelta (opzionale) es. "abc123".

- Se il programma viene invocato con 1 parametro (nome file) dovra' 
stampare a video il numero di dipendenti DIVERSI che hanno effettuato
passaggi.

- Se il programma viene invocato con 2 parametri (nome file + matricola)
dovra' stampare a video il numero di minuti totali in cui il dipendente
e' stato all'interno dell'azienda.

NB: in entrambi i casi il programma stampera' un messaggio d'errore in caso
di operazione non riuscita.


DESCRIZIONE DELLE FUNZIONI:

1) int leggi(char* nomefile, struct dipendenti* accessi)
	
Scopo: leggere i passaggi dal file e memorizzarli nella struct "accessi"

Descrizione parametri:
	-char* nomefile: puntatore all'array di caratteri contenente il nome del file da aprire.
	-struct dipendenti* accessi: puntatore alla struttura che conterra' i passaggi letti da file.

Descrizione output prodotto:
	return 1: OK 
	return 0: ERRORE



2) int opzione1(struct dipendenti accessi)

Scopo: restituire il numero totale di dipendenti DIVERSI entrati nell'azienda

Descrizione Parametri: 
	-struct dipendenti accessi: copia della struttura contenente i passaggi letti da file

	return cont (numero dipendenti diversi trovati)

Descrizione output prodotto:
	printf "in totale ci sono x dipendenti"     x = cont



3) void opzione2(char matricola[], struct dipendenti accessi)

Scopo: restituire il numero totale di minuti in cui il dipendente scelto
e' stato all'interno dell'azienda

Descrizione parametri:
	-char matricola[]: nome della matricola (passata come parametro al main)
	-struct dipendenti accesso: copia della struttura contenente i passaggi letti da file.

Descrizione output:
	OK: printf "il dipendente abc123 ha lavorato 200 minuti"
	ERR: printf "il dipendente ha effettuato solo un passaggio"
	ERR: printf "dipendente non trovato"



MAIN:

int main(int argc,char** argv) {
    struct dipendenti accessi;

    if(argc == 2) leggi(argv[1],&accessi) ? printf("In totale ci sono %d dipendenti",opzione1(accessi)) : printf("Errone nell'apertura del file\n");
    for(int i = 0; argv[2][i]; i++) argv[2][i] = tolower(argv[2][i]); //Converto la stringa in minuscolo
    if(argc == 3) (leggi(argv[1],&accessi) == 1) ? opzione2(argv[2],accessi) : printf("Errore nell'apertura del file");

    return 0;
}

DESCRIZIONE MAIN:

int argc = contatore che ci dice il numero di parametri passati al main.

char** argv = matrice di caratteri:
	argv[1][] = nome del file da aprire
	argv[2][] = nome della matrice

if(arcg == 2) -> se e' stato passato un solo parametro (oltre al nome del programma)
if(argc == 3) -> se sono stati passati due parametri (oltre al nome del programma)

il ciclo for serve semplicemente a trasformare la matrice in minuscolo, per evitare errori banali.






