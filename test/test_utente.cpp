#include <gtest/gtest.h>
#include "utente.h"

TEST(UtenteTest, Costruttore) {
Utente utente(1, "Mario", "1234567890");
EXPECT_EQ(utente.getId(), 1);
EXPECT_EQ(utente.getNome(), "Mario");
EXPECT_EQ(utente.getNumeroTelefono(), "1234567890");
}

TEST(UtenteTest, AggiungiNotifica) {
Utente utente(1, "Mario", "1234567890");
utente.aggiungiNotifica("Nuovo messaggio da Luigi");
EXPECT_NO_THROW(utente.mostraNotifiche());
}
