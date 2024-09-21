#ifndef REGISTROCHAT_H
#define REGISTROCHAT_H

#include "chat.h"
#include <vector>


class RegistroChat {
private:
    std::vector<Chat> chats;

public:
    void aggiungiChat(const Chat &chat);
    void mostraChats() const;
};

#endif
