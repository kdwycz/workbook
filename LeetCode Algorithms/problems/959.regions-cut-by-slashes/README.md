In a N x N grid composed of 1 x 1 squares, each 1 x 1 square consists of a /, \, or blank space.  These characters divide the square into contiguous regions.

(Note that backslash characters are escaped, so a \ is represented as "\\".)

Return the number of regions.

Example 1:
```
Input:
[
  " /",
  "/ "
]
Output: 2
Explanation: The 2x2 grid is as follows:
```
Example 2:
```
Input:
[
  " /",
  "  "
]
Output: 1
Explanation: The 2x2 grid is as follows:
```
Example 3:
```
Input:
[
  "\\/",
  "/\\"
]
Output: 4
Explanation: (Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.)
The 2x2 grid is as follows:
```
Example 4:
```
Input:
[
  "/\\",
  "\\/"
]
Output: 5
Explanation: (Recall that because \ characters are escaped, "/\\" refers to /\, and "\\/" refers to \/.)
The 2x2 grid is as follows:
```
Example 5:
```
Input:
[
  "//",
  "/ "
]
Output: 3
Explanation: The 2x2 grid is as follows:
```

Note:
```
1 <= grid.length == grid[0].length <= 30
grid[i][j] is either '/', '\', or ' '.
```

假设能同时画左右两个斜杠的话，1x1 正方形会被分割成 4 份，2x2 正方形会被分割成 12 份……把这些点当做一个图。求这个图中有多少个联通图。只需要一次深度优先遍历即可。时间复杂度为O(n²)，n 为 grid.length(忽略常数)

写完看了下讨论区，还有用并查集实现的= =