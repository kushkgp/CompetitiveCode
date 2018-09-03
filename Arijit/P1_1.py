################################################################################
################################################################################
## Template file for problem 1. You have to fill in the function findNumbers  ##
## defined below. The function takes in an input number and return the list   ##
## of numbers that satisfy the problem statement. Please ensure you return a  ##
## list as the submission will be auto evaluated. We have provided a little   ##
## helper to ensure that the return value is correct.                         ##
##                                                                            ##
## You can run this template file to see the output of your function.         ##
## First replace the TEST_NUMBER with correct number.                         ##
## Then simply run: `python problem1_template.py`                             ##
## You should see the output printed once your program runs.                  ##
##                                                                            ##
## DO NOT CHANGE THE NAME OF THE FUNCTION BELOW. ONLY FILL IN THE LOGIC.      ##
## DONT FORGET TO RETURN THE VALUES AS A LIST                                 ##
## IF YOU MAKE ANY IMPORTS PUT THEM IN THE BODY OF THE FUNCTION               ##
##                                                                            ##
## You are free to write additional helper functions but ensure they are all  ##
## in this file else your submission wont work.                               ##
##                                                                            ##
## Good Luck!                                                                 ##
################################################################################
################################################################################

from collections import Counter, defaultdict

TEST_NUMBER = 0

def sumfactors(val):
    return set([i+val/i for i in range(max(1,int(val/1000)), int(val**0.5+1)) if val % i == 0])
    
def proddiffer(val):
	mylist = []
	for i in range(1, val):
		mylist.append(i*(val-i))
	return set(mylist)

def fac_lt_1000(val):
	count = 0
	start = max(1, int(val/1000))
	end = int(val**0.5)+1
	for i in range(start, end):
		if val % i == 0:
			count += 1
			if count > 1:
				return True
	return False

def findNumbers(inputNumber):
	U1 = set([i for i in range(1, 1000**2+1) if fac_lt_1000(i)])
	U2 = {i for i in range(2,2001) if len([j for j in range(1,i) if j*(i-j) in U1])==i-1}
	U3 = {i for i in U1 if len(U2 & sumfactors(i))==1}
	U4 = set([])
	solutions = set([])
	for i in iter(U2):
		temp = proddiffer(i)
		if len(U3 & temp) == 1:
			U4.add(i)
			temp = U3 & temp
			solutions.add((i, temp.pop()))

	sol = set([])
	dean = set([])
	for i in iter(solutions):
		dif = (i[0]**2-4*i[1])**0.5
		dean.add(dif)
		sol.add(((i[0]+dif)/2, (i[0]-dif)/2))

	final = set([])
	for i in iter(sol):
		for j in iter(sol):
			if (i != j) and (i[0] - i[1] == j[0] - j[1]):
				 final.add(i)
	
	d = dict()
	for i in final:
		if i[0] - i[1] in d:
			d[i[0]-i[1]] += 1
		else:
			d[i[0] - i[1] ] = 1
	
	ans = set([])
	for i in final:
		if d[i[0] - i[1]] >= 3:
			ans.add(i)
	
	e = dict(dict()) 
	for i in d:
		e[i] = dict()

	for i in ans:
		if i[0] in e[i[0]-i[1]]:
			e[i[0]-i[1]][i[0]] += 1
		else:
			e[i[0]-i[1]][i[0]] = 1

		if i[1] in e[i[0]-i[1]]:
			e[i[0]-i[1]][i[1]] += 1
		else:
			e[i[0]-i[1]][i[1]] = 1


	tempres = set([])
	for i in ans:
		key = i[0] - i[1]
		temp = 0
		for val in e[key]:
			if e[key][val] > 1:
				temp = 1

		if temp >= 1:
			tempres.add(i)

	finalres = set([])
	for i in tempres:
		key = i[0] - i[1]
		temp = 0

		if e[key][i[0]] == 1 & e[key][i[1]] == 1:
			finalres.add(int(i[0]))
			finalres.add(int(i[1]))

	return list(finalres)

def ensureNumbers(returnList):
    for num in returnList:
        if type(num) is int:
            continue
        else:
            print(num, ' is not an integer.')
            raise TypeError('The return value is not a list of integers')
    return returnList

def ensureListOfNumbers(returnList):
    if type(returnList) is list:
        return ensureNumbers(returnList)
    else:
        print('Return value is not a list. Please ensure you return a list.')
        raise TypeError('The return value is not a list')



if __name__ == "__main__":
    print(ensureListOfNumbers(findNumbers(TEST_NUMBER)))