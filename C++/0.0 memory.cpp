/* 
http://baike.baidu.com/view/93201.htm?fr=aladdin
http://www.c-sharpcorner.com/uploadfile/c210df/how-memory-is-managed-by-stack-and-heap/

Memory address = OS kernel -> text segment -> data segment -> bss segment -> heap -> <- stack
stack is from high memory address to lower, e.g. the first stack address maybe 0xffffffff ��2^32 - 1 or 2^64 - 1��, and the second may be 0xffffffee

    
һ����C/C++����ĳ���ռ�õ��ڴ��Ϊ���¼�������
1��ջ����stack���� �ɱ������Զ������ͷ� ����ź����Ĳ��������ֲ����������ȡ��������ʽ���������ݽṹ�е�ջ��
2��������heap���� �ɳ���Ա�����ͷţ� ������Ա���ͷţ��������ʱ������OS���ա�ע���������ݽṹ�еĶ��������£����䷽ʽ��������������
3��ȫ��������̬������static����ȫ�ֱ����;�̬�����Ĵ洢�Ƿ���һ��ģ���ʼ����ȫ�ֱ����;�̬������һ������ δ��ʼ����ȫ�ֱ�����δ��ʼ���ľ�̬���������ڵ���һ�����򡣳����������ϵͳ�ͷš�
4�����ֳ������������ַ������Ƿ�������ģ������������ϵͳ�ͷ� ��
5������������� ��ź�����Ķ����ƴ��롣
    
    */
    
    
    //main.cpp
int a=0; //ȫ�ֳ�ʼ����
char *p1; //ȫ��δ��ʼ����
class C{
private:
    int a; // heap
public:
    int b;  // heap
}
main()
{
int b; // stack, 4 bytes = 32 bits
chars[] = "abc"; // stack�����е�ʱ��ֵ��һϵ��stack
char *p2; // stack
char *p3 = "123456"; // 123456\0�ڳ�������p3��ջ�ϡ������ʱ���ȷ����
static int c = 0; // ȫ�֣���̬����ʼ����
p1 = (char*)malloc(10);
p2 = (char*)malloc(20); //���������10��20�ֽڵ�������ڶ�����
}