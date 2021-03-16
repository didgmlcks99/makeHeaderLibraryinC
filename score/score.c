#include <stdio.h>
#include <string.h>
#include "score.h"

int addScore(Score *s){
    printf("�̸���? ");
    scanf("%s", s->name);

    printf("�����? ");
    scanf("%d", &s->score[0]);

    printf("�����? ");
    scanf("%d", &s->score[1]);

    printf("������? ");
    scanf("%d", &s->score[2]);

    s->sum = s->score[0] + s->score[1] + s->score[2];
    s->avg = ((float)s->sum/3);
    s->flag = 1;

    printf("=> ���������� �߰� �Ͽ����ϴ�.\n");

    return 1;
}

void readScore(Score s){
    printf("%s\t%d\t%d\t%d\t%d\t%.1f\n", s.name, s.score[0], s.score[1], s.score[2], s.sum, s.avg);
}

int updateScore(Score *s){
    if(s->flag == 0){
        printf("=> �� ��ȣ�� �л� ����� �ȵǾ� �ֽ��ϴ�.\n");
        return 1;
    }else{
        printf("�̸���? ");
        scanf("%s", s->name);

        printf("�����? ");
        scanf("%d", &s->score[0]);

        printf("�����? ");
        scanf("%d", &s->score[1]);

        printf("������? ");
        scanf("%d", &s->score[2]);

        s->sum = s->score[0] + s->score[1] + s->score[2];
        s->avg = ((float)s->sum/3);
        s->flag = 1;

        printf("=> ��������!\n");
        return 1;
    }
    return 1;
}

int deleteScore(Score *s){
    if(s->flag == 0){
        printf("=> ������ �����Ͱ� �����ϴ�.\n");
        return 1;
    }else{
        s->flag = 0;
        for(int i=0; i<sizeof(s->name); i++){
            s->name[i] = ' ';
        }
        for(int i=0; i<sizeof(s->score)/sizeof(int); i++){
            s->score[i] = -1;
        }
        s->sum = -1;
        s->avg = -1.0;

        printf("=> ������!\n");
        
        return 1;
    }
    return 1;
}

int selectMenu(){
    int menu;
    printf("\n*** �������� ***\n");
    printf("1. ��ȸ\n");
    printf("2. �߰�\n");
    printf("3. ����\n");
    printf("4. ����\n");
    printf("5. ����\n");
    printf("6. �̸����� �˻�\n");
    printf("0. ����\n\n");
    printf("=> ���ϴ� �޴���? ");
    scanf("%d", &menu);
    return menu;
}

void listScore(Score *s, int index){
    printf("No\tName\tKor\tEng\tMath\tSum\tAvg\n");
    printf("===============================================================\n");
    for(int i=0; i<index; i++){
        if(s[i].flag == 0) continue;
        printf("%d\t", i+1);
        readScore(s[i]);
    }
}

int selectDataNo(Score *s, int index){
    int no;
    listScore(s, index);
    printf("\n��ȣ��(���:0) ");
    scanf("%d", &no);
    return no;
}

void saveData(Score *s, int index){
    FILE *fp;
    fp = fopen("score.txt", "wt");
    for(int i=0; i<index; i++){
        if(s[i].flag == 0) continue;
        fprintf(fp, "%s %d %d %d\n", s[i].name, s[i].score[0], s[i].score[1], s[i].score[2]);
    }
    fclose(fp);
    printf("=> �����! \n");
}

int loadData(Score *s){
    int count = 0;
    FILE *fp;
    fp = fopen("score.txt", "rt");
    if(fp == NULL){
        printf("=> ���� ����\n");
        return 0;
    }
    for(int i=0; i<100; i++){
        fscanf(fp, "%s", s[i].name);
        if(feof(fp)) break;
        fscanf(fp, "%d", &s[i].score[0]);
        fscanf(fp, "%d", &s[i].score[1]);
        fscanf(fp, "%d", &s[i].score[2]);
        s[i].flag = 1;

        s[i].sum = s[i].score[0] + s[i].score[1] + s[i].score[2];
        s[i].avg = ((float)s[i].sum/3);

        count++;
    }
    fclose(fp);
    printf("=> �ε� ����!\n");
    return count;
}

void searchName(Score *s, int index){
    int scnt = 0;
    char search[20];

    printf("�˻��� �̸�? ");
    scanf("%s", search);

    printf("No\tName\tKor\tEng\tMath\tSum\tAvg\n");
    printf("===============================================================\n");

    for(int i=0; i<index; i++){
        if(s[i].flag == 0) continue;
        if(strstr(s[i].name, search)){
            printf("%d\t", i+1);
            readScore(s[i]);
            scnt++;
        }
    }
    if(scnt == 0) printf("=> �˻��� ������ ����!\n");
}