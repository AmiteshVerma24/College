# Calculate the electricity bill. For example, electricity charges and rates.
# 1 - 100 unit - 1.5 ₹/unit + additional charges=25.00₹
# 101-200 unit - 2.5₹/unit+ additional charges=50.00₹
# 201-300 unit - 4₹/unit + additional charges=75.00₹
# 300 - 350 unit - 7₹/unit + additional charges=100.00₹
# above 350 - fixed charge 1500₹

unit = int(input("Enter the number of units consumed: "))
result = 0
if(unit < 101):
    result = unit * 1.5 + 25
elif(unit < 201):
    result = unit * 2.5 + 50
elif(unit < 301):
    result = unit * 4 + 75
elif(unit < 351):
    result = unit * 7 + 100
else:
    result = 1500
print("The total bill is",result)