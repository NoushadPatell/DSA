def binary_search(arr, x):
    low, high = 0, len(arr) - 1

    while low <= high:
        mid = (low + high) // 2
        mid_value = arr[mid]

        if mid_value == x:
            return True
        elif mid_value < x:
            low = mid + 1
        else:
            high = mid - 1

    return False

def fibonacci_search(arr, x):
    def fibonacci_sequence(n):
        fib = [0, 1]
        while fib[-1] < n:
            fib.append(fib[-1] + fib[-2])
        return fib

    n = len(arr)
    fib = fibonacci_sequence(n)

    offset = 0
    i = min(fib[-2], n - 1)

    while i > 0:
        mid = min(offset + fib[i - 1], n - 1)

        if arr[mid] == x:
            return True
        elif arr[mid] < x:
            i -= 2
            offset = mid + 1
        else:
            i -= 1

    return False

if __name__ == "__main__":
    student_roll_numbers = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]

    search_roll_number = 40
    result_binary_search = binary_search(student_roll_numbers, search_roll_number)
    print(f"Binary Search: Student with roll number {search_roll_number} {'attended' if result_binary_search else 'did not attend'} the training program.")

    search_roll_number = 70
    result_fibonacci_search = fibonacci_search(student_roll_numbers, search_roll_number)
    print(f"Fibonacci Search: Student with roll number {search_roll_number} {'attended' if result_fibonacci_search else 'did not attend'} the training program.")
