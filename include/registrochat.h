#ifndef REGISTROCHAT_H
#define REGISTROCHAT_H

#include "chat.h"
#include "registroutenti.h"
#include <vector>


class RegistroChat {
private:
    std::vector<Chat> chats;
    void salvaSuFile();// Salva solo l'ultima chat aggiunta in coda al file
    void caricaDaFile(RegistroUtenti &registroUtenti); // Carica le chat da un file

public:
    RegistroChat(RegistroUtenti &registroUtenti);
    void aggiungiChat(const Chat &chat);
    void mostraChatsPerUtente(const Utente &utente) const;
    Chat getChatByIndicePerUtente(const Utente &utente, int indice);
};

#endif
