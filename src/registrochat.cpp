#include "registrochat.h"
#include <fstream>
#include <iostream>

// Costruttore: carica le chat dal file
RegistroChat::RegistroChat(RegistroUtenti &registroUtenti) {
    caricaDaFile(registroUtenti);
}
// Metodo per aggiungere una nuova chat
void RegistroChat::aggiungiChat(const Chat &chat) {
    chats.push_back(chat);
    salvaSuFile();
}

void RegistroChat::mostraChatsPerUtente(const Utente &utente) const {
    int indice = 1;
    for (const auto &chat : chats) {
        if (chat.getUtente1().getId() == utente.getId() || chat.getUtente2().getId() == utente.getId()) {
            std::cout << indice << ". Chat con "
                      << (chat.getUtente1().getId() == utente.getId() ? chat.getUtente2().getNome() : chat.getUtente1().getNome())
                      << std::endl;
            indice++;
        }
    }
}

Chat RegistroChat::getChatByIndicePerUtente(const Utente &utente, int indice){
    int contatore = 0;
    for (auto it = chats.begin(); it != chats.end(); ++it) {
        if (it->getUtente1().getId() == utente.getId() || it->getUtente2().getId() == utente.getId()) {
            if (contatore == indice) {
                // Trovata la chat, estraila dal vettore
                Chat chatSelezionata = *it;  // Crea una copia della chat
                chats.erase(it);  // Rimuovi la chat dal vettore
                return chatSelezionata;  // Restituisci la chat estratta
            }
            contatore++;
        }
    }
    throw std::out_of_range("Indice non valido");  // Gestisce il caso in cui l'indice sia fuori dai limiti
}


//il metodo getMessaggi che era dichiarato nella classe chat, e che rompeva l'incapsulamento, era necessario nel vecchio metodo
//salvaSuFile per scorrere i messaggi della chat per poterli salvare(con tutti i loro parametri opportunatamente posizionati nel file).
//Per risolvere questo problema creo il metodo salvaSuFile anche nella classe chat di modo che sarà ogni chat, che viene chiamata in causa
//dal for del metodo salvaSuFile della classe registrochat, a salvare sé stessa sul file
void RegistroChat::salvaSuFile() const {
    // Apri il file in modalità sovrascrittura (std::ios::trunc) per riscrivere tutte le chat
    std::ofstream file("chats.txt", std::ios::trunc);  // Il file viene aperto e svuotato
    if(file.is_open()){
        file.close();
    }
    for (const auto &chat : chats) {
        chat.salvaSuFile();
    }
}


void RegistroChat::caricaDaFile(RegistroUtenti &registroUtenti) {
    std::ifstream file("chats.txt");
    if (file.is_open()) {
        int idUtente1, idUtente2;
        while (file >> idUtente1 >> idUtente2) {
            // Cerca gli utenti nel registro usando i loro ID
            Utente* utente1 = registroUtenti.trovaUtentePerId(idUtente1);
            Utente* utente2 = registroUtenti.trovaUtentePerId(idUtente2);

            // Se entrambi gli utenti esistono, crea una chat
            if (utente1 != nullptr && utente2 != nullptr) {
                Chat chat(*utente1, *utente2);

                int idMittente, idDestinatario;
                std::string contenuto;
                // Continua a leggere i messaggi fino a quando non troviamo "END_CHAT"
                while (true) {
                    // Se incontriamo "END_CHAT", interrompi la lettura della chat corrente
                    if (file.fail() || file.eof() || file.peek() == 'E') {
                        std::string endChatMarker;
                        file >> endChatMarker;
                        if (endChatMarker == "END_CHAT") {
                            break;
                        }
                    }
                    int is_letto;
                    file >> idMittente;
                    file >> idDestinatario;
                    file >> is_letto;
                    file.ignore(); // Ignora lo spazio prima del contenuto del messaggio
                    std::getline(file, contenuto);

                    // Trova gli utenti mittente e destinatario
                    Utente* mittente = registroUtenti.trovaUtentePerId(idMittente);
                    Utente* destinatario = registroUtenti.trovaUtentePerId(idDestinatario);

                    // Se entrambi esistono, aggiungi il messaggio alla chat
                    if (mittente != nullptr && destinatario != nullptr) {
                        chat.aggiungiMessaggio(Messaggio(*mittente, *destinatario, contenuto,is_letto));
                    }
                }

                // Aggiungi la chat completa al registro delle chat
                chats.push_back(chat);
            }

            // Verifica se siamo alla fine del file prima di proseguire
            if (file.eof()) {
                break;
            }
        }
    }
    file.close();
}


