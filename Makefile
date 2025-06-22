OBJS := main.o
TARGETS := main
CC := gcc
CFLAGS := -O2 -Wall

# $@ means the first target in current rule, which is main
# $^ means all prerequisites in current rule, which is $(OBJS)
main: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@      

# $< means the first prerequisite in current rule, which is main.c
main.o: main.c coroutine.h
	$(CC) $(CFLAGS) $< -c -o $@

.PHONY: clean
clean:
	rm -f $(TARGETS) $(OBJS)