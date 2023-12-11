def get_marks():
    n = int(input("Enter the number of students: "))
    marks = []
    
    for i in range(n):
        mark = float(input(f"Enter the marks for student {i + 1}: "))
        marks.append(mark)
    
    return marks

def calculate_average(marks):
    total = sum(marks)
    average = total / len(marks)
    return average

def find_highest_and_lowest(marks):
    highest = max(marks)
    lowest = min(marks)
    return highest, lowest

def count_absent_students(marks):
    absent_students = marks.count(0)  # Assuming 0 represents an absent student
    return absent_students

def find_highest_frequency(marks):
    frequency_dict = {}
    
    for mark in marks:
        if mark in frequency_dict:
            frequency_dict[mark] += 1
        else:
            frequency_dict[mark] = 1
    
    max_frequency = max(frequency_dict.values())
    most_frequent_mark = [key for key, value in frequency_dict.items() if value == max_frequency][0]
    
    return most_frequent_mark

if __name__ == "__main__":
    student_marks = get_marks()

    average_score = calculate_average(student_marks)
    highest_score, lowest_score = find_highest_and_lowest(student_marks)
    absent_students_count = count_absent_students(student_marks)
    most_frequent_mark = find_highest_frequency(student_marks)

    print(f"Average score of the class: {average_score}")
    print(f"Highest score in the class: {highest_score}")
    print(f"Lowest score in the class: {lowest_score}")
    print(f"Number of students absent for the test: {absent_students_count}")
    print(f"Mark with the highest frequency: {most_frequent_mark}")
