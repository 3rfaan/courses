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

Create file with the `touch` command:

```zsh
$ touch file.c
```
