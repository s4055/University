create database ��ȭ
go
use ��ȭ
go

create table ��ȭ
(���� nchar(20) not null,
��ȭ nchar(20) not null,
������ int,
�󿵰� char(10) not null primary key,
���� char(10))

create table ����
(�̸� nchar(8) not null,
ID nchar(10) not null primary key,
���� int,
���� nchar(2),
ǥ�ݾ� int)

create table ��ȭ��
(��ȭ�� nchar(20) not null,
�¼���ȣ nchar(10) not null primary key,
�����ο� int,
ID nchar(10) foreign key references ����(ID),
�󿵰� char(10) foreign key references ��ȭ(�󿵰�))

--��ȭ ���̺�
insert into ��ȭ
values('��� ����','ĸƾ �Ƹ޸�ī:�ú���',12,'5��','�̱�')
insert into ��ȭ
values('������','Ž�� ȫ�浿:����� ����',15,'6��','�ѱ�')
insert into ��ȭ
values('�����','�ð� ��Ż��',15,'7��','�ѱ�')
insert into ��ȭ
values('�� �з�','����Ǯ',20,'9��','�̱�')
insert into ��ȭ
values('�������� �����','������',12,'1��','�ε�')
insert into ��ȭ
values('��ư ƿ��','�̹����̼� ����',15,'3��','����')
insert into ��ȭ
values('��ö��','�����ϰ� �����ϰ�',15,'4��','�ѱ�')
insert into ��ȭ
values('������ ��ī��','ũ�ο��� ����',15,'2��','�Ϻ�')
insert into ��ȭ
values('�̾���Ű �Ͼ߿�','�Ͽ��� �����̴� ��',7,'8��','�Ϻ�')
insert into ��ȭ
values('�� ī��','��� �����',15,'10��','�̱�')
insert into ��ȭ
values('�����','��������1��',15,'11��','�߱�')

--���� ���̺�
insert into ����
values('�質��','M0T123',19,'��',10000)
insert into ����
values('���Ѻ�','M0D265',20,'��',12000)
insert into ����
values('����','M0E125',7,'��',9000)
insert into ����
values('���ѿ�','M0R789',8,'��',7000)
insert into ����
values('ȫ��','M0Y489',21,'��',12000)
insert into ����
values('����','P0R753',15,'��',11000)
insert into ����
values('�����','P0A487',15,'��',8000)
insert into ����
values('�Ѽ���','P0B257',19,'��',12000)
insert into ����
values('����','N0B751',10,'��',8000)
insert into ����
values('�ֿ���','N0T159',20,'��',15000)
insert into ����
values('��ä��','N0E789',19,'��',15000)
insert into ����
values('������','N0F456',15,'��',11000)
insert into ����
values('������','B0S429',24,'��',15000)
insert into ����
values('�����','B0P154',26,'��',15000)
insert into ����
values('�迵��','B0K168',19,'��',10000)

--��ȭ�� ���̺�
insert into ��ȭ��
values('�Ե��ó׸�','A�� 20��',200,'P0R753','1��')
insert into ��ȭ��
values('CGV','D�� 5��',150,'B0K168','2��')
insert into ��ȭ��
values('�ް��ڽ�','E�� 17��',245,'P0A487','3��')
insert into ��ȭ��
values('���̾ؽó׸�','B�� 13��',320,'N0F456','4��')
insert into ��ȭ��
values('�ε��÷���','T�� 20��',180,'M0T123','5��')
insert into ��ȭ��
values('CGV','B�� 10��',200,'M0D265','6��')
insert into ��ȭ��
values('�ε��÷���','P�� 16��',230,'N0T159','7��')
insert into ��ȭ��
values('���̾ؽó׸�','E�� 19��',195,'M0E125','8��')
insert into ��ȭ��
values('�Ե��ó׸�','F�� 20��',300,'B0P154','9��')
insert into ��ȭ��
values('�ε��÷���','A�� 6��',310,'N0E789','10��')
insert into ��ȭ��
values('�ް��ڽ�','G�� 8��',250,'P0B257','11��')
insert into ��ȭ��
values('CGV','D�� 8��',180,'M0R789','8��')
insert into ��ȭ��
values('�Ե��ó׸�','A�� 15��',200,'N0B751','8��')
insert into ��ȭ��
values('���̾ؽó׸�','B�� 9��',270,'M0Y489','3��')
insert into ��ȭ��
values('�ް��ڽ�','H�� 17��',300,'B0S429','9��')

Select*from ��ȭ
Select*from ��ȭ��
Select*from ����

--��ȭ ���̺��� �������� ���� �˻��Ͻÿ�
--�� ���󺰷� ��� �˻��Ͻÿ�
select ����,SUM(������) as �� from ��ȭ
group by ����

--��ȭ ���̺��� �������� ����� �˻��Ͻÿ�
--�� ���󺰷� ��� �˻��Ͻÿ�
select ����,AVG(������) as ��� from ��ȭ
group by ����

--��ȭ�� ���̺��� �����ο��� ���� �˻��Ͻÿ�
--�� ��ȭ������ ��� �˻��Ͻÿ�
select ��ȭ��,SUM(�����ο�) as �� from ��ȭ��
group by ��ȭ��

--��ȭ ���̺��� �������� ���� ū ��ȭ�� ����,��ȭ,���� �˻��Ͻÿ�
select ����,��ȭ,���� from ��ȭ where ������=(select MAX(������) from ��ȭ)

--��ȭ ���̺��� �������� ���� ���� ��ȭ�� ��� ������ �˻��Ͻÿ�
select*from ��ȭ where ������=(select MIN(������) from ��ȭ)

--���� ���̺��� ���̰� ���� ���� ����� ����,�̸��� �˻��Ͻÿ�
select �̸�,���� from ���� where ����=(select MAX(����) from ����)

--�¼���ȣ�� H�� 17���� ����� ����,�̸�,������ �˻��Ͻÿ�
select �̸�,����,���� from ���� join ��ȭ�� on ����.ID=��ȭ��.ID
where �¼���ȣ='H�� 17��'

--����Ǯ�� �󿵵� ��ȭ���� �˻��Ͻÿ�
select ��ȭ�� from ��ȭ join ��ȭ�� on ��ȭ.�󿵰�=��ȭ��.�󿵰�
where ��ȭ='����Ǯ'

--8������ ��ȭ�� �� ����� �¼���ȣ,�̸�,��ȭ,����,������ �˻��Ͻÿ�
select �¼���ȣ,�̸�,��ȭ,����,���� from ��ȭ join ��ȭ�� on ��ȭ.�󿵰�=��ȭ��.�󿵰� join ���� on ��ȭ��.ID=����.ID
where ��ȭ.�󿵰�='8��'

--�����ο��� ���� ǥ�ݾ��� ����� ���Ͻÿ�
select sum(�����ο�) as  ��, avg(ǥ�ݾ�)as ��� from ��ȭ�� join ���� on ��ȭ��.ID=����.ID