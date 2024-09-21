// main.cpp
#include "utente.h"
#include "messaggio.h"
#include "chat.h"
#include "registrochat.h"

int main() {
    // Creazione degli utenti
    Utente utente1(1, "Alice");
    Utente utente2(2, "Bob");
    Utente utente3(3, "Charlie");

    // Creazione di chat tra utenti
    Chat chat1(utente1, utente2);
    Chat chat2(utente1, utente3);

    // Aggiunta di messaggi
    chat1.aggiungiMessaggio(Messaggio(utente1, utente2, "Ciao Bob!"));
    chat1.aggiungiMessaggio(Messaggio(utente2, utente1, "Ciao Alice, come stai?"));

    chat2.aggiungiMessaggio(Messaggio(utente1, utente3, "Ciao Charlie, tutto bene?"));
    chat2.aggiungiMessaggio(Messaggio(utente3, utente1, "Ciao Alice, sì grazie!"));

    // Registro delle chat
    RegistroChat registro;
    registro.aggiungiChat(chat1);
    registro.aggiungiChat(chat2);

    // Mostrare tutte le chat
    registro.mostraChats();

    return 0;
}

int main(){

}
