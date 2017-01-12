CC = cc
CFLAGS = -Wall

prog = a.out

objs = main.o\
       bianchi.o\
       result.o

$(prog):$(objs)
	$(CC) -o $(prog) $(objs) -lm


main.o: IEEE802_11.h define.h
bianchi.o: define.h bianchi.h
result.o: IEEE802_11.h define.h


clean:
	rm -f $(prog) $(objs)
