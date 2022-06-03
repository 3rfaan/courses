# Advanced Git Tutorial | Google IT Automation

In this course I learned advanced Git commands to improve the workflow with version control systems.

## Skipping the Staging Area

### git commit -a

Shortcut to stage any changes to tracked files and commit them in one step.

Firstly modifying a file to then stage and commit it:

```bash
vim all_checks.py
```

```python
#!/usr/bin/env python3
import os
import sys

def check_reboot():
  """Returns True if the computer has a pending reboot."""
  return os.path.exist('/run/reboot-required')

def main():
  if check_reboot():
    print('Pending reboot')
    sys.exit(1)

main()
```

Now we can stage and commit the file in one command:

```bash
git commit -a -m "Call check_reboot from main, exit with 1 on error"
```

Now we can check the commit using:

```bash
commit fd0b38f72fd36d1ef764bba509f543e3b4d4406f (HEAD -> master)
Author: My name <me@example.com>
Date: Sun Jan 5 16:14:18 2020 -0800

  "Call check_reboot from main, exit with 1 on error"

```

Head indicates what the currently checked out snapshot is.

## Getting more information about our changes

### git log -p

```bash
git log -p
```

Outputs the default log and shows added and removed lines

### git show

```bash
git show fd0b38f72fd36d1ef764bba509f543e3b4d4406f4
```

Detailed view of a single commit taking commit id as param

### git log --stat

```bash
git log --stat
```

Shows how many insertions and deletions were made in the commits

### git diff

With git diff we see the changes in files before they are staged.

Modifying the above file to see the difference before commiting.

```python
#!/usr/bin/env python3
import os
import sys

def check_reboot():
  """Returns True if the computer has a pending reboot."""
  return os.path.exist('/run/reboot-required')

def main():
  if check_reboot():
    print('Pending reboot')
    sys.exit(1)
  print('Everything ok.")
  sys.exit(0)

main()
```

```bash
git diff
```

We can also add the file as parameter to only see changes in a specific file.

### git add -p

Review changes in unstaged files before adding them

```bash
git add -p
```

### git diff --staged

See changes that are staged but not commited yet:

```bash
git diff --staged
```

## Deleting and renaming files

### Delete a file

Deleting a file and changes are staged to be committed

```bash
git rm process.py
git commit -m "Delete unneeded processes file"
```

### Rename a file

Renaming a file and changes are staged to be committed

```bash
git mv disc_usage.py check_free_space.py
git commit -m "New name for disk_usage.py"
```

### Ignoring files

```bash
echo .DS_STORE > .gitignore
```

```bash
git add .gitignore
git commit -m "Add a gitignore file, ignoring .DS_STORE"
```

## Undoing changes before commiting

### git checkout

Removed the check_reboot function in the above process.py file

```python
#!/usr/bin/env python3
import os
import sys

def main():
  if check_reboot():
    print('Pending reboot')
    sys.exit(1)
  print('Everything ok.")
  sys.exit(0)

main()
```

This code results in errors! When we check the status it shows that the file is ready to be staged.

Now using git checkout we will _checkout_ the original file from the latest stored snapshot. We can run git checkout to discard the unstaged changes.

```bash
git checkout all_checks.py
git status
```

Use the `git checkout -p` flag to view individual changes instead of the whole file. Askes change for change if you want to go back to previous snapshot.

### git add \*

Adds any change in the working tree to staging area.

```bash
./all_checks.py > output.txt
git add *
```

### Unstage

Unstages a previously staged file. Opposite of `add`.

```bash
git reset HEAD output.txt
```

## Amending commits

### --amend

Fix a commit that is incomplete:

We create 2 new script files but forget

Creating 2 new files but forgetting to add one of them:

```bash
touch auto-update.py gather-information.sh

git add auto-update.py
git commit -m "Add two new scripts"
```

We can add the missing file and then `--amend` it to the previous commit:

```bash
git add gather-information.sh
git commit --amend
```

The two fields will be added to the staging area to be commited (again).

**Remember: Avoid amending commits that have already been made public.**

## Rollbacks

### git revert

**Git Revert** doesn't mean undo. It creates a new commit that is _inverse_ to the last commit. If one bad line was added this line gets deleted.

Adding faulty commit to repo:

```bash
vim checks.py
```

```python
#!/usr/bin/env python3
import os
import sys

def check_reboot():
  """Returns True if the computer has a pending reboot."""
  return os.path.exist('/run/reboot-required')

def main():
  if check_reboot():
    print('Pending reboot')
    sys.exit(1)

  if disk_full():
    print('Disk Full.')
    sys.exit(1)

  print('Everything ok.")
  sys.exit(0)

main()
```

```bash
git commit -a -m "Add call to disk_full function"
```

The above commited code has errors in it. We forgot to define the `disk_full()` function. We have to do a rollback:

```bash
git revert HEAD
```

Opens commit interface in text editor where we can edit the message and execute the rollback.

## Identifying a commit

We need to identify the commit ID to revert commits that have been committed earlier in time...

### Getting ID of last commit

```bash
git log -1
```

### Why does GIT use SHA1 hashes as IDs?

> "You can verify the data you get back out is the exact same data you put in." _-Linus Torvalds_

### Revert specific commit

Use `git show <commit ID>` to view specific commit

```bash
git show fd0b38f72fd36d1ef764bba509f543e3b4d4406f4
```

_You don't have to write down the full ID. Try with some chars and if there is only one commit that starts with that ID it will show._

```bash
git show fd0b3
```

**Now we can `revert` this specific commit:**

```bash
git revert fd0b38f72fd36d1ef764bba509f543e3b4d4406f4
```

## Branches

### Show all branches

```bash
git branch
```

### Create new branch

```bash
git branch new-feature
```

### Switch to another branch

```bash
git checkout new-feature
```

_Or use the shortcut:_

```bash
git checkout -b another-branch
```

Creating a new file in the new branch

```python
#!/usr/bin/env python3

def main():
  pass

main()
```

Saving the file and commiting to the new branch:

```bash
git add free_memory.py
git commit -m "Add an empty free_memory.ps"
```

## Working with branches

> When we switch branches using `checkout` the HEAD changes and points to the latest current snapshot in the current branch.

After using `ls -l` the current workdirectory and Git history changes to be specific to the branch you are currently in.

**Each branch is just a pointer to a specific commit in a series of snapshots**

### Delete a branch

```bash
git branch -d new-feature
```

## Merging

> **Merging**
>
> The term that Git uses for combining branches data and history together

### Merge `another-feature` branch into the `main` branch

```bash
git checkout main
git merge another-feature
```

### Fast-forward merge

A merge when all commits in the checked-out branch are also in the branch that's being merged. **`HEAD` points to the same commit after merging.**

### Three-way merge

Is performed when the history of the branches has diverted in some way. There isn't a linear path to combine them via fast-forwarding.

## Merge conflicts

Happens when in different branches edits happened on the same part in the same file and Git doesn't know which edit to apply when merging.

_Editing the past file to add comment on what the main function should do:_

```python
#!/usr/bin/env python3

def main():
  """Checks if there's enough free memory in the computer."""

main()
```

```bash
git commit -a -m "Add comment to main()"
```

_Switching from `main` branch to `another-feature` branch:_

```bash
git checkout another-feature
```

Now we make a change in this branch on the same file in the same place:

```python
#!/usr/bin/env python3

def main():
  print("Everything is ok.")

main()
```

```bash
git commit -a -m "Print everything ok"
```

Going back to `main` and merging with `another-feature`:

```bash
git checkout main
git merge another-feature
```

This will result in a merge conflict:

```bash
Auto-merging free_memory.py
CONFLICT (content): Merge conflic in free_memory.py
Automatic merge failed; fix conflicts and then commit result.
```

### Fix conflict

We can fix the conflict when we open the file in which the conflict happened and editing it. The conflict is marked by Git.

```python
#!/usr/bin/env python3

def main():
  """Checks if there's enough free memory in the computer."""
  print("Everything is ok.")

main()
```

Now we need to add the file again:

```bash
git add free_memory.py
```

All conflicts are resolved when we run `git status`.

After running `git commit` (_without message_) a terminal will open where we can edit the commit.

### Check the history with `git log`

```bash
git log --graph --oneline
```

Outputs a nice representation of commits and branches.

### Throw merge away

This will stop merge and reset files in working tree back to previous commit before merge happened.

```bash
git merge --abort
```
