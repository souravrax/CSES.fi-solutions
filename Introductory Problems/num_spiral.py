# def f(a,b):M=max(a,b);return(a-b)*(-1)**M+M*M-M+1
def f(x, y):
    diag = 1
    if x > y:
        diag = x * x - x + 1
        diff = abs(x - y)
        if x & 1:
            diag -= diff
        else:
            diag += diff

    elif y > x:
        diag = y * y - y + 1
        diff = abs(x - y)
        if y & 1:
            diag += diff
        else:
            diag -= diff

    elif x == y:
        diag = y * y - y + 1

    return diag


def solve():
    x, y = map(int, input().split())
    print(str(f(x, y)))


if __name__ == "__main__":
    tt = int(input())
    while tt > 0:
        solve()
        tt -= 1

