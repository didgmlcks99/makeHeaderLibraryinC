#include <stdio.h>
#include <string.h>
#include "menu.h"

int main(void){
    Menu m[100];
    int index = 0;
    for(int i=0; i<100; i++){
        m[i].flag = 0;
    }
    int count = 0, menu;

    count = loadData(m);
    index = count;
 
    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
            if(count>0){
                listMenu(m, index);
            }else{
                printf("=> ��ȸ �� �����Ͱ� �����ϴ�.\n");
            }
        }
        else if (menu == 2){
            if(count<20){
                count += addMenu(&m[index++]);
            }else{
                printf("=> 20���� �޴� ������ �־� �� �߰� �� �� �����ϴ�.\n");
            }
        }
        else if (menu == 3){
            if(count > 0){
                int no = selectDataNo(m, index);
                if(no > 0){
                    updateMenu(&m[no-1]);
                }else{
                    printf("=> ��� �Ǿ����ϴ�.\n");
                }
            }else{
                printf("=> ���� �� �����Ͱ� �����ϴ�.\n");
            }
        }
        else if (menu == 4){
            if(count > 0){
                int no = selectDataNo(m, index);
                if(no > 0){
                    int delok;
                    printf("������ �����Ͻðڽ��ϱ�?(1:����) ");
                    scanf("%d", &delok);
                    if(delok == 1){
                        deleteMenu(&m[no-1]);
                        count--;
                    }else{
                        printf("=> ���� ��� �Ǿ����ϴ�.\n");
                    }
                }else{
                    printf("=> ��� �Ǿ����ϴ�\n");
                }
            }else{
                printf("������ �����Ͱ� �����ϴ�.\n");
            }
        }else if(menu == 5){
            saveData(m, index);
        }else if(menu == 6){
            searchName(m, index);
        }
    }
    printf("�����!\n");
    return 0;
}