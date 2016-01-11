#include "k_socket.h"
#include "k_types.h"



k_status_t
k_socket_init()
{
#ifdef linux
	//noting to do
#else
	WORD wVersionRequested;
	WSADATA wsaData;

	wVersionRequested = MAKEWORD(2, 2);

	// 0 is success
	return WSAStartup(wVersionRequested, &wsaData);
#endif
}

k_status_t
k_sockt_destory()
{
#ifdef linux
	//noting to do
#else
	return WSACleanup();
#endif
	return K_SUCCESS;
}

errno_t
k_socket_errno()
{
#ifdef linux
	return errno;
#else
	return WSAGetLastError();
#endif
}

k_socket_t
k_socket(int domain, int type, int protocol)
{
	
#ifdef linux
	//noting to do
#else
	
#endif
	return socket(domain, type, protocol);
}

k_status_t
k_bind(k_socket_t sock_fd, k_sockaddr_t* my_addr, int addr_len)
{
	return bind(sock_fd, my_addr, addr_len);
}

k_status_t
k_connect(k_socket_t sock_fd, k_sockaddr_t *serv_addr, int addrlen)
{
	return connect(sock_fd, serv_addr, addrlen);
}

k_status_t
k_listen(k_socket_t sock_fd, int backlog)
{
	return listen(sock_fd, backlog);
}

k_status_t
k_accept(k_socket_t sock_fd, k_sockaddr_t* addr, int addrlen)
{
#ifdef linux
	return accept(sock_fd, addr, addrlen);
#else
	return accept(sock_fd, addr, &addrlen);
#endif

}

k_size_t
k_send(k_socket_t fd, const void *buf, size_t nbytes)
{
#ifdef linux
	return write(fd, buf, nbytes);
#else
	return send(fd, buf, nbytes, 0);
#endif
}

k_size_t
k_recv(k_socket_t fd, void *buf, size_t nbytes)
{
#ifdef linux
	return read(fd, buf, nbytes);
#else
	return recv(fd, buf, nbytes,0);
#endif
}

k_status_t
k_close(k_socket_t sock_fd)
{
#ifdef linux
	return colse(sock_fd);
#else
	return closesocket(sock_fd);
#endif
}