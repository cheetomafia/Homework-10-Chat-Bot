# Homework-10-Chat-Bot
Homework 10
===
In this homework you will implement a very simple chat program that has Chat Bots. These Chat Bots
are to be programmed to have fixed responses based on keyword found in a chat session. 
Along the way, you will gain experience with using the STL, specifically a map and list.

This homework has been designed to follow a Observer/Oserverable or Publish/Subscribe design pattern.
You can find more information on these design patterns in many places. 
Here is one such article: https://en.wikipedia.org/wiki/Observer_pattern#:~:text=The%20observer%20pattern%20is%20a,calling%20one%20of%20their%20methods.

Design pattern
===

The ChatSession class is designed to be the "Publisher" of messages. The ChatSession's run function
reads input from the user and "Publishes" the messages to those interested. The interested party
would be the ChatBox class, which is designed to subscribe to the ChatSession (register function)
and receive messages from the publisher (ChatSession).

The ChatSession class contains a list of ChatBot objects that are subscribers to the ChatSession.
Whenever a user inputs a message from the terminal, all of the ChatBots in the session are notified
(notifyBots function) by calling each ChatBot's newMessage function.

When a ChatBot receives an input message, it searches the message for keywords. If it finds any of 
the keywords, it will print out a pre-determined message to the terminal related to that keyword. 

Loading Responses
===
There is a loadResponses function for each ChatBot object. This function reads lines from 
a file that defines a ChatBot's keyword to response mapping. The file has the file name 
ROBOT_NAME.txt where ROBOT_NAME is the name for the ChatBot. There are (2) ChatBots defined
Johnny5 and T800. The format of the file is each line is KEYWORD:response, where KEYWORD 
is a keyword in all caps and the response is a string.

You will need to implement this function such that it inserts a pair into the ChatBot's
member variable responses which is a map container. The pair are to be read from the 
files Johnny5.txt and T800.txt

Generating Responses
===
Each ChatBot that is subscribed to the ChatSession will need to parse incoming messages and
generate a response (if any) to output to the terminal. 

1. You will need to split incoming messages based on any whitespace character into individual words
2. You will need to convert the word to all uppercase. 
3. You need to ignore all non-alpha characters
4. For each word, you will need to search the responses map to see if there is a match
5. If there is a match, you need to output the response
6. The first match is the only response needed
7. No match means no response

Input to program
===
See the main function, but for completeness here is how the input works.

Lines:
* User name for the chat session (your name)
* ChatBot Name (1st)
* ChatBot Name (2nd) 
...
* ChatBot Name (Nth)
* START
* Message 1
* Message 2
...
* Last Message
* QUIT

What is Required
===
* Implement all the member functions outlined by the provided header files. 
* DO NOT MODIFY the header files

Hints
===
* Example for grabbing line with whitespace: std::getline(std::cin >> std::ws, message);
* Perform a cout.flush() before executing std:getline
* Converting to uppercase: std::toupper
* Checking character if alpha: std::isalpha
* Think about using a lambda to convert the raw word to uppercase only alpha.
* You can use a stringstream object to iterate through the words in a string
* You can use the find function of a map to look for keywords
* The find function returns an iterator
* If "find" does not find a match it returns iterator that points to the contain's end
* When implementing loadResponses consider using find and substr member functions of string.
