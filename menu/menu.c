#include <stdio.h>
#include <string.h>
#include "menu.h"
 
int addMenu(Menu *m){
    int c;
    /* discard all characters up to and including newline */
    while ((c = getchar()) != '\n' && c != EOF); 

    printf("�޴�����? ");
    scanf("%[^\n]%*c", &m->name);

    printf("�޴�����(P/S/R)? ");
    scanf("%c", &m->type);
    
    printf("������? ");
    scanf("%d", &m->price);

    m->flag = 1;

    printf("=> ���������� �߰� �Ͽ����ϴ�.\n");

    return 1;
}

void readMenu(Menu m){
    printf("%d %c %s\n", m.price, m.type, m.name);
}

int updateMenu(Menu *m){
    if(m->flag == 0){
        printf("=> ���� �� �����Ͱ� �����ϴ�.\n");
        return 1;
    }else{
        int c;
        /* discard all characters up to and including newline */
        while ((c = getchar()) != '\n' && c != EOF); 

        printf("�� �޴�����? ");
        scanf("%[^\n]%*c", &m->name);

        printf("�� �޴�����(P/S/R)? ");
        scanf("%c", &m->type);

        printf("�� ������? ");
        scanf("%d", &m->price);

        m->flag = 1;

        printf("=> ��������!\n");
        return 1;
    }
    return 1;
}

int deleteMenu(Menu *m){
    if(m->flag == 0){
        printf("=> ������ �����Ͱ� �����ϴ�.\n");
        return 1;
    }else{
        m->flag = 0;
        for(int i=0; i<sizeof(m->name); i++){
            m->name[i] = ' ';
        }
        m->type = ' ';
        m->price = -1;

        printf("=> ������!\n");
        
        return 1;
    }
    return 1;
}

int selectMenu(){
    int menu;
    printf("\n*** PizzaYaho ***\n");
    printf("1. �޴���ȸ\n");
    printf("2. �޴��߰�\n");
    printf("3. �޴�����\n");
    printf("4. �޴�����\n");
    printf("5. �޴�����\n");
    printf("6. �޴������� �˻�\n");
    printf("0. ����\n\n");
    printf("=> ���ϴ� �޴���? ");
    scanf("%d", &menu);
    return menu;
}

void listMenu(Menu *m, int index){
    printf("**********************\n");
    for(int i=0; i<index; i++){
        if(m[i].flag == 0) continue;
        printf("%d\t", i+1);
        readMenu(m[i]);
    }
}

int selectDataNo(Menu *m, int index){
    int no;
    listMenu(m, index);
    printf("��ȣ��(���:0) ");
    scanf("%d", &no);
    return no;
}

void saveData(Menu *m, int index){
    FILE *fp;
    fp = fopen("menu.txt", "wt");
    for(int i=0; i<index; i++){
        if(m[i].flag == 0) continue;
        fprintf(fp, "%d %c %s\n",m[i].price, m[i].type, m[i].name);
    }
    fclose(fp);
    printf("=> �����! \n");
}

int loadData(Menu *m){
    int count = 0;
    FILE *fp;
    fp = fopen("menu.txt", "rt");
    if(fp == NULL){
        printf("=> ���� ����\n");
        return 0;
    }
    for(int i=0; i<100; i++){
        fscanf(fp, "%d", &m[i].price);
        if(feof(fp)) break;
        fscanf(fp, "%c", &m[i].type);
        fscanf(fp, "%[^\n]s", m[i].name);

        m[i].flag = 1;

        count++;
    }
    fclose(fp);
    printf("=> �ε� ����!\n");
    return count;
}

void searchName(Menu *m, int index){
    int scnt = 0;
    char search[20];

    printf("�˻��� �̸�? ");
    scanf("%s", search);

    printf("**********************\n");

    for(int i=0; i<index; i++){
        if(m[i].flag == 0) continue;
        if(strstr(m[i].name, search)){
            printf("%d\t", i+1);
            readMenu(m[i]);
            scnt++;
        }
    }
    if(scnt == 0) printf("=> �˻��� ������ ����!\n");
}