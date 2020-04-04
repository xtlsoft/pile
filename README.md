# Pile

Pile aims to build an elegant library and scripting language for small devices.

It has several components including pile class, pile library, pile runtime and pile intepreter.

## Pile Class

Pile uses C macro and struct to implement classes.

Here's an example:

```c
// test_class.h
#include "pile_class.h"
#include "pile_types.h"
#define PILE_CLASS_SHORTCUTS true
class(test_class)
{
    pile_int_t a;

    pile_int_t def_fn(test_class, get_a);
    def_destruct(test_class);
};

// test_class.c
pile_int_t impl_fn(test_class, get_a)
{
    return self->a;
}
impl_construct(test_class, pile_int_t a)
{
    self->a = a;
    _assgin(test_class, get_a);
}
impl_default_destruct(test_class);

// main.c
#include <stdio.h>
#include "test_class.h"

int main() {
    new(test_class, ins, 10);
    printf("%d\r\n", ins->get_a(ins));
    ins->a = 1000;
    printf("%d\r\n", call(ins, get_a));
    del(ins);
    renew(test_class, ins, 200);
    printf("%d\r\n", ins->get_a(ins));
    del(ins);
    return 0;
}
```

### Class Shortcuts

The macros have shortcuts when `PILE_CLASS_SHORTCUTS` is defined.

You can disable that if the shortcuts cause name conflicts.

| Shortcut                | Origin                          |
| ----------------------- | ------------------------------- |
| `class`                 | `PILE_CLASS`                    |
| `new`                   | `PILE_NEW`                      |
| `del`                   | `PILE_DEL`                      |
| `impl_fn`               | `PILE_CLASS_METHOD`             |
| `impl_construct`        | `PILE_CLASS_CONSTRUCTOR`        |
| `impl_destruct`         | `PILE_CLASS_DESTRUCTOR`         |
| `impl_default_destruct` | `PILE_CLASS_DESTRUCTOR_DEFAULT` |
| `_assign`               | `PILE_ASSIGN_METHOD`            |
| `def_fn`                | `PILE_DEFINE_METHOD`            |
| `def_destruct`          | `PILE_DEFINE_DESTRUCT`          |
| `call`                  | `PILE_CALL`                     |

In the document, we will use shortcuts to tell.

### Define a class

```c
class(test_class)
{
    pile_int_t a;

    void def_fn(test_class, set_a, pile_int_t a);

    def_destruct(test_class);
};
```

In the code above, we define a class named `test_class`.

To define a class, we need to use macro `class` or `PILE_CLASS`. It receives an argument as the class name. Then a struct body need to be followed.

> Note: after the brackets the semicolon(`;`) cannot be missed.

Because of the limits of C language, pile doesn't support private atrributes. The properties can be defined in normal struct way, like: `pile_str_t str;`.

When defining class methods, we use `def_fn` or `PILE_DEFINE_METHOD` macros. The macro receives its first parameter as the class name, and the second as method name. The return type should be defined before calling the macro, and the parameter list should start at the third macro parameter, separated by commas.

Note the constructor should **not** be defined in the class definition. But the destructor must be defined using `def_destruct` or `PILE_DEFINE_DESTRUCT` macro. The macro receives its first parameter as the class name and no other parameters should be followed.

The following types will be defined as in the example:

- struct test_class: The original struct type
- test_class_t: Orignal type defined using typedef
- test_class_ptr_t: Pointer to the original type (instance type)

### Implement a method

> Note: constructors and destructors should be defined using another macro, which will be described in the next section.

When implementing a method, macro `impl_fn` or `PILE_CLASS_METHOD` should be used.

```c
void impl_fn(test_class, set_a, pile_int_t a)
{
    self->a = a;
}
```

The return type should be defined before calling the macro.

The first parameter is the class name while the second is the method name.

The following parameters are argument list of the method.

Inside the function body we can use `self` to access the instance.

### Implementing a destructor

In a destructor, a class can free the resources it uses.

Use `impl_destruct` or `PILE_CLASS_DESTRUCTOR` to implement one.

Example:

```c
impl_destruct(test_class)
{
    PILE_FREE(self->data);
}
```

When a class does nothing in a destructor, you can use `impl_default_destruct`.

Example:

```c
impl_default_destruct(test_class);
```

### Implement a constructor

A constructor need to do two things:

1. Init the properties
2. Assign methods

You can use `impl_construct` or `PILE_CLASS_CONSTRUCT` macros to implement.

The first parameter is class name, and it can receive a parameter list.

```c
impl_construct(test_class, pile_int_t a)
{
    _assign(test_class, set_a);

    self->set_a(a);
}
```

The `_assign` or `PILE_ASSIGN` macro can automatically assign a method to a class.

All the methods need to be assigned in the constructor,

The macro receives two parameters, where the first one is the class name and the second one is the method name.

### Creating a new instance

You can use `new` or `PILE_NEW` macros to create a new instance.

Example:

```c
new(test_class, ins, 123);
```

The first parameter is the class name, while the second is the variable name. The following parameters will be passed to the constructor. Then you can use `ins` to access the instance.

The above code will create a new variable with type `test_class_ptr_t`.

If you have a variable typed that already available, you can use `renew` or `PILE_RENEW` macro to re-initialize it.

Example:

```c
test_class_ptr_t ins;
renew(test_class, ins, 123);
```

### Deleting a instance

Use `del` or `PILE_DEL` macros.

Example:

```c
del(ins);
```

The parameter is the variable name of the instance.

### Calling a method

You can use `ins->method_name(ins, 123);` to call a method.

Note the first parameter should pass the variable again.

If you use `call` or `PILE_CALL` macro, then you don't need to pass itself again. It looks like:

```c
call(test_cass, set_a, 100);
```

The first parameter is the class name, while the second one is the method name.

## Shortcuts

pcert = pile_container_t

pvcoer = PILE_VALUE_CONTAINER
