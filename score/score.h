#include <stdio.h>

typedef struct{
    char name[20];
    int score[3];
    int sum;
    float avg;
    int flag;
} Score;

int addScore(Score *s);
void readScore(Score s);
int updateScore(Score *s);
int deleteScore(Score *s);
int selectMenu();
void listScore(Score *s, int index);
int selectDataNo(Score *s, int index);
void saveData(Score *s, int index);
int loadData(Score *s);
void searchName(Score *s, int index);