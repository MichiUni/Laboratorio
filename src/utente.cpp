#include "utente.h"
#include <iostream>

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

