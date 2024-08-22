#include <iostream>
 
using namespace std;
 
class Line
{
   public:
      int getLength( void ) const;
      Line( int len );             // 简单的构造函数
      Line( const Line &obj);      // 拷贝构造函数
      Line( double len );          // 构造函数重载
      ~Line();                     // 析构函数
 
   private:
      int *ptr;
};
 
// 成员函数定义，包括构造函数
Line::Line(int len)
{
    cout << "调用构造函数" << endl;
    // 为指针分配内存
    ptr = new int;
    *ptr = len;
}
 
Line::Line(const Line &obj)
{
    cout << "调用拷贝构造函数并为指针 ptr 分配内存" << endl;
    ptr = new int;
    *ptr = *obj.ptr; // 拷贝值
}

Line::~Line(void)
{
    cout << "释放内存" << endl;
    delete ptr;
}
int Line::getLength( void ) const
{
    return *ptr;
}
 
// void display(Line obj)
// {
//    cout << "line 大小 : " << obj.getLength() <<endl;
// }
/*这里是值传递方式，创建临时副本时会调用拷贝构造函数*/

void display(const Line& line) { // 通过引用传递，避免拷贝
    std::cout << "Line length: " << line.getLength() << std::endl;
}

/*
在此处用引用的方式传递参数，可以避免拷贝构造函数的调用。
但加入const关键字后，就不能在display函数中修改line对象了。这里的line是常量对象了
并且，不能调用非const的成员函数，因为编译器会认为line是const的。

例子如下：
class MyClass {
public:
    int getValue() const { // 这是一个const成员函数
        // 这里不能修改任何非mutable成员变量
        return value;
    }

    void setValue(int newVal) {
        value = newVal; // 这里可以修改成员变量
    }

private:
    int value;
};

int main() {
    const MyClass myConstObject(10); // 创建一个常量对象

    // 下面的调用是合法的，因为getValue是const成员函数
    int val = myConstObject.getValue();

    // 下面的调用是不合法的，因为setValue不是const成员函数，
    // 而myConstObject是一个常量对象，其成员不能被修改
    // myConstObject.setValue(20); // 编译错误

    MyClass myNonConstObject(20); // 创建一个非常量对象

    // 这两个调用都是合法的，因为myNonConstObject不是常量对象
    val = myNonConstObject.getValue();
    myNonConstObject.setValue(30);

    return 0;
}
*/


// 程序的主函数
int main( )
{
   Line line(10);
/*
在这个例子中，display函数接收一个Line类型的对象作为参数，
但是由于它是按值传递的，所以实际上会创建一个Line对象的临时副本。
为了创建这个临时副本，编译器会调用Line类的拷贝构造函数。
因此，你会看到先调用有参构造函数来初始化line1，
然后调用拷贝构造函数来创建display函数内部使用的临时对象。
*/
   display(line);
 
   return 0;
}