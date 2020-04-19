#include "product.h"
//내용 추가하는 함수 
int creatProduct(Product *p){
 printf("제품명은? "); 
getchar(); 
scanf("%[^\n]",p->name); 
getchar(); printf("제품의 중량은? "); 
scanf("%d",&p->weight); 
printf("제품 가격은? "); 
scanf("%d",&p->price); 
printf("제품의 표준가격은? "); 
scanf("%d",&p->avg_price); 
printf("별점수는? "); 
scanf("%d",&p->star); 
printf("후기 개수는? "); 
scanf("%d",&p->review); 
printf("=>추가됨!\n"); 
return 1; 
} 
//리스트를 출력할때 한줄의 내용 
void readProduct(Product *p){ 
s="★ "; 
printf(" %s %dg \n", p->name, p->weight); 
printf("%d원\n",p->price); 
printf("(10g당 %d원)\n",p->avg_price); 
for(int i=0;i<p->star;i++) 
	printf("%s",s); 
printf("(%d개)",p->review); 
printf("\n");
}

//내용을 업데이트 하는 함수
int updateProduct(Product *p){
printf("제품명은? ");
getchar();
scanf("%[^\n]",p->name);
getchar();
printf("제품의 중량은? ");
scanf("%d",&p->weight);
printf("제품 가격은? ");
scanf("%d",&p->price);
printf("제품의 표준가격은? ");
scanf("%d",&p->avg_price);
printf("별점수는? ");
scanf("%d",&p->star);
printf("후기 개수는? ");
scanf("%d",&p->review);
printf("=> 수정됨!\n");
return 1;
}


//내용을 삭제하는 함수
int deleteProduct(Product *p){
  p->weight= -1;
  p->price= -1;
  p->avg_price= -1;
  p->star= -1;
  p->review= -1;
  printf("=> 삭제됨!\n");
  return 1;
}


