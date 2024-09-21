#include "registrochat.h"
#include <iostream>

void RegistroChat::aggiungiChat(const Chat &chat) {
    chats.push_back(chat);
}

void RegistroChat::mostraChats() const {
    for (const auto &chat : chats) {
        chat.mostraChat();
        std::cout << std::endl;
    }
}
