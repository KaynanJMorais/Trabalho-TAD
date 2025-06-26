all: compila

compila: main.o RegistroDeHumor.o ListaDuplamenteEnc.o
	gcc main.o RegistroDeHumor.o ListaDuplamenteEnc.o -o prog.exe
	start "" cmd /k "chcp 65001 > nul && prog.exe"

main.o: main.c
	gcc -c main.c

RegistroDeHumor.o: RegistroDeHumor.c
	gcc -c RegistroDeHumor.c

ListaDuplamenteEnc.o: ListaDuplamenteEnc.c
	gcc -c ListaDuplamenteEnc.c

clean:
	del main.o RegistroDeHumor.o ListaDuplamenteEnc.o prog.exe
