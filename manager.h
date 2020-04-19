#include <stdio.h>

int count;
int menu;
int curcount;// 현재가진 데이터의 개수
int i;

//menu==3에서 필요 (리스트 수정시 selectDatano를 받는 변수)
int no;

//menu==4에서 필요(데이타 삭제할 떄)
int deleteok;

//search 함수들
int scount;
char search[20];
int search1, search2;
int starnum;

//loaddata함수
int i, j, k;//반복문 위한 변수
int count;//p의 index번호
int check;//check=0이면 name에 제품명 저장, 1이면 숫자를 저장하기 시작
char temp;//파일에서 문자를 하나씩 읽어서 임시저장
char str[10];//제품명 이후 나오는 문자들을 빈칸직전까지 문자열로 저장
int store[5];//빈칸을 기준으로 atoi(str)한 값을 순차적으로 저장


/*prototype*/
int selectDataNo(Product* p, int curcount);
void listProduct(Product*p, int curcount);
void saveData(Product* p, int curcount);
int loadData(Product* p);
void searchName(Product* p, int curcount);
void searchPrice (Product* p, int curcount);
void searchStar(Product* p, int curcount);
void searchFunction(Product* p, int curcount);
