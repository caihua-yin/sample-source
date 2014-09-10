#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

void print_error(const char* s) {
    printf("%s, errno: %d, message: %s.\n", s, errno, sys_errlist[errno]);
}

void confirm_continue() {
    printf("Press any key to continue:");
    getchar();
}

int main() {
    int listen_sockfd, connect_sockfd;
    int server_len, client_len;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;

    listen_sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = 9734;
    server_len = sizeof(server_address);
    int ret = bind(listen_sockfd, (struct sockaddr *)&server_address, server_len);
    if (ret < 0) {
        print_error("Bind server socket failed");
        exit(1);
    }
    if (listen(listen_sockfd, 5) < 0 ) {
        print_error("Server listen failed");
        exit(1);
    }
 
    while (1) {
        printf("server waiting...\n");
        client_len = sizeof(client_address);
        connect_sockfd = accept(listen_sockfd,
            (struct sockaddr *)&client_address, &client_len);

        if (connect_sockfd >= 0) {
            printf("Accepted connection.\n");
        }
        else {
            print_error("Accept connection failed");
            exit(1);
        }
        char* buffer = malloc(100);
        ret = read(connect_sockfd, buffer, 100);
        if (ret >= 0) {
            printf("%d bytes read from client.\n", ret);
        }
        else {
            print_error("Read data failed");
            exit(1);
        }
        printf("Message data from client: %s\n", buffer);
        close(connect_sockfd);
    }
}
