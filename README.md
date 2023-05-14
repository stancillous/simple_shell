## Simple Shell
<h5>Project done by Philip and Raymond. An implementation of the linux shell.

Compile the program: 
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

```
Testing the program
<br>
in interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
in non interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
</h5>
HELLO
