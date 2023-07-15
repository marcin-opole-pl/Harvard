# Create empty dict
shoping = {}
# Try input
while True:
    try:
        item = input()
        # Capitalize input
        item = item.upper().strip()
        # Check if input in dict
        if item in shoping:
            # If in dict update value
            shoping[item] += 1
        # Else create new entry in dict
        else:
            shoping[item] = 1
    # EOF create list from dict
    except EOFError:
        l = list(shoping.items())
        # Sort list
        sl = sorted(l)
        # Convert list into dict
        sd = dict(sl)
        # Print dict
        for item in sd:
            print(sd[item], item)
        break
    #KeyError
    except KeyError:
        pass