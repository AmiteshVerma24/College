# Write a program to read a string and count how many times each letter
# appears. (Histogram)

str = "Amitesh Amitesh Verma"
histogram = dict()
for ch in str.lower():
    if(ch in histogram):
        histogram[ch] += 1
    else:
        histogram[ch] = 1
print(histogram)