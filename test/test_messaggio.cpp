#include <gtest/gtest.h>
#include "messaggio.h"

TEST(MessaggioTest, Costruttore) {
Utente mittente(1, "Mario", "1234567890");
Utente destinatario(2, "Luigi", "0987654321");
Messaggio messaggio(mittente, destinatario, "Ciao!");

EXPECT_EQ(messaggio.getMittente().getNome(), "Mario");
EXPECT_EQ(messaggio.getDestinatario().getNome(), "Luigi");
EXPECT_EQ(messaggio.getContenuto(), "Ciao!");
}
