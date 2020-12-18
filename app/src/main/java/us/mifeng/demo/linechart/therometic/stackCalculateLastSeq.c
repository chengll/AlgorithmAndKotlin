3.基于栈的后缀表达式的求值问题：

       eg：已后缀表达式为 ： AB + C D * E / -F +;

       很明显后缀表达式的求解是通过栈来实现的，规则是这样的，从左到右依次扫描表达式，
       1).如果碰到运算数直接入栈，
       2).如果碰到的是运算符，则需要将栈中的运算数出栈，注意：先出栈的为右边操作数，后出栈的为左边操作数，
       3).计算完将运算的结果压入栈中；
       4).重复上面1-3的步骤直到扫完整个表达式为止；
		下面以该后缀表达式为例，来说明 AB + C D * E / -F +;
		 1>.扫描到的为操作数 A,则直接入栈，
		 2>.同理B也直接入栈，
		 3>.扫描到 乘号（*），因为不是操作数，因此让栈中的两个操作数出栈， 由于B先出栈，所以B为右边运算数，
		 	A后出栈，A为左侧运算数，所以输出的结果为 A + B;
		 4>.将运算的结果压入栈中，(A+B)入栈，接着继续扫描，扫的是C和D，同样入栈，
		 5>.再扫描扫到的是 乘号（*） 因此需要出栈两个操作数，所以CD，出栈，D先出为 右边运算数，C后出，因此为
		 	左侧运算数，即： C * D，将C*D的结果压入栈中，此时栈中的数据为 （A+B） C*D,接着继续扫描，
		 6>.扫到操作数E,入栈，栈内数据为 （A+B） C*D E 再继续，扫到 除号（/），因此需要出栈两个操作数，因此
		 	出栈的两个数位 (（C*D）/E ),将该结果压入栈中，则栈中的表达式为 （A+B） (（C*D）/E )
		 7>.再扫描，扫到的是减号（-），因此需要出栈两个操作数 ：（（A+B）- (（C*D）/E )）连接减号，将运算结果入栈
		    ，即栈中的元素只有一个 （（A+B）- (（C*D）/E )） 继续扫描，扫到 F 直接入栈，
		 8>.继续扫描，扫到 加号（+），因此出栈两个数，即 （（A+B）- (（C*D）/E )） + F ,这时候表达式已经扫描完，