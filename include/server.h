#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <netinet/in.h>
#include <unistd.h>
#include <thread>
#include <mutex>
#include <fstream>
#include <chrono>
#include <string>

struct Config {
    int port;
    int max_Clients;
};
extern Config config;

extern std::vector<std::pair<int, int>> clients;
extern std::queue<std::pair<int, int>> clientQueue;
extern std::mutex clientListMutex;

void readConfig();

int createServerSocket(int& serverSocket);

void listenConnection(int serverSocket);

void handleClients();
void serveClient(std::pair<int, int> client);


#endif // SERVER_H