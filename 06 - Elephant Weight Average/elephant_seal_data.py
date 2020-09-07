with open("elephant_seal_data.txt", "r") as f:
    f_split = f.read().split(' \t')

f_split.remove('')

sum = 0
for i in f_split:
    sum += int(i)
    
print(sum/len(f_split))