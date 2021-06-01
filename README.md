This repository is abandoned.
Please see the new repository at
http://git.ankarstrom.se/repl/.

---

`repl.c` creates a read-eval-print loop out of any command.  It is
a simple and readable C program that requires GNU readline.

In other words, it's a REPL for command-line interfaces that always
require a "prefix" command.  If you're tired of having to type `git`
everytime you want to issue a `git` command:

    $ git init
    $ git add .
    $ git status
    $ git commit
    $ git push
    $ git status

... then you can do this instead:

    $ repl git
    git > init
    git > add .
    git > status
    git > commit
    git > push
    git > status

The program automatically prefixes each command with `git`, so that
you don't have to type it.

### Installation

The following commands install `repl` in `/usr/local/bin` and
`repl.1`, its man page, in `/usr/local/man`:

    $ make
    $ make install

If you want to install it somewhere different from `/usr/local`,
edit the Makefile and modify the `PREFIX` variable.

To uninstall both binary and man page, run `make uninstall`.

***

REPL(1) - General Commands Manual

### NAME

**repl** - create a REPL out of any command

### SYNPOSIS

**repl**
*command*

### DESCRIPTION

When invoked, the
**repl**
utility puts the user in a read-eval-print loop, in which it reads
input from the user, appends it to the
*command*
provided by the single argument, and lets the shell evaluate the
full string.

Built on GNU readline, it supports history and Emacs key bindings.

**repl**
is useful for command-line interfaces built on a
"prefix command"
that has to be typed over and over preceding the actual command, like
git(1).

### EXAMPLES

	$ repl git
	git > status
	On branch master
	Your branch is up to date with 'origin/master'.
	git >

### AUTHORS

**repl**
is written by
John Ankarstr&#246;m,
available {on the web|by e-mail} at john{.|@}ankarstrom.se.

OpenBSD 6.4 - January 10, 2019
