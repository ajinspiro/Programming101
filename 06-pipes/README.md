pipe demonstration
pipe reads stdout from a command and writes it in stdin of the next command. this is repeated for all the commands in the pipe chain.

eg.
echo 1 | square | add 3 | cube | subtract 5

TODO: find more such commands/refine the following commands

ls -l | grep keyword

env | grep HOME

cat file.txt | sort | uniq

ps aux | grep python

dmesg | less

find . -type f | wc -l

history | tail -10
