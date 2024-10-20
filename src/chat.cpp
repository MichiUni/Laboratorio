#include "chat.h"
#include <iostream>

Chat::Chat(const Utente &utente1, const Utente &utente2) : utente1(utente1), utente2(utente2) {}

void Chat::aggiungiMessaggio(const Messaggio &messaggio) {
    if((messaggio.getMittente().getId()==utente1.getId() && messaggio.getDestinatario().getId()==utente2.getId()) || (messaggio.getMittente().getId()==utente2.getId() && messaggio.getDestinatario().getId()==utente1.getId())){
        messaggi.push_back(messaggio);
    }
    else
    {
        std::cout<<"Errore: Il messaggio non appartiene a questa chat."<<std::endl;
    }
}

void Chat::mostraChat() {
    const std::string ANSI_BLUE = "\033[34m";   // Colore blu per i messaggi dell'utente1
    const std::string ANSI_RED = "\033[31m";    // Colore rosso per i messaggi dell'utente2
    const std::string ANSI_YELLOW = "\033[33m"; // Colore giallo per i messaggi non letti
    const std::string ANSI_RESET = "\033[0m";   // Resetta il colore

    for (auto& messaggio:messaggi) {
        if(!messaggio.isLetto()) {
            std::cout << ANSI_YELLOW;
        }else{
            if(messaggio.getMittente().getId()==utente1.getId()){
                std::cout<<ANSI_BLUE;
            }
            else if(messaggio.getMittente().getId()==utente2.getId()){
                std::cout<<ANSI_RED;
            }
        }
        // Mostra il messaggio
        std::cout << messaggio.getMittente().getNome() << ": "<< messaggio.getContenuto() << ANSI_RESET << std::endl;
        messaggio.setLetto(true);
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