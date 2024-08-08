# Centipede Monitor
## Overview

Centipede Monitor is a multiple computer process monitor that allows you to monitor processes across different machines. The project consists of a server and a client that work together to provide real-time monitoring.

## Prerequisites

clone the repository

    git clone https://github.com/jero98772/centipede-monitor

Before you begin, ensure that you have `make` installed on your system. You can install it using your package manager. For instance, on Ubuntu, you can install it with:

```sh
sudo apt-get install make
```

## Compiling the Project

To compile the server and client, navigate to the project directory and run:

```sh
make
```

This command will compile both the server and the client programs.

## Running the Server

Start the server with the following command:

```sh
make run-servidor
```

The server will launch on the specified port and will be ready to accept incoming client connections.

## Running the Client

To start the client and connect it to the server, use:

```sh
make run-cliente
```

The client will initiate a connection to the server and begin monitoring the processes.

## Cleaning Up

If you want to clean up the project by removing the compiled server and client executables, you can run:

```sh
make clean
```

This will delete the compiled binaries from your directory.

## License

This project is licensed under the GPLv3 License. For more details, see the [LICENSE](LICENSE) file.

## Author

Jero98772 - [jero98772@protonmail.com](mailto:jero98772@protonmail.com)
