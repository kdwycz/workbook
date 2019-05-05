class Solution:
    DIRECTION_DICT = {
        0: (0, 1), 
        1: (1, 0),
        2: (0, -1),
        3: (-1, 0)
    }
    
    def spiralMatrixIII(self, R: int, C: int, r0: int, c0: int) -> List[List[int]]:
        answer = [[r0, c0]]
        answer_set = set([str([r0, c0])])
        direction_num = 0
        while len(answer) < R * C:
            r0 += self.DIRECTION_DICT[direction_num][0]
            c0 += self.DIRECTION_DICT[direction_num][1]
            
            # 在网格内才记录
            if 0 <= r0 < R and 0 <= c0 < C:
                answer.append([r0, c0])
                answer_set.add(str([r0, c0]))
            
            # 如果没有阻拦就变向
            if str([r0 + self.DIRECTION_DICT[(direction_num + 1) % 4][0], c0 + self.DIRECTION_DICT[(direction_num + 1) % 4][1]]) not in answer_set:
                direction_num = (direction_num + 1) % 4
        
        return answer
