#include "../include/server.h"

int main() {

    readConfig();
    int PORT = config.port;
    int serverSocket;
    
    if (createServerSocket(serverSocket) == 1) {
        std::cout << "Server listening on port " << PORT << "..." << std::endl;
    } else {
        std::cerr << "Server socket creation failed." << std::endl;
    }


    std::thread listenConnectionThread(listenConnection, serverSocket);
    std::thread serveClientThread(handleClients);

    listenConnectionThread.join();
    serveClientThread.join();

    close(serverSocket);

    return 0;
}