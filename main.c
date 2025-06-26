#include <stdio.h>
#include <stdlib.h>

/* code obtained from code review */
/* link: https://www.tabnews.com.br/JohnVantas/code-review-c-procuro-pessoas-para-fazer-uma-review-de-uma-implementacao-do-utilitario-do-unix-seq */

void print_usage(const char *pname) {
	printf("Usage: %s:\n", pname);
	printf("       %s [ENDNUMBER].\n", pname);
	printf("       %s [STARTNUMBER] [ENDNUMBER].\n", pname);
	printf("       %s [STARTNUMBER] [STEP] [ENDNUMBER].\n", pname);
	exit(1);
}

void set_sequence(int argc, char *argv[], int *start_number, int *end_number, int *step) {
	switch(argc) {
		case 2:
			*end_number = atoi(argv[1]);
		break;
		case 3:
			*start_number = atoi(argv[1]);
			*end_number = atoi(argv[2]);
		break;
		case 4:
			*start_number = atoi(argv[1]);
			*step = atoi(argv[2]);
			*end_number = atoi(argv[3]);
		break;
		default:
			print_usage(argv[0]);
		break;
	}
}

int main(int argc, char *argv[]) {
	int step = 1;
	int start_number = 1;
	int end_number = 0;

	set_sequence(argc, argv, &start_number, &end_number, &step);

	while((step > 0 ? start_number <= end_number : start_number >= end_number)) {
		printf("%d\n", start_number);
		start_number += step;
	}

	return 0;
}
