# GIT Basics
Git is a version control system. It can act like a one bih undo button.	It allows you:
* to check the history of a project at any point. 
* develop features separately by branching.
* with multiple developers on single project.

## Initializing a git repository
Makes the current directory and its children trackable by git by creating a .git dir which contains snapshots of your project and commit hashes in the root directory of your project.
```
git init
```
## Adding files for the next commit
```
git add filename
# To add everything that has changed since previous commit
git add . 
```
## Creating a commit
When you are ready and you want to pack all the changes in a single unit (commit)
```
git commit -m "your commit message"
```
## Remotes
Remote versions of your repository/project somewhere on the internet.
```
git remote add origin url
# prints all remotes
git remote
```
## Pushing
The process of uploading your changes to a remoet repository
```
git push origin master
```
Another very useful command for checking the state of your repository:
```
git status
```
Important files:
* .gitignore
  * files which should not tracked by git but are in the dir of your project(binary and local config files) 
* README.md
  * a short description of what is your project and how to use it

Learn about git branches [here](https://www.atlassian.com/git/tutorials/merging-vs-rebasing)
