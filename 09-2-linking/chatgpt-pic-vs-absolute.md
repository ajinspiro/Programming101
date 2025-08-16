Great question! To **see the difference between fixed-position (absolute) and position-independent (relative) instructions**, you’ll need to inspect how instructions are **encoded** and **what kinds of addresses they use** in your binary. You can do this using tools like:

* `readelf`
* `objdump`
* `file`
* `nm`

---

## 🧠 Crash Course: Fixed vs Position-Independent Code (PIC)

| Feature            | Fixed-Position Code | Position-Independent Code (PIC) |
| ------------------ | ------------------- | ------------------------------- |
| Code Addressing    | Absolute            | Relative                        |
| Reusable in memory | ❌ No                | ✅ Yes                           |
| Used in            | Executables         | Shared Libraries (`.so`)        |

---

## 🛠️ Compile with and without PIC

### 1. Fixed-Position Example (default for executables):

```bash
clang++ -no-pie -fno-pic test.cpp -o fixed
```

### 2. Position-Independent Example:

```bash
clang++ -fPIC -shared test.cpp -o pic.so
```

Or make a PIE executable:

```bash
clang++ -fPIC -pie test.cpp -o pic_exec
```

---

## 🔍 Inspect the Binary

### 1. Use `file` to confirm type

```bash
file fixed
# → ELF 64-bit LSB executable, not dynamically linked, no PIE

file pic_exec
# → ELF 64-bit LSB PIE executable (Position-Independent Executable)
```

---

### 2. Use `readelf` or `objdump` to inspect instructions

```bash
objdump -d fixed > fixed.asm
objdump -d pic_exec > pic.asm
```

Now inspect the assembly. You’ll notice:

### 🔒 Fixed Binary:

```asm
mov    0x60104c,%eax     ; absolute memory address
```

### 🧳 PIC Binary:

```asm
lea    0x2e(%rip),%rax   ; RIP-relative addressing
```

* `RIP` = instruction pointer (used in x86\_64 for relative addressing)
* `lea ...(%rip)` = position-independent access

---

### 3. View Relocations

Position-independent code relies on **relocation tables** more than fixed binaries:

```bash
readelf -r pic_exec
```

---

## ✅ Summary

| Tool         | What to Look For                                 |
| ------------ | ------------------------------------------------ |
| `file`       | Whether it's PIE or not                          |
| `objdump -d` | Absolute vs RIP-relative instructions            |
| `readelf -r` | Relocations used                                 |
| `nm`         | Symbol addresses (if fixed, they’ll be absolute) |

---

Would you like to try with a minimal `test.cpp` source and compare both binaries step by step?
