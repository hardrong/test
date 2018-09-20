objects = bitpicture.o main.o
edit:$(objects)
	gcc -o edit $(objects)
bitpicture.o:bitpicture.h bitpicture.c
main.0:bitpicture.h main.c
.PHONY:clean
clean:
	rm -f $(objects) edit
