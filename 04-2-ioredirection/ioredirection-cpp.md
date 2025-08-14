
in 01, we printed some text to screen. in this lesson we will understand a little bit of what happened underneath. file descriptors and 3 process streams. stdin stdout stderr. demo them here

1. compile the program as `streams_demo`.

2. execute the program to understand how it works `./streams_demo`

Now lets learn about I/O redirection.

I/O redirection in bash allows you to control where input comes from and where output goes. Here are the basics:

Redirects stdout (standard output) to a file (overwrites):
```bash
./streams_demo > output.txt
```

Appends stdout to a file:
```bash
./streams_demo >> output.txt
```

2> Redirects stderr (standard error) to a file:
```bash
./streams_demo 2> error.txt
```

&> Redirects both stdout and stderr to a file:
```bash
./streams_demo &> all_output.txt
```

< Redirects stdin (standard input) from a file:
```bash
./streams_demo < input.txt
```

You can combine them as needed. For example, to redirect stdout to one file and stderr to another:
```bash
./streams_demo > out.txt 2> err.txt
```

TODO: explain ./lower < input.txt > output.txt (PGM 9 CD_Learn GNULinux.pdf)