`repl.c` creates a read-eval-print loop out of any command.  It is
a simple and readable C program that requires GNU readline.

### Installation

The following commands install `repl` in `/usr/local/bin` and
`repl.1`, its man page, in `/usr/local/man`:

    $ make
    $ make install

If you want to install it somewhere different from `/usr/local`,
edit the Makefile and modify the `PREFIX` variable.

To uninstall both binary and man page, run `make uninstall`.

### Usage

    $ repl git
    git > status
    On branch master
    Your branch is up to date with 'origin/master'.
    git > 
