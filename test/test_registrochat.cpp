#include <gtest/gtest.h>
#include "registrochat.h"

TEST(RegistroChatTest, AggiungiChat) {
RegistroUtenti registroUtenti;
RegistroChat registroChat(registroUtenti);

Utente utente1(1, "Mario", "1234567890");
Utente utente2(2, "Luigi", "0987654321");
Chat nuovaChat(utente1, utente2);

registroChat.aggiungiChat(nuovaChat);
EXPECT_NO_THROW(registroChat.mostraChatsPerUtente(utente1));
}
