# `xcc/ware/compiler`

Detect more than 26 compiler (name, version) at compile/run time.

##

- **[Overview](#overview)**
- **[API](#api)**

---

## Overview

- ##### Access The Compiler Information

  ```cpp
  // ✤ using predefined macros
  XCC_COMP                                    // ➜ "GCC"
  XCC_COMP_VER_MAJ                            // ➜ 12
  XCC_COMP_VER_MIN                            // ➜ 1
  XCC_COMP_VER_PAT                            // ➜ 0
  XCC_COMP_VER_NRM                            // ➜ 201392128

  // ✤ using structures
  xcc::ware::compiler::name;                  // ➜ "GCC"
  xcc::ware::compiler::major                  // ➜ 12
  xcc::ware::compiler::minor                  // ➜ 1
  xcc::ware::compiler::patch                  // ➜ 0
  xcc::ware::compiler::nversion               // ➜ 201392128
  xcc::ware::compiler::version()              // ➜ "12.1.0"
  ```

- ##### Preprocessor Guards

  ```cpp
  // ✤ check for specific compiler
  #ifdef XCC_COMP_<ID>

  // ✤ check for specific compiler version
  #if XCC_COMP_VER_FORM >= XCC_MAKE_VER_FORM(major,minor,patch)
  ```

## API

### Structure

> inside namespace: `xrx::ware`

| Member                | Returns               | Value Type             | Constexpr |
| --------------------- | --------------------- | ---------------------- | --------- |
| `compiler::name`      | `XCC_COMP`            | constant c-string      | YES       |
| `compiler::major`     | `XCC_COMP_VER_MAJ`    | constant std::uint64_t | YES       |
| `compiler::minor`     | `XCC_COMP_VER_MIN`    | constant std::uint64_t | YES       |
| `compiler::patch`     | `XCC_COMP_VER_PAT`    | constant std::uint64_t | YES       |
| `compiler::nversion`  | `XCC_COMP_VER_NRM`    | constant std::uint64_t | YES       |
| `compiler::version()` | `"major.minor.patch"` | std::string            | NO        |

### Macros

- #### General

  > All macros here is Always-Defined

  | Macro              | Returns                        | Value Type             |
  | ------------------ | ------------------------------ | ---------------------- |
  | `XCC_COMP`         | compiler name in shortest form | constant c-string      |
  | `XCC_COMP_VER_MAJ` | compiler major version         | constant std::uint64_t |
  | `XCC_COMP_VER_MIN` | compiler minor version         | constant std::uint64_t |
  | `XCC_COMP_VER_PAT` | compiler patch version         | constant std::uint64_t |
  | `XCC_COMP_VER_NRM` | compiler normalized version    | constant std::uint64_t |

- #### ID's

  > Only one macro will be defined if available, otherwise you will warned

  | Macro                   | `XCC_COMP` value                        |
  | ----------------------- | --------------------------------------- |
  | `XCC_COMP_CUDA`         | `"NVIDIA CUDA C++"`                     |
  | `XCC_COMP_GCC_XML`      | `"GCC XML"`                             |
  | `XCC_COMP_CRAY`         | `"Cray C"`                              |
  | `XCC_COMP_COMO`         | `"Comeau C++"`                          |
  | `XCC_COMP_PATHCC`       | `"PathScale EKOPath"`                   |
  | `XCC_COMP_ICX`          | `"Intel ICX"`                           |
  | `XCC_COMP_ICC`          | `"Intel ICC"`                           |
  | `XCC_COMP_CLANG`        | `"Clang"`                               |
  | `XCC_COMP_DMC`          | `"Digital Mars"`                        |
  | `XCC_COMP_DCC`          | `"Diab C/C++""`                         |
  | `XCC_COMP_PGI`          | `"Portland Group C/C++"`                |
  | `XCC_COMP_GCC`          | `"GNU C++"`                             |
  | `XCC_COMP_KCC`          | `"Kai C++"`                             |
  | `XCC_COMP_SGI`          | `"SGI MIPSpro C++"`                     |
  | `XCC_COMP_COMPAQ`       | `"Compaq C/C++"`                        |
  | `XCC_COMP_GHS`          | `"Green Hill C/C++"`                    |
  | `XCC_COMP_CODEGEARC`    | `"CodeGear"`                            |
  | `XCC_COMP_BORLANDC`     | `"Borland C++"`                         |
  | `XCC_COMP_MWERKS`       | `"Metrowerks CodeWarrior"`              |
  | `XCC_COMP_SUNPRO`       | `"Oracle Solaris Studio"`               |
  | `XCC_COMP_HPACC`        | `"HP aC++"`                             |
  | `XCC_COMP_MRC`          | `"MPW C++"`                             |
  | `XCC_COMP_IBMXL_ZOS`    | `"IBM z/OS XL C/C++"`                   |
  | `XCC_COMP_IBMXL_CLANG`  | `"IBM XL C/C++ (Clang-based versions)"` |
  | `XCC_COMP_IBMXL_LEGACY` | `"IBM XL C/C++ (legacy versions)"`      |
  | `XCC_COMP_MSC`          | `"Microsoft Visual C++"`                |
  | `XCC_COMP_NONE`         | `"Unknown"`                             |

---

### Notes

- To disable the warning that occurs when compiler detection fails define the following macro:

  ```cpp
  #define XCC_OPT_FORCED_WARNINGS 0 // value (0) is required to disable this option
  ```
