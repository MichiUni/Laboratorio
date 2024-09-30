#ifndef UTENTE_H
#define UTENTE_H

#include <string>

class Utente {
private:
    int id;
    std::string nome;
    std::string numeroTelefono;

public:
    Utente(int id, const std::string &nome, const std::string &numeroTelefono);
    int getId() const;
    std::string getNome() const;
    std::string getNumeroTelefono() const;

    bool operator==(const Utente &other) const;
};

#endif
