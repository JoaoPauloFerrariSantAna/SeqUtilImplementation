#include <stdio.h>
#include <stdlib.h>

#define PROGRAM_NAME "myseq"
#define DEFAULT_STEP 1

void print_usage() {
	fprintf(stderr, "Usage: ./%s:\n", PROGRAM_NAME);
	fprintf(stderr, "\t-./%s [ENDNUMBER] [STARTNUMBER]\n", PROGRAM_NAME);
	fprintf(stderr, "\t-./%s [ENDNUMBER]\n", PROGRAM_NAME);
	fprintf(stderr, "\t-./%s [ENDNUMBER] [STARTNUMBER] [STEP]\n", PROGRAM_NAME);
}

void set_step(int* step, int received_step, int start_number, int end_number) {
	if(received_step == 0) {
		received_step = DEFAULT_STEP;
	} else if(start_number > end_number) {
		/* set the value negative */
		received_step = received_step * (-1);
	} else {
		/* if we can increment normally and we are providing a step */
		/* then just set it let it be the normal value */
		received_step = received_step;
	}

	*step = received_step;
}

void inc_step(int start_number, int end_number, int step) {
	do {
		printf("%d ", start_number);
		start_number = start_number + step;
	} while(start_number <= end_number);
}

void dec_step(int start_number, int end_number, int step) {
	do {
		printf("%d ", start_number);
		start_number = start_number + step;
	} while(end_number <= start_number);
}

int main(int argc, char *argv[]) {
	int end_number = 0;
	int start_number = 1;
	int step = 0;

	/* no arguments were passed: output file is already one arg */
	if(argc == 1) {
		print_usage();
		return 1;
	}

	/**
	* from this point on, we will have a bunch of strings in argv
	* so... now we can make scripting...
	*/

	/* this is pretty much the only thing that we have guaranteed */
	end_number = atoi(argv[1]);

	if(argv[2] != NULL) start_number = atoi(argv[2]);

	set_step(&step, atoi(argv[3]), start_number, end_number);

	if(start_number < end_number) inc_step(start_number, end_number, step);
	else dec_step(start_number, end_number, step);

	printf("\n");

	return 0;
}
