#--coding:utf-8--
'''
������14��
��Ŀ����һ���������ֽ������������磺����90,��ӡ��90=2*3*3*5��
'''
from sys import stdout
n = int(raw_input("input number:\n"))
print "n = %d" % n

for i in range(2,n + 1):
    while n != i:
        if n % i == 0:
            stdout.write(str(i))
            stdout.write("*")
            n = n / i
        else:
            break
print "%d" % n
