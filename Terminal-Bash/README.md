# The 50 Most Popular Linux & Terminal Commands

This is my summary of the 5-hour long FreeCodeCamp course about popular Unix-like systems terminal commands.

## Find name of user using the system

```bash
$ whoami
arfanzubi
```

## Manual pages

Shows manual for a specific command. For example `man whoami` shows all the information about the `whoami` command.

```bash
$ man <command>
```

## Clear terminal screen

```bash
$ clear
```

Or press <kbd>CTRL</kbd> + <kbd>L</kbd>.

### Clear terminal preserving history

```bash
$ clear -x
```

## Print working directory

Prints the current directory you are in.

```bash
$ pwd
/Users/arfanzubi/Desktop
```

## List contents of a folder

```bash
$ ls
```

To show contents of a subfolder in the current directory:

```bash
$ ls Files/
```

You can also list contents of a folder in **a different directory** without switching directory:

```bash
$ ls /Users/arfanzubi/Desktop
```

Directories starting with `/` are **full paths.**

### List contents in long format

```bash
$ ls -l
```

### List all files (including secret files starting with `.`)

```bash
$ ls -a
```

You can also combine commands like this:

```bash
$ ls -la
```

## Change directory

Change the shell working directory.

```bash
$ Desktop/
```

### Go up a directory

```bash
$ cd ..
```

### Go up any directories

```bash
$ cd ../../..
```

### Go to any directory with full path

```bash
$ cd /Users/arfanzubi/Desktop
```

### Go directly to home directory

```bash
$ cd ~
```

or simply:

```bash
$ cd
```

### Go to `root` from any directory

```bash
$ cd /
```

| Symbol | Directory |
| ------ | --------- |
| /      | root      |
| ~      | home      |

## Make directories

Creates a new folder in the _current working directory_.

```bash
$ mkdir test-folder
```

Or create multiple folders at once:

```bash
$ mkdir folder1 folder2 folder3
```

You can also create folders in a subdirectory:

```bash
$ mkdir ~/Desktop/desktop-folder
```

This creates a folder named `desktop-folder` in the desktop directory.

### Create folders and subfolders using `-p` flag

If we wanted to create a folder named `test-folder` in the desktop and this folder should contain another folder `test` we can do it in one command with the `-p` flag:

```bash
$ mkdir -p ~/Desktop/test-folder/test
```

This creates any folder that does not exists yet in the provided path.

## Create files

Create empty file with the `touch` command:

```bash
$ touch file.c
```

Again we can also create multiple files at once:

```bash
$ touch file1.c file2.pdf file3.txt
```

## Remove _empty_ folders

Remove _empty_ folder(s) from a directory:

```bash
$ rmdir folder
```

## Remove files

You can remove a files or multiple files by using the `rm` command:

```bash
$ rm file1 file2
```

### To see details use the `-v` flag for verbose output

```bash
$ rm -v file1 file2
```

## Remove directories with content

Use the `-r` flag (for _recursive_) to remove a folder that is NOT empty:

```bash
$ rm -r folder
```

### Remove files in a folder interactively

Using the `-i` flag, the shell asks for permission to delete files one-by-one and expects user input:

```bash
$ rm -ri folder
```

## The `open` command

If you want to _open_ a file you can use the `open` command and the system will open the specific file in an application supporting the file type.

```bash
$ open file.pdf
```

To open the current directory in a GUI do this:

```bash
$ open .
```

The `open` command is found on OS X systems. On Linux you can do:

```bash
$ xdg-open file.pdf
```

## Move / rename files

### Rename file name

```bash
$ mv fil.pdf file.pdf
```

### Change location of a file

```bash
$ mv file.pdf Files/
```

The file `file.pdf` has been moved to the `Files/` directory.

You can also move multiple files and folders:

```bash
$ mv file.pdf test-folder Files/
```

Or move it back one directory:

```bash
$ mv file.pdf ../
```

## Copy files and folders

```bash
$ cp file.pdf file-copy.pdf
```

### Copy directories

To copy folders use the recursive `-r` flag:

```bash
$ cp -r Files/ ~/Desktop/Files
```

This command copies the `Files/` folder to the desktop preserving the same name.

## Print `head` or `tail` of a file

### `head`

Using the `head` command it will output the first _10_ lines of a file:

```bash
$ head text-file.txt
```

But we can specify the number of lines we want to be in the output:

```bash
$ head -n 100 text-file.txt
```

### `tail`

The `tail` command does the exact opposite of `head`: It print the last ten lines:

```bash
$ tail -n 20 text-file.txt
```

If you want to track a file so it gives a live preview if anything changed in the file like a log you can use:

```bash
$ tail -f log-file.txt
```

## Print the current date

```bash
$ date
```

## Redirecting standard output

Instead of printing the output of a command to the terminal you can also output in a file for example.

```bash
$ date > file.txt
```

This will redirect the ouput of the `date` command to `file.txt`.

Note that if we redirect standard output, the destination file will be **overwritten**.

To _append_ the output do this:

```bash
$ date >> file.txt
```

If the destination file does not exists it will be created automatically.

Another useful example of redirecting:

```bash
$ ls -l > contents
```

## Print contents of file

### `cat`

```bash
$ cat contents
```

Or print multiple files:

```bash
$ cat file1.txt file2.txt
```

Let's suppose we have three files `butcher.txt`, `feedstore.txt`, `groceries.txt` and we want to create one single list out of them. We can use the con**cat**inate commant `cat` to do this:

```bash
$ cat butcher.txt feedstore.txt groceries.txt > shopping-list.txt
```

Get line numbers with the `-n` flag:

```bash
$ cat -n file.txt
```

### `less`

Print files in a better interface for reading.

```bash
$ less file.txt
```

To exit press <kbd>Q</kbd>.

## The `echo` command

The `echo` command does one simple job: it prints to the output the argument passed to it.

```bash
$ echo "Hello, world!"
Hello, world!
```

You can also output the echo to a file:

```bash
$ echo "USERNAME:3RFAN" > config.txt
```

In `config.txt` there will be one line which is "USERNAME:3RFAN".

## Word Counting

To find out how many lines are in a file:

```bash
$ wc lyrics.txt
1757 15767 87022 lyrics.txt
```

| Number | Description     | Flag            |
| ------ | --------------- | --------------- |
| 1757   | Number of lines | `-l`, `--lines` |
| 15767  | Number of words | `-w`, `--words` |
| 87022  | Number of bytes | `-c`, `--bytes` |

## Piping

Through piping we can take the output of one command and pass it as an input to the second command.

Let's find out how many files and folders are in a directory by piping:

```bash
$ ls -la | wc -l
```

Above we had an example of three different shopping lists. Let's take `butcher.txt` and `groceries.txt` and find out how many things we need to buy:

```bash
$ cat groceries.txt butcher.txt | wc
9 15 95
```

We can even output the output of the two piped commands to a new file:

```bash
$ cat groceries.txt butcher.txt | wc -l > shopping-list-length.txt
```

## Sorting

The `sort` command sorts the elements in a file and outputs it to the terminal. _It will not modify the file passed as input, it will simply output a sorted version of the passed file_!

```bash
$ sort file.txt
```

It is also case-senstive and capital letters preceed lower letters.

### Numeric sorts

Use the `-n` flag to sort numerically:

```bash
$ sort -n numbers.txt
```

Or in descending order:

```bash
$ sort -nr numbers.txt
```

### Remove duplicates

To keep only unique values in a file use the `-u` flag:

```bash
$ sort -nu numbers.txt
```

If there was a duplicate it would be removed.

Let's suppose we have a file of numbers and we want to find out how many _unique_ numbers are in that file:

```bash
$ sort -nu numbers.txt | wc -l
```

## The `uniq` command

Most likely used with the `sort` command. It reports or omits repeated lines.

```bash
$ uniq file.txt
```

When used like this it will only remove _adjecent_ duplicate values!

So it should mostly be used together with the `sort` command:

```bash
$ sort file.txt | uniq
```

If we wanted to print out the words that have duplicates we can do this:

```bash
$ sort file.txt | uniq -d
```

To display only non-duplicate lines we can use the `-u` flag:

```bash
$ sort file.txt | uniq -u
```

### Count Duplicates

To see a count of how many duplicates each word has in a file use the `-c` flag:

```bash
$ sort file.txt | uniq -c
```

Putting it all together we can sort a list using `sort` then pipe it to `uniq -c` to get the counts of the duplicates and then pipe it again to sort it according to the count of the duplicates:

```bash
$ sort file.txt | uniq -c | sort -nr
```

## Expansions

There are special characters and syntax that the shell will interpret and expand into some other value.

For example:

```bash
$ echo ~
/Users/arfanzubi
```

If we wanted to print the character `~` we have to do it like this:

```bash
$ echo '~'
~
```

### Environment Variables

| Var    | Description                                                 |
| ------ | ----------------------------------------------------------- |
| $PATH  | Directories currently configured in system's $PATH variable |
| $USER  | Name of the current user                                    |
| $SHELL | Path to the currently used shell                            |

### The star variable

The star variable will match anything.

```bash
$ echo *
```

Will output anything in that directory.

If we only wanted `.txt` files we can do it like this:

```bash
$ ls -l *.txt
```

### The question mark variable

The question mark will match any single character.

```bash
$ echo *.??
```

This means we search for a file that ends with a dot and 2 characters.

### Curly Braces

Curly braces group together some values.

For example we wanted to create three files named `a.txt`, `b.txt`, `c.txt`:

```bash
$ echo {a, b, c}.txt
a.txt b.txt c.txt
```

Or something more useful:

```bash
$ touch app.{js, html, css, py}
app.js app.html app.css app.py
```

This also works with numbers:

```bash
$ echo Day{1..5}
Day1 Day2 Day3 Day4 Day5
```

## Find Difference between two Files

The `diff` command will process files and output the differences between them.

```bash
$ diff file1.txt file2.txt
24a25
```

The output of `24a25` means in `file1.txt` line 24, line 25 was added (`a`).

If we switch the file names the output will be the opposite:

```bash
$ diff file2.txt file1.txt
25d24
```

### See files side-by-side

Using the `-y` flag will compare the 2 files line by line:

```bash
$ diff -y file1.txt file2.txt
```

### Git-style output

To see the differences in a style which is familiar if you use Git we can add the `-u` flag:

```bash
$ diff -u file1.txt file2.txt
```

## The `find` command

The `find` command can be used to find files or folders matching a particular search pattern. It search _recursively_.

If we want to find files or directories we need to provide a location in which to search for:

```bash
$ find . -name '*.js'
```

Let's suppose we want to find all files and folders on the desktop containing in their names the number 7:

```bash
$ find ~/Desktop -name '*7*'
```

Or find all _C_ files:

```bash
$ find . -name '*.c'
```

### Find by Type

Find only directories (`-type d`):

```bash
$ find . -type d
```

Or find only files:

```bash
$ find . -type f
```

Combining the two would be something like this:

```bash
$ find . -type d -iname '*E*'
```

The `-i` flag before the `-name` flag makes the search _case insensitive_.

### Logic

We can also use some logical operators for searching files and directories:

```bash
$ find . -name 'E*' -or -name 'F*'
```

This finds files and directories that start with capital letters E or F.

### Sizes

Search files that have more than 100 chars (bytes) in them:

```bash
$ find . -type f -size +100c
```

Search files bigger than 100KB but smaller than 1MB:

```bash
$ find . -type f -size +100k -size -1M
```

### Modification Time

Search files edited more than 3 days ago:

```bash
$ find . -type f -mtime +3
```

Search files edited in the last 24 hours:

```bash
$ find . -type f -mtime -1
```

### The `-exec` Flag

It is even possible with `find` to execute a command on each result of the search.

```bash
$ find . -type f -exec cat {} \;
```

The `\;` is for termination and `{}` is filled with the file name at execution time.

## The `grep` command

The `grep` finds text inside files, while the `find` command finds files/directories.

The first argument passed to the `grep` command is the string/regex we want to search for and the second is a document.

```bash
$ grep document.getElementById index.md
```

### Get Line Numbers

`grep` is even more useful if we knew on which line our search results occured. For this try the `-n` flag:

```bash
$ grep -n text file.txt
```

### Context

To view 2 lines before and 2 lines after the search result you can use the uppercase `-C` flag:

```bash
$ grep -nC 2 text file.txt
```

### Search Recursively

To search in a nested directory use the `-r` flag:

```bash
$ grep -r "regex" .
```

You can also search case insensitive:

```bash
$ grep -ri "regex" .
```

Let's see an example where we search for mail addresses in our home directory:

```bash
$ grep -rE -o "\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,6}\b" ~
```

## Disk Usage

`du` let's you find sizes of files and directories on the machine. It searches recursively.

The command without arguments will print the sizes of all files and folders in the current directory.

At the button there is the size of the whole directory marked with a dot (`.`).

You can also use these flags to print out in different values:

| Flag | Description      |
| ---- | ---------------- |
| `-h` | "Human-readable" |
| `-m` | megabytes        |
| `-g` | gigabytes        |

```bash
$ du -h .
```

To find largest five directories on the desktop:

```bash
$ du -h ~/Desktop | sort -h | tail -n 5
```

The above command is similar to the following. Here we sort in reverse order and pipe it to the `head` command:

```bash
$ du -h ~/Desktop | sort -hr | head
```

## Display free disk space

Shows how much free space is on the system.

`-h` stands, as above, for "human-readable".

```bash
$ df -h
```

We can also pass directories as arguments:

```bash
$ df -h ~/Desktop
```

## Lookup Terminal History

`history` will show the history of all executed commands:

```bash
$ history
```

Next to the various commands you find a number. You can use this number to access the command and execute it:

```bash
$ !2064
```

A usual way to open `history` is through piping to `less`:

```bash
$ history | less
```

You can also combine `grep` with `history`:

```bash
$ history | grep 'cookie'
```

## Processes

Inspect processes running on the computer. `ps` stand for "process status".

`ps` without flags or arguments will show processes initiated by the user:

```bash
$ ps
```

To show all the processes, _not only the ones initiated by the user_:

```bash
$ ps ax
```

Note that there is no word-wrapping in the output, so the results may be incomplete.

To use word-wrapping use:

```bash
$ ps axww
```

### Find Processes

You can find processes using `grep`:

```bash
$ ps axww | grep "Visual Studio"
```

## The `top` Command

`top` shows us the most (top) memory-intensive or CPU-intensive processes:

```bash
$ top
```

To sort numbers in order of how much memory the processes take up:

```bash
$ top -o mem
```

## The `kill` command

Processes on UNIX-like systems can receive signals and react to them. The `kill` program can send a variety of signals to a program.

To see available signals:

```bash
$ kill -l
```

The main syntax is:

```bash
$ kill <PID>
```

Where `PID` stands for "Process ID".

We can use flags to send other signals, including:

```bash
$ kill -HUP <PID>
$ kill -INT <PID>
$ kill -KILL <PID>
$ kill -TERM <PID>
$ kill -CONT <PID>
$ kill -STOP <PID>
```

## The `killall` Command

The `killall` command kills processes selected by name, as opposed to the selection by PID as done by `kill`.

```bash
$ killall -KILL node
```

## Running Things in the Background or Foreground

Let's see an example command that finds all the files on the entire system (`root` directory) that changed in the last 24 hours (1day) and save it in a `.txt` file called `allchanges.txt`:

```bash
$ find / -ctime -1 > allchanges.txt
```

This is going to take a lot of time as it is running in the foreground.

When we now press <kbd>CTRL</kbd> + <kbd>Z</kbd> then the command will stop running.

Now we can check it with the `jobs` command:

```bash
$ jobs
[1]+  Stopped       find / -ctime -1 > allchanges.txt
```

### `fg` - Foreground

To resume a job we can use the `fg` command:

```bash
$ fg 1
find / -ctime -1 > allchanges.txt
```

### `bg` - Background

If we want to run a command in the background, we use `bg`:

```bash
$ bg 1
[1]+ find / -ctime -1 > allchanges.txt &
```

The `&` sign shows that it is a background job that is running.

### The `sleep` Command

The `sleep` command pauses output for a number of seconds:

```bash
$ sleep 2
```

We can run it also in the background

```bash
$ sleep 50 &
```

## Compressing Files

We can compress (or "enzip") files in UNIX-like systems using `gzip`:

```bash
$ gzip file
```

**ATTENTION:** Doing it like this will compress the file and overwrite it, meaning you only have the compressed file on the system after the process is done and the original is gone!

If you want to _keep_ the original file use the `-k` flag:

```bash
$ gzip -k file
```

Use the `-v` flag (verbose) to see how much the size has been reduced in percent.

```bash
$ gzip -kv file
```

### Unzipping files

To "unzip" or _decompress_ ZIP files use the `-d` flag:

```bash
$ gzip -d zip-file.gz
```

But you can also use the `gunzip` command:

```bash
$ gunzip zip-file.gz
```

## Enzipping Multiple Files with `tar`

The `tar` command is used to create an archive, grouping multiple files in a single file.

```bash
$ tar -cf archive.tar file1 file2
```

The `-c` option stands for _create_. The `-f` option is used to provide the filename.

Notice: The archive is NOT compressed yet. It is just a single file holding all the files provided as arguments in the command above!

### Extract Files from Archive

To unarchive or extract the files from an archive (`.tar` file):

```bash
$ tar -xf archive.tar
```

The `-x` option stands for _extract_.

To extract to a specific directory use:

```bash
$ tar -xf archive.tar -C directory
```

To view what's in the archive use the `-t` file:

```bash
$ tar -tf archive.tar
file1
file2
```

### Compress when creating Archive

To compress directly when creating an archive use the `-z` flag:

```bash
$ tar -czf archive.tar.gz file1 file2
```

## The `nano` Text Editor

I won't cover this as I'm using **VIM**, a more powerful text editor.

## Aliases

We can define an `alias` to create shortcuts for frequently used commands.

```bash
$ alias la='ls -la'
```

**Note:** The `alias` created in the way of above command will only be accessible in the instance it has been declared. When you open a new terminal it won't be present there.

If you want to persist the aliases you have to modify the terminal profile of your OS.

On Mac we can modify the `.zshrc` file:

```bash
$ vim ~/.zshrc
```

When we have updated the `.zshrc` file we can go back to the terminal window and input:

```bash
$ source .zshrc
```

The changes are now in effect and we can use the `alias`.

## The `xargs` command

`xargs` takes the output of one command and turn into arguments for a second command.

Let's suppose we have a folder `Games/` with 12 players in it (`Player1.txt`, ..., `Player12.txt`) and a file `deadPlayers.txt`.

In the file `deadPlayers.txt` are some players that died so we have to remove them from the list of players in the `Games/` folder.

```bash
$ cat deadPlayers.txt | xargs rm
```

Here we provide the `rm` command the arguments through piping a list of players that need to be removed.

One more example using the `find` command:

```bash
find . -size +1M | xargs ls -l
```

We only see files in the current working directory with size bigger than 1MB and print them out using long format.

## Create Links using `ln`

The `ln` command in UNIX-like systems is used to create links. A link in Linux is like a pointer to another file. A file that points to another file, like Windows shortcuts.

### Hard Links

With a hard link we create a file that stays in sync with another file. But still we DON'T create a copy of a file. It is only a pointer to a file.

```bash
$ ln original.txt hardlink.txt
```

We created a hard link that points to the file `original.txt`. If we modify `original.txt` the changes will be shown in `hardlink.txt` too and vice versa.

If we delete `original.txt`, `hardlink.txt` will still persist as it continues to point to the data in memory.

### Symbolic / Soft Links

To create a _symbolic_ link we use the `-s` flag:

```bash
$ ln -s original.txt symlink.txt
```

The difference to a hard link is that when we delete the original file, the symbolic link won't work. Because the symbolic link only _points_ to the original file, while the hard link points directly to the values in memory!

## Users & Groups

On UNIX-like systems, many users can use the same machine. Here permissions play a big role to regulate who can read, modify and execute data.

### The `who` Command

The `who` command shows every seperate instance of a terminal listed with the login date:

```bash
$ who
arfanzubi console  Jun 27 22:09
arfanzubi ttys001  Jun 27 22:10
arfanzubi ttys002  Jun 27 23:18
arfanzubi ttys003  Jun 27 23:18
arfanzubi ttys004  Jun 27 23:18
```

### The `su` Command

With the `su` command we can _switch users_ directly in the terminal.

```bash
$ su <username>
```

To login and switch directly to the home directory of the new user use the `-` or the `-l` flag:

```bash
$ su - <username>
$ su -l <username>
```

### Superuser

`sudo` is commonly used to run a command as root. Root has full permission of all possible actions on the system.

To modify the file in `/etc/hosts` we must prefix the `sudo` command:

```bash
$ sudo vim /etc/hosts
```

Generally, commands that have an effect on _all_ users need `sudo` rights.

### The `passwd` Command

With the `passwd` command you can change the password.

To change your own password:

```bash
$ passwd
```

To change someone else's password (only if you have `root` permissions):

```bash
$ sudo passwd <username>
```

### The `chown` Command

The `chown` or _change ownership_ command let's us change who owns particular files or directories.

Every file and directory has its owner.

The syntax is:

```bash
$ chown <owner> <file>
```

For example:

```bash
$ sudo chown arfanzubi Documents/
```

To change the ownership of all the files in a folder recursively use the `-R` flag:

```bash
$ chown -R <owner> <file>
```

### Groups

If we `ls -l` in a directory we get the owner of the file/directory and next to that we find the group. A group can have special rights, like only reading files.

To see which groups you belong to:

```bash
$ groups
```

To change the group:

```bash
$ sudo chown <user>:<group> <file>
```

## Permissions

When listing a directory in long format the first things we see are some bizarre looking letters:

```bash
drwxr-xr-x
drwxr-xr-x
-rw-r--r--
...
```

**Index 0**

| Symbol | Desc                   |
| ------ | ---------------------- |
| \-     | regular file           |
| d      | directory              |
| c      | character special file |
| l      | symbolic link          |

**Index 1 - 3, 4 - 6, 7 - 9**

Index 1 - 3: Owner: `rw-`

Index 4 - 6: Group: `rw-`

Index 7 - 9: World: `r--`

**Effect on Files:**

| Symbol | Meaning       | Desc                                            |
| ------ | ------------- | ----------------------------------------------- |
| r      | Read          | file can be read                                |
| w      | Write         | file can be modified                            |
| x      | Execute       | file can be treated as a program to be executed |
| \-     | No Permission | file cannot be read, modified or executed       |

**Effect on Directories:**

| Symbol | Meaning       | Desc                                                          |
| ------ | ------------- | ------------------------------------------------------------- |
| r      | Read          | directory's contents can be listed                            |
| w      | Write         | directory's contents can be modified (needs x rights too)     |
| x      | Execute       | allows a directory to be entered or `cd`ed into               |
| \-     | No Permission | directory contents cannot be shown, modified or switched into |

## Change Permissions

To change the permissions of a file or directory, we can use the `chmod` or _change mode_ command.

The basic syntax is:

```bash
$ chmod <mode> <file>
```

1. We specify the "who" using the following values:

- **u** - user (owner of the file)
- **g** - group (members of the group the file belongs to)
- **o** - others (everyone else)
- **a** - all of the above

2. Then we tell "what" we are doing using the following characters:

- **-** - minus sign (removes permission)
- **+** - plus sign (grants permission)
- **=** - equals sign (set a permission and remove others)

3. The "which" values are:

- **r** - read permission
- **w** - write permission
- **x** - execute permission

---

Let's see an example:

For `file.txt` we add **write** permission for a group:

```bash
$ chmod g+w file.txt
```

Let's see another example. If we had these permissions for `file.txt`:

| Owner | Group | Others |
| ----- | ----- | ------ |
| rw-   | rw-   | r--    |

We now want to remove **write** permissions from _all_:

```bash
$ chmod a-w file.txt
```

After executing this command we have the following table:

| Owner | Group | Others |
| ----- | ----- | ------ |
| r--   | r--   | r--    |

### Using Octal System to Change Permissions

| Octal | Binary | File Mode |
| ----- | ------ | --------- |
| 0     | 000    | ---       |
| 1     | 001    | --x       |
| 2     | 010    | -w-       |
| 3     | 011    | -wx       |
| 4     | 100    | r--       |
| 5     | 101    | r-x       |
| 6     | 110    | rw-       |
| 7     | 111    | rwx       |

```bash
$ chmod 755 file.txt
```

The above command will result in following permissions:

| Owner | Group | Others |
| ----- | ----- | ------ |
| 111   | 101   | 101    |

| Owner | Group | Others |
| ----- | ----- | ------ |
| rwx   | r-x   | r-x    |
