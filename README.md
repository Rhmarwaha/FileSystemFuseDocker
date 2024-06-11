# FileSystemFuseDocker

# Simple File System Using Docker

A simple file system implemented using FUSE.

## Features
- Create (add) a file
- Open and close files with system notifications
- Read from and write to files

## Requirements
- FUSE (Filesystem in Userspace)
- Docker
- `libnotify` for notifications

## Setup

### 1. Install DockerDeskTop
### 2. Clone this Repostiory
### 3. Open Terminal In this responsitory
### 4. Create docker Image using Dockerfile ( docker build -t simple_fs . )
### 5. Start Container in interactive mode (sudo docker run --privileged --cap-add=SYS_ADMIN --device /dev/fuse -it simple_fs /bin/bash)
### 6. manually start the file system (/src/simple_fs /mountpoint)
### 7. Test the file System in another terminal
### 8. cd /mountpoint
### 9. touch myfile
### 10. echo "Hello, World!" > myfile
### 11. cat myfile
### 12. fusermount3 -u /mountpoint

