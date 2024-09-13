#include "../include/server.h"

int createServerSocket(int& serverSocket){

    readConfig(); // read data from env.cfg file

    int PORT = config.port;

    struct sockaddr_in serverAddress;

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == 0) {
        std::cerr << "Socket creation failed." << std::endl;
        return -1;
    }

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(PORT);

    if (bind(serverSocket, (struct sockaddr*)& serverAddress, sizeof(serverAddress)) < 0) {
        std::cerr << "Binding failed." << std::endl;
        close(serverSocket);
        return -1;
    }

    if (listen(serverSocket, 10) < 0) {
        std::cerr << "Listen failed." << std::endl;
        close(serverSocket);
        return -1;
    }

    return 1;
}