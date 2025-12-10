#https://www.hackerrank.com/challenges/collections-counter

from collections import Counter


X_num_of_shoes = int(input())

'''
shoe_sizes_available = []
elements = input()
shoe_sizes_available=[int(element) for element in elements if element != ' ']
'''

shoe_sizes_available = list(map(int, input().split()))


N_num_of_customers = int(input())
customer_orders = []
for i in range(N_num_of_customers):
    list_of_strings = input().split()
    customer_orders.append(tuple(int(x) for x in list_of_strings))


'''
print("Shoe sizes available {}".format(shoe_sizes_available))
for c in customer_orders:
    c_size = c[0]
    c_price = c[1]
    print("Customer Requests Size {} and Price {}".format(c_size,c_price))
'''

total_money_earned = 0
collection_counter = Counter(shoe_sizes_available)
for c in customer_orders:
    c_size = c[0]
    c_price = c[1]
    if collection_counter[c_size] > 0:
        total_money_earned += c_price
        collection_counter[c_size] -= 1

print(total_money_earned,end='')
