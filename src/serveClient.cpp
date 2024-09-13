#include "../include/server.h"


void serveClient(std::pair<int, int> client) {
    srand(time(0));
    while(true) {
        int randomNUmber = rand() % 900 + 100; // generate number between 100 and 999
        std::string response = std::to_string(randomNUmber) + "\n";

        send(client.second, response.c_str(), response.size(), 0);
        std::cout << "Sent data: " << randomNUmber << " to client: " << client.first << std::endl;

        sleep(2);
    }
}

void handleClients() {
    while(true) {
        std::lock_guard<std::mutex> lock(clientListMutex);
        if (!clientQueue.empty()) {
            std::pair<int, int> client = clientQueue.front();
            clientQueue.pop();
            std::thread(serveClient, client).detach();
        }
    }
}