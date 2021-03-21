typedef struct{
    char name[20];
    char type;
    int price;
    int flag;
} Menu;
 
int addMenu(Menu *m);
void readMenu(Menu m);
int updateMenu(Menu *m);
int deleteMenu(Menu *m);
int selectMenu();
void listMenu(Menu *m, int index);
int selectDataNo(Menu *m, int index);
void saveData(Menu *m, int index);
int loadData(Menu *m);
void searchName(Menu *m, int index);