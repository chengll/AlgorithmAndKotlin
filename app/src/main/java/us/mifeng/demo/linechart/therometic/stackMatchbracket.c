/*通过栈来实现括号匹配算法
  算法的核心思想是：在一个表达式中，依次扫描一个表达式，如果碰到（ ，{，【 左括号时入栈
  当遇到右圆括号，），}和】时出栈，然后通过topElem来存放栈顶元素，如果当前出栈是的符号str[i]=）,
  topElem='（" ||str[i]=‘】’ && topElem='【' ||  str[i]=‘}’ && topElem='{'这种情况时，则
  为匹配，最终是否匹配要看栈是否为空，如果为空则是匹配成功，如果栈不为空，则为不匹配
*/
//1.定义栈
#define MaxSize 100
typedef struct{
	char data[MaxSize];
	int top;
}SqStack;

//2.初始化栈
void initStack(SqStack &s);

//3.入栈操作
bool push(SqStack &s,char x);

//4.栈顶元素出栈，用x返回
bool pop(SqStack &s,char &x)

//5.判断栈是否为空的
bool StackEmpty(SqStack s);

//6.核心算法
bool bracketCheck(char str[],int length){
	SqStack s;
	initStack(s);
	for (int i = 0; i < length; ++i)
	{

		if (str[i]=='(' || str[i]=='[' || str[i]=='{')
		{
			push(s,str[i]); //入栈
		}else {
			if (initStack)

				return false; //栈空
			char topElem;
			pop(s,topElem);
			if (str[i]==')' && topElem!='(')
			{
				return false;
			}else if (str[i]==']' && topElem!='[')
			{
				return false;
			}else if (str[i]=='}' && topElem!='{')
			{
				return false;
			}
		}
	}
	return StackEmpty(s);//如果到最后，栈空则为匹配成功，不然则匹配失败
}

