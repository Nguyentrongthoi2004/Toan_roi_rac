def calculate_savings(M, n, ls):
    monthly_rate = ls / (12 * 100)
    final_amount = M * (1 + monthly_rate) ** n
    return round(final_amount, 6)
n, M, ls = map(float, input().split())
result = calculate_savings(M, n, ls)
print(f"{result:.6f}")