STATIC = programs
DYNAMIC = programd

CFLAGS = -std=c11 -Wall -Werror -Wpedantic -MP -MMD
SRCS = main.c calc.c print.c models.c
LIBS = -lcrypto

all:  $(STATIC) $(DYNAMIC)

$(STATIC): $(SRCS:%.c=%.o)
	$(CC) -o $@ $(SRCS:%.c=%.o) -Wl,-Bstatic -lcrypto -Wl,-Bdynamic


$(DYNAMIC): $(SRCS:%.c=%.o)
	$(CC) -o $@ $(SRCS:%.c=%.o) -lcrypto

.PHONY: clean all

clean:
	rm -f *.o $(STATIC) $(DYNAMIC) *.d

-include $(SRCS:%.c=%.d)
