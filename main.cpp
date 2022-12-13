#include <iostream>
#include "ChatSession.h"


using namespace std;
const bool ECHO_INPUT = true;

int main()
{

    /*
     * Input to setup Chat Session
     * USERNAME
     * BOTNAME_1
     * BOTNAME_2
     * ....
     * START
     */
  

    /*
     * Example:
     * Neo
     * T800
     * START
     */

    string userName;
    string botName;
 
    // Read in username and create the chat sesssion
 // std::getline(std::cin, userName);
/*cin >> userName;
  //ChatSession(std::string userName, bool echo);
  ChatSession chat(userName, true);
  
  //std::getline(std::cin, botName);
     

    // Register the chat bots
  
  //ChatBot chatbot(botName);
  //std::getline(std::cin, botName);
  cin >> botName;  
  while(botName != "START")
    {
      //ChatBot(std::string name);
      //ChatBot bot(botName);
      shared_ptr<ChatBot> bot(new ChatBot(botName));
      bot->loadResponses(botName+".txt");
      chat.registerBot(bot);
      cin >> botName;
     
    }

    // Run the chat session
  
   chat.run();*/
  
     // Read in username and create the chat sesssion
    cin >> userName;
    ChatSession chat(userName, true);
    // Register the chat bots
    cin >> botName;
    while(botName != "START")
    {
      shared_ptr<ChatBot> bot(new ChatBot(botName));
      bot->loadResponses(botName+".txt");
      chat.registerBot(bot);
      cin >> botName;
    }

    // Run the chat session
    chat.run();
   

    return 0;
}
