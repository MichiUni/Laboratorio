#include "chat.h"
#include "MessaggioNonValidoException.h"
#include <iostream>
#include <fstream>


Chat::Chat(const Utente &utente1, const Utente &utente2) : utente1(utente1), utente2(utente2), num_messaggi(0) {}

void Chat::aggiungiMessaggio(const Messaggio &messaggio) {
    if((messaggio.getMittente().getId()==utente1.getId() && messaggio.getDestinatario().getId()==utente2.getId()) || (messaggio.getMittente().getId()==utente2.getId() && messaggio.getDestinatario().getId()==utente1.getId())){
        messaggi.push_back(messaggio);
        num_messaggi++;
    }
    else {
        throw MessaggioNonValidoException("Errore: Il messaggio non appartiene a questa chat.");
    }
}

void Chat::mostraChat(){
    const std::string ANSI_BLUE = "\033[34m";   // Colore blu per i messaggi dell'utente1
    const std::string ANSI_RED = "\033[31m";    // Colore rosso per i messaggi dell'utente2
    const std::string ANSI_YELLOW = "\033[33m"; // Colore giallo per i messaggi non letti
    const std::string ANSI_PURPLE= "\033[35m"; //Colore viola per il numero di messaggi della chat
    const std::string ANSI_RESET = "\033[0m";   // Resetta il colore

    std::cout<<ANSI_PURPLE<<"Questa chat contiene "<<num_messaggi<<" messaggi"<<ANSI_RESET<<std::endl;

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

/*const std::vector<Messaggio>& Chat::getMessaggi() const {
    return messaggi;
}
*/

void Chat::salvaSuFile() const {
    std::ofstream file("chats.txt", std::ios::app);  // Il file viene aperto in modalità append
    if(file.is_open()) {
        file << utente1.getId() << " " << utente2.getId() << std::endl;
        for (const auto &messaggio: messaggi) {
            file << messaggio.getMittente().getId() << " "
                 << messaggio.getDestinatario().getId() << " ";
            if (messaggio.isLetto()) {
                file << 1 << " ";
            } else {
                file << 0 << " ";
            }
            file << messaggio.getContenuto() << std::endl;
        }
        file << "END_CHAT" << std::endl;  // Indicatore di fine chat
    }
    file.close();
}