def interest(start_val, years, multiplier = 1, promo = 0):
    '''(float, int, float, float) -> float
    This function takes a starting saving amount <start_val>
    an amount of years of accumulation <years> and if given, an average yearly
    expected promotion <promo>, an interest rate <multiplier> and calculates
    the amount of total money that will be accumulated after the amount of
    the years specified.
    REQ: start_val >= 0
    REQ: years >= 0
    REQ: multiplier >= 0
    >>> interest(20000, 10, 1.04, 2000)
    'You will accumulate $354044.6 after 10 years.'
    >>> interest(20000, 10, 1.04)
    'You will accumulate $249727.03 after 10 years.'
    >>> interest(20000, 10)
    'You will accumulate $200000 after 10 years.'
    '''
    # iterate through the amount of years given.
    for i in range(0, years):
        # if it's the first year, multiply by the interest rate
        if i == 0:
            total = start_val*multiplier
        # otherwise
        else:
            # increment by the promotion
            start_val += promo
            # multiply by the interest rate after incrementing
            total = (total + start_val)*multiplier
    # return the total amount, rounding to 2 decimals
    return "You will accumulate $"+ str(
        round(total,2)) + " after " + str(years) + " years."