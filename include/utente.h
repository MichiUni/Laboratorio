#ifndef UTENTE_H
#define UTENTE_H

#include <string>

class Utente {
private:
    int id;
    std::string nome;

public:
    Utente(int id, const std::string &nome);
    int getId() const;
    std::string getNome() const;
};

#endif
