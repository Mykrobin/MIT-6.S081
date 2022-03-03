# MIT-6.S081
**Title:** Operating System Engineering

6.S081 is based on xv6, (xv6: a simple, Unix-like teaching operating system).

## Overview of Deployment

For Deployment Details, Please turn to [MIT-6-S081-0-deployment](http://mykrobin.github.io/2021/06/22/MIT-6-S081-0-deployment/)

libs: 
```shell
apt-get install git build-essential gdb-multiarch qemu-system-misc gcc-riscv64-linux-gnu binutils-riscv64-linux-gnu
```

| Info                    | Description                                               |
| ----------------------- | --------------------------------------------------------- |
| Based OS                | `ubuntu-20.04`                                            |
| **clone xv6-labs-2020** | `git clone git://g.csail.mit.edu/xv6-labs-2020`           |
| add remote repositories | `git remote add labs git://g.csail.mit.edu/xv6-labs-2020` |
| pull                    | `git fetch labs`                                          |
| show all branches       | `git branch -a`                                           |
| checkout                | `git checkout util`                                       |
| push                    | `git@github.com:Mykrobin/MIT-6.S081.git`                  |
| **build**               | `make qemu`                                               |



## Labs



lab-1-util:   [MIT_link](https://pdos.csail.mit.edu/6.828/2020/labs/util.html)     [Backup_link](http://mykrobin.github.io/2021/06/22/MIT-6-S081-1-util/)

lab-2-syscall:   [MIT_link](https://pdos.csail.mit.edu/6.828/2020/labs/syscall.html)     [Backup_link](http://mykrobin.github.io/2021/06/22/MIT-6-S081-1-util/)

lab-3-pgtbl:   [MIT_link](https://pdos.csail.mit.edu/6.828/2020/labs/pgtbl.html)     [Backup_link](http://mykrobin.github.io/2021/06/22/MIT-6-S081-1-util/)

lab-4-traps:   [MIT_link](https://pdos.csail.mit.edu/6.828/2020/labs/traps.html)     [Backup_link](http://mykrobin.github.io/2021/06/22/MIT-6-S081-1-util/)

lab-5-lazy:   [MIT_link](https://pdos.csail.mit.edu/6.828/2020/labs/lazy.html)     [Backup_link](http://mykrobin.github.io/2021/06/22/MIT-6-S081-1-util/)

lab-6-cow:   [MIT_link](https://pdos.csail.mit.edu/6.828/2020/labs/cow.html)     [Backup_link](http://mykrobin.github.io/2021/06/22/MIT-6-S081-1-util/)

lab-7-thread:   [MIT_link](https://pdos.csail.mit.edu/6.828/2020/labs/thread.html)     [Backup_link](http://mykrobin.github.io/2021/06/22/MIT-6-S081-1-util/)

lab-8-lock:   [MIT_link](https://pdos.csail.mit.edu/6.828/2020/labs/lock.html)     [Backup_link](http://mykrobin.github.io/2021/06/22/MIT-6-S081-1-util/)

lab-9-fs:   [MIT_link](https://pdos.csail.mit.edu/6.828/2020/labs/fs.html)     [Backup_link](http://mykrobin.github.io/2021/06/22/MIT-6-S081-1-util/)

lab-10-mmap:   [MIT_link](https://pdos.csail.mit.edu/6.828/2020/labs/mmap.html)     [Backup_link](http://mykrobin.github.io/2021/06/22/MIT-6-S081-1-util/)

lab-11-net:   [MIT_link](https://pdos.csail.mit.edu/6.828/2020/labs/net.html)     [Backup_link](http://mykrobin.github.io/2021/06/22/MIT-6-S081-1-util/)

```

```