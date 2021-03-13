# ore_dipendenti_azienda
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
