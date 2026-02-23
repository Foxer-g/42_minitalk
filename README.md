# MINITALK

Minitalk is a project form 42's Common Core on the circle 2

This project is about coding a small data exchange program using UNIX signals.
To achieve it, only **SIGUSR1** and **SIGUSR2** were allowed.
Those two signals were so used to express binary with **SIGUSR1** as 1 and **SIGUSR2** as 0.

Minitalk is a project with two programs :
 - The server
 - The client

Those two acts as input and output for data transmition

## Usage instructions

The server just need to be executed as follows

```sh
./server
```
output exemple :
```sh
[SYS] server pid : 3765698
```
and it will give its pid to be used by the client

This one is called with two inputs as follows

```sh
./client <server_id> <data_to_send>
```

The first one is the server's pid and the second one the data to transfer.

The data must contain only characters presents in the unicode table.

This data will be next sent and printed to by the server program which the pid is.
At the end the client will write an aknowledge message in the terminal when the server printed everything.

## Ressources

> - **Arch man page of sigaction** : [Arch man](https://man.archlinux.org/man/sigaction.2.en)
> - **Bit shift explained** by : [5BNeumann](https://github.com/5BNeumann)
> - **Gif creation made with** : [VHS by Charm team](https://github.com/charmbraclet/vhs)

AI has been used to understand asyncronous principle in this project.
