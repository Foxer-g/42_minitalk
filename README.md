*This project has been created as part of the 42 curriculum by toespino*

# MINITALK

Minitalk is a project form 42's Common Core on the circle 2

This project is about coding a small data exchange program using UNIX signals.
To achieve it, it was only allowed to use **SIGUSR1** and **SIGUSR2**.
Those two signals were so used as binaries with **SIGUSR1** as 1 and **SIGUSR2** as 0.

Minitalk is a project with two programs :
 - The server
 - The client

Those two acts as input and output for data transmition

## Usage instructions

The server just need to be executed as following
![]()
and it will give it pid to be used by the client

This one is called with two inputs as following
![]()
The first one is the server's pid and the second one the data to transfer.

The data must contain only characters presents in the unicode table.

This data will be next sent and printed to by the server program which the pid is.
At the end the client will write an aknowledge message in the terminal when the server printed everything.

## Ressources

> - arch man page of sigaction : [arch man](https://man.archlinux.org/man/sigaction.2.en)
> - bit shift explained by : [5bNeumann](https://profile.intra.42.fr/users/rboutelo)

AI has been used to understand asyncronous principle in this project.
