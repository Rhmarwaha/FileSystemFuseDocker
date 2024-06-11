#define FUSE_USE_VERSION 31

#include <fuse.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

// Data structure to store file content in memory
struct file {
    char *name;
    char *content;
    size_t size;
};

static struct file my_file = {NULL, NULL, 0};

// Function to create (add) a file
static int simple_fs_create(const char *path, mode_t mode, struct fuse_file_info *fi) {
    (void) fi;
    (void) mode;

    if (strcmp(path, "/myfile") != 0)
        return -ENOENT;

    my_file.name = strdup(path + 1);
    my_file.content = NULL;
    my_file.size = 0;

    return 0;
}

// Function to open a file
static int simple_fs_open(const char *path, struct fuse_file_info *fi) {
    if (strcmp(path, "/myfile") != 0)
        return -ENOENT;

    // Notify the system that the file is being opened
    system("terminal-notifier -message 'File opened' -title 'simple_fs'");

    return 0;
}

// Function to close a file
static int simple_fs_release(const char *path, struct fuse_file_info *fi) {
    if (strcmp(path, "/myfile") != 0)
        return -ENOENT;

    // Notify the system that the file is being closed
    system("terminal-notifier -message 'File closed' -title 'simple_fs'");

    return 0;
}

// Function to read from a file
static int simple_fs_read(const char *path, char *buf, size_t size, off_t offset, struct fuse_file_info *fi) {
    size_t len;
    (void) fi;

    if(strcmp(path, "/myfile") != 0)
        return -ENOENT;

    len = my_file.size;
    if (offset < len) {
        if (offset + size > len)
            size = len - offset;
        memcpy(buf, my_file.content + offset, size);
    } else
        size = 0;

    return size;
}

// Function to write to a file
static int simple_fs_write(const char *path, const char *buf, size_t size, off_t offset, struct fuse_file_info *fi) {
    (void) fi;

    if(strcmp(path, "/myfile") != 0)
        return -ENOENT;

    if (my_file.content == NULL) {
        my_file.content = malloc(size);
        memcpy(my_file.content, buf, size);
        my_file.size = size;
    } else {
        my_file.content = realloc(my_file.content, offset + size);
        memcpy(my_file.content + offset, buf, size);
        my_file.size = offset + size;
    }

    return size;
}

// File system operations structure
static struct fuse_operations simple_fs_oper = {
    .open       = simple_fs_open,
    .release    = simple_fs_release,
    .read       = simple_fs_read,
    .write      = simple_fs_write,
    .create     = simple_fs_create,
};

// Main function
int main(int argc, char *argv[]) {
    return fuse_main(argc, argv, &simple_fs_oper, NULL);
}
