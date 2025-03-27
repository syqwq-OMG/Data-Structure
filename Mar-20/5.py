digits = ["", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"]
tens1 = [
    "Ten",
    "Eleven",
    "Twelve",
    "Thirteen",
    "Fourteen",
    "Fifteen",
    "Sixteen",
    "Seventeen",
    "Eighteen",
    "Nineteen",
]
tens = [
    "",
    "",
    "Twenty",
    "Thirty",
    "Forty",
    "Fifty",
    "Sixty",
    "Seventy",
    "Eighty",
    "Ninety",
]


def solve(x: int):
    if x < 10:
        return digits[x]
    if 10 <= x < 20:
        return tens1[x - 10]
    if x < 100:
        return tens[x // 10] + " " + digits[x % 10]
    if x < 1000:
        return "{} Hundred {}".format(digits[x // 100], solve(x % 100))
    if x < 1e6:
        return "{} Thousand {}".format(solve(x // 1000), solve(x % 1000))
    if x < 1e9:
        return "{} Million {}".format(solve(x // 1000000), solve(x % 1000000))
    else:
        return "{} Billion {}".format(solve(x // 1000000000), solve(x % 1000000000))


num = int(input())
if num == 0:
    print("Zero")
else:
    print(solve(num))
