#--coding:utf-8--
'''
������12��
��Ŀ���ж�101-200֮���ж��ٸ����������������������
1.����������ж������ķ�������һ�����ֱ�ȥ��2��sqrt(�����)������ܱ�������
���������������������������������֮�������� ������������
2.����Դ���룺
'''
from math import sqrt
from sys import stdout

def isprime(a):
    k = int(sqrt(m + 1))
    for i in range(2,k + 1):
        if m % i == 0:
            return False
    return True


h = 0
for m in range(101,201):
    leap = isprime(m)
    if leap :
        print '%-4d' % m
        h += 1
        if h % 10 == 0:
            print ''
print 'The total is %d' % h
