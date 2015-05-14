import re
import urllib2

movie_items = []
url = "http://movie.douban.com/top250?start="

for pages in range(0,10):
    my_page = urllib2.urlopen(url + repr(pages*25)).read().decode("utf-8")
    temp_data = re.findall(r'<span.*?class="title">(.*?)</span>', my_page, re.S)
    
    for items in temp_data:
        if items[0] != '&':
            movie_items.append(items)

num = 1
for items in movie_items:
    print('Top %3d: %s' %(num,items))
    num += 1