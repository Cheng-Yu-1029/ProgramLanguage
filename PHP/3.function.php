<!--
 * Created by PhpStorm.
 * User: lenovo
 * Date: 2017/9/12
 * Time: 8:48
-->

<HTML>
<HEAD>
<TITLE>�򵥵ĺ���</TITLE>
</HEAD>
<BODY>
<FONT SIZE=5>
<?
	function printBold($inputText)			//����function printBold����
    {
        print("<B>" . $inputText . "</B>");	////��ӡ$inputText
    }
    function makeBold($inputText)       //����function makeBold()����
    {
        $boldedText = "<B>";
        $boldedText .= $inputText;
        $boldedText .= "</B>";
        return($boldedText);        //���ر���$boldedText
    }
	print("����û�м��أ�<BR>\n");			//ֱ�Ӵ�ӡ�ַ���
	printBold("���м����ˣ�����");			//����function printBold()����
	print("<BR>\n");
    print(makeBold("���б������ˣ�����") . "<BR>\n");//����function makeBold()����
	print("����û�м��أ�<BR>\n");			//ֱ�Ӵ�ӡ�ַ���
?>
</FONT>
</BODY>
</HTML>