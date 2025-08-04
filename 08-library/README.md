Static library (Position dependency)
    pros, cons
    Demonstrate position dependency using program.
Dynamic library (Position independent code)
    pros, cons
    Demonstrate position independency using program.

TODO: figure out how to demonstrate the difference in fixed position instructions
and position independent instructions. 
demonstrate using asm. 

```asm
mov    0x60104c,%eax     ; absolute memory address
```

```asm
lea    0x2e(%rip),%rax   ; RIP-relative addressing
```