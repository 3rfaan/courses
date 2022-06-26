# The 50 Most Popular Linux & Terminal Commands

This is my summary of the 5-hour long FreeCodeCamp course about popular Unix-like systems terminal commands.

## Find name of user using the system

```zsh
$ whoami
arfanzubi
```

## Manual pages

Shows manual for a specific command. For example `man whoami` shows all the information about the `whoami` command.

```zsh
$ man <command>
```

## Clear terminal screen

```zsh
$ clear
```

Or press <kbd>CTRL</kbd> + <kbd>L</kbd>.

### Clear terminal preserving history

```zsh
$ clear -x
```

## Print working directory

Prints the current directory you are in.

```zsh
$ pwd
/Users/arfanzubi/Desktop
```

## List contents of a folder

```zsh
$ ls
```

To show contents of a subfolder in the current directory:

```zsh
$ ls Files/
```

You can also list contents of a folder in **a different directory** without switching directory:

```zsh
$ ls /Users/arfanzubi/Desktop
```

Directories starting with `/` are **full paths.**

### List contents in long format

```zsh
$ ls -l
```

### List all files (including secret files starting with `.`)

```zsh
$ ls -a
```

You can also combine commands like this:

```zsh
$ ls -la
```

## Change directory

Change the shell working directory.

```zsh
$ Desktop/
```

### Go up a directory

```zsh
$ cd ..
```

### Go up any directories

```zsh
$ cd ../../..
```

### Go to any directory with full path

```zsh
$ cd /Users/arfanzubi/Desktop
```

### Go directly to home directory

```zsh
$ cd ~
```

or simply:

```zsh
$ cd
```

### Go to `root` from any directory

```zsh
$ cd /
```

| Symbol | Directory |
| ------ | --------- |
| /      | root      |
| ~      | home      |

## Make directories

Creates a new folder in the _current working directory_.

```zsh
$ mkdir test-folder
```

Or create multiple folders at once:

```zsh
$ mkdir folder1 folder2 folder3
```

You can also create folders in a subdirectory:

```zsh
$ mkdir ~/Desktop/desktop-folder
```

This creates a folder named `desktop-folder` in the desktop directory.

### Create folders and subfolders using `-p` flag

If we wanted to create a folder named `test-folder` in the desktop and this folder should contain another folder `test` we can do it in one command with the `-p` flag:

```zsh
$ mkdir -p ~/Desktop/test-folder/test
```

This creates any folder that does not exists yet in the provided path.

## Create files

Create empty file with the `touch` command:

```zsh
$ touch file.c
```

Again we can also create multiple files at once:

```zsh
$ touch file1.c file2.pdf file3.txt
```

## Remove _empty_ folders

Remove _empty_ folder(s) from a directory:

```zsh
$ rmdir folder
```

## Remove files

You can remove a files or multiple files by using the `rm` command:

```zsh
$ rm file1 file2
```

### To see details use the `-v` flag for verbose output

```zsh
$ rm -v file1 file2
```

## Remove directories with content

Use the `-r` flag (for _recursive_) to remove a folder that is NOT empty:

```zsh
$ rm -r folder
```

### Remove files in a folder interactively

Using the `-i` flag, the shell asks for permission to delete files one-by-one and expects user input:

```zsh
$ rm -ri folder
```

## The `open` command

If you want to _open_ a file you can use the `open` command and the system will open the specific file in an application supporting the file type.

```zsh
$ open file.pdf
```

To open the current directory in a GUI do this:

```zsh
$ open .
```

The `open` command is found on OS X systems. On Linux you can do:

```bash
$ xdg-open file.pdf
```

## Move / rename files

### Rename file name

```zsh
$ mv fil.pdf file.pdf
```

### Change location of a file

```zsh
$ mv file.pdf Files/
```

The file `file.pdf` has been moved to the `Files/` directory.

You can also move multiple files and folders:

```zsh
$ mv file.pdf test-folder Files/
```

Or move it back one directory:

```zsh
$ mv file.pdf ../
```

## Copy files and folders

```zsh
$ cp file.pdf file-copy.pdf
```

### Copy directories

To copy folders use the recursive `-r` flag:

```zsh
$ cp -r Files/ ~/Desktop/Files
```

This command copies the `Files/` folder to the desktop preserving the same name.

## Print `head` or `tail` of a file

### `head`

Using the `head` command it will output the first _10_ lines of a file:

```zsh
$ head text-file.txt
```

But we can specify the number of lines we want to be in the output:

```zsh
$ head -n 100 text-file.txt
```

### `tail`

The `tail` command does the exact opposite of `head`: It print the last ten lines:

```zsh
$ tail -n 20 text-file.txt
```

If you want to track a file so it gives a live preview if anything changed in the file like a log you can use:

```zsh
$ tail -f log-file.txt
```

## Print the current date

```zsh
$ date
```

## Redirecting standard output

Instead of printing the output of a command to the terminal you can also output in a file for example.

```zsh
$ date > file.txt
```

This will redirect the ouput of the `date` command to `file.txt`.

Note that if we redirect standard output, the destination file will be **overwritten**.

To _append_ the output do this:

```zsh
$ date >> file.txt
```

If the destination file does not exists it will be created automatically.

Another useful example of redirecting:

```zsh
$ ls -l > contents
```

## Print contents of file

### `cat`

```zsh
$ cat contents
```

Or print multiple files:

```zsh
$ cat file1.txt file2.txt
```

Let's suppose we have three files `butcher.txt`, `feedstore.txt`, `groceries.txt` and we want to create one single list out of them. We can use the con**cat**inate commant `cat` to do this:

```zsh
$ cat butcher.txt feedstore.txt groceries.txt > shopping-list.txt
```

Get line numbers with the `-n` flag:

```zsh
$ cat -n file.txt
```

### `less`

Print files in a better interface for reading.

```zsh
$ less file.txt
```

To exit press <kbd>Q</kbd>.

## The `echo` command

The `echo` command does one simple job: it prints to the output the argument passed to it.

```zsh
$ echo "Hello, world!"
Hello, world!
```

You can also output the echo to a file:

```zsh
$ echo "USERNAME:3RFAN" > config.txt
```

In `config.txt` there will be one line which is "USERNAME:3RFAN".

## Word Counting

To find out how many lines are in a file:

```zsh
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

```zsh
$ ls -la | wc -l
```

Above we had an example of three different shopping lists. Let's take `butcher.txt` and `groceries.txt` and find out how many things we need to buy:

```zsh
$ cat groceries.txt butcher.txt | wc
9 15 95
```

We can even output the output of the two piped commands to a new file:

```zsh
$ cat groceries.txt butcher.txt | wc -l > shopping-list-length.txt
```

## Sorting

The `sort` command sorts the elements in a file and outputs it to the terminal. _It will not modify the file passed as input, it will simply output a sorted version of the passed file_!

```zsh
$ sort file.txt
```

It is also case-senstive and capital letters preceed lower letters.

### Numeric sorts

Use the `-n` flag to sort numerically:

```zsh
$ sort -n numbers.txt
```

Or in descending order:

```zsh
$ sort -nr numbers.txt
```

### Remove duplicates

To keep only unique values in a file use the `-u` flag:

```zsh
$ sort -nu numbers.txt
```

If there was a duplicate it would be removed.

Let's suppose we have a file of numbers and we want to find out how many _unique_ numbers are in that file:

```zsh
$ sort -nu numbers.txt | wc -l
```

## The `uniq` command

Most likely used with the `sort` command. It reports or omits repeated lines.

```zsh
$ uniq file.txt
```

When used like this it will only remove _adjecent_ duplicate values!

So it should mostly be used together with the `sort` command:

```zsh
$ sort file.txt | uniq
```

If we wanted to print out the words that have duplicates we can do this:

```zsh
$ sort file.txt | uniq -d
```

To display only non-duplicate lines we can use the `-u` flag:

```zsh
$ sort file.txt | uniq -u
```

### Count Duplicates

To see a count of how many duplicates each word has in a file use the `-c` flag:

```zsh
$ sort file.txt | uniq -c
```

Putting it all together we can sort a list using `sort` then pipe it to `uniq -c` to get the counts of the duplicates and then pipe it again to sort it according to the count of the duplicates:

```zsh
$ sort file.txt | uniq -c | sort -nr
```

## Expansions

There are special characters and syntax that the shell will interpret and expand into some other value.

For example:

```zsh
$ echo ~
/Users/arfanzubi
```

If we wanted to print the character `~` we have to do it like this:

```zsh
$ echo '~'
~
```

### Environment Variables

| Var   | Description                                                 |
| ----- | ----------------------------------------------------------- |
| $PATH | Directories currently configured in system's $PATH variable |
| $USER | Name of the current user                                    |

### The star variable

The star variable will match anything.

```zsh
$ echo *
```

Will output anything in that directory.

If we only wanted `.txt` files we can do it like this:

```zsh
$ ls -l *.txt
```

### The question mark variable

The question mark will match any single character.

```zsh
$ echo *.??
```

This means we search for a file that ends with a dot and 2 characters.

### Curly Braces

Curly braces group together some values.

For example we wanted to create three files named `a.txt`, `b.txt`, `c.txt`:

```zsh
$ echo {a, b, c}.txt
a.txt b.txt c.txt
```

Or something more useful:

```zsh
$ touch app.{js, html, css, py}
app.js app.html app.css app.py
```

This also works with numbers:

```zsh
$ echo Day{1..5}
Day1 Day2 Day3 Day4 Day5
```
