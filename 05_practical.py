def binary_search_recursive(arr, target, low, high):
    if low <= high:
        mid = (low + high) // 2
        mid_name, _ = arr[mid]

        if mid_name == target:
            return mid
        elif mid_name < target:
            return binary_search_recursive(arr, target, mid + 1, high)
        else:
            return binary_search_recursive(arr, target, low, mid - 1)
    else:
        return -1

def binary_search_iterative(arr, target):
    low, high = 0, len(arr) - 1

    while low <= high:
        mid = (low + high) // 2
        mid_name, _ = arr[mid]

        if mid_name == target:
            return mid
        elif mid_name < target:
            low = mid + 1
        else:
            high = mid - 1

    return -1

if __name__ == "__main__":
    friends_list = [("Alice", "123-456-7890"),
                    ("Bob", "234-567-8901"),
                    ("Charlie", "345-678-9012"),
                    ("David", "456-789-0123"),
                    ("Eve", "567-890-1234")]

    friends_list.sort()

    search_name_recursive = "Charlie"
    result_recursive = binary_search_recursive(friends_list, search_name_recursive, 0, len(friends_list) - 1)
    print(f"Binary Search (Recursive): {search_name_recursive} found at index {result_recursive}.")

    search_name_iterative = "Eve"
    result_iterative = binary_search_iterative(friends_list, search_name_iterative)
    print(f"Binary Search (Iterative): {search_name_iterative} found at index {result_iterative}.")
