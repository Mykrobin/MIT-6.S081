# MIT-6.S081
**Title:** Operating System Engineering

6.S081 is based on xv6, (xv6: a simple, Unix-like teaching operating system).

## Overview of Deployment

For Deployment Details, Please turn to [MIT-6-S081-0-deployment](http://mykrobin.github.io/2021/06/22/MIT-6-S081-0-deployment/)

libs: 
```shell
apt-get install git build-essential gdb-multiarch qemu-system-misc gcc-riscv64-linux-gnu binutils-riscv64-linux-gnu
```

| Info                        | Description                                               |
| --------------------------- | --------------------------------------------------------- |
| **Based OS**                | `ubuntu-20.04`                                            |
| **clone xv6-labs-2020**     | `git clone git://g.csail.mit.edu/xv6-labs-2020`           |
| **add remote repositories** | `git remote add labs git://g.csail.mit.edu/xv6-labs-2020` |
| **pull**                    | `git fetch labs`                                          |
| **show all branches**       | `git branch -a`                                           |
| **checkout**                | `git checkout util`                                       |
| **push**                    | `git@github.com:Mykrobin/MIT-6.S081.git`                  |
| **build**                   | `make qemu`                                               |

## Labs

| Labs              | Links                                                        |
| ----------------- | ------------------------------------------------------------ |
| **lab-1-util**    | [MIT-link-util](https://pdos.csail.mit.edu/6.828/2020/labs/util.html) |
|                   | [MIT-6-S081-1-util/](http://mykrobin.github.io/2021/06/22/MIT-6-S081-1-util/) |
| **lab-2-syscall** | [MIT-link-syscall](https://pdos.csail.mit.edu/6.828/2020/labs/syscall.html) |
|                   | [MIT-6-S081-2-syscall/]                                      |
| **lab-3-pgtbl**   | [MIT-link-pgtbl](https://pdos.csail.mit.edu/6.828/2020/labs/pgtbl.html) |
|                   | [MIT-6-S081-3-pgtbl/]                                        |
| **lab-4-traps**   | [MIT-link-traps](https://pdos.csail.mit.edu/6.828/2020/labs/traps.html) |
|                   | [MIT-6-S081-4-traps/]                                        |
| **lab-5-lazy**    | [MIT-link-lazy](https://pdos.csail.mit.edu/6.828/2020/labs/lazy.html) |
|                   | [MIT-6-S081-5-lazy/]                                         |
| **lab-6-cow**     | [MIT-link-cow](https://pdos.csail.mit.edu/6.828/2020/labs/cow.html) |
|                   | [MIT-6-S081-6-cow/]                                          |
| **lab-7-thread**  | [MIT-link-thread](https://pdos.csail.mit.edu/6.828/2020/labs/thread.html) |
|                   | [MIT-6-S081-7-thread/]                                       |
| **lab-8-lock**    | [MIT-link-lock](https://pdos.csail.mit.edu/6.828/2020/labs/lock.html) |
|                   | [MIT-6-S081-8-lock/]                                         |
| **lab-9-fs**      | [MIT-link-fs](https://pdos.csail.mit.edu/6.828/2020/labs/fs.html) |
|                   | [MIT-6-S081-9-fs/]                                           |
| **lab-10-mmap**   | [MIT-link-mmap](https://pdos.csail.mit.edu/6.828/2020/labs/mmap.html) |
|                   | [MIT-6-S081-10-mmap/]                                        |
| **lab-11-net**    | [MIT-link-net](https://pdos.csail.mit.edu/6.828/2020/labs/net.html) |
|                   | [MIT-6-S081-11-net/]                                         |