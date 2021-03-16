# makeHeaderLibraryinC
+ make header file
+ make library
    + static
        + gcc -c score.c : makes .o file
        + running : gcc score.o scoremain.c -o scoremainStatic
    + dynamic
        + ar rv libscore.a score.o : makes .a file
