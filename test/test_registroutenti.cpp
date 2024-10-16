#include <gtest/gtest.h>
#include "registroutenti.h"

TEST(RegistroUtentiTest, RegistraUtente) {
RegistroUtenti registro;
Utente* nuovoUtente = registro.registraUtente("Mario", "1234567890");

EXPECT_EQ(nuovoUtente->getNome(), "Mario");
EXPECT_EQ(nuovoUtente->getNumeroTelefono(), "1234567890");
}
