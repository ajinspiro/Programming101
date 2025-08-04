# Hello World

Let's learn how to make a computer say hello! We'll do this using a shell script (bash).

---

Bash is a simple way to tell your computer what to do using commands. The `echo` command prints text to the screen.

Try this in your terminal:
```bash
echo "Hello, bash"
```
You should see `Hello, bash` printed out.

Now, save this line in a file called `hello.sh`.

**Try to run it:**
```bash
./hello.sh
```
You might see an error: `Permission denied`. That's normal!

---

### How to Run Scripts in Linux

Linux doesn't run scripts just because they end with `.sh`. You need to do one of these:

1. Run it with bash:
   ```bash
   bash ./hello.sh
   ```
2. Make it executable:
   - Add the following "shebang" as the first line in `hello.sh`:
     ```bash
     #!/bin/bash
     ```
   - Give it permission to execute:
     ```bash
     chmod +x ./hello.sh
     ```
   - Now execute it:
     ```bash
     ./hello.sh
     ```

You should see the output now!

---

Feel free to ask questions or search online if you're curious about anything, like what "shebang" means.

Happy coding!