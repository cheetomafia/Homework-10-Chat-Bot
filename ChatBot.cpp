#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "ChatBot.h"

using namespace std;

ChatBot::ChatBot(string name)
    : name(name) {}

void ChatBot::newMessage(string message)
{
    stringstream ss(message);
    string word;

    auto strUpper = [](string w){
        string u;
        for(auto c : w ){
            if( std::isalpha(c) )
            {
                u += toupper(c);
            }
        }
        return u;
    };

    while( ss >> word) {
        auto respIt = responses.find(strUpper(word));
        if (respIt != responses.end()) {
            cout << "[" + name + "]: " + respIt->second << endl;
            break;
        }
    }
}

void ChatBot::loadResponses(std::string fileName)
{
    ifstream file(fileName);
    string line;
    while(getline(file, line) )
    {
        int splitIndex = line.find(':');
        string keyword = line.substr(0, splitIndex);
        string resp = line.substr(splitIndex+1, line.size()-1);
        responses.insert(pair<string,string>(keyword, resp));
    }
    file.close();
}
