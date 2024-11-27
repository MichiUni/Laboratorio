#include "utente.h"
#include <iostream>
#include <vector>

Utente::Utente(int id, const std::string &nome, const std::string &numeroTelefono) : id(id), nome(nome), numeroTelefono(numeroTelefono)  {}

int Utente::getId() const {
    return id;
}

std::string Utente::getNome() const {
    return nome;
}

std::string Utente::getNumeroTelefono() const {
    return numeroTelefono;
}

bool Utente::operator==(const Utente &other) const {
    // Confronta gli ID degli utenti per determinare l'uguaglianza
    return this->id == other.id;
}

void Utente::mostraNotifiche(){
    for (std::vector<std::string>::iterator it = notifiche.begin(); it != notifiche.end(); ++it) {
        std::cout << *it << std::endl;
    }
    notifiche.clear();
}

void Utente::aggiungiNotifica(const std::string &nome_mittente) {
    notifiche.push_back("Hai ricevuto un messaggio da "+nome_mittente);
}

