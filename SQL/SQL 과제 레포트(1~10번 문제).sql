create database 영화
go
use 영화
go

create table 영화
(감독 nchar(20) not null,
영화 nchar(20) not null,
관람가 int,
상영관 char(10) not null primary key,
나라 char(10))

create table 관객
(이름 nchar(8) not null,
ID nchar(10) not null primary key,
연령 int,
성별 nchar(2),
표금액 int)

create table 영화관
(영화관 nchar(20) not null,
좌석번호 nchar(10) not null primary key,
수용인원 int,
ID nchar(10) foreign key references 관객(ID),
상영관 char(10) foreign key references 영화(상영관))

--영화 테이블
insert into 영화
values('루소 형제','캡틴 아메리카:시빌워',12,'5관','미국')
insert into 영화
values('조성희','탐정 홍길동:사라진 마을',15,'6관','한국')
insert into 영화
values('곽재용','시간 이탈자',15,'7관','한국')
insert into 영화
values('팀 밀러','데드풀',20,'9관','미국')
insert into 영화
values('라지쿠마르 히라니','세얼간이',12,'1관','인도')
insert into 영화
values('모튼 틸덤','이미테이션 게임',15,'3관','영국')
insert into 영화
values('장철수','은밀하게 위대하게',15,'4관','한국')
insert into 영화
values('미이케 다카시','크로우즈 제로',15,'2관','일본')
insert into 영화
values('미야자키 하야오','하울의 움직이는 성',7,'8관','일본')
insert into 영화
values('존 카니','비긴 어게인',15,'10관','미국')
insert into 영화
values('오우삼','적벽대전1부',15,'11관','중국')

--관객 테이블
insert into 관객
values('김나라','M0T123',19,'여',10000)
insert into 관객
values('김한별','M0D265',20,'남',12000)
insert into 관객
values('김준','M0E125',7,'남',9000)
insert into 관객
values('김한울','M0R789',8,'남',7000)
insert into 관객
values('홍희연','M0Y489',21,'여',12000)
insert into 관객
values('이정','P0R753',15,'남',11000)
insert into 관객
values('박재우','P0A487',15,'남',8000)
insert into 관객
values('한세상','P0B257',19,'남',12000)
insert into 관객
values('이준','N0B751',10,'남',8000)
insert into 관객
values('주연수','N0T159',20,'여',15000)
insert into 관객
values('김채은','N0E789',19,'여',15000)
insert into 관객
values('김지수','N0F456',15,'여',11000)
insert into 관객
values('이지영','B0S429',24,'여',15000)
insert into 관객
values('김수빈','B0P154',26,'여',15000)
insert into 관객
values('김영광','B0K168',19,'남',10000)

--영화관 테이블
insert into 영화관
values('롯데시네마','A열 20번',200,'P0R753','1관')
insert into 영화관
values('CGV','D열 5번',150,'B0K168','2관')
insert into 영화관
values('메가박스','E열 17번',245,'P0A487','3관')
insert into 영화관
values('조이앤시네마','B열 13번',320,'N0F456','4관')
insert into 영화관
values('인디플러스','T열 20번',180,'M0T123','5관')
insert into 영화관
values('CGV','B열 10번',200,'M0D265','6관')
insert into 영화관
values('인디플러스','P열 16번',230,'N0T159','7관')
insert into 영화관
values('조이앤시네마','E열 19번',195,'M0E125','8관')
insert into 영화관
values('롯데시네마','F열 20번',300,'B0P154','9관')
insert into 영화관
values('인디플러스','A열 6번',310,'N0E789','10관')
insert into 영화관
values('메가박스','G열 8번',250,'P0B257','11관')
insert into 영화관
values('CGV','D열 8번',180,'M0R789','8관')
insert into 영화관
values('롯데시네마','A열 15번',200,'N0B751','8관')
insert into 영화관
values('조이앤시네마','B열 9번',270,'M0Y489','3관')
insert into 영화관
values('메가박스','H열 17번',300,'B0S429','9관')

Select*from 영화
Select*from 영화관
Select*from 관객

--영화 테이블에서 관람가의 합을 검색하시오
--단 나라별로 묶어서 검색하시오
select 나라,SUM(관람가) as 합 from 영화
group by 나라

--영화 테이블에서 관람가의 평균을 검색하시오
--단 나라별로 묶어서 검색하시오
select 나라,AVG(관람가) as 평균 from 영화
group by 나라

--영화관 테이블에서 수용인원의 합을 검색하시오
--단 영화관별로 묶어서 검색하시오
select 영화관,SUM(수용인원) as 합 from 영화관
group by 영화관

--영화 테이블에서 관람가가 가장 큰 영화의 감독,영화,나라를 검색하시오
select 감독,영화,나라 from 영화 where 관람가=(select MAX(관람가) from 영화)

--영화 테이블에서 관람가가 가장 낮은 영화의 모든 내역을 검색하시오
select*from 영화 where 관람가=(select MIN(관람가) from 영화)

--관객 테이블에서 나이가 가장 많은 사람의 성별,이름을 검색하시오
select 이름,성별 from 관객 where 연령=(select MAX(연령) from 관객)

--좌석번호가 H열 17번인 사람의 나이,이름,성별을 검색하시오
select 이름,연령,성별 from 관객 join 영화관 on 관객.ID=영화관.ID
where 좌석번호='H열 17번'

--데드풀이 상영된 영화관을 검색하시오
select 영화관 from 영화 join 영화관 on 영화.상영관=영화관.상영관
where 영화='데드풀'

--8관에서 영화를 본 사람의 좌석번호,이름,영화,연령,성별을 검색하시오
select 좌석번호,이름,영화,연령,성별 from 영화 join 영화관 on 영화.상영관=영화관.상영관 join 관객 on 영화관.ID=관객.ID
where 영화.상영관='8관'

--수용인원은 합을 표금액은 평균을 구하시오
select sum(수용인원) as  합, avg(표금액)as 평균 from 영화관 join 관객 on 영화관.ID=관객.ID