#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void print_error(const char* s) {
    printf("%s, errno: %d, message: %s.\n", s, errno, sys_errlist[errno]);
}

void confirm_continue() {
    printf("Press any key to continue:");
    getchar();
}
int main()
{
    int sockfd;
    int len;
    struct sockaddr_in address;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = 9734;
    len = sizeof(address);

    int ret = connect(sockfd, (struct sockaddr *)&address, len);
    if(ret < 0) {
        print_error("Connect to server failed");
        exit(1);
    }
    
    char* buffer = malloc(100);
    memset(buffer, 'a', 99);
    buffer[99] = '\0';
    ret = write(sockfd, buffer, 100);
    if (ret >= 0) {
        printf("%d bytes written to server.\n", ret);
    }
    else {
        print_error("Write data failed");
    }
    close(sockfd);
}
