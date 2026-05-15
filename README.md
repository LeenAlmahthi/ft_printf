<div align="center">

````md
<div align="center">

```text
███████╗████████╗        ██████╗ ██████╗ ██╗███╗   ██╗████████╗███████╗
██╔════╝╚══██╔══╝        ██╔══██╗██╔══██╗██║████╗  ██║╚══██╔══╝██╔════╝
█████╗     ██║           ██████╔╝██████╔╝██║██╔██╗ ██║   ██║   █████╗
██╔══╝     ██║           ██╔═══╝ ██╔══██╗██║██║╚██╗██║   ██║   ██╔══╝
██║        ██║           ██║     ██║  ██║██║██║ ╚████║   ██║   ██║
╚═╝        ╚═╝           ╚═╝     ╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝   ╚═╝   ╚═╝
````

# ft_printf

**A complete reimplementation of the C standard `printf` function**

![Language](https://img.shields.io/badge/Language-C-blue?style=flat-square)
![School](https://img.shields.io/badge/School-42_Network-black?style=flat-square)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen?style=flat-square)
![Library](https://img.shields.io/badge/Output-libftprintf.a-orange?style=flat-square)

</div>

---

## What Is ft_printf?

`ft_printf` is a ground-up reimplementation of the classic C library function `printf`. Built as part of the **42 Network** curriculum, this project dives deep into how variadic functions work, how format strings are parsed, and how characters are written to standard output at the lowest level — one byte at a time.

No `printf`. No shortcuts. Just pure C.

---

## Supported Conversions

| Specifier | Description |
|:---------:|-------------|
| `%c` | Prints a single **character** |
| `%s` | Prints a **string** |
| `%p` | Prints a **pointer** address in hexadecimal |
| `%d` | Prints a **signed decimal integer** |
| `%i` | Prints a **signed integer** |
| `%u` | Prints an **unsigned decimal integer** |
| `%x` | Prints a number in **lowercase hexadecimal** |
| `%X` | Prints a number in **uppercase hexadecimal** |
| `%%` | Prints a literal **percent sign** |

---

## Getting Started

### Clone the repository

```bash
git clone https://github.com/LeenAlmahthi/ft_printf.git
cd ft_printf
```

### Compile the library

```bash
make
```

This produces `libftprintf.a` — a static library ready to link into any C project.

### Use it in your project

```bash
gcc your_file.c -L. -lftprintf -o your_program
```

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "world");
    ft_printf("Decimal: %d | Hex: %x | Pointer: %p\n", 42, 255, &main);
    return (0);
}
```

---

## Makefile Rules

| Rule | Action |
|------|--------|
| `make` / `make all` | Compile and build `libftprintf.a` |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and the library |
| `make re` | Full recompile from scratch |

---

## Project Structure

```
ft_printf/
├── ft_printf.c      # Core function — parses format string and dispatches conversions
├── ft_printf.h      # Header — prototypes and includes
├── fun.c            # Helpers: char, string, integer, unsigned integer
├── fun2.c           # Helpers: hexadecimal (lower/upper) and pointer
└── Makefile         # Build system
```

---

## How It Works

At its core, `ft_printf` walks through the format string character by character. When it encounters a `%`, it reads the next character to identify the conversion specifier, then calls the appropriate helper function. The return value tracks the **total number of characters printed**, matching the behavior of the real `printf`.

```
ft_printf("Score: %d", 42)
         │        │
         │        └─ Dispatch → ft_putnbr(42) → writes "42" → returns 2
         └─ Writes "Score: " → returns 7
                                              Total returned: 9
```

Variadic arguments are handled using `va_list`, `va_start`, `va_arg`, and `va_end` from `<stdarg.h>` — giving the function the ability to accept any number of arguments of any type.

---

## Key Concepts Practiced

- **Variadic functions** — handling unknown argument counts and types at runtime
- **String parsing** — iterating and dispatching based on format specifiers
- **Low-level output** — writing directly with `write()` system call
- **Static libraries** — compiling and archiving with `ar rcs`
- **Memory-safe C** — no leaks, no undefined behavior

---

## Author

**Leen Almahthi**
42 Login: `lalmahthi`
GitHub: [@LeenAlmahthi](https://github.com/LeenAlmahthi)

---

<div align="center">

*Built at 42 Network — where you learn by building everything yourself.*

</div>
