months = [
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
]

while True:
    try:
        # Get str
        date_us = input('Date: ')
        # If month is an int
        if '/' in date_us:
            m, d, y = date_us.split('/')
            # Int d and m
            d = int(d)
            m = int(m)
            # Check d and m correctness
            if 1 <= d <= 31 and 1 <= m <= 12:
                print(y, '-', f'{m:02}', '-', f'{d:02}', sep='')
                break
            else:
                date_us = input('Date: ')
        # If month is a str
        elif ',' in date_us:
            md, y = date_us.split(',')
            m, d =md.split(' ')
            # Int d
            d = int(d)
            # Check d and m correctness
            if 1 <= d <= 31 and m in months:
                m = months.index(m) + 1
                print(y, '-', f'{m:02}', '-', f'{d:02}', sep='')
                break
            else:
                date_us = input('Date: ')
    except ValueError:
        pass
    