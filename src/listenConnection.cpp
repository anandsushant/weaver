#include "../include/server.h"

int clientID = 10000;
std::vector<std::pair<int, int>> clients;
std::queue<std::pair<int, int>> clientQueue;

std::mutex clientListMutex;
void listenConnection(int serverSocket) {

    while(true) {
        struct sockaddr_in clientAddress;
        socklen_t clientLength = sizeof(clientAddress);
        int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientLength);
        if (clientSocket >= 0) {
            std::lock_guard<std::mutex> lock(clientListMutex);
            clientID++;
            clients.push_back(std::make_pair(clientID, clientSocket));
            clientQueue.push(std::make_pair(clientID, clientSocket));
            std::cout << "A new client added to the list with client ID: " << clientID << std::endl;
        } else {
            std::cerr << "Accept failed." << std::endl;
            close(serverSocket);
            return;
        }
    } 
    return;
}