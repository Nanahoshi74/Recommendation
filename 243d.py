def main():
    n, x = map(int, input().split())
    s = input().strip()
    
    for char in s:
        if char == 'U':
            if x % 2 == 0:
                x //= 2
            else:
                x -= 1
                x //= 2
        elif char == 'L':
            x *= 2
        else:
            x *= 2
            x += 1
    
    print(x)

if __name__ == "__main__":
    main()
