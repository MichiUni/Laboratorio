#include "utente.h"
#include <iostream>

Utente::Utente(int id, const std::string &nome) : id(id), nome(nome) {}

int Utente::getId() const {
    return id;
}

std::string Utente::getNome() const {
    return nome;
}
