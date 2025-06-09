C++ - Mo dule 07
C++ templates
Summary:
This document contains the exercises of Module 07 from C++ modules.
Version: 7


Contents
I Intro duction
 2
I I General rules
 3
I I I Exercise 00: Start with a few functions
 5
IV Exercise 01: Iter
 7
V Exercise 02: Array
 8
VI Submission and p eer-evaluation
 9
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


C++ - Mo dule 07 C++ templates
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
Exercise 00: Start with a few
functions
Exercise : 00
Start with a few functions
Turn-in directory :
ex
00
=
Files to turn in :
Makefile, main.cpp, whatever.{h, hpp}
Forbidden functions :
None
Implement the following function templates:

swap
: Swaps the values of two given arguments. Do es not return anything.

min
: Compares the two values passed in its arguments and returns the smallest
one. If the two of them are equal, then it returns the second one.

max
: Compares the two values passed in its arguments and returns the greatest one.
If the two of them are equal, then it returns the second one.
These functions can b e called with any typ e of argument. The only requirement is
that the two arguments must have the same typ e and must supp ort all the comparison
op erators.
Templates must be defined in the header files.
5


C++ - Mo dule 07 C++ templates
Running the following co de:
int
main
(
void
)
 {
int
a
 =
 2
;
int
b
 =
 3
;
::
swap
(
 a
,
 b
 );
std
::
cout
 <<
 "a = "
 <<
 a
 <<
 ", b = "
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
 "min( a, b ) = "
 <<
 ::
min
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
std
::
cout
 <<
 "max( a, b ) = "
 <<
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
std
::
string
 c
 =
 "chaine1"
;
std
::
string
 d
 =
 "chaine2"
;
::
swap
(
c
,
 d
);
std
::
cout
 <<
 "c = "
 <<
 c
 <<
 ", d = "
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
 "min( c, d ) = "
 <<
 ::
min
(
 c
,
 d
 )
 <<
 std
::
endl
;
std
::
cout
 <<
 "max( c, d ) = "
 <<
 ::
max
(
 c
,
 d
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
Should output:
a = 3, b = 2
min(a, b) = 2
max(a, b) = 3
c = chaine2, d = chaine1
min(c, d) = chaine1
max(c, d) = chaine2
6


Chapter IV
Exercise 01: Iter
Exercise : 01
Iter
Turn-in directory :
ex
01
=
Files to turn in :
Makefile, main.cpp, iter.{h, hpp}
Forbidden functions :
None
Implement a function template
iter
that takes 3 parameters and returns nothing.

The ˝rst parameter is the address of an array.

The second one is the length of the array.

The third one is a function that will b e call on every element of the array.
Turn in a
main.cpp
˝le that contains your tests. Provide enough co de to generate a
test executable.
Your
iter
function template must work with any typ e of array. The third parameter
can b e an instantiated function template.
7


Chapter V
Exercise 02: Array
Exercise : 02
Array
Turn-in directory :
ex
02
=
Files to turn in :
Makefile, main.cpp, Array.{h, hpp}
and optional file: Array.tpp
Forbidden functions :
None
Develop a class template
Array
that contains elements of typ e
T
and that implements
the following b ehavior and functions:

Construction with no parameter: Creates an empty array.

Construction with an unsigned int
n
as a parameter: Creates an array of
n
elements
initialized by default.
Tip: Try to compile
int * a = new int();
then display
*a
.

Construction by copy and assignment op erator. In b oth cases, mo difying either the
original array or its copy after copying musn't a˙ect the other array.

You MUST use the op erator
new[]
to allo cate memory. Preventive allo cation (al-
lo cating memory in advance) is forbidden. Your program must never access non-
allo cated memory.

Elements can b e accessed through the subscript op erator: [ ].

When accessing an element with the [ ] op erator, if its index is out of b ounds, an
std::exception
is thrown.

A memb er function
size()
that returns the numb er of elements in the array. This
memb er function takes no parameter and musn't mo dify the current instance.
As usual, ensure everything works as exp ected and turn in a
main.cpp
˝le that con-
tains your tests.
8


Chapter VI
Submission and p eer-evaluation
Turn in your assignment in your
Git
rep ository as usual. Only the work inside your
rep ository will b e evaluated during the defense. Don't hesitate to double check the
names of your folders and ˝les to ensure they are correct.
16D85ACC441674FBA2DF65190663F43A243E8FA5424E49143B520D3DF8AF68036E47
114F20A16827E1B16612137E59ECD492E468BC6CD109F65388DC57A58E8942585C8
D193B96732206
9
