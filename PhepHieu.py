def convert_and_sort(input_list):
    numbers = sorted([x for x in input_list if x.isdigit()], key=int)
    letters = sorted([x for x in input_list if x.isalpha()])
    return numbers + letters


input_a = input().split()
n_a = int(input_a[0])
set_a = set(input_a[1:n_a + 1])

input_b = input().split()
n_b = int(input_b[0])
set_b = set(input_b[1:n_b + 1])

difference = list(set_a - set_b)

sorted_difference = convert_and_sort(difference)

if sorted_difference:
    print(" ".join(sorted_difference))
else:
    print("none")