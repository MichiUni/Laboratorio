#include "gtest/gtest.h"
#include "registrochat.h"
#include "registroutenti.h"
#include "utente.h"
#include "chat.h"
#include <fstream>
#include <sstream>
#include <iostream>

class RegistroChatTest : public ::testing::Test {
protected:
    RegistroUtenti registroUtenti;
    RegistroChat* registroChat;

    void SetUp() override {
        // Ripulisce il file delle chat prima di ogni test
        std::ofstream("chats.txt", std::ios::trunc).close();
        registroChat = new RegistroChat(registroUtenti);
    }

    void TearDown() override {
        delete registroChat;
    }

    // Funzione di supporto per catturare l'output di mostraChat
    std::string catturaMostraChat(Chat& chat) {
        std::ostringstream oss;
        auto oldCoutBuf = std::cout.rdbuf(oss.rdbuf());
        chat.mostraChat();
        std::cout.rdbuf(oldCoutBuf);  // Ripristina il buffer standard di cout
        return oss.str();
    }
};

// Test per l'aggiunta di una chat
TEST_F(RegistroChatTest, AggiungiChat) {
    Utente* utente1 = registroUtenti.login("Alice", "123456789");
    Utente* utente2 = registroUtenti.login("Bob", "987654321");

    Chat nuovaChat(*utente1, *utente2);
    nuovaChat.aggiungiMessaggio(Messaggio(*utente1, *utente2, "Ciao, Bob!"));
    registroChat->aggiungiChat(nuovaChat);

    std::string output = catturaMostraChat(nuovaChat);
    EXPECT_NE(output.find("Ciao, Bob!"), std::string::npos);
}

// Test per il recupero di una chat esistente per un utente
TEST_F(RegistroChatTest, GetChatByIndicePerUtente) {
    Utente* utente1 = registroUtenti.login("Alice", "123456789");
    Utente* utente2 = registroUtenti.login("Bob", "987654321");

    Chat nuovaChat(*utente1, *utente2);
    nuovaChat.aggiungiMessaggio(Messaggio(*utente1, *utente2, "Messaggio di prova"));
    registroChat->aggiungiChat(nuovaChat);

    Chat chatEstratta = registroChat->getChatByIndicePerUtente(*utente1, 0);
    EXPECT_EQ(chatEstratta.getUtente1().getNome(), "Alice");
    EXPECT_EQ(chatEstratta.getUtente2().getNome(), "Bob");

    std::string output = catturaMostraChat(chatEstratta);
    EXPECT_NE(output.find("Messaggio di prova"), std::string::npos);
}

// Test per mostrare le chat di un utente
TEST_F(RegistroChatTest, MostraChatsPerUtente) {
    Utente* utente1 = registroUtenti.login("Alice", "123456789");
    Utente* utente2 = registroUtenti.login("Bob", "987654321");

    Chat nuovaChat(*utente1, *utente2);
    registroChat->aggiungiChat(nuovaChat);

    std::ostringstream oss;
    auto oldCoutBuf = std::cout.rdbuf(oss.rdbuf());
    registroChat->mostraChatsPerUtente(*utente1);
    std::cout.rdbuf(oldCoutBuf);

    std::string output = oss.str();
    EXPECT_NE(output.find("Chat con Bob"), std::string::npos);
}

// Test per verificare il caricamento da file
TEST_F(RegistroChatTest, CaricaDaFile) {
    Utente* utente1 = registroUtenti.login("Alice", "123456789");
    Utente* utente2 = registroUtenti.login("Bob", "987654321");

    Chat nuovaChat(*utente1, *utente2);
    nuovaChat.aggiungiMessaggio(Messaggio(*utente1, *utente2, "Ciao, Bob!"));
    registroChat->aggiungiChat(nuovaChat);

    // Crea un nuovo registro e carica dal file
    RegistroChat nuovoRegistroChat(registroUtenti);
    Chat chatEstratta = nuovoRegistroChat.getChatByIndicePerUtente(*utente1, 0);

    std::string output = catturaMostraChat(chatEstratta);
    EXPECT_NE(output.find("Ciao, Bob!"), std::string::npos);
}
