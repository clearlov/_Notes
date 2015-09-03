#  AS (Assembler Language)

###################################  1_begin.s  #################################################
.section .data

# start
.section .text

.globl _start

_start:

# Register  // first char: r is for 64-bit, e.g. rax;   eax is for 32-bit;   ax is for 16-bit
#   General Register
#     %rax
#     %rbx
#     %rcx
#     %rdx
#     %rdi  // 64-bit index register, range from [0,]
#     %rsi
#   Special Register
#     %rbp
#     %rsp
#     %rip
#     %rflags  

# movl source destination
#   寻址方式
#     立即寻址  $VALUE, REGISTER   // movl $1, %eax==>*(%eax) = 1
#     寄存器寻址
#     直接寻址  ADDR, REGISTER  // movl 1, %eax==>%eax = 1
#                                 movl %eax, %ebx    ==> %ebx = %eax
#     变址寻址
#     间接寻址  (REGISTER_A) REGISTER_B // movl (%eax) %ebx    ===> *(%ebx) = *%eax
#     基址寻址  LEN(ADDR_START), REGISTER // movl 4(%eax), %ebx ==> %ebx = (void *)%eax + 4
#     索引寻址  ADDR_START(,INDEX_REGISTER, LENGTH) 
#              // movl ADDR_START(, %edi, 4), %eax  ==> %eax = (int *)ADDR_START + %edi
movl $1, %eax      # move 1 to register %eax

movl $0, %ebx

# int $hex_interrupt_number            // interrupt
int $0x80
##########################################################################################

# sh$ as 1_begin.s -o 1.o
# sh$ ld 1.o -o 1
# sh$ ./1
# sh$ echo $? // get the error code of program in Linux 