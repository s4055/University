create database ��ȭ
go
use ��ȭ
go

create table ��ȭ
(���� nchar(20) not null,
��ȭ nchar(20) not null,
������ int,
��ȭ�ڵ� char(10) not null primary key,
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
��ȭ�ڵ� char(10) foreign key references ��ȭ(��ȭ�ڵ�))

--��ȭ ���̺�
insert into ��ȭ
values('��� ����','ĸƾ �Ƹ޸�ī:�ú���',12,'B1','�̱�')
insert into ��ȭ
values('������','Ž�� ȫ�浿:����� ����',15,'B2','�ѱ�')
insert into ��ȭ
values('�����','�ð� ��Ż��',15,'B3','�ѱ�')
insert into ��ȭ
values('�� �з�','����Ǯ',20,'C1','�̱�')
insert into ��ȭ
values('�������� �����','������',12,'A1','�ε�')
insert into ��ȭ
values('��ư ƿ��','�̹����̼� ����',15,'A3','����')
insert into ��ȭ
values('��ö��','�����ϰ� �����ϰ�',15,'A4','�ѱ�')
insert into ��ȭ
values('������ ��ī��','ũ�ο��� ����',15,'A2','�Ϻ�')
insert into ��ȭ
values('�̾���Ű �Ͼ߿�','�Ͽ��� �����̴� ��',7,'B4','�Ϻ�')
insert into ��ȭ
values('�� ī��','��� �����',15,'C2','�̱�')
insert into ��ȭ
values('�����','��������1��',15,'C3','�߱�')

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
values('�迵��','N0B751',10,'��',8000)
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
values('�Ե��ó׸�','A�� 20��',200,'P0R753','A1')
insert into ��ȭ��
values('CGV','D�� 5��',150,'B0K168','A2')
insert into ��ȭ��
values('�ް��ڽ�','E�� 17��',245,'P0A487','A3')
insert into ��ȭ��
values('���̾ؽó׸�','B�� 13��',320,'N0F456','A4')
insert into ��ȭ��
values('CGV','B�� 10��',200,'M0D265','B2')
insert into ��ȭ��
values('�ε��÷���','P�� 16��',230,'N0T159','B3')
insert into ��ȭ��
values('���̾ؽó׸�','E�� 19��',195,'M0E125','B4')
insert into ��ȭ��
values('�ε��÷���','A�� 6��',310,'N0E789','C2')
insert into ��ȭ��
values('�ް��ڽ�','G�� 8��',250,'P0B257','C3')
insert into ��ȭ��
values('CGV','D�� 8��',180,'M0R789','B4')
insert into ��ȭ��
values('���̾ؽó׸�','B�� 9��',270,'M0Y489','A3')
insert into ��ȭ��
values('�ް��ڽ�','H�� 17��',300,'B0S429','C1')

Select*from ��ȭ
Select*from ��ȭ��
Select*from ����

--��ȭ������ �����ο��� ����� �˻��Ͽ� ��ȭ�����並 �����Ͻÿ�
create view ��ȭ������ as
select ��ȭ��, avg(�����ο�) as ��� from ��ȭ��
group by ��ȭ��

--��ȭ�����信�� �����ο� ����� 250�̻��� ��ȭ���� �˻��Ͻÿ�
select*from ��ȭ������ where ���>=250

--�������� ������ ��հ� ǥ�ݾ��� ���� �˻��Ͽ� �������並 �����Ͻÿ�
create view �������� as
select ����,avg(����) as '���� ���',SUM(ǥ�ݾ�) as 'ǥ�ݾ� ��' from ����
group by ����

--�������信�� ������ '��'�� ����� ��� ������ �˻��Ͻÿ�
select*from �������� where ����='��'

--���󺰷� �������� ���� �˻��Ͽ� ��ȭ���並 �����Ͻÿ�
create view ��ȭ���� as
select ����,SUM(������) as '��' from ��ȭ
group by ����

--��ȭ���信�� ������ ���� 30�̻��� ���� �˻��Ͻÿ�
select*from ��ȭ���� where ��>=30

--�������̺��� �̿��Ͽ� �������� ���̺��� �����ϰ��� �Ѵ�.
select*into �������� from ����

--��ȭ���� ��ȭ�� �������� ���� ����� �̸�,����,������ �˻��Ͻÿ�
select �̸�, ����,���� from ��ȭ�� right outer join ���� on ��ȭ��.ID=����.ID
where ��ȭ�� is null

--��ȭ���� ��ȭ�� ������ ����� �̸� �� ��ȭ��,��ȭ�ڵ�,�̸�,����,������ �˻��Ͻÿ�
 select ��ȭ��,��ȭ�ڵ�,�̸�,����,���� from ��ȭ�� right outer join ���� on ��ȭ��.ID=����.ID
 where ��ȭ�� is not null
 
--�������̺��� ID�� �ٸ��� �̸��� ���� ������ ����� �˻��Ͻÿ�(self join ���)
select*from ���� a, ���� b
where a.ID !=  b.ID and a.�̸�=b.�̸�

--��ȭ�ڵ带 �Է����� ������ �ڵ����� �������� ����ǵ��� �����Ͻÿ�(��ȭ���⺻��)
alter table ��ȭ��
add constraint ��ȭ���⺻��
default '����' for �����ο�

--�������� �Է����� ������ �ڵ����� �������� ����ǵ��� �����Ͻÿ�(��ȭ�⺻��)
alter table ��ȭ
add constraint ��ȭ�⺻��
default '����' for ������

--������ �Է����� ������ �ڵ����� 20���� ����ǵ��� �����Ͻÿ�(�����⺻��)
alter table ����
add constraint �����⺻��
default '20' for ����

--ǥ�ݾ��� 7000������ 15000�� ������ ���� �Էµǵ��� ǥ�ݾ����������� �����Ͻÿ�
alter table ����
add constraint ǥ�ݾ�����
check(ǥ�ݾ� between 7000 and 15000)

--�������� 5~28�� ������ ���� �Էµǵ��� �������������� �����Ͻÿ�
alter table ��ȭ
add constraint ����������
check(������ between 5 and 28)

--�����ο��� 120~350�� ������ ���� �Էµǵ��� �����ο����������� �����Ͻÿ�
alter table ��ȭ��
add constraint �����ο�����
check(�����ο� between 120 and 350)

--�������̺��� ǥ�ݾ����������� �����Ͻÿ�
alter table ����
drop constraint ǥ�ݾ�����

--��ȭ���̺��� ���������������� �����Ͻÿ�
alter table ��ȭ
drop constraint ����������

--�������̺��� �������� �������� �˻��Ǵ� '���ɻ���'�ε����� �����Ͻÿ�
create index ���ɻ��� on ����(���� asc)

--�������̺� �����ϴ� ���ɻ��� �ε����� �����Ͻÿ�
drop index ����.���ɻ���
