#ifndef REGISTROUTENTI_H
#define REGISTROUTENTI_H

#include "utente.h"
#include <vector>
#include <string>

class RegistroUtenti {
private:
    std::vector<Utente> utenti;
    static int prossimoId;

    Utente* registraUtente(const std::string &nome, const std::string &numeroTelefono);

    void salvaSuFile() const;           // Salva i dati su un file
    void caricaDaFile();          // Carica i dati da un file

public:
    RegistroUtenti();

    Utente* login(const std::string &nome, const std::string &numeroTelefono);

    Utente* trovaUtentePerNumero(std::string &numeroTelefono);  // Cerca un utente per numero di telefono
    Utente* trovaUtentePerNome(std::string &nome);  // Cerca un utente per nome
    Utente* trovaUtentePerId(int id);
};

#endif // REGISTROUTENTI_H
