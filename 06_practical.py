def fibonacci_search(arr, x):
    n = len(arr)
    fib_m_2 = 0
    fib_m_1 = 1
    fib = fib_m_1 + fib_m_2

    while fib < n:
        fib_m_2 = fib_m_1
        fib_m_1 = fib
        fib = fib_m_1 + fib_m_2

    offset = -1

    while fib > 1:
        i = min(offset + fib_m_2, n - 1)

        if arr[i]['name'] < x:
            fib = fib_m_1
            fib_m_1 = fib_m_2
            fib_m_2 = fib - fib_m_1
            offset = i

        elif arr[i]['name'] > x:
            fib = fib_m_2
            fib_m_1 = fib_m_1 - fib_m_2
            fib_m_2 = fib - fib_m_1

        else:
            return i

    if fib_m_1 and offset + 1 < n and arr[offset + 1]['name'] == x:
        return offset + 1

    return -1

def insert_friend(phonebook, name, number):
    index = fibonacci_search(phonebook, name)

    if index == -1:
        # Friend not found, insert the new friend at the appropriate position
        phonebook.append({'name': name, 'number': number})
        phonebook.sort(key=lambda x: x['name'])
        print(f"{name} added to the phonebook.")
    else:
        print(f"{name} already exists in the phonebook.")


def main():
    phonebook = []
    while True:
        print("\n1. Add Friend\n2. Search Friend\n3. Exit")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            name = input("Enter friend's name: ")
            number = input("Enter friend's mobile number: ")
            insert_friend(phonebook, name, number)

        elif choice == 2:
            name = input("Enter friend's name to search: ")
            index = fibonacci_search(phonebook, name)

            if index != -1:
                print(f"{name}'s mobile number: {phonebook[index]['number']}")
            else:
                print(f"{name} not found in the phonebook.")

        elif choice == 3:
            print("Exiting the program.")
            break

        else:
            print("Invalid choice. Please enter a valid option.")


if __name__ == "__main__":
    main()