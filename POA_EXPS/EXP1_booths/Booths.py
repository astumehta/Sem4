def conv(num):
    result = ""
    length = len(num)
    temp = n - length
    if length != n:
        result = "0" * temp + num   #gives the actual length
    return result

def add(x, y):
    max_len = max(len(x), len(y))
    res, carry = '', 0
    for i in range(max_len - 1, -1, -1):
        total = carry + int(x[i]) + int(y[i])
        res = str(total % 2) + res
        carry = total // 2
    return res

def twocomp(num):
    l = list(num)  
    for i in range(len(l)):  #converts into 1's complement
        if l[i]=="1":
            l[i]="0"
        else:
            l[i]="1"
    b = "0" * (len(l) - 1) + "1"  #to add 1 to the 1's complement
    return add("".join(l), b) #converts into 2's complement

def right_shift(AC, Q, Q1):
    a = AC[0] + AC[:-1]
    b = AC[-1] + Q[:-1]
    c = Q[-1]
    return a, b, c

x = int(input("Enter multiplicand:"))  #3
y = int(input("Enter multiplier:"))    #2
a = bin(x).replace("0b", "")   #11
b = bin(y).replace("0b", "")   #10
na= 0
nb= 0
if a[0] == "-":  #to check negative number
    a = a[1:]
    na = 1
if b[0] == "-":  #to check negative number
    b = b[1:]
    nb = 1

n = max(len(a), len(b)) + 1  #3
n1 = n   #3
fp = conv(a)  #011
sp = conv(b)  #010
fn = twocomp(fp)  #101
sn = twocomp(sp)  #110

if na == 0:   #value of M and -M
    M, MC = fp, fn
else:
    M, MC = fn, fp
if nb==0:     #value of Q 
    Q=sp
else:
    Q=sn
    
AC = conv("0")  #find length of accumulator
Q1 = "0"

print("n"+"   "+"AC"+"    "+"Q"+"     " +"Q1"+"  Operation")
print(str(n) + " " * n1 + AC + " " * n1 + Q + " " * n1 + Q1 + " " * n1 + "initial")

while n > 0:
    comp = Q[-1] + Q1
    if comp[0] == comp[-1]:  #for 00 and 11
        AC, Q, Q1 = right_shift(AC, Q, Q1)
        Op = "right shift"
    elif comp == "10":   
        AC = add(AC, MC)
        AC, Q, Q1 = right_shift(AC, Q, Q1)
        Op = "AC=AC-M and right shift"
    elif comp == "01":
        AC = add(AC, M)
        AC, Q, Q1 = right_shift(AC, Q, Q1)
        Op = "AC=AC+M and right shift"
    
    print(str(n) + " " * n1 + AC + " " * n1 + Q + " " * n1 + Q1 + " " * n1 + Op)
    n =n-1

answer = AC + Q
if na == nb:  #if both are positive/both are negative
    ans_d = str(int(answer, 2))  #multiply 0/1 with 2^power
else:
    ans_d = "-" + str(int(twocomp(answer), 2))


print("The product in binary is:" + answer)
print("Decimal conversion:" + ans_d)

