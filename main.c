#include <stdio.h>
#include "product.h"
#include "manager.h"

//메뉴판을 보여주는 함수
int selectMenu(){
int menu;//사용자가 입력할 메뉴번호
printf("\n*** Loacker chocolate ***\n");
printf("1. 제품조회\n");
printf("2. 제품추가\n");
printf("3. 제품수정\n");
printf("4. 제품삭제\n");
printf("5. 파일저장\n");
printf("6. 추가검색\n");
printf("0. 종료\n\n");
printf("=> 원하는 메뉴는? ");
scanf("%d", &menu);
return menu;
}

int main(void){
  Product p[100];// 데이터를 저장하는 구조체변수배열
  count = 0; //읽어들일 데이터의 개수
  //반복문을 위한 변수, 사용자가 원하는 메>뉴번호
  curcount=0;
 
  count=loadData(p);
  curcount=count;
  while (1){
    menu = selectMenu();
    if (menu == 0) break;
    if (menu == 1){
#ifdef DEBUG
	printf("Debug: 확인");
#endif
	if(count>0) listProduct(p, curcount);
        else printf("데이터가 없습니다.\n");
    }
    else if (menu == 2){
#ifdef DEBUG
	printf("Debug : 확인");
#endif
        count+=creatProduct(&p[curcount++]);
    }
    else if (menu == 3){
	no=selectDataNo(p,curcount);
	if(no==0){
	printf("취소됨!\n");
	continue;
	}
        updateProduct(&p[no-1]);
    }
    else if (menu == 4){
	no=selectDataNo(p, curcount);
	if(no==0){
	printf("취소됨!\n");
	continue;
	}
	printf("정말로 삭제합니까?(삭제:1): ");
	scanf("%d",&deleteok);
	if(deleteok==1){
       	    if(deleteProduct(&p[no-1]))
		count--;
	}
    }
   else if (menu==5){
	if(count==0) printf("데이터가 없습니다!\n");
	else saveData(p,curcount);
   }
   else if(menu==6){
	searchFunction(p, curcount);
   }
  }
printf("종료됨!\n");
return 0;
}

