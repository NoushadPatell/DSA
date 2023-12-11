def calculate_net_amount(transaction_log):
    net_amount = 0

    transactions = transaction_log.split(';')

    for transaction in transactions:
        operation, amount_str = transaction.split(':')
        amount = float(amount_str.strip())

        if operation.lower() == 'deposit':
            net_amount += amount
        elif operation.lower() == 'withdrawal':
            net_amount -= amount

    return net_amount

if __name__ == "__main__":
    transaction_log_input = input("Enter the transaction log (e.g., Deposit: 300; Withdrawal: 200): ")

    # Calculate the net amount based on the transaction log
    net_amount = calculate_net_amount(transaction_log_input)

    print(f"Net amount in the bank account: {net_amount}")
