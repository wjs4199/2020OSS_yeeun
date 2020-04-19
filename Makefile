CC=gcc
TARGET=shop
CFLAGS =-W -Wall
DTARGET =shop_debug
OBJECTS =main.c product.o manager.o


$(TARGET) : $(OBJECTS)
	$(CC) $(CRLAGS) -o $@ $^

$(DTARGET): $(OBJECTS)
	$(CC) $(CRLAGS) -DDEBUG -o $@ $^ 


clean : 
	rm *.o $(TARGET) $(DTARGET)
