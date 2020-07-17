create database 영화
go
use 영화
go

create table 영화
(감독 nchar(20) not null,
영화 nchar(20) not null,
관람가 int,
영화코드 char(10) not null primary key,
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
영화코드 char(10) foreign key references 영화(영화코드))

--영화 테이블
insert into 영화
values('루소 형제','캡틴 아메리카:시빌워',12,'B1','미국')
insert into 영화
values('조성희','탐정 홍길동:사라진 마을',15,'B2','한국')
insert into 영화
values('곽재용','시간 이탈자',15,'B3','한국')
insert into 영화
values('팀 밀러','데드풀',20,'C1','미국')
insert into 영화
values('라지쿠마르 히라니','세얼간이',12,'A1','인도')
insert into 영화
values('모튼 틸덤','이미테이션 게임',15,'A3','영국')
insert into 영화
values('장철수','은밀하게 위대하게',15,'A4','한국')
insert into 영화
values('미이케 다카시','크로우즈 제로',15,'A2','일본')
insert into 영화
values('미야자키 하야오','하울의 움직이는 성',7,'B4','일본')
insert into 영화
values('존 카니','비긴 어게인',15,'C2','미국')
insert into 영화
values('오우삼','적벽대전1부',15,'C3','중국')

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
values('김영광','N0B751',10,'남',8000)
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
values('롯데시네마','A열 20번',200,'P0R753','A1')
insert into 영화관
values('CGV','D열 5번',150,'B0K168','A2')
insert into 영화관
values('메가박스','E열 17번',245,'P0A487','A3')
insert into 영화관
values('조이앤시네마','B열 13번',320,'N0F456','A4')
insert into 영화관
values('CGV','B열 10번',200,'M0D265','B2')
insert into 영화관
values('인디플러스','P열 16번',230,'N0T159','B3')
insert into 영화관
values('조이앤시네마','E열 19번',195,'M0E125','B4')
insert into 영화관
values('인디플러스','A열 6번',310,'N0E789','C2')
insert into 영화관
values('메가박스','G열 8번',250,'P0B257','C3')
insert into 영화관
values('CGV','D열 8번',180,'M0R789','B4')
insert into 영화관
values('조이앤시네마','B열 9번',270,'M0Y489','A3')
insert into 영화관
values('메가박스','H열 17번',300,'B0S429','C1')

Select*from 영화
Select*from 영화관
Select*from 관객

--영화관별로 수용인원의 평균을 검색하여 영화관통계뷰를 생성하시오
create view 영화관통계뷰 as
select 영화관, avg(수용인원) as 평균 from 영화관
group by 영화관

--영화관통계뷰에서 수용인원 평균이 250이상인 영화관을 검색하시오
select*from 영화관통계뷰 where 평균>=250

--성별별로 연령의 평균과 표금액의 합을 검색하여 관객통계뷰를 생성하시오
create view 관객통계뷰 as
select 성별,avg(연령) as '연령 평균',SUM(표금액) as '표금액 합' from 관객
group by 성별

--관객통계뷰에서 성별이 '남'인 경우의 모든 내역을 검색하시오
select*from 관객통계뷰 where 성별='남'

--나라별로 관람가의 합을 검색하여 영화통계뷰를 생성하시오
create view 영화통계뷰 as
select 나라,SUM(관람가) as '합' from 영화
group by 나라

--영화통계뷰에서 관람가 합이 30이상인 나라를 검색하시오
select*from 영화통계뷰 where 합>=30

--관객테이블을 이용하여 관객복사 테이블을 구성하고자 한다.
select*into 관객복사 from 관객

--영화관에 영화를 보러가지 않은 사람의 이름,성별,연령을 검색하시오
select 이름, 성별,연령 from 영화관 right outer join 관객 on 영화관.ID=관객.ID
where 영화관 is null

--영화관에 영화를 보러간 사람의 이름 본 영화관,영화코드,이름,성별,연령을 검색하시오
 select 영화관,영화코드,이름,성별,연령 from 영화관 right outer join 관객 on 영화관.ID=관객.ID
 where 영화관 is not null
 
--관객테이블에서 ID는 다르나 이름은 같은 관객의 명단을 검색하시오(self join 사용)
select*from 관객 a, 관객 b
where a.ID !=  b.ID and a.이름=b.이름

--영화코드를 입력하지 않으면 자동으로 미정으로 저장되도록 설정하시오(영화관기본값)
alter table 영화관
add constraint 영화관기본값
default '미정' for 수용인원

--관람가를 입력하지 않으면 자동으로 미정으로 저장되도록 설정하시오(영화기본값)
alter table 영화
add constraint 영화기본값
default '미정' for 관람가

--연령을 입력하지 않으면 자동으로 20살이 저장되도록 설정하시오(관객기본값)
alter table 관객
add constraint 관객기본값
default '20' for 연령

--표금액이 7000원에서 15000원 사이의 값만 입력되도록 표금액제약조건을 생성하시오
alter table 관객
add constraint 표금액제약
check(표금액 between 7000 and 15000)

--관람가가 5~28살 사이의 값만 입력되도록 연령제약조건을 생성하시오
alter table 영화
add constraint 관람가제약
check(관람가 between 5 and 28)

--수용인원이 120~350석 사이의 값만 입력되도록 수용인원제약조건을 생성하시오
alter table 영화관
add constraint 수용인원제약
check(수용인원 between 120 and 350)

--관객테이블에서 표금액제약조건을 삭제하시오
alter table 관객
drop constraint 표금액제약

--영화테이블에서 관람가제약조건을 삭제하시오
alter table 영화
drop constraint 관람가제약

--관객테이블에서 연령으로 오름차순 검색되는 '연령색인'인덱스를 생성하시오
create index 연령색인 on 관객(연령 asc)

--관객테이블에 존재하는 연령색인 인덱스를 삭제하시오
drop index 관객.연령색인
