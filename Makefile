CC	= gcc
CFLAGS 	= -I. -g
DEPS 	= lss.h
OBJ 	= lss_bf.o lss_dp.o lss_test.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

lss_test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

