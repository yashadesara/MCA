create table CATEGORY(
    catcode int PRIMARY KEY,
    catdesc VARCHAR2(10) NOT NULL CHECK (catdesc in('DELUXE','SUPERDELUXE','SUPERFAST','NORMAL'))
);

insert into CATEGORY values(1,'DELUXE');
insert into CATEGORY values(2,'SUPERDELUXE');
insert into CATEGORY values(3,'NORMAL');


create table ROUTEMASTER(
    routeno int PRIMARY KEY,
    origin VARCHAR2(10) NOT NULL,
    destination VARCHAR2(10) NOT NULL,
    fare number(5) NOT NULL,
    distance number(3),
    capacity number(3) CHECK (capacity>0 and capacity<=60),
    day date,
    catcode int REFERENCES CATEGORY(catcode),
    CHECK(destination!=origin)
);
insert into ROUTEMASTER values(1,'JAM','RJKT',100,90,40,'21-NOV-2021',1);
insert into ROUTEMASTER values(2,'RJKT','AHMDAB',400,300,50,'22-NOV-2021',2);
insert into ROUTEMASTER values(3,'AHMDAB','MUMBAI',900,850,10,'23-NOV-2021',3);



create table TICKETHEADER(
    ticketno int PRIMARY KEY,
    dateofissue date,
    dateoftravel date,
    boardplace VARCHAR2(10),
    routeno int REFERENCES ROUTEMASTER(routeno)
);

insert into TICKETHEADER values(1,'20-NOV-2021','21-NOV-2021','JAM-RJKT',1);
insert into TICKETHEADER values(2,'20-NOV-2021','22-NOV-2021','RJKT-AHMDAB',2);
insert into TICKETHEADER values(3,'20-NOV-2021','23-NOV-2021','AHMDAB-MUMBAI',3);
insert into TICKETHEADER values(4,'20-NOV-2021','23-DEC-2021','JAM-RJKT',1);



create table TICKETDETAILS(
    ticketno int REFERENCES TICKETHEADER(ticketno),
    name VARCHAR2(8),
    sex varchar2(6),
    age number(3),
    fare number(5)
);

insert into TICKETDETAILS values(1,'BHURO','MALE',40,1000);
insert into TICKETDETAILS values(1,'BHURO2','MALE',40,800);
insert into TICKETDETAILS values(2,'BHURI','FEMALE',30,700);
insert into TICKETDETAILS values(3,'HARSHIT','MALE',50,600);
insert into TICKETDETAILS values(4,'SHIT','MALE',50,500);


select * from ROUTEMASTER;
select * from TICKETHEADER;
select * from TICKETDETAILS;

---1 Display the total number of people traveled on each ticket group by ticket no 23
select * from TICKETDETAILS where ticketno=1;


---2 Give the total collection of fare for each route.
select sum(td.fare), r.routeno
from TICKETDETAILS td, ROUTEMASTER r, TICKETHEADER th
where 
r.routeno=th.routeno and
th.ticketno=td.ticketno group by r.routeno;


---3 Give the number of months between issue date and travel date of each ticket issued
select ticketno,to_char(dateoftravel,'MM')-to_char(dateofissue,'MM') as GAPE from TICKETHEADER;


---4 Count number of person boarding from the same place and same route.
select th.boardplace,th.routeno,count(td.ticketno)
from 
TICKETHEADER th, TICKETDETAILS td
where
th.ticketno=td.ticketno
group by th.boardplace,th.routeno
having count(td.ticketno)>1;



---5 Display count of person who has traveled in each category
select c.catdesc,count(td.ticketno)
from CATEGORY c,TICKETDETAILS td, ROUTEMASTER rm, TICKETHEADER th
where c.catcode=rm.catcode and
th.ticketno=td.ticketno and
rm.routeno=th.routeno
group by catdesc;








