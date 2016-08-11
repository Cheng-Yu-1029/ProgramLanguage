create nonclustered index btime_index on H_Datas(btime);
create nonclustered index traff_index on H_Datas(H_traff);
create nonclustered index dis_index on Distance(distance);

CREATE DATABASE GSM
ON
PRIMARY
( NAME = GSM1,   --���ļ�
FILENAME =
 'c:\program files\microsoft sql server
\mssql.1\mssql\data\GSM1.mdf',
 SIZE = 100M,
 MAXSIZE = 200,
 FILEGROWTH = 20 ),
( NAME = GSM2,   --���ļ�
FILENAME =
 'c: \program files\microsoft sql server
\mssql.1\mssql\data\GSM2.ndf',
 SIZE = 100M,
 MAXSIZE = 200,
 FILEGROWTH = 20 ),LOG ON            ---��־�ļ�
( NAME = GSMlog1,
FILENAME =
'c: \program files\microsoft sql server
\mssql.1\mssql\data\GSMlog1.ldf',
SIZE = 100M,
MAXSIZE = 200,
FILEGROWTH = 20 );

