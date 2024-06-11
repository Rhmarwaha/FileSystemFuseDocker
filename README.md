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

### Install DockerDeskTop
### Clone this Repostiory
### Open Terminal In this responsitory
### Create docker Image using Dockerfile ( docker build -t simple_fs . )
### Start Container in interactive mode (sudo docker run --privileged --cap-add=SYS_ADMIN --device /dev/fuse -it simple_fs /bin/bash)
### manually start the file system (/src/simple_fs /mountpoint)
### Test the file System in another terminal
### cd /mountpoint
### touch myfile
### echo "Hello, World!" > myfile
### cat myfile
### fusermount3 -u /mountpoint

