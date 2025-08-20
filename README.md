dumb lang 🧠

A tiny esoteric programming language written in C.

Overview

dumb lang is a lightweight esoteric programming language and interpreter written in C.
It was built to explore low-level programming, interpreters, and language design.

Programs operate on a fixed-size memory tape and use single-character instructions for arithmetic, pointer movement, and I/O.

Features

  Interpreter written fully in C (no external deps)
  
  Fixed memory tape of 3000 integer cells
  
  Integer output (!) and ASCII output (c, with an offset)
  
  Integer input (i)
  
  Custom .dumb file extension with validation
  
  Basic error handling for invalid operators / file types
  
  Portable: compiles with gcc in seconds

Installation
git clone https://github.com/yourusername/dumb-lang.git
cd dumb-lang
gcc dumb.c -o dumb

Usage

Run the interpreter with a .dumb file:

./dumb program.dumb


View the built-in docs:

./dumb docs

Language Specification

Memory: array of 3000 signed integers, pointer starts at index 0.
ASCII printing: c prints cell_value + 32 as a character (so 0 → " ", 1 → "!", etc.).

Operator	Description
>	Move pointer right
<	Move pointer left
+	Increment current cell
-	Decrement current cell
!	Print current cell as integer
c	Print current cell as ASCII (value + 32)
n	Print newline
i	Read an integer into current cell
.	End program (exit)
1–9	Add that numeric value to current cell
_1–_9	Subtract that numeric value from current cell

Notes
• The digit 0 is not interpreted (only 1–9).
• Unknown characters (spaces/newlines) are ignored, so you can format your code.

Examples
Print “HI”

hi.dumb

```
9 9 9 9 4       c      # 36+4 = 40 → 40+32 = 72 = 'H'
> 9 9 9 9 5     c      # 36+5 = 41 → 41+32 = 73 = 'I'
n
.
```

Note: Comments are not supported

Run:

`
./dumb hi.dumb
`

Output:

`
HI
`

Echo an integer and its ASCII (simple I/O)

echo.dumb

`
i ! n c n .
`

Prompts for an integer input, prints it as a number, newline, then as ASCII (value + 32), newline.

Roadmap

  Loop constructs (e.g., [ and ])
  
  Dynamic tape growth
  
  Better error messages with line/column info
  
  String literals
  
  Optional “strict mode” to warn on unknown characters

Known Limitations

  No control flow yet (no loops/branches)
  
  Only single-digit increment/decrement literals (1–9, _1–_9)
  
  ASCII printing uses an offset of +32 by design

Author

Hamza Albanna

LinkedIn: https://linkedin.com/in/your-link

Codeforces: https://codeforces.com/profile/your-handle
