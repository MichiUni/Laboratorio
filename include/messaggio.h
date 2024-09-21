#ifndef MESSAGGIO_H
#define MESSAGGIO_H

#include "utente.h"
#include <string>

class Messaggio {
private:
    Utente mittente;
    Utente destinatario;
    std::string contenuto;

public:
    Messaggio(const Utente &mittente, const Utente &destinatario, const std::string &contenuto);
    void mostraMessaggio() const;
};

#endif
