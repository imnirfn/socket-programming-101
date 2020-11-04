#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char ** argv) {
  int socket_desc, new_socket, c;
  struct sockaddr_in server, client;

  // Creating the socket
  socket_desc = socket(AF_INET, SOCK_STREAM, 0);

  if (socket_desc == -1) {
    printf("Socket create failed");
  }

  server.sin_family = AF_INET;
  server.sin_addr.s_addr = inet_addr("127.0.0.1"); // testing
  server.sin_port = htons(8000);

  // binding the socket 
  if (bind(socket_desc, (struct sockaddr*)&server, sizeof(server)) < 0) {
    printf("Binding socket failed\n");
  } else {
    printf("Binding socket success\n");
  }

  // Listen for connection
  listen(socket_desc, 3);
  
  // accpt and wait connection
  printf("Waiting for incoming connection\n");
  c = sizeof(struct sockaddr_in);

  new_socket = accept(socket_desc, (struct sockaddr*)&client, (socklen_t*)&c);
  if (new_socket < 0) {
    printf("Connection failed\n");
  }

  printf("Connection accepted\n");
  return 0;
}
