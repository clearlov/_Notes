关键字inline 必须与函数定义体放在一起才能使函数成为内联，仅将inline 放在函数声明前面不起任何作用。

如下风格的函数Foo 不能成为内联函数：

inline void Foo(int x, int y); // inline 仅与函数声明放在一起

void Foo(int x, int y){}

而如下风格的函数Foo 则成为内联函数：

void Foo(int x, int y);

inline void Foo(int x, int y) // inline 与函数定义体放在一起{}

所以说，inline 是一种“用于实现的关键字”，而不是一种“用于声明的关键字”。一般地，用户可以阅读函数的声明，但是看不到函数的定义。尽管在大多数教科书中内联函数的声明、定义体前面都加了inline 关键字，但我认为inline 不应该出现在函数的声明中。这个细节虽然不会影响函数的功能，但是体现了高质量C++/C 程序设计风格的一个基本原则：声明与定义不可混为一谈，用户没有必要、也不应该知道函数是否需要内联。

定义在类声明之中的成员函数将自动地成为内联函数

例如

class A

{

    public:void Foo(int x, int y) {  } // 自动地成为内联函数

}

将成员函数的定义体放在类声明之中虽然能带来书写上的方便，但不是一种良好的编程风格，上例应该改成：

// 头文件

class A

{

    public:

    void Foo(int x, int y);

}

// 定义文件

inline void A::Foo(int x, int y){} 

慎用内联

内联能提高函数的执行效率，为什么不把所有的函数都定义成内联函数？如果所有的函数都是内联函数，还用得着“内联”这个关键字吗？内联是以代码膨胀（复制）为代价，仅仅省去了函数调用的开销，从而提高函数的执行效率。如果执行函数体内代码的时间，相比于函数调用的开销较大，那么效率的收获会很少。另一方面，每一处内联函数的调用都要复制代码，将使程序的总代码量增大，消耗更多的内存空间。

以下情况不宜使用内联：

（1）如果函数体内的代码比较长，使用内联将导致内存消耗代价较高。

（2）如果函数体内出现循环，那么执行函数体内代码的时间要比函数调用的开销大。类的构造函数和析构函数容易让人误解成使用内联更有效。要当心构造函数和析构函数可能会隐藏一些行为，如“偷偷地”执行了基类或成员对象的构造函数和析构函数。所以不要随便地将构造函数和析构函数的定义体放在类声明中。一个好的编译器将会根据函数的定义体，自动地取消不值得的内联（这进一步说明了 inline 不应该出现在函数的声明中）。


注意点:


内联函数既能够去除函数调用所带来的效率负担又能够保留一般函数的优点。然而，内联函数并不是万能药，在一些情况下，它甚至能够降低程序的性能。因此在使用的时候应该慎重。   
     1．我们先来看看内联函数给我们带来的好处：从一个用户的角度来看，内联函数看起来和普通函数一样， 它可以有参数和返回值，也可以有自己的作用域，然而它却不会引入一般函数调用所带来的负担。另外， 它可以比宏更安全更容易调试。   
    当然有一点应该意识到，inline   specifier仅仅是对编译器的建议，编译器有权利忽略这个建议。那么编译器是如何决定函数内联与否呢？一般情况下关键性因素包括函数体的大小，是否有局部对象被声明，函数的复杂性等等。   
     2．那么如果一个函数被声明为inline但是却没有被内联将会发生什么呢？理论上，当编译器拒绝内联一个   函数的时候，那个函数会像普通函数一样被对待，但是还会出现一些其他的问题。例如下面这段代码：   
  //   filename   Time.h   
  #include<ctime>   
  #include<iostream>   
  using   namespace   std;   
  class   Time   
  {   
  public:   
          inline   void   Show()  

          {   
              for (int   i   =   0;   i<10;   i++)
                  cout<<time(0)<<endl;
          }   
  };   
     因为成员函数Time::Show()包括一个局部变量和一个for循环，所以编译器一般拒绝inline，并且把它当作一个普通的成员函数。但是这个包含类声明的头文件会被单独的#include进各个独立的编译单元中：   
  //   filename   f1.cpp   
  #include   "Time.h"   
  void   f1()   
  {   
          Time   t1;   
          t1.Show();   
  }   
  //   filename   f2.cpp   
  #include   "Time.h"   
  void   f2()   
  {   
          Time   t2;   
          t2.Show();   
  }   
  结果编译器为这个程序生成了两个相同成员函数的拷贝：   
  void   f1();   
  void   f2();   
  int   main()   
  {
          f1();     
          f2();   
          return   0;   
  }
     当程序被链接的时候，linker将会面对两个相同的Time::Show()拷贝，于是函数重定义的连接错误发生。但是老一些的C++实现对付这种情况的办法是通过把一个un-inlined函数当作static来处理。因此每一份函数拷贝仅仅在自己的编译单元中可见，这样链接错误就解决了，但是在程序中却会留下多份函数拷贝。在这种情况下，程序的性能不但没有提升，反而增加了编译和链接时间以及最终可执行体的大小。但是幸运的是，新的C++标准中关于un-inlined函数的说法已经改变。一个符合标准C++实现应该只生成一份函数拷贝。然而，要想所有的编译器都支持这一点可能还需要很长时间。

  
     另外关于内联函数还有两个更令人头疼的问题。第一个问题是该如何进行维护。一个函数开始的时候可能以内联的形式出现，但是随着系统的扩展，函数体可能要求添加额外的功能，结果内联函数就变得不太可能，因此需要把inline   specifier去除以及把函数体放到一个单独的源文件中。另一个问题是当内联函数被应用在代码库的时候产生。当内联函数改变的时候，用户必须重新编译他们的代码以反映这种改变。然而对于一个非内联函数，用户仅仅需要重新链接就可以了。 

 
     这里想要说的是，内联函数并不是一个增强性能的灵丹妙药。只有当函数非常短小的时候它才能得到我们想要的效果，但是如果函数并不是很短而且在很多地方都被调用的话，那么将会使得可执行体的体积增大。最令人烦恼的还是当编译器拒绝内联的时候。在老的实现中，结果很不尽人意，虽然在新的实现中有很大的改善，但是仍然还是不那么完善的。一些编译器能够足够的聪明来指出哪些函数可以内联哪些不能，但是，大多数编译器就不那么聪明了，因此这就需要我们的经验来判断。如果内联函数不能增强行能，就避免使用它！  