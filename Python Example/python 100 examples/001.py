#--coding:utf-8--
'''
������1��
��Ŀ����1��2��3��4�����֣�����ɶ��ٸ�������ͬ�����ظ����ֵ���λ�������Ƕ��٣�
'''
for i in range(1,5):
	for j in range(1,5):
		if (i != j) :
			for k in range(1,5):
				if (i != k) and (j != k):
					print i,j,k
