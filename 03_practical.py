class Book:
    def __init__(self, title, author, cost):
        self.title = title
        self.author = author
        self.cost = cost

def delete_duplicates(books):
    unique_books = []
    seen_titles = set()

    for book in books:
        if book.title not in seen_titles:
            seen_titles.add(book.title)
            unique_books.append(book)

    return unique_books

def display_books_ascending_order(books):
    sorted_books = sorted(books, key=lambda x: x.cost)
    for book in sorted_books:
        print(f"{book.title} by {book.author} - ${book.cost}")

def count_expensive_books(books):
    expensive_books_count = sum(1 for book in books if book.cost > 500)
    return expensive_books_count

def copy_books_less_than_500(books):
    inexpensive_books = [book for book in books if book.cost < 500]
    return inexpensive_books

if __name__ == "__main__":
    book1 = Book("Book1", "Author1", 300)
    book2 = Book("Book2", "Author2", 700)
    book3 = Book("Book3", "Author3", 450)
    book4 = Book("Book4", "Author4", 600)
    book5 = Book("Book5", "Author5", 250)

    books = [book1, book2, book3, book4, book5]

    unique_books = delete_duplicates(books)
    print("Books after deleting duplicates:")
    for book in unique_books:
        print(f"{book.title} by {book.author} - ${book.cost}")

    print("\nBooks in ascending order based on cost:")
    display_books_ascending_order(books)

    count_expensive = count_expensive_books(books)
    print(f"\nNumber of books with cost more than 500: {count_expensive}")

    inexpensive_books = copy_books_less_than_500(books)
    print("\nBooks with cost less than 500:")
    for book in inexpensive_books:
        print(f"{book.title} by {book.author} - ${book.cost}")
