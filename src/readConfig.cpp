#include "../include/server.h"
// no error in this file
Config config;

void readConfig() {

    std::string file = "../config/env.cfg";
    std::ifstream fileStream(file);
    std::string line;

    while (std::getline(fileStream, line)) {

        size_t delimiterPos = line.find('=');

        if (delimiterPos != std::string::npos) {

            std::string key = line.substr(0, delimiterPos);
            std::string value = line.substr(delimiterPos + 1);

            key.erase(key.find_last_not_of(" \t") + 1);
            value.erase(0, value.find_first_not_of(" \t"));

            if (key == "PORT") {
                config.port = std::stoi(value);
            } else if (key == "MAX_CLIENTS") {
                config.max_Clients = std::stoi(value);
            }
        }
    }
    fileStream.close();
    return;
}