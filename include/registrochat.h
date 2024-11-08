#ifndef REGISTROCHAT_H
#define REGISTROCHAT_H

#include "chat.h"
#include "registroutenti.h"
#include <vector>


class RegistroChat {
private:
    std::vector<Chat> chats;
    void salvaSuFile() const;// Salva solo l'ultima chat aggiunta in coda al file
    void caricaDaFile(RegistroUtenti &registroUtenti); // Carica le chat da un file

public:
    RegistroChat(RegistroUtenti &registroUtenti);
    void aggiungiChat(const Chat &chat);
    void mostraChatsPerUtente(const Utente &utente) const;
    Chat getChatByIndicePerUtente(const Utente &utente, int indice);  //questo metodo non è dichiarato costante perchè quando seleziona
                                                                      //la chat che l'utente vuole "trattare" la toglie dal vector delle
                                                                      //chat della classe registrochat per poi potercela reionserire eventualmente modificata
};

#endif
