C++ - Mo dule 03
Inheritance
Summary:
This document contains the exercises of Module 03 from C++ modules.
Version: 7


Contents
I Intro duction
 2
I I General rules
 3
I I I Exercise 00: Aaaaand... OPEN!
 5
IV Exercise 01: Serena, my love!
 7
V Exercise 02: Rep e titive work
 8
VI Exercise 03: Now it's weird!
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


C++ - Mo dule 03 Inheritance
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
Exercise 00: Aaaaand... OPEN!
Exercise : 00
Aaaaand... OP EN!
Turn-in directory :
ex
00
=
Files to turn in :
Makefile, main.cpp, ClapTrap.{h, hpp}, ClapTrap.cpp
Forbidden functions :
None
First, you have to implement a class! How original!
It will b e called
ClapTrap
and will have the following private attributes initialized
to the values sp eci˝ed in brackets:

Name, which is passed as parameter to a constructor

Hit p oints (10), represent the health of the ClapTrap

Energy p oints (10)

Attack damage (0)
Add the following public memb er functions s o the ClapTrap lo oks more realistic:

void attack(const std::string& target);

void takeDamage(unsigned int amount);

void beRepaired(unsigned int amount);
When ClapTrack attacks, it causes its target to lose
<attack damage>
hit p oints.
When ClapTrap repairs itself, it gets
<amount>
hit p oints back. Attacking and repairing
cost 1 energy p oint each. Of course, ClapTrap can't do anything if it has no hit p oints
or energy p oints left.
5


C++ - Mo dule 03 Inheritance
In all of these memb er functions, you have to print a message to describ e what hap-
p ens. For example, the
attack()
function may display something like (of course, without
the angle brackets):
ClapTrap <name> attacks <target>, causing <damage> points of damage!
The constructors and destructor must also dis play a message, so your p eer-evaluators
can easily see they have b een called.
Implement and turn in your own tests to ensure your co de works as exp ected.
6


Chapter IV
Exercise 01: Serena, my love!
Exercise : 01
Serena, my love!
Turn-in directory :
ex
01
=
Files to turn in :
Files from previous exercise + ScavTrap.{h, hpp},
ScavTrap.cpp
Forbidden functions :
None
Because you can never have enough ClapTraps, you will now create a derived rob ot.
It will b e named
ScavTrap
and will inherit the constructors and destructor from Clap-
Trap. However, its constructors, destructor and
attack()
will print di˙erent messages.
After all, ClapTraps are aware of their individuality.
Note that prop er construction/destruction chaining must b e shown in your tests.
When a ScavTrap is created, the program starts by building a ClapTrap. Destruction is
in reverse order. Why?
ScavTrap
will use the attributes of ClapTrap (up date ClapTrap in consequence) and
must initialize them to:

Name, which is passed as parameter to a constructor

Hit p oints (100), represent the health of the ClapTrap

Energy p oints (50)

Attack damage (20)
ScavTrap will also have its own sp ecial capacity:
void guardGate();
This memb er function will display a message informing that ScavTrap is now in Gate
keep er mo de.
Don't forget to add more tests to your program.
7


Chapter V
Exercise 02: Rep etitive work
Exercise : 02
Rep etitive work
Turn-in directory :
ex
02
=
Files to turn in :
Files from previous exercises + FragTrap.{h, hpp},
FragTrap.cpp
Forbidden functions :
None
Making ClapTraps is probably starting to get on your nerves.
Now, implement a
FragTrap
class that inherits from ClapTrap. I t is very similar to
ScavTrap. However, its construction and des truction messages must b e di˙erent. Prop er
construction/destruction chaining must b e shown in your tests. When a FragTrap is
created, the program starts by building a ClapTrap. D estruction is in reverse order.
Same things for the attributes, but with di˙erent values this time:

Name, which is passed as parameter to a constructor

Hit p oints (100), represent the health of the ClapTrap

Energy p oints (100)

Attack damage (30)
FragTrap has a sp ecial capacity to o:
void highFivesGuys(void);
This memb er function displays a p ositive high ˝ves request on the standard output.
Again, add more tests to your program.
8


Chapter VI
Exercise 03: Now it's weird!
Exercise : 03
Now it's weird!
Turn-in directory :
ex
03
=
Files to turn in :
Files from previous exercises + DiamondTrap.{h, hpp},
DiamondTrap.cpp
Forbidden functions :
None
In this exercise, you will create a monster: a ClapTrap that's half FragTrap, half
ScavTrap. It will b e named
DiamondTrap
, and it will inherit from b oth the FragTrap
AND the ScavTrap. This is so risky!
The DiamondTrap class will have a
name
private attribute. Give to this attribute
exactly the same variable's name (not talking ab out the rob ot's name here) than the one
in the ClapTrap base class.
To b e more clear, here are two examples.
If ClapTrap's variable is
name
, give the name
name
to the one of the DiamondTrap.
If ClapTrap's variable is
_name
, give the name
_name
to the one of the DiamondTrap.
Its attributes and memb er functions will b e picked from either one of its parent class es:

Name, which is passed as parameter to a constructor

ClapTrap::name
(parameter of the constructor + "
_clap_name
" su˚x)

Hit p oints (FragTrap)

Energy p oints (ScavTrap)

Attack damage (FragTrap)

attack()
(Scavtrap)
9


C++ - Mo dule 03 Inheritance
In addition to the sp ecial functions of b oth its parent classes, DiamondTrap will have
its own sp ecial capacity:
void whoAmI();
This memb er function will display b oth its name and its ClapTrap name.
Of course, the ClapTrap sub ob ject of the DiamondTrap will b e created once, and only
once. Yes, there's a trick.
Again, add more tests to your program.
Do you know the -Wshadow and -Wno-shadow compiler flags?
You can pass this module without doing exercise 03.
10


Chapter VI I
Submission and p eer-evaluation
Turn in your assignment in your
Git
rep ository as usual. Only the work inside your
rep ository will b e evaluated during the defense. Don't hesitate to double check the
names of your folders and ˝les to ensure they are correct.
???????????? XXXXXXXXXX = $3$$cf36316f07f871b4f14926007c37d388
11
