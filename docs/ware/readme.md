# `xcc/ware`

A set of macros and structures to simplify and standardize the way to access **software/hardware** information.

## 
- **[Documents](#documents)**
- **[Overview](#overview)**

---
## Documents

- #### [Compiler](compiler.md) 
  Detect more than `26 compiler` (name, version) at compile/run time

---
## Overview

- #### Include
  ```cpp
  #include "xcc/ware.h"
  ```

- #### Possible Output
  > [**Try It**](https://godbolt.org/z/xYjdcTYTr) online on different platforms, compilers

  ```cpp
  ╔═══════════════════SOFTWARE═══════════════════╗
  ║ ┌─COMPILER─────────────────────────────────┐ ║
  ║ ├ name     ➜ "GNU C++"                     ┤ ║
  ║ ├ version  ➜ 12.1.0                        ┤ ║
  ║ ├ major    ➜ 12                            ┤ ║
  ║ ├ minor    ➜ 1                             ┤ ║
  ║ ├ patch    ➜ 0                             ┤ ║
  ║ ├ nversion ➜ 201392128                     ┤ ║
  ║ └──────────────────────────────────────────┘ ║
  ╚══════════════════════════════════════════════╝
  ```