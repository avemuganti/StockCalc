# StockCalc

A tool for efficient dollar-cost averaging. Uses a greedy algorithm to reduce percentage losses.

Note about usage: The user of this program is expected to interact with the code to input their own stock portfolio.
 - This was done because the program was originally intended exclusively for use by the creator.

Greedy algorithm: This algorithm is based on the principle that buying new shares at prices lower than the average price paid per share will reduce percentage loss for the equity in question.

The program runs through all the stocks that a shareholder is currently losing money in, and finds the maximum percentage gain per unit cost. This explanation may not make very much sense right now, but hopefully it will make sense after an example:

 - I own 5 shares of Company X, and am losing 20% of my investment. I also own 10 shares of Y Corporation, and I am losing 5% of my investment. Shares of Company X cost $20 (my average cost, therefore, was $25 per share, meaning I paid $125 for the 5 shares). Shares of Y Corporation cost $95 (meaning my average cost was $100 per share, and I paid $1000 for my 10 shares).
 - Buying one more share of Company X will bring my average cost down to $24.17 per share, which would make my percentage loss around 17.2%, instead of 20%. This is a change of 2.8%, and this will cost me $20. Therefore, the cost to cut my losses by 1 percentage point (assuming linearity) is around $7.25.
 - Buying one more share of Y Corporation will bring my average cost down to $99.55 per share, which would make my percentage loss around 4.6%, instead of 5%. This is a change of 0.4%, and this will cost me $95. Therefore, the cost to cut my losses my losses by 1 percentage point (assuming linearity) is around $219.
 - Clearly, $7.25 is cheaper than $219. So the program will suggest I buy 1 share of Company X. This share will be added to my holdings for the remainder of this program run. The program then repeats the process, until the user runs out of brokerage cash.
 - The output is the total number of shares of each company that the user should buy, in order to to maximize DCA efficiency in this manner.
