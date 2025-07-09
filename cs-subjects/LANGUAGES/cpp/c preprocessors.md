preprocessor is a program, not a part of compiler.

done before compiler, text substitution tool

hash (#) -> preprocessor directives, compiler wont understand

#define , #include are some examples.

preprocessor will basically get all the content and include in the main file.

#define PI 3.14 -> replace all PI with 3.14 -> macro substitution.

now compiler will compile this gaint file with all of them included.

other files can also be included from local directory.

### define and undef

- `#define` is used to create macros or symbolic constants.
- `#undef` removes a previously defined macro.
- After `#undef`, the macro no longer has any meaning unless redefined.
- Helps avoid redefinition conflicts and allows conditional logic using macros.
