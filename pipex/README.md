# Welcome to pipex 👋

> This project aims to make us understand a bit deeper two concepts that we already know: the redirections and the pipes.

## Install

Just `git@github.com:sdummett/pipex.git` and `cd pipex`
then
```sh
make
```
or for the bonus part (multiple pipes and heredoc handling)
```sh
make bonus
```

## Usage

### Mandatory
It should be executed this way
```sh
./pipex file1 cmd1 cmd2 file2
```
This is similar to the next shell command
```sh
< file1 cmd1 | cmd2 > file2
```

### Bonus
For multiple pipes handling
```sh
./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```
This is the equivalent of the next shell command
```sh
< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
```

For the heredoc handling
```sh
./pipex here_doc LIMITER cmd cmd1 file
```
This is similar to the next shell command
```sh
cmd << LIMITER | cmd1 >> file
```

## Author

👤 **Stone**

* Github: [@sdummett](https://github.com/sdummett)
