#include "messaggio.h"
#include <iostream>

Messaggio::Messaggio(const Utente &mittente, const Utente &destinatario, const std::string &contenuto)
        : mittente(mittente), destinatario(destinatario), contenuto(contenuto) {}

void Messaggio::mostraMessaggio() const {
    std::cout << mittente.getNome() << " a " << destinatario.getNome() << ": " << contenuto << std::endl;
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
