C++ - Mo dule 02
Ad-ho c p olymorphism, op erator overloading
and Ortho dox Canonical class form
Summary:
This document contains the exercises of Module 02 from C++ modules.
Version: 8


Contents
I Intro duction
 2
I I General rules
 3
I I I New rules
 5
IV Exercise 00: My First Class in Ortho dox Canonical Form
 6
V Exercise 01: Towards a more useful ˝xed-p oint numb er class
 8
VI Exercise 02: Now we're talking
 10
VI I Exercise 03: BSP
 12
VI I I Submission and p eer-evaluation
 14
1


Chapter I
Intro duction
C++ is a general-purpose programming language created by Bjarne Stroustrup as an ex-
tension of the C programming language, or "C with Classes" (source:
 Wikipedia
).
The goal of these mo dules is to intro duce you to
Ob ject-Oriented Programming
.
This will b e the starting p oint of your C++ journey. Many languages are recommended
to learn OOP. We decided to cho ose C++ since it's derived from your old friend C.
Because this is a complex language, and in order to keep things simple, your co de will
comply with the C++98 standard.
We are aware mo dern C++ is way di˙erent in a lot of asp ects. So if you want to
b ecome a pro˝cient C++ develop er, it's up to you to go further after the 42 Common
Core!
2


Chapter I I
General rules
Compiling

Compile your co de with
c++
and the ˛ags
-Wall -Wextra -Werror

Your co de should still compile if you add the ˛ag
-std=c++98
Formatting and naming conventions

The exercise directories will b e named this way:
ex00, ex01, ... , exn

Name your ˝les, classes, functions, memb er functions and attributes as required in
the guidelines.

Write class names in
Upp erCamelCase
format. Files containing clas s co de will
always b e named according to the class name. For instance:
ClassName.hpp
/
ClassName.h
,
ClassName.cpp
, or
ClassName.tpp
. Then, if you
have a header ˝le containing the de˝nition of a class "BrickWall" standing for a
brick wall, its name will b e
BrickWall.hpp
.

Unless sp eci˝ed otherwise, every output messages must b e ended by a new-line
character and displayed to the standard output.

Goodbye Norminette!
No co ding style is enforced in the C++ mo dules. You can
follow your favorite one. But keep in mind that a co de your p eer-evaluators can't
understand is a co de they can't grade. Do your b est to write a clean and readable
co de.
Allowe d/Forbidden
You are not co ding in C anymore. Time to C++! Therefore:

You are allowed to use almost everything from the standard library. Thus, instead
of sticking to what you already know, it would b e smart to use as much as p ossible
the C++-ish versions of the C functions you are used to.

However, you can't use any other external library. It means C++11 (and derived
forms) and
Boost
libraries are forbidden. The following functions are forbidden
to o:
*printf()
,
*alloc()
and
free()
. If you use them, your grade will b e 0 and
that's it.
3


C++ - Mo dule 02
Ad-ho c p olymorphism, op erator overloading
and Ortho dox Canonical class form

Note that unless explicitly stated otherwise, the
using namespace <ns_name>
and
friend
keywords are forbidden. Otherwise, your grade will b e -42.

You are allowed to use the STL in the Mo dule 08 and 09 only.
That means:
no
Containers
(vector/list/map/and so forth) and no
Algorithms
(anything that
requires to include the
<algorithm>
header) until then. Otherwise, your grade will
b e -42.
A few design requirements

Memory leakage o ccurs in C++ to o. When you allo cate memory (by using the
new
keyword), you must avoid
memory leaks
.

From Mo dule 02 to Mo dule 09, your classes must b e designed in the
Ortho dox
Canonical Form, except when explicitely stated othe rwise
.

Any function implementation put in a header ˝le (except for function templates)
means 0 to the exercise.

You should b e able to use each of your headers indep endently from others. Thus,
they must include all the dep endencies they need. However, you must avoid the
problem of double inclusion by adding
include guards
. Otherwise, your grade will
b e 0.
Read me

You can add some additional ˝les if you need to (i.e., to split your co de). As these
assignments are not veri˝ed by a program, feel free to do so as long as you turn in
the mandatory ˝les.

Sometimes, the guidelines of an exercise lo ok short but the examples can show
requirements that are not explicitly written in the instructions.

Read each mo dule completely b efore starting! Really, do it.

By Odin, by Thor! Use your brain!!!
You will have to implement a lot of classes. This can seem tedious,
unless you're able to script your favorite text editor.
You are given a certain amount of freedom to complete the exercises.
However, follow the mandatory rules and don't be lazy. You would
miss a lot of useful information! Do not hesitate to read about
theoretical concepts.
4


Chapter I I I
New rules
From now on, all your classes must b e designed in the
Ortho dox Canonical Form
,
unless explicitely stated otherwise. Then, they will implement the four required memb er
functions b elow:

Default constructor

Copy constructor

Copy assignment op erator

Destructor
Split your class co de into two ˝les. The header ˝le (.hpp/.h) contains the class
de˝nition whereas the source ˝le (.cpp) contains the implementation.
5


Chapter IV
Exercise 00: My First Class in
Ortho dox Canonical Form
Exercise : 00
My First Class in Ortho dox Canonical Form
Turn-in directory :
ex
00
=
Files to turn in :
Makefile, main.cpp, Fixed.{h, hpp}, Fixed.cpp
Forbidden functions :
None
You think you know integers and ˛oating-p oint numb ers. How cute.
Please read this 3 pages article (
1
,
 2
,
 3
) to discover that you don't. Go on, read it.
Until to day, every numb er you used in your co de was basically either an integer or a
˛oating-p oint numb er, or any of their variants (
short
,
char
,
long
,
double
, and so forth).
After reading the article ab ove, it's safe to assume that integers and ˛oating-p oint num-
b ers have opp osite caracteristics.
But to day, things will change. You are going to discover a new and awesome numb er
typ e:
˝xed-p oint numb ers
! Forever missing from the scalar typ es of most languages,
˝xed-p oint numb ers o˙er a valuable balance b etween p erformance, accuracy, range and
precision. That explains why ˝xed-p oint numb ers are particularly applicable to computer
graphics, sound pro cessing or scienti˝c programming, just to name a few.
As C++ lacks ˝xed-p oint numb ers, you're going to add them.
 This article
 from
Berkeley is a go o d start. If you have no idea what Berkeley University is, read
 this
section
 of its Wikip edia page.
6


C++ - Mo dule 02
Ad-ho c p olymorphism, op erator overloading
and Ortho dox Canonical class form
Create a class in Ortho dox Canonical Form that represents a ˝xed-p oint numb er:

Private memb ers:

An
integer
to store the ˝xed-p oint numb er value.

A
static constant integer
to store the numb er of fractional bits. Its value
will always b e the integer literal
8
.

Public memb ers:

A default constructor that initializes the ˝xed-p oint numb er value to
0
.

A copy constructor.

A copy ass ignment op erator overload.

A destructor.

A memb er function
int getRawBits( void ) const;
that returns the raw value of the ˝xed-p oint value.

A memb er function
void setRawBits( int const raw );
that sets the raw value of the ˝xed-p oint numb er.
Running this co de:
#include
<iostream>
int
main
(
void
)
 {
Fixed
 a
;
Fixed
 b
(
 a
 );
Fixed
 c
;
c
 =
 b
;
std
::
cout
 <<
 a
.
getRawBits
()
 <<
 std
::
endl
;
std
::
cout
 <<
 b
.
getRawBits
()
 <<
 std
::
endl
;
std
::
cout
 <<
 c
.
getRawBits
()
 <<
 std
::
endl
;
return
0
;
}
Should output something similar to:
$> ./a.out
Default constructor called
Copy constructor called
Copy assignment operator called // <-- This line may be missing depending on your implementation
getRawBits member function called
Default constructor called
Copy assignment operator called
getRawBits member function called
getRawBits member function called
0
getRawBits member function called
0
getRawBits member function called
0
Destructor called
Destructor called
Destructor called
$>
7


Chapter V
Exercise 01: Towards a more useful
˝xed-p oint numb er class
Exercise 01
Towards a more useful ˝xed-p oint numb er class
Turn-in directory :
ex
01
=
Files to turn in :
Makefile, main.cpp, Fixed.{h, hpp}, Fixed.cpp
Allowed functions :
roundf (from <cmath>)
The previous exercise was a go o d start but our class is pretty useles s. It can only
represent the value
0.0
.
Add the following public constructors and public memb er functions to your class:

A constructor that takes a
constant integer
as a parameter.
It converts it to the corresp onding ˝xed-p oint value. The fractional bits value is
initialized to 8 like in exercise 00.

A constructor that takes a
constant ˛oating-p oint numb e r
as a parameter.
It converts it to the corresp onding ˝xed-p oint value. The fractional bits value is
initialized to 8 like in exercise 00.

A memb er function
float toFloat( void ) const;
that converts the ˝xed-p oint value to a ˛oating-p oint value.

A memb er function
int toInt( void ) const;
that converts the ˝xed-p oint value to an integer value.
And add the following function to the
Fixed
class ˝les:

An overload of the insertion () op erator that inserts a ˛oating-p oint representation
of the ˝xed-p oint numb er into the output stream ob ject passed as parameter.
8


C++ - Mo dule 02
Ad-ho c p olymorphism, op erator overloading
and Ortho dox Canonical class form
Running this co de:
#include
<iostream>
int
main
(
void
)
 {
Fixed
 a
;
Fixed
const
b
(
 10
 );
Fixed
const
c
(
 42.42f
 );
Fixed
const
d
(
 b
 );
a
 =
 Fixed
(
 1234.4321f
 );
std
::
cout
 <<
 "a is "
 <<
 a
 <<
 std
::
endl
;
std
::
cout
 <<
 "b is "
 <<
 b
 <<
 std
::
endl
;
std
::
cout
 <<
 "c is "
 <<
 c
 <<
 std
::
endl
;
std
::
cout
 <<
 "d is "
 <<
 d
 <<
 std
::
endl
;
std
::
cout
 <<
 "a is "
 <<
 a
.
toInt
()
 <<
 " as integer"
 <<
 std
::
endl
;
std
::
cout
 <<
 "b is "
 <<
 b
.
toInt
()
 <<
 " as integer"
 <<
 std
::
endl
;
std
::
cout
 <<
 "c is "
 <<
 c
.
toInt
()
 <<
 " as integer"
 <<
 std
::
endl
;
std
::
cout
 <<
 "d is "
 <<
 d
.
toInt
()
 <<
 " as integer"
 <<
 std
::
endl
;
return
0
;
}
Should output something similar to:
$> ./a.out
Default constructor called
Int constructor called
Float constructor called
Copy constructor called
Copy assignment operator called
Float constructor called
Copy assignment operator called
Destructor called
a is 1234.43
b is 10
c is 42.4219
d is 10
a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer
Destructor called
Destructor called
Destructor called
Destructor called
$>
9


Chapter VI
Exercise 02: Now we're talking
Exercise 02
Now we're talking
Turn-in directory :
ex
02
=
Files to turn in :
Makefile, main.cpp, Fixed.{h, hpp}, Fixed.cpp
Allowed functions :
roundf (from <cmath>)
Add public memb er functions to your class to overload the following op erators:

The 6 comparison op erators:
>
,
<
,
>=
,
<=
,
==
and
!=
.

The 4 arithmetic op erators:
+
,
-
,
*
, and
/
.

The 4 increment/decrement (pre-increment and p ost-increment, pre-decrement and
p ost-decrement) op erators, that will increase or decrease the ˝xed-p oint value from
the smallest representable

such as
1 +
 >
1
.
Add these four public overloaded memb er functions to your class:

A static memb er function
min
that takes as parameters two references on ˝xed-p oint
numb ers, and returns a reference to the smallest one.

A static memb er function
min
that takes as parameters two references to
constant
˝xed-p oint numb ers, and returns a reference to the smallest one.

A static memb er function
max
that takes as parameters two references on ˝xed-p oint
numb ers, and returns a reference to the greatest one.

A static memb er function
max
that takes as parameters two references to
constant
˝xed-p oint numb ers, and returns a reference to the greatest one.
10


C++ - Mo dule 02
Ad-ho c p olymorphism, op erator overloading
and Ortho dox Canonical class form
It's up to you to test every feature of your class. However, running the co de b elow:
#include
<iostream>
int
main
(
void
)
 {
Fixed
 a
;
Fixed
const
b
(
 Fixed
(
 5.05f
 )
 *
 Fixed
(
 2
 )
 );
std
::
cout
 <<
 a
 <<
 std
::
endl
;
std
::
cout
 <<
 ++
a
 <<
 std
::
endl
;
std
::
cout
 <<
 a
 <<
 std
::
endl
;
std
::
cout
 <<
 a
++
 <<
 std
::
endl
;
std
::
cout
 <<
 a
 <<
 std
::
endl
;
std
::
cout
 <<
 b
 <<
 std
::
endl
;
std
::
cout
 <<
 Fixed
::
max
(
 a
,
 b
 )
 <<
 std
::
endl
;
return
0
;
}
Should output something like (for greater readability, the constructor/destructor mes-
sages are removed in the example b elow):
$> ./a.out
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
$>
If you ever do a division by 0, it is acceptable that the program
crashes
11


Chapter VI I
Exercise 03: BSP
Exercise 03
BSP
Turn-in directory :
ex
03
=
Files to turn in :
Makefile, main.cpp, Fixed.{h, hpp}, Fixed.cpp,
Point.{h, hpp}, Point.cpp, bsp.cpp
Allowed functions :
roundf (from <cmath>)
Now that you have a functional
Fixed
class, it would b e nice to use it.
Implement a function which indicates whether a p oint is inside of a triangle or not.
Very useful, isn't it?
BSP stands for Binary space partitioning. You are welcome. :)
You can pass this module without doing exercise 03.
12


C++ - Mo dule 02
Ad-ho c p olymorphism, op erator overloading
and Ortho dox Canonical class form
Let's start by creating the class
Point
in Ortho dox Canonical Form that represents
a 2D p oint:

Private memb ers:

A Fixed const attribute
x
.

A Fixed const attribute
y
.

Anything else useful.

Public memb ers:

A default constructor that initializes
x
and
y
to
0
.

A constructor that takes as parameters two constant ˛oating-p oint numb ers.
It initializes
x
and
y
with those parameters.

A copy constructor.

A copy ass ignment op erator overload.

A destructor.

Anything else useful.
To conclude, implement the following function in the appropriate ˝le:
bool bsp( Point const a, Point const b, Point const c, Point const point);

a, b, c: The vertices of our b eloved triangle.

p oint: The p oint to check.

Returns: True if the p oint is inside the triangle. False otherwise.
Thus, if the p oint is a vertex or on edge, it will return False.
Implement and turn in your own tests to ensure that your class b ehaves as exp ected.
13


Chapter VI I I
Submission and p eer-evaluation
Turn in your assignment in your
Git
rep ository as usual. Only the work inside your
rep ository will b e evaluated during the defense. Don't hesitate to double check the
names of your folders and ˝les to ensure they are correct.
???????????? XXXXXXXXXX = $3$$d6f957a965f8361750a3ba6c97554e9f
14
