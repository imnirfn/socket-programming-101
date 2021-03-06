#include <unistd.h>
#include <stdio.h>
#include  <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char** argv) {
  
  int socket_desc;
  struct sockaddr_in server;
  
  // AF_INET - to tell the socket to communicate with IPv4
  // AF_INET6 - tell socket to communicate with IPv6
  // SOCK_STREAM - connection based (TCP), terminate if either server terminate the connection
  // SOCK_DGRAM - datagram based (UDP), terminate after one reply
  socket_desc = socket(AF_INET, SOCK_STREAM, 0);
  char *ip = "192.168.0.105";
  if ( socket_desc == -1) {
    printf("Socket error");
  }
  
  // sin_addr - ip address in the socket
  // s_addr - one block of 4bytes integer
  server.sin_addr.s_addr = inet_addr(ip);
  server.sin_family = AF_INET;
  // htons(), htonl - convert values between host & network byte order(big endian)
  server.sin_port = htons(8000);

  // connecting to remote server
  if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
    printf("Connect error\n");
    return 1;
  }
  printf("Connected to %s\n", ip);
  
  // to send data
  char *msg;
  char *server_reply;
  msg = "idk";

  if(send(socket_desc, msg, sizeof(msg), 0) < 0) {
    printf("Send failed\n");
    return 1;
  }

  printf("Data sent\n");

  // this receives a reply from the server
  if (recv(socket_desc, server_reply, 2000, 0) < 0) {
    printf("Reply from server failed\n");
    close(socket_desc);
    return -1;
  }
  printf("Reply received from server:\n");
  puts(server_reply);

  return 0;
}



