#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//구조체 정의
typedef struct{
char name[50];//제품명
int weight;//중량
int price;//가격
int avg_price;//표준가격
int star;//평점
int review;//후기 개수
} Product;

char* s;//평점 표시
FILE* fp;

/*Prototype*/
//내용 추가하는 함수
int creatProduct(Product *p);
//리스트를 출력할때 데이터 1개의 내용
void readProduct(Product *p);
//내용을 업데이트 하는 함수
int updateProduct(Product *p);
//내용을 삭제하는 함수
int deleteProduct(Product *p);
