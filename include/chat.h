#ifndef CHAT_H
#define CHAT_H

#include "messaggio.h"
#include <vector>

class Chat {
private:
    Utente utente1;
    Utente utente2;
    std::vector<Messaggio> messaggi;

public:
    Chat(const Utente &utente1, const Utente &utente2);
    void aggiungiMessaggio(const Messaggio &messaggio);
    void mostraChat() const;
};

#endif
