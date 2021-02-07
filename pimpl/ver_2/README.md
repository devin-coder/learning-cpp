# learning-cpp
指向实现的指针 Pimpl  
这项技术是你可以把类的数据成员替换成一个指向实现类（结构）的指针，把原来在主类中的数据成员放置到实现类中，然后通过指针间接的访问这些数据。  

 一个已声明但未定义的类型被称作不完整类型。Widget::Impl 就是这样的类型。对一个不完整类型你可以做的事情很少，但是声明一个指向它的指针就是其中之一可做的事情。Pimpl技巧就利用这点。  

  Pimpl技巧的第一部分是声明一个指向不完整类型的指针的数据成员，第二部分是动态分配（放到堆上）和析构该对象（对象里保存了在原始类里的数据成员）。分配和析构的代码放在实现文件里。  
  假如我们需要的是在Widget构造函数里动态的分配一个Widget::Impl 对象，同时析构时自动释放对象，那么std::unique_ptr（见条款18）恰恰就是一个我们需要的工具！    
  用std::unique_ptr代替原始的指向Impl的指针，这个默认删除器会去删除std::unique_ptr内部的原始指针，然而在删除前，c++11中典型的实现会使用static_assert去确保原始指针没有指向不完整类型。   
   当编译器为Widget w的析构函数产生代码时，会遇到一个static_assert失败，于是就导致了错误发生。  
   为了修复这个问题，你只需要保证在生成析构std::unique<Widget::Impl>代码的地方，Widget::Impl是个完整类型。当类型的定义可以被看到时类型就是完整的。而Widget::Impl是定义在Widget.cpp文件中的。成功编译的关键是让编译器在widget.cpp中Widget::Impl定义之后看到Widget的析构函数的函数体。  
   正如条款17解释的，在Widget里声明了析构函数会阻止编译器产生move操作代码，因此，假如你需要支持move操作，你必须自己声明该函数。既然编译器产生的版本是正确的，
c++ learning
https://mp.weixin.qq.com/s?__biz=MzA3MTU1MzMzNQ==&mid=2247489368&idx=1&sn=565d09ae7fc6aa961845954bfb6512f3&scene=58&subscene=0&exportkey=A7DjNSU%2Fy0Ww%2BpGRo8i14jo%3D&pass_ticket=oXbmqP%2FndIU4BWijz4vjQhyNnRJnoLDnD7GHBRwpnDgVh5%2B727KRfsHwzLXz4XiV&wx_header=0

https://blog.csdn.net/qfturauyls/article/details/107621076?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromBaidu-5.control&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromBaidu-5.control
