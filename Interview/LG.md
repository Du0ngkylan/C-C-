SELF-INTRODUCATIO

----
Agenda
+ Personal infomation
+ Education background
+ Working experience
+ Reccent projects in charge
+ Plan after joining

---
Personal infomation: 
- Name:
- Date of birth:
- Address:

---
Education
+ 2010 - 2015 : Hanoi University of Science and technolory
+ Electronic and telecommunication
+ Talented Engineer class

---
Working experience
+ 3/2017 - 4/2018 : FPT software
  - software developer
  - automotive (C++, Qt)
+ 11/2015 - 11/2016:
  - internship
  - android  & java

----
Plan after joining
-Improve skill
+ programming : c/c++, Qt, Android
+ Communication
+ leadership
- Become a team leader

----

# 1, Con trỏ là gì?
 - Là một biến được dùng để lưu trữ địa chỉ của biến khác.
 - khai báo: <data_type> *<name_of_pointer>;
 
 ví dụ:</br>
 ```
  int *ptr; //declare an int pointer
  
  int value = 5;
  ptr = &value; //ptr point to value

  cout << &value << endl; //print the address of value
  cout << ptr << endl;    //print the address of value which is held in ptr

  cout << value << endl;  //print the content of value
  cout << *(&value) << endl; //print the content of value
  cout << *ptr << endl;	//print the content of value
 ```
 
# 2, Cấp phát động trong c(malloc, calloc) và c++(new)

Trong c:
+ malloc:
ptr = (castType*) malloc(size);
ví dụ: ```ptr = (int*) malloc(100 * sizeof(int));```

+ calloc:
ptr = (castType*)calloc(n, size);
ví dụ: ```ptr = (int*) calloc(100, sizeof(int));```

+ realloc: thay đổi kích thước bộ nhớ đã được cấp phát trước đó
ptr = realloc(ptr, n);

+ free:
free(ptr); // ptr là con trỏ

Trong C++
+ sử dụng toán tử new và giải phóng bộ nhớ sử dụng delete.
ví dụ:</br>
```
float *ptr = new float[num];
delete [] ptr;
```

3, khác nhau malloc and calloc?

|               malloc()	              |                  calloc()                 |
|:--------------------------------------|:------------------------------------------|
|malloc viết tắt của memory allocation	| calloc viết tắt của contiguous allocation |
|=======================================|===========================================|
|malloc nhận 1 tham số truyền vào là số byte của vùng nhớ cần cấp phát   | calloc nhận 2 tham số truyền vào là số block và kích thước mỗi block (byte)      |
|=======================================|===========================================|
| void *malloc(size_t n);               | void *calloc(size_t n, size_t size);      |
|=======================================|===========================================|
|Hàm trả về con trỏ trỏ tới vùng nhớ nếu nếu cấp phát thành công, trả về NULL nếu cấp phát fail | Hàm trả về con trỏ trỏ tới vùng nhớ được cấp phát và vùng nhớ được khởi tạo bằng giá trị 0. Trả về NULL nếu cấp phát fail  |
|=======================================|===========================================|
|Hàm malloc() nhanh hơn hàm calloc()	  | Hàm calloc() tốn thêm thời gian khởi tạo vùng nhớ. Tuy nhiên, sự khác biệt này không đáng kể. 
|=======================================|===========================================|


4, dùng hàm gì để khởi tạo giá trị các ô nhớ sau khi dùng malloc?

5, thu hồi bộ nhớ c(free), c++ (delete) ?

6, 4 tính chất hướng đối tượng c++ là gì?
- Tính trừu tượng(Abstraction)
- Tính đóng gói (Encapsulation)
- Tính kế thừa (Inheritance)
- Tính đa hình (Polymorphism )

7, cho 1 ví dụ về tính đa hình?

8, overload, override khác nhau như nào?

9, khi nào xảy ra memory leak?

10, vì sao destructor của class cha nên khai báo virtual?

11, truyền tham trỏ, tham trị, tham chiếu khác nhau như nào, khi nào dùng loại nào?

12, kích thước struct tính như nào, alignment memory là gì ?

- size của struct phải là tổng size của các thành phần bên trong nó.
- Data Structure Alignment là gì?
+ Data alignment: sắp xếp data sao cho địa chỉ của các biến luôn là số chẵn và phù hợp với hệ thống.
+ Data padding: để làm được việc alignment như ở trên chúng ta cần phải “padding” thêm một số byte vào sau biến “char c” để khi đó biến “int i” có thể ở địa chỉ chẵn.

ví dụ:
struct padding {
    char c1;
    int i1;
    char c2;
    short s1;
};
===> sizeof = 12

struct no_padding {
    int i1;
    char c1;
    char c2;
    short s1;
};
===> sizeof = 8

13, khác nhau struct và union?
- struct và union cơ bản giống nhau. Tuy nhiên, về mặt lưu trữ trong bộ nhớ, chúng có sự khác biệt rõ rệt như sau:
 =>>> chỉ khác một điều union tận dụng tối đa vùng nhớ trống để lưu trữ kiểu dữ liệu. Còn struct thì không.
 ```
typedef union Struct1{
    char a;
    char b;
    int c;
};
```
----------> sizeof = 4
```
typedef struct Struct2{
    char a;
    char b;
    int c;
};
```
---------> sizeof = 8

14, array(vector) và list khác nhau như nào?

- List là double linked list
- Vector là dynamic array, tức là array được cấp phát động bằng Allocator

Khi nào nên dùng list và khi nào nên dùng vector?

Nên mặc định sử dụng vector. Bởi vì phần lớn các trường hợp mình hay dùng là thêm phần tử vào cuối mảng và truy xuất random một phần từ nào đấy. Vector là array, việc thêm phần tử vào cuối mảng hay lấy một phần tử bất rất dễ dàng và nhanh.

Khi náo ử dụng list?

Khi ta cần thêm/xóa phần tử ở giữa mảng hoặc ở đầu mảng nhiều hơn so với việc thêm vào ở cuối. Và không có nhu cầu truy vấn random các phần tử một cách thường xuyên

Ưu và nhược của chúng là gì?

####Ưu của vector:
Thêm vào cuối mảng nhanh, truy xuất phần tử nhanh vì mỗi phần tử đều có index.

####Nhược của vector:
Chèn phần tử chậm, cần một khoảng nhớ liên tiếp để chứa mảng. Khi hết chứa đủ mảng thì cần phải allocate/move 31 một mảng mới với số phần tử gấp đôi.

####Ưu của list:
Chèn phần tử, xóa phần tử nhanh, không cần một khoảng nhớ liên tiếp để chứa các phần tử vì nó là double linked list

####Nhược của list:
Truy xuất phần tử chậm vì các phần tử không có index thực, phải duyệt danh sách phần tử cho tới khi tới được phần tử cần.

15, vì sao sau khi delete con trỏ thì nên gán giá trị nullptr cho nó?

16, multi thread và multi process khác nhau như nào?

17, khi dùng multi thread phải chú ý gì?

18, dùng hàm gì để tránh gây xung đột bộ nhớ khi dùng multi thread?

19, Pure virtual khai báo như nào, có đặc điểm gì?
- Hàm ảo thuần túy là một hàm ảo trong C ++ mà chúng ta không cần phải viết bất kỳ định nghĩa hàm nào và chỉ chúng ta phải khai báo nó. Nó được khai báo bằng cách gán 0 trong khai báo.

- Abstract class có thể có các hàm và biến thông thường cùng với một hàm thuần ảo.

- Abstract class không thể được khởi tạo, nhưng con trỏ và tham chiếu của loại lớp Trừu tượng có thể được tạo.

- Abstract class chủ yếu được sử dụng cho Upcasting, do đó các lớp dẫn xuất của nó có thể sử dụng giao diện của nó.

- Nếu Abstract class có lớp dẫn xuất, chúng phải thực hiện tất cả các hàm ảo thuần túy, nếu không chúng cũng sẽ trở thành Trừu tượng.

- Chúng ta có thể tạo đối tượng của Abstract class khi chúng tôi dành một vị trí cho một hàm thuần ảo trong Vtable, nhưng chúng ta không đặt bất kỳ địa chỉ nào, vì vậy Vtable sẽ không đầy đủ.

20, guard header file là gì,tại sao cần guard header?
- Header guard (hay còn gọi là inlcude guard) là một phương pháp cực kì đơn giản để tránh việc include header file 2 lần trong một file source.
- Hiện nay rất nhiều compiler hổ trợ #pragma once, và nó có mục đích tương tự như header guard.
- Tuy nhiên, #pragma once không phải là thành phần chính thức trong C++, không phải compiler nào cũng hổ trợ.
- Nên sử dụng header guard thay vì #pragma once

21, khi nào dùng friend class?

22, dll và lib khác nhau như nào?

23, smart pointer && overload operator?

24, Linked Lists?

25, Stack, queue, heap.

26, Đệ Quy?
