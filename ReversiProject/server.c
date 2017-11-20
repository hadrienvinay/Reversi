<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>

/*
 * 
 */
int main(int argc , char *argv[]) {
    
=======
#include "header.h"
#include <sys/socket.h>
#include <arpa/inet.h>


void initServer(){

>>>>>>> b6d08076d707c93b2d3135f7d2c4fb25da207203
int sock;
struct sockaddr_in server;
char message[1000] , server_reply[2000];
//Create socket
sock = socket(AF_INET , SOCK_STREAM , 0);
if (sock == -1) { printf("Could not create socket"); } puts("Socket created");
    server.sin_addr.s_addr =  inet_addr("127.0.0.1");
    server.sin_family =  AF_INET;
    server.sin_port = htons(8888);
    if(connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0) {
        perror("connect failed. Error");
        return 1;
    }
    puts("Connected\n");
    while(1) {
printf("Enter message : "); scanf("%s" , message);
//Send some data
if( write(sock , message , strlen(message) , 0) < 0) { puts("write failed");
return 1; }

//Receive a reply from the server
if( read(sock , server_reply , 2000 ) < 0) { puts("read failed");
break; }
puts("Server reply :");
puts(server_reply); }
close(sock);
<<<<<<< HEAD
return 0; 

}

=======
}
>>>>>>> b6d08076d707c93b2d3135f7d2c4fb25da207203
