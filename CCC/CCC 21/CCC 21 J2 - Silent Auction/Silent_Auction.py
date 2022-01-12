dict1 = {'X':0}
number_of_people = int(input().strip())
for i in range(number_of_people):
    name = input().strip()
    bids = int(input().strip())
    if bids > max(dict1.values()):
        dict1[name] = bids

highest_bid = max(dict1.values())
winner = list(dict1.keys())[list(dict1.values()).index(highest_bid)]

print(winner)
