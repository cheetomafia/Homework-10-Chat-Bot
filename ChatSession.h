#ifndef CHATSESSION_H
#define CHATSESSION_H

#include "ChatBot.h"
#include <memory>
#include <list>

class ChatSession
{
public:
    /**
     * Create new chat session
     * @param userName - your username
     * @param echo - true if input messages to echo back
     */
    ChatSession(std::string userName, bool echo);

    /**
     * Add chat box to chat session
     * @param bot - shared pointer to ChatBox to add
     */
    void registerBot(std::shared_ptr<ChatBot> bot);

    /**
     * Remove a bot from chat session (not used, here for completeness)
     * @param bot - shared pointer to ChatBot to remove
     */
    void removeBot(std::shared_ptr<ChatBot> bot);

    /**
     * Notify all ChatBots in the session of new message
     * @param message - string message to notify all about
     */
    void notifyBots(std::string message);

    /**
     * Run the chat session, handle input from terminal and
     * notify all ChatBox of the messages as they are input.
     *
     * Function terminates when "QUIT" is entered by the user.
     */
    void run();

private:

    /**
     * Stores list of chat bots for the chat session
     */
    std::list<std::shared_ptr<ChatBot>> bots;

    /**
     * User name of person starting the chat session ("you")
     */
    std::string userName;

    /**
     * True if input message are to be echoed to the terminal
     */
    const bool echo = true;
};

#endif
