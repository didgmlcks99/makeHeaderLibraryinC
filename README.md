# makeHeaderLibraryinC
+ make header file
+ make library
    + static
        + gcc -c score.c : .o file ����
        + gcc score.o scoremain.c -o scoremainStatic : object�� �̿��� ���� ���� ����
        + ar rv libscore.a score.o : .a file ����
        + gcc scoremain.c -o scoremain -I./ -L./  : library.a�� �̿��� ���� ���� ����
        + gcc scoremain.c -o scoremain : scoremain���� ���� ����
            + -I./  : ���� �������� ��� ���� ã�� �ɼ�
            + -L./  : ���� �������� ���̺귯�� ���� ã�� �ɼ�
            + -lscore : ���̺귯���� ��ũ
