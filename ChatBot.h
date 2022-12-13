#ifndef CHATBOT_H
#define CHATBOT_H

#include <string>
#include <map>

class ChatBot
{
public:
    /**
     * Create new ChatBot
     * @param name - name for the ChatBot
     */
    ChatBot(std::string name);

    /**
     * Search incoming message and generate response if key words are found.
     * Use the map of responses to find responses based on keywords found in the entire input message.
     * Need to parse each word, ignore non-alpha characters, convert words to uppercase
     * Only one response per message (first identified keyword)
     * @param message - message to parse to find keywords
     */
    void newMessage(std::string message);

    /**
     * Load responses for keywords from a file
     * File has format KEYWORD:response for each line
     * Keywords are all uppercase and response is a string
     * This populates the responses map
     * @param fileName - file name storing KEYWORD:response pairs
     */
    void loadResponses(std::string fileName);

private:

    /**
     * Name of the ChatBot
     */
    std::string name;

    /**
     * Map associating KEYWORD (string) to a response (string)
     */
    std::map<std::string, std::string> responses;
};

#endif
