#include "gtest/gtest.h"
#include "utente.h"

// Test per l'aggiunta di notifiche e la loro visualizzazione
TEST(UtenteTest, AggiungiMostraNotifiche) {
    Utente utente(1, "Alice", "123456789");
    utente.aggiungiNotifica("Bob");

    testing::internal::CaptureStdout();
    utente.mostraNotifiche();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Hai ricevuto un messaggio da Bob\n");
}
