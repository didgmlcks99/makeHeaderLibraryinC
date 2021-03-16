# makeHeaderLibraryinC
+ make header file
+ make library
    + static
        + gcc -c score.c : makes .o file
        + running file : gcc score.o scoremain.c -o scoremainStatic
    + dynamic
        + ar rv libscore.a score.o : makes .a file
        + running file : gcc scoremain.c -o scoremain -I./ -L / -lscore
