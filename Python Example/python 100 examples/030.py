#--coding:utf-8--
'''
��Ŀ��һ��5λ�����ж����ǲ��ǻ���������12321�ǻ���������λ����λ��ͬ��ʮλ��ǧλ��ͬ��������
1.���������ͬ29��
2.����Դ���룺
'''
x = int(raw_input("input a number:\n"))
x = str(x)
flag = 1
for i in range(len(x)/2):
    if x[i] != x[-i - 1]:
        flag = 0
        break
if flag == 1:
    print 'this number is a huiwen'
else:
    print 'this number is not a huiwen'
