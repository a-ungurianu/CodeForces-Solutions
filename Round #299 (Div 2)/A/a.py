def nrToLit(nr):
	dcd = { 1:"one",2:"two",3:"three",4:"four",5:"five",6:"six",7:"seven",8:"eight",9:"nine",10:"ten",11:"eleven",12:"twelve",
			13:"thirteen",14:"fourteen",15:"fifteen",16:"sixteen",17:"seventeen",18:"eighteen",19:"nineteen",20:"twenty",
			30:"thirty",40:"forty",50:"fifty",60:"sixty",70:"seventy",80:"eighty",90:"ninety",100:"hundred",1000:"thousand" }
	if nr == 0:
		return ""
	if nr == 1000:
		return dcd[1] + " " + dcd[1000]
	if nr >= 100:
		return dcd[nr/100] + " " + dcd[100] + (" and " if nr%100 != 0 else "") + nrToLit(nr%100)
	if nr > 20:
		return dcd[nr/10*10] + ("-" if nr%10 != 0 else "") + nrToLit(nr%10)
	return dcd[nr]


num = int(input())
if num == 0:
	print "zero"
else:
	print nrToLit(num)