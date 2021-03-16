#include <stdio.h>
#include <string.h>
#include "score.h"

int main(void){
    Score s[100];
    int index = 0;
    for(int i=0; i<100; i++){
        s[i].flag = 0;
    }
    int count = 0, menu;

    count = loadData(s);
    index = count;
 
    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
            if(count>0){
                listScore(s, index);
            }else{
                printf("=> ��ȸ �� �����Ͱ� �����ϴ�.\n");
            }
        }else if (menu == 2){
            if(count<20){
                count += addScore(&s[index++]);
            }else{
                printf("=> 20���� �л� ������ �־� �� �߰� �� �� �����ϴ�.\n");
            }
        }else if (menu == 3){
            if(count > 0){
                int no = selectDataNo(s, index);
                if(no > 0){
                    updateScore(&s[no-1]);
                }else{
                    printf("=> ��� �Ǿ����ϴ�.\n");
                }
            }else{
                printf("=> ���� �� �����Ͱ� �����ϴ�.\n");
            }
        }else if (menu == 4){
            if(count > 0){
                int no = selectDataNo(s, index);
                if(no > 0){
                    int delok;
                    printf("������ �����Ͻðڽ��ϱ�?(1:����) ");
                    scanf("%d", &delok);
                    if(delok == 1){
                        deleteScore(&s[no-1]);
                        count--;
                    }else{
                        printf("=> ���� ��� �Ǿ����ϴ�.\n");
                    }
                }else{
                    printf("=> ��� �Ǿ����ϴ�.\n");
                }
            }else{
                printf("=> ������ �����Ͱ� �����ϴ�.\n");
            }
        }else if(menu == 5){
            saveData(s, index);
        }else if(menu == 6){
            searchName(s, index);
        }
    }
    printf("�����!\n");
    return 0;
}