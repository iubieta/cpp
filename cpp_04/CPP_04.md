C++ - Mo dule 04
Subtyp e p olymorphism, abstract classes, interfaces
Summary:
This document contains the exercises of Module 04 from C++ modules.
Version: 11


Contents
I Intro duction
 2
I I General rules
 3
I I I Exercise 00: Poly morphism
 5
IV Exercise 01: I don't want to set the world on ˝re
 7
V Exercise 02: Abstract class
 9
VI Exercise 03: Interface & recap
 10
VI I Submission and p eer-evaluation
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


C++ - Mo dule 04 Subtyp e p olymorphism, abstract classes, interfaces
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
Exercise 00: Polymorphism
Exercise : 00
Polymorphism
Turn-in directory :
ex
00
=
Files to turn in :
Makefile, main.cpp, *.cpp, *.{h, hpp}
Forbidden functions :
None
For every exercise, you have to provide the
most complete tests
you can.
Constructors and destructors of each class must display sp eci˝c messages. Don't use the
same message for all classes.
Start by implementing a simple base class called
Animal
. It has one protected
attribute:

std::string type;
Implement a
Dog
class that inherits from Animal.
Implement a
Cat
class that inherits from Animal.
These two derived classes must set their
type
˝eld dep ending on their name. Then,
the Dog's typ e will b e initialized to "Dog", and the Cat's typ e will b e initialized to "Cat".
The typ e of the Animal class can b e left empty or set to the value of your choice.
Every animal must b e able to use the memb er function:
makeSound()
It will print an appropriate sound (cats don't bark).
5


C++ - Mo dule 04 Subtyp e p olymorphism, abstract classes, interfaces
Running this co de should print the sp eci˝c sounds of the Dog and Cat classes, not
the Animal's.
int
main
()
{
const
Animal
*
 meta
 =
new
Animal
();
const
Animal
*
 j
 =
new
Dog
();
const
Animal
*
 i
 =
new
Cat
();
std
::
cout
 <<
 j
->
getType
()
 <<
 " "
 <<
 std
::
endl
;
std
::
cout
 <<
 i
->
getType
()
 <<
 " "
 <<
 std
::
endl
;
i
->
makeSound
();
//will output the cat sound!
j
->
makeSound
();
meta
->
makeSound
();
...
return
0
;
}
To ensure you understo o d how it works, implement a
WrongCat
class that inherits
from a
WrongAnimal
class. If you replace the Animal and the Cat by the wrong ones
in the co de ab ove, the WrongCat should output the WrongAnimal sound.
Implement and turn in more tests than the ones given ab ove.
6


Chapter IV
Exercise 01: I don't want to set the
world on ˝re
Exercise : 01
I don't want to set the world on ˝ re
Turn-in directory :
ex
01
=
Files to turn in :
Files from previous exercise + *.cpp, *.{h, hpp}
Forbidden functions :
None
Constructors and destructors of each class must display sp eci˝c messages.
Implement a
Brain
class. It contains an array of 100
std::string
called
ideas
.
This way, Dog and Cat will have a private
Brain*
attribute.
Up on construction, Dog and Cat will create their Brain using
new Brain();
Up on destruction, Dog and Cat will
delete
their Brain.
In your main function, create and ˝ll an array of
Animal
ob jects. Half of it will
b e
Dog
ob jects and the other half will b e
Cat
ob jects. At the end of your program
execution, lo op over this array and delete every Animal. You must delete directly dogs
and cats as Animals. The appropriate destructors must b e called in the exp ected order.
Don't forget to check for
memory leaks
.
A copy of a Dog or a Cat mustn't b e shallow. Thus, you have to test that your copies
are deep copies!
7


C++ - Mo dule 04 Subtyp e p olymorphism, abstract classes, interfaces
int
main
()
{
const
Animal
*
 j
 =
new
Dog
();
const
Animal
*
 i
 =
new
Cat
();
delete
j
;
//should not create a leak
delete
i
;
...
return
0
;
}
Implement and turn in more tests than the ones given ab ove.
8


Chapter V
Exercise 02: Abstract class
Exercise : 02
Abstract class
Turn-in directory :
ex
02
=
Files to turn in :
Files from previous exercise + *.cpp, *.{h, hpp}
Forbidden functions :
None
Creating Animal ob jects do esn't make sense after all. It's true, they make no sound!
To avoid any p ossible mistakes, the default Animal class should not b e instantiable.
Fix the Animal class so nob o dy can instantiate it. Everything should work as b efore.
If you want to, you can up date the class name by adding a A pre˝x to Animal.
9


Chapter VI
Exercise 03: Interface & recap
Exercise : 03
Interface & recap
Turn-in directory :
ex
03
=
Files to turn in :
Makefile, main.cpp, *.cpp, *.{h, hpp}
Forbidden functions :
None
Interfaces don't exist in C++98 (not even in C++20). However, pure abstract classes
are commonly called interfaces. Thus, in this last exercise, let's try to implement inter-
faces in order to make sure you got this mo dule.
Complete the de˝nition of the following
AMateria
class and implement the necessary
memb er functions.
class AMateria
{
protected:
[...]
public:
AMateria(std::string const & type);
[...]
std::string const & getType() const; //Returns the materia type
virtual AMateria* clone() const = 0;
virtual void use(ICharacter& target);
};
10


C++ - Mo dule 04 Subtyp e p olymorphism, abstract classes, interfaces
Implement the Materias concrete classes
Ice
and
Cure
. Use their name in lower-
case ("ice" for Ice, "cure" for Cure) to set their typ es. Of course, their memb er function
clone()
will return a new instance of the same typ e (i.e., if you clone an Ice Materia,
you will get a new I ce Materia).
The
use(ICharacter&)
memb er function will display:

Ice: "
* shoots an ice bolt at <name> *
"

Cure: "
* heals <name>'s wounds *
"
<name>
is the name of the Character passed as parameter. Don't print the angle
brackets (< and >).
While assigning a Materia to another, copying the type doesn't make
sense.
Write the concrete class
Character
which will implement the following interface:
class ICharacter
{
public:
virtual ~ICharacter() {}
virtual std::string const & getName() const = 0;
virtual void equip(AMateria* m) = 0;
virtual void unequip(int idx) = 0;
virtual void use(int idx, ICharacter& target) = 0;
};
The
Character
p ossesses an inventory of 4 slots, which means 4 M aterias at most.
The inventory is empty at construction. They equip the Materias in the ˝rst empty slot
they ˝nd. This means, in this order: from slot 0 to slot 3. In case they try to add
a Materia to a full inventory, or use/unequip an unexisting Materia, don't do anything
(but still, bugs are forbidden). The
unequip()
memb er function must NOT delete the
Materia!
Handle the Materias your character left on the floor as you like.
Save the addresses before calling unequip(), or anything else, but
don't forget that you have to avoid memory leaks.
The
use(int, ICharacter&)
memb er function will have to use the Materia at the
slot[
idx
], and pass the target parameter to the
AMateria::use
function.
11


C++ - Mo dule 04 Subtyp e p olymorphism, abstract classes, interfaces
Your character's inventory will be able to support any type of
AMateria.
Your
Character
must have a constructor taking its name as a parameter. Any copy
(using copy constructor or copy assignment op erator) of a Character must b e
deep
.
During copy, the Materias of a Character must b e deleted b efore the new ones are added
to their inventory. Of course, the Materias must b e deleted when a Character is destroyed.
Write the concrete class
MateriaSource
which will implement the following interface:
class IMateriaSource
{
public:
virtual ~IMateriaSource() {}
virtual void learnMateria(AMateria*) = 0;
virtual AMateria* createMateria(std::string const & type) = 0;
};

learnMateria(AMateria*)
Copies the Materia passed as a parameter and store it in memory so it can b e cloned
later. Like the Character, the
MateriaSource
can know at most 4 Materias. They
are not necessarily unique.

createMateria(std::string const &)
Returns a new Materia. The latter is a copy of the Materia previously learned by
the
MateriaSource
whose typ e equals the one passed as parameter. Returns 0 if
the typ e is unknown.
In a nutshell, your
MateriaSource
must b e able to learn "templates" of Materias to
create them when needed. Then, you will b e able to generate a new Materia using just
a string that identi˝es its typ e.
12


C++ - Mo dule 04 Subtyp e p olymorphism, abstract classes, interfaces
Running this co de:
int
main
()
{
IMateriaSource
*
 src
 =
new
MateriaSource
();
src
->
learnMateria
(
new
Ice
());
src
->
learnMateria
(
new
Cure
());
ICharacter
*
 me
 =
new
Character
(
"me"
);
AMateria
*
 tmp
;
tmp
 =
 src
->
createMateria
(
"ice"
);
me
->
equip
(
tmp
);
tmp
 =
 src
->
createMateria
(
"cure"
);
me
->
equip
(
tmp
);
ICharacter
*
 bob
 =
new
Character
(
"bob"
);
me
->
use
(
0
,
 *
bob
);
me
->
use
(
1
,
 *
bob
);
delete
bob
;
delete
me
;
delete
src
;
return
0
;
}
Should output:
$> clang++ -W -Wall -Werror *.cpp
$> ./a.out | cat -e
* shoots an ice bolt at bob *$
* heals bob
'
s wounds *$
As usual, implement and turn in more tests than the ones given ab ove.
You can pass this module without doing exercise 03.
13


Chapter VI I
Submission and p eer-evaluation
Turn in your assignment in your
Git
rep ository as usual. Only the work inside your
rep ository will b e evaluated during the defense. Don't hesitate to double check the
names of your folders and ˝les to ensure they are correct.
???????????? XXXXXXXXXX = $3$$6b616b91536363971573e58914295d42
14
