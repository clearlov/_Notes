/* 
http://baike.baidu.com/view/93201.htm?fr=aladdin
http://www.c-sharpcorner.com/uploadfile/c210df/how-memory-is-managed-by-stack-and-heap/

Memory address = OS kernel -> text segment -> data segment -> bss segment -> heap -> <- stack
stack is from high memory address to lower, e.g. the first stack address maybe 0xffffffff （2^32 - 1 or 2^64 - 1）, and the second may be 0xffffffee

    
一个由C/C++编译的程序占用的内存分为以下几个部分
1、栈区（stack）— 由编译器自动分配释放 ，存放函数的参数名，局部变量的名等。其操作方式类似于数据结构中的栈。
2、堆区（heap）— 由程序员分配释放， 若程序员不释放，程序结束时可能由OS回收。注意它与数据结构中的堆是两回事，分配方式倒是类似于链表。
3、全局区（静态区）（static）—全局变量和静态变量的存储是放在一块的，初始化的全局变量和静态变量在一块区域， 未初始化的全局变量和未初始化的静态变量在相邻的另一块区域。程序结束后由系统释放。
4、文字常量区—常量字符串就是放在这里的，程序结束后由系统释放 。
5、程序代码区— 存放函数体的二进制代码。
    
    */
    
    
    //main.cpp
int a=0; //全局初始化区
char *p1; //全局未初始化区
class C{
private:
    int a; // heap
public:
    int b;  // heap
}
main()
{
int b; // stack, 4 bytes = 32 bits
chars[] = "abc"; // stack，运行的时候赋值，一系列stack
char *p2; // stack
char *p3 = "123456"; // 123456\0在常量区，p3在栈上。编译的时候就确定了
static int c = 0; // 全局（静态）初始化区
p1 = (char*)malloc(10);
p2 = (char*)malloc(20); //分配得来的10和20字节的区域就在堆区。
}