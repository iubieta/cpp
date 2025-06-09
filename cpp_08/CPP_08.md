C++ - Mo dule 08
Templated containers, iterators, algorithms
Summary:
This document contains the exercises of Module 08 from C++ modules.
Version: 8


Contents
I Intro duction
 2
I I General rules
 3
I I I Mo dule-sp eci˝c rules
 5
IV Exercise 00: Easy ˝nd
 6
V Exercise 01: Span
 7
VI Exercise 02: Mutated ab omination
 9
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


C++ - Mo dule 08 Templated containers , iterators, algorithms
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
Mo dule-sp eci˝c rules
You will notice that, in this mo dule, the exercises can b e solved WITHOUT the standard
Containers and WITHOUT the standard Algorithms.
However,
using them is precis ely the goal of this Mo dule
. You are allowed to
use the STL. Yes, you can use the
Containers
(vector/list/map/and so forth) and the
Algorithms
(de˝ned in header
<algorithm>
). Moreover, you should use them as much
as you can. Thus, do your b est to apply them wherever it's appropriate.
You will get a very bad grade if you don't, even if your co de works as exp ected. Please
don't b e lazy.
You can de˝ne your templates in the header ˝les as usual. Or, if you want to, you
can write your template declarations in the header ˝les and write their implementations
in .tpp ˝les. In any case, the header ˝les are mandatory while the .tpp ˝les are optional.
5


Chapter IV
Exercise 00: Easy ˝nd
Exercise : 00
Easy ˝ nd
Turn-in directory :
ex
00
=
Files to turn in :
Makefile, main.cpp, easyfind.{h, hpp}
and optional file: easyfind.tpp
Forbidden functions :
None
A ˝rst easy exercise is the way to start o˙ on the right fo ot.
Write a function template
easyfind
that accepts a typ e
T
. It takes two parameters.
The ˝rst one has typ e
T
and the second one is an integer.
Assuming
T
is a container
of intege rs
, this function has to ˝nd the ˝rst o ccurrence
of the second parameter in the ˝rst parameter.
If no o ccurrence is found, you can either throw an exception or return an error value
of your choice. If you need some inspiration, analyze how standard containers b ehave.
Of course, implement and turn in your own tests to ensure everything works as ex-
p ected.
You don't have to handle associative containers.
6


Chapter V
Exercise 01: Span
Exercise : 01
Span
Turn-in directory :
ex
01
=
Files to turn in :
Makefile, main.cpp, Span.{h, hpp}, Span.cpp
Forbidden functions :
None
Develop a
Span
class that can store a maximum of
N
integers.
N
is an unsigned int
variable and will b e the only parameter passed to the constructor.
This class will have a memb er function called
addNumber()
to add a single numb er
to the Span. It will b e used in order to ˝ll it. Any attempt to add a new element if there
are already
N
elements stored should throw an exception.
Next, implement two memb er functions:
shortestSpan()
and
longestSpan()
They will resp ectively ˝nd out the shortest span or the longest span (or distance, if
you prefer) b etween all the numb ers stored, and return it. If there are no numb ers stored,
or only one, no span can b e found. Thus, throw an exception.
Of course, you will write your own tests and they will b e way more thorough than the
ones b elow. Test your Span at least with a minimum of 10 000 numb ers. More would b e
even b etter.
7


C++ - Mo dule 08 Templated containers , iterators, algorithms
Running this co de:
int
main
()
{
Span
 sp
 =
 Span
(
5
);
sp
.
addNumber
(
6
);
sp
.
addNumber
(
3
);
sp
.
addNumber
(
17
);
sp
.
addNumber
(
9
);
sp
.
addNumber
(
11
);
std
::
cout
 <<
 sp
.
shortestSpan
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
 sp
.
longestSpan
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
Should output:
$> ./ex01
2
14
$>
Last but not least, it would b e wonderful to ˝ll your Span using a
range of iterators
.
Making thousands calls to
addNumber()
is so annoying. Implement a memb er function
to add many numb ers to your Span in one call.
If you don't have a clue, study the Containers. Some member
functions take a range of iterators in order to add a sequence of
elements to the container.
8


Chapter VI
Exercise 02: Mutated ab omination
Exercise : 02
Mutated ab omination
Turn-in directory :
ex
02
=
Files to turn in :
Makefile, main.cpp, MutantStack.{h, hpp}
and optional file: MutantStack.tpp
Forbidden functions :
None
Now, time to move on more serious things. Let's develop something weird.
The
std::stack
container is very nice. Unfortunately, it is one of the only STL Con-
tainers that is NOT iterable. That's to o bad.
But why would we accept this? Esp ecially if we can take the lib erty of butchering the
original stack to create missing features.
To repair this injustice, you have to make the
std::stack
container iterable.
Write a
MutantStack
class. It will
b e implemented in terms of
a
std::stack
.
It will o˙er all its memb er functions, plus an additional feature:
iterators
.
Of course, you will write and turn in your own tests to ensure everything works as
exp ected.
9


C++ - Mo dule 08 Templated containers , iterators, algorithms
Find a test example b elow.
int
main
()
{
MutantStack
<
int
>
 mstack
;
mstack
.
push
(
5
);
mstack
.
push
(
17
);
std
::
cout
 <<
 mstack
.
top
()
 <<
 std
::
endl
;
mstack
.
pop
();
std
::
cout
 <<
 mstack
.
size
()
 <<
 std
::
endl
;
mstack
.
push
(
3
);
mstack
.
push
(
5
);
mstack
.
push
(
737
);
//[...]
mstack
.
push
(
0
);
MutantStack
<
int
>::
iterator
 it
 =
 mstack
.
begin
();
MutantStack
<
int
>::
iterator
 ite
 =
 mstack
.
end
();
++
it
;
--
it
;
while
(
it
 !=
 ite
)
{
std
::
cout
 <<
 *
it
 <<
 std
::
endl
;
++
it
;
}
std
::
stack
<
int
>
 s
(
mstack
);
return
0
;
}
If you run it a ˝rst time with your MutantStack, and a second time replacing the
MutantStack with, for example, a
std::list
, the two outputs should b e the same. Of
course, when testing another container, up date the co de b elow with the corresp onding
memb er functions (
push()
can b ecome
push_back()
).
10


Chapter VI I
Submission and p eer-evaluation
Turn in your assignment in your
Git
rep ository as usual. Only the work inside your
rep ository will b e evaluated during the defense. Don't hesitate to double check the
names of your folders and ˝les to ensure they are correct.
16D85ACC441674FBA2DF65195A38EE36793A89EB04594B15725A1128E7E97B0E7B47
111668BD6823E2F873124B7E59B5CE94B47AB764CF0AB316999C56E5989B4B4F00C
91B619C70263F
11
