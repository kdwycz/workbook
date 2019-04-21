# 2019年第16周 2019.04.15 - 2019.04.21

在群里潜水了好久……感觉不踢之恩。要好好做每周任务了

## Algorithm

还好Random出了一道水题，不然就赶不及12点之前打卡了= =

[Leetcode 155 min-stack](https://github.com/kdwycz/Workbook/tree/master/LeetCode%20Algorithms/155.min-stack)

## Review

[How To Create A NAS Using ZFS and Proxmox (with pictures)](https://forum.level1techs.com/t/how-to-create-a-nas-using-zfs-and-proxmox-with-pictures/117375)

一篇不那么“技术”的文章。最近沉迷NAS，在蜗牛星际上安装了Proxmox，从而接触到了一些虚拟化和ZFS相关的知识。稍晚些翻译下这篇文章发到博客上面

## Tip

关于 ZFS 的一些简单操作

```bash
# 在 Ubuntu 安装zfs
sudo apt install zfsutils

# 创建RAID5/RAIDZ1存储池
# RAID0: 默认选项
# RAID1: mirror
# RAID5/RAIDZ1（单盘冗余）: raidz1 
# RAID6/RAIDZ2（双盘冗余）: raidz2
sudo zpool create {pool-name} raidz1 /dev/sdc /dev/sdd /dev/sde
# RAID10
sudo zpool create {pool-name} mirror /dev/sdc /dev/sdd mirror /dev/sde /dev/sdf

# 查看存储池状态
sudo zpool status

# 删除存储池
sudo zpool destory {pool-name}
```

## Share

[知乎专栏 Redis与Mysql双写一致性方案解析](https://zhuanlan.zhihu.com/p/59167071)

对于后端的同学，用 Redis 做缓存大家都懂，麻烦点在于缓存合适更新和删除。这篇文章基本覆盖了常见的情况