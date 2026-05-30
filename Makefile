CC = gcc
CFLAGS = -Wall -Wextra -std=c11
LIBS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lm

TARGETS = fractaltree tree_angle20 tree_angle45 tree_colors \
          tree_depth5 tree_depth9 tree_factor06 tree_factor08

all: $(TARGETS)

%: %.c turtlec.c turtlec.h
	$(CC) $(CFLAGS) $< turtlec.c -o $@ $(LIBS)

run:
	./$(FILE)

clean:
	rm -f $(TARGETS)
