obj =$(patsubst %.c,%.o,$(wildcard *.c))
mp3_edit.exe : $(obj)
	gcc -o mp3_edit.exe $(obj)

clean:
	rm *.exe *.o
