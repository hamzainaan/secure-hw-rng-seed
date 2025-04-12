# secure-hw-rng-seed

Generate a secure random seed using Intel's RDSEED instruction in C.  
Supports both 32-bit and 64-bit systems.

## Build

```bash
$ make
```

## Run

```bash
$ ./rdseed_secure
```

## Clean

```bash
$ make clean
```

## Notes

-   Requires a CPU that supports RDSEED.
-   To verify if your CPU supports the `RDSEED` instruction, you can use the `CPUID` command. Specifically, check bit 18 of the `EBX` register in the `CPUID` function 0x07. If this bit is set, your processor supports the `RDSEED` instruction.
    
-   May retry if entropy is not immediately available.
