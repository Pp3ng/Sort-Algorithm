CC = gcc
CFLAGS = -Wall
PROGRAMS = bubbleSort countingSort heapSort insertSort mergeSort quickSort radixSort selectionSort shellSort

.PHONY: all clean

all: $(PROGRAMS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

run: $(PROGRAMS)
	@for target in $(PROGRAMS); do \
		echo -n "$$target: "; \
		{ time -p ./$$target 2>&1; } | awk '/^real/ {printf "%s %s: %s\n", $$2, $$1, target}'; \
	done | sort -k2 -n -k2,2

clean:
	rm -f $(PROGRAMS)
