import sys

def main(argv):
    s = input()
    for i in range (len(s)-1):
        for j in range(i+1, len(s)):
            if s[i] == s[j]:
                print("重複あり")
                return True;
    print("重複なし")
    return False;


if __name__ == '__main__':
    sys.exit(main(sys.argv))