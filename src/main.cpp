#include <iostream>
#include "utente.h"
#include "messaggio.h"
#include "registroutenti.h"
#include "registrochat.h"
#include "chat.h"


int main() {
    // Crea il registro degli utenti e delle chat
    RegistroUtenti registroUtenti;
    RegistroChat registroChat(registroUtenti);

    std::string nome, numeroTelefono;

    // Login o registrazione dell'utente
    std::cout << "Benvenuto! Inserisci il tuo nome utente: ";
    std::cin >> nome;
    std::cout << "Inserisci il tuo numero di telefono: ";
    std::cin >> numeroTelefono;

    Utente* utenteLoggato = registroUtenti.login(nome, numeroTelefono);

    std::cout << "Ciao, " << utenteLoggato->getNome() << "! Sei loggato nel sistema.\n";

    // Menu principale
    int scelta = 0;
    do {
        std::cout << "\n1. Visualizza le tue chat\n2. Inizia nuova chat\n3. Esci\n";
        std::cin >> scelta;

        if (scelta == 1) {
            // Visualizza solo le chat dell'utente loggato
            registroChat.mostraChatsPerUtente(*utenteLoggato);

            int indiceChat;
            std::cout << "Inserisci il numero della chat per visualizzarla o inviare messaggi (0 per tornare indietro): ";
            std::cin >> indiceChat;

            if (indiceChat != 0) {
                try {
                    // Ottieni la chat selezionata e rimuovila dal vettore
                    Chat chatSelezionata = registroChat.getChatByIndicePerUtente(*utenteLoggato, indiceChat - 1);

                    // Mostra la chat
                    chatSelezionata.mostraChat();

                    // Chiedi all'utente se vuole inviare un nuovo messaggio
                    std::string messaggio;
                    std::cout << "Vuoi inviare un messaggio? (si/no): ";
                    std::string risposta;
                    std::cin >> risposta;

                    if (risposta == "si") {
                        std::cout << "Scrivi il tuo messaggio: ";
                        std::cin.ignore();  // Ignora il newline lasciato dal precedente input
                        std::getline(std::cin, messaggio);

                        // Aggiungi il nuovo messaggio alla chat
                        chatSelezionata.aggiungiMessaggio(Messaggio(*utenteLoggato, chatSelezionata.getUtente1() == *utenteLoggato ? chatSelezionata.getUtente2() : chatSelezionata.getUtente1(), messaggio));

                        // Reinserisci la chat aggiornata nel registro
                    }
                    registroChat.aggiungiChat(chatSelezionata);  // Questa chat sarà riscritta sul file
                } catch (const std::out_of_range &e) {
                    std::cout << "Chat non valida.\n";
                }
            }
        } else if (scelta == 2) {
            // Inizia una nuova chat
            std::string criterio, messaggio;
            std::cout << "Inserisci '1' per cercare un utente tramite numero di telefono, '2' per cercare tramite nome utente: ";
            std::cin >> criterio;

            Utente* altroUtente = nullptr;
            if (criterio == "1") {
                std::string numero;
                std::cout << "Inserisci il numero di telefono: ";
                std::cin >> numero;
                altroUtente = registroUtenti.trovaUtentePerNumero(numero);
            } else if (criterio == "2") {
                std::string nomeUtente;
                std::cout << "Inserisci il nome utente: ";
                std::cin >> nomeUtente;
                altroUtente = registroUtenti.trovaUtentePerNome(nomeUtente);
            }

            if (altroUtente != nullptr) {
                // Inizia la nuova chat
                Chat nuovaChat(*utenteLoggato, *altroUtente);
                std::cout << "Scrivi il primo messaggio: ";
                std::cin.ignore();
                std::getline(std::cin, messaggio);

                nuovaChat.aggiungiMessaggio(Messaggio(*utenteLoggato, *altroUtente, messaggio));
                registroChat.aggiungiChat(nuovaChat);  // Questa chat sarà salvata sul file
            } else {
                std::cout << "Utente non trovato.\n";
            }
        }
    } while (scelta != 3);

    std::cout << "Arrivederci!\n";
    return 0;
}
