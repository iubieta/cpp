C++ - Mo dule 06
C++ casts
Summary:
This document contains the exercises of Module 06 from C++ modules.
Version: 6.2


Contents
I Intro duction
 2
I I General rules
 3
I I I Additional rule
 5
IV Exercise 00: Conversion of scalar typ es
 6
V Exercise 01: Serialization
 9
VI Exercise 02: Identify real typ e
 10
VI I Submission and p eer-evaluation
 11
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


C++ - Mo dule 06 C++ casts
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
Additional rule
The following rule applies to the entire mo dule and is not optional.
For each exercise, the typ e conversion must b e solved using one sp eci˝c typ e of casting.
Your choice will b e checked during defense.
5


Chapter IV
Exercise 00: Conversion of scalar
typ es
Exercise 00
Conversion of scalar typ es
Turn-in directory :
ex
00
=
Files to turn in :
Makefile, *.cpp, *.{h, hpp}
Allowed functions :
Any function to convert from a string to an int, a
float or a double. This will help, but won't do the whole job.
Write a class ScalarConverter that will contain only one
static
metho ds "convert"
that will takes as parameter a string representation of a C++ literal in its most common
form and output its value in the following serie of scalar typ es :

char

int

˛oat

double
As this class do esn't need to store anything at all, this class must not b e instanciable by
users.
Except for char parameters, only the decimal notation will b e used.
Examples of char literals:
'c'
,
'a'
, ...
To make things simple, please note that non displayable characters shouldn't b e used as
inputs. If a conversion to char is not displayable, prints an informative message.
Examples of int literals:
0
,
-42
,
42
...
Examples of ˛oat literals:
0.0f
,
-4.2f
,
4.2f
...
You have to handle these pseudo literals as well (you know, for science):
-inff
,
+inff
6


C++ - Mo dule 06 C++ casts
and
nanf
.
Examples of double literals:
0.0
,
-4.2
,
4.2
...
You have to handle these pseudo literals as well (you know, for fun):
-inf
,
+inf
and
nan
.
7


C++ - Mo dule 06 C++ casts
Write a program to test that your class works as exp ected.
You have to ˝rst detect the typ e of the literal passed as parameter, convert it from
string to its actual typ e, then convert it
explicitly
to the three other data typ es. Lastly,
display the results as shown b elow.
If a conversion do es not make any sense or over˛ows, display a message to inform
the user that the typ e conversion is imp ossible. Include any header you need in order to
handle numeric limits and sp ecial values.
./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0
./convert nan
char: impossible
int: impossible
float: nanf
double: nan
./convert 42.0f
char:
'
*
'
int: 42
float: 42.0f
double: 42.0
8


Chapter V
Exercise 01: Serialization
Exercise : 01
Serialization
Turn-in directory :
ex
01
=
Files to turn in :
Makefile, *.cpp, *.{h, hpp}
Forbidden functions :
None
Implement a class Serializer, who will not b e initializable by the user by any way,
with the following
static
metho ds:
uintptr_t serialize(Data* ptr);
It takes a p ointer and converts it to the unsigned integer typ e
uintptr_t
.
Data* deserialize(uintptr_t raw);
It takes an unsigned integer parameter and converts it to a p ointer to
Data
.
Write a program to test that your class works as exp ected.
You must create a non-empty (it means it has data memb ers)
Data
structure.
Use
serialize()
on the address of the Data ob ject and pass its return value to
deserialize()
. Then, ensure the return value of
deserialize()
compares equal to the
original p ointer.
Do not forget to turn in the ˝les of your
Data
structure.
9


Chapter VI
Exercise 02: Identify real typ e
Exercise : 02
Identify real typ e
Turn-in directory :
ex
02
=
Files to turn in :
Makefile, *.cpp, *.{h, hpp}
Forbidden functions :
std::typeinfo
Implement a
Base
class that has a public virtual destructor only. Create three empty
classes
A
,
B
and
C
, that publicly inherit from Base.
These four classes don't have to be designed in the Orthodox
Canonical Form.
Implement the following functions:
Base * generate(void);
It randomly instanciates A, B or C and returns the instance as a Base p ointer. Feel free
to use anything you like for the random choice implementation.
void identify(Base* p);
It prints the actual typ e of the ob ject p ointed to by p: "A", "B" or "C".
void identify(Base& p);
It prints the actual typ e of the ob ject p ointed to by p: "A", "B" or "C". Using a p ointer
inside this function is forbidden.
Including the
typeinfo
header is forbidden.
Write a program to test that everything works as exp ected.
10


Chapter VI I
Submission and p eer-evaluation
Turn in your assignment in your
Git
rep ository as usual. Only the work inside your
rep ository will b e evaluated during the defense. Don't hesitate to double check the
names of your folders and ˝les to ensure they are correct.
16D85ACC441674FBA2DF65190663E136253996A5020347143B460E2CF3A3784D794B
104265933C3BE5B62C4E062601EC8DD1F82FEB73CB17AC57D49054A7C29B5A5C1D8
2027A997A3E24E387
11
