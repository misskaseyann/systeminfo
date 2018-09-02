#include <pwd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	/* Get user entry. */
	struct passwd *pwd_entry;
	pwd_entry = getpwuid(getuid());

	/* Get hostname. */
	char hostname[1024];
	gethostname(hostname, 1024);

	/* Print values. */
	printf("\nUser is: %s\n\n", pwd_entry->pw_name);
	printf("UID is: %d\n", pwd_entry->pw_uid);
	printf("GID is: %d\n\n", pwd_entry->pw_gid);
	printf("Host is: %s\n\n", hostname);

	/* List first five entries of pwd file. */
	for (int i=0; i<5; i++) {
		pwd_entry = getpwent();
		printf("entry %d: %s\n", i, pwd_entry->pw_name);
	}

	char input[1024];

	/* Get environment input and show output. */
	do {
		printf("\nenvironment variable desired? ");
		scanf("\n%s", input);
		if (getenv(input) != NULL) {
			printf("\nvalue is: %s\n\n", getenv(input));
			break;
		}
		printf("invalid entry! try TERM or PATH or HOME\n\n");
	} while (1);

	return 0;
}