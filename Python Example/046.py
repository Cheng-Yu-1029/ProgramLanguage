# -*- coding: UTF-8 -*-
'''
������46��
��Ŀ�����������ֵ�ƽ�������ƽ�������С�� 50 ���˳���
'''
TRUE = 1
FALSE = 0
def SQ(x):
    return x * x
print 'Program will stop if input value less than 50.'
again = 1
while again:
    num = int(raw_input('Please input number'))
    print 'The square for this number is %d' % (SQ(num))
    if num >= 50:
        again = TRUE
    else:
        again = FALSE
