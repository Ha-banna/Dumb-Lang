# dumb lang 🧠

*A tiny esoteric programming language written in C.*

---

## 🚀 Overview

**dumb lang** is a lightweight esoteric programming language and interpreter written in C.
It was built to explore **low-level programming, interpreters, and language design**.

Programs operate on a fixed-size memory tape and use single-character instructions for arithmetic, pointer movement, and I/O.

---

## ✨ Features

* 📝 Written fully in **C** (no external dependencies)
* 📦 Fixed memory tape of **3000 integer cells**
* 🔢 Integer output (`!`) and ASCII output (`c`, with offset)
* ⌨️ Integer input (`i`)
* 📂 Custom `.dumb` file extension with validation
* ⚠️ Basic error handling for invalid operators / file types
* ⚡ Portable: compiles with `gcc` in seconds

---

## ⚙️ Installation

```bash
git clone https://github.com/yourusername/dumb-lang.git
cd dumb-lang
gcc dumb.c -o dumb
```

---

## ▶️ Usage

Run the interpreter with a `.dumb` program:

```bash
./dumb program.dumb
```

View the built-in docs:

```bash
./dumb docs
```

---

## 📖 Language Specification

**Memory:** Array of 3000 signed integers (pointer starts at index `0`).
**ASCII printing:** `c` prints `cell_value + 32` as a character (so `0 → " "`, `1 → "!"`, etc.).

| Operator | Description                                       |
| -------- | ------------------------------------------------- |
| `>`      | Move pointer right                                |
| `<`      | Move pointer left                                 |
| `+`      | Increment current cell                            |
| `-`      | Decrement current cell                            |
| `!`      | Print current cell as integer                     |
| `c`      | Print current cell as ASCII (`value + 32`)        |
| `n`      | Print newline                                     |
| `i`      | Read integer input into current cell              |
| `.`      | End program (exit)                                |
| `1–9`    | Add numeric value directly to current cell        |
| `_1–_9`  | Subtract numeric value directly from current cell |

**Notes:**

* `0` is ignored (only `1–9` are valid digits).
* Unknown characters (spaces/newlines) are ignored → you can format code for readability.

---

## 💡 Examples

### Print “HI”

**hi.dumb**

```dumb
9 9 9 9 4   c     # (36+4)+32 = 72 → 'H'
> 9 9 9 9 5 c     # (36+5)+32 = 73 → 'I'
n
.
```

> ⚠️ Note: Comments are **not supported** — they are added here just for illustration.

Run:

```bash
./dumb hi.dumb
```

Output:

```
HI
```

---

### Echo an integer and its ASCII

**echo.dumb**

```dumb
i ! n c n .
```

Behavior:

* Prompts for integer input
* Prints it as a number → newline → its ASCII (`value + 32`) → newline

---

## 🛣️ Roadmap

* 🔄 Loop constructs (`[` and `]`)
* 📈 Dynamic tape growth
* 🛑 Better error messages (line/column info)
* 📝 String literals
* ⚙️ Optional “strict mode” for warnings on unknown characters

---

## ⚠️ Known Limitations

* ❌ No control flow yet (no loops/branches)
* 🔢 Only single-digit increments/decrements (`1–9`, `_1–_9`)
* 🔤 ASCII printing uses a fixed offset of `+32`

---

## 👤 Author

**Hamza Albanna**

* [LinkedIn](https://linkedin.com/in/your-link)
* [Codeforces](https://codeforces.com/profile/your-handle)

