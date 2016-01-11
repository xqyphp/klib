#ifndef k_socket_h
#define k_socket_h

#include "k_types.h"

#ifdef linux
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <fcntl.h>

typedef int                  k_socket_t;

#else

#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")

typedef SOCKET               k_socket_t;

#endif

typedef struct	sockaddr  k_sockaddr_t;


k_status_t
k_socket_init();

k_status_t
k_sockt_destory();

errno_t
k_socket_errno();

k_socket_t
k_socket(int domain, int type, int protocol);

k_status_t
k_bind(k_socket_t sock_fd, k_sockaddr_t* my_addr, int addr_len);

k_status_t
k_connect(k_socket_t sock_fd, k_sockaddr_t *serv_addr, int addrlen);

k_status_t
k_listen(k_socket_t sock_fd, int backlog);

k_status_t
k_accept(k_socket_t sock_fd, k_sockaddr_t* addr, int addrlen);

k_size_t
k_send(k_socket_t fd, const void *buf, size_t nbyte);

k_size_t
k_recv(k_socket_t fd,  void *buf, size_t nbytes);

k_status_t 
k_close(k_socket_t sock_fd);

#endif
