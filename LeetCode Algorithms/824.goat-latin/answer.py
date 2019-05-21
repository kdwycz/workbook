class Solution:
    def toGoatLatin(self, S: str) -> str:
        vowel = set(['a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'])
        answer_list = []
        for i, word in enumerate(S.split()):
            if word[0] not in vowel:
                word = word[1:] + word[0]
            word += 'ma' + 'a' * (i + 1)
            answer_list.append(word)
        return ' '.join(answer_list)
