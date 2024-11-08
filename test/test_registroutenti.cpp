#include "gtest/gtest.h"
#include "registroutenti.h"
#include "utente.h"

// Test per la registrazione di un nuovo utente
TEST(RegistroUtentiTest, RegistraUtente) {
    RegistroUtenti registro;
    Utente* nuovoUtente = registro.login("Alice", "123456789");

    EXPECT_EQ(nuovoUtente->getNome(), "Alice");
    EXPECT_EQ(nuovoUtente->getNumeroTelefono(), "123456789");
}

// Test per la ricerca di un utente per numero di telefono
TEST(RegistroUtentiTest, TrovaUtentePerNumero) {
    RegistroUtenti registro;
    registro.login("Alice", "123456789");
    Utente* utenteTrovato = registro.trovaUtentePerNumero("123456789");

    ASSERT_NE(utenteTrovato, nullptr);
    EXPECT_EQ(utenteTrovato->getNome(), "Alice");
}
