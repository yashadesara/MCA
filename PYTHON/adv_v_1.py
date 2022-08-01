import matplotlib.pyplot as plt

class InterestCalc(object):
    def __init__(self,p,r,n):
        self.p = p
        self.r = r
        self.n = n

    def getSimpleInterest(self):
        si = (self.p * self.r * self.n)/100
        return si
    
    def getCompoundInterest(self):
        ci = self.p * (pow((1+self.r/100), self.n))
        return ci

    def showBar(self):
        y = [self.getSimpleInterest(),self.getCompoundInterest()]
        x = [f'si {y[0]}', f'ci {y[1]}']
        plt.bar(x,y,label='Interest Data',color=['lightgreen','lightblue'])
        plt.xlabel('interest type')
        plt.ylabel('interest')
        plt.title(f"P: {self.p} R : {self.r} N: {self.n}")
        plt.legend()
        plt.show()


p = 1000.00
r = 5.00
n = 2

obj = InterestCalc(p,r,n)

print("Simple Interest: ",obj.getSimpleInterest())
print("Compound Interest: ",obj.getCompoundInterest())

obj.showBar()