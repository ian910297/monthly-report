

all:

prepare-false-sharing:
	echo "for cache misses"
	sudo sh -c " echo 0 > /proc/sys/kernel/kptr_restrict"
	echo "for perf"
	sudo sh -c " echo -1 > /proc/sys/kernel/perf_event_paranoid"

false-sharing:
	gcc false-sharing.c -pthread
	perf stat --repeat 5 -e cache-misses,cache-references ./a.out

static-build:
	gcc -static ltrace-print-hello.c

shared-library:
	gcc -fPIC -c shared-library.c
	gcc -shared shared-library.o -o libshared-library.so
	gcc ltrace-print-hello.c -L. -lshared-library
