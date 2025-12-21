#Weaver
Multithreaded C++ TCP Server for Concurrent Clients

Weaver is a multithreaded TCP server written in modern C++, designed to handle multiple concurrent client connections with a focus on correctness, concurrency control, and low-level systems understanding.
The project serves as a hands-on exploration of Linux networking, thread synchronization, IPC concepts, and safe memory management in performance-sensitive systems.

Motivation

High-performance systems—such as trading engines, distributed services, and real-time backends—rely heavily on:

efficient socket handling

safe concurrency

predictable behavior under load

Weaver was built to understand these fundamentals from first principles, without relying on high-level frameworks or abstractions.

Key Features

TCP-based server supporting multiple concurrent clients

Multithreaded request handling

Explicit use of POSIX sockets (socket, bind, listen, accept)

Thread-safe access to shared resources
High-Level Architecture

The main thread listens for incoming connections.

Each client connection is handled by a worker thread.

Shared resources are protected using synchronization primitives.

Concurrency Model

Each client connection is handled independently.

Worker threads operate concurrently, enabling parallel request processing.

Synchronization mechanisms are used to ensure:

thread-safe shared state access

absence of race conditions

predictable behavior under concurrent load

The project prioritizes correctness and clarity over premature optimization.
Clean ownership and lifetime management

Designed and tested on Linux
