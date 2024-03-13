#  CPP06

## Type Conversion

E.g.

```C
int a = 42;
double b = a; // Implicit conversion cast
double c = (double) a; // Explicit conversion cast

double d = a; // Implicit promotion -> OK
int e = d; // Implicit demotion -> Hazardous
int f = (int) d; // Explicit demotion -> OK
```

Using the `--Wno-conversion` compiling flag when doing advanced calculations, prevents implicit cast when losing accuracy.

## Type Reinterpretation (Identity conversion)

```C
float a = 420.042f;

// Void allows to store the address of any type, but is less accurate than other types (e.g. float)
void *b = &a; // Implicit reinterpretation cast
void *c = (void *) &a; // Exmplicit reinterpretation cast

void *d = &a; // Implicit promotion -> OK
int *e = d; // Implicit demotion -> Hazardous
int *f = (int *) d; //Explicit demotion -> OK (Bad example)
```

## Type Qualifier Reinterpretation

Type qualifiers in C are keywords like `const` and `volatile`.

```C
int a = 42;
int const *b = &a; // Implicit conversion cast
int const *c = (int const *) &a; // Explicit conversion cast

int const *d = &a; // Implicit promotion -> OK
int *e = d; // Implicit demotion -> Won't compile
int *f = (int *) d; // Explicit demotion -> Compiles, but shouldn't be used
```

## Upcast and Downcast

Upcast and downcast are reinterpretations of class addresses.

```CPP
// Using C syntax

class Parent{};
class Child1 : public Parent {}
class Child2 : public Parent {}

int main()
{
    Child1 a;

    Parent *b = &a; // Implicit 'reinterpretation' cast
    Parent *c = (Parent *) &a; // Explicit 'reinterpretation' cast

    Parent *d = &a; // Implicit upcast -> Ok
    Child1 *e = d; // Implicit downcast -> Won't compile
    Child2 *f = (Child2 *) d; // Explicit downcast -> Compiles, but shouldn't be used (Child2 could be implemented differently than Child1)
}
```

## [CPP Casts](https://www.learncpp.com/cpp-tutorial/explicit-type-conversion-casting-and-static-cast/)

### Static Cast

Static cast can be used to convert simple values. It ensures casts will only be made between compatible addresses in the same inheritance tree.

```CPP
int a = 42;

double b = a;
int c = b;
int d = static_cast<int> b: // Explicit demotion -> OK
```

```CPP
class Parent{};
class Child1 : public Parent {}
class Child2 : public Parent {}
class Unknown {}

int main()
{
    Child1 a;

    Parent *b = &a; // Implicit upcast -> Ok
    Child1 *c = d; // Implicit downcast -> Won't compile
    Child2 *d = static_cast<Child2 *>(d); // Explicit downcast -> Compiles, but shouldn't be used (Child2 could be implemented differently than Child1)

Unknown *e = static_cast<Unknown *>(b); // Won't compile
}
```

### Dynamic Cast

Dynamic Cast only happens at runtime, while all other casts are done during compilation. Program may compile but the dynamic cast may fail at runtime, which means the Dynamic Cast should be handled properly (error checking).

Dynamic Cast only works with polymorphic instances (sub-type polymorphisms), meaning at least one the member functions has to be virtual (to allow for dynamic cast).

Dynamic cast is used only for down cast, and checks if the cast is possible.

Dynamic cast only works for pointer and reference casts. The behaviour is different for each.

Dynamic cast returns either the converted address or NULL when the cast of a pointer is impossible. If casting a reference, one should use try/catch.

Dynamic cast can be used when implementing **plugins**. The plugin type may be different each time it's used, and dynamic cast allows us to know which type is used and return errors accordingly.

```CPP

class Parent {public: virtual ~Parent(){}}; //At least one member function must be virtual
class Child1 : public Parent {};
class Child2 : public Parent {};

int main()
{
    Child1 a;
    Parent *b = &a;

    // Explicit downcast (pointer)
    Child1 *c = dynamic_cast<Child1 *> (b);
    if (c == NULL)
    // error
    else
    // OK

    // Explicit downcast (reference)
    try
    {
        Child2& d = dynamic_cast<Child 2&> (*b); // Child2 can't be NULL
        std::cout << "conversion OK\n";
    }
    catch(std::bad_cast &bc)
    {
        std::cout << bc.what();
    }
}
```

### Reinterpret Cast

Applies to up-casts and down-casts.

There are no semantics tests.

A common use cast is re-typing. Example, when receiving raw data, we can store it in a void pointer (as a stream of bytes) and then reinterpret it as whatever a protocol says it is (eg. a string).

```CPP
float a = 420.042f;

void *b = &a;
int *c = reinterpret_cast<int *>(b); // OK
int &d = reinterpret_cast<int &>(*b); // OK
```

### Const Cast

```CPP
int a = 42;
int const a = 42;

int const *b = &a;
int *c = b; // Won't compile
int *d = const_cast<int *> (b); //Ok, but shouldn't be used.
```

## Type Cast operators

```CPP
class Foo {
    float _v;

    public:
    Foo (float const v) : _v(v) {}
    float getV(void) {return this->_v;}
    operator float() {return this->_v;}
    operator int() {return static_cast<int>(this->_v);}
};

int main()
{
    Foo a(420.024f);
    float b = a;    // OK
    int c = a;  //OK
}
```

## Explicit keyword

Explicit is used to prevent the implicit construction of an instance.

```CPP
class A {};
class B {};

class C
{
    public:
                C(A const &_) {return;}
    explicit    C(B const &_) {return;}
};

void f(C const &_)
{
    return;
}

int main()
{
    f(A()); // Implicit conversion OK
    f(B()); // Implicit conversion NOT OK, constructor is explicit
}
```

