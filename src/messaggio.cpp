#include "messaggio.h"
#include <iostream>

Messaggio::Messaggio(const Utente &mittente, const Utente &destinatario, const std::string &contenuto)
        : mittente(mittente), destinatario(destinatario), contenuto(contenuto), letto(false) {}

Messaggio::Messaggio(const Utente &mittente, const Utente &destinatario, const std::string &contenuto, int is_letto)
        : mittente(mittente), destinatario(destinatario), contenuto(contenuto)
        {
            if(is_letto==1)
                letto=true;
            else
                letto=false;
        }

const Utente &Messaggio::getMittente() const {
    return mittente;
}

const Utente &Messaggio::getDestinatario() const {
    return destinatario;
}

const std::string &Messaggio::getContenuto() const {
    return contenuto;
}

bool Messaggio::isLetto() const {
    return letto;
}

void Messaggio::setLetto(bool value) {
    letto=value;
}