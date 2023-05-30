# minitalk

minitalk is a client-server communication program developed as part of the 42 school curriculum. It allows for reliable transmission of messages between a client and a server using only signals. The program demonstrates the use of interprocess communication (IPC) and signal handling in a Unix-like environment.

The main objective of minitalk is to implement a simple and efficient messaging system using the concept of signals. It provides a practical understanding of IPC mechanisms and signal handling techniques, which are fundamental concepts in system-level programming.

## Key Features:

- Client-server architecture: minitalk follows a client-server model, where the client sends messages to the server, which then displays them.
- Signal-based communication: The program utilizes signals to send messages between the client and the server. Each character of the message is transmitted as a series of binary signals.
- Reliable message transmission: minitalk incorporates acknowledgment mechanisms to ensure reliable delivery of messages. The server confirms the successful reception of each character, and the client retransmits if necessary.
- Asynchronous operation: The program allows multiple clients to send messages simultaneously, making use of signal handling to manage concurrent communication.
- Simple and lightweight: minitalk is designed to be minimalistic and lightweight, with a focus on core functionality and efficiency.

*Through the implementation of minitalk, you will gain practical experience in working with signals, handling interruptions, and designing client-server applications. It provides a solid foundation for understanding IPC mechanisms and serves as a stepping stone for more complex interprocess communication scenarios.*

**Note:** This project was developed as part of the 42 school curriculum and should be considered a learning exercise rather than a full-fledged production-grade communication system.
