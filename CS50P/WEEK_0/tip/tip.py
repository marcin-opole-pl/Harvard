def main():
    dollars = dollars_to_float(input("How much was the meal? "))
    percent = percent_to_float(input("What percentage would you like to tip? "))
    tip = dollars * percent
    print(f"Leave ${tip:.2f}")


def dollars_to_float(d):
    # TODO
    x = d.removeprefix('$')
    y = float(x)
    return y


def percent_to_float(p):
    # TODO
    x = p.removesuffix('%')
    y = float(x)/100
    return y

main()