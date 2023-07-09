This is the shell (main.c) that can handle 2 internal commands and 4 external comands(using fork(),execl(),wait()).

2 commands:-
->echo , echo -n typeanything 
->pwd, pwd -L

4 external comands:-
->cat
->date, date -R
->mkdir, mkdir -v typedirectoryname
->rm, rm -i

Errors handlled by the shell:-

	if above listed commands are entered incorrectly error is thrown,this includes spell error(like eco in place of echo)
	syntax error(rm -I instead of rm -i).If arguments are not entered errors are thrown. 

Test cases:-

-->	echo typeanything
	echo -n typeanything

--> 	pwd
	pwd -L

-->	cat .txtfilename

-->	date
	date -R
	
--> 	mkdir directoryname
	mkdir -v directoryname
	
-->	rm file_name
	rm -i file_name 	


Assumptions:-
	Assumed that only one arguments are being provided to the above listed commands example
	(rm a.txt and not rm a.txt b.txt).
