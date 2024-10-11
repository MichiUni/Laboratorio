#ifndef UTENTE_H
#define UTENTE_H

#include <string>
#include <vector>

class Utente {
private:
    int id;
    std::string nome;
    std::string numeroTelefono;
    std::vector<std::string> notifiche;

public:
    Utente(int id, const std::string &nome, const std::string &numeroTelefono);
    int getId() const;
    std::string getNome() const;
    std::string getNumeroTelefono() const;

    void mostraNotifiche();
    void aggiungiNotifica(std::string nome_mittente);

    bool operator==(const Utente &other) const;
};

#endif
