# minitalk

Minitalk is a lightweight communication system between processes

The aim of the project is to create a simple server-client architecture that enables two-way communication between a server and multiple clients, using UNIX signals as the medium for data exchange

## Features
- Efficient and lightweight communication using UNIX signals (SIGUSR1 and SIGUSR2)
- Error handling and message delivery confirmation


## Installation
To install Minitalk, clone the repository and build the project using the provided Makefile:
```bash
git clone https://github.com/username/minitalk.git
cd minitalk
make
```
This will generate two binaries: server and client

## Usage
Start the server by running the server binary

The server will display its Process ID (PID)
```bash
./server
```

In a separate terminal, send a message to the server using the client binary and providing the server's PID and the message you want to send
```bash
./client <server_pid> "Your message here"
```

The server will receive and display the message sent by the client

The client will receive a confirmation of successful message delivery
