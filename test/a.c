#include<sys/types.h>
#include <fcntl.h>
#include<unistd.h>
#include <stdio.h>

int main() {
    int i = 0;
    for (i = 0; i < 100; i++) {
        const char* file_path = "./test_file";
        int fd = open(file_path, O_RDWR | O_APPEND | O_CREAT);
        if (fd > 0) {
            int size = write(fd, "aaaaa", 5);
            if (size > 0) {
                printf("%d bytes written\n", size);
            }
            else {
                perror("Write file failed");
                return 1;
            }
            close(fd);
        }
        else {
            perror("Create/Open file failed");
            return 1;
        }
    }
    return 0;
}
