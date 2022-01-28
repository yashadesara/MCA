create table DISTRIBUTOR
(
    dno int PRIMARY KEY,
    dname VARCHAR2(10),
    daddress VARCHAR2(10),
    dphone number(10)
);

insert into DISTRIBUTOR values(1,'SHAH','DUBAI',1293998880,'mr.bhuro');
insert into DISTRIBUTOR values(2,'MEHTA','RAJKOT',4295998880,'mr.bha');
insert into DISTRIBUTOR values(3,'VORA','SURAT',5294928880,'Mr.Talkative');
insert into DISTRIBUTOR values(4,'OBO','ADCITY',67828880,'mr.bro');
insert into DISTRIBUTOR values(5,'ABCDOHOB','ACITY',6787680,'mr.handsome');

create table ITEMM
(
    itemno int PRIMARY KEY,
    itemname VARCHAR2(10), 
    colour VARCHAR2(10), 
    weight number(3)
);

insert into ITEMM values(1,'IPHONE','RED',100);
insert into ITEMM values(2,'CHARGER','WHITE',200);
insert into ITEMM values(3,'CABLE','BLACK',300);
insert into ITEMM values(4,'WIRELESS','BLACK',500);
insert into ITEMM values(5,'LESS','BLACK',400);


create table DIST_ITEM 
(
    dno int REFERENCES DISTRIBUTOR(dno), 
    itemno int REFERENCES ITEMM(itemno), 
    qty number(3)
);

insert into DIST_ITEM values(1,1,10);
insert into DIST_ITEM values(1,1,20);
insert into DIST_ITEM values(4,1,40);
insert into DIST_ITEM values(2,4,600);
insert into DIST_ITEM values(2,4,600);
insert into DIST_ITEM values(3,3,30);
insert into DIST_ITEM values(3,3,15);


---1 Add a column CONTACT_PERSON to the DISTRIBUTOR table with the not null constraint.
alter table DISTRIBUTOR add CONTACT_PERSON VARCHAR2(20) NOT NULL;

-- 2. Create a view LONDON_DIST on DIST_ITEM which contains only those records
-- where distributors are from London. Make sure that this condition is checked for every
-- DML against this view
create or replace view LONDON_DIST as
select dname from DISTRIBUTOR where daddress='DUBAI';

---3 Display the details of all those items that have never been supplied.
select itemname from ITEMM where itemno not in(select itemno from DIST_ITEM);


---4 Delete all those items that have been supplied only once.
DELETE FROM DIST_ITEM 
WHERE dno IN(SELECT dno FROM DIST_ITEM GROUP BY dno HAVING COUNT(*)=1);

---5 List names of distributors who have an ‘A’ and also a ‘B’ somewhere in their names.
select dname from DISTRIBUTOR where dname like '%A%' or dname like '%B%';

---6 Count the number of items having the same colour but not having weight
--- between 20 and 100.
select count(*) from ITEMM 
WHERE weight not BETWEEN 100 and 200 group by colour having count(*)>1;


--7 Display all those distributors who have supplied more than 1000 parts of the same type.
select d.dname
from DISTRIBUTOR d, DIST_ITEM di
where d.dno=di.dno group by d.dname having sum(di.qty)>=1000;


--8 Display the average weight of items of the same colour provided at least three items
-- have That colour.
select avg(weight) from ITEMM group by colour having count(*)>2;

--9 Display the position where a distributor name has an ‘OH’ in its spelling somewhere
-- after the fourth character.
select dname from DISTRIBUTOR where dname like '____OH%';


-- 10. Count the number of distributors who have a phone connection and are supplying item
-- number ‘I100’.
select count(dname) from DISTRIBUTOR where dno in(select dno from DIST_ITEM where itemno=1);


-- 11. Create a view on the tables in such a way that the view contains the distributor name,
-- item name and the quantity supplied.
create or replace view all_tables as 
select distinct d.dname, i.itemname, di.qty
from DISTRIBUTOR d, ITEMM i, DIST_ITEM di
where
d.dno=di.dno and
i.itemno=di.itemno;


-- 12 List the name, address and phone number of distributors who have the same three
-- digits in their number as ‘Mr. Talkative’.
select dname,dphone,daddress from distributor where substr(dphone,1,3) in
(select substr(dphone,1,3) from distributor where dname='ABCDOHOB') and dname!='ABCDOHOB'


-- 13. List all distributor names who supply either item I1 or I7 or the 
-- quantity supplied is more than 100.
select d.dno , d.dname from distributor d where dno in
(select dno from dist_item where (itemno=2 or itemno=3) and qty>=10);


-- 14. Display the data of the top three heaviest ITEMS.
SELECT weight
FROM (SELECT weight FROM ITEMM order by weight DESC)
WHERE ROWNUM <= 3;