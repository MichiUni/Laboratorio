#include "chat.h"
#include <iostream>

Chat::Chat(const Utente &utente1, const Utente &utente2) : utente1(utente1), utente2(utente2) {}

void Chat::aggiungiMessaggio(const Messaggio &messaggio) {
    messaggi.push_back(messaggio);
}

void Chat::mostraChat() const {
    std::cout << "Chat tra " << utente1.getNome() << " e " << utente2.getNome() << ":\n";
    for (const auto &messaggio : messaggi) {
        messaggio.mostraMessaggio();
    }
}
