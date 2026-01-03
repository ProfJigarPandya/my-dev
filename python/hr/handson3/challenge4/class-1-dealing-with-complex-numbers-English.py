import math

class Complex(object):  
    def __init__(self, real, imaginary):
        self.real = real
        self.imaginary = imaginary
    def toConjugate(self):
        return Complex(self.real, -self.imaginary)
    def isConjugate(self, no):
        return self.real == no.real and self.imaginary == -no.imaginary
    def __add__(self, no):
        return Complex(self.real+no.real, self.imaginary+no.imaginary)
    def __sub__(self, no):
        return Complex(self.real-no.real, self.imaginary-no.imaginary)
    def __mul__(self, no):
        #((a+bi)(c+di))
        #((ac-bd)+(ad+bc)i)
        real_part = self.real*no.real - self.imaginary*no.imaginary
        imaginary_part = self.real*no.imaginary + self.imaginary*no.real
        if self.isConjugate(no):
            return Complex(real_part, 0)
        else:
            return Complex(real_part, imaginary_part)
    def __truediv__(self, no):
        conjugate_no = no.toConjugate()
        #print('conjugate_no',conjugate_no)
        numerator = self * conjugate_no
        denominator = no * conjugate_no
        #print('numerator',numerator)
        #print('denominator',denominator)
        return Complex(numerator.real/denominator.real, numerator.imaginary/denominator.real)
    def mod(self):
        # \(|z|=\sqrt{a^{2}+b^{2}}\)
        return Complex(math.sqrt(self.real**2 + self.imaginary**2),0)
    def __str__(self):
        if self.imaginary == 0:
            result = "%.2f+0.00i" % (self.real)
        elif self.real == 0:
            if self.imaginary >= 0:
                result = "0.00+%.2fi" % (self.imaginary)
            else:
                result = "0.00-%.2fi" % (abs(self.imaginary))
        elif self.imaginary > 0:
            result = "%.2f+%.2fi" % (self.real, self.imaginary)
        else:
            result = "%.2f-%.2fi" % (self.real, abs(self.imaginary))
        return result

if __name__ == '__main__':
    c = map(float, input().split())
    d = map(float, input().split())
    x = Complex(*c)
    y = Complex(*d)
    print(*map(str, [x+y, x-y, x*y, x/y, x.mod(), y.mod()]), sep='\n',end='')
