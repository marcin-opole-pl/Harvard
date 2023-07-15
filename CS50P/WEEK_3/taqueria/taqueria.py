# Menu dict
menu = {
    "Baja Taco": 4.00,
    "Burrito": 7.50,
    "Bowl": 8.50,
    "Nachos": 11.00,
    "Quesadilla": 8.50,
    "Super Burrito": 8.50,
    "Super Quesadilla": 9.50,
    "Taco": 3.00,
    "Tortilla Salad": 8.00
}
# Set cost to 0
cost = 0.00
# Get input from user
while True:
    try:
        dish = input('Item:')
# Titlecase input
        dish = dish.title()
# Check if input in dict
        if dish in menu:
# Calculate cost
            cost += menu[dish]
            # Print cost with $
            print(f'Total: ${cost:.2f}')
# Catch KeyError and EOFError
    except EOFError:
        print()
        break
    except KeyError:
        pass
