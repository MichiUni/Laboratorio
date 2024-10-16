#include <gtest/gtest.h>
#include "chat.h"

TEST(ChatTest, AggiungiMessaggio) {
Utente utente1(1, "Mario", "1234567890");
Utente utente2(2, "Luigi", "0987654321");
Chat chat(utente1, utente2);

Messaggio messaggio(utente1, utente2, "Ciao!");
chat.aggiungiMessaggio(messaggio);

EXPECT_EQ(chat.getMessaggi().size(), 1);
EXPECT_EQ(chat.getMessaggi()[0].getContenuto(), "Ciao!");
}
