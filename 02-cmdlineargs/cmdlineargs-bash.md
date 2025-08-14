# Command line arguments

Bash scripts like the "hello world" example we wrote earlier are simple and useful, but they don't let the user give any input. Most real scripts become more helpful when they can take information from the user, do something with it, and then show a result. For example, Uber asks for your account info and location to find a taxi nearby.

There are different ways a script can get input from the user. In this lesson, we'll learn about command line arguments.

Below is a simple bash script that parses command line arguments and prints them. We will use the `$#` to get the command line argument count and `$@` to access the command line arguments themselves. Save it as `cmdlineargs.sh`:

```bash
#!/bin/bash

echo "Argument count: $#"
echo "Program name: $0"

if [ $# -lt 1 ]; then
    echo "No additional arguments provided."
    exit 0
fi

echo "Arguments:"
for arg in "$@"; do
    echo -e "\t$arg"
done
```

**Try making the script executable yourself. Take a peek at hello-bash.md if necessary.**

**Try running the script in the following ways**
```bash
./cmdlineargs
```
```bash
./cmdlineargs 123
```
```bash
./cmdlineargs apple orange 223
```

### Accessing Command Line Arguments using their positions 

It is possible to access the command line arguments using their position. Let's see that in action.

```bash
#!/bin/bash

echo "Number of arguments: $#"
echo "First argument (\$1): $1"
echo "Second argument (\$2): $2"
echo "Third argument (\$3): $3"
# You can continue with $4, $5, etc., as needed
```

It's possible to check if a positional command line variable is defined and if not use a default value. 
Try that out as an exercise.

Happy coding!