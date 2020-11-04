#include <unistd.h>
#include <string.h>
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
  server.sin_addr.s_addr = INADDR_ANY;
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

  char *msg;
  while ((new_socket = accept(socket_desc, (struct sockaddr*)&client, (socklen_t*)&c))) {
    printf("Connection accepted\n"); 
    // reply to client
    msg = "Msg from server\n";
    write(new_socket, msg, strlen(msg));
  }

  if (new_socket < 0) {
    printf("Connection failed\n");
    return -1;
  }
  return 0;
}
