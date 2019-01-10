#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>
#include <err.h>
#include <readline/readline.h>
#include <readline/history.h>

void handle_int(int sig) { /* handle ctrl-c */
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
	if (prompt == NULL) err(1, NULL);
	snprintf(prompt, size, "%s > ", argv[1]);

	struct sigaction act;
	act.sa_handler = handle_int;
	sigaction(SIGINT, &act, NULL);

	rl_clear_signals(); /* tell readline to ignore signals */

	while (true) {
		char *input = readline(prompt);

		if (input == NULL) { /* ctrl-d */
			printf("\n");
			break;
		}
		
		add_history(input);

		int size = strlen(argv[1]) + 1 + strlen(input) + 1;
		char *command = malloc(size);
		if (command == NULL) err(1, NULL);
		snprintf(command, size, "%s %s", argv[1], input);

		system(command);

		free(input);
		free(command);
	}

	free(prompt);

	return 0;
}
