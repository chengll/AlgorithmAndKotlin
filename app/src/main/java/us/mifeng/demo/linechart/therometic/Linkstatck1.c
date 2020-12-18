#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* 
 栈相关操作
 typedef struct Node{
     int elem;
     struct Node *next;
 }node,*LinkList;

 对于LinkList L:L是指向定义的node结构体指针，可以用->运算符来访问结构体成员，即L->elem;
 而（*L）就是Node型的结构体了，可以用点运算符访问该结构体成员，即（*L).elem;
 在链表操作中，我们通常会把链表变量作为函数的参数，这时候使用LinkList *L还是LinkList L 
 就值得考虑了
   1）如果函数会改变指针L的值，而你希望函数结束后保存L的值，那你就要用LinkList *L 
    这样向函数传递的就是指针的地址，结束调用后，自然就可以去改变指针的值；

   2） 如果函数只会修改指针所指向的内容，而不会更改指针的值，那么LinkList L就行了。
    typedef int ElemType;
    typedef struct Node{
    ElemType elem;
    struct Node * next;
    }Node, * LinkList;
    
  //1、初始化链表,函数调用完毕后,L会指向一个空的链表,即会改变指针的值,所以要用*L
    void InitList(LinkList *L)
    {
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
    }

    //清空链表L,使L重新变为空链表,函数调用完后不会改变指针L的值,只会改变指针L所指向的内容(即L->next的值)
    void ClearList(LinkList L)
    {
    LinkList p;
    while(p = L->next)
    free(p);
    }

    //销毁链表L,释放链表L申请的内存,使L的值重新变为NULL,所以会改变L的值,得用*L
     void DestroyList(LinkList *L)
     {
      LinkList p;
      while(p = (*L)->next )
       free(p);
      free(*L);
      *L = NULL;
     }
     //调用时需要注意点：如果传递的是LinkList* L在调用时要加&，如果为LinkList L直接传就可以了
     void main()
    {
      LinkList L = NULL;
     InitList(&L);
      ClearList(L);
      DestroyList(&L);
    }

 


 */


typedef struct snode{
    int data;
    struct snode * next;
}Snode,*LinkStack;

int main(int argc, char const *argv[])
{
   LinkStack *s;
   (*s)->data=1;

   LinkStack ss;
   ss->data=2;

   initLinkStack(s);
    return 0;
}
//1.初始化链栈
void initLinkStack(LinkStack *ls){
    *ls=NULL;
}

//  2 栈是否为空
int LinkStackEmpty(LinkStack *s){
    if (s==NULL){return 1;}
    {
        /* code */
    }
    
}
//3.进栈
void LinkStackPush(LinkStack *LS,char e){
    LinkStack p=(LinkStack)malloc(sizeof(Snode));
    p->data=e;
    p->next=*LS;
    *LS=p;
}
//4.出栈操作
int LinkStackPop(LinkStack *Ls){
    LinkStack *p=Ls;
    if (*Ls==NULL){return 0;}
    (*Ls)=(*Ls)->next;
    free(p);
    return 1;
}
//5.获取栈顶元素
int LinkStackGetTop(LinkStack Ls,char *e){
    LinkStack p=Ls;
    if (Ls==NULL) return -1;
    *e=Ls->data;
    return 1;
}

void matching(char str[] ){
  LinkStack Ls;
  int n=9;
  int flag;//用来判断括号是否匹配成功
  char e;//存放获取的栈顶元素
  initLinkStack(&Ls);
  for (int i = 0; i < n; i++)
  {
      //如果数组里面存放的不是[({})]时，也要让循环继续
      if (str[i]!='(' && str[i]!='[' && str[i]!='{' && str[i]!='}' && str[i]!=']' && str[i]!=')')
      continue;
      
      switch (str[i]) {
     //如果是（，{ 和[就进栈
      case '(':
      case '{':
      case '[':
         LinkStackPush(&Ls,str[i]);
          break;
      case ')':
      LinkStackGetTop(Ls,&e);
      if (Ls!=NULL)
      { if (e=')'){ //如果栈顶是）则出栈
          LinkStackPop(&Ls);
          flag=1;
        }else{
            flag=0; 
        }
      }
      break;
      case '}':
      LinkStackGetTop(Ls,&e);
      if (Ls!=NULL) {
        if (e='}'){ //如果栈顶是）则出栈
            LinkStackPop(&Ls);
            flag=1;
            }else{
                flag=0; 
            }
        }
      break;
      case ']':
       LinkStackGetTop(Ls,&e);
      if (Ls!=NULL) {
        if (e=']'){ //如果栈顶是）则出栈
            LinkStackPop(&Ls);
            flag=1;
            }else{
            flag=0; 
            }
        }
      break;
      default:
          break;
     if (flag==1 && Ls==NULL){printf("括号匹配成功");
      }else {
          printf("括号匹配不成功");
      }
  }
  
}
