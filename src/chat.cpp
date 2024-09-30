#include "chat.h"
#include <iostream>

Chat::Chat(const Utente &utente1, const Utente &utente2) : utente1(utente1), utente2(utente2) {}

void Chat::aggiungiMessaggio(const Messaggio &messaggio) {
    messaggi.push_back(messaggio);
}

/*void Chat::mostraChat() const {
    std::cout << "Chat tra " << utente1.getNome() << " e " << utente2.getNome() << ":\n";
    for (const auto &messaggio : messaggi) {
        messaggio.mostraMessaggio();
    }
}
*/
void Chat::mostraChat() const {
    const std::string ANSI_BLUE = "\033[34m";   // Colore blu per i messaggi dell'utente1
    const std::string ANSI_RED = "\033[31m";    // Colore rosso per i messaggi dell'utente2
    const std::string ANSI_RESET = "\033[0m";   // Resetta il colore

    for (const auto& messaggio : messaggi) {
        if (messaggio.getMittente().getId() == utente1.getId()) {
            // Stampa messaggi dell'utente1 in blu
            std::cout << ANSI_BLUE << messaggio.getMittente().getNome() << ": " << messaggio.getContenuto() << ANSI_RESET << std::endl;
        } else if (messaggio.getMittente().getId() == utente2.getId()) {
            // Stampa messaggi dell'utente2 in rosso
            std::cout << ANSI_RED << messaggio.getMittente().getNome() << ": " << messaggio.getContenuto() << ANSI_RESET << std::endl;
        }
    }
}


const Utente& Chat::getUtente1() const {
    return utente1;
}

const Utente& Chat::getUtente2() const {
    return utente2;
}

const std::vector<Messaggio>& Chat::getMessaggi() const {
    return messaggi;
}