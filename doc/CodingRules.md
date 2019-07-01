# Coding Rules

## Git Rules

One main thing/feature per commit (unless you document your code at the same time as you code).
Use of [Git Emoji](https://gitmoji.carloscuesta.me/) (if you need two git emoji [except documentation] try to split your commit)

## Repository Structure

- **dependencies** : installed dependencies
- **doc** For Documentation complement, coding rules...
  - only in **.md* for text
  - Documentation images : prefers Vector graphics **.svg* or **.png*
  - Logo : *logo.png*
- **src** : all source code except tests
- **vcxproj** : all visual studio projects files
- *.codedocs*
- *.gitignore*
- *.gitmodules*
- *.travis.yml*
- *appveyor.yml*
- *CHANGELOG.md*
- *CMakeLists.txt*
- *Doxyfile*
- *hello.sln*
- *LICENSE*
- *README.md*

## folders and files name

- **Folders** : all-lower
  - ✔️ **my-folder-name**
  - ❌ **my_folder_name**, **myFolderName**, **MyFolderName**, **My Folder Name**...
- *Files* : lowerCamelCase, UpperCamelCase, Underscore prefix tolerant, dash + specification suffix tolerant
  - ✔️ *myFileName.ext*, *MyFileName.ext*, *myFileName-extended.ext*, *_myFileName.ext*
  - ❌ *my_file_name*, *my-file-name*, *My File Name*...

## C/C++ Coding Rules

### Tools

To respect Coding Rules, I use [Resharper C++](https://www.jetbrains.com/resharper-cpp/) Free for students, teachers,  classroom assistance, Open Source projects... I provide [here](https://github.com/tmonseigne/cpp-crossplatform-ci-template/blob/master/doc/CodingStyle.DotSettings) an example of setting with Resharper.

### Naming

#### Explicit Naming

The name should be explicit. Abbreviations are allowed as long as they are obvious or if it's an acronym (if it is present in a function name, the documentation of it will clearly indicate the definition of the acronym).
Ex: pointer => ptr, input => in, result => res, Support Vector Machine => SVM, ...

#### Naming Style

| Entity | Style | Prefix | Suffix | Naming Template |
|:---|:---|:---:|:---:|:---|
| Struct | UpperCamelCase | S | | SMyStruct |
| Enum | UpperCamelCase | E | | EMyEnum |
| Class | UpperCamelCase | C | | CMyClass |
| Template class | UpperCamelCase | T | | TMyTemplateClass |
| Interface (abstract class) | UpperCamelCase | I | | IMyInterface |
| Local Function (in cpp) | lowerCamelCase | | | myFunction |
| Global Function (in hpp) | UpperCamelCase | | | MyFunction |
| Function argument | all_lower | | | my_args |
| CONST | ALL_UPPER | | | MY_CONST |
| **Class/struct** |  |  |  |  |
| - Private variable | lowerCamelCase | _ | | _myVariable |
| - Public variable | UpperCamelCase | _ | | _MyVariable |
| - Private Function | lowerCamelCase | | | myFunction |
| - Public Function | UpperCamelCase | | | MyFunction |

### Modernize style Code

In Header file :

- ✔️ `#pragma once`
- ❌ `#ifndef ...#define ... #endif`

auto use : use auto if type is iterator or not important

- ✔️ `for (const auto& elem:vector){ cout<<elem; }`
- ✔️ `auto it = v.begin();`
- ❌ `auto i = 0;`

Loop range (with useless iterator) :

- ✔️ `for (const auto& elem:vector){ cout<<elem; }`
- ❌ `for (size_t i = 0; i < vector.size(); ++i){ cout<<vector[i]; }`
- ❌ `for (auto it = v.begin(); it != v.end(); ++it){ cout<<*it; }`

nullptr instead of NULL:

- ✔️ `double *a = nullptr;`
- ❌ `double *a = NULL;`

constexpr instaed of MACRO define:

- ✔️ `constexpr int A = 10;`
- ❌ `#define A 10`

always initialize the variables in the class declaration :

```c++
class C
{
public:
    int var = 0;
    float *arr = nullptr;

    void a();
};
```

#### Class declaration

```c++
class C
{
protected:
    //variables (const first)
private:
    //variables (const first)
public:
    //variables (const first)
protected:
    //function
private:
    //function
public:
    //function
};
```

### Formatting

It's a listing of Resharper options (plugin of Jetbrain in visual studio). If you use it you can load the setting file in `doc` folder

#### Tabs & Indent

- Tab character
- How to aligne : Mix Tab and space for optimal fill

#### Braces Layout

**Namespace Déclaration** : at next line (BSD Style)

```c++
namespace ns
{
    void a();
}
```

**Type Declaration** : at next line (BSD Style)

```c++
class C
{
public:
    void a();
};
```

**Place Namespace on the same line** : false

```c++
namespace A
{
    namespace B
    {
        void a();
    }
}
```

**Function Déclaration** : at next line (BSD Style)

```c++
void a()
{
    b();
}
```

**Block under case label** : at end of line (K&R Style)

```c++
switch (expression) {
    case 0: {
        foo();
        break;
    }
}
```

**Other statement and blocks** : at end of line (K&R Style)

```c++
if (condition) {
    foo();
} else {
    foo();
}
```

**Empty Braces format** : together on the same line (BSD Style)

```c++
class C {};
```

**Simple statement** : as you want short statement can be stay in one line

```c++
int foo() { return 0; }
int foo()
{
    return 0;
}
```

#### Blank lines

**Max blank lines** : 1
**Blank line around function, namespace, classes** : min 1
**Blank line around variable declaration** : min 0

#### Spaces

**pointer & reference declaration** : before

```c++
int **data;
int **data, *data2, &data3 = *data2;
int **foo(int a, int b);
```

**comma déclaration** : before

```c++
int a, b, c;
int foo(int a, int b, int c);
template<typename K, typename V>
```

**parentheses parameter, angle bracket Template, empty bracket** : No

```c++
int foo(int a, int b, int c);
template<typename K>
vector<vector<int>> v;
template<>
int foo();
struct map {};
```

**around operator** : Always

```c++
c = a + b;
c = (a > 0) ? a : b;
```

**Align end of line comments** : if possible

```c++
int a;              // a variable
int FooVariable;    // Foo Variable
```

**Align Multiple declaration if possible** : previous option in Tabs & Indent part make for you the alignment

```c++
int first,
    second;
double average(double first,
               double second);
```

#### Line breaks

**If / else** : if single statement : as you want short statement can be stay in one line

```c++
if (true) {
    foo();
} else {
    foo();
}

if (true) { foo(); }
else { foo(); }
```

**Do While** :

```c++
do {
    foo();
} while (true);
```

**Try Catch** :

```c++
try {
    foo();
} catch (...) {
    foo();
}
```

**Switch Case** : if single statement : as you want short statement can be stay in one line

```c++
switch (a) {
    case b:
        foo();
        foo();
        break;
    case c: break;
}

switch (a) {
    case b: foo(); break;
    case c: foo(); break;
}
```
