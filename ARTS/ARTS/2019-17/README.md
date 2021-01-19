# 2019年第17周 2019.04.22 - 2019.04.28

很惭愧的打水卡

## Algorithm

[Leetcode 908 smallest-range-i](https://github.com/kdwycz/Workbook/tree/master/LeetCode%20Algorithms/problems/908.smallest-range-i)

连续刷水题总给人一种钦定的感觉，再 Random 一道吧

[Leetcode 959 Regions Cut By Slashes](https://github.com/kdwycz/Workbook/tree/master/LeetCode%20Algorithms/problems/959.regions-cut-by-slashes)

## Review

[User Authentication with Django REST Framework and JSON Web Tokens](https://medium.com/@sebastianojeda/user-authentication-with-django-rest-framework-and-json-web-tokens-747ea4d84b9f)

迫于稀烂的英语能力，从首页找了篇非常简单的文章读了下。这篇文章用 REST Framework 和 PyJWT 构建了一个 Django 项目（模版？）

## Tip

最近为了排除灵异 bug 需要在服务器抓包，使用了 tcpdump 抓包，并且用 wireshark 看保存后的结果

```bash
# 监控第一个网卡上所有的包
tcpdump

# -i 监控指定网卡的包
tcpdump -i eth1

# host 监控指定 host 的包
tcpdump host 192.168.2.1

# 监控 tcp 协议 443 端口的包
tcpdump tcp port 443

# 保存结果到captcha.cap
tcpdump -w captcha.cap
```

## Share

本周在极客时间上听了一个专栏《如何设计一个秒杀系统》
