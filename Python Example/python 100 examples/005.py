#--coding:utf-8--
'''
������5��
��Ŀ��������������x,y,z���������������С���������

����1��
l = []
for i in range(3):
    x = int(raw_input('integer:\n'))
    l.append(x)
l.sort()
print l
'''
l = map(int, raw_input().split(' '))
l.sort()
print l