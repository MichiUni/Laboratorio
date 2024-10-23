#ifndef CHAT_H
#define CHAT_H

#include "messaggio.h"
#include <vector>

//metodo che mostra i messaggi da leggere

class Chat {
private:
    Utente utente1;
    Utente utente2;
    std::vector<Messaggio> messaggi;
    int num_messaggi;

public:
    Chat(const Utente &utente1, const Utente &utente2);
    void aggiungiMessaggio(const Messaggio &messaggio);
    void mostraChat(); //Questo metodo non è costante perchè setta lo specifico attributo booelano a true qualora un messaggio
                       //della chat venga letto per la prima volta

    const Utente& getUtente1() const;
    const Utente& getUtente2() const;

    void salvaSuFile() const;

    //To do aggiungere metodi: numeroMessaggi, numMessaggiDaleggere
    //const std::vector<Messaggio>& getMessaggi() const;   //Da togliere
};

#endif
