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
                printf("=> 조회 할 데이터가 없습니다.\n");
            }
        }else if (menu == 2){
            if(count<20){
                count += addScore(&s[index++]);
            }else{
                printf("=> 20명의 학생 제한이 있어 더 추가 할 수 없스니다.\n");
            }
        }else if (menu == 3){
            if(count > 0){
                int no = selectDataNo(s, index);
                if(no > 0){
                    updateScore(&s[no-1]);
                }else{
                    printf("=> 취소 되었습니다.\n");
                }
            }else{
                printf("=> 수정 할 데이터가 없습니다.\n");
            }
        }else if (menu == 4){
            if(count > 0){
                int no = selectDataNo(s, index);
                if(no > 0){
                    int delok;
                    printf("정말로 삭제하시겠습니까?(1:삭제) ");
                    scanf("%d", &delok);
                    if(delok == 1){
                        deleteScore(&s[no-1]);
                        count--;
                    }else{
                        printf("=> 삭제 취소 되었습니다.\n");
                    }
                }else{
                    printf("=> 취소 되었습니다.\n");
                }
            }else{
                printf("=> 삭제할 데이터가 없습니다.\n");
            }
        }else if(menu == 5){
            saveData(s, index);
        }else if(menu == 6){
            searchName(s, index);
        }
    }
    printf("종료됨!\n");
    return 0;
}