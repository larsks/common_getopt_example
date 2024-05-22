SRCS = \
	common_opts.c \
	main.c

DEPS = $(SRCS:.c=.d)
OBJS = $(SRCS:.c=.o)

%.d: %.c
	$(CC) -MM -o $@ $<

all: argtest

argtest: $(OBJS)
	$(CC) -o $@ $(OBJS)

clean:
	rm -f $(DEPS) $(OBJS) argtest

include $(DEPS)
