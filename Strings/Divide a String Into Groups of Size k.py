from typing import List

def divideString(s: str, k: int, fill: str) -> List[str]:
    ans = []
    i = 0
    while i < len(s):
        t = s[i:i+k]
        if len(t) < k:
            t += fill * (k - len(t))
        ans.append(t)
        i += k
    return ans

# Sample usage
if __name__ == "__main__":
    s = input()
    k = int(input)
    fill = input()
    result = divideString(s, k, fill)
    print("Divided Strings:", result)
