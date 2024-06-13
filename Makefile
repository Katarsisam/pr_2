CC = g++
CFLAGS = -c -Wall -Werror -Wextra 

CF_CHECK = clang-format  -n
CF_APPLY = clang-format  -i
RM = rm -rf 


all :  ConsolePRall

format : 
	$(CF_CHECK) *.c
	$(CF_CHECK) *.h
	$(CF_APPLY) *.c
	$(CF_APPLY) *.h
	
ConsolePRall : ConsolePR.o lib.o ConsolePR4.o ConsolePR2.o ConsolePR5.o
	$(CC) ConsolePR.o lib.o -o ConsolePR
	$(CC) ConsolePR4.o lib.o -o ConsolePR4
	$(CC) ConsolePR2.o -o ConsolePR2
	$(CC) ConsolePR5.o -o ConsolePR5

ConsolePR.o : ConsolePR.cpp
	$(CC) $(CFLAGS) ConsolePR.cpp -o ConsolePR.o

ConsolePR4.o : ConsolePR4.cpp
	$(CC) $(CFLAGS) ConsolePR4.cpp -o ConsolePR4.o

ConsolePR2.o : ConsolePR2_3.cpp
	$(CC) $(CFLAGS) ConsolePR2_3.cpp -o ConsolePR2.o

ConsolePR5.o : ConsolePR5.cpp
	$(CC) $(CFLAGS) ConsolePR5.cpp -o ConsolePR5.o

lib.o : lib.cpp
	$(CC) $(CFLAGS) lib.cpp -o lib.o
clean :
	$(RM) *.o *.a *.so

rebuild : clean ConsolePRall
