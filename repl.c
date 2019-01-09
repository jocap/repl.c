#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>
#include <errno.h>
#include <readline/readline.h>
#include <readline/history.h>

void handle_int(int sig) {
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay(); /* thanks James Taylor on Stack Overflow */
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "usage: %s command\n", argv[0]);
		return 1;
	}

	int size = strlen(argv[1]) + 3 + 1;
	char *prompt = malloc(size);
	snprintf(prompt, size, "%s > ", argv[1]);

	struct sigaction act;
	act.sa_handler = handle_int;
	sigaction(SIGINT, &act, NULL);

	rl_clear_signals();

	while (true) {
	    char *input = readline(prompt);

		if (input == NULL) { /* ctrl-d */
			printf("\n");
			break;
		}

		int size = strlen(argv[1]) + 1 + strlen(input) + 1;
		char *command = malloc(size);
		snprintf(command, size, "%s %s", argv[1], input);

		system(command);

	    free(input);
	}
    return 0;
}
