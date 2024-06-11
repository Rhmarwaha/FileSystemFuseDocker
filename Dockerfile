FROM ubuntu:22.04

# Install dependencies
RUN apt-get update && \
    apt-get install -y \
    fuse3 \
    libfuse3-dev \
    libnotify-bin \
    build-essential \
    pkg-config

# Copy source files
COPY src /src

# Build the file system
WORKDIR /src
RUN make

# Set up the mountpoint
RUN mkdir /mountpoint

# Keep the container running
CMD ["tail", "-f", "/dev/null"]
