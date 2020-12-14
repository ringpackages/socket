#ifndef ring_socket_h
#define ring_socket_h


#include <stdlib.h>
#include <string.h>


#if defined _WIN32
    #define win

    #define WIN32_LEAN_AND_MEAN

    #pragma once

    #include <winsock2.h>
    #include <WS2tcpip.h>

    #pragma comment (lib,"ws2_32.lib")
    #pragma comment (lib,"mswsock.lib")
    #pragma comment (lib,"advapi32.lib")

    typedef struct ring_vm_socket_obj {

        SOCKET sockfd;
        struct addrinfo *addr;
        struct addrinfo hints;

    } RING_SOCKET;

#else

    #include <sys/socket.h>
    #include <sys/types.h>
    #include <netinet/in.h>
    #include <unistd.h>
    #include <arpa/inet.h>
    #include <netdb.h>


    typedef struct ring_vm_socket_obj {

        int sockfd;
        struct sockaddr_in addr;

    } RING_SOCKET;
#endif


void ring_vm_socket_init(void *pPointer);
void ring_vm_socket_bind(void *pPointer);
void ring_vm_socket_listen(void *pPointer);
void ring_vm_socket_accept(void *pPointer);
void ring_vm_socket_send(void *pPointer);
void ring_vm_socket_recv(void *pPointer);
void ring_vm_socket_gethostbyname(void *pPointer);
void ring_vm_socket_gethostbyaddr(void *pPointer);
void ring_vm_socket_connect(void *pPointer);
void ring_vm_socket_close(void *pPointer);
RING_API void ringlib_init(RingState *pRingState);

// MACRO
#define RING_VM_POINTER_SOCKET "socket"

#endif

