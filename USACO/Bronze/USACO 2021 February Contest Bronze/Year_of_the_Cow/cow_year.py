zodiac_animals = ['Ox', 'Tiger', 'Rabbit', 'Dragon', 'Snake', 'Horse', 'Goat', 'Monkey', 'Rooster', 'Dog', 'Pig', 'Rat']

def find_relashonship(list2, zodiac_animals):
    p1 = zodiac_animals.index(list2[2])
    p2 = zodiac_animals.index(list2[4])

    if list2[1] == 'previous':
        if p1 > p2:
            different = p2 - p1 + 12
        elif p1 < p2:
            different = p2 - p1
        elif p1 == p2:
            different = 12
    if list2[1] == 'next':
        if p1 > p2:
            different = p2 - p1
        elif p1 < p2:
            different = p2 - p1 - 12
        elif p1 == p2:
            different = -12
    return different

def find_next_cow(name):
    x = -1
    while True:
        x += 1
        if list_relationship[x][0] == name:
            name = list_relationship[x][3]
            break
    return x, name

######################################################
zodiac_animals_of_cows = {}
list_relationship = []
number_of_lines = int(input().strip())
for i in range(number_of_lines):
    line = input().strip().split()
    list1 = [line[0], line[3], line[4], line[7]]
    zodiac_animals_of_cows[line[0]] = line[4]
    list_relationship.append(list1)

for ii in range(len(list_relationship)):
    for k, v in zodiac_animals_of_cows.items():
        if list_relationship[ii][3] == k:
            list_relationship[ii].append(v)
    if list_relationship[ii][3] == 'Bessie':
        list_relationship[ii].append('Ox')

difference = 0
name = 'Elsie'
while True:
    x, name = find_next_cow(name)
    different = find_relashonship(list_relationship[x], zodiac_animals)
    difference += different
    if name == 'Bessie':
        break

print(abs(difference))


