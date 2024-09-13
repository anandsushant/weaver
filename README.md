# Weaver

A multithreaded C++ web server engineered for rapid and concurrent request handling.

## Overview

This project is a multithreaded web server implemented in C++ designed to handle multiple client connections efficiently. The server uses socket programming to establish communication with clients and employs threads and synchronization mechanisms to manage concurrent connections.

## Setup and Build

1. **Configure the Environment**

   Edit the `config/env.cfg` file to set up your desired configuration parameters such as `PORT` and `MAX_CLIENTS`.

2. **Build and Run the Project**

   In the main project directory, create a folder named `build` and compile using following commands:
   ```bash
   mkdir build
   cd build
   cmake..
   make
   ./test

