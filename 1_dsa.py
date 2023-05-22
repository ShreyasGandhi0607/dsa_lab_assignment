def initializeHashTable():
    size = int(input('Enter size of hash table: '))
    hashtable = [[-1, 'null'] for _ in range(size)]
    print('Hashtable of size', size, 'is successfully created .....')
    print(' ')
    return size, hashtable


choice = 1
while choice != 4:
    print('\n****** Menu ******')
    print(' 1.Linear Probing')
    print(' 2.Double Hashing')
    print(' 3.Exit\n')
    choice = int(input('Enter your choice: '))
    print()
    count = 0

    if choice == 1:
        size, hashtable = initializeHashTable()
        choice1 = 1
        while choice1 != 4:
            print('\n* Menu for Linear Probing *')
            print(' 1.Insert')
            print(' 2.Search')
            print(' 3.Display')
            print(' 4.Back\n')
            choice1 = int(input('Enter your choice: '))
            print()

            if choice1 == 1:
                if count == size:
                    print('Hash table is Full .........')
                else:
                    number = int(input('Enter number: '))
                    name = input('Enter Name: ')
                    hashvalue = number % size
                    while hashtable[hashvalue][0] != -1:
                        print('\nCollision has occurred .....')
                        print(
                            'Now, Calculating new hash value by using linear Probing')
                        hashvalue = (hashvalue + 1) % size

                    hashtable[hashvalue][0] = number
                    hashtable[hashvalue][1] = name
                    count += 1
                    print('Data is successfully inserted in the hash table ....')

            if choice1 == 2:
                number = int(input('Enter number to search: '))
                hashvalue = number % size
                comparison = 0

                while hashtable[hashvalue][0] != number and comparison < size:
                    hashvalue = (hashvalue + 1) % size
                    comparison += 1

                if comparison < size:
                    print('The number', number, 'is found at location',
                          hashvalue, 'with total comparisons=', comparison+1)
                else:
                    print(
                        'The number is NOT found in the hashtable.... with comparisons', comparison+1)

            if choice1 == 3:
                for i in range(size):
                    print('Hash Value', i, '->', hashtable[i])

        print('Total inserted record=', count)
        print()

    if choice == 2:
        size, hashtable = initializeHashTable()
        choice1 = 1
        while choice1 != 4:
            print('\n* Menu for Double Hashing *')
            print(' 1.Insert')
            print(' 2.Search')
            print(' 3.Display')
            print(' 4.Back\n')
            choice1 = int(input('Enter your choice: '))
            print()

            if choice1 == 1:
                if count == size:
                    print('Hash table is Full .........')
                else:
                    number = int(input('Enter number: '))
                    name = input('Enter Name: ')
                    hashvalue1 = number % size
                    i = 1

                    while hashtable[hashvalue1][0] != -1:
                        print('\nCollision has occurred .....')
                        print(
                            'Now, Calculating new hash value by Double Hashing Technique')
                        prime = int(
                            input("\nEnter prime number lesser than size of HASH TABLE: "))
                        hashvalue2 = hashvalue1 = (
                            hashvalue1 + i * (prime - (number % prime))) % size
                        i += 1

                    hashtable[hashvalue1][0] = number
                    hashtable[hashvalue1][1] = name
                    count += 1
                    print('Data is successfully inserted in the hash table .....')

            if choice1 == 2:
                number = int(input('Enter number to search: '))
                hashvalue1 = number % size
                comparison = 0
                i = 1

                while hashtable[hashvalue1][0] != number and comparison < size:
                    hashvalue1 = (
                        hashvalue1 + i * (prime - (number % prime))) % size
                    comparison += 1
                    i += 1

                if comparison < size:
                    print('The number', number, 'is found at location',
                          hashvalue1, 'with comparisons', comparison+1)
                else:
                    print(
                        'The number is NOT found in the hashtable... with comparisons', comparison+1)

            if choice1 == 3:
                for i in range(size):
                    print('Hash Value', i, '->', hashtable[i])

        print('Total inserted record=', count)
        print()

    if choice == 3:
        print("Thanks for using this Program !!")
        exit()
