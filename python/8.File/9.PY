inp = "hgehcflbewgyfghkjerbgquyaeh"

d = {}
for ch in inp: d[ch] = d.get(ch, 0) + 1
print(d)
