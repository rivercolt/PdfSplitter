//handle flags
#include <stdlib.h>
#include <getopt.h>
#include <stdio.h>
#include <sched.h>

struct pdfFlags {
	int start;
	int split;
	char *path;
};

struct pdfFlags handleFlags(int argc, char *argv[]) {
	int opt;
	int flag_f = 0;
	//default values
	struct pdfFlags defArgs = {
		.start = 1, //start on page 1
		.split = 2, //split into 2 windows 
		.path = NULL 
	};
    
    while ((opt = getopt (argc, argv, ":hf:p:s:")) != -1)
    {
        switch (opt){
            case 'h':
                printf("Usage: splitter [options]\n");
                printf("Options:\n");
                printf("  -f <file>   Specify a filename\n");
                printf("  -h          Show this help message\n");
                printf("  -p <num>    Specify page number to start on\n");
                printf("  -s          How many tabs to split into\n");
                exit(0);

            case 'f':
                defArgs.path = optarg;
                flag_f = 1;
                printf("filename: %s\n", optarg);
                break;
            case 'p':
                defArgs.start = atoi(optarg);
                printf("index %d\n", defArgs.start);
                break;
            case 's':
                defArgs.split = atoi(optarg);
                printf("split into %s\n", optarg);
                break;

            case ':':
                   printf("no value");
                   break;
            case '?':
                   printf("unknown option: %c\n", optopt);
                   break;
        }

    }

    if (!flag_f) {
        fprintf(stderr, "Error: -f is required.\n");
        fprintf(stderr, "Run with -h for help.\n");
        exit(1);
    }
    
    for(; optind < argc; optind++){     
        printf("extra arguments: %s\n", argv[optind]); 
    }

    
    return defArgs;

}
