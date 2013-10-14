CFLAGS =  -fPIC -shared -g -Wall
CC = gcc

TARGET = hackint.so
OBJS = hackint.o

INCLUDE = -I/data/Python-2.7.5 \
          -I/data/Python-2.7.5/Include


all: $(TARGET)

$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJS):%.o:%.c %.h
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	-rm $(TARGET) $(OBJS)
