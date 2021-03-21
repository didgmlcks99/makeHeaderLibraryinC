# makeHeaderLibraryinC
+ make header file
+ make library
    + static
        + gcc -c score.c : .o file 생성
        + gcc score.o scoremain.c -o scoremainStatic : object을 이용해 실행 파일 생성
        + ar rv libscore.a score.o : .a file 생성
        + gcc scoremain.c -o scoremain -I./ -L./  : library.a를 이용해 실행 파일 생성
        + gcc scoremain.c -o scoremain : scoremain실행 파일 생성
            + -I./  : 현재 폴더에서 헤더 파일 찾기 옵션
            + -L./  : 현재 폴더에서 라이브러리 파일 찾기 옵션
            + -lscore : 라이브러리와 링크
