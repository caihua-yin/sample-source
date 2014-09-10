#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
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
int main()
{
    int sockfd;
    int len;
    struct sockaddr_un address;

    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);

    address.sun_family = AF_UNIX;
    strcpy(address.sun_path, "server_socket");
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
