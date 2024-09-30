#include "registroutenti.h"
#include <fstream>


int RegistroUtenti::prossimoId=1;

RegistroUtenti::RegistroUtenti() {
    caricaDaFile();  // Carica gli utenti esistenti dal file all'avvio del programma
}

// Metodo per registrare un nuovo utente
Utente* RegistroUtenti::registraUtente(const std::string &nome, const std::string &numeroTelefono) {
    utenti.emplace_back(prossimoId++, nome, numeroTelefono);
    salvaSuFile();  // Salva l'ultimo utente aggiunto
    return &utenti.back();
}

Utente* RegistroUtenti::login(const std::string &nome, const std::string &numeroTelefono) {
    for (auto &utente : utenti) {
        if (utente.getNome() == nome && utente.getNumeroTelefono() == numeroTelefono) {
            return &utente;
        }
    }
    return registraUtente(nome, numeroTelefono);  // Se non esiste, registralo
}

// Metodo per trovare un utente tramite numero di telefono
Utente* RegistroUtenti::trovaUtentePerNumero(const std::string &numeroTelefono) {
    for (auto &utente : utenti) {
        if (utente.getNumeroTelefono() == numeroTelefono) {
            return &utente;  // Restituisce il puntatore all'utente trovato
        }
    }
    return nullptr;  // Se nessun utente viene trovato, restituisce nullptr
}

// Metodo per trovare un utente tramite nome
Utente* RegistroUtenti::trovaUtentePerNome(const std::string &nome) {
    for (auto &utente : utenti) {
        if (utente.getNome() == nome) {
            return &utente;  // Restituisce il puntatore all'utente trovato
        }
    }
    return nullptr;  // Se nessun utente viene trovato, restituisce nullptr
}

// Metodo per trovare un utente tramite ID
Utente* RegistroUtenti::trovaUtentePerId(int id){
    for (auto &utente : utenti) {
        if (utente.getId() == id) {
            return &utente;  // Restituisce il puntatore all'utente trovato
        }
    }
    return nullptr;  // Se nessun utente viene trovato, restituisce nullptr}{
}

// Metodo per salvare solo l'ultimo utente in coda al file
void RegistroUtenti::salvaSuFile() {
    // Apri il file in modalità append per aggiungere solo l'ultimo utente
    std::ofstream file("utenti.txt", std::ios::app);
    if (file.is_open()) {
        // Aggiungi solo l'ultimo utente nel vettore
        const Utente& ultimoUtente = utenti.back();
        file << ultimoUtente.getId() << " " << ultimoUtente.getNome() << " " << ultimoUtente.getNumeroTelefono() << std::endl;
    }
    file.close();
}

// Metodo per caricare i dati degli utenti da un file
void RegistroUtenti::caricaDaFile() {
    std::ifstream file("utenti.txt");
    if (file.is_open()) {
        utenti.clear();  // Pulisci il vettore prima di caricare i dati
        int id;
        std::string nome, numeroTelefono;
        while (file >> id >> nome >> numeroTelefono) {
            utenti.emplace_back(id, nome, numeroTelefono);
            if (id >= prossimoId) {
                prossimoId = id + 1;  // Mantieni il prossimo ID corretto
            }
        }
    }
    file.close();
}