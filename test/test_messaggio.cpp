#include "gtest/gtest.h"
#include "messaggio.h"
#include "utente.h"

// Test per il costruttore Messaggio con mittente e destinatario diversi
TEST(MessaggioTest, CostruttoreMittenteDestinatarioDiversi) {
    Utente mittente(1, "Alice", "123456789");
    Utente destinatario(2, "Bob", "987654321");
    Messaggio messaggio(mittente, destinatario, "Ciao, Bob!");

    EXPECT_EQ(messaggio.getMittente().getNome(), "Alice");
    EXPECT_EQ(messaggio.getDestinatario().getNome(), "Bob");
    EXPECT_EQ(messaggio.getContenuto(), "Ciao, Bob!");
    EXPECT_FALSE(messaggio.isLetto());
}

// Test per il costruttore Messaggio con mittente e destinatario uguali
TEST(MessaggioTest, CostruttoreMittenteDestinatarioUguali) {
    Utente mittenteDestinatario(1, "Alice", "123456789");
    Messaggio messaggio(mittenteDestinatario, mittenteDestinatario, "Messaggio a me stessa");

    EXPECT_EQ(messaggio.getMittente().getNome(), "Alice");
    EXPECT_EQ(messaggio.getDestinatario().getNome(), "Alice");
    EXPECT_EQ(messaggio.getContenuto(), "Messaggio a me stessa");
    EXPECT_FALSE(messaggio.isLetto());
}

// Test per il metodo setLetto e isLetto
TEST(MessaggioTest, SetLettoIsLetto) {
    Utente mittente(1, "Alice", "123456789");
    Utente destinatario(2, "Bob", "987654321");
    Messaggio messaggio(mittente, destinatario, "Ciao, Bob!");

    EXPECT_FALSE(messaggio.isLetto());
    messaggio.setLetto(true);
    EXPECT_TRUE(messaggio.isLetto());
}
