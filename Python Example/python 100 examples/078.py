# -*- coding: UTF-8 -*-
'''
������78��
��Ŀ���ҵ����������ˣ�����������ҳ���������ʲô���⡣
1.���������
2.����Դ����
'''
if __name__ == '__main__':
    person = {"li":18,"wang":50,"zhang":20,"sun":22}
    m = 'li'
    for key in person.keys():
        if person[m] < person[key]:
            m = key

    print '%s,%d' % (m,person[m])

    # max function
    list1, list2 = [123, 'xyz', 'zara', 'abc'], [456, 700, 200]

    print "Max value element : ", max(list1);
    print "Max value element : ", max(list2);