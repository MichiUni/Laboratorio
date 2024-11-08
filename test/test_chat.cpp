#include "gtest/gtest.h"
#include "chat.h"
#include "messaggio.h"
#include "utente.h"

// Test per aggiungere un messaggio valido a una chat
TEST(ChatTest, AggiungiMessaggioValido) {
    Utente utente1(1, "Alice", "123456789");
    Utente utente2(2, "Bob", "987654321");
    Chat chat(utente1, utente2);

    Messaggio messaggio(utente1, utente2, "Ciao, Bob!");
    chat.aggiungiMessaggio(messaggio);

    // Verifica che il messaggio sia stato aggiunto
    chat.mostraChat();  // Questo dovrebbe mostrare il messaggio
}

// Test per aggiungere un messaggio non valido a una chat
TEST(ChatTest, AggiungiMessaggioNonValido) {
    Utente utente1(1, "Alice", "123456789");
    Utente utente2(2, "Bob", "987654321");
    Chat chat(utente1, utente2);

    Utente utente3(3, "Charlie", "111222333");
    Messaggio messaggio(utente1, utente3, "Messaggio non valido");  // Mittente e destinatario non corrispondono alla chat
    chat.aggiungiMessaggio(messaggio);  // Dovrebbe dare un errore

    // Assicurati che il messaggio non venga aggiunto
    chat.mostraChat();  // Non dovrebbe mostrare il messaggio
}
