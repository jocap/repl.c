PREFIX = /usr/local

LDFLAGS = -lreadline -ltermcap

repl: repl.c

install: repl
	cp repl ${PREFIX}/bin/repl
	cp repl.1 ${PREFIX}/man/man1/repl.1

uninstall:
	rm ${PREFIX}/bin/repl
	rm ${PREFIX}/man/man1/repl.1
