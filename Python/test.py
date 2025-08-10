import random

def calculate_old_tax(income):
    if income <= 2000:
        return 0
    elif 2001 <= income <= 4000:
        return income * 5 // 100
    elif 4001 <= income <= 8000:
        return income * 10 // 100
    elif 8001 <= income <= 15000:
        return income * 15 // 100
    else:
        return income * 20 // 100

def calculate_new_tax(income):
    if income <= 500:
        return 0
    elif 501 <= income <= 2500:
        return income * 10 // 100
    elif 2501 <= income <= 5000:
        return income * 15 // 100
    elif 5001 <= income <= 9000:
        return income * 20 // 100
    else:
        return income * 25 // 100

def generate_test_case_for_interval(interval):
    T = random.randint(4, 10)  # Each interval test case has 1 input
    test_cases = []
    for _ in range(T):
        income = random.randint(interval[0] // 20, interval[1] // 20) * 20
        old_tax = calculate_old_tax(income)
        new_tax = calculate_new_tax(income)
        if old_tax == 0:
            output = -1
        else:
            output = new_tax
        test_cases.append((old_tax, output))
    return T, test_cases

def generate_random_test_case(max_income=20000):
    T = random.randint(4, 10)  # 1 to 5 inputs per random test case
    test_cases = []
    for _ in range(T):
        income = random.randint(0, max_income // 20) * 20
        old_tax = calculate_old_tax(income)
        new_tax = calculate_new_tax(income)
        if old_tax == 0:
            output = -1
        else:
            output = new_tax
        test_cases.append((old_tax, output))
    return T, test_cases

def main():
    # Key income intervals to cover
    intervals = [
        (0, 2000),      # 0-2000
        (2001, 2500),   # 2001-2500
        (2501, 4000),   # 2501-4000
        (4001, 5000),  # 4001-5000
        (5001, 8000),   # 5001-8000
        (8001, 9000),   # 8001-9000
        (9001, 15000),  # 9001-15000
        (15001, 500000) # 15001+
    ]
    
    # Generate test cases for each interval
    for i in range(8):
        T, test_cases = generate_test_case_for_interval(intervals[i])
        with open(f"{i+1}.in", "w") as fin:
            fin.write(f"{T}\n")
            for case in test_cases:
                fin.write(f"{case[0]}\n")
        with open(f"{i+1}.out", "w") as fout:
            for case in test_cases:
                fout.write(f"{case[1]}\n")
    
    # Generate random test cases for the last 2 files
    for i in range(8, 10):
        T, test_cases = generate_random_test_case()
        with open(f"{i+1}.in", "w") as fin:
            fin.write(f"{T}\n")
            for case in test_cases:
                fin.write(f"{case[0]}\n")
        with open(f"{i+1}.out", "w") as fout:
            for case in test_cases:
                fout.write(f"{case[1]}\n")

if __name__ == "__main__":
    main()