#ifndef MESSAGGIO_H
#define MESSAGGIO_H

#include "utente.h"
#include <string>

class Messaggio {
private:
    Utente mittente;
    Utente destinatario;
    std::string contenuto;
    bool letto;

public:
    Messaggio(const Utente &mittente, const Utente &destinatario, const std::string &contenuto);
    Messaggio(const Utente &mittente, const Utente &destinatario, const std::string &contenuto, int is_letto); //overload del costruttore, usato nel metodo carica da file

    const Utente &getMittente() const;
    const Utente &getDestinatario() const;
    const std::string &getContenuto() const;

    bool isLetto() const;
    void setLetto(bool value);
};

#endif
