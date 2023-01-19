all:
	gcc mkdir.c -o mkdir
	gcc rm.c -o rm
	gcc cat.c -o cat
	gcc date.c -o date
	gcc main.c -o mainrun
	./mainrun
