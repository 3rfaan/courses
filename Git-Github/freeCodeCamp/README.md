# Advanced FreeCodeCamp Course on Git

I found this course on FreeCodeCamp and took some notes. Feel free to share.

## Discarding All Local Changes in a File

```bash
git restore <filename>
```

**Discarding uncommited local changes cannot be undone!**

## Restoring a Deleted File

```bash
git restore <filename>
```

## Discarding Chunks / Lines in a File

```bash
git restore -p <filename>
```

The `-p` flag allows us to go to the patch level and choose which lines to keep and which ones to delete.

## Discarding All Local Changes

Go back to the last commited stage.

```bash
git restore .
```

## Fixing the Last Commit

```bash
git commit --amend -m "Corrected commit message"
```

**`--amend` rewrites history! Never change history for commits that have already been pushed to a remote repository!**

## Reverting a Commit in the Middle

Revert create a new commit which _inverses_ a faulty commit.

```bash
git revert <SHA>
```

## Resetting to an Old Revision

Sets your HEAD pointer to an older revision.

```bash
git reset --hard <SHA>
git reset --mixed <SHA>
```

- `--hard` means that no local changes survive. You go back to a certain point in time and undo all commits after.
- `--mixed` does the same as `--hard` but keeps changes made in the commits and you can modify it locally.

## Resetting a File to an Old Revision

```bash
git restore --source <SHA> <file name>
```

## Reflog

A journal that logs every movement of the HEAD pointer.

```bash
git reflog
```

### Recovering Deleted Commits using Reflog

```bash
git reflog
git branch <branch name> <SHA>
```

## Recovering a Deleted Branch

```bash
git reflog
git branch <branch name> <SHA>
```

## Moving a Commit to a New Branch

```bash
git branch <branch name>
git reset HEAD~1 --hard
```

## Moving a Commit to a Different Branch

```bash
git checkout <branch name>
git cherry-pick <SHA>
git checkout master
git reset --hard HEAD~1
```

## Interactive Rebase

The Swiss Army knife of Git tools.

1. How far back do you want to go? What should be the _"base"_ commit?
2. `git rebase -i HEAD~3`
3. In the editor, only determine which _actions_ you want to perform. Don't change commit data in this step, yet! **Notice: Commits are in "reverse" order!**

### Edit Old Commit Messages

```bash
git rebase -i HEAD~3
```

...then use `reword` option

### Deleting Old Commits

```bash
git rebase -i HEAD~2
```

...then use `drop` option

### Squashing Multiple Commits Into One

```bash
git rebase -i HEAD~3
```

...then use `squash` option

### Adding a Change to an Old Commit

```bash
git add <file name>
git commit --fixup <SHA>
```

```bash
git rebase -i HEAD~4 --autosquash
```

In the editor window we don't have to do anything!
