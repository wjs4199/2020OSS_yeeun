#include "product.h"
#include "manager.h"
#include <stdio.h>

int selectDataNo(Product* p, int curcount){
listProduct(p, curcount);
printf("번호는? (취소:0) ");
scanf("%d",&no);
return no;
}

void listProduct(Product* p, int curcount){
for(int i=0; i<curcount;i++){
	if(p[i].weight==-1){continue;}
	printf("\n%-1d",i+1);
	readProduct(&p[i]);
}
printf("\n");
}

//이름 검색 기능하는 함수
void searchName(Product*p, int curcount){
  //int scount=0; //데이터의 존재유무 가리는 변수
  //char search[20]; //사용자가 검색할 제품명
  scount=0;
  printf("검색할 제품명? ");
  scanf("%s",search);
  for(int i=0;i<curcount;i++){
    if(p[i].weight !=-1)
      if(strstr(p[i].name, search)){
        printf("%2d ",i+1);
        readProduct(&p[i]);
        scount++;
      }
  }
  if(scount==0) printf("=> 검색된 데이터 없음!");
  printf("\n");
}
//원하는 가격대의 제품을 찾아주는 함수
void searchPrice(Product*p,int curcount){
  //int scount=0;//데이터의 존재유무 가리는 변수
  //int search1, search2;//사용자가 원하는 최저가격대/ 원하는 최고가격대
  scount=0;
  printf("원하는 가격한도?( ~ ) :");
  scanf("%d~%d",&search1,&search2);
  for(int i=0;i<curcount;i++){
    if(p[i].weight !=-1)
      if(p[i].price>=search1 && p[i].price<=search2){
        printf("%2d ",i+1);
        readProduct(&p[i]);
        scount++;
      }
  }
  if(scount==0) printf("=> 검색된 데이터 없음!");
  printf("\n");  
}
//원하는 평점 이상의 제품을 찾아주는 함수
void searchStar(Product*p,int curcount){
  scount=0;//데이터의 존재유무 가리는 변수
  //int search;//사용자가 원하는 평점
  printf("원하는 평점? (0~5)");
  scanf("%d",&starnum);
  for(int i=0;i<curcount;i++){
    if(p[i].weight !=-1)
      if(p[i].star>=starnum){
        printf("%2d ",i+1);
        readProduct(&p[i]);
        scount++;
      }
  }
  if(scount==0) printf("=> 검색된 데이터 없음!");
  printf("\n");  
}

//검색 기능을 하는 함수
void searchFunction(Product*p,int curcount){
  printf("=== 검색기능 ===\n1. 제품명 검색\n2. 제품가격대 검색\n3. 제품평점 검색\n0. 취소\n");
  no= selectDataNo(p, curcount);
  if(no==1) searchName(p,curcount);
  else if(no==2) searchPrice(p, curcount);
  else if(no==3) searchStar(p, curcount);
  else if(no==0) printf("취소되었습니다!");
}

//파일 데이터 저장하는 함수
void saveData(Product* p, int curcount){
  fp= fopen("product.txt","wt");
  for(int i=0;i<curcount;i++){
    if(p[i].weight !=-1)
      fprintf(fp,"%s %d %d %d %d %d \n",p[i].name, p[i].weight,p[i].price, p[i].avg_price, p[i].star,p[i].review); 
  }
  fclose(fp);
  printf("저장됨!");
}

//파일 데이터 불러오는 함수
int loadData(Product p[]){
  i=0;j=0;k=0;
  count=0; check=0;
  fp= fopen("product.txt","rt");
  if(fp==NULL){
    printf("=> 파일없음\n");
    return 0;
  }
  while(1){
    temp=fgetc(fp);
    if(temp>='0' && temp<='9') check=1;
    if(check==1){
      if(temp==32||temp=='\n' || temp==EOF){
        p[count].name[i]='\0';
        str[j]='\0';
        store[k++]=atoi(str);
        if(temp==32){
          j=0;
        }
        if(temp=='\n'){
          p[count].weight=store[0];
          p[count].price=store[1];
          p[count].avg_price=store[2];
          p[count].star=store[3];
          p[count].review=store[4];
          check=0;j=0;i=0;k=0;
          count++;
          continue;
        }
      }
      else {
        str[j++]=temp;
      }
    }
    else {
      p[count].name[i++]=temp;
    }
    if(feof(fp)){
      p[count].weight=-1;
      break;
    }
  }
  fclose(fp);
  printf("=> 로딩 성공!\n");
  return count;
}
