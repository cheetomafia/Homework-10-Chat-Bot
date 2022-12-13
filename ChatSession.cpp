#include <algorithm>
#include <deque>
#include <iostream>
#include "ChatSession.h"

using namespace std;

ChatSession::ChatSession(string userName, bool echo)
: userName(userName), echo(echo)
{}

void ChatSession::registerBot(std::shared_ptr<ChatBot> bot)
{
    bots.push_back(bot);
}

void ChatSession::removeBot(std::shared_ptr<ChatBot> bot)
{
    auto toRemove = std::find(bots.begin(), bots.end(),bot);
    if( toRemove != bots.end() )
    {
        bots.erase(toRemove);
    }
}

void ChatSession::notifyBots(string message)
{
    for( auto bot : bots )
    {
        bot->newMessage(message);
    }
}

void ChatSession::run()
{
    string message;

    while(message.compare("QUIT")){
        cout << "[" << userName << "]: ";
        cout.flush();
        getline(cin >> ws, message);
        if( echo ) {
            cout << message << endl;
        }
        notifyBots(message);
    }
}
